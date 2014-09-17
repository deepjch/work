// check if one string is permutation of another
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef enum {false, true} bool;

int cmpchar(const void *c1, const void *c2)
{
   return *(char *)c1 - *(char *)c2;
}

bool isPermutationStrings(char *s1, char *s2)
{
   assert(s1 && s2);
   
   int len1 = strlen(s1);
   int len2 = strlen(s2);
   
   // strings not having similar lengths cannot
   // have same permutation
   if (len1 != len2) return false;
   
   // sort the strings
   qsort(s1, len1, sizeof(char), cmpchar);
   qsort(s2, len2, sizeof(char), cmpchar);

   while (*s1 != '\0') {
      if (*s1 != *s2) return false;
      s1++;
      s2++;
   }
   return true;
}

int main()
{
   char s1[] = "hello";
   char s2[] = "olleh";
   bool bret = isPermutationStrings(s1, s2);
   if (bret)
      printf("Strings s1<%s> and s2<%s> are of same permutation\n", s1, s2);
   else
      printf("Strings s1<%s> and s2<%s> are of different permutation\n", s1, s2);

   return 0;
}

