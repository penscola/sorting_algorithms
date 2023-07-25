#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

bitonic_sort_recursive(array, size, 0, size, 1);
}

/**
 * bitonic_sort_recursive - recursive function for bitonic sort
 * @array: array to sort
 * @size: size of the array
 * @start: start index
 * @end: end index
 * @dir: direction of sort
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t end, int dir)
{
size_t mid = (end - start) / 2;

if (end - start < 2)
return;

printf("Merging [%lu/%lu] (%s):\n", end - start, size, dir == 1 ? "UP" : "DOWN");
print_array(array + start, end - start);

bitonic_sort_recursive(array, size, start, start + mid, 1);
bitonic_sort_recursive(array, size, start + mid, end, 0);
bitonic_merge(array, size, start, end, dir);

printf("Result [%lu/%lu] (%s):\n", end - start, size, dir == 1 ? "UP" : "DOWN");
print_array(array + start, end - start);
}

/**
 * bitonic_merge - merges two subarrays in bitonic sort
 * @array: array to sort
 * @size: size of the array
 * @start: start index
 * @end: end index
 * @dir: direction of sort
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t end, int dir)
{
size_t i, mid = (end - start) / 2;
int tmp;

if (end - start < 2)
return;

for (i = start; i < start + mid; i++)
{
if (dir == (array[i] > array[i + mid]))
{
tmp = array[i];
array[i] = array[i + mid];
array[i + mid] = tmp;
}
}

bitonic_merge(array, size, start, start + mid, dir);
bitonic_merge(array, size, start + mid, end, dir);
}
