/*
 * implement logic to replace spaces with %20 inplace
 * the input string is long enough to hold %20 for all
 * spaces. true length of string is also given
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void replaceSpaces(char s[], int len)
{
   assert(s && len);
   char *p = &s[0];
   int i = 0, spaces = 0;
   
   // count number of spaces to calculate new len
   while (i < len) {
      if (s[i] == ' ') spaces++;
      i++;
   }
   
   // space already occupy 1 size
   // we need 3 size for %20
   // substract existing 1 space from 3 to get
   // space x 2
   int newlen = len + spaces * 2;
   s[newlen] = '\0';
   p = &s[newlen - 1];     // go to the last position just before end null char
   i = len - 1;
   while (i >= 0){
      if (s[i] == ' ') {
         *p = '%'; p--;
         *p = '0'; p--;
         *p = '2'; p--;
      }
      else {
         *p = s[i];
         p--;
      }
      i--;
   }
}

int main()
{
   char s[] = "Mr John Smith      ";   // input string
   int len = 13;                       // true length of string
   
   replaceSpaces(s, len);
   printf("modified string is: %s\n", s);

   return 0;
}

