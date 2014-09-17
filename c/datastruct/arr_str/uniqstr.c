// algorithm to determine if string has unique characters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_CHAR 256

typedef enum {false, true} bool;

// assumption: string contains only ascii characters
// ascii char range 0 - 255 (128 - 255: extended ascii char)
// using additional datastructure
bool hasUniqueChars_additional_ds(const char *s)
{
   assert(s);
   
   // input string length > 256 (max chars),
   // its not a string with all unique chars
   int len = strlen(s);
   if (len > MAX_CHAR)
      return false;
   
   int char_count[MAX_CHAR] = {0};
   int i;
   while (*s != '\0') {
      i =  *s - '0';
      char_count[i]++;
      if (char_count[i] > 1)
         return false;
      s++;
   }
   
   return true;
}

// without using additional datastructure
// sort the string and compare current char
// with next char for uniqueness

int cmpchar(const void *c1, const void *c2)
{
   return (*(char *)c1 - *(char *)c2);
}

bool hasUniqueChars(char *s)
{
   assert(s);
   
   // input string length > 256 (max chars),
   // its not a string with all unique chars
   int len = strlen(s);
   if (len > MAX_CHAR)
      return false;
   
   qsort(s, len, sizeof(char), cmpchar);
   printf("sorted string: %s\n", s);
   while (*s != '\0') {
      if (*s == *(s+1)) return false;
      s++;
   }
   
   return true;
}

int main()
{
   //char s[] = "abcdefghiklmnopqr";
   char s[] = "hello how are you";
   bool b = hasUniqueChars(s);
   if (b)
      printf("String <%s> has all unique characters\n", s);
   else
      printf("String <%s> has duplicate characters\n", s);

   return 0;
}
