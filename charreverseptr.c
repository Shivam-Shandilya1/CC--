/*Author: Shivam Shandilya */
/*Link Section */
#include <stdio.h>
#include <string.h>

/*Global Decalaration Section */
/* main() function section */
int main()
{
char string[30],result[30];
gets(string);
for(int i=0;i<strlen(string);i++)
{
  *(result+i)=*(string + (strlen(string)-1-i));
}
*(result+strlen(string))='\0';
puts(result);
return 0;
}