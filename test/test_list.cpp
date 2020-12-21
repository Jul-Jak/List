#pragma once
#include <translator.h>

#include "gtest.h""
TEST(TStack, can_create_stack_with_positive_size) {
	ASSERT_NO_THROW(TStack<int> s(100));
}
TEST(TStack, throws_when_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> s(-10));
}
TEST(TStack, trows_when_create_stack_with_too_large_size) {
	ASSERT_ANY_THROW(TStack<int> s(STACK_MAX_SIZE + 1));
}
TEST(TStack, can_create_copied_stack) {
	TStack<int> st1(100);
	ASSERT_NO_THROW(TStack<int> st2(st1));
}
TEST(TStack, copied_stack_is_equal_to_source_one) {
	TStack<int> st1(100);
	st1.push(2);
	TStack<int> st2(st1);
	EXPECT_EQ(st1.pop(), st2.pop());
}
TEST(TStack, isfull_method_return_true_when_stack_is_full) {
	TStack<int> s(1);
	s.clear();
	s.push(1);
	EXPECT_TRUE(s.isFull());
}
TEST(TStack, isfull_method_return_false_when_stack_isnt_full) {
	TStack<int> s(2);
	s.clear();
	s.push(1);
	EXPECT_FALSE(s.isFull());
}
TEST(TStack, isempty_method_return_true_when_stack_is_empty) {
	TStack<int> s(1);
	s.clear();
	EXPECT_TRUE(s.isEmpty());
}
TEST(TStack, isempty_method_return_false_when_stack_isnt_empty) {
	TStack<int> s(3);
	s.push(1);
	EXPECT_FALSE(s.isEmpty());
}
TEST(TStack, can_get_top) {
	TStack<int> s(3);
	s.push(1);
	ASSERT_NO_THROW(s.top());
}
TEST(TStack, push_work_corretly) {
	TStack<int> s(3);
	s.clear();
	s.push(2);
	EXPECT_EQ(2, s.top());
}
TEST(TStack, pop_correct_value) {
	TStack<int> s(3);
	s.clear();
	s.push(3);
	EXPECT_EQ(3, s.pop());
}
TEST(TStack, pop_move_pointer_back) {
	TStack<int> s(5);
	s.clear();
	s.push(3);
	s.push(2);
	s.pop();
	EXPECT_EQ(3, s.top());
}
TEST(TStack, can_puch_element_in_full_stack_by_repackaging) {
	TStack<int> s(2);
	s.push(2);
	s.push(4);
	s.push(6);
	s.push(8);
	EXPECT_EQ(8, s.top());
}
TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int>s);
}

TEST(TQueue, can_push_element_in_queue)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q.push(1));
}

TEST(TQueue, no_throw_when_push_element_in_full_queue)
{
	TQueue<int> q(1);
	q.push(1);
	ASSERT_NO_THROW(q.push(2));
}

TEST(TQueue, can_pop_element_from_queue)
{
	TQueue<int> q(5);
	q.push(1);
	q.push(2);
	q.push(3);
	ASSERT_NO_THROW(q.pop());
}

TEST(TQueue, throws_when_pop_from_empty_queue)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, no_throw_when_many_pushes_and_pops)
{
	TQueue<int> q(7);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	q.push(6);
	q.pop();
	q.push(6);
	q.push(7);
	ASSERT_NO_THROW(q.pop());
}

TEST(TQueue, right_algoritm)
{
	TQueue<int> q(3);
	q.push(1);
	q.push(2);
	q.push(3);
	q.pop();
	q.push(4);
	q.pop();
	q.push(8);
	EXPECT_EQ(8, q[2]);
}

TEST(TQueue, can_return_element)
{
	TQueue<int> q(1);
	q.push(1);
	ASSERT_NO_THROW(q[0]);
}

TEST(TQueue, throws_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-1));
}

TEST(Translator, do_not_throw_when_try_transform_infix_in_postfix)
{
	Translator a;
	a.setInfix("3+2");
	ASSERT_NO_THROW(a.GoToPostfix());
}

TEST(Translator, can_add_elements)
{
	Translator a;
	a.setInfix("2+3+4");
	a.GoToPostfix();
	EXPECT_EQ(9, a.GoToCalculate());
}
TEST(Translator, can_sub_elem_of_elem)
{
	Translator a;
	a.setInfix("2-3");
	a.GoToPostfix();
	EXPECT_EQ(-1, a.GoToCalculate());
}

TEST(Translator, can_mult_elem_no_elem)
{
	Translator a;
	a.setInfix("2*3*4");
	a.GoToPostfix();
	EXPECT_EQ(24, a.GoToCalculate());
}
TEST(Translator, can_div_elem_on_elem)
{
	Translator a;
	a.setInfix("5/4");
	a.GoToPostfix();
	EXPECT_EQ(1.25, a.GoToCalculate());
}

TEST(Translator, can_use_brackets)
{
	Translator a;
	a.setInfix("(2+3)*2");
	a.GoToPostfix();
	EXPECT_EQ(10, a.GoToCalculate());
}

