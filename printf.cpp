#include <cstdio>

int main()
{
    int n = 10;
    printf("%d\n",(printf("%d\n",n)));
    int a;
    printf("%d\n", (scanf("%d",&a))); 
}

/*output is:
10
3
Reason:10 is for obvious reason. 3 because - 2digit + '\n' of inner printf
 printf("%d\n",(printf("%d",n)));
 would have output:
 102 
*/