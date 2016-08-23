//sum(x) = fib(x+2) - 1
//sum from m+1 to n --> sum(n) - sum(m) = fib(n+2) - fib(m+2)
//sum from m to n-->sum(n)-sum(m-1)=fib(n+2)-fib(m+1)
#include <cstdio>

void multiply(long long int f[2][2], long long int m[2][2])
{
    long long int x = f[0][0] * m[0][0] + f[0][1] * m[1][0];
    long long int y = f[0][0] * m[0][1] + f[0][1] * m[1][1];
    long long int z = f[1][0] * m[0][0] + f[1][1] * m[1][0];
    long long int w = f[1][0] * m[0][1] + f[1][1] * m[1][1];
    f[0][0] = x % 1000000007;
    f[0][1] = y % 1000000007;
    f[1][0] = z % 1000000007;
    f[1][1] = w % 1000000007;
}

void power(long long int f[2][2],int n)
{
    if(n == 0 || n == 1) return;
    power(f,n/2);
    multiply(f,f);
    long long int m[2][2] = {{1,1},{1,0}};
    if(n % 2 == 1) multiply(f,m);
}

long long int fib(int n)
{
    long long int f[2][2] = {{1,1},{1,0}}; //as final result can be big
    if(n == 0) return 0;
    power(f,n);
    return f[0][1];
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        long long int ans = fib(n+2) - fib(m+1);  
        //Reason of following:
        /*
        Though given n<=m .But you are taking mod with 10^9+7;
        So there might be a problem of a negative mod.Take this case ,
        suppose (N!)=(10^9+6) and (M)!=(10^9)+8, (M!)%mod=1 and (N!)%mod=(10^9)+6; 
        so here (M!)-(N!) <0
        DOESN'T MAKE SENSE WE ARE SUBTRACTING THEN TAKING MOD!!!
        */
        ans = ans % 1000000007;
        if(ans < 0 ) ans = ans + 1000000007;     
        printf("%lli\n",ans);  
    }
}