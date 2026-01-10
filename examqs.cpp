#include<stdio.h>
#include<string.h>

#define Max_Books 5000
typedef struct{
    char title[50];
    int isbn;
    char author[50];
    int publicationYear;
    float price;
}Book;

void add_Book(int *count, Book b[] ){

    int i = *count;
    
        printf("Enter book title: ");
        scanf(" %[^\n]",b[i].title);
        printf("Enter ISBN: ");
        scanf("%d",&b[i].isbn);
        printf("Author Name: ");
        scanf(" %[^\n]",&b[i].author);
        printf("Publication Year:");
        scanf("%d",&b[i].publicationYear);
        printf("Price: ");
        scanf("%f",&b[i].price);
        (*count)++;
    
}

void displayBook(Book b){
    printf("Book title: %s\n",b.title);
    printf("Book Isbn: %d\n",b.isbn);
    printf("Book author: %s\n",b.author);
    printf("Publication Year: %d\n",b.publicationYear);
    printf("Price: %.2f\n",b.price);
}

void cheapestBookInsertionSort(Book b[], int *count){
    for(int i = 1; i<*count; i++){
        Book key = b[i];
        int j = i-1;
        while(j>=0 && b[j].price>key.price){
            b[j+1] = b[j];
            j = j-1;
        }
        b[j+1] = key;
    }
}
void sortByPublicationYear(Book b[], int *count){
    int n = *count;
    for(int i = 1; i<n; i++){
        Book key = b[i];
        int j = i-1;
        while (j>=0 && b[j].publicationYear<key.publicationYear)
        {
            b[j+1] = b[j];
            j=j-1;
        }
        b[j+1] = key;
        
    }
}

int main(){

    
    
    int M;
    printf("Enter a number of book: ");
    scanf("%d",&M);
    Book book[Max_Books];

    int count = 0;
    
    for(int i = 0; i<M; i++){
        printf("Enter book title: ");
        scanf(" %[^\n]",book[i].title);
        printf("Enter ISBN: ");
        scanf("%d",&book[i].isbn);
        printf("Author Name: ");
        scanf(" %[^\n]",&book[i].author);
        printf("Publication Year:");
        scanf("%d",&book[i].publicationYear);
        printf("Price: ");
        scanf("%f",&book[i].price);
        count++;
    }

    int choice;
    while(1){
        printf("1. Add a new book record\n");
        printf("2. Search for a book ISBN\n");
        printf("3. Kth cheapest book\n");
        printf("4. Show all books sorted by publication year\n");
        printf("5.Exit\n");

        printf("Enter your Choice: ");
        scanf("%d",&choice);

        if(choice == 1){
            add_Book(&count, book );
        }else if(choice == 2){
            int search;
            printf("Enter Isbn: ");
            scanf("%d",&search);
            for(int i = 0; i<count; i++){
            if(book[i].isbn == search){
                displayBook(book[i]);
                break;
            }
        }
        }else if(choice == 3){
            int k;
            printf("Enter kth chepeast book: ");
            scanf("%d",&k);
            cheapestBookInsertionSort(book, &count);
            displayBook(book[k-1]);
        }else if(choice == 4){
            sortByPublicationYear(book, &count);
            for(int i = 0; i<count; i++){
            displayBook(book[i]);
        }
        }else if(choice == 5){
            break;
        }else{
            printf("Invalid Choice\n");
        }
        
    
    }
    
    
}