#include "pch.h"
#include "../Quicksort/quicksort.h"

//  testing on 500 random int
//  295 972 nanoseconds - this quicksort
//  725 581 nanoseconds - std::sort

template<typename T>
bool is_equal(T* first, T* second, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (first[i] != second[i])
        {
            return false;
        }
    }
    return true;
}

TEST(SortTest, pivot_test)
{
    const int len = 7;
    int array_test[len] = { 6, 5, 4, 3, 2, 1, 0 };

    int pivot = pivot_find(array_test, array_test + len - 1, comparator_lambda);
    ASSERT_EQ(pivot, 3);
}

TEST(SortTest, int_array)
{
    const int len = 10;
    int array_test[len] = { 3, 0, 1, 8, 7, 2, 5, 4, 9, 6 };
    int correct_array[len] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort(array_test, array_test + len - 1, comparator_lambda);
    ASSERT_EQ(is_equal(correct_array, array_test, len), true);
}

TEST(SortTest, int_array_500)
{
    const int len = 500;
    int array_test[len] = { };
    int correct_array[len] = { };
    for (int i = 0; i < len; i++)
    {
        array_test[i] = 499 - i;
        correct_array[i] = i;
        //   std::cout << std::endl;
       //    std::cout << array_test[i] << " ";
    }
    std::cout << std::endl;
    sort(array_test, array_test + len - 1, comparator_lambda);
    ASSERT_EQ(is_equal(correct_array, array_test, len), true);
}

TEST(SortTest, int_array_revers_comp)
{
    const int len = 10;
    int array_test[len] = { 3, 0, 1, 8, 7, 2, 5, 4, 9, 6 };
    int correct_array[len] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    sort(array_test, array_test + len - 1, comparator_lambda_revers);
    std::cout << std::endl;
    ASSERT_EQ(is_equal(correct_array, array_test, len), true);
}

TEST(SortTest, reverse)
{
    const int len = 10;
    int array_test[len] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int correct_array[len] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    sort(array_test, array_test + len - 1, comparator_lambda);
    ASSERT_EQ(is_equal(correct_array, array_test, len), true);
}

TEST(SortTest, sorted_array_test)
{
    const int len = 10;
    int array_test[len] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int correct_array[len] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    sort(array_test, array_test + len - 1, comparator_lambda);
    ASSERT_EQ(is_equal(correct_array, array_test, len), true);
}

TEST(SortTest, single_element_test)
{
    const int len = 1;
    int array_test[len] = { 5 };
    int correct_array[len] = { 5 };

    sort(array_test, array_test + len - 1, comparator_lambda);
    ASSERT_EQ(is_equal(correct_array, array_test, len), true);
}

TEST(SortTest, float_array)
{
    const int len = 10;
    float array_test[len] = { 7.00125, 0.193304, 4.58501, 8.35029, 4.82284, 5.17411, 7.7105, 1.30399, 2.0914, 6.14731 };
    float correct_array[len] = { 0.193304, 1.30399, 2.0914, 4.58501, 4.82284, 5.17411, 6.14731, 7.00125, 7.7105, 8.35029 };
    sort(array_test, array_test + len - 1, comparator_lambda);
    ASSERT_EQ(is_equal(correct_array, array_test, len), true);
}

TEST(SortTest, char_array)
{
    const int len = 10;
    char array_test[len] = { 'q', 'u', 'i', 'c', 'k', 's', 'o', 'r', 't', 's' };
    char correct_array[len] = { 'c', 'i', 'k', 'o', 'q', 'r', 's', 's', 't', 'u' };
    sort(array_test, array_test + len - 1, comparator_lambda);
    ASSERT_EQ(is_equal(correct_array, array_test, len), true);
}


struct items {
    int id;
    int amount;

    friend bool operator==(items a1, items a2)
    {
        return a1.amount == a2.amount;
    }
};

auto comp_lambda_class = [](items a1, items a2) {return a1.amount != a2.amount; };

template<typename T>
bool is_equal_class(T* first, T* second, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (comp_lambda_class(first[i], second[i]))
        {
            return false;
        }
    }
    return true;
}

TEST(SortTest, class_custom_int)
{
    const int len = 2;
    items array_arrows[len] = { items{20, 22}, items{0, 16} };
    items correct_array[len] = { items{0, 16}, items{20, 22} };
    sort(array_arrows, array_arrows + 1, [](items a1, items a2) {return a1.amount < a2.amount; });
    ASSERT_EQ(is_equal_class(array_arrows, correct_array, len), true);
}