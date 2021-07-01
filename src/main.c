#include <stdio.h>
#include <stdlib.h>
#include "history.c"
#include "tokenizer.c"
#define MAX_LENGTH 32

// Function Declarations
int strcmp(char *str1, char *str2);

int main(){
  List *history = init_history(); // initializes history list
  char **tokens;
  char str[MAX_LENGTH];
  char c;
  int i, index = 0;
  int IDNum;

  printf("\t WELCOME");
  printf("\n-------------------------------------------\n");
  printf("COMMANDS:\t \"q\" TO EXIT\n");
  printf("\t \"history\" TO VIEW HISTORY\n");
  printf("\t \"!\" TO PRINT INDIVIDUAL HISTORY\n");
  printf("ENTER A STRING TO BE TOKENIZED");
  while(strcmp(str,"q") != 0){
    printf("$\n");
    i = 0;
    while((c = getchar()) != '\n'){
	str[i] = c;
	i++;
    }
    str[i] = '\0';

    
    if(strcmp(str, "q") == 0){ // if user uses 'q' to exit
      goto done;
    }
    else if(strcmp(str, "history") == 0){
      print_history(history);
    }
    else if(str[0] == '!'){
      printf("ENTER ID NUMBER: ");
      scanf("%d\n", &IDNum);
      printf("%s", get_history(history, IDNum));
    }
    else{
      tokens = tokenizer(str);
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
    if (str1[i] == '\0'){
      return 0;
    }
    return str1[i] - str2[i];
  }
}

     
