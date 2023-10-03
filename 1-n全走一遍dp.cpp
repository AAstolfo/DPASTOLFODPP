#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =20,M=1<<N;
int a[N][N];
int f[M][N];
int main()
{
	int n;
	cin>>n;
	memset(f,0x3f,sizeof f);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	
	f[1][0]=0;	
	for(int i=1;i<1<<n;i++)
	{
		
		for(int j=0;j<n;j++)
		{
		if(i>>j&1)
			for(int k=0;k<n;k++)
			{
			if(((i>>k)&1)&&k!=j)
			f[i][j]=min(f[i][j],f[i-(1<<j)][k]+a[k][j]);
			//printf("3\n");	
				
			}
				
	//	printf("2\n");	
		}
		//printf("1------%d\n",i);
	}
	
	printf("%d\n",f[(1<<n)-1][n-1]);
	return 0;
}
