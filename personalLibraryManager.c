#include <stdio.h>
#include <string.h>

int main() {

    int userChoice;

    struct Book {
        char bookTitle[100];
        char bookAuthor[40];
        int publicationYear;
        int pageCount;
        int readingStatus;
    };

    int bookCount = 10;

    struct Book myLibrary[bookCount] = {};

    int currentBookCount = 0;

    while(userChoice != 4){

        int userExit;

        printf(" ========================== \n ");
        printf("\tPERSONAL LIBRARY\n "); 
        printf("========================== \n");

        printf("1. Add a book");
        printf("\n2. View Library");
        printf("\n3. Search Book");
        printf("\n4. Exit\n");

        printf("Choose an option (1,2,3,4): ");
        scanf("%d", &userChoice);

        if(userChoice == 1) {

            struct Book newBook;
            
            printf("Add a book\n");

            char newBookTitle[100];

            printf("Enter book title: ");
            scanf(" %[^\n]%*c", newBookTitle);
            strcpy(newBook.bookTitle, newBookTitle);

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

            if(currentBookCount < bookCount){

                myLibrary[currentBookCount] = newBook;

                currentBookCount ++;
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

        } else if(userChoice == 2){

            printf("View Library\n");
            for (int i = 0; i < currentBookCount; i++) {
                printf("%d. Title: %s\n",i+1, myLibrary[i].bookTitle);
                printf("Author: %s\n", myLibrary[i].bookAuthor);
                printf("Publucation Year: %d\n", myLibrary[i].publicationYear);
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

        }else if(userChoice == 3){

            printf("Search Book\n");

            char searchTitle[100];
            
            printf("Please enter a book title to search or enter stop to exit: ");
            scanf(" %[^\n]%*c", searchTitle);

            
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