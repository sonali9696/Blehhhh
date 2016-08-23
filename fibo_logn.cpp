//O(log n)
#include <cstdio>

void multiply(int F[2][2],int M[2][2])
{
    int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int f[2][2], int n)
{
    if(n == 0 || n == 1) return; //IMP!
    int m[2][2] = {{1,1},{1,0}};
    power(f,n/2);
    multiply(f,f);
    if(n % 2 != 0) multiply(f,m);
}

int fib(int n)
{
    int f[2][2] = { {1,1}, {1,0} };
    //f power n
    power(f,n);
    return f[0][1];
}

int main()
{
    int n = 9;
    printf("%d\n",fib(n));
}