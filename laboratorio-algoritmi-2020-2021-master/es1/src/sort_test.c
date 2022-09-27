#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "sort.h"

int cmpint(void* n, void* m)
{
	if (*(int*) n > *(int*) m)
		return 1;
	else if (*(int*) n < *(int*) m)
		return -1;
	else
		return 0;
}

#define SIZE_OF_ARR	10
static void test_is_sort_input_null()
{
	TEST_ASSERT_TRUE(is_sort(NULL, SIZE_OF_ARR, sizeof(int), cmpint) == -1);
}

static void test_is_sort_input_arr_sz_zero()
{
	int a[1] = {0};		//NOTE: uso un array di dimensione > 0 per retrocompatibilitá con C89
	
	TEST_ASSERT_TRUE(is_sort(a, 0, sizeof(int), cmpint));
}

static void test_is_sort_input_elem_sz_zero()
{
	int a[1] = {0};
	
	TEST_ASSERT_TRUE(is_sort(a, 1, 0, cmpint) == -1);
}

static void test_is_sort_arr_ordered()
{
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	
	TEST_ASSERT_TRUE(is_sort(a, SIZE_OF_ARR, sizeof(int), cmpint));
}

static void test_is_sort_arr_unordered()
{
	int a[]={3,7,9,4,0,1,8,2,6,5};
	
	TEST_ASSERT_FALSE(is_sort(a, SIZE_OF_ARR, sizeof(int), cmpint));
}

static void test_merge_input_null()
{
	TEST_ASSERT_TRUE(merge(NULL, 1, NULL, 1, sizeof(int), cmpint) == NULL);
}

static void test_merge_input_zero()
{
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int b[] = {0,1,2,3,4,5,6,7,8,9};
	TEST_ASSERT_TRUE(merge(a, SIZE_OF_ARR, b, SIZE_OF_ARR, 0, cmpint) == NULL);	
}

static int arr_equal(int* arr1_p,  size_t arr1_sz, int* arr2_p, size_t arr2_sz)
{
	unsigned long int i;

	if (arr1_sz != arr2_sz)
		return 0;
	else
		for(i=0; i < arr1_sz; i++)
			if (arr1_p[i] != arr2_p[i])
				return 0;
	return 1;
}

static void test_merge_equal()
{
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int b[] = {0, 0, 1, 1, 2, 2, 3, 3,4, 4,5,5,6,6,7,7,8,8,9,9};
	int* c = (int*) merge(a, SIZE_OF_ARR, a, SIZE_OF_ARR, sizeof(int), cmpint);	
	TEST_ASSERT_TRUE(arr_equal(b, 2 * SIZE_OF_ARR, c, 2 * SIZE_OF_ARR));

}

static void test_merge_int()
{
	int a[] = {0,1,2,3,4,};
	int b[] = {5,6,7,8,9};
	int c[] = {0,1,2,3,4,5,6,7,8,9};
	
	int* d = (int*) merge(a, SIZE_OF_ARR / 2, b, SIZE_OF_ARR / 2, sizeof(int), cmpint);
	TEST_ASSERT_TRUE(arr_equal(c, SIZE_OF_ARR, d, SIZE_OF_ARR));
}

static void test_merge_sort_null()
{
	TEST_ASSERT_TRUE(merge_sort(NULL, 1, sizeof(int), cmpint) == NULL);
}

static void test_merge_sort_zero()
{
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	TEST_ASSERT_TRUE(merge_sort(a, SIZE_OF_ARR, 0, cmpint) == NULL);	
}

static void test_merge_sort_size_one()
{
	int a[] = {0};
	int* b = (int*) merge_sort(a, 1, sizeof(int), cmpint);
	TEST_ASSERT_TRUE(arr_equal(a, 1, b, 1));
}

