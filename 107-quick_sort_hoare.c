#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive_hoare(array, size, 0, size - 1);
}

/**
 * quick_sort_recursive_hoare - recursive function for quick sort
 * @array: array to sort
 * @size: size of the array
 * @start: start index
 * @end: end index
 */
void quick_sort_recursive_hoare(int *array, size_t size, ssize_t start, ssize_t end)
{
ssize_t pivot;

if (end - start < 1)
return;

pivot = hoare_partition(array, size, start, end);
quick_sort_recursive_hoare(array, size, start, pivot - 1);
quick_sort_recursive_hoare(array, size, pivot, end);
}

/**
 * hoare_partition - partitions an array using the Hoare scheme
 * @array: array to sort
 * @size: size of the array
 * @start: start index
 * @end: end index
 *
 * Return: index of the pivot
 */
ssize_t hoare_partition(int *array, size_t size, ssize_t start, ssize_t end)
{
ssize_t i = start - 1, j = end + 1;
int pivot = array[end], tmp;

while (1)
{
do {
i++;
} while (array[i] < pivot);

do {
j--;
} while (array[j] > pivot);

if (i >= j)
return (i);

tmp = array[i];
array[i] = array[j];
array[j] = tmp;
print_array(array, size);
}
}
