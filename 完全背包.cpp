//第一重优化，去k循环
//第二重优化，转一维数组 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =1e5+10;
int n,m;
int v[N],w[N];
int f[N];                                                                                  
int main()
{
	while(cin>>m>>n)
	{
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		scanf("%d%d",w+i,v+i);
		
		for(int i=1;i<=n;i++)
		for(int j=v[i];j<=m;j++)
		{
		    f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
		
	   cout<<f[m]<<endl;
	}
	return 0;
}
