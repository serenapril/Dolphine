#include "p2.h"
#include "recursive.h"
#include <iostream>
#include <cassert>

using namespace std;

/*
* EFFECTS: returns true if list contains the given element, false if not
*/
bool list_contains(list_t list, int elt) {
	// base case
	if (elt == list_first(list)) {
		return true;
	}
	if (list_isEmpty(list_rest(list))) {
		return false;
	}

	// recursive case
	return list_contains(list_rest(list), elt);
}

/*
* REQUIREMENTS: sum is an integer
* EFFECTS: a helper function for sum(). 
           returns the sum of each element in list
*          zero if the list is empty.
*/
static int sum_helper(list_t list, int sum) {
	// base case
	if (list_isEmpty(list)) {
		return sum;
	}

	// recursive case
	sum += list_first(list);
	return sum_helper(list_rest(list), sum);
}

/*
* EFFECTS: returns the sum of each element in list
*          zero if the list is empty.
*/
int sum(list_t list) {

	return sum_helper(list, 0);
}

/*
* REQUIREMENTS: product is an integer.
* EFFECTS: a helper function for product().
           returns the product of each element in list
*          one if the list is empty.
*/
static int product_helper(list_t list, int product) {
	// base case
	if (list_isEmpty(list)) {
		return product;
	}

	// recursive case
	product *= list_first(list);
	return product_helper(list_rest(list), product);
}


/*
* REQUIRES: fn must be associative.
* EFFECTS:  return identity if list is empty.
*           Otherwise, return the tail recursive equivalent of
*           fn(list_first(list), accumulate(list_rest(list), fn, identity).
*           Be sure to make your code tail recursive!
*/
int accumulate(list_t list, int(*fn)(int, int), int identity) {
	// base case 
	if (list_isEmpty(list)) {
		return identity;
	}

	// recursive case
	identity += list_first(list);
	return accumulate(list_rest(list), fn, identity);
}
