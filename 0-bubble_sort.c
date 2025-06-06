#include "sort.h"

/**
 * bubble_sort - check the code
 * @array: est un int pointeur
 * @size: est une taille
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swap = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swap = 1;
			}
		}

		if (swap == 0)
			break;
	}
}
