#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcomeUser();
void seeToDo();
void createToDo();
void delToDo();

typedef struct todo {
    char data[100];
    int count;
    struct todo* next;
} todo;

todo* start;
todo* currentNode;

int main() {
    int choice;
    welcomeUser();

    while (1) {
        printf("\n1. See Your ToDo List");
        printf("\n2. Create Your ToDos");
        printf("\n3. Delete Your ToDos");
        printf("\n4. Update Your ToDos");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                seeToDo();
                break;
            case 2:
                createToDo();
                break;
            case 3:
                delToDo();
                break;
                /*
            case 4:
                updateToDo();
                break;
                */
            case 5:
                exit(0);
                
        }
    }

    return 0;
}

void welcomeUser() {
    printf("\n\n\n\n\n");
    printf("\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t#################################### YOUR TODO LIST APP ###################################\n\n");
    printf("\t-------------------------------------------------------------------------------------------");
    printf("\n\n\n\t\t**********************************WELCOME********************************\n\n\n\n\n\n\n\n\n\t");
}

void seeToDo() {
    currentNode = start;

    if (start == NULL) {
        printf("\nEmpty TODO\n\n");
        return;
    }

    int count = 1;

    while (currentNode != NULL) {
        printf("%d) %s\n", count, currentNode->data);
        currentNode = currentNode->next;
        count++;
    }

    printf("\n");
}

void createToDo() {
    char k;
    todo* t;

    while (1) {
        printf("\nWant to add? (y/n): ");
        fflush(stdin);
        scanf(" %c", &k);

        if (k == 'n') {
            break;
        } else {
            if (start == NULL) {
                currentNode = (struct todo*)malloc(sizeof(struct todo));
                start = currentNode;
                printf("\nAdd it..\n");
                fflush(stdin);
                fgets(currentNode->data, sizeof(currentNode->data), stdin);
                currentNode->count = 1;
                currentNode->next = NULL;
            } else {
                currentNode->next = (struct todo*)malloc(sizeof(struct todo));
                currentNode = currentNode->next;
                printf("\nAdd it..\n");
                fflush(stdin);
                fgets(currentNode->data, sizeof(currentNode->data), stdin);
                currentNode->count = 1;
                currentNode->next = NULL;
            }
        }
    }
}

void delToDo() {
    int del;
    printf("\nEnter the number of the todo you want to remove: ");
    scanf("%d", &del);

    if (start == NULL) {
        printf("Empty TODO\n");
        return;
    }

    if (start->count == del) {
        todo* temp = start;
        start = start->next;
        free(temp);
        return;
    }

    todo* current = start;
    todo* previous = NULL;

    while (current != NULL && current->count != del) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid todo number\n");
        return;
    }

    previous->next = current->next;
    free(current);
}



