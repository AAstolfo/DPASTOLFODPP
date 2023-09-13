#include<iostream>
using namespace std;
const int N =3010;
int a[N];
int f[N],g[N];
int t[N];
int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		g[i]=i;
		for(int j=1;j<=i;j++)
		if(a[i]>a[j])
		{
			if(f[j]+1>f[i])
			{
				f[i]=f[j]+1;
				g[i]=j;	
			}
		
		}
	}
	
	int res=0;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]>res)
		{
			res=f[i];
			k=i;
		}
	}
	
	
	
	cout<<res<<endl;
	
	for(int i=0,j=k;i<f[k];i++)
	{
		t[i]=a[j];
		j=g[j];
	}
	
	for(int i=f[k]-1;i>=0;i--)
	printf("%d ",t[i]);
	return 0;
}
