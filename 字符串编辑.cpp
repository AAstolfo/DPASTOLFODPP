#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =1810;
int f[N][N];
char a[N],b[N];
int main()
{
	gets(a+1),gets(b+1);
	int n=strlen(a+1);
	int m=strlen(b+1);
	//printf("%s\n%s\n%d %d\n",a+1,b+1,n,m); 
	for(int i=1;i<=m;i++)f[0][i]=i;
	for(int i=1;i<=n;i++)f[i][0]=i;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			{
				f[i][j]=min(f[i-1][j],f[i][j-1])+1;
				f[i][j]=min(f[i][j],f[i-1][j-1]+ (a[i]!=b[j])); 
			}   
	
	cout<<f[n][m]<<endl;
	return 0;
}
