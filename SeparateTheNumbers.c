//https://www.hackerrank.com/challenges/separate-the-numbers/problem


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    long long int no;
    int len,maxDigits,q,j;
    bool found = false;
    
    scanf("%d",&q);
    for(int a0 = 0; a0 < q; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s",s);
        len = strlen(s);
        //printf("len: %d\n",len);
        maxDigits  = len/2;
        char *tmp = (char *)malloc(maxDigits * sizeof(char));
        char *tmp2 = (char *)malloc(len * sizeof(char));
        char *number = (char *)malloc(len * sizeof(char));
        
        for(j=1;j<=maxDigits;j++)
        {
                for( int i = 0;i<len;i++)
                {
                    tmp2[i]='\0';
                    number[i]='\0';
                }
            
                for(int i = 0;i<maxDigits;i++)
                tmp[i]='\0';
               strncpy(tmp,s,j);
               tmp[j]= '\0';
               //printf("tmp: %s\n",tmp);
               found = false;
               no = atoll(tmp);
               //printf("no: %d\n",no);
               while(strlen(tmp2)<len)
               {
                   sprintf(number,"%lld", no);
                   strcat(tmp2,number);
                   //printf("tmp2: %s\n",tmp2);
                   if(strstr(s,tmp2)== NULL)
                   {
                       //printf("A substring\n");
                       found = false;
                       break;
                   }
                   else
                   {
                       no++;
                       //printf("no from else: %d\n",no);
                       found = true;
                   }
               }
            if(found == true)
            {
                break;
            }
        }
        if(found == true)
        {
          printf("YES %s\n",tmp);
        }
        else
        {
            printf("NO\n");
        }
        // your code goes here
    }
    return 0;
}
