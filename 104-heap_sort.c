#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @a: first integer
 * @b: second integer
 *
 * Return: No Return
 */
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * heapify - heapifies a subtree
 *
 * @array: array to heapify
 * @size: size of the array
 * @i: index to heapify at
 * @len: size of the array to print
 *
 * Return: No Return
 */
void heapify(int *array, size_t size, int i, size_t len)
{
int max = i;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < (int)size && array[left] > array[max])
max = left;

if (right < (int)size && array[right] > array[max])
max = right;

if (max != i)
{
swap(&array[i], &array[max]);
print_array(array, len);
heapify(array, size, max, len);
}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: No Return
 */
void heap_sort(int *array, size_t size)
{
int i;

if (!array || size < 2)
return;

for (i = size / 2 - 1; i >= 0; i--)
heapify(array, size, i, size);

for (i = size - 1; i > 0; i--)
{
swap(&array[0], &array[i]);
print_array(array, size);
heapify(array, i, 0, size);
}
}
