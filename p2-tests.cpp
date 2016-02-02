#include "p2.h"

#include  "test_helpers.h"

#include <iostream>
#include <cassert>

using namespace std;

// YOU MUST EXTEND THE MAIN FUNCTION IN THIS FILE SO THAT IT TESTS EVERY
// PUBLIC FUNCTION YOU IMPLEMENT IN P2.CPP!
//
// Protip #1: Write tests for the functions BEFORE you implement them!
// (i.e. Write tests for sum() first, and then write sum())
// It sounds like a pain, but it helps make sure that you are never under the
// illusion that your code works when it's actually full of bugs.
//
// Protip #2: Instead of putting all your tests in main() (and making life
// more difficult--especially for the graders), put each test case in a
// function!
//
//
// We recommend using the functions in test_helpers.h when
// writing your test cases.
//

void test_sum_basic();
// ---- Add prototypes for your test cases here ----

void test_list_contains();

void test_sum_case1();
void test_sum_case2();

void test_product_case1();
void test_product_case2();
void test_product_case3();




int main()
{
    // test_sum_basic();
    // ---- Call your test functions here ----

	test_list_contains();

	test_sum_case1();
	test_sum_case2();

	test_product_case1();
	test_product_case2();
	test_product_case3();

    return 0;
}

/* void test_sum_basic()
{
    // Here's a free test case! You can model your tests after this one.
    list_t listA = list_make();

    for (int i = 0; i < 5; ++i)
    {
        listA = list_make(i, listA);
    }

    const int EXPECTED_SUM = 10;
    int actual_sum = sum(listA);
    cout << "Expected sum: " << EXPECTED_SUM << endl;
    cout << "Actual sum: " << actual_sum << endl;
    assert(EXPECTED_SUM == actual_sum);

    cout << "PASS!" << endl;
}*/

// ---- Add your test function implementations here ----

void test_list_contains() {
	list_t list1 = list_make();

	for (int i = 0; i < 5; ++i)
	{
		list1 = list_make(i, list1);
	}

	assert(list_contains(list1, 0));
	assert(!list_contains(list1, 5));

	cout << "PASS!" << endl;
}

void test_sum_case1() {
	list_t list1 = list_make();

	for (int i = 0; i < 5; ++i)
	{
		list1 = list_make(i, list1);
	}

	assert(sum(list1) == 10);
	
	cout << "PASS!" << endl;
}

void test_sum_case2() {
	list_t list2 = list_make();

	assert(sum(list2) == 0);

	cout << "PASS!" << endl;
}

void test_product_case1() {
	list_t list1 = list_make();

	for (int i = 0; i < 5; ++i)
	{
		list1 = list_make(i, list1);
	}

	assert(product(list1) == 0);

	cout << "PASS!" << endl;
}

void test_product_case2() {
	list_t list2 = list_make();

	for (int i = 1; i < 5; ++i)
	{
		list2 = list_make(i, list2);
	}

	assert(product(list2) == 24);

	cout << "PASS!" << endl;
}

void test_product_case3() {
	list_t list3 = list_make();

	assert(product(list3) == 1);

	cout << "PASS!" << endl;
}

void test_accumulate() {
	
}
