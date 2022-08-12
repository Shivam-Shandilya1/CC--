#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
     char s1[30] = "string 1";
     char s2[30] = "string 2: I’m using strncpy";
     /* this function has copied first 10 chars of s2 into s1*/
     strncpy(s1,s2, 12);
     printf("String s1 is: %s", s1);
     return 0;
}