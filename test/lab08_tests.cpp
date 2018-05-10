#include "gtest/gtest.h"
#include "../lib/lab08/inc/hash_table.h"
#include "../lib/lab08/src/sorts.cpp"
//#include "../lib/lab06/inc/doubly_linked_list.h"

class Lab08SortsFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        test_numbers=std::vector<unsigned>({12,8,14,15,18,16,17,19,22,20,4,10,9,13,11,5,7,6,2,1,3});

    }

public:
    lab6::doubly_linked_list *to_sort_short, *to_sort_long;
    std::vector <unsigned> test_numbers;

};


class Lab08SortsProfiler : public ::testing::Test {
protected:
    virtual void SetUp(){

    }
public:
    lab6::doubly_linked_list *list_16, *list_32, *list_64, *list_128, *list_256, *list_512, *list_1024, *list_2048, *list_4096, *list_8192, *list_16384, *list_32768;
};

TEST_F(Lab08SortsFixture, Quicksort){
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
    int low= 0;
    int high =10;
    int hello[] = {0,1,2,3,4,5,6,7,8,9,10};
   lab6::quicksort(arr,low, high);

   EXPECT_EQ(0,arr[0]);
    EXPECT_EQ(1,arr[1]);
    EXPECT_EQ(1,arr[1]);
    EXPECT_EQ(2,arr[2]);
    EXPECT_EQ(3,arr[3]);
    EXPECT_EQ(4,arr[4]);
    EXPECT_EQ(5,arr[5]);
    EXPECT_EQ(6,arr[6]);
    EXPECT_EQ(7,arr[7]);
    EXPECT_EQ(8,arr[8]);
    EXPECT_EQ(9,arr[9]);
    EXPECT_EQ(10,arr[10]);

}