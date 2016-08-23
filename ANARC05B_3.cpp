//using sum arrays

#include <cstdio>


int find_equal_positions(int equalLocs_i[],int equalLocs_j[], int max, int pos, int a[], int m, int b[], int n)
{
        int i=0,j=0,flag = 0;
        while(i<m)
        {
            if(b[j] == a[i]) 
            {
                equalLocs_i[pos++] = i;
                equalLocs_j[pos-1] = j;
                i++;
                j++;
                continue;
            }

            else if(b[j] < a[i] && flag != 1)
            {
                while(b[j] < a[i] && j<n) j++;
                if(j == n) 
                {
                    j--;
                    flag = 1; //no need to enter here anymore
                }
            }
            
            else if(b[j] > a[i]) 
            {
                while(a[i] < b[j] && i<m) i++;
            }      
            else i++; //like when flag = 1 but 2nd condition
        }
        return pos;
}

int main()
{
    int m,n;
    while(1)
    {
        scanf("%d",&m);
        if(m == 0) return 0;
        int a[m];
        for(int i=0; i<m; i++) scanf("%d",&a[i]);
        int n;
        scanf("%d",&n);
        int b[n];
        for(int i=0; i<n; i++) scanf("%d",&b[i]);

        //STEPS:
        //first find all the points when they are equal
        //then make the sum arrays
        //then take the greedy approach to choose appropriate sum

        int max;
        if(m >= n) max = m;
        else max = n;
        int equalLocs_i[max];
        int equalLocs_j[max]; 
        int pos = 0;

        pos = find_equal_positions(equalLocs_i,equalLocs_j,max,pos,a,m,b,n);

       //TRY BELOW: STEP 2 & 3 & TODO
       
       
        for(int i=0;i<pos;i++) printf("%d ",equalLocs_i[i]);
        printf("\n");
        for(int i=0;i<pos;i++) printf("%d ",equalLocs_j[i]);
        printf("\n");
        

        int sum1[m],s1=0, sum2[n],s2=0;
        int ind = 0,i=0;
        while(ind < pos)
        {
            if(i != equalLocs_i[ind])
            {
                sum1[s1] = 0;
                while(i != equalLocs_i[ind])
                {
                    sum1[s1] += a[i++];
                }
                s1++;
            }
            else sum1[s1++] = 0;
            sum1[s1] = a[i];
            s1++; i++;
            ind++;
            if(i == n) break;
        }        
        if(ind == pos && i < m)
        {
            int total = 0;
            while(i<m)
            {
                total += a[i++];
            }
            sum1[s1++] = total;
        }
        

        for(int i=0;i<s1;i++) printf("%d ",sum1[i]);
        printf("\n");

        ind = 0;
        int j=0;
        while(ind < pos)
        {
            if(j != equalLocs_j[ind])
            {
                sum2[s2] = 0;
                while(j != equalLocs_j[ind])
                {
                    sum2[s2] += b[j++];
                }
                s2++;
            }
            else sum2[s2++] = 0;
            printf("s2=%d\n",sum2[s2]);
            sum2[s2] = b[j];
            printf("s2=%d\n",sum2[s2]);
            s2++; j++;
            ind++;
            if(j == n) break;
        }        

        if(ind == pos && j < n)
        {
            int total = 0;
            while( j < n)
            {
                total += b[j++];
            }
            sum2[s2++] = total;
        }

        
        for(int i=0;i<s2;i++) printf("%d ",sum2[i]);
        printf("\n");
        

        i=0;j=0;
        long long int ans = 0;
        while(i<s1 && j<s2)
        {
            if(sum1[i] >= sum2[i]) ans += sum1[i];
            else ans += sum2[j];
            i++;
            j++;
        }

        printf("ans till now=%lli, i=%d, j=%d\n",ans,i,j);
        if(i == s1 && j < s2)
        {
            while(j < s2)
            {
                ans += sum2[j++];
            }
        }

        else if(i < s1 && j == s2)
        {
            while(i < s1)
            {
                ans += sum1[i++];
            }
        }

        printf("%lli\n",ans);

        //TODO: if one has reached end other has not?

    }
}