//
//  main.c
//  PalindromeNumber
//
//  Created by Yuhua Mai on 8/4/13.
//  Copyright (c) 2013 Yuhua Mai. All rights reserved.
//

#include <stdio.h>

void checkPalindrome(int i){
    int result = 0;
    int temp = i;
    
    if (i < 0) {
        i = -i;
        temp = i;
    }
    
    while (temp > 0) {
        result = result*10 + temp%10;
        temp /= 10;
    }
    
    printf("result is %d\n", result);
    
    if (result == i) {
        printf("Palindrome!");
    } else {
        printf("Not Palindrome!");
    }
    
}

int main(int argc, const char * argv[])
{
    int i = -12321;
    
    checkPalindrome(i);
    
    // insert code here...
    //printf("Hello, World!\n");
    
    return 0;
}

