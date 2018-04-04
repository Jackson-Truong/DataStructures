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

TEST(doubly_linked_list,addTest) {
    lab6::doubly_linked_list testLL1(32);
    testLL1.append(9);
    testLL1.append(7);
    testLL1.append(24);

    lab6::doubly_linked_list testLL2(13);
    testLL2.append(2);
    testLL2.append(17);
    testLL2.append(32);
    testLL2.append(91);

    lab6::doubly_linked_list temp;


    //basic add
    temp = testLL1 + testLL2;
    EXPECT_EQ(9, temp.size());

    EXPECT_EQ(32, temp.get_data(0));
    EXPECT_EQ(9, temp.get_data(1));
    EXPECT_EQ(7, temp.get_data(2));
    EXPECT_EQ(24, temp.get_data(3));
    EXPECT_EQ(13, temp.get_data(4));
    EXPECT_EQ(2, temp.get_data(5));
    EXPECT_EQ(17, temp.get_data(6));
    EXPECT_EQ(32, temp.get_data(7));
    EXPECT_EQ(91, temp.get_data(8));

}

TEST(doubly_linked_list,concatenate) {
    lab6::doubly_linked_list testLL1(32);
    testLL1.append(9);
    testLL1.append(7);
    testLL1.append(24);

    lab6::doubly_linked_list testLL2(13);
    testLL2.append(2);
    testLL2.append(17);
    testLL2.append(32);
    testLL2.append(91);
testLL1+=testLL2;
    EXPECT_EQ(32, testLL1.get_data(0));
    EXPECT_EQ(9, testLL1.get_data(1));
    EXPECT_EQ(7, testLL1.get_data(2));
    EXPECT_EQ(24, testLL1.get_data(3));
    EXPECT_EQ(13, testLL1.get_data(4));
    EXPECT_EQ(2, testLL1.get_data(5));
    EXPECT_EQ(17, testLL1.get_data(6));
    EXPECT_EQ(32, testLL1.get_data(7));
    EXPECT_EQ(91, testLL1.get_data(8));
}

TEST(doubly_linked_list,boolean) {
    lab6::doubly_linked_list testLL1(7);
    testLL1.append(80);
    testLL1.append(24);
    testLL1.append(14);

    lab6::doubly_linked_list testLL2(7);
    testLL2.append(80);
    testLL2.append(24);
    testLL2.append(14);
    testLL2.append(29);


    EXPECT_FALSE(testLL1==testLL2);
}

TEST(doubly_linked_list, truuuu){
    lab6::doubly_linked_list testLL1(1);
    testLL1.append(3);
    testLL1.append(5);
    testLL1.append(7);
    lab6::doubly_linked_list testLL2(1);
    testLL2.append(3);
    testLL2.append(5);
    testLL2.append(7);
    EXPECT_TRUE(testLL1 == testLL2);
}