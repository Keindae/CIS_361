
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
#define MAX_IDENTIFIER_LENGTH 31
//This is used for parsing the file. This checks for either a specific
//delimiter or character, or if there are multiple lines.
void handleChar(char currentString[], char newChar){
  currentString[strcspn(currentString, "\r\n")] = 0;
  int len = strlen(currentString);
  if(len == 0){
    if(isalpha(newChar) || newChar == '_'){
      currentString[0] = newChar;
    }
  }
  //Checking to see if it isalpha, isdigit,
  //or if the new character is equal to "_"
  else if(isalpha(newChar) || newChar == '_' || isdigit(newChar)){
    currentString[len] = newChar;
  }
  else if(len != 0){
    currentString[strcspn(currentString, "\r\n")] = 0;
    add_identifier(currentString);
    memset(currentString, 0, MAX_IDENTIFIER_LENGTH);
  }
}
//Main used to execute the functions and check if everything is working.
int main(){
    char currentIdentifier[MAX_IDENTIFIER_LENGTH];
    currentIdentifier[0] = NULL;
    initialize_list("Matt Noblett");
    //Creates the file that we are reading in
    FILE *file_in;
    char buf[1000];
    int isSingleLineComment = 0;
    int isMultiLineComment = 0;
    int isString = 0;
    file_in = fopen("sample1.c", "r");
    if(!file_in){
        printf("File failed to open");
        return 1;
    }
    //Reading each line of the file.
    while(fgets(buf, 1000, file_in)!=NULL){
        isSingleLineComment = 0;
        int i;
        for(i = 0; i < strlen(buf); i++){
          //If we are already in a comment
          //or string don't look for beginning characters
          if(!isSingleLineComment && !isMultiLineComment && !isString){
            if(buf[i] == '/'){
              if(buf[i + 1] == '/'){
                isSingleLineComment = 1;
              }
              if(buf[i + 1] == '*'){
                isSingleLineComment = 0;
                isMultiLineComment = 1;
              }
            }
            else if(buf[i] == '"'){
               isString = 1;
             }
          }else{
            if(isMultiLineComment && buf[i] == '*' && buf[i + 1] == '/'){
              isMultiLineComment = 0;
            }
            else if(isString && buf[i] == '"'){
              isString = 0;
            }
          }
          if(!isSingleLineComment && !isMultiLineComment && !isString){
            handleChar(currentIdentifier, buf[i]);
          }
        }
    }
    fclose(file_in);

    printList();
    return 0;

}
