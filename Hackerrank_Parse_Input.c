#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
        
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
