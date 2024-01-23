#include "sort.h"

/**
 * _swap - swap between 2 integers
 * @num1: first number
 * @num2: second number
 * Return: (nothing)
*/

void _swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * selection_sort - selection_sort algorithm
 * @array: array of integers
 * @size: numbers of elements in the array
 * Retrun: (nothing)
*/

void selection_sort(int *array, size_t size)
{
size_t i = 0, j = 0, min_index = 0;

for (i = 0; i < size; i++)
{
	min_index = i;

	for (j = i + 1; j < size; j++)
	{
		if (array[j] < array[min_index])
		min_index = j;
	}

	if (i != min_index)
	{
	_swap(&array[min_index], &array[i]);
	print_array(array, size);
	}
}

}
