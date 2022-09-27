#include "unity.h"
#include "edit_distance.h"

static void test_first_string_empty(){
    char a[] = "";
    char b[] = "b";
    TEST_ASSERT_EQUAL(1, edit_distance(a, b));
}

static void test_second_string_empty(){
    char a[] = "a";
    char b[] = "";
    TEST_ASSERT_EQUAL(1, edit_distance(a, b));
}

static void test_one(){
    char a[] = "casa";
    char b[] = "cassa";
    TEST_ASSERT_EQUAL(1, edit_distance(a, b));
}

static void test_two(){
    char a[] = "casa";
    char b[] = "cara";
    TEST_ASSERT_EQUAL(2, edit_distance(a, b));
}

static void test_three() {
	char a[] = "vinaio";
    char b[] = "vino";
    TEST_ASSERT_EQUAL(2, edit_distance(a, b));

}

static void test_four() {
	char a[] = "tassa";
    char b[] = "passato";
    TEST_ASSERT_EQUAL(4, edit_distance(a, b));

}

static void test_five() {
	char a[] = "pioppo";
	char b[] = "pioppo";
	TEST_ASSERT_EQUAL(0, edit_distance(a, b));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_first_string_empty);
    RUN_TEST(test_second_string_empty);
//  RUN_TEST(test_both_strings_empty);
    RUN_TEST(test_one);
    RUN_TEST(test_two);
    RUN_TEST(test_three);
    RUN_TEST(test_four);
    RUN_TEST(test_five);
    UNITY_END();
}
