#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =1e3+10;
char a[N],b[N];
int f[N][N]={0};
int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		memset(f,0,sizeof(f));
		scanf("%s",a+1);
		getchar();
		scanf("%s",b+1);
		getchar();
		int n=strlen(a+1);
		int m=strlen(b+1);
		a[n+1]='\0',b[m+1]='\0';
		
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])f[i][j]=f[i-1][j-1]+1;
			//else f[i][j]=max(f[i-1][j],f[i][j-1]);
			int t=max(f[i-1][j],f[i][j-1]);
			f[i][j]=max(f[i][j],t);
		}
		
		cout<<f[n][m]<<endl;
	}
}