static void test_merge_sort_ordered()
{
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int* b = (int*) merge_sort(a, SIZE_OF_ARR, sizeof(int), cmpint);
	TEST_ASSERT_TRUE(arr_equal(a, SIZE_OF_ARR, b, SIZE_OF_ARR));
}

static void test_merge_sort_int()
{
	int a[]={3,7,9,4,0,1,8,2,6,5};
	int c[] = {0,1,2,3,4,5,6,7,8,9};
	int* b = (int*) merge_sort(a, SIZE_OF_ARR, sizeof(int), cmpint);
	TEST_ASSERT_TRUE(arr_equal(b, SIZE_OF_ARR, c, SIZE_OF_ARR));
}
/*
static void test_binary_insertion_pos_input_null()
{
	int a[] = {0,1,2,3,4,6,7,8,9,10};
	int elem = 5;
	TEST_ASSERT_TRUE(binary_insertion_pos(NULL, &elem, SIZE_OF_ARR, sizeof(int), cmpint) == -1
		&& binary_insertion_pos(a, NULL, SIZE_OF_ARR, sizeof(int), cmpint) == -1);
}

static void test_binary_insertion_pos_input_zero()
{
	int a[] = {0};
	int elem = 5;
	TEST_ASSERT_TRUE(binary_insertion_pos(a, &elem, 0, sizeof(int), cmpint) == -1);
}

#define CORRECT_INDEX	5
static void test_binary_insertion_pos_int()
{
	int a[] = {0,1,2,3,4,5,6,7,8,9,10};
	int elem = 5;
	TEST_ASSERT_TRUE(binary_insertion_pos(a, &elem, SIZE_OF_ARR, sizeof(int), cmpint) == CORRECT_INDEX);
}
*/
static void test_binary_insertion_sort_null()
{
	TEST_ASSERT_TRUE(binary_insertion_sort(NULL, 1, sizeof(int), cmpint) == NULL);
}

static void test_binary_insertion_sort_zero()
{
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	TEST_ASSERT_TRUE(binary_insertion_sort(a, SIZE_OF_ARR, 0, cmpint) == NULL);	
}

static void test_binary_insertion_sort_int()
{
	int i;
	int a[] = {3,7,9,4,0,1,8,2,6,5};
	int c[] = {0,1,2,3,4,5,6,7,8,9};
	int* b = (int*) binary_insertion_sort(a, SIZE_OF_ARR, sizeof(int), cmpint);
	for (i=0; i < SIZE_OF_ARR; i++)
		printf("%d\t", a[i]);
	printf("\n");
	
	printf("\n");
	
	for (i=0; i < SIZE_OF_ARR; i++)
		printf("%d\t", b[i]);
	printf("\n");
	TEST_ASSERT_TRUE(arr_equal(b, SIZE_OF_ARR, c, SIZE_OF_ARR));
}

int main() {
	UNITY_BEGIN();
	
	RUN_TEST(test_is_sort_input_null);
	RUN_TEST(test_is_sort_input_arr_sz_zero);
	RUN_TEST(test_is_sort_input_elem_sz_zero);	
	RUN_TEST(test_is_sort_arr_ordered);
	RUN_TEST(test_is_sort_arr_unordered);
	RUN_TEST(test_merge_input_null);
	RUN_TEST(test_merge_input_zero);
	RUN_TEST(test_merge_equal);
	RUN_TEST(test_merge_int);
	RUN_TEST(test_merge_sort_null);
	RUN_TEST(test_merge_sort_zero);
	RUN_TEST(test_merge_sort_ordered);
	RUN_TEST(test_merge_sort_int);
	/*
	RUN_TEST(test_binary_insertion_pos_input_null);
	RUN_TEST(test_binary_insertion_pos_input_zero);
	RUN_TEST(test_binary_insertion_pos_int);
	*/
	RUN_TEST(test_binary_insertion_sort_null);
	RUN_TEST(test_binary_insertion_sort_zero);
	RUN_TEST(test_binary_insertion_sort_int);
	
	return UNITY_END();
}
