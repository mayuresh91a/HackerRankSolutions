#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int search(char** set,char* str,int n)
{
    int t= 0;
        
        while(t<n)
        {
            if(strcmp(set[t],str)==0)
                return 1;
            t++;
        }
    return 0;
}


char **substrings(char *inputString, int lenSubstring, int *result)
    
{
    printf("\nEntered substrings()");
    int len = strlen(inputString);
    char **finalSet = (char**)malloc((len - lenSubstring + 1 )*sizeof(char*));
    int cnt = 0;
    int i=0;
    char* sub =  (char*)malloc((lenSubstring+1)*sizeof(char));
    
    int nIter = len - lenSubstring + 1; //maximum unique strings possible 
    for(int k=0;k<nIter;k++)
    {
        int j = k;
        for(i = 0;i<lenSubstring;i++)   //create a substr
        {
            sub[i] = inputString[j];
            j++;
            
        }
        sub[i] = '\0';
        printf("\nSubstr = %s",sub);
        if(search(finalSet,sub,cnt) ==0) // not found, add to the set
        {
            finalSet[cnt] = (char*)malloc((lenSubstring+1)*sizeof(char)); 
            strcpy(finalSet[cnt],sub);
            printf("\nSubstr = %s added",sub);
            cnt++;
        }
        
    }
    for (i = 0; i < cnt-1; ++i)			//sort the final set
    {
        for (int j = i+1; j < cnt; ++j)
        {
            if (strcmp (finalSet[i], finalSet[j]) > 0)
            {
                strcpy (sub, finalSet[i]);
                strcpy (finalSet[i], finalSet[j]);
                strcpy (finalSet[j], sub);
            }
        }
    }
    
    *result = cnt;
    return finalSet;
}

int main(){
    int rVal = 0;
    char* S = (char *)malloc(10240 * sizeof(char));
    scanf("%s",S);
    
    char strings[100][4];
    
    char s[20];
    strcpy(s,"bcdeefaaa");
    
    char ** result = substrings(s,2,&rVal);
    printf("\n");
    for(int i = 0;i<rVal-1;i++)
    {
        printf("%s,",result[i]);
    }
    printf("%s\n",result[rVal-1]);   
    return 0;
}
