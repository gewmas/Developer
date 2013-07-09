#include <stdio.h>
#include <stdlib.h>

char FirstNotRepeatingChar(char pString[20]){//char *pString){
  if(!pString) return 0;

  const int tableSize = 256;
  unsigned int hashTable[tableSize];
  unsigned int i = 0;

  for(i = 0; i < tableSize; ++i){
    hashTable[i] = 0;
  }

  char *pHashKey = pString;
  while(*pHashKey != '\0') hashTable[*(pHashKey++)]++;

  pHashKey = pString;
  while(*pHashKey != '\0'){
    if(hashTable[*pHashKey] == 1) return *pHashKey;

    pHashKey++;
  }

  return 0;
}

int main(int argc, char *argv[]){
  char *s = "abaccdeff";
  //  char s[20] = "abaccdeff";
  char result = ' ';
  
  result = FirstNotRepeatingChar(s);
  printf("%c", result);

  return 0;
}
