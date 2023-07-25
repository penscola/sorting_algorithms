#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
int *count_array, *new_array, max = 0, i, j, sum = 0;

if (array == NULL || size < 2)
return;
for (i = 0; i < (int)size; i++)
{
if (array[i] > max)
max = array[i];
}
count_array = malloc(sizeof(int) * (max + 1));
if (count_array == NULL)
return;
for (i = 0; i < (max + 1); i++)
count_array[i] = 0;
for (i = 0; i < (int)size; i++)
count_array[array[i]] += 1;
for (i = 0; i < (max + 1); i++)
{
sum += count_array[i];
count_array[i] = sum;
}
print_array(count_array, max + 1);
new_array = malloc(sizeof(int) * size);
if (new_array == NULL)
{
free(count_array);
return;
}
for (i = 0; i < (int)size; i++)
{
new_array[count_array[array[i]] - 1] = array[i];
count_array[array[i]] -= 1;
}
for (j = 0; j < (int)size; j++)
array[j] = new_array[j];
free(count_array);
free(new_array);
}
