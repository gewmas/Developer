#include <stdio.h>

void findSum(int *myArray, int sum){
  int *head = myArray;
  int *tail = myArray;
  int targetSum = 0;
  

  while(*tail != '\0') tail++;
  tail--;

  while(head < tail){
    targetSum = *head + *tail;

    if(targetSum > sum) tail--;
    else if(targetSum < sum) head++;
    else{
      printf("Target sum %d satisfied with %d and %d", targetSum, *head, *tail);
      return;
    }
  }

  printf("No such sum exists!");
  return;
}

int main(int argc, char *argv[]){
  int data[10] = {1, 3, 4, 5, 6, 8, 9};
  int sum = 0;

  findSum(data, sum);

  return 0;
}
