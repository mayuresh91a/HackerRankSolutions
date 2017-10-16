#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //char* str = (char*)malloc(1000*sizeof(char));
    string str,tmp;
    
    while(cin>>tmp)
    {
        str = str+tmp;
    }
    //cout<<str;
    
    int len = str.length();
    int i=0;
    int arr[26]={0};
    while(i<len)
    {
       if((int)str[i]>= (int)'a')
       {
           arr[(int)str[i]%(int)'a'] = 1;
       }
       else if((int)str[i]>= (int)'A')
       {
           arr[(int)str[i]%(int)'A'] = 1;
       }
        i++;
    }
    i=0;
    int product = 1;
    while(i<26)
    {
        product = product*arr[i];
        i++;
    }
    if(product ==0)
    {
       cout<<"not pangram"; 
    }
    else if(product == 1)
    {
        cout<<"pangram";
    }
    //while
    
    
    //int len =strlen()
    
    return 0;
}