TEST(Translator, can_add_int_to_double)
{
	Translator a;
	a.setInfix("2.2+2");
	a.GoToPostfix();
	EXPECT_EQ(4.2, a.GoToCalculate());
}

TEST(Translator, can_add_double_to_double)
{
	Translator a;
	a.setInfix("2.2+2.4");
	a.GoToPostfix();
	EXPECT_EQ(4.6, a.GoToCalculate());
}

TEST(Translator, can_mult_int_with_double)
{
	Translator a;
	a.setInfix("2.1*5");
	a.GoToPostfix();
	EXPECT_EQ(10.5, a.GoToCalculate());
}
TEST(Translator, can_mult_double_with_double)
{
	Translator a;
	a.setInfix("2.2*2.94");
	a.GoToPostfix();
	EXPECT_EQ(6.468, a.GoToCalculate());
}
TEST(Translator, cant_introduce_wrong_string_exp_1)
{
	Translator a;
	a.setInfix("2.2+-2");
	EXPECT_EQ(false, a.GoToPostfix());
}
TEST(Translator, cant_introduce_wrong_string_exp_2)
{
	Translator a;
	a.setInfix("2.2-/2--2");
	EXPECT_EQ(false, a.GoToPostfix());
}
TEST(Translator, cant_introduce_wrong_string_exp_3)
{
	Translator a;
	a.setInfix("(2.2-2-))2");
	EXPECT_EQ(false, a.GoToPostfix());
}

TEST(Translator, cant_introduce_wrong_string_exp_4)
{
	Translator a;
	a.setInfix("5..02+2");
	//std::cout << a.getInfix() << std::endl;
	//a.GoToPostfix();
	//std::cout << a.getPostfix() << std::endl;
	//std::cout << a.GoToCalculate() << std::endl;
	EXPECT_EQ(false, a.GoToPostfix());
}

TEST(Translator, cant_introduce_wrong_string_exp_5)
{
	Translator a;
	a.setInfix("2.2.45+2");
	//std::cout << a.getInfix() << std::endl;
	//a.GoToPostfix();
	//std::cout << a.getPostfix() << std::endl;
	//std::cout << a.GoToCalculate() << std::endl;
	EXPECT_EQ(false, a.GoToPostfix());
}

TEST(Translator, cant_introduce_wrong_string_exp_6)
{
	Translator a;
	a.setInfix(".2.2+2");
	//std::cout << a.getInfix() << std::endl;
	EXPECT_EQ(false, a.GoToPostfix());
}

TEST(Translator, cant_introduce_wrong_string_exp_7)//
{
	Translator a;
	a.setInfix("7..+12");
	//std::cout << a.getInfix() << std::endl;
	//a.GoToPostfix();
	//std::cout << a.getPostfix() << std::endl;
	//std::cout << a.GoToCalculate() << std::endl;
	EXPECT_EQ(false, a.GoToPostfix());
}

TEST(Translator, cant_introduce_wrong_string_exp_8)
{
	Translator a;
	a.setInfix("+-*/");
	//std::cout << a.getInfix() << std::endl;
	EXPECT_EQ(false, a.GoToPostfix());
}

TEST(Translator, cant_introduce_wrong_string_exp_9)
{
	Translator a;
	a.setInfix(".2-0.1");
	//std::cout << a.getInfix() << std::endl;
	//a.GoToPostfix();
	//std::cout << a.getPostfix() << std::endl;
	//std::cout << a.GoToCalculate() << std::endl;
	EXPECT_EQ(false, a.GoToPostfix());
}

TEST(Translator, can_introduce_well_string_exp1)
{
	Translator a;
	a.setInfix("4.2+1.");
	//std::cout << a.getInfix() << std::endl;
	//a.GoToPostfix();
	//std::cout << a.getPostfix() << std::endl;
	//std::cout << a.GoToCalculate() << std::endl;
	EXPECT_EQ(true, a.GoToPostfix());
}

TEST(Translator, can_introduce_well_string_exp2)
{
	Translator a;
	a.setInfix("2.2+2-2+1");
	EXPECT_EQ(true, a.GoToPostfix());
}

TEST(Translator, can_calculate_dificult_example)
{
	Translator a;
	a.setInfix("2.2*2.94+1*(7/8)");
	std::cout << a.getInfix() << std::endl;
	a.GoToPostfix();
	std::cout << a.getPostfix() << std::endl;
	std::cout << a.GoToCalculate() << std::endl;
	EXPECT_EQ(7.343, a.GoToCalculate());
}

TEST(Translator, cant_div_on_zero)
{
	Translator a;
	a.setInfix("7/0");
	//std::cout << a.getInfix() << std::endl;
	a.GoToPostfix();
	//std::cout << a.getPostfix() << std::endl;
	//std::cout << a.GoToCalculate() << std::endl;
	EXPECT_EQ(-404, a.GoToCalculate());
}

TEST(Translator, cant_introduce_string_started_in_minus)
{
	Translator a;
	a.setInfix("-2+4");
	//std::cout << a.getInfix() << std::endl;
	//a.GoToPostfix();
	//std::cout << a.getPostfix() << std::endl;
	//std::cout << a.GoToCalculate() << std::endl;
	EXPECT_EQ(false, a.GoToPostfix());
}