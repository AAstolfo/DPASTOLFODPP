#include<iostream>
using namespace std;
const int N =110;
int a[N][N];
int f[N][N];
int n,m;
int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
int dfs(int i,int j)
{
	if(f[i][j])return f[i][j];
	f[i][j]=1;
	
	for(int k=0;k<4;k++)
	{
		int x=i+dx[k],y=j+dy[k];
		if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]<a[i][j])
		f[i][j]=max(f[i][j],dfs(x,y)+1);
	}
	return f[i][j];
}
int main()
{
	
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	
	int res=0;		
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			
			res=max(res,dfs(i,j));
		}
	
	printf("%d\n",res);		
	return 0;
}
