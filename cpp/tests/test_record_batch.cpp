#include <gtest/gtest.h>
#include <arrow/api.h>

TEST(RecordBatchTest, Initialize) {
    arrow::UInt8Builder builder;

    std::vector<uint8_t> values = {10, 20, 30};
    for (auto value : values) {
        builder.Append(value);
    }

    std::shared_ptr<arrow::UInt8Array> array;
    arrow::Status status = builder.Finish(&array);

    arrow::StringBuilder builder2;
    std::vector<std::string> strings = {"Hello", "World", "!!"};
    for (auto string : strings) {
        builder2.Append(string);
    }
    std::shared_ptr<arrow::StringArray> string_array;
    status = builder2.Finish(&string_array);

    auto id_field = arrow::field("x", arrow::uint8());
    //auto id_field = std::make_shared<arrow::Field>("name",arrow::uint8());
    auto v_field = std::make_shared<arrow::Field>("val",arrow::utf8());


/*
    arrow::SchemaBuilder builder3;

    builder3.AddField(id_field);
    builder3.AddField(v_field);

    //std::shared_ptr<arrow::Schema> schema;
    const auto schema = builder3.Finish();
*/
    auto schema = arrow::schema({id_field, v_field});

    auto record_batch = arrow::RecordBatch::Make(schema, 2, {array, string_array});
    //EXPECT_FALSE(record_batch->Validate() == true);
    status = record_batch->Validate();
    EXPECT_TRUE(!status.ok());

}
