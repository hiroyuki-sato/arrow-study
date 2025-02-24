#include <gtest/gtest.h>
#include <arrow/api.h>

TEST(ArrayTest, Validate1) {
    arrow::UInt8Builder builder;

    std::vector<uint8_t> values = {10, 20, 30, 255};
    for (auto value : values) {
        builder.Append(value);
    }

    std::shared_ptr<arrow::UInt8Array> array;
    arrow::Status status = builder.Finish(&array);

    int64_t length = array->length();
    uint8_t value = array->Value(0);
    status = array->Validate();
    EXPECT_EQ(true,status.ok());
    // #std::cout << "Array length: " << length << std::endl;
   
    EXPECT_EQ(4, length);
    EXPECT_EQ(10,value);
}

