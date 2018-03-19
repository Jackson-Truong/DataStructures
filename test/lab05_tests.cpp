#include "gtest/gtest.h"
#include "queue.h"
#include "stack.h"
#include "fancy_calculator.h"

class Lab05Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

public:
};
TEST_F(Lab05Fixture, Queue){
    lab5::queue q;
    q.enqueue("1");
    EXPECT_EQ("1", q.top());
    q.enqueue("2");
    EXPECT_EQ(2, q.queueSize());
    EXPECT_EQ("1",q.top());
    q.dequeue();
    EXPECT_EQ("2",q.top());
    EXPECT_EQ(1, q.queueSize());
    q.dequeue();
    EXPECT_TRUE(q.isEmpty());
}

TEST_F(Lab05Fixture, Linked){
    lab5::linked_list L;
    std::string a = "hello";
    std::string b = "world";
    std::string c = "c";
    L.append(a);
    EXPECT_EQ("hello", L.get_value_at(0));
    EXPECT_EQ(1, L.listSize());
    L.append(b);
    EXPECT_EQ("world", L.get_value_at(1));
    EXPECT_EQ(2, L.listSize());
    L.append(b);
    EXPECT_EQ("world", L.get_value_at(2));
    EXPECT_EQ(3, L.listSize());
    L.insert(c,1);
    EXPECT_EQ("c", L.get_value_at(1));
}
TEST_F(Lab05Fixture, Sort){
    std::string a = "10";
    std::string b = "20";
    std::string c = "30";
    std::string d = "40";
    lab5::linked_list S;
    S.append(d);
    S.append(c);
    S.append(b);
    S.append(a);
    EXPECT_EQ("40", S.get_value_at(0));
    EXPECT_EQ("30", S.get_value_at(1));
    EXPECT_EQ("20", S.get_value_at(2));
    EXPECT_EQ("10", S.get_value_at(3));
    S.sort();
    EXPECT_EQ("10", S.get_value_at(0));
    EXPECT_EQ("20", S.get_value_at(1));
    EXPECT_EQ("30", S.get_value_at(2));
    EXPECT_EQ("40", S.get_value_at(3));


}
TEST_F(Lab05Fixture, Stack){
    lab5::stack S;
    EXPECT_TRUE(S.isEmpty());
    std::string a = "hello";
    std::string b = "world";
    S.push(a);
    EXPECT_EQ("hello", S.top());
    S.push(b);
    EXPECT_EQ("world",S.top());
    EXPECT_EQ(2,S.queueSize());
    S.pop();
    EXPECT_EQ("hello",S.top());
}
TEST_F(Lab05Fixture, Calculator){
    std::string a = "2^3";
    lab5::calculator C(a);
    EXPECT_EQ(8, C.calculate());
}
TEST_F(Lab05Fixture, modelo){
    std::string a = "5%2";
    lab5::calculator C(a);
    EXPECT_EQ(1, C.calculate());
}

TEST_F(Lab05Fixture, complicated){
    std::string a = "2-(3*4/6)+4";
    lab5::calculator C(a);
    EXPECT_EQ(4,C.calculate());
}

TEST_F(Lab05Fixture, Queue_2){
    std::string Test= "Test";
    lab5::queue q1(Test);
    q1.enqueue("Hello");
    EXPECT_EQ("Test", q1.top());
    lab5::queue q2;
    lab5::queue q3(q1);
    q2 = q1;
    EXPECT_EQ("Test", q3.top());
    q1.enqueue("World");
    EXPECT_EQ(3, q1.queueSize());
    EXPECT_EQ("Test", q1.top());
    q1.dequeue();
    EXPECT_EQ("Hello", q1.top());
    EXPECT_EQ(2, q1.queueSize());
    q1.dequeue();
    EXPECT_EQ(1, q1.queueSize());

    EXPECT_EQ("World", q1.top());
    q1.dequeue();
    EXPECT_TRUE(q1.isEmpty());
}
TEST_F(Lab05Fixture, build_test){
    std::string test = "4+2+5+8";
    lab5::calculator obj(test);
    EXPECT_EQ(19, obj.calculate());
}

TEST_F(Lab05Fixture, complicated2){
    std::string a = "10-(2^3)";
    lab5::calculator C(a);
    EXPECT_EQ(2,C.calculate());
}

TEST_F(Lab05Fixture, Fancy_As_Fuck){
    std::string test = "(425%7)*(3^3)-(1+12*(10%7))";
    lab5::calculator obj(test);
    EXPECT_EQ(98, obj.calculate());
}
