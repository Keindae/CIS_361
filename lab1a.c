#include <stdio.h>
#include <ctype.h>
int main () {
	char ch;
    //Counters to keep track of how many of the word or symbol sequences there are. 
    int wordcount;
    int symbolcount;
    //Created to keep track of what the character is. 
    int isWord = 0;
    int isSymbol = 0;
	printf ("Enter text (Ctrl-D to quit).\n");

	while ( ch = getchar(), ch != EOF ) {
        //Checks white space first.
        if(isspace(ch)){
            isWord = 0;
            isSymbol = 0;
        }
        //Checks to see if there is Alpha Numeric. 
        else if(isalnum(ch)){
            if(!isWord){
                isWord = 1;
                wordcount++;
            }
            if(isSymbol){
                isSymbol = 0;
            }
        }
        //Anything else besides this is going to be a "symbol".
        else{
            if(!isSymbol){
                isSymbol = 1;
                symbolcount++;
            }
            if(isWord){
                isWord = 0;
            }
        }
        putchar(ch);
    }

    printf("Input Word Count: %d\n Input Symbol Count: %d\n", wordcount, symbolcount);
}


