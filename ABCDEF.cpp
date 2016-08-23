//(ab + c)/d - e = f
//ab + c = de + df
#include <cstdio>
#include <algorithm>
using namespace std;

int lhs[1000000],lhsInd = 0;
int rhs[1000000],rhsInd = 0;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    //all possibilities of lhs: ab+c
    //rhs: de + df
    for(int i = 0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0; k<n; k++)
            {
                lhs[lhsInd++] = a[i]*a[j] + a[k]; //ab + c
                if(a[i] != 0) rhs[rhsInd++] = a[i]* ( a[j] + a[k] ); //d(e+f)
            }
        }
    }

    sort(lhs,lhs+lhsInd);
    sort(rhs,rhs+rhsInd);

    //for every distinct element of lhs, 
    //let no. of times it is repeated in lhs be a
    //let no. of times it is repeated in rhs be b
    //ans = a*b for that element
    int i=0,j=0,countLHS=0,countRHS=0;
    long long int ans=0;
    while(i<lhsInd)
    {
        countLHS = 1;
        countRHS = 0;
        int item = lhs[i];
        i++;
        while(lhs[i] == item && i != lhsInd)
        {
            countLHS++;
            i++;
        }
        while(rhs[j] < item ) j++; //means this element was not in lhs so discard
        while(rhs[j] == item && j != rhsInd)
        {
            countRHS++;
            j++;
        }
        ans += (countLHS*countRHS);
    }
    printf("%lli\n",ans);
}
