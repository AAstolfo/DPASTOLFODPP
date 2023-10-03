//跟闫总写的不一样，但acwing过了，oj报tle，我怀疑是oj啥币 
//闫总也过不了，ojsb
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int count(int n,int x)
{
	if(!n)return 0;
	int len=0;
	int t=n;
		while(t)
		{
			t/=10;
			len++;
		}
	int cnt=0;
	for(int j=len-1-!x;j>=0;j--)//0不能做最高位 
	{
	 int m=pow(10,j);
	int l=n/m/10,r=n-(l*10+x)*m;
	if(!x)cnt+=(l-1)*m;
	else cnt+=l*m;
	if(l*10+x==n/m)cnt+=r+1;
	else if(l*10+x<n/m)cnt+=m;  
	}
	
	return cnt;
}
int  main()
{
	int n,m; 
	while(cin>>n>>m,n||m)
	{	
		if(n>m)
		swap(n,m);
		for(int i=0;i<10;i++)
			printf("%d ",count(m,i)-count(n-1,i));
		puts("");
	}
	return 0;
}
