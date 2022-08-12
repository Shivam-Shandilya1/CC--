/*Author: Shivam Shandilya */
/*Link Section */
#include <stdio.h>
#include <stdlib.h>
/*Global Decalaration Section */
void MinNMax(int *arr,int len,int *minin,int *maxin,int countmin,int countmax)
{
   int min = *(arr),max= *(arr);

   for(int i=0;i<len;i++)
   {
       if(*(arr+i)<min)
       {
           min=*(arr+i);

       }
       if(*(arr+i)>max)
       {
           max=*(arr+i);

       }
    }
    for(int k=0;k<len;k++)
    {
        if(*(arr+k)==min)
       {
           *(minin+countmin)=k;
           countmin ++;

       }
       if(*(arr+k)==max)
       {
           *(maxin+countmax)=k;
           countmax ++;
       }
    }


    printf("\n");
    printf("Max: %d occurs at index: ",max);
    for(int j=0;j<countmax;j++)
    {
        printf("%d ",*(maxin+j));
    }
    printf("\nMin: %d occurs at index: % \n",min);
      for(int j=0;j<countmin;j++)
    {
        printf("%d ",*(minin+j));
    }
}
/* main() function section */
int main()
{
int len;
int countmin=0,countmax=0;
int *arr,*minin,*maxin;
printf("Enter the count of Numbers: ");
scanf("%d",&len);
minin=(int*)malloc(len*sizeof(int));
maxin=(int*)malloc(len*sizeof(int));
arr=(int*)malloc(len*sizeof(int));
printf("Enter %d numbers: ",len);
for(int i=0;i<len;i++)
{
    scanf("%d",(arr+i));
}
for(int i=0;i<len;i++)
{
    printf("%d ",*(arr+i));
}
MinNMax(arr,len,minin,maxin,countmin,countmax);

return 0;
}