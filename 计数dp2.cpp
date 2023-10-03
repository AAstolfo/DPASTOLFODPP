//这是闫总写法就几把事过不了
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int power10(int i)
{
	int res=1;
	while(i--)res*=10;
	return res;
}
int get2(vector<int> num,int l,int r)
{
	if(l<r)return 0;//这句注意要加，防止边界情况 
	int ans=num[r];
	for(int i=r+1;i<=l;i++)
		ans+=num[i]*power10(i-r);
	
	return ans;
}
int get(vector<int> num,int l,int r)
{
	int res=0;
	for(int i=l;i>=r;i--)res=res*10+num[i];
	return res; 
}
int count(int n,int x)
{
	if(!n)return 0;
	vector<int> num;
	while(n)
	{
		num.push_back(n%10);
		n/=10;
	}
	
	n=num.size();
	
	int res=0;
	for(int i=n-1-!x;i>=0;i--)
	{
		if(i<n-1)
		{
			res+=get(num,n-1,i+1)*power10(i);
			if(!x)res-=power10(i);
		}
		if(num[i]==x)res+=get(num,i-1,0)+1;
		else if(num[i]>x)res+=power10(i);
	}
	
	return res;
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
