#include <stdio.h>

int main() {
    int sum = 1;
    int n = 100;
    double result = (double)(1-((double)pow(-1,n)/(double)pow(2,n)))/(double)(1-(-0.5));
    printf("result: %f",result);
    return 0;
}
