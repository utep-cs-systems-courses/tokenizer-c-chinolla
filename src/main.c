#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
#define MAX_LENGTH 32

// Function Declarations
int strcmp(char *str1, char *str2);
int str_to_num(char *str);

int main(){
  List *history = init_history(); // initializes history list
  char **tokens;
  char str[MAX_LENGTH];
  char c;
  int i, index = 0;

  printf("\t WELCOME");
  printf("\n-------------------------------------------\n");
  printf("COMMANDS: \"\tq\" TO EXIT\n");
  printf("\"history\" TO VIEW HISTORY\n");
  printf("\"!n\" TO PRINT INDIVIDUAL HISTORY\n");
  printf("ENTER A STRING TO BE TOKENIZED\n");
  while(strcmp(str,"q") != 0){
    printf("\n> ");
    i = 0;
    while((c = getchar()) != '\n'){
	str[i] = c;
	i++;
    }
    str[i] = '\0';

    
    if(strcmp(str, "q") == 0){ // if user uses 'q' to exit
      goto done;
    }
    else if(strcmp("history",str) == 0){
      print_history(history);
    }
    else if(str[0] == '!'){
      index = str_to_num(str + 1);
      printf("%s", get_history(history, index));
    }
    else{
      tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);
      add_history(history, copy_str(str, i));
    }
  }
 done:
  free_history(history);
  return 0;
}


int strcmp(char *str1, char *str2){
  int i;
  for(i = 0; str1[i] == str2[i]; i++){
    if (str1[i] == '\0') return 0;
  }
  return str1[i] - str2[i];
}


     
int str_to_num(char *str){
  int number = 0;
  int i = 0;
  while(str[i] != '\0'){
    number = number * 10;
    number = number + (str[i] - '0');
    i++;
  }
  return number;
}
