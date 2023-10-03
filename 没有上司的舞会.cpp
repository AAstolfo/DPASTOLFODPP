#include<iostream>
#include<cstring>
using namespace std;
const int N =6e3+10;
int happy[N];
int e[N],h[N],idx=0,ne[N];
bool has_dad[N];
int f[2][N];//已i为根，happy的值。0代表不选i，1代表选i
void dfs(int u)
{
	if(f[1][u])return;
	f[1][u]+=happy[u];
	
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		dfs(j);
		f[0][u]+=max(f[0][j],f[1][j]);
		
		f[1][u]+=f[0][j];
	}
 } 
void add(int a,int b)
{
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++)scanf("%d",happy+i);
	
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(b,a);
		has_dad[a]=true;
	}
	
	int root=0;
	for(int i=1;i<=n;i++)
		if(!has_dad[i])
		{
		 root=i;
		 break; 	
		}
		//printf("root=%d\n",root);
	dfs(root);
	printf("%d\n",max(f[0][root],f[1][root]));
	return 0;
}
