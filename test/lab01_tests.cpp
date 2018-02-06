#include "gtest/gtest.h"
#include "expressionstream.h"

class Lab01Fixture : public ::testing::Test {
protected:
protected:
    virtual void TearDown() {
        delete stream1;
        delete stream2;
    }

    virtual void SetUp() {
        stream1=new expressionstream("1+2+3");
        stream2=new expressionstream("1   + 2 *4+(2*3)");
        stream3=new expressionstream("-1 +-2");
        stream5=new expressionstream("1+2*4");
        stream6=new expressionstream("12");
        stream7=new expressionstream("6.5");

    }


public:
    expressionstream *stream1;
    expressionstream *stream2;
    expressionstream *stream3;
    expressionstream *stream5;
    expressionstream *stream6;
    expressionstream *stream7;



};


TEST(crashTest , constructorTest) {
    expressionstream stream1 ("1+2+3");
    expressionstream stream2 ("1   + 2 *4+(2*3)");
    expressionstream stream5 ("1+2*4");

}


TEST_F(Lab01Fixture, basicTest) {
    EXPECT_EQ("1",stream1->get_next_int());
    EXPECT_EQ("2",stream1->get_next_int());
    EXPECT_EQ("3",stream1->get_next_int());

    EXPECT_EQ("+",stream1->get_next_op());
    EXPECT_EQ("+",stream1->get_next_op());
//todo: Get these tests to pass using the debugger
    EXPECT_EQ("1",stream2->get_next_int());
    EXPECT_EQ("2",stream2->get_next_int());
    EXPECT_EQ("4",stream2->get_next_int());
    EXPECT_EQ("2",stream2->get_next_int());
    EXPECT_EQ("3",stream2->get_next_int());

    EXPECT_EQ("+",stream2->get_next_op());
    EXPECT_EQ("*",stream2->get_next_op());
    EXPECT_EQ("+",stream2->get_next_op());
    EXPECT_EQ("(",stream2->get_next_op());
    EXPECT_EQ("*",stream2->get_next_op());
    EXPECT_EQ(")",stream2->get_next_op());

    EXPECT_EQ("+", stream3->get_next_op());
    EXPECT_EQ("-1", stream3->get_next_int());
    EXPECT_EQ("-2", stream3->get_next_int());
}

TEST_F(Lab01Fixture, isNext) {
    EXPECT_FALSE(stream1->expression_complete());
    stream1->get_next_int();
    stream1->get_next_int();
    stream1->get_next_int();
    EXPECT_FALSE(stream1->expression_complete());
    stream1->get_next_op();
    stream1->get_next_op();
    EXPECT_TRUE(stream1->expression_complete());
}

TEST_F(Lab01Fixture, Test1){
    EXPECT_EQ("1", stream5->get_next_int());
    EXPECT_EQ("2", stream5->get_next_int());
    EXPECT_EQ("4", stream5->get_next_int());
    EXPECT_EQ("+", stream5->get_next_op());
    EXPECT_EQ("*", stream5->get_next_op()); //This is to show that the constructor test works with any other streams
}

TEST_F(Lab01Fixture, Test2) {
    EXPECT_NE("6.5", stream7->get_next_int()); //This test shows that the Expect not equal function works because stream 5 starts with a 1 rather than a 5
}

TEST_F(Lab01Fixture, Test3){
    EXPECT_EQ("12", stream6->get_next_int()); //Cuts off the decimal because it is getting integers
}
TEST_F(Lab01Fixture, Test4){
    EXPECT_GT(stream6, stream5);//This test works because stream6 is larger than stream5
}
TEST_F(Lab01Fixture, Test5){
 EXPECT_FALSE(stream6==stream7);//This passes because it expected the statement to be false (stream6 is greater than 7)
}

//todo: create a new test
//step 1: press alt+insert (or right click and select generate)
//step 2: choose test to generate a new test where the cursor is
//step 3: type "Lab01Fixture" in the red box and press tab to go to next auto fill box
//step 4: type name of your test
//step 5: inside the function create your test, use previous test as examples
