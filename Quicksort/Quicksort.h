#ifndef	QUICKSORT_H
#define	QUICKSORT_H

/**
 * Compares elements of primary data types
 * @param a - first element
 * @param b - second element
 * @return true if a < b
 */
const auto comparator_lambda = [](auto a, auto b) { return a < b; };

/**
 * Compares elements of primary data types in reverse order
 * @param a - first element
 * @param b - second element
 * @return true if a > b
 */
const auto comparator_lambda_revers = [](auto a, auto b) { return a > b; };

/**
 * Experimentally found interval length after which the sorting type changes
 */
const int g_sortIntersection = 13;

/**
 * Swap elements
 * @tparam T - data type
 * @param a - pointer to the first element
 * @param b - pointer to the second element
 */
template<typename T>
void swap(T* a, T* b);

/**
 * Function that selects the sort type.
 * If the interval length is less than g_sortIntersection - use insertion sort,
 * if the interval length is more than g_sortIntersection - use quick sort
 * @tparam T - data type
 * @param first - pointer to the first element of the sorted interval
 * @param last - pointer to the second element of the sorted interval
 * @param comp - comparison function
 */
template <typename T, typename Compare>
void sort(T* first, T* last, Compare comp);

/**
 * Insertion sort
 * @tparam T - data type
 * @param first - pointer to the first element of the sorted interval
 * @param last - pointer to the second element of the sorted interval
 * @param comp - comparison function
 */
template <typename T, typename Compare>
void insertion_sort(T* first, T* last, Compare comp);

/**
 * Returns the pivot element of the interval, 
 * which is the median of the first, last, and middle elements of the interval
 * @tparam T - data type
 * @param first - pointer to the first element of the sorted interval
 * @param last - pointer to the second element of the sorted interval
 * @param comp - comparison function
 */
template <typename T, typename Compare>
T pivot_find(T* first, T* last, Compare comp);

/**
 * Elements more than the pivot element are sent to the right interval,
 * less than the reference - to the left
 * @tparam T - data type
 * @param first - pointer to the first element of the sorted interval
 * @param last - pointer to the second element of the sorted interval
 * @param pivot -pivot element
 * @param comp - comparison function
 */
template <typename T, typename Compare>
int partition(T* first, T* last, T pivot, Compare comp);

/**
 * Quick sort
 * @tparam T - data type
 * @param first - pointer to the first element of the sorted interval
 * @param last - pointer to the second element of the sorted interval
 * @param comp - comparison function
 */
template <typename T, typename Compare>
void quick_sort(T* first, T* last, Compare comp);

#include "quicksort_impl.h"

#endif	QUICKSORT_H