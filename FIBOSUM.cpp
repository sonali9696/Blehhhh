//too large array
#include <cstdio>
#include <cstring>
long long int fib[1000000000];

void fibo(int m)
{
    for(int i=2; i<=m; i++) 
    {
        if(fib [i] == -1) fib[i] = fib[i-1] + fib[i-2];
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    memset(fib,-1,sizeof(fib));
    fib[0] = 0;
    fib[1] = 1;
    while(T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);//0 3
        long long int sum ;
        if(fib[n] == -1) fibo(n);
        sum = fib[n]; //0
        int begin = n+1; //1
        if(n == 0)
        {
            sum = 1; //f[0] + f[1]; 1
            begin = 2;
        }
        for(int i=begin; i<=m; i++)
        {
             fib[i] = fib[i-1] + fib[i-2];
             sum += fib[i];
        } 
        printf("%lli\n", (sum % 1000000007) );
    }
}