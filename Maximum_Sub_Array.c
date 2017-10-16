#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int add(int arr[],int i,int j)
{
    int sum = 0;
    while(i<=j)
    {
        sum = sum + arr[i];
        i++;
    }
    return sum;
}

void calcSums(int arr[],int size)
{
    int i = 0;
   long int randomSum = 0;
    long int contSum = 0;
    int j = size-1;
    int t;
    randomSum = arr[0];
    i = 1;
    while(i<size)
    {
        if( (randomSum + arr[i])>randomSum)
             randomSum = randomSum + arr[i];
        else if( arr[i] > randomSum)
            randomSum = arr[i];
        i++;
    }
    i =0;
    contSum = -99999;
    
    while(i<=j)
    {
         t = add(arr,i,j);
         if(t>contSum)
             contSum = t;
        if(arr[i] > arr[j])
            {
                j--;
            }
        else
            i++;
    }
    printf("%ld %ld\n",contSum,randomSum);
}

int main() {
    int N, cnt;
    int testCaseSize[100000];
    int **a = NULL;
    
    scanf("%d",&N) ;
    a  = (int**)malloc(N*sizeof(int*));
    for(int i=0;i<N;i++)
    {
        scanf("%d",&cnt);
        testCaseSize[i] = cnt;
        a[i] = (int*)malloc(cnt*sizeof(int));
        for(int j=0;j<cnt;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    for(int i=0;i<N;i++)
    {
        calcSums(a[i],testCaseSize[i]);
    }
    
    
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}


/*
6
1
1
6
-1 -2 -3 -4 -5 -6
2
1 -2
3
1 2 3
1
-10
6
1 -1 -1 -1 -1 5

1 1
-1 -1
1 1
6 6
-10 -10
5 6
===========================

2
4
1 2 3 4
2
-100 -1

10 10
-1 -1
*/