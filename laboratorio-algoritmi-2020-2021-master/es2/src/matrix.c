#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"

struct _matrix {
	void* start_p;
	size_t rows;
	size_t columns;
	size_t sz_cell;
};

struct _matrix* matrix_create(size_t no_rows, size_t no_columns, size_t sz_elem)
{
	struct _matrix* matrix_p ;
	
	if (no_rows == 0 && no_columns == 0)
		return NULL;

	if (sz_elem == 0)
		return NULL;

	matrix_p = (struct _matrix*) malloc(sizeof(struct _matrix));
	matrix_p->rows		= no_rows;
	matrix_p->columns	= no_columns;
	matrix_p->sz_cell	= sz_elem;
	//(n_cell % colonne) + riga	
	//cells[i*SO_WIDTH+j] 
	matrix_p->start_p	= malloc(sz_elem * no_rows * no_columns);
	return matrix_p;
}

int matrix_destroy(struct _matrix** matrix_pp)
{
	if (matrix_pp == NULL || *matrix_pp == NULL) {
		return -1;
	}
	free((*matrix_pp)->start_p);
	free(*matrix_pp);
	*matrix_pp = NULL;
	return 0;
}

size_t matrix_get_rows_size(struct _matrix* matrix_p)
{
	return matrix_p->rows;
}

size_t matrix_get_columns_size(struct _matrix* matrix_p)
{
	return matrix_p->columns;
}

static size_t _cell_position(struct _matrix* matrix_p, size_t row, size_t column)
{
	return row * matrix_p->columns + column;
}

static void* _get_cell(struct _matrix* matrix_p, size_t row, size_t column)
{
	return (void*) (
			(char*) matrix_p->start_p + 
			_cell_position(matrix_p, row, column) * matrix_p->sz_cell
		       );
}

int matrix_get_cell(struct _matrix* matrix_p, size_t row, size_t column, void* destination_p)
{
	if (matrix_p == NULL || destination_p == NULL)
		return -1; 

	if (row >= matrix_p->rows || column >= matrix_p->columns)
		return -1;

	memcpy(
		destination_p,
		_get_cell(matrix_p, row, column),
		matrix_p->sz_cell
	);

	return 0;
}

int matrix_set_cell(struct _matrix* matrix_p, size_t row, size_t column, void* value_p)
{
	if (matrix_p == NULL || value_p == NULL)
		return -1; 
	
	if (row >= matrix_p->rows || column >= matrix_p->columns)
		return -1;

	memcpy(
		_get_cell(matrix_p, row, column),
		value_p,
		matrix_p->sz_cell
	);

	return 0;}



