//Reverse Linklist

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
  int value;
  struct ListNode *next;
}Node;

void print(Node *head){
  Node *current = head;

  while(current != NULL){
    printf("%d\n", current->value);
    current = current->next;
  }

}

Node *insert(Node *head, int value){
  Node *newNode = malloc(sizeof(newNode));
  newNode->value = value;
  newNode->next = NULL;

  if(head == NULL){
    return newNode;
  }

  Node *current = head;

  while(current->next != NULL){
      current = current->next;
  }

  current->next = newNode; 
  
  return head;;
}

Node *reverse(Node *head){
  if(head == NULL){
    return head;
  }

  Node *prev = NULL;
  Node *current = head;
  Node *next = head->next;

  while(current != NULL){
    next = current->next;

    current->next = prev;
    
    prev = current;
    current = next;

  }

  return prev;
  
}

int main(int argc, char *argv[]){
  Node *head = malloc(sizeof(head));
  head = NULL;
  
  //head = insert(head, 10);
  //head = insert(head, 9);
  //head = insert(head, 8);
  //head = insert(head, 7);
  //head = insert(head, 6);
  print(head);
  head = reverse(head);
  print(head);

  return 0;
}

