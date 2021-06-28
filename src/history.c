#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history(){
  List *history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str){
  Item *item = malloc(sizeof(Item));
  Item *temp = list->root; // setting temp to the root of the list (if first  = NULL)

  item->str = str;
  item->next = NULL;
  int count = 0;

  if(list->root == NULL){
    item->id = count;
    list->root = item;
  }
  else{
    count = 1;
    while(temp->next != NULL){
      count++;
      temp = temp->next;
    }
    temp->next = item;
    item->id = count;
  }
}

  
