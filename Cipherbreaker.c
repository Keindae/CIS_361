//Matt Noblett
//CIS 361 - Winter 2017
//Cipher Breaker



#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float given_nums[26];
float clac_nums[26];

//This will load the array called given with the letter frequencies for english from the file letfreq.txt
void readFreq(float given[], char fname[]){
    char str[20];
    int x = 0;
    FILE *filein;
    //Open the file and read it
    filein = fopen(fname, "r");
    //Checking to see if the file exists
    if(filein == NULL){
        printf("Cannot Open File");
        exit(0);
    }
    //This converts each piece of the cipher to a double, and gives each number the correct value. 
    while(fgets(str, 20, filein) != NULL){
        given_nums[x] = atof(str+2);
        x++;
    }
    fclose(filein);
}


//Calc Freq function reads the encoded text from an input file and accumulates the letter frequency data for the encoded text. 
//Then the frequency data is stored in the array called found
void calcFreq(float found[], char fname[]){
    FILE *filein;
    char c;
    int count = 0;

    filein = fopen(fname, "r");

    if(filein == NULL){
        printf("Cannot Open FIle");
        exit(0);
    }

    while((c = fgetc(in)) != EOF){
        if(isalpha(c)){
            if(c >= 'a' && c <= 'z'){
                located[c - 'a']++;
                count++;
            }
            if(c >= 'A' && c <= 'Z'){
                located[c - 'A']++;
                count++;
            }
        }
    }

    for(int i = 0; i < 26; i++){
        located[i] = (located[i]/count);
    }
    fclose(in);
}

//Rotate function rotates the character in the ch parameter down the alphabet for the number of positions as given in parameter num 
//and it is returns the resulting character. 
char rotate( char ch, int num){
    if(islower(ch)){
        return((((ch - 'a') + num) % 26) + 'a');
    }else{
        return((((ch - 'A') + num) % 26) + 'A');

    }

}


int findkey(float given[], float found[]){


}

