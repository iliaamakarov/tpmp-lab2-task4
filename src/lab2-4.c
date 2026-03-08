#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "film.h"
#include "functions.h"

#define _CRT_SECURE_NO_WARNINGS 1

void printNewFilms(struct film* arr, FILE* outptr) {
    printf("--------------------\n");
    for (int j = 0; j < ARRAY_SIZE; j++) {
        if (arr[j].year >= 2018 && (strstr(arr[j].genre, "child") != NULL || strstr(arr[j].genre, "Child") != NULL)) {
            print(&(arr[j]));
            printToFile(&(arr[j]), outptr);
        }
    }
}

int main()
{
    FILE* fptr = fopen("file.txt", "r");
    FILE* outptr = fopen("output.txt", "w");
    struct film* arr = readFileToArr(fptr);
    printNewFilms(arr, outptr);
}
