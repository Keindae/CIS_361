/*
Matt Noblett
Header File for the functions
Tao - GVSU Winter 2017
*/

#ifndef LIST_H_
#define LIST_H_
void printList(char *argv);
void createList(char *identifier);
void addIdentifier(char identifier[]);
void pushToFront(char identifier[]);
void sortToFront(struct node *current, struct node *previous);

#endif
