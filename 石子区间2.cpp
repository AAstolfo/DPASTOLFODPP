#include<iostream>
using namespace std;
const int N =1010,mod=1e9+7;
int f[N][N];
int main()
{
	int n;
	cin>>n;
	
	//用j个数表示出i的方案
	//分为
	//j个数中最小值为1 == f[i-1][j-1] 
	//j个数中最小值不为1 == f[i-j][j]
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)//j不能大于i 
			f[i][j]=(f[i-1][j-1] + f[i-j][j])%mod;
			
	int res=0;
	for(int i=1;i<=n;i++)
	res=(res+f[n][i])%mod;
	
	cout<<res<<endl;
	return 0;
}
