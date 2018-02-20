#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"

class Lab03Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

public:
};
TEST_F(Lab03Fixture, Test1){
    lab3::fifo FIFO;
    lab3::lifo LIFO;
    EXPECT_EQ(true, FIFO.is_empty()); //It should be true because I did not append anything
    EXPECT_ANY_THROW(FIFO.size()); //It does a throw because of my lab2
    EXPECT_EQ(true, LIFO.is_empty()); //It should be true because I did not append anything
    EXPECT_EQ(0, LIFO.size()); // my LIFO size function returns nothing which has the value of 0 if it is empty
}

TEST_F(Lab03Fixture, Test2){
    lab3::lifo Lifo;
    Lifo.push("0th element");
    Lifo.push("Hello");
    EXPECT_EQ("Hello",Lifo.top());// Top should be Hello
    EXPECT_EQ(2,Lifo.size());
    Lifo.push("World");
    EXPECT_EQ("World",Lifo.top());//Top should be the back index, World in this case
    EXPECT_EQ(3,Lifo.size());
    Lifo.push("Popping");
    EXPECT_EQ("Popping",Lifo.top());// Top should be the back index, Popping in this case
    EXPECT_EQ(4,Lifo.size());
    Lifo.pop();//Pop takes away a number from the index bringing it back to world
    EXPECT_EQ("World",Lifo.top());
    Lifo.pop();
    Lifo.pop();
    Lifo.pop();
    EXPECT_EQ(true,Lifo.is_empty());
}
TEST_F(Lab03Fixture, Test3){
    lab3::fifo Fifo;
    Fifo.enqueue("Hello");
    EXPECT_EQ("Hello", Fifo.top());//Top should be Hello
Fifo.enqueue("World");
    EXPECT_EQ("Hello",Fifo.top());//Because the top is the front index which is the first element
    EXPECT_EQ(2,Fifo.size());
    Fifo.dequeue();//Dequeue is like pop, but adds to front index, meaning we should expect world.
    EXPECT_EQ("World",Fifo.top());
    EXPECT_EQ(1,Fifo.size());
    Fifo.dequeue();
    EXPECT_EQ(true,Fifo.is_empty());
}
