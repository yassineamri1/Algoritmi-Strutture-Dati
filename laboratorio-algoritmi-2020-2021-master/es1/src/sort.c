#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "utility.h"


int is_sort(void* arr_p, size_t arr_sz, size_t elem_sz, int (*cmp)(void*, void*)) {
	size_t i;
	int is_order = -1;

	if (arr_p == NULL || elem_sz < 1 || cmp == NULL)
		errno = EINVAL;
	else
		is_order = 1;

	for (i = 1; i < arr_sz && is_order > 0; i++)
		if (cmp(index_to_p(arr_p, i - 1, elem_sz), index_to_p(arr_p, i, elem_sz)) > 0)
			is_order = 0;
	return is_order;
}

void _print_int_array(void* arr_p, size_t sz_arr) {
	int i;
	for (i = 0; i < sz_arr; i++)
		printf("\t %d", *(int*)index_to_p(arr_p, i, sizeof(int)));
	printf("\n");
}

#define EQUAL 	 0
#define GREAT	 1
#define LESS	-1

size_t _find_position_to_ins(void* arr_p, int start, int end, void* elem, size_t sz_elem, int (*cmp)(void*, void*))
{
	size_t mid_pos;
	
	if (start >= end) {
		if (cmp(elem, index_to_p(arr_p, start, sz_elem)) == 1) {
			return start + 1;
		} else {
			return start;
		}
	} else {
		mid_pos = (start + end) / 2;
		
		switch (cmp(elem, index_to_p(arr_p, mid_pos, sz_elem))) {
		case EQUAL:
			return mid_pos + 1;
		case GREAT:
			return _find_position_to_ins(arr_p, mid_pos + 1, end, elem, sz_elem, cmp);
		case LESS:
			return _find_position_to_ins(arr_p, start, mid_pos - 1, elem, sz_elem, cmp);			
		default:	
			printf("unexpeted return valued from compare function");
			return 0;
		}
	}
}

void* binary_insertion_sort(void* arr_p, size_t sz_arr, size_t sz_elem, int (*cmp)(void*, void*))
{
	size_t i, j, pos;
	void* current_elem;

	if (arr_p == NULL || sz_elem < 1 || cmp == NULL) {
		errno = EINVAL;
		return NULL;
	}

	

	if (sz_arr == 0 || sz_arr == 1)	{
		return arr_p;
	}

	current_elem = malloc(sz_elem);
	for (i = 1; i < sz_arr; i++) {	
		memcpy(
			current_elem,
			index_to_p(arr_p, i, sz_elem),
			sz_elem
		);

		pos = _find_position_to_ins(arr_p, 0, (int)i - 1, current_elem, sz_elem, cmp);

		for (j = i; j > pos; j--) {
			memcpy(
				index_to_p(arr_p, j, sz_elem),
				index_to_p(arr_p, j - 1, sz_elem),
				sz_elem
			);	
		}

		memcpy(	
			index_to_p(arr_p, pos, sz_elem),
			current_elem,
			sz_elem
		);
		
	}

	free(current_elem);
	return arr_p;	
}

void* merge(void* arr1, size_t sz_arr1, void* arr2, size_t sz_arr2, size_t sz_elem, int (*cmp)(void*, void*)) {
	size_t i, j, k;
	void* order;

	if (arr1 == NULL || arr2 == NULL || sz_elem < 1 || cmp == NULL) {
		errno = EINVAL;
		return NULL;
	}
	order = malloc((sz_arr1 + sz_arr2) * sz_elem);
	
	for (k=i=j=0; k < (sz_arr1 + sz_arr2); k++) {	
		if (i == sz_arr1) {								// end of arr1
			memcpy(index_to_p(order,k,sz_elem), index_to_p(arr2, j, sz_elem), sz_elem);
			j++;
		} else if (j == sz_arr2) {							// end of arr2
			memcpy(index_to_p(order,k,sz_elem), index_to_p(arr1, i, sz_elem), sz_elem);
			i++;
		} else if (cmp(index_to_p(arr1,i,sz_elem), index_to_p(arr2,j,sz_elem)) == 1) {	// arr1[i] > arr2[j]
			memcpy(index_to_p(order,k,sz_elem), index_to_p(arr2, j, sz_elem), sz_elem);
			j++;
		} else {									//arr1[i] <= arr2[j]
			memcpy(index_to_p(order,k,sz_elem), index_to_p(arr1, i, sz_elem), sz_elem);
			i++;
		}
	}
	return order;
}

void* hybrid_sort(void* arr_p, size_t sz_arr, size_t sz_elem, size_t k, int (*cmp)(void*, void*))
{
    void *left, *right, *order_arr, *arr_right_start_p;
    size_t sz_arr_left, sz_arr_right;
    if (arr_p == NULL || sz_elem < 1 || cmp == NULL) {
        errno = EINVAL;
        return NULL;
    } else if (k == 0) {
	return hybrid_sort(arr_p, sz_arr, sz_elem, 1, cmp); 
    }else if (sz_arr <= k) {
	order_arr = malloc(sz_elem * sz_arr);
	memcpy(order_arr, arr_p, sz_elem * sz_arr);
        return binary_insertion_sort(order_arr, sz_arr, sz_elem, cmp);
    } else {
        sz_arr_left		= sz_arr/2;
        left			= hybrid_sort(arr_p, sz_arr_left, sz_elem, k, cmp);
        sz_arr_right		= sz_arr - sz_arr_left;				
       	arr_right_start_p	= index_to_p(arr_p, sz_arr/2, sz_elem);
        right			= hybrid_sort(arr_right_start_p, sz_arr_right, sz_elem, k, cmp);
        order_arr		= merge(left, sz_arr_left, right, sz_arr_right,sz_elem, cmp);
        free(left);
        free(right);
        return order_arr;
    }
}

void* merge_sort(void* arr_p, size_t sz_arr, size_t sz_elem, int (*cmp)(void*, void*))
{
	return hybrid_sort(arr_p, sz_arr, sz_elem, 1, cmp);
}

