#include <gtest/gtest.h>
#include <arrow/api.h>
#include <arrow/extension/fixed_shape_tensor.h>
#include <type_traits>
#include <iostream>


TEST(FixedShapeTensor, Initialize) {

  //auto registered_type = arrow::GetExtensionType("arrow.fixed_shape_tensor");
  //std::cout << registered_type->extension_name() << std::endl;

  //std::shared_ptr<arrow::DataType> value_type = arrow::float64();
  //std::vector<int64_t> shape = {2, 2};

  auto type = arrow::extension::fixed_shape_tensor(arrow::float32(), {3, 224, 224});

  std::vector<int64_t> element_shape_ = {3, 4};
  std::shared_ptr<arrow::DataType> value_type_ = arrow::int64();
  std::vector<std::string> dim_names_ = {"x", "y"};
  auto var = arrow::extension::fixed_shape_tensor(value_type_, element_shape_, {}, dim_names_);

  auto value_type = arrow::uint64();
  std::vector<int64_t> shape = {3,4};
  std::vector<std::string> dim_name = {"x","y"};

  auto var2 = arrow::extension::FixedShapeTensorType::Make(value_type, shape, {}, dim_name);
  std::cout << var2.ok() << std::endl;

  //auto ext_type = std::make_shared<arrow::extension::FixedShapeTensorType>(value_type, shape);
  //auto ext_type = std::make_shared<registered_type.type()>(value_type, shape);
  //auto ext_type = std::make_shared<registered_type.type()>(value_type, shape);

  //EXPECT_EQ(typeid(*registered_type), typeid(arrow::extension::FixedShapeTensorType));
  EXPECT_TRUE(true);

}
