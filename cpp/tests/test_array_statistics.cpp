#include <gtest/gtest.h>
#include <arrow/api.h>

TEST(ArrayStatistics, Initialize) {
    auto stat = std::make_shared<arrow::ArrayStatistics>();
    ASSERT_FALSE(stat->null_count.has_value());
}
