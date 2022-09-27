#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "matrix.h"

/*
 * INPUT: three int values;
 * OUTPUT: the lesser value
 */
static size_t min_three_values(size_t d1, size_t d2, size_t d3) {
    if (d1 <= d2 && d1 <= d3)
	    return d1;
    else if (d2 <= d1 && d2 <= d3)
	    return d2;
    else return d3;

}

#define SIZE_T_MAX	(~(size_t)0)

/*
 *
 *
 *
 */
size_t edit_distance(char* s1, char* s2) {     
    size_t dnoop, min;

    if (*s1 == NULL)		
        return strlen(s2);
    else if (*s2 == NULL)
        return strlen(s1);
    else {
        if (*s1 == *s2)
            dnoop = edit_distance(s1 + 1, s2 + 1);
        else
            dnoop = 10000;
        size_t dcanc	= 1 + edit_distance(s1, s2 + 1);
        size_t dins	= 1 + edit_distance(s1 + 1, s2);
        min = min_three_values(dnoop, dcanc, dins);
	return min;
    }
}

#define UNVISITED -1
size_t _edit_distance_dyn_r(char* s1, char* s2, size_t i, size_t j, matrix m)	
{
	size_t edit_distance_value, ed_equal;
	int cell_value; 

	matrix_get_cell(m, i, j, &cell_value);

	if (cell_value != UNVISITED) {
        	matrix_get_cell(m, i, j, &edit_distance_value);
	} else if (i == 0) {
		matrix_set_cell(m, i, j, &j);
		edit_distance_value = j;
	} else if (j == 0) {
		matrix_set_cell(m, i, j, &i);
		edit_distance_value = i;
	} else {
		if (s1[i - 1] == s2[j - 1]) {	
			ed_equal = _edit_distance_dyn_r(s1, s2, i - 1, j - 1, m);
		} else {
			ed_equal = INT_MAX;
		}
		
		edit_distance_value = min_three_values(
			1 + _edit_distance_dyn_r(s1, s2, i, j - 1, m),
			1 + _edit_distance_dyn_r(s1, s2, i - 1, j, m),
			ed_equal
			);

        	matrix_set_cell(m, i, j, &edit_distance_value);
	}

	return edit_distance_value;
}
/*
 *
 *
 *
 */

size_t edit_distance_dyn(char* s1, char* s2) {
	matrix m;
	int tmp;
	int cell_value_default;
	size_t s1_lenght, s2_lenght, i, j;

	if (*s1 == 0)		
		return strlen(s2);
	else if (*s2 == 0)
		return strlen(s1);

	cell_value_default = UNVISITED;
	s1_lenght = strlen(s1);
	s2_lenght = strlen(s2);

	m = matrix_create(s1_lenght + 1, s2_lenght + 1, sizeof(int));

	for (i = 0; i < s1_lenght + 1; i++) {
		for (j = 0; j < s2_lenght + 1; j++) {
			matrix_set_cell(m, i, j, &cell_value_default);
			matrix_get_cell(m, i, j, &tmp);
		}
	}
	return _edit_distance_dyn_r(s1, s2, s1_lenght, s2_lenght, m);
}



