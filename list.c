#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
 int value;
 struct Node* next;
}node;

node *createList(int firstval){
  node *newlist = malloc(sizeof(node));
  newlist->next=NULL;
  newlist->value =firstval;

  return newlist;
}
void addVal(node* list,int val){
  
  node *new =malloc(sizeof(node));
  new->next=NULL;
  new->value =val;
  while(list->next!=NULL){
    list = list->next;
  }
  list->next = new;

}
void removeAtIndex(int index,node* list){
  node* afternode;
  node *buffer = list;
  for(int i = 1;i<index;i++){
    buffer =buffer->next;
    if(buffer->next == NULL){
      printf("system exception: list has reached the end before index");
      return;
    }
  }
  if(buffer->next->next == NULL){
    buffer->next =NULL;
    return;
  }

  afternode = buffer->next->next;
  free(buffer->next);

  buffer->next=afternode;

}


void makeRound(node*list){
  node *lastnode =list;
  while(lastnode->next !=NULL){
    lastnode =lastnode->next;
  }
  lastnode->next=list;
}

void printroundlist(node*list,int toBePrinted){
  node *buffer =list;
  for(int i = 0 ;i<toBePrinted;i++){
    printf("%d. element = %d\n",i,buffer->value);
    buffer =buffer->next;
  }
}

void appendnodeNthindex(node* list, size_t n,int val){
  node* buffer = list;
  node *nextnode= buffer->next;
  for(int i = 1;i<n;i++){
      buffer = buffer->next;
      nextnode = nextnode->next;
      if(buffer == NULL){
        printf("System exception there is no more next node to add, pointer reached to end");
        return ;
      }
  }
  node *newnode = createList(val);
  buffer->next =newnode;
  newnode->next =nextnode;
}

void printlist(node *list){
  node *buffer = list;
  int i = 0; 
  if(buffer == NULL) return;
  
  while(buffer !=NULL){
    printf("%d. eleman = %d\n",i,buffer->value);
    buffer =buffer->next;
    i++;
  }
}

//© burak canbul
//homework 210229006
size_t getlength(node* list){//lenghtList();
  size_t i =0;
  while(list !=NULL){
    i++;
    list = list->next;
  }
  return i;
}
void printReverse(node* list){//revPrintList();
  size_t length = getlength(list);
  node *val =list;
  for(int j = 0;j<length;j++){
    for(int i=length;i>0;i--){
      val= val->next;
    }
    printf("element = %d",val);
    val =list;
  }
}
void deleteAllNodes(node*list){ //deleteAllNodes();
  size_t length = getlength(list);
  for(int i = 0 ;i<length;i++){
    free(list);
    list = list->next;
  } 
  free(list);
}

int main(){
  node *list = createList(6);
  srand(time(NULL));
  for(int i=0;i<15;i++){
    addVal(list,rand()%55);
  }
  printlist(list);
  removeAtIndex(8,list);
  printf("\n\nreverseprinting\n\n");
  printReverse(list);//revPrintlist();
  printf("\nafterremove\n");
  printlist(list);
  printf("\n%d elements found",getlength(list));
  appendnodeNthindex(list,8,585);
  printf("\n\nafter append\n\n");
  printlist(list);
  
  
  printf("\nafterrounding\n\n");
  printlist(list);
    //  makeRound(list);
    // printroundlist(list,36);

  deleteAllNodes(list);

  system("pause");
  return 0;
}