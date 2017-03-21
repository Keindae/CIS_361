//Matt Noblett
//Project 2 - Self Organizing List
//Tao - Winter 2017


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>



    //Create the structure for the linked list
    struct node{
        char *identifier;
        int val;
        struct node *next;
    };

    struct node *head;



void  initialize_list(char *identifier){
        head = (struct node *)malloc(sizeof(struct node));
        head->identifier = identifier;
        head->val = 1;
    }

int main(){
    initialize_list("Head");
}


//Function will iterate through the list and print each node inside of the current list
void print_list(struct node *head){
    struct node *current = head;

    while(current != NULL){
        printf("%d\n", current->val);

        current = current->next;
    }
}

//This function will add an item to the end of a list. 
void push(struct node *head, int val){
    struct node *current = head;
    while(current->next != NULL){
        current = current-> next;
    }
    //creates a new node to be store data, and then points to null, indicating the end of the linked list
    current->next = malloc(sizeof(struct node));
    current->next->val = val;
    current->next->next = NULL;

}


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


void pushtofrontsort(

