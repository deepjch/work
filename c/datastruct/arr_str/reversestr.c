// reverse string inplace
#include <stdio.h>
#include <string.h>
#include <assert.h>

void reversestr(char *s)
{
   assert(s);
   
   int len = strlen(s);
   if (len <= 1) return;
   
   char *ps = s;             // start of string
   char *pe = (s + len - 1); // end of string excluding end '\0'
   char ch;                   // temp buffer to swap chars

   while (ps < pe) {
      ch = *ps;
      *ps = *pe;
      *pe = ch;
      ps++; pe--;
   }
}
int main()
{
   char s[] = "hello how are you";
   printf("before reversing the string: %s\n", s);
   reversestr(s);
   printf("after reversing the string: %s\n", s);
   return 0;
}

