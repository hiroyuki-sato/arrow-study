#include <gtest/gtest.h>
#include <arrow/api.h>

//Result<std::shared_ptr<StringViewArray>> MakeBinaryViewArray(
std::shared_ptr<arrow::StringViewArray> MakeBinaryViewArray(
    arrow::BufferVector data_buffers,
    const std::vector<arrow::BinaryViewType::c_type>& views,
    bool validate = true) {

  auto length = static_cast<int64_t>(views.size());
  auto arr = std::make_shared<arrow::StringViewArray>(
      arrow::utf8_view(), length, arrow::Buffer::FromVector(views), std::move(data_buffers));
/*
  if (validate) {
    RETURN_NOT_OK(arr->ValidateFull());
  }
*/
  return arr;
}

//inline BinaryViewType::c_type ToBinaryView(const void* data, int32_t size,
//                                           int32_t buffer_index, int32_t offset)

//inline BinaryViewType::c_type ToBinaryView(std::string_view v, int32_t buffer_index,
//                                           int32_t offset)

TEST(BinaryViewTest, Initialize) {

  auto length = static_cast<int64_t>(1);
  auto buffer_s = arrow::Buffer::FromString("supercalifragilistic(sp?)");
  auto buffer_y = arrow::Buffer::FromString("yyyyyyyyyyyyyyyyyyyyyyyyy");
  std::vector<std::shared_ptr<arrow::Buffer>> data_buffers = {buffer_s, buffer_y};


  //auto view = arrow::util::ToBinaryView("supe", static_cast<int32_t>(buffer_s->size()), 0, 0);
  std::vector<arrow::BinaryViewType::c_type>view = {arrow::util::ToBinaryView("supe", static_cast<int32_t>(buffer_s->size()), 0, 0)};
  
  auto bva = std::make_shared<arrow::BinaryViewArray>(arrow::binary_view(),1,arrow::Buffer::FromVector(view),std::move(data_buffers));
  auto status = bva->Validate();
  EXPECT_TRUE(status.ok());
  //auto bva = new arrow::BinaryViewArray(arrow::binary_view(),1,{buffer_s},view);
/*
  BinaryViewArray(std::shared_ptr<DataType> type, int64_t length,
                  std::shared_ptr<Buffer> views, BufferVector data_buffers,
                  std::shared_ptr<Buffer> null_bitmap = NULLPTR,
                  int64_t null_count = kUnknownNullCount, int64_t offset = 0);
*/

/*
  auto bva = std::make_shared<arrow::BinaryViewArray>(arrow::utf8_view(),length,
                                                      arrow::Buffer::FromVector(buffer_y),
                                                      std::move(buffer_s));
*/

/*
  auto length = static_cast<int64_t>(views.size());
  auto arr = std::make_shared<StringViewArray>(
  utf8_view(), length, Buffer::FromVector(views), std::move(buffer_s));

  EXPECT_TRUE(status.ok());
*/

}
