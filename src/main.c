#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS 1

#define MAX_NAME 50
#define MAX_DIRECTOR 50
#define MAX_COUNTRY 50
#define MAX_GENRE 50
#define ARRAY_SIZE 10

struct film {
    char name[MAX_NAME];
    char director[MAX_DIRECTOR];
    int year;
    char country[MAX_COUNTRY];
    double price;
    double profit;
    char genre[MAX_GENRE];
};

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

void printNewFilms(struct film* arr) {
    printf("--------------------\n");
    for (int j = 0; j < ARRAY_SIZE; j++) {
        if (arr[j].year >= 2018 && (strstr(arr[j].genre, "child") != NULL || strstr(arr[j].genre, "Child") != NULL)) {
            print(&(arr[j]));
        }
    }
}

int main()
{
    FILE* fptr = fopen("file.txt", "r");
    struct film* arr = readFileToArr(fptr);
    printNewFilms(arr);
}
