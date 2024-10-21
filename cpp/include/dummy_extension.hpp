#ifndef DUMMY_EXTENSION_HPP
#define DUMMY_EXTENSION_HPP

#include <arrow/extension_type.h>
#include <arrow/api.h>
#include <memory>

class DummyType : public arrow::ExtensionType {
 public:
  DummyType() : ExtensionType(arrow::fixed_size_binary(5)) {};

  std::string extension_name() const override { return "dummy"; }

  bool ExtensionEquals(const ExtensionType& other) const override;

//  std::shared_ptr<Array> MakeArray(std::shared_ptr<ArrayData> data) const override;

  arrow::Result<std::shared_ptr<DataType>> Deserialize(
      std::shared_ptr<DataType> storage_type,
      const std::string& serialized) const override;

  std::string Serialize() const override { return "dummy"; }
};

#endif  // DUMMY_EXTENSION_HPP

