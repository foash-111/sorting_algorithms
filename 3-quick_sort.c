#include "sort.h"

/**
 * lomuto - function to partition the passed array
 *
 * @array: the array to be partitiones
 * @lower_bound: the first index of the array
 * @upper_bound: the max index of the array
 * @size: the size if the array
 */

void lomuto(int *array, int lower_bound, int upper_bound, size_t size)
{
	int pivot = array[upper_bound];
	int i, j = lower_bound;

	if (lower_bound > upper_bound)
		return;
	for (i = lower_bound; i < upper_bound; i++)
	{
		if (array[i] <= pivot)
		{
			if (array[i] != array[j])
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size); }
			j++;
		}
	}
	if (array[j] != array[upper_bound])
	{
		swap_int(&array[j], &array[upper_bound]);
		print_array(array, size); }
	lomuto(array, lower_bound, j - 1, size);
	lomuto(array, j + 1, upper_bound, size);
}

/**
 *swap_int - swaps two integer
 *
 * @num1: address of the first number
 * @num2: address of the second number
 */

void swap_int(int *num1, int *num2)
{
	int temp = *num1;

	*num1 = *num2;
	*num2 = temp;
}

/**
 * quick_sort - function that sorts array ascendengly using quick sort algorith
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto(array, 0, size - 1, size);
}
