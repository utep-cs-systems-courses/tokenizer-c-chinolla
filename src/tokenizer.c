// Cristobal Chinolla
// Comp. Arch I
// Lab 1 - Tokenizer

#include "tokenizer.h"
#include <stdio.h>
#include <stdlin.h>


// checks 'c' to see if its a space character, if so, returns 1
// if not, returns 0
int space_char(char c){
  if( ( c == '\t' || c == ' ') && c != '\0'){
    return 1;
  }
  else{
    return 0;
  }
}

// checks 'c' to see if its a non-space character, if so, returns 1
// if not, returns 0
int non_space_char(char c){
  if( ( c!= '\t' && c != ' ') && c != '\0'){
    return 1;
  }
  else{
    return 0;
  }
}

// interates through the string until the space_char returns false
// returns the address of that index in the form of a pointer
char *word_start(char *s){
  int i = 0;
  while(space_char(s[i])){
      i++;
    }
    return &s[i];
}


