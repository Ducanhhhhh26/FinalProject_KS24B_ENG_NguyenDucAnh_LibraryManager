// day la noi de code chinh va the ham vao 
#include <stdio.h>
#include <stdlib.h>
#include "function.h" 
#include "datatype.h"

int main(int argc, char *argv[]) {
int option;
	do{
		printf("***Library Management System Using C***\n");
		printf("[1] Book Manager\n");
		printf("[2] Member Manager\n");
		printf("[3] Exit\n"); 
		
		printf("==================================\n"); 
		printf("\t CHOOSE YOUR ROLE \t \n");
		scanf("%d",&option);
		switch(option){
			case 1:{
				int choice; 
			
				struct Book library[100];
				int bookCount= 0;
				getInforByFile(library, &bookCount);
				system("cls"); 
		do{
			printf("********Quan li sach********\n"); 
			printf("[1] Add a new book\n");
			printf("[2] Display all books\n");
			printf("[3] Edit book's information\n");
			printf("[4] Delete book\n");
			printf("[5] Search for books\n");
			printf("[6] Sort book\n");
			printf("[7] Back to Menu\n");  
			printf("=============================\n"); 
			printf("Choose your role:"); 
			scanf("%d",&choice); 
			getchar(); 
			switch(choice){
				case 1: {
					system("cls"); 
					addBook(library, &bookCount);
					saveBooksToFile(library, bookCount);	
					break;
				} 
				case 2: {
					system("cls"); 
					displayBooks(library, bookCount);
					saveBooksToFile(library, bookCount);
					break;
				} 
				case 3: {
					system("cls"); 
					updateBookById(library, &bookCount);
					saveBooksToFile(library, bookCount);
					break;
				} 
				case 4: {
					system("cls"); 
					deleteBookById(library, &bookCount);
					saveBooksToFile(library, bookCount);
					break;
				} 
				case 5: {
					system("cls"); 
					searchBookByTitle(library, bookCount);
					saveBooksToFile(library, bookCount);
					break;
				} 
				case 6: {
					system("cls"); 
					int pick;
					printf("Choose your role\n");
					printf("1:Increasing\n2:Decresing\n");
					scanf("%d",&pick); 
					sortBooksByPrice(library, bookCount, pick);
					printf("The list after being arranged is:\n");
					saveBooksToFile(library, bookCount);
    				displayBooks(library, bookCount);
					break;
				} 
				case 7: {
					system("cls"); 
					printf("You exited\n"); 
					break;
				} 	
				default :
					printf("wrong choice, please choose again\n"); 
			} 
			} while(choice!=7); 
				break;
			
		}
		case 2: {
			system("cls");
				int choose;
				Customer member[100];
				int customerCount =0; 
				GetCustomersFromFile(member,&customerCount);
			do{
				printf("********Customer Manager********\n");
				printf("[1]:Add a customer\n");
				printf("[2]:Show customer\n");
				printf("[3]:Edit customer's infor\n");
				printf("[4]:Unlock customer's status \n");			
				printf("[5]:Search customer\n");
				printf("[6]:Back to menu\n");
				printf("=============================\n");
				printf("Enter your choice:");
				scanf("%d",&choose);
				
				switch(choose){
					case 1:{
						system("cls"); 
						addCustomer(member,&customerCount);
						saveCustomersToFile(member,customerCount);
						break;
					}
					case 2:{
						system("cls");
						showCustomer(member,customerCount);
						break;
					}
					case 3:{
						system("cls");
						break;
					}
					case 4:{
						system("cls");
						lockOrUnlockStatus(member,customerCount);
						saveCustomersToFile(member,customerCount);
						break;
					}
					case 5:{
						system("cls");
						searchCustomerByName(member,customerCount);
						break;
					}
					case 6:{
						system("cls");
						break;
					}
					default:
					printf("Wrong choice!\nplease choose again");
				}
				}while(choose!=6); 
			break;
		} 
		case 3:{
			printf("You exited !"); 
			break;
		} 
		default :
			printf("Wrong choice!\nplease choose again");  
		} 
	} while(option!=3); 
	
	
	
	
	return 0;
}
