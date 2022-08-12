#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        for(int j=num;j>i;j--)
    {
        printf(" ");
    }
    for(int j=i;j>=0;j--)
    {
      printf("%d",j);
    }
    if(i>0)
    {
      for(int j=1;j<=i;j++)
    {
      printf("%d",j);
    }
    }
      
   printf("\n");
    }
   
return 0;
}