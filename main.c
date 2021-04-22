#include <stdio.h>

//********************************************************************
//
// Program        : Übung 21 - Buchverwaltung
//
//
// Author         : Niklas Schachl
//
//
// Date           : 22.4.2021
//
//
// Description: Program to manage books
//
//********************************************************************

//defining structs
struct book
{
    char number[30];
    char author[30];
    char title[30];
    char year[10];
    char publisher[30];
};
struct book number, author, title, year, publisher;

//defining functions
int search(struct book* cat, int len, char* id);
void printBook(struct book item);

//declaring variables
//struct book catalog[200] = {1234567, "LUSTIG", "LACH-STORY", 1986, "TROCKEN"};

//main program
int main()
{
    struct book catalog[200] = {{"1234567", "LUSTIG", "LACH-STORY", "1986", "TROCKEN"},
                                {"8745343", "KARL", "ABENTEUER", "1981", "VERITAS"},
                                {"7654321", "MUTIG", "KRIMI-ROMANZE", "1989", "SPANNEND"},
                                {"4078222", "HUNTER", "Die letzten Geheimnisse", "2017", "BELTZ&GELBERG"}};

    int results;
    results = search(catalog, 200, "K");
    printf("* Search results: %d", results);
}

//********************************************************************
//
// Funkction        : search
//
//
// Description      : Searches through the catalog to find a book with an author matching the id
//
// Parameter        :
//    1   cat  struct book*     The catalog you want to search through
//    2   len  int              The lenght of the catalog
//    3   id   char*            The letter you want to find the matchig author
//
//********************************************************************
int search(struct book* cat, int len, char* id)
{
    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        if(cat[i].author[0] == *id)
        {
            printBook(cat[i]);
            ++count;
        }
    }
    return count;
}

//********************************************************************
//
// Funkction        : printBook
//
//
// Description      : prints the values of a book to the console
//
// Parameter        :
//    1   item  struct book*    The book, whose values should be printed
//
//********************************************************************
void printBook(struct book item)
{
    printf("* ---- Book ----\n");
    printf("* Book number: %s\n", item.number);
    printf("* Author: %s\n", item.author);
    printf("* Title: %s\n", item.title);
    printf("* Year: %s\n", item.year);
    printf("* Publisher: %s\n", item.publisher);
}