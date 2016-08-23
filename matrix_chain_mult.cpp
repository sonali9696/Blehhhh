#include <cstdio>
#include <limits.h>

void matrix_chain(int p[], int n)
{
    int dp[n][n];//4 matrices but made for 5 for simplicity i.e. one extra row and col

    // P(i-1) * Pk * Pj for i,k & k+1,j
    for(int i=1; i< n;i++) dp[i][i] = 0;
    for(int L=1; L< n ; L++)
    {
        for(int i = 1; i <= n - L; i++ )
        {
            int j = i+L;
            int q = INT_MAX;
            for(int k=i; k<=j ;k++)
            {
                int calc = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if(q > calc) q = calc; 
            }
            dp[i][j] = q; 
        }
    }    

    printf("%d\n",dp[1][n-1]);
}

int main()
{
    int p[] = {1,2,3,4}; //dimensions
    matrix_chain(p,4);
}