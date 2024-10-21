#include <arrow/api.h>
#include <arrow/extension_type.h>

class DummyType : public arrow::ExtensionType {
 public:

  bool ExtensionEquals(const arrow::ExtensionType& other) const override {
    return other.extension_name() == this->extension_name();
  }

  arrow::Result<std::shared_ptr<DataType>> Deserialize(
      std::shared_ptr<DataType> storage_type,
      const std::string& serialized)
  {
    return nullptr;
  }
};

