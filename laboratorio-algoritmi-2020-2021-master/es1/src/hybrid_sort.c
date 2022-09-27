#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "sort.h"

void* hybrid_sort(void* arr, int sz_arr, size_t sz_elem, int (*cmp)(void*, void*), int k) {
	void *left, *right, *order_arr;
	int sz_arr_left, sz_arr_right;
	
	if (arr == NULL || sz_arr < 0 || sz_elem < 1 || cmp == NULL || k < 0) {
	    errno = EINVAL;
	    return NULL;
	}
	
	if (k == 0)
		return merge_sort(arr, sz_arr, sz_elem, cmp);
	else if (k <= sz_arr) {
		return binary_insertion_sort(arr, sz_arr, sz_elem, cmp);
	} else {
		sz_arr_left = sz_arr/2;
		left = hybrid_sort(arr, sz_arr, sz_elem, cmp, k);
		sz_arr_right= sz_arr - sz_arr_left;             // gestisco sia sz_arr pari che dispari
		right = hybrid_sort(arr + (sz_elem *(sz_arr_left + 1)), sz_arr, sz_elem, cmp, k);   
		order_arr = merge(left, sz_arr_left, right, sz_arr_right,sz_elem, cmp);
		free (left);
		free(right);
		return order_arr;
	}
}
