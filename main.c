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
    char title[50];
    char year[10];
    char publisher[30];
};
struct book number, author, title, year, publisher;

//defining functions
int search(struct book* cat, int len, char* id);
void printBook(struct book item);

//main program
int main()
{

    struct book catalog[200] = {{"1234567", "LUSTIG", "LACH-STORY", "1986", "TROCKEN"},
                                {"8745343", "KARL", "ABENTEUER", "1981", "VERITAS"},
                                {"7654321", "MUTIG", "KRIMI-ROMANZE", "1989", "SPANNEND"},
                                {"978-3-407-82222-2", "HUNTER", "Warrior Cats: Die letzten Geheimnisse", "2017", "BELTZ&GELBERG"},
                                {"978-3-407-82366-3", "HUNTER", "Warrior Cats: Feuer und Eis", "2008", "BELTZ&GELBERG"},
                                {"978-3-902894-03-8", "KNOLL", "100 Jahre Traunseebahn", "2012", "Railway-Media-Group"},
                                {"87909870", "WEGENSTEIN", "Die Stubaitalbahn", "1981", "POSPISCHIL"},
                                {"978-3-7855-7361-7", "POZNANSKI", "Erebos", "2010", "LOEWE"},
                                {"978-3-7855-8231-2", "POZNANSKI", "Elanus", "2016", "LOEWE"},
                                {"3-473-34448-6", "LEMANCZYK", "Das verlorene Land", "2005", "Ravensburger"},
                                {"978-3-570-30961-2", "DASHNER", "Elanus", "2015", "cbt"},
                                {"978-3-442-24492-8", "HICKMAN", "Der Quell der Finsternis", "2007", "blanvalet"},
                                {"978-0-099-57286-2", "BOYNE", "The boy in the striped pyjamas", "2006", "vintage"}};
    char letter[3];
    printf("* Please type in the first letter of the author of the book you are searching for\n");
    fflush(stdin);
    scanf("%s", &letter);
    printf("* Search results: %d", search(catalog, 200, letter));
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
    printf("* _________________________\n");
}