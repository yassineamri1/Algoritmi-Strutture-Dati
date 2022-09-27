#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include "edit_distance.h"

int read_file(char* path, char **array) {
    FILE* file = fopen(path, "r");
    if(file == NULL){
        fprintf(stderr, "Can't open file %s\n", path);
	return -1;
    }

    int i = 0;
    int begin = 0, end = 0;
    char c;
    char* buf = calloc(128, sizeof(*buf));
    while(!feof(file)) {
        c = (char) fgetc(file);
        if(c >= 'a' && c <= 'z'){
            buf[end - begin] = c;
            end++;
        }else if(c >= 'A' && c <= 'Z'){
            buf[end - begin] =(char) tolower(c);
            end++;
        }else if(end > begin){
            array[i] = buf;
            i++;
            buf = calloc(128, sizeof(*buf));
            begin = end;
        }
    }
    fclose(file);
    return i;
}



void check_dictionary(char *word, char **dictionary, int length_dictionary){
    int i, find;
    size_t current_edit_distance, min_edit_distance;

    char **output;
    int indice_output = 0;

    output = (char **) malloc((size_t)length_dictionary * sizeof(char*));

    min_edit_distance = INT_MAX; // infinito
    find = 0;
    
    for(i = 0; !find && i < length_dictionary; i++){
        current_edit_distance = edit_distance_dyn(word, dictionary[i]);

        if(current_edit_distance < min_edit_distance) {
            min_edit_distance = current_edit_distance;
            indice_output = 0;
        }

        if(current_edit_distance == min_edit_distance) {
            output[indice_output] = dictionary[i];
            indice_output++;
        }

        if(current_edit_distance == 0) {
            find = 1;
        }
    }


    for(i = 0; i < indice_output; i++) {
        printf("\t%s\n", output[i]);
    }
    free(output);
}

void check_word(char **dictionary, int length_dictionary, char **correctme, int length_correctme){
    int i;
    for(i = 0; i < length_correctme; i++) {
        check_dictionary(correctme[i], dictionary, length_dictionary);
        printf("\n");

    }
}

int main(){

    time_t start_t, end_t;
    double diff_t;

    char **dictionary = (char**) malloc(sizeof(char*) * 1000000);
    char **correctme = (char**) malloc(sizeof(char*) * 100);

    int length_dictionary = read_file("bin/dictionary.txt", dictionary);

    int length_correctme = read_file("bin/correctme.txt", correctme);
   
    time(&start_t);

    check_word(dictionary, length_dictionary, correctme, length_correctme);

    time(&end_t);

    diff_t = difftime(end_t, start_t);
    printf("time in seconds: %f\n", diff_t);
}
