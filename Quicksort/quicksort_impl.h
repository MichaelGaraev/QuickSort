#ifndef QUICKSORT_IMPL_H
#define QUICKSORT_IMPL_H

template<typename T>
void swap(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template <typename T, typename Compare>
void sort(T* first, T* last, Compare comp)
{
	int len = (last - first) + 1;

	if (len < 2)
	{
		return;
	}

	if (len > g_sortIntersection)
	{
		quick_sort(first, last, comp);
	}
	else
	{
		insertion_sort(first, last, comp);
	}
}

template <typename T, typename Compare>
void insertion_sort(T* first, T* last, Compare comp)
{
	if (last - first < 1)
	{
		return;
	}

	for (int i = 0; first + i < last; i++)
	{
		T temp = *(first + i + 1);
		int j = i;
		while (j >= 0 && comp(temp, *(first + j)))
		{
			*(first + j + 1) = *(first + j);
			j--;
		}
		*(first + j + 1) = temp;
	}
}

template <typename T, typename Compare>
T pivot_find(T* first, T* last, Compare comp)
{
	T temp_array[3];
	T* middle = first + (last - first) / 2;
	temp_array[0] = *first;
	temp_array[1] = *middle;
	temp_array[2] = *last;
	insertion_sort(temp_array, temp_array + 2, comp);
	return temp_array[1];
}

template <typename T, typename Compare>
int partition(T* first, T* last, T pivot, Compare comp)
{
	int len = (last - first) + 1;
	int lo = 0;
	int hi = len - 1;

	while (lo < hi) 
	{
		if (first[lo] == first[hi])
		{
			lo++;
		}

		while (comp(first[lo], pivot))
		{
			lo++;
		}

		while (comp(pivot, first[hi]))
		{
			hi--;
		}

		if (lo < hi) 
		{
			swap(&first[lo], &first[hi]);
		}
	}
	return hi;
}

template <typename T, typename Compare>
void quick_sort(T* first, T* last, Compare comp)
{
	while (last - first > 0)
	{
		T pivot = pivot_find(first, last, comp);
		int partition_id = partition(first, last, pivot, comp);

		if (partition_id < (last - first) / 2)
		{
			sort(first, first + partition_id - 1, comp);
			first = first + partition_id + 1;
		}
		else
		{
			sort(first + partition_id + 1, last, comp);
			last = first + partition_id - 1;
		}
	}
}

#endif QUICKSORT_IMPL_H
