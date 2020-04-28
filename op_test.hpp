#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "Operations.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}
TEST(OpTest, DoesAddWork) {
	Op* test1=new Op(1);
	Op* test2=new Op(2);
	Base* result=new Add(test1->evaluate(),test2->evaluate());
	EXPECT_EQ(result->evaluate(),3);
}
TEST(OpTest, DoesSubWork) {
	Op* test1=new Op(2);
	Op* test2=new Op(1);
	Base* result=new Sub(test1->evaluate(),test2->evaluate());
	EXPECT_EQ(result->evaluate(),1);
}

TEST(OpTest, DoesSubWork_Negative){                                                                           
	Op* test1=new Op(2);  
	Op* test2=new Op(3);   
	Base* result=new Sub(test1->evaluate(),test2->evaluate());     
	EXPECT_EQ(result->evaluate(),-1);  
}
TEST(OpTest, DoesMultWork){
	Op* test1=new Op(5);
	Op* test2=new Op(4);
	Base* result= new Mult(test1->evaluate(),test2->evaluate());
	EXPECT_EQ(result->evaluate(),20);
}
TEST(OpTest, DoesDivWork){
	Op* test1=new Op(10);
	Op* test2=new Op(2);
	Base* result= new Div(test1->evaluate(), test2->evaluate());
	EXPECT_EQ(result->evaluate(),5);
}
TEST(OpTest, MultAdd)
{
	Op* test1=new Op(2);
	Op* test2=new Op(3);
	Base* a=new Add(test1->evaluate(),test2->evaluate());
	Base* b= new Mult(a->evaluate(), test1->evaluate());
	EXPECT_EQ(b->evaluate(), 10);
}
#endif //__OP_TEST_HPP__
