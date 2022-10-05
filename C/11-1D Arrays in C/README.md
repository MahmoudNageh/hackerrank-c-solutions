# 1D Arrays in C
## Medium

### Objective

An array is a container object that holds a fixed number of values of a single type. To create an array in C, we can do int arr[n];. Here, arr, is a variable array which holds up to 10 integers. The above array is a static array that has memory allocated at compile time. A dynamic array can be created in C, using the malloc function and the memory is allocated on the heap at runtime. To create an integer array, arr of size n, int *arr = (int*)malloc(n * sizeof(int)), where arr points to the base address of the array. When you have finished with the array, use free(arr) to deallocate the memory.

In this challenge, create an array of size n dynamically, and read the values from stdin. Iterate the array calculating the sum of all elements. Print the sum and free the memory where the array is stored.

While it is true that you can sum the elements as they are read, without first storing them to an array, but you will not get the experience working with an array. Efficiency will be required later.

### Input Format

The first line contains an integer, n.
The next line contains  space-separated integers.


### Output Format

Print the sum of the integers in the array.

### Sample Input 0
```
6
16 13 7 2 1 12 
```
### Sample Output 0
```
51
```
### Sample Input 1
```
7
1 13 15 20 12 13 2 
```
### Sample Output 1
```
76
```
