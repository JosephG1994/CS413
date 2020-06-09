// C++ recursive program for checking if a number is palindrome. 
#include <stdio.h> 
  
// Function for one digit numbers
int oneDigit(int num) 
{ 
    return (num >= 0 && num < 10); 
} 
   
// Recursive function for identifying palindromes.
bool Palindrome(int num, int* dupNum) 
{ 
    // Base case
    if (oneDigit(num)) 
        return (num == (*dupNum) % 10); 
  
    if (!Palindrome(num/10, dupNum)) 
        return false; 
  
    *dupNum /= 10; 
    return (num % 10 == (*dupNum) % 10); 
} 
  
// Function uses recursive function Palindrome() to identify palindromes.
int isPalindrome(int num) 
{  
    if (num < 0) 
       num = -num; 
   
    int *dupNum = new int(num);
    return Palindrome(num, dupNum); 
} 
  
// Test cases that print results
int main() 
{ 
    int n = 0; 
    isPalindrome(n)? printf("Yes\n"): printf("No\n"); 
  
    n = 1234554321; 
    isPalindrome(n)? printf("Yes\n"): printf("No\n"); 
  
    n = 123454321; 
    isPalindrome(n)? printf("Yes\n"): printf("No\n"); 
  
    n = 1221; 
    isPalindrome(n)? printf("Yes\n"): printf("No\n"); 

    n = 1234;
    isPalindrome(n)? printf("Yes\n"): printf("No\n");

    n = 7676;
    isPalindrome(n)? printf("Yes\n"): printf("No\n");

    n = -121;
    isPalindrome(n)? printf("Yes\n"): printf("No\n");

    n = -456;
    isPalindrome(n)? printf("Yes\n"): printf("No\n");
    return 0;
} 