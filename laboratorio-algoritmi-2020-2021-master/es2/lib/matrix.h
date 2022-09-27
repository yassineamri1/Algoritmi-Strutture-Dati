#pragma once
typedef struct _matrix* matrix;

/*
 *
 */
matrix matrix_create(size_t no_rows, size_t no_columns, size_t sz_elem);

/*
 *
 */
int matrix_destroy(matrix* matrix_p);

/*
 *
 */
size_t matrix_get_columns_size(matrix m);

/*
 *
 */
size_t matrix_get_rows_size(matrix m);

/*
 *
 */
int matrix_get_cell(matrix m, size_t row, size_t column, void* destination_p);

/*
 *
 */
int matrix_set_cell(matrix m, size_t row, size_t column, void* cell_value_p);

