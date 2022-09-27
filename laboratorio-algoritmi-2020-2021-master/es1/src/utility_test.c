#include "unity.h"
#include "utility.h"

#define ARRAY_SZ	5
#define ELEMENT_POS	2

static void test_index_to_p_input_null() {
	TEST_ASSERT_TRUE(index_to_p(NULL, ELEMENT_POS, sizeof(int)) == NULL);
}

static void test_index_to_p_intput_zero() {
	int a[] = {1,2,3,4,5};
	
	TEST_ASSERT_TRUE(index_to_p((void*) a, ELEMENT_POS, 0) == NULL);
}

static void test_index_to_p_output_int() {
	int a[] = {1,2,3,4,5};
	int* elem_p = (int*) index_to_p((void*) a, ELEMENT_POS, sizeof(int));
	
	TEST_ASSERT_TRUE(&(a[ELEMENT_POS]) == elem_p);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_index_to_p_input_null);
	RUN_TEST(test_index_to_p_intput_zero);
	RUN_TEST(test_index_to_p_output_int);
	return UNITY_END();
}
