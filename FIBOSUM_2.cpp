//TLE
#include <cstdio>
#include <cstring>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n;
        scanf("%d %d",&m,&n);//0 3
        long long int sum ;
        int prev2 = 0, prev1 = 1,fib=1;
        for(int i=2; i<=m; i++) 
        {
            fib = prev1 + prev2;
            prev2 = prev1;
            prev1 = fib;
        }
        int begin = m+1;
        if(m == 0 || m == 1)
        {
            sum = 1;
            begin = 2;
        }
        else sum = fib;
        for(int i = begin; i<=n ;i++)
        {
            fib = prev1 + prev2;
            prev2 = prev1;
            prev1 = fib;
            sum += fib;
        }

        printf("%lli\n", (sum % 1000000007) );
    }
}
