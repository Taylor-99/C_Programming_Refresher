#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
// How many books the library can hold
#define BOOK_COUNT 10

 //book structure 
struct Book {
    char bookTitle[100];
    char bookAuthor[40];
    int publicationYear;
    int pageCount;
    int readingStatus;
};

int displayMenu(){

    int choice;

    printf(" ========================== \n ");
    printf("\tPERSONAL LIBRARY\n "); 
    printf("========================== \n");

    printf("1. Add a book");
    printf("\n2. View Library");
    printf("\n3. Search Book");
    printf("\n4. Exit\n");

    printf("Choose an option (1,2,3,4): ");
    scanf("%d", &choice);

    return choice;

};

int addBook(int bookCount, struct Book* myLibrary) {

     //creates a structure for the newly added book
            struct Book newBook;
            
            printf("Add a book\n");

            char newBookTitle[100];

            printf("Enter book title: ");
            scanf(" %[^\n]%*c", newBookTitle);
            strcpy(newBook.bookTitle, newBookTitle); // copies the string to the variable

            char newAuthor[50];
            printf("\nEnter book author: ");
            scanf(" %[^\n]%*c", newAuthor);
            strcpy(newBook.bookAuthor, newAuthor);

            int newPublicationYear;
            printf("\nEnter book publication year: ");
            scanf(" %d", &newPublicationYear);
            newBook.publicationYear = newPublicationYear;

            int newPageCount;
            printf("\nEnter book page count: ");
            scanf(" %d", &newPageCount);
            newBook.pageCount = newPageCount;

            while(newPageCount <= 1 ) {

                printf("Page count must be greater than 1 ");
                printf("\nEnter book page count: ");
                scanf(" %d", &newPageCount);
                newBook.pageCount = newPageCount;
            };

            int newReadingStatus;
            printf("\nWhat is your current reading status of %s\n 1.Want to read\n 2.Currently reading\n 3.Completed\n Please enter a number: ", newBookTitle);
            scanf(" %d", &newReadingStatus);
            newBook.readingStatus = newReadingStatus;

            //will only add the book if the library is not full
            if(bookCount < BOOK_COUNT){

                myLibrary[bookCount] = newBook;

                bookCount ++;
            };

            printf("Book Title: %s\n", newBookTitle);
            printf("Author: %s\n", newAuthor);
            printf("Publication Year: %s\n", newAuthor);
            printf("Page count: %d\n", newPageCount);
            switch(newReadingStatus) {
                case 1:
                    printf("Reading Status: Want to read\n");
                    break;
                case 2:
                    printf("Reading Status: Currently reading\n");
                    break;
                case 3:
                    printf("Reading Status: Completed\n");
                    break;
            };
            printf("Was added to your library\n");

            return bookCount;

};

void viewBooks(int bookCount, struct Book* myLibrary) {

    printf("View Library\n");

        //will loop throught the users library to view the book s in the users library
        for (int i = 0; i < bookCount; i++) {
            printf("%d. Title: %s\n",i+1, myLibrary[i].bookTitle);
            printf("Author: %s\n", myLibrary[i].bookAuthor);
            printf("Publication Year: %d\n", myLibrary[i].publicationYear);
            printf("Page Count: %d\n", myLibrary[i].pageCount);
            switch(myLibrary[i].readingStatus) {
            case 1:
                printf("Reading Status: Want to read\n");
                break;
            case 2:
                printf("Reading Status: Currently reading\n");
                break;
            case 3:
                printf("Reading Status: Completed\n");
                break;
            };
            printf("\n");
        };

};

void searchBooks(int bookCount, struct Book* myLibrary) {

    printf("Search Book\n");

    char searchTitle[100];
    
    printf("Please enter a book title to search or enter stop to exit: ");
    scanf(" %[^\n]%*c", searchTitle);

    char exit[] = "stop";
    int exitCompare = strcmp(searchTitle, exit);

    if(exitCompare == 0){

        printf("Going back to the main screen\n");

    }else{

        int found = 0;
        struct Book foundMatch;

        for(int book = 0; book < bookCount; book++){

            if(strcasecmp(myLibrary[book].bookTitle, searchTitle) == 0){
                found = 1;
                foundMatch = myLibrary[book];
                break;
            };

        };

        if(found == 1){

            printf("Found book: \n");
            printf("Title: %s\n", foundMatch.bookTitle);
            printf("Author: %s\n", foundMatch.bookAuthor);
            printf("Publucation Year: %d\n", foundMatch.publicationYear);
            printf("Page Count: %d\n", foundMatch.pageCount);
            switch(foundMatch.readingStatus) {
            case 1:
                printf("Reading Status: Want to read\n");
                break;
            case 2:
                printf("Reading Status: Currently reading\n");
                break;
            case 3:
                printf("Reading Status: Completed\n");
                break;
            };
            printf("\n");
        };
        
        printf("Match not found.\n");

    };

};

int main() {

    //holds the user choice for the while loop
    int userChoice;

    // Creates an empty library
    struct Book myLibrary[BOOK_COUNT] = {0};

    //how many books are in the library
    int currentBookCount = 0;

    myLibrary[0] = (struct Book){
        .bookTitle = "The Hobbit",
        .bookAuthor = "J.R.R. Tolkien",
        .publicationYear = 1937,
        .pageCount = 310,
        .readingStatus = 1
    };

    myLibrary[1] = (struct Book){
        .bookTitle = "Pride and Prejudice",
        .bookAuthor = "Jane Austen",
        .publicationYear = 1813,
        .pageCount = 432,
        .readingStatus = 3
    };

    currentBookCount = 2;

    //loop that keeps going until the user chooses to exit
    while(userChoice != 4){

        int userExit;

        userChoice = displayMenu();

        //Adds a book to user library
        if(userChoice == 1) {

           currentBookCount = addBook(currentBookCount, &myLibrary);

        } else if(userChoice == 2){

            viewBooks(currentBookCount, &myLibrary);

        }else if(userChoice == 3){

           searchBooks(currentBookCount, &myLibrary);
            
        }else if(userChoice == 4){

            printf("Are you sure? (1=Yes, 2=No): ");
            scanf("%d", &userExit);
    
            if(userExit == 1){
                printf("You're data has been deleted.\n");
                printf("Good Bye\n");
            } else {
                userChoice = 0;
            };
        };

    };

    // printf("\n %s is added to your %s list", bookTitle, readingStatus);

    return 0;
};