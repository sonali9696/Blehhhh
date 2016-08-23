//STUCK AT MENTIONED PLACE

#include <cstdio>

int max(int a,int b)
{
	return (a>=b)?a:b;
}

int max(int a,int b,int c,int d,int e,int f)
{
	return max(a,max(b,max(c,max(d,max(e,f)))));
}

int maxSumQuery(int lsum[],int rsum[] ,int best_sum[] ,int total_sum[] ,int low,int high,
	int qlow,int qhigh,int pos)
{
	if(qlow == low && qhigh == high) return pos;

	int mid = (low+high)/2;
	if(qhigh <= mid) return maxSumQuery(lsum,rsum,best_sum,total_sum,low,mid,qlow,qhigh,2*pos+1);
	else if(qlow > mid) return maxSumQuery(lsum,rsum,best_sum,total_sum,mid+1,high,qlow,qhigh,2*pos+2);

	//some part of interval is in left and some in right subtree
	
	//STUCK HERE!!!!!!!!!!!!!!!1

	int ans1 = maxSumQuery(lsum,rsum,best_sum,total_sum,low,mid,qlow,mid,2*pos+1);
	int ans2 = maxSumQuery(lsum,rsum,best_sum,total_sum,mid+1,high,mid+1,qhigh,2*pos+1);
	int result = max(ans1,ans2,)
}	

void construct_seg_tree(int a[],int low, int high, int lsum[], int rsum[],
			int best_sum[],int total_sum,int pos) //pos=pos of node
{
	if(low == high)	//leaf
	{
		lsum[pos] = rsum[pos] = best_sum[pos] = total_sum[pos] = a[low];
		return;
	}
	int mid = (low+high)/2;
	construct_seg_tree(a,low,mid,lsum,rsum,best_sum,total_sum,2*pos+1);
	construct_seg_tree(a,mid+1,high,lsum,rsum,best_sum,total_sum,2*pos+2);
	int left = 2*pos + 1, right = 2*pos+2;
	total_sum[pos] = total_sum[left] + total_sum[right];
	lsum[pos] = max(lsum[left], lsum[right] + total_sum[left]);
	rsum[pos] = max(rsum[right], rsum[left] + total_sum[right]);
	best_sum[pos] = max(
		lsum[pos],rsum[pos],best_sum[left], best_sum[right],rsum[left] + lsum[right], total_sum); 
}

int seg_size(int n)
{
	if( !(x & (x-1)) ) //n>=1 given so can't be zero
	{
		return (n << 1 - 1);
	}
	else
	{
		int s = 1;

		for(;s<n; s << 1); //now s will store nearest power of 2 > n
		
		return (s <<1 - 1); //this value can be max 4*N this is how global array size can be determined
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int size = seg_size(n);
	int lsum[size];
	int rsum[size];
	int best_sum[size];
	int total_sum[size];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	construct_seg_tree(a,0,n-1,lsum,rsum,best_sum,total_sum,0);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int pos = maxSumQuery(lsum,rsum,best_sum,total_sum,0,n-1,x,y,0);
		int ans = best_sum[pos];
		printf("%d\n",ans);
	}
}
