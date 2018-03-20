#include "gtest/gtest.h"
#include "doubly_linked_list.h"

class Lab06Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }
    virtual void TearDown() {
    }
public:
};
TEST(Lab06Fixture, sort){
    lab6::doubly_linked_list hi;
    hi.append(10);
    hi.append(9);
    hi.append(8);
    hi.append(7);
    hi.append(6);
    hi.append(5);
    hi.append(4);
    hi.append(3);
    hi.append(2);
    hi.append(1);
    hi.append(0);
    hi.sort();
    EXPECT_EQ(0, hi.get_data(0));
    EXPECT_EQ(1, hi.get_data(1));
    EXPECT_EQ(2, hi.get_data(2));
    EXPECT_EQ(3, hi.get_data(3));
    EXPECT_EQ(4, hi.get_data(4));
    EXPECT_EQ(5, hi.get_data(5));
    EXPECT_EQ(6, hi.get_data(6));
    EXPECT_EQ(7, hi.get_data(7));
    EXPECT_EQ(8, hi.get_data(8));
    EXPECT_EQ(9, hi.get_data(9));
    EXPECT_EQ(10, hi.get_data(10));
}

