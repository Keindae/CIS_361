#ifndef LIST_H_
#define LIST_H_
void printList();
void initialize_list(char *_identifier);
void add_identifier(char _identifier[]);
void push(char _identifier[]);
void move_to_front(struct node *current, struct node *previous);

#endif
