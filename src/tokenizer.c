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


// uses the pointer from word_start to start at the first letter of the string and interates until
// a space character is found (non_space_char returns true)
// returns the address of the first space character in the string (the end of the word)
char *word_terminator(char *word){
  start_of_word = word_start(word);
  int i = 0;
  while(non_space_char(start_of_word[i])){
    i++;
  }
  return &start_of_word[i];
}




// returns int value for number of words in a string
int count_words(char *c){
  int count = 0;

  while( c != word_terminator(c)){ // c cannot initially be == to word_term(c) because never called
    c = word_terminator(c); // c is given the value of word_term(c) for 1st word (if > 1 in str)
    count++;
  }
  return count;
}


// returns the first address of output string which now has memory allocated for it 
char *copy_str(char *inStr, short len){
  char *outputStr = malloc( (len + 1) * sizeof(char)); // + 1 for '/0' char at end
  int i = 0;
  while ( i <= len){
    outputStr[i] = inStr[i];
    i++;
  }
  outputStr[len + 1] = '\0'; // sets last byte to null terminator
  return outputStr;
}

char **tokenizer(char *str){
  int numWords = count_words(str);// the number of words going to be tokenized from string
  char **tokens == malloc( (numWords + 1) * sizeof(char *)); // allocates memory to tokens
  char *wordstart = word_start(str);
  char *wordend = word_terminator(str);

  int i;
  for(i = 0; i < numWords; i++){
    tokens[i] = copy_str(wordstart, wordend - wordstart);
    wordstart = word_start(wordend);
    wordend = word_terminator(wordstart);
  }
  tokens[i] = NULL;
  return tokens;
}






      
  
  
