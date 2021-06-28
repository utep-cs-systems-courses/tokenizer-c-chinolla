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


// return pointer to specific token(word) if found, if not, returns NUll
char *get_history(List *list, int id){
  Item *temp = list->root;
  while(temp != NULL){
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL; // returns null if no id is found
}


// traverses thru list printing out token id and string
void print_history(List *list){
  Item *temp = list->root;
  printf("\n");
  while(temp != NULL){
    printf("ID: %d String: %s \n", temp->id, temp->str);
    temp = temp->next;
  }
  printf("\n");
}

// frees history
void free_history(List *list){
  Item *temp;
  while(list->root != NULL){
    temp = list->root; //starts off at first node
    list->root = list->root->next; // moves root to the next node
    free(temp); // frees old root
  }
  free(list); // after all nodes are free, free the list
}


  
