#include <stdio.h>
#include <stdlib.h>
#define N 20

int main() {
    int i;
    double vt[N];
    double* pVt = vt;
    for(i = 0; i < N; i++)
    {
        *pVt=1+rand()%100;
        printf("%f ", *pVt);
        pVt++;
    }
}
