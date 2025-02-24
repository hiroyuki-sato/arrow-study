#include <gtest/gtest.h>
#include <arrow/api.h>
#include <iostream>

TEST(MemoryPoolTest, BackendName) {
    auto memory_pool = arrow::default_memory_pool();
    std::cout << memory_pool->backend_name() << std::endl;
    std::cout << memory_pool->max_memory() << std::endl;
    std::cout << memory_pool->bytes_allocated() << std::endl;
   
    //EXPECT_EQ(4, length);
    //EXPECT_EQ(10,value);
}
