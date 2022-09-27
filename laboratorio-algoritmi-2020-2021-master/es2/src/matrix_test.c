#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "matrix.h"

static void test_matrix_is_null()
{
	TEST_ASSERT_TRUE(matrix_create(0, 0, 5) == NULL);
	TEST_ASSERT_TRUE(matrix_create(2, 3, 0) == NULL);
}

static void test_matrix_is_destroyed()
{
	int i = 0;
	matrix m = matrix_create(2, 3, 5);
	TEST_ASSERT_TRUE(
			matrix_destroy(&m) == 0 &&
			matrix_set_cell(m,1,1,&i) == -1	
			);
}

static void test_get_columns_size()
{
	matrix m;
	m = matrix_create(2, 3, 5);
	TEST_ASSERT_TRUE(matrix_get_columns_size(m) == 3);


}

static void test_get_rows_size()
{
	matrix m;
	m = matrix_create(2, 3, 5);
	TEST_ASSERT_TRUE(matrix_get_rows_size(m) == 2);

}

static void test_set_cell()
{
	int i = 10;
	matrix m = matrix_create(2, 3, sizeof(int));
	TEST_ASSERT_TRUE(matrix_set_cell(m, 1, 2, &i) == 0);

}

static void test_get_cell()
{
	int i,j;
       	i = 10;
	matrix m = matrix_create(2, 3, sizeof(int));
	matrix_set_cell(m, 1, 2, &i);
	matrix_get_cell(m, 1, 2, &j);
	TEST_ASSERT_TRUE(i == j);

}

int main() {
	UNITY_BEGIN();
	
	RUN_TEST(test_matrix_is_null);
	RUN_TEST(test_matrix_is_destroyed);
	RUN_TEST(test_get_columns_size);
	RUN_TEST(test_get_rows_size);
	RUN_TEST(test_set_cell);
	RUN_TEST(test_get_cell);
	return UNITY_END();
}
