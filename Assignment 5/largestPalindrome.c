/*  Assignment 5
 *  Name: Evan Laia
 *  Partner's name: Cordan W.
 *  CS 1713 Summer 2015
 */

#include <stdio.h>
#include <string.h>

/*
`*  Checks whether the characters from position first to position last of the string str form a palindrome.
 *  If it is palindrome it returns 1.  Otherwise it returns 0.
 */
int isPalindrome(int first, int last, char* str)
{
    while (first <= last) { //if the string was an odd number of characters, you would check the middle value to itself
        if (str[first] != str[last]) {
            return 0;       //quickly exit because there's no chance it's a palindrome
        
        } else {
            first++;        //increment first and decrement last to see if it stays a palindrome
            last--;
        }
        
    }
    return 1;               //does not return 0, sfirst to last in the string is a palindrome
}

/*
`*  Find and print the largest palindrome found in the string str.  Uses isPalindrome as a helper function.
 */
void largestPalindrome(char* str)
{
    int i, j, k, l, p;
    int length;                               //to test if the identifed palindrome is the longest
    int longest = 0;                          //length of the longest palindrome

    for (i=0;i < strlen(str);i++) {           //outer for loop, only increments aftter j has reached the end of the string
        
        for (j = i + 1;j < strlen(str);j++) { //j = i + 1 to look for any palindrome greater than 1 character
            
            if (isPalindrome(i, j, str) == 1) {
                printf("Palindrome found at position %d through %d\n", i, j);
                length = (j - i) + 1;         //+1 because j - i would come up short by 1 character every time
                printf("The length of the palindrome is %d characters\n", length);
                
                if (length > longest) {       //need to save the positions of the largest palindrome
                    k = i;                    //start of the longest palindrome
                    l = j;                    //end of the longest palindrome
                    longest = length;
                
                }
            }
        }
    }
    printf("The longest palindrome is located from position %d through %d\n", k, l);
    printf("The longest palindrome is ");
    for(p = k; p<=l; p++){                    //print from k to l
        printf("%c", str[p]);                 //start to end of longest palindrome
    }
}
/*
`*  Do not modify this code.
 */
int main()
{
    int i = 0;
    /* you can change these strings to other test cases but please change them back before submitting your code */
    char *str1 = "ABCBACDCBAAB";
    char *str2 = "ABCBAHELLOHOWRACECARAREYOUIAMAIDOINEVERODDOREVENNGGOOD";

    /* test easy example */
    printf("Test String 1: %s\n",str1);
    largestPalindrome(str1);

    /* test hard example */
    printf("\n\nTest String 2: %s\n",str2);   //Added extra \n for formatting
    largestPalindrome(str2);
    
    return 0;
}