/*
Matt Noblett
Setting up for the Linked List and Linked List functions
Tao - GVSU Winter 2017
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_IDENTIFIER_LENGTH 31
//Create the strucutre of the linked list and the parameters inside of it
struct node{
    char *identifier;
    int occurences;
    struct node *next;
};
struct node *head;

//Print all the elements inside of the linked list to a defined outputfile.
void printList(char *argv){
  FILE *outputfile;
  outputfile = fopen(argv, "w");
    struct node *current = head;
    while(current != NULL){
        fprintf(outputfile, "%s: %d\n", current->identifier, current->occurences);
        current = current -> next;
    }
    fclose(outputfile);
}
//Initalizes the linked list - creates only the head
void createList(char *identifier){
    head = (struct node *) malloc(sizeof(struct node));
    head->identifier = identifier;
    head->occurences = 1;
    head->next = NULL;
}
//Pushes an item to the front of the list, rather than appending it to
//the end of the list
void pushToFront(char identifier[]){
    struct node * new_node;
    new_node = malloc(sizeof(struct node));
    new_node->occurences = 1;
    new_node->identifier = identifier;
    new_node->next = head;
    head = new_node;
    return;
}
//Moves the found item to the front of the linked list, and moves the head
//to the current position in the linked list
void sortToFront(struct node * current, struct node * previous){
    //if the previous is null, then there is nothing to do.
    if(previous == NULL){
        return;
    }
    //Sets the previous to the current position. Then set the current position
    //to the head, which now makes it the head of the list.
    previous->next = current->next;
    current->next = head;
    head = current;
}
//Creates an identifier to be added to the position in the linked list.
void addIdentifier( char *identifier){
    //make local copy of string
    char *copy = malloc(1 + strlen(identifier));
    if(copy){ strcpy(copy, identifier);}
    struct node * current = head;
    struct node * previous = NULL;
    while(current != NULL){
        //Check to see if the identifier and the copy are the sample
        //If they are, then we increase the amount of occureneces there are for
        //that word, and then move it to the front of the linked list.
        if(strcmp(copy, current->identifier) == 0){
            current->occurences++;
            sortToFront(current, previous);

            return;
        }
        previous = current;
        current = current -> next;
    }
    //this is only hit if there are not more identifiers in the list.
    pushToFront(copy);
}
