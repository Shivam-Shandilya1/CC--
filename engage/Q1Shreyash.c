#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char rollNo[10];
    float marks;
    int rank;
};

void sort(struct Student *record,int n)
{
     for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                if (record[i].marks < record[j].marks) 
                {
                    struct Student a = record[i];
                    record[i] = record[j];
                    record[j] = a;
                }
            }
        }
}

void rank(struct Student *record,int n){
    int cnt = 1;
    record[0].rank = cnt;
for(int i=1;i<n;i++)
{
    if(record[i].marks==record[i-1].marks)
    {
        record[i].rank = cnt;
    }else{
            cnt++;
            record[i].rank = cnt;
    }
}

}

void search(struct Student *record,int n,int r){
    for(int i=0;i<n;i++)
    {
        if(record[i].rank==r)
        {
            printf("%s\n",record[i].rollNo);
        }
    }
}

int main()
{
    FILE *fp;
    int N,r;
    char ch;
    struct Student *result;

    fp = fopen("input.dat", "r");
    if (!fp) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
 
    // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(fp);
        
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);
    // Closing the file
    fclose(fp);

    sort(result,N);
    rank(result,N);
    scanf("%d",&r);
    search(result,N,r);
    return 0;
}