/*
 * SUMMARY: verifica se un array è ordinato
 * INPUT: un puntatore non nullo ad un array generico arr, il numero non negativo di elementi di arr,
 *        la dimensione di ciascun elemento maggiore di 0 e il puntatore non nullo a una funzione cmp che
 *        prenda in input due elementi e restituisca 1 se e1 > e2, 0 se e1=e2 e -1 altrimenti.
 * OUTPUT: 1 se è ordinato, 0 se non lo è.
 * ERROR: -1 e setta errno.
 * PRE:	arr not NULL, elem_sz > 0
 */
int is_sort(void* arr_p, size_t arr_sz, size_t elem_sz, int (*cmp)(void*, void*));

/*
 * SUMMARY: implementazione generica merge per algoritmo merge-sort
 * INPUT: un puntatore ad un array generico arr1, il numero di elementi di arr1,
 *        un puntatore ad un array generico arr2, il numero di elementi di arr2,
 *        la dimensione di ciascun elemento e il puntatore a una funzione cmp che
 *        prenda in input due elementi e restituisca 1 se e1 > e2, 0 se e1=e2 e -1 altrimenti.
 * OUTPUT: un puntatore all'array ordinato.
 * ERROR: NULL e setta errno.
 * PRE:	arr1 not NULL, arr2 not NULL, elem_sz > 0
 */
void* merge(void* arr1, size_t sz_arr1, void* arr2, size_t sz_arr2, size_t sz_elem, int (*cmp)(void*, void*));

/*
 * SUMMARY: implementazione generica merge sort per algoritmo merge-sort
 * INPUT: un puntatore ad un array generico, la dimensione di ogni elemento,
 *        il numero di elementi e il puntatore a una funzione cmp che prenda in
 *        input due elementi e restituisca 1 se e1 > e2, 0 se e1=e2 e -1 altrimenti.
 * OUTPUT: un puntatore all'array ordinato.
 * ERROR: NULL e setta errno.
 * PRE:	arr not NULL, elem_sz > 0
 */
void* merge_sort(void* arr, size_t sz_arr, size_t sz_elem, int (*cmp)(void*, void*));

/*
 * SUMMARY: implementazione generica binary-insertion-sort
 * INPUT: un puntatore ad un array generico, la dimensione di ogni elemento,
 *        il numero di elementi e il puntatore a una funzione cmp che prenda in
 *        input due elementi e restituisca 1 se e1 > e2, 0 se e1=e2 e -1 altrimenti.
 * OUTPUT: un puntatore all'array ordinato.
 * ERROR: NULL e setta errno.
 * PRE:	arr not NULL, elem_sz > 0
 */
void* binary_insertion_sort(void* arr, size_t sz_arr, size_t sz_elem, int (*cmp)(void*, void*));

void* hybrid_sort(void* arr_p, size_t sz_arr, size_t sz_elem, size_t k, int (*cmp)(void*, void*));