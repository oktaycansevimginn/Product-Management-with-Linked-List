#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

typedef struct Product {
    int quantity;  
    char name[35]; 
    char type[35]; 
    float price;   
    struct Product* next; 
} Product;

Product* head = NULL;

void addingProd() {
    Product* newProduct = (Product*)malloc(sizeof(Product));  

    printf("Please enter the name of the product: ");
    scanf("%s", newProduct->name);  
    printf("Please enter the product type: ");
    scanf("%s", newProduct->type);  
    printf("Please enter the quantity of the product: ");
    scanf("%d", &newProduct->quantity);  
    printf("Please enter the price of the product: ");
    scanf("%f", &newProduct->price); 

    newProduct->next = head;  
    head = newProduct;  
    printf("The product has been successfully added!\n"); 
}

void updatingProd() {
    char name[50];  
    printf("Please enter the name of the product you want to update: ");
    scanf("%s", name);  

    Product* temp = head;  
    while (temp != NULL) {  
        if (strcmp(temp->name, name) == 0) {  
            printf("Please enter the new type of the product: ");
            scanf("%s", temp->type);  
            printf("Please enter the new quantity: ");
            scanf("%d", &temp->quantity); 
            printf("Please enter the new price: ");
            scanf("%f", &temp->price); 
            printf("The product has been successfully updated!\n");  
        }
        temp = temp->next;  
    }
    printf("The product could not be found!\n"); 
}

void displayingProd() {
    if (head == NULL) { 
        printf("No products are currently available.\n");  
        return;  
    }
    Product *temp1, *temp2; 
    int swapped;  

    do {
        swapped = 0;  
        temp1 = head;  
        while (temp1->next != NULL) {  
            temp2 = temp1->next;  
            if (temp1->quantity > temp2->quantity) {  
                int tempQuantity = temp1->quantity;  
                float tempPrice = temp1->price;  
                char tempName[50], tempType[30];  

                strcpy(tempName, temp1->name);
                strcpy(tempType, temp1->type);

                temp1->quantity = temp2->quantity;
                temp1->price = temp2->price;
                strcpy(temp1->name, temp2->name);
                strcpy(temp1->type, temp2->type);

                temp2->quantity = tempQuantity;
                temp2->price = tempPrice;
                strcpy(temp2->name, tempName);
                strcpy(temp2->type, tempType);

                swapped = 1;  
            }
            temp1 = temp1->next;  
        }
    } while (swapped);  

    Product* temp = head;  
    while (temp != NULL) {  
        printf("Product Name: %s\n", temp->name);  
        printf("Product Type: %s\n", temp->type);  
        printf("Product Quantity: %d\n", temp->quantity);  
        printf("Product Price: %.2f\n", temp->price);  
        printf("-------------\n");  
        temp = temp->next;  
    }
}

void deletingProd() {
    char name[50];  
    printf("Please enter the name of the product you wish to delete: ");
    scanf("%s", name);  

    Product *temp = head, *prev = NULL;  

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        head = temp->next;  
        free(temp);  
        printf("The product has been successfully deleted!\n");  
        displayingProd();
        return;  
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;  
        temp = temp->next;  
    }

    if (temp == NULL) {
        printf("The product could not be found!\n");  
        displayingProd();
        return;  
    }

    prev->next = temp->next;  
    free(temp);  
    printf("The product has been successfully deleted!\n");  
    displayingProd();
}

void menu() {
    int choice;  
    do {
        printf("\n--- Product Management System ---\n");
        printf("1. Add a new product\n");
        printf("2. Update a product\n");
        printf("3. Delete a product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);  

        switch (choice) {
            case 1:
                addingProd();  
                break;
            case 2:
                updatingProd();  
                break;
            case 3:
                deletingProd();  
                break;
            case 4:
                displayingProd();  
                break;
            case 5:
                printf("Exiting program...\n");  
                break;
            default:
                printf("Invalid choice. Please try again.\n");  
                break;
        }
    } while (choice != 5);  
}

int main() {
    menu();  
    return 0;  
}

