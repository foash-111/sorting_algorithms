#include<stdio.h>

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
 * bubble_sort - bubble_sorting algorithm
 * @array: array of integers
 * @size: numbers of elements in the array
 * Retrun: (nothing)
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int flag = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				_swap(&array[j], &array[j + 1]);
				flag = 1;
				print_array(array, size);
			}

		}
		if (flag == 0)
		break;
	}


}
