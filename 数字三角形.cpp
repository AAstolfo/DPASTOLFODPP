#include<iostream>
#include<algorithm>
using namespace std;
const int N =6e2+10,INF=1e9;
int a[N][N];
int f[N][N];
int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		f[i][0]-=INF;
		f[i][i+1]-=INF;
	}
	
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
    scanf("%d",&a[i][j]);
    
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
    	f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
    	
    int res=0;
    
    for(int i=1;i<=n;i++)
    res =max(res,f[n][i]);
    
    cout<<res<<endl;
}
