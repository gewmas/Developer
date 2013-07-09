//check array is the result of post-order traverse of bst
#include <iostream>

using namespace std;

bool checkPostOrder(int sequence[], int length){
  if(sequence == NULL || length <= 0) return false;

  int root = sequence[length-1];

  int i = 0;
  for(i = 0; i < length-1; ++i){
    if(sequence[i] > root) break;
  }

  int j = 0;
  for(j = i; j < length-1; ++j){
    if(sequence[j] < root) return false;
  }

  bool left = true;
  if(i > 0) left = checkPostOrder(sequence, i);

  bool right = true;
  if(i < length-1) right = checkPostOrder(sequence+i, length-i-1);

  return left && right;
  
}

int main(int argc, char *argv[]){
  int postOrder[] = {5, 7, 6, 9, 11, 10, 8};
  int postOrder2[] = {5, 7, 4, 9, 4, 10, 8};

  cout << sizeof(postOrder)/sizeof(postOrder[0]) << endl;
  //if(!postOrder)
  cout << checkPostOrder(postOrder2, sizeof(postOrder2)/sizeof(postOrder2[0])) << endl;

  return 0;
}
