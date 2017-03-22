//Matt Noblett
//Project 2 - Self Organizing List
//Tao - Winter 2017


#include <stdio.h>
//#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

/*
void initialize_list(char *identifier);
void print_list(struct node *head);
void push(struct node *head, int val);
int pop(struct node **head);
*/
    //Create the structure for the linked list
    struct node{
        char *identifier;
        int occurence;
        int val;
        struct node *next;
    };

    struct node *head;
    struct node *current;


//This is used to initialize the list
void  initialize_list(char *identifier){
        head = (struct node *)malloc(sizeof(struct node));
        head->identifier = identifier;
        head->val = 1;
        head->occurence = 1;
        //printf("%s\n", current->identifier);
    }


//Function will iterate through the list and print each
//node inside of the current list
void print_list(){
    struct node *current = head;

    while(current != NULL){
        printf("%s\n", current->identifier);
      }
        current = current->next;
}

//This function will add an item to the end of a list.
void push(char *identifier, int val){
    struct node *current = head;
    while(current->next != NULL){
        current = current-> next;
    }
    //creates a new node to store data,
    //and then points to null, indicating the end of the linked list
    current->next = malloc(sizeof(struct node));
    current->next->val = val;
    current->next->next = NULL;

}

//Pops the top part of the list off, and out of the linked list.
int pop(struct node **head){
    int retval = -1;
    struct node *next_node = NULL;

    if(*head == NULL){
        return -1;
    }
    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

//This will search through the linked list, and find the value that is being
//requested, and then switch the data in the head, and the current node,
//making the searches for the same value faster.

void pushtofrontsort(char *identifier){
  int i, j, tempKey, tempData;
   struct node *current;
   int size = sizeof(struct node);

   for ( i = 0 ; i < size - 1 ; i++) {
      current = head;
      for ( j = 1 ; j < size - 1; j++ ) {
         if ( current->identifier == identifier ) {
            tempData = current->val;
            current->val = head->val;
            head->val = tempData;

            tempKey = current->occurence;
            current->occurence = head->occurence;
            head->occurence = tempKey;
         }
      }
   }
}

//Main to run the program and test
int main(){
    initialize_list("Head");
    push("song", 1);
    push("wing", 1);
    //print_list();

    char userInput[50];
    printf("Please input what you are searching for: \n");
    fgets(userInput, 60, stdin);
    pushtofrontsort(userInput);
    print_list();
}
