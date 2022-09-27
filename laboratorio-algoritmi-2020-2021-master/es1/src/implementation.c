#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "sort.h"

#define FILE_PATH	"bin/records.csv"
#define SZ_LINE_MAX	60
#define NO_LINES	2000000

struct entry {
	int id;
	char field1[30];
	int field2;
	float field3;
};

int cmpfield1(void* n, void* m)
{
	int tmp;
	struct entry* left = (struct entry*) n;
	struct entry* right = (struct entry*) m;

	tmp =strcmp(left->field1, right->field1);

	if (tmp > 0)
		return 1;
	else if (tmp < 0)
		return -1;
	else
		return 0;
}

int cmpfield2(void* n, void* m)
{
	struct entry* left = (struct entry*) n;
	struct entry* right = (struct entry*) m;

	if (left->field2 > right->field2)
		return 1;
	else if (left->field2 < right->field2)
		return -1;
	else
		return 0;
}

int cmpfield3(void* n, void* m)
{
	struct entry* left = (struct entry*) n;
	struct entry* right = (struct entry*) m;

	if (left->field3 > right->field3)
		return 1;
	else if (left->field3 < right->field3)
		return -1;
	else
		return 0;
}

struct entry* populate_from_csv()
{
	int i;
	FILE* s;
	char line[SZ_LINE_MAX];
	struct entry* r;
	const char separator[2] = ",";

	r = malloc(sizeof(struct entry) * NO_LINES);
	s = fopen(FILE_PATH, "r");	
	if (s != NULL)
		printf("file aperto\n");
	else
		printf("ERROR!\n");

	for (i = 0; i < NO_LINES; i++) {
		fgets(line, SZ_LINE_MAX, s);
		r[i].id = atoi(strtok(line, separator));
		strcpy(r[i].field1, strtok(NULL, separator));	
		r[i].field2 = atoi(strtok(NULL, separator));
		r[i].field3 = atof(strtok(NULL, separator));
	}
	fclose(s);

	return r;
}

#define K_MIN_VAL	1
#define K_MAX_VAL	10000
int main()
{
	int k;
	double cpu_time_used;
	clock_t start, end;
	struct entry* r;

	printf("Loading: data to order\n");
	r = populate_from_csv();

	printf("Start of test\n");

	for (k = K_MIN_VAL; k <= K_MAX_VAL; k++) {
		start = clock();
		free(hybrid_sort(r, NO_LINES, sizeof(struct entry), k, cmpfield1));
		free(hybrid_sort(r, NO_LINES, sizeof(struct entry), k, cmpfield2));
		free(hybrid_sort(r, NO_LINES, sizeof(struct entry), k, cmpfield3));
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

		printf("\tFor K = %i\t time for orderer is %f\n", k, cpu_time_used);
	}
	
	printf("End of test\n");
}


