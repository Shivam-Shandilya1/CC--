#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{   
  int n,m,roll,marks,sum=0;
  printf("Enter number of students and subjects \n");
  scanf("%d %d",&n,&m);
 
for(int i=0;i<n;i++)
{
   printf("Enter Roll Number: ");
  scanf("%d", &roll);
  printf("ENTER MARKS OF %d SUBJECTS FOR ROLL %d: \n",m,roll);
  for(int j=0;j<m;j++)
  {
    scanf("%d",&marks);
    sum=sum+marks;
  }
  printf("Total Marks = %d",sum);
  if(sum>=360)printf("(FIRST DIVISION)");
  if(sum>=240&&sum<360)printf("(Second DIVISION)");
  if(sum<240)printf("(Fail)");
  sum=0;
}
    return 0;
}