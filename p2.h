#ifndef P2_H
#define P2_H

#include "recursive.h"

/* REQUIREMENTS: elt is an integer
 * EFFECTS: returns true if list contains the given element, false if not
 */
bool list_contains(list_t list, int elt);

/*
* REQUIREMENTS: sum is an integer
* EFFECTS: a helper function for sum().
returns the sum of each element in list
*          zero if the list is empty.
*/
static int sum_helper(list_t list, int sum);

/*
 * EFFECTS: returns the sum of each element in list
 *          zero if the list is empty.
 */
int sum(list_t list);

/*
* REQUIREMENTS: product is an integer.
* EFFECTS: a helper function for product().
           returns the product of each element in list
*          one if the list is empty.
*/
static int product_helper(list_t list, int product);

/*
 * EFFECTS: returns the product of each element in list
 *          one if the list is empty.
 */
int product(list_t list);


/*
 * REQUIRES: fn must be associative.
 * EFFECTS:  return identity if list is empty.
 *           Otherwise, return the tail recursive equivalent of
 *           fn(list_first(list), accumulate(list_rest(list), fn, identity).
 *           Be sure to make your code tail recursive!
 *
 * For example, if you have the following function:
 *
 *           int add(int x, int y);
 *
 * Then the following invocation returns the sum of all elements:
 *
 *           accumulate(list, add, 0);
 *
 * The "identity" argument is typically the value for which
 * fn(X, identity) == X and fn(identity, X) == X for any X.
 */
int accumulate(list_t list, int (*fn)(int, int), int identity);

/*
 * EFFECTS: returns the reverse of list
 *
 * For example: the reverse of ( 3 2 1 ) is ( 1 2 3 )
 */
list_t reverse(list_t list);

/*
 * EFFECTS: returns the list (first second)
 */
list_t append(list_t first, list_t second);

/*
 * EFFECTS: returns a new list containing only the elements of the
 *          original list that are odd in value,
 *          in the order in which they appeared in list.
 *
 * For example, if you applied filter_odd to the list ( 4 1 3 0 )
 * you would get the list ( 1 3 )
 */
list_t filter_odd(list_t list);

/*
 * EFFECTS: returns a new list containing only the elements of the
 *          original list that are even in value,
 *          in the order in which they appeared in list.
 *
 * For example, if you applied filter_odd to the list ( 4 1 3 0 )
 * you would get the list ( 4 0 )
 */
list_t filter_even(list_t list);

/*
 * EFFECTS: returns a new list containing precisely the elements of list
 *          for which the predicate fn() evaluates to true, in the
 *          order in which  they appeared in list.
 */
list_t filter(list_t list, bool (*fn)(int));

/*
 * REQUIRES: n >= 0 and n <= the number of elements in first
 * EFFECTS: returns a new list comprising the first n elements of
 *          this list, followed by elt, followed by any remaining
 *          elements of this list.
 *
 *     For example: insert (( 4 5 6 ), 1, 2)
 *            is  ( 4 5 1 6 ).
 */
list_t list_insert(list_t list, int elt, int n);

/*
 * REQUIRES: n >= 0
 * EFFECTS: computes the Nth Fibonacci number
 *          fib(0) = 0
 *          fib(1) = 1
 *          fib(n) = fib(n-1) + fib(n-2) for (n>1).
 * This must be recursive but need not be tail recursive
 */
int fib(int n);

/*
 * REQUIRES: n >= 0
 * EFFECTS: computes the Nth Fibonacci number
 *          fib(0) = 0
 *          fib(1) = 1
 *          fib(n) = fib(n-1) + fib(n-2) for (n>1).
 * MUST be tail recursive
 * Hint: instead of starting at n and workind down, start at
 * 0 and 1 and *upwards*.
 */
int fib_tail(int n);

/*
 * EFFECTS: returns the sum of all elements in the tree,
 *          zero if the tree is empty
 */
int tree_sum(tree_t tree);

/*
 * EFFECTS: returns the elements of tree in a list using an
 *          in-order traversal. An in-order traversal yields a list with
 *          the "left most" element first, then the second-left-most,
 *          and so on, with the right-most element last.
 *
 *          for example, the tree:
 *
 *                           4
 *                         /   \
 *                        /      \
 *                       2        5
 *                      / \      / \
 *                         3
 *                        / \
 *
 *  would return the list
 *
 *       ( 2 3 4 5 )
 *
 * An empty tree would return the list
 *
 *       ( )
 *
 */
list_t traversal(tree_t tree);

/*
 * REQUIRES; tree is a sorted binary tree
 * EFFECTS: returns true if tree contains the given element, false if not
 * MUST be tail recursive
 */
bool tree_contains(tree_t tree, int elt);

/*
 * REQUIRES: n > 0
 * EFFECTS: computes the number of ways to partition n into the sum of
 *          positive integers
 * MUST be tree recursive
 * Hint: Use a helper function that computes the number of ways to
 * partition n using a bounded subset of integers. Then use logic
 * similar to count_change() from lecture to divide partitions into
 * those that use a specific item and those that do not.
 */
int num_partitions(int n);

/*
 * REQUIRES: num_items >= 0, capacity >= 0,
 *           size of item_values >= num_items,
 *           size of item_weights >= num_items,
 *           item_values are all >= 0, item_weights are all >= 0
 * EFFECTS: Computes the maximum value that can be obtained by picking
 *          from a set of num_items items without exceeding the given
 *          capacity. Choosing item i produces the value item_values[i]
 *          but uses weight item_weights[i] out of the available capacity.
 */
int max_value(const int item_values[], const int item_weights[],
              int num_items, int capacity);


#endif /* P2_H */
