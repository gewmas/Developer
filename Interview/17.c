//STRING to INT

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

double stringToInteger(char s[256]){
  int positive = 1;
  double result = 0;
  int index = 0;
  int digit = 0;

  if(!isdigit(s[0])){
    if(s[1] == '\0') assert(0);

    index++;

    if(s[0] == '+') positive = 1;
    else if(s[0] == '-') positive = -1;
    else{
      printf("Wrong Input");
      assert(0);
    }
  }

  while(s[index] != '\0'){
    if(!isdigit(s[index])) assert(0);
    
    digit = s[index] - '0';
    result = result*10 + digit;
    
    index++;
  }

  result *= positive;
  
  return result;
}

int main(int argc, char *argv[]){
  char s[256] = "-";
  double result = 0;
  
  result = stringToInteger(s);
  printf("%.0f", result);

  return 0;
}
