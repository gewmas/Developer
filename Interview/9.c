//find last but kth node
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode{
  int key;
  struct ListNode *next;
} Node;

Node *pushToBack(Node *current, int key){
  if(current == 0){
    Node *newNode = malloc(sizeof(newNode));
    newNode->key = key;
    newNode->next = 0;
    return newNode;
  }

  current->next = pushToBack(current->next, key);
  return current;
}

Node *findLastButKthNode(Node *root, int k){
  if(root == 0){
    assert(0);
    return 0;
  }

  Node *fast = root;
  Node *slow = root;
  int i = 0;

  for(i = 0; i < k; i++){
    fast = fast->next;
    if(fast == 0) return 0;
  }

  while(fast != 0){
    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}

void print(Node *current){
  if(current != 0){
    printf("%d", current->key);
    print(current->next);
  }
}

void clear(Node *current){
  if(current != 0){
    clear(current->next);
    free(current);
    current = 0;
  }
}

int main(int argc, char *argv[]){
  Node *root = malloc(sizeof(root));
  root = 0;
  int i = 0;

  for(i = 0; i < 10; i++)
    root = pushToBack(root, i);

  print(root);
  printf("\n");

  Node *lastButKthNode = findLastButKthNode(root, 4);
  if(lastButKthNode != 0)
    printf("The Node is %d.\n", lastButKthNode->key);

  clear(root);
  printf("%d", (int)root->next);
  //free(root);
  root = 0;
  printf("%d", (int)root);

  return 0;
}
