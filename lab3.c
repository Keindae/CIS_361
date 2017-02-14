#include <stdio.h>
#include <string.h>

#define LEN 5

char* strnsub (char *p, int n);

int main()
{
	char line[] = "His textbook was bought from that bookstore";  
	char *p1, *p2;
    int match = 0;

	//set p1 to the beginning of string line;
    p1 = line;
	
	while ( *(p1 + LEN) ) 	
	{
		//set p2 to the position immediately after p1
            p2 = p1 + 1;
		
		while ( *(p2 + LEN) )
		{
			if (strncmp(p1, p2, LEN) == 0){		// use strncmp() to compare	
				match = 1;
                goto done;	
            }
				
			//advance p2 to the next position
           *p2++;
           
		}

		//advance p1 to the next position
        *p1++;
	}
done:	
    if(match){
        printf ("the first substring: %s\n", strnsub(p1, LEN));
	    printf ("the second substring: %s\n", strnsub(p2, LEN));
    }
    else{
        printf("No matching strings\n");
    }
	return 0;
}


// returns a string with the first n characters of string p

char* strnsub (char *p, int n)
{
	// write function definition here
    
    int i;
    char *returnString = malloc(n+1);
    for(i = 0; i < 4; i++){
        if(!(*(p + i) == '\n')){
            returnString[i] = *(p+i);
        }
    }
    returnString[n] = '\0';
    return returnString;
}
