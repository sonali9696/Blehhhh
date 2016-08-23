#include <cstdio>
#include <limits.h>

long long int dp[100][100];
long long int sum[100][100];

long long int minMatrixChainMult(int a[], int n)
{
    for(int i=0;i<n;i++) 
    {
        dp[i][i] = 0; //no smoke without mixing
        sum[i][i] = a[i];
    }
   
    for(int L=1;L<n;L++)
    {
        for(int i=0;i<n-L;i++)
        {
            int j = i+L;
            long long int q = INT_MAX;
            for(int k=i;k<j;k++)
            {
                int sum_ans = (sum[i][k] + sum[k+1][j]) % 100;
                int ans = dp[i][k] + dp[k+1][j] + sum[i][k] * sum[k+1][j];
                if(q>ans) 
                {
                    q = ans;
                    sum[i][j] = sum_ans;
                }
            }
            dp[i][j] = q;
        }
    }      

    return dp[0][n-1];
}

int main()
{
    int n;
    while(scanf("%d",&n) > 0)
    {
        int a[n];
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        long long int ans = minMatrixChainMult(a,n);
        printf("%lli\n",ans);
    }
}