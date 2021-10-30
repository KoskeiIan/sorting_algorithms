#include "sort.h"

/**
 * partitioner - find position of pivot element in array
 * @array: array to be sorted
 * @low: lower boundary of array
 * @high: upper bound of array
 * @size: size of the array
 *
 * Return: position of pivot
 */

int partitioner(int *array, int low, int high, size_t size)
{
int pivot = array[high], temp, i = low - 1, j;

for (j = low; j <= high; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
temp = array[j];
array[j] = array[i];
array[i] = temp;
print_array(array, size);
}
}
}
return (i);
}

/**
 * quick_sort - sort a certain range of an array of integers
 * @array: array to be sorted
 * @low: lower boundary of range to be sorted
 * @high: upper boundary of range to be sorted
 * @size: size of whole array
 *
 * Return: no return value (void)
 */
void quick_sort(int *array, int low, int high, size_t size)
{
int part = 0;

if (low < high)
{
part = partitioner(array, low, high, size);
quick_sort(array, low, part - 1, size);
quick_sort(array, part + 1, high, size);
}
}

/**
 * quicksort - sort an array of integers in ascending order
 * @array: pointer to first element of array to be sorted
 * @size: size of the array
 *
 * Return: no return value (void)
 */
void quicksort(int *array, size_t size)
{
if (size < 2)
return;

quick_sort(array, 0, size - 1, size);
}
