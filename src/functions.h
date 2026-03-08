#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "film.h"

#define ARRAY_SIZE 10

void print(struct film* s) {
    printf("%s:%s:%d:%s:%lf:%lf:%s\n", s->name, s->director, s->year, s->country, s->price, s->profit, s->genre);
}

struct film* readFileToArr(FILE* fptr) {
    struct film* arr = calloc(ARRAY_SIZE, sizeof(struct film));
    int i = 0;
    char line[100];

    while (fgets(line, sizeof(line), fptr) != NULL) {
        char* res;
        //name
        res = strtok(line, ";");
        strcpy(arr[i].name, res);
        //director
        res = strtok(NULL, ";");
        strcpy(arr[i].director, res);
        //year
        res = strtok(NULL, ";");
        char* c;
        arr[i].year = strtol(res, &c, 10);
        //country
        res = strtok(NULL, ";");
        strcpy(arr[i].country, res);
        //price
        res = strtok(NULL, ";");
        c = NULL;
        arr[i].price = strtod(res, &c);
        //profit
        res = strtok(NULL, ";");
        c = NULL;
        arr[i].profit = strtod(res, &c);
        //genre
        res = strtok(NULL, "\n");
        strcpy(arr[i].genre, res);

        print(&arr[i++]);
        if (i >= ARRAY_SIZE) {
            printf("%s:%d", "The number of lines in read document exceeds the maximum set parameter", ARRAY_SIZE);
            break;
        }
        memset(line, 0, sizeof(line));
    }
    return arr;
}