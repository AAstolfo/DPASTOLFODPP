#include<iostream>
using namespace std;
const int N=1010,mod=1e9+7;
int f[N];
int main()
{
	int n;
	cin>>n;
	
	f[0]=1; 
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		f[j]=(f[j]+f[j-i])%mod;		

		
	cout<<f[n]<<endl;
	return 0;
 } 
 //二维数组写法 
 /*
	for(int i=0;i<=n;i++)f[i][0]=1;//体积为0，可选0-i都有一种选法，即啥都不选 
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k*i<=j;k++)
		 f[i][j]=(f[i][j]+f[i-1][j-k*i])%mod;	
		}
	//朴素写法 
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=i)
		 		f[i][j]=(f[i][j]+f[i][j-i])%mod;	
		}
	//优化1	
*/
