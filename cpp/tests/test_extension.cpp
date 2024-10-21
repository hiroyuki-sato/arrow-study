#include <gtest/gtest.h>
#include <arrow/api.h>
#include <dummy_extension.hpp>

TEST(FieldExtensionTest, Initialize) {
    arrow::UInt8Builder builder;

    std::vector<uint8_t> values = {10, 20, 30, 255};
    for (auto value : values) {
        builder.Append(value);
    }

    std::shared_ptr<arrow::UInt8Array> array;
    arrow::Status status = builder.Finish(&array);

    int64_t length = array->length();
    uint8_t value = array->Value(0);
    // #std::cout << "Array length: " << length << std::endl;
   
    EXPECT_EQ(4, length);
    EXPECT_EQ(10,value);
}

TEST(FieldExtensionTest, Dummy) {
    //arrow::UInt8Builder builder;

    arrow::RegisterExtensionType(std::make_shared<DummyType>());
    //arrow::ExtensionTypeRegistry::RegisterType(std::make_shared<DummyType>());

    //arrow::FixedSizeBinaryBuilder builder(arrow::fixed_size_binary(16));
    //std::shared_ptr<arrow::FixedSizeBinaryArray> array;

    //EXPECT_EQ(4, length);
    //EXPECT_EQ(10,value);
}
