#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N =3e2+10;
int s[N];
int f[N][N];
int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
			scanf("%d",s+i);
	
	for(int i=1;i<=n;i++)s[i]+=s[i-1];
	
	
	for(int j=2;j<=n;j++)
	for(int i=1;i+j-1<=n;i++)
	{
		int l=i,r=i+j-1;
		f[l][r]=1e9;
		for(int k=l;k<r;k++)
			f[l][r]=min(f[l][k]+f[k+1][r]+s[r]-s[l-1],f[l][r]);
	}
	
	cout<<f[1][n]<<endl;
	return 0;
}
