#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define TRUE	 1
#define FALSE	 0
#define SUCCESS	 0
#define FAILURE	-1

#define MEM_MIN_SZ	1

int memswp(void* p1, void* p2, size_t sz)
{
	int result;
	
	if (p1 == NULL || p2 == NULL || sz < MEM_MIN_SZ) {
		errno = EINVAL;
		result = FAILURE;
	} else {
		char* tmp = (char*) malloc(sz);
		memcpy(tmp, p1,	 sz);
		memcpy(p1,  p2,  sz);
		memcpy(p2,  tmp, sz);
		free(tmp);
		result = SUCCESS;
	}

	return result;
}

#define ELE_MIN_SZ	1
#define ARR_MIN_SZ	1

int arr_rotate(void* a, int a_sz, size_t ele_sz)
{
	void* dst;

	if (a == NULL || a_sz < ARR_MIN_SZ || ele_sz < ELE_MIN_SZ)
		return FAILURE;

	dst = (void*) ((size_t) a + ele_sz);
	if (a_sz > 2)
		arr_rotate(dst, a_sz - 1, ele_sz);
	memswp(a, dst, ele_sz);

	return SUCCESS;
}

void* index_to_p(void* a, unsigned long index, size_t sz)
{
	if (a == NULL || sz == 0)
		return NULL;
	else 
    		return (void*) (((char*)a) + (sizeof(char) * (sz) * (index)));
}
