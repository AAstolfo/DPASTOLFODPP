#include<iostream>
using namespace std;
const int N =1e5+10;
int a[N];
int q[N]={0};
int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	scanf("%d",a+i);
	
	q[0]=-2e9;
	int len =0;//代表q数组里元素的个数 
	for(int i=0;i<n;i++)
	{
		int l=0,r=len;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(q[mid]<a[i])l=mid;//这里要严格递增，所以不能加等于号 
			else r=mid-1;
			printf("l=%d r=%d\n",l,r);
		}
		
		q[r+1]=a[i];
		len=max(len,r+1);	
	}
	
	cout<<len<<endl;
	return 0;
}
