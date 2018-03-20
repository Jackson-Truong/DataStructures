#include "gtest/gtest.h"
#include "doubly_linked_list.h"

class Lab06Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        test2 = new lab6::doubly_linked_list(5);
        test2->append(8);
        test2->append(2);
        test2->append(4);
        test2->append(1);
        test2->append(3);
        test2->append(7);
        test2->append(6);
        test2->append(0);


    }

    virtual void TearDown() {
    }

public:
    lab6::doubly_linked_list *test2;
};

TEST_F(Lab06Fixture, Sort){
    test2->sort();
    EXPECT_EQ(0, test2->get_data(0));
    EXPECT_EQ(1, test2->get_data(1));
    EXPECT_EQ(2, test2->get_data(2));
    EXPECT_EQ(3, test2->get_data(3));
    EXPECT_EQ(4, test2->get_data(4));
    EXPECT_EQ(5, test2->get_data(5));
    EXPECT_EQ(6, test2->get_data(6));
    EXPECT_EQ(7, test2->get_data(7));
    EXPECT_EQ(8, test2->get_data(8));


}