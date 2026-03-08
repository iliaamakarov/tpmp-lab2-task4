#ifndef FILM
#define FILM

#define MAX_NAME 50
#define MAX_DIRECTOR 50
#define MAX_COUNTRY 50
#define MAX_GENRE 50

struct film {
    char name[MAX_NAME];
    char director[MAX_DIRECTOR];
    int year;
    char country[MAX_COUNTRY];
    double price;
    double profit;
    char genre[MAX_GENRE];
};
#endif