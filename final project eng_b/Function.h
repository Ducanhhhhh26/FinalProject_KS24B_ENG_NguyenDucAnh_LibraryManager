// di khai bao nhung nguyen mau ham
#include<stdbool.h> 
#include"datatype.h"
//book 
struct Book {
    char bookID[20];
    char title[30];
    char author[30];
    float price;
    char category[30];
};
typedef struct {
    char memberId[50];
    char name[20];
    char phone[15];	
    bool status;
} Customer;

void getInforByFile(struct Book books[],int *n);
void saveBooksToFile(struct Book books[], int n);
void addBook(struct Book books[], int *n);
int titleUnique(struct Book books[], int n, char *title);
int idUnique(struct Book books[], int n, char *bookID);
void addBook(struct Book books[], int *n);
void displayBooks(struct Book books[], int n);
void updateBookById(struct Book books[], int *n);
void deleteBookById(struct Book books[], int *n);
void searchBookByTitle(struct Book books[], int n);
void sortBooksByPrice(struct Book books[], int n, int pick);



 void saveCustomersToFile(Customer customers[], int n);
void addCustomer(Customer customers[], int* n);
void showCustomer(Customer customers[], int n);
void editCustomer(Customer customers[], int n);
void unlockLockStatus(Customer customers[], int n);
void searchCustomer(Customer customers[], int n);
bool isUniqueCustomer(Customer customers[], int n, char* memberId, char* phone);
void lockOrUnlockStatus(Customer customers[], int n);
void searchCustomerByName(Customer customers[], int n);
void GetCustomersFromFile(Customer customers[], int *n);
 





