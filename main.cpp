#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(float *a, float *b)
{
    float c;
    c=*a;
    *a=*b;
    *b=c;
}
void toptriangle(float **a, int n, int d,int *inv)
{
    int i,j;
    float p;
    if(d<n-1)
    {
        if(a[d][d]==0)
        {
            i=d;
            while(a[i][d]==0)
            {
                i++;
                (*inv)++;
            }
             for(j=0;j<n;j++)
            {
                swap(&a[d][j],&a[i][j]);
            }
        }
        for(i=d+1;i<n;i++)
        {
            p=a[i][d]/a[d][d];
            for(j=d;j<n;j++)
            {
                a[i][j]=a[i][j]-a[d][j]*p;
            }
        }
        toptriangle(a,n,d+1,inv);
    }
}
void bottomtriangle(float **a,int n)
{
    int i,j;
    float p;
    if(n>1)
    {
        for(i=n-2;i>=0;i--)
        {
            p=a[i][n-1]/a[n-1][n-1];
            for(j=n-1;j>=0;j--)
            {
                a[i][j]=a[i][j]-a[n-1][j]*p;

            }
        }
        bottomtriangle(a,n-1);
    }
}
float det(float **a, int n)
{
    int i,inv=0;
    float d=1;
    toptriangle(a,n,0,&inv);
    bottomtriangle(a,n);
    for(i=0;i<n;i++)
    {
        d=d*a[i][i];
    }
    if(inv%2==0)
    {
        return d;
    }
    else
    {
        return -d;
    }
}
int main()
{
    int n,i,j;
    float **a;
    printf("Введите порядок вашей матрицы\n");
    scanf("%d", &n);
    a=(float**) malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
    {
        a[i]=(float*) malloc(n*sizeof(float));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Введите значение a[%d][%d]\n", i,j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("Дискриминант =%f",det(a,n));
    return 0;
}
