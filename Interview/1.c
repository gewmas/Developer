#include <stdio.h>
#include <stdlib.h>

typedef struct BSTreeNode{
  int nValue;
  struct BSTreeNode *pLeft;
  struct BSTreeNode *pRight;
} Node;
//typedef struct BSTreeNode Node;

Node * insert(Node *root, int value){
  Node *newNode = malloc(sizeof(newNode));
  newNode->nValue = value;
  newNode->pLeft = NULL;
  newNode->pRight = NULL;

  Node *current = root;
  Node *prev = NULL;

  if(root == NULL){
    return newNode;
  } else {
    while(current != NULL){
      prev = current;
      if(value < current->nValue){
	current = current->pLeft;
      }else if(value > current->nValue){
	current = current->pRight;
      }
    }

    if(value < prev->nValue){
      prev->pLeft = newNode;
    }else if(value > prev->nValue){
      prev->pRight = newNode;
    }

  }

  return root;

}

void print(Node *current){
  if(current != NULL){
    print(current->pLeft);
    printf("%d", current->nValue);
    print(current->pRight);
  }
}

typedef enum _ChangeDirection {LEFT, RIGHT} ChangeDirection;

Node *postOrderChange(Node *current, Node *prev, ChangeDirection myDirection){
  if(current != NULL){
    current->pLeft = postOrderChange(current->pLeft, current, LEFT);
    current->pRight = postOrderChange(current->pRight, current, RIGHT);
    
    Node *newHead = current;
    if(myDirection == LEFT){
      while(newHead->pRight != NULL) newHead = newHead->pRight;
      newHead->pRight = prev;
    }else{
      while(newHead->pLeft != NULL) newHead = newHead->pLeft;
      newHead->pLeft = prev;
    }
    
    return newHead;
  }
}

int main(int argc, char *argvf[]){
  Node *root = malloc(sizeof(root));
  root = NULL;

  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 4);
  root = insert(root, 2);
  root = insert(root, 6);
  root = insert(root, 8);
  root = insert(root, 9);
  root = insert(root, 10);
  root = insert(root, 1);
  print(root);
  printf("\n");
  
  root = postOrderChange(root, NULL, LEFT);
  
  Node *current = root;
  while(current != NULL){
    printf("%d", current->nValue);
    current = current->pLeft;
  }

  return 0;
}
