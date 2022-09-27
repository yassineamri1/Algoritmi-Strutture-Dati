/*
 * scambia il contenuto di due aree di memoria aventi la stessa dimensione
 * INP: il puntatore alla prima area di memoria, il puntatore alla seconda area di memoria,
 * 	la dimensione di ciascuna delle due aree.
 * OUT: 0 o -1 in caso di errore e setta errno
 */
int memswp(void* a1_p, void* a2_p, size_t mem_sz);

/*
 * SUM: sposta di una posizione gli elementi di un array in modo circolare
 * INP: il puntatore al primo elemento dell'array, il numero di elementi dell'array
 * 	e la dimensione di ciascun elemento.
 * OUT: 0 o -1 in caso di errore e setta errno
 */
int arr_rotate(void* arr_start_p, int n_arr_elem, size_t ele_sz);

/*
 * SUM: dato un indice i, restituisce il puntatore all'i-esimo elemento di un array.
 * INP: il puntatore al primo elemento dell'array, un indice valido dell'array
 * 	e la dimensione di ciascun elemento dell'array.
 * OUT: il puntatore all'elemento o NULL in caso di errore e setta errno
 */
void* index_to_p(void* a, unsigned long index, size_t sz);
