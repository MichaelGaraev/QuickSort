#include <iostream>
#include <algorithm>
#include "Quicksort.h"

int main(int argc, char* argv[])
{
	const int len = 10;
	int array_test[len] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	sort(array_test, array_test + len - 1, comparator_lambda);

	for (int i = 0; i < len; i++)
	{
		std::cout << array_test[i] << " ";
	}

	return 0;
}