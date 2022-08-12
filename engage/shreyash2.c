#include <stdio.h>
#include<math.h>
#include<stdlib.h>

//INTITALIZING STRUCT WITH M AS ROW , N AS COLUMN AND ARR AS 2D ARRAY
struct Matrix 
{
    int m,n;
    int **arr;
};

//GENERATING 2D ARRAY
struct Matrix getMatrix(struct Matrix a)
{
    int k;
    for(int i = 0;i<a.m;i++)
    {
        for(int j = 0;j<a.n;j++)
        {
            printf("Enter value for disp[%d][%d]:", i, j);
            scanf("%d", &k);
            a.arr[i][j] = k;
        }
    }
    return a;
}
//PRINTING MATRIX
void printMatrix(struct Matrix b)
{
    for(int i = 0;i<b.m;i++)
    {
        for(int j = 0;j<b.n;j++)
        {
            printf("%d ",b.arr[i][j]);
        }
        printf("\n");
    }
}

//CALCULATING FINAL MATRIX A
struct Matrix MulMatrix(struct Matrix a,struct Matrix b,struct Matrix c)
{
    struct Matrix mul; // RESULT MATRIX
    //PRINTING ERROR IF NOT MULTIPLIED
    if(a.n != b.m)
    {
        printf("Error: Can't be MultiPlied");
        return mul;
    }
    int mult[a.m][b.n];
    //MULTIPLYING
    printf("multiply of the matrix=\n");    
    for(int i=0;i<a.m;i++)    
    {    
        for(int j=0;j<b.n;j++)    
        {    
            mult[i][j]=0;    
            for(int k=0;k<b.n;k++)    
            {    
                mult[i][j]+=a.arr[i][k]*b.arr[k][j];    
            }    
        }    
    } 

//ADDING
    printf("Addition of the matrix=\n");

    for(int i = 0;i<a.m;i++)
    {
        for(int j=0;j<a.n;j++)
        {
            mult[i][j]+=c.arr[i][j];
        }
    }

    for(int i=0;i<a.m;i++)    
    {    
        for(int j=0;j<b.n;j++)    
        {        
            for(int k=0;k<b.n;k++)    
            {    
               mul.arr[i][j] = mult[i][j];    
            }    
        }    
    } 
    return mul; 
}



int main()
{
    struct Matrix a,b,C,x,y;
    int r,c;
    printf("No of Rows:");
    scanf("%d",&r);
    printf("No of Columns:");
    scanf("%d",&c);
    a.m = r;
    a.n = c;
    a.arr = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        a.arr[i] = (int*)malloc(c * sizeof(int));
    }
    getMatrix(a);
    printMatrix(a);
    printf("No of Rows:");
    scanf("%d",&r);
    printf("No of Columns:");
    scanf("%d",&c);
    b.m = r;
    b.n = c;
    b.arr = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        b.arr[i] = (int*)malloc(c * sizeof(int));
    }
    getMatrix(b);
    printMatrix(b);
    printf("No of Rows:");
    scanf("%d",&r);
    printf("No of Columns:");
    scanf("%d",&c);
    C.m = r;
    C.n = c;
    C.arr = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        C.arr[i] = (int*)malloc(c * sizeof(int));
    }
    getMatrix(C);
    printMatrix(C);
    x = MulMatrix(a,b,C);
    printf("Final Matrix A = ");
    printMatrix(x);
    return  0;
}