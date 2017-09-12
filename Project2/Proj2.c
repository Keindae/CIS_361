/*
Matt Noblett
Project 2 - Self Organizing List
Tao - GVSU Winter 2017
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
#define MAX_IDENTIFIER_LENGTH 31
//This is used for parsing the file. This checks for either a specific
//delimiter or character, or if there are multiple lines.
void readChar(char currentString[], char character){
  currentString[strcspn(currentString, "\r\n")] = 0;
  int len = strlen(currentString);
  if(len == 0){
    if(isalpha(character) || character == '_'){
      currentString[0] = character;
    }
  }
  //Checking to see if it isalpha, isdigit,
  //or if the new character is equal to "_"
  else if(isalpha(character) || character == '_' || isdigit(character)){
    currentString[len] = character;
  }
  else if(len != 0){
    currentString[strcspn(currentString, "\r\n")] = 0;
    addIdentifier(currentString);
    memset(currentString, 0, MAX_IDENTIFIER_LENGTH);
  }
}
//Main used to execute the functions and check if everything is working.
int main(int argc, char **argv){
    char currentIdentifier[MAX_IDENTIFIER_LENGTH];
    currentIdentifier[0] = NULL;
    //Used to get the command line arguments that is the user is passing in
    char *file;
    file = argv[1];
    char *file2;
    file2 = argv[2];
    //Creates the file that we are reading in
    FILE *inputfile;
    char buffer[1000];
    //Used to store how many single line comments
    int isSingleLineComment = 0;
    //Used to store how many multi line comments there are
    int isMultiLineComment = 0;
    //Store the number of strings
    int isString = 0;
    //Open the file that is passed in by the user via command line
    inputfile = fopen(file, "r");
    if(!inputfile){
        printf("Error Opening the File");
        return 1;
    }
    //Reading each line of the file.
    //Logic for figuring out the delimeters and unique characters
    while(fgets(buffer, 1500, inputfile)!=NULL){
        isSingleLineComment = 0;
        int i;
        for(i = 0; i < strlen(buffer); i++){
          //If we are already in a comment
          //or string don't look for beginning characters
          if(!isSingleLineComment && !isMultiLineComment && !isString){
            //Check to see if the line is a comment
            if(buffer[i] == '/'){
              //Move ahead one position to see if it is going to be a
              //multi line comment, or a single line comment.
              if(buffer[i + 1] == '/'){
                isSingleLineComment = 1;
              }
              //If an asterik follows a '/', then I know it is going to be a
              //multi line comment.
              if(buffer[i + 1] == '*'){
                isSingleLineComment = 0;
                isMultiLineComment = 1;
              }
            }
            else if(buffer[i] == '"'){
               isString = 1;
             }
          }else{
            if(isMultiLineComment && buffer[i] == '*' && buffer[i + 1] == '/'){
              isMultiLineComment = 0;
            }
            else if(isString && buffer[i] == '"'){
              isString = 0;
            }
          }
          if(!isSingleLineComment && !isMultiLineComment && !isString){
            readChar(currentIdentifier, buffer[i]);
          }
        }
    }
    fclose(inputfile);

    printList(file2);
    return 0;

}
