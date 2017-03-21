#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 25

typedef int EType;		// type of elements in stack
typedef int BOOLEAN;

typedef struct {
	EType data[MAX];
	int top;
} STACK;

void initialize(STACK *pS) 	// initialze the stack	
{
    pS->top = -1;
}

BOOLEAN isEmpty(STACK *pS) 	// returns true if the stack is empty
{
    if(pS->top == -1){
        return TRUE;
    }
    return FALSE;
}

BOOLEAN isFull(STACK *pS)  	// returns true if the stack is full
{
    if(pS->top == MAX -1){
        return TRUE;
    }
    return FALSE;
}

BOOLEAN pop(STACK *pS, EType *px)	// removes the top element from the stack 
{					// has px point to the removed element   
                    // returns true if done successfully       

    if(isEmpty(pS)){
        return FALSE;
    }else{
        *px = (pS->data[pS->top]);
        pS->top--;
        return TRUE;
    }

}

BOOLEAN push(EType x, STACK *pS)	// puts an element on the top of the stack  
{					// returns true if done successfully       


    if(isFull(pS)){
        return FALSE;
    }else{
        pS->data[pS->top++] = x;
        return TRUE;
    }
}

int main ()
{
	STACK s;
	EType i;
    int poppedresults;
	initialize (&s);

	// write code below to test functions defined above
    for(i = 0; i< 26; i++){
        if(!(push(i, &s))){
            printf("Number is to large\n");
        }
    }

    for(i = 0; i < 27; i++){
        if(!(pop(&s, &poppedresults))){
                printf("Number is too small\n");
        }else{
            printf("%d\n", poppedresults);
        }
    }
    return 0;
}

