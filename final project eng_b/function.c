// noi di trien khai cai ham

#include <stdio.h>
#include "function.h"
#include<string.h> 
#include<stdbool.h> 
#include <ctype.h>
void getInforByFile(struct Book books[],int *n){
	FILE *file;
	file = fopen("book2.bin","rb");
	if(file == NULL){
		printf("Khong the mo file");
		return; 
	}
	fread(n,sizeof(int),1,file);
	fread(books,sizeof(struct Book),*n,file);
	fclose(file);
}
void saveBooksToFile(struct Book books[], int n) {
    FILE *file = fopen("book2.bin", "wb");
    if (file == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fwrite(&n, sizeof(int),1,file);
    fwrite(books, sizeof(struct Book), n, file);
    fclose(file);
	printf("Luu thong tin sach thanh cong!\n");
} 
int titleUnique(struct Book books[], int n, char *title) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return 0; 
        }
    }
    return 1;
}


int idUnique(struct Book books[], int n, char *bookID) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].bookID, bookID) == 0) {
            return 0; 
        }
    }
    return 1; 
}


void addBook(struct Book books[], int *n) {
    if (*n >= 100) {
        printf("The library is full\n");
        return;
    }
    struct Book newBook;

    printf("Type ID: ");
    fgets(newBook.bookID, sizeof(newBook.bookID), stdin);
    newBook.bookID[strcspn(newBook.bookID, "\n")] = 0;
    if (strlen(newBook.bookID) == 0) {
        printf("ID is empty\n");
        printf("Please type again\n"); 
        return;
    }else if(strlen(newBook.bookID)>=20){
    	printf("Id is too long\n");
        printf("Please type again\n"); 
        return;
	}
    if (!idUnique(books, *n, newBook.bookID)) {
        printf("ID existed\n"); 
        return;
    }

    printf("Type title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    if (strlen(newBook.title) == 0) {
        printf("Title is empty\n");
        printf("Please type again\n"); 
        return;
    }
    if (!titleUnique(books, *n, newBook.title)) {
        printf("Title existed\n");
        printf("Please type again\n"); 
        return;
    }

    printf("Nhap tac gia: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;
    if (strlen(newBook.author) == 0) {
        printf("Author is empty\n");
        printf("Please type again\n"); 
        return;
    }

    printf("Nhap gia sach: ");
    scanf("%f", &newBook.price);
    getchar();
    if (newBook.price <= 0) {
        printf("Price must be greater than 0\n");
        printf("Please type again\n"); 
        return;
    }

    printf("Nhap the loai: ");
    fgets(newBook.category, sizeof(newBook.category), stdin);
    newBook.category[strcspn(newBook.category, "\n")] = 0;
    if (strlen(newBook.category) == 0) {
        printf("Category is empty\n");
        printf("Please type again\n"); 
        return;
    }

    books[*n] = newBook;
    (*n)++;
    printf("Add book successfully!\n");
}


void displayBooks(struct Book books[], int n) {
    if (n == 0) {
        printf("Library is empty\n");
    } else {
        printf("+--------------------+------------------------------+------------------------------+-------------+------------------------------+\n");
        printf("| %-18s | %-28s | %-28s | %-11s | %-28s |\n", "ID", "Title", "Author", "Price", "Category");
        printf("+--------------------+------------------------------+------------------------------+-------------+------------------------------+\n");

        for (int i = 0; i < n; i++) {
            printf("| %-18s | %-28s | %-28s | %-11.2f | %-28s |\n",
                   books[i].bookID,
                   books[i].title,
                   books[i].author,
                   books[i].price,
                   books[i].category);
        }
        printf("+--------------------+------------------------------+------------------------------+-------------+------------------------------+\n");
    }
}


void updateBookById(struct Book books[], int *n){
    char bookId[20];
    printf("Type ID need to edit: ");
    fgets(bookId, sizeof(bookId), stdin);
    bookId[strcspn(bookId, "\n")] = 0;
    
    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strcmp(books[i].bookID, bookId) == 0) {
            found = 1;
            printf("Title: %s\n",books[i].title);
			printf("Author: %s\n",books[i].author);
			printf("Price: %.2f\n",books[i].price);
			printf("Category: %s\n",books[i].category); 
            printf("Type new title: ");
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = 0;

            printf("Type new author: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = 0;

            printf("Type new price: ");
            scanf("%f", &books[i].price);
            getchar(); 

            printf("Type new category: ");
            fgets(books[i].category, sizeof(books[i].category), stdin);
            books[i].category[strcspn(books[i].category, "\n")] = 0;
            break;
        }
    }
    if (!found) {
        printf("The book is not founded\n");
    }
    
}
void deleteBookById(struct Book books[], int *n) {
    char bookId[20];
    printf("Type ID need to delete: ");
    fgets(bookId, sizeof(bookId), stdin);
    bookId[strcspn(bookId, "\n")] = 0;
    
    int found = 0;
   
    for (int i = 0; i < *n; i++) {
        if (strcmp(books[i].bookID, bookId) == 0) {
            found = 1;
            int flag ;
            printf("Do you want to delete this book ?\n");
            printf("1: Yes   0:No \n");
            scanf("%d",&flag);
            getchar(); 
            if(flag==1){
            for (int j = i; j < *n - 1; j++) {
                books[j] = books[j + 1];
            } 
            (*n)--;
            printf("The book is deleted\n"); 
            break;
        	}else if(flag==0){
        		printf("The book is not deleted\n");
        		break;
			}else{
				printf("Wrong choice\n");
				break;
			}
				
        }
    }
    if (!found) {
        printf("The book is not founded\n");
    }
}
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void searchBookByTitle(struct Book books[], int n) {
    char title[100];
    printf("type title need to search: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;
    toLowerCase(title);

    int found2 = 0;
    for (int i = 0; i < n; i++) {
       
    char bookTitle[100];
    strcpy(bookTitle, books[i].title);
    toLowerCase(bookTitle);

        if (strstr(bookTitle, title) != NULL) {
            printf("ID: %s\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n", books[i].price);
            printf("Category: %s\n\n", books[i].category);
            found2 = 1;
        }
    }
    if (!found2) {
        printf("The book is not founded!\n"); 
    }
}

void sortBooksByPrice(struct Book books[], int n, int pick) {
    struct Book temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((pick == 1 && books[i].price > books[j].price) || 
                (pick == 2 && books[i].price < books[j].price)) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
void saveCustomersToFile(Customer customers[], int n) {
    FILE *file = fopen("member.bin", "wb");
    if (file == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    
    fwrite(&n, sizeof(int), 1, file);
    fwrite(customers, sizeof(Customer), n, file);
    fclose(file);
    printf("Thong tin khach hang da duoc luu vao tep %s.\n", "member.bin");
}
bool isUniqueCustomer(Customer customers[], int n, char* memberId, char* phone) {
    for (int i = 0; i < n; i++) {
        if (strcmp(customers[i].memberId, memberId) == 0 || strcmp(customers[i].phone, phone) == 0) {
            return false;
        }
    }
    return true;
}
void addCustomer(Customer customers[], int* n) {
    if (*n < 100) {
        Customer newCustomer;
        printf("Nhap Ma khach hang:");
        fflush(stdin);     
        if (fgets(newCustomer.memberId, sizeof(newCustomer.memberId), stdin) != NULL) {
            newCustomer.memberId[strcspn(newCustomer.memberId, "\n")] = 0;
            if (strlen(newCustomer.memberId) == 0) {
                printf("ID is empty\n");
                printf("Please type again\n");
                return;
            }
            if (!isUniqueCustomer(customers, *n, newCustomer.memberId, newCustomer.phone)) {
                printf("Member ID or Phone number already exists. Please type a different ID or Phone number.\n");
                return;
            }
        } else {
            printf("Error reading input\n");
            return;
        }

        printf("Nhap ten khach hang: ");
        if (fgets(newCustomer.name, sizeof(newCustomer.name), stdin) != NULL) {
            newCustomer.name[strcspn(newCustomer.name, "\n")] = 0;
            if (strlen(newCustomer.name) == 0) {
                printf("Name is empty\n");
                printf("Please type again\n");
                return;
            }
        } else {
            printf("Error reading input\n");
            return;
        }

        while (1) {
            printf("Nhap so dien thoai khach hang: ");
            if (fgets(newCustomer.phone, sizeof(newCustomer.phone), stdin) != NULL) {
                newCustomer.phone[strcspn(newCustomer.phone, "\n")] = 0;
                if (strlen(newCustomer.phone) == 10) {
                    bool valid = true;
                    for (int i = 0; i < 10; i++) {
                        if (!isdigit(newCustomer.phone[i])) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        if (isUniqueCustomer(customers, *n, newCustomer.memberId, newCustomer.phone)) {
                            break;
                        } else {
                            printf("Phone number already exists. Please type a different number.\n");
                            return;
                        }
                    }
                }
                printf("Invalid phone number. Please try again.\n");
            } else {
                printf("Error reading input\n");
                return;
            }
        }

        newCustomer.status = true;
        customers[*n] = newCustomer;
        (*n)++;
        printf("Khach hang da duoc them thanh cong!\n");
    } else {
        printf("Khong the them khach hang moi, da day!\n");
    }
}

void showCustomer(Customer customers[], int n) {
    if (n == 0) {
        printf("Chua co khach hang nao.\n");
    } else {
        printf("+---------------------+------------------------------+---------------------+-----------+\n");
        printf("| Ma khach hang       | Ten khach hang               | So dien thoai       | Trang thai|\n");
        printf("+---------------------+------------------------------+---------------------+-----------+\n");

        for (int i = 0; i < n; i++) {
            printf("| %-19s | %-28s | %-19s | %-9s |\n", customers[i].memberId, customers[i].name, customers[i].phone, customers[i].status ? "Open" : "Lock");
        }

        printf("+---------------------+------------------------------+---------------------+-----------+\n");
    }
}
void lockOrUnlockStatus(Customer customers[], int n) {
    char memberId[20];
    bool found = false;
    
    printf("Nhap Ma khach hang de khoa/mo khoa: ");
    fflush(stdin);
    if (fgets(memberId, sizeof(memberId), stdin) != NULL) {
        memberId[strcspn(memberId, "\n")] = 0; 

        for (int i = 0; i < n; i++) {
            if (strcmp(customers[i].memberId, memberId) == 0) {
                found = true;
                if (customers[i].status) {
                    customers[i].status = false;
                    printf("Khach hang da bi khoa thanh cong!\n");
                } else {
                    customers[i].status = true;
                    printf("Khach hang da duoc mo khoa thanh cong!\n");
                }
                break; 
            }
        }
        
        if (!found) {
            printf("Khong tim thay khach hang voi Ma khach hang nay.\n");
        }
    } 
}
void searchCustomerByName(Customer customers[], int n) {
    char searchName[50];
    int foundCount = 0;

    printf("Nhap ten khach hang de tim kiem: ");
    fflush(stdin);
    if (fgets(searchName, sizeof(searchName), stdin) != NULL) {
        searchName[strcspn(searchName, "\n")] = 0;

        printf("+---------------------+------------------------------+---------------------+-----------+\n");
        printf("| Ma khach hang       | Ten khach hang               | So dien thoai       | Trang thai|\n");
        printf("+---------------------+------------------------------+---------------------+-----------+\n");

        for (int i = 0; i < n; i++) {
            if (strstr(customers[i].name, searchName) != NULL) {
                printf("| %-19s | %-28s | %-19s | %-9s |\n", customers[i].memberId, customers[i].name, customers[i].phone, customers[i].status ? "Open" : "Locked");
                foundCount++;
            }
        }

        if (foundCount == 0) {
            printf("Khong tim thay khach hang nao.\n");
        } else {
            printf("+---------------------+------------------------------+---------------------+-----------+\n");
        }
    }
}
void GetCustomersFromFile(Customer customers[], int *n) {
    FILE *file = fopen("member.bin", "rb");
    if (file == NULL) {
        printf("Khong the mo tep de doc.\n");
        return;
    }

    fread(n, sizeof(int), 1, file);
    fread(customers, sizeof(Customer), *n, file);
    fclose(file);
}




 



