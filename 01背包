#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int M =13010;
int f[M];
int v[M],w[M];
int n,m;
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		memset(f,0,sizeof(f));
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		scanf("%d%d",v+i,w+i);
		
	for(int i=1;i<=n;i++)
	for(int j=m;j>=v[i];j--)
		f[j]=max(f[j],f[j-v[i]]+w[i]);	
		
		printf("%d\n",f[m]);
	}

	return 0;
}
