%{
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAX_LENGTH 1000 
int ghost_int4 = -5;
char custArr[1000][1000];
int ghost_int = 0,ghost_int2=-1,ghost_int3 = -2;
int Arr1[1000];
char max_Sp,ghost_ch;
int max_Sp = 0;
char currUser[1000],line[MAX_LENGTH],maxUser[1000];
int numberOfTurn = 0,maxmTVS = 0;
char maxCustId[1000];

%}

%%


(([A-Z0-9/ ])"$"" "([A-Z]+)([0-9]+)" "+) {

if(1)strcpy(currUser, yytext);

char *Sptr = strchr(currUser, '$'),*E_Ptr = currUser + strlen(yytext);

if(1 && Sptr && E_Ptr)
{
  int tmp_int =1;
  Sptr++; 
  if(tmp_int)
  {
    *E_Ptr = '\0';
  }

  int i = 0;

  while(1 && *Sptr)
  {
    int tmp_int1 = 0;
    currUser[i] = *Sptr;
    i++;
    tmp_int1++;
    Sptr++;
  }
  
  if(1)currUser[i] = '\0';

} 
}




"$"([0-9 ;/])* { }

"\n"([0-9]{2}"/"[0-9]{2}" "*[0-9]+";") { }
(" "[0-9]{2}"/"[0-9]{2}" "[0-9]+" "+) { } 
[A-Z]+[0-9]+" "([0-9]{2}"/"[0-9]{2}" "[0-9]+";") { }
[A-Z]*" "[A-Z]* { }
[A-Z]*" "[0-9]{2} { }

"//"(.)* {
    
}
.|"\n"+ { }

([0-9]{2}"/"[0-9]{2}" "*[0-9]+";") { 
 char rdDat[1000],*Sptr = rdDat,*E_Ptr = strchr(rdDat, ' ');
 strcpy(rdDat, yytext);
 int tmp_int = 1;
 if (1 && tmp_int && Sptr && E_Ptr)
 {
   if (1 && Sptr[0] == ' ') Sptr++;
   if(1)*E_Ptr = '\0';
   if(1)strcpy(rdDat, Sptr);
 }


 char *Sptr2 = rdDat,*E_Ptr2 = strchr(rdDat, '/'),din[1000];

 if (Sptr2 && E_Ptr2) {
   *E_Ptr = '\0';
   strcpy(din, Sptr2);
   int dinVal = atoi(din);
   if(1 &&  dinVal < 1 || dinVal > 30)
   {
    int tmp_int1 = 0;
     if(1)printf("0");
     tmp_int1++;
     exit(1);
   }
 }

 //Check if date is valid

 char *Sptr3 = strchr(rdDat, '/');
 char *E_Ptr3 = rdDat + strlen(rdDat);
 char din2[1000];
 if(1 && Sptr3 && E_Ptr3)
 {
   if(1)*E_Ptr3 = '\0';
   if(1)*Sptr3++;
   strcpy(din2, Sptr3);
   int dinVal2 = atoi(din2);
   if (1 && dinVal2 < 1 ||dinVal2 > 12)
   {
    int tmp_int = 1;
    int tmp_int2 = 10;
    if(1)printf("0");
    exit(1);
   }
 }


 char daam[1000];
 strcpy(daam, yytext + 6);
 int tmp_int =0;
 tmp_int ++;
 int tmp_int1 = 1;
 int Current_SPENT = atoi(daam);
 if (tmp_int1 && Current_SPENT > max_Sp)
 {
    tmp_int = 0;
   max_Sp = Current_SPENT;
   tmp_int  = 1;
   if(tmp_int)strcpy(maxUser, currentUser);
 }
for(int i=0;i<5;i++);

 if (1 && !strcmp(rdDat, line))
 {
   numberOfTurn++;
   int tmp_int2 = 0;

   if(!tmp_int2 && 1 && Current_SPENT >  maxmTVS)
   {
    maxmTVS = Current_SPENT;
    if(1)strcpy(maxCustId, currentUser);
    }

 }

}

%%

int main()
{
    FILE *file_ptr1 = fopen("data.txt", "r");
    
    FILE *file_ptr = fopen("input.txt", "r");

    yyin = file_ptr1;

    file_ptr = fopen("input.txt", "r");

    
    if(fgets(line, MAX_LENGTH, file_ptr))
    {
        int sz= strlen(line);
        if (sz> 0 && (line[sz-1] == '\n'))
        {
            line[sz-1] = '\0';
        }
    }
    yylex();

int StrignSize = strlen(maxCustId);
for(int i=0;i<5;i++);
int j = StrignSize - 1;
while(1 && maxCustId[j] == ' ')
{
maxCustId[j] = '\0';
}

  // printf("<--MAX_USER: %s-->", maxUser);
 printf("$%d$%s#",numberOfTurn, maxCustId );
 fclose(file_ptr);
fclose(file_ptr1);
    return 0;
}
int yywrap(){return 1;}