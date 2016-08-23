#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int a[] = {1,1,2,2,2,2,3,4};
    int *low = lower_bound(a,a+8,2);
    printf("%d\n",*low); //2 --> exact index where 2 starts
    //int *high = upper_bound(a,a+8,2);
    //printf("%d\n",*high);
    cout<<( upper_bound(a,a+8,2) - a );
}
