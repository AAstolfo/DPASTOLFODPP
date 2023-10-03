//f[i][j]存储是第i列上一列小方格捅过来的情况j 
#include<iostream>
#include<cstring>
using namespace std;
const int N =15,M=1<<N;
long long  f[N][M];
bool st[M];
int main()
{
	int n,m;
	
	while(cin>>n>>m,n||m)
	{
		memset(f,0,sizeof f);
		
	//	memset(st,0,sizeof st);//一定要初始化，n变化的时候st的数值会变 
		//原因：n=1,cnt记录为st[1]记录为0; n=2,cnt记录为st[1]记录为1,因为这个1不仅仅是1，代表的是01这个状态 
		for(int i=0;i<1<<n;i++)
		{
			st[i]=false;//本句相当于初始化 
			int cnt=0;
			for(int j=0;j<n;j++)
			{
				if(i>>j&1)
				{
					if(cnt&1)st[i]=true;//true代表不行
					cnt=0;
				}
				else 
				cnt++;
			}
			if(cnt&1)st[i]=true;
		}
		
		
		/*
		for(int i=0;i<1<<n;i++)
		printf("%d ",!st[i]);
		puts("");
		*/
		/*
		for(int i=0;i<1<<n;i++)
		{
			st[i]=true;//本句相当于初始化 
			int cnt=0;
			for(int j=0;j<n;j++)
			{
				if(i>>j&1)
				{
					if(cnt&1)st[i]=false;//true代表不行
					cnt=0;
				}
				else 
				cnt++;
			}
			if(cnt&1)st[i]=false;
		}
		
		for(int i=0;i<1<<n;i++)
		printf("%d ",st[i]);
		puts("");*/
		
		
		f[0][0]=1;
		for(int i=1;i<=m;i++)
			for(int j=0;j<1<<n;j++)
			{
				for(int k=0;k<1<<n;k++)
				if((k&j)==0&&(!st[k|j]))//位运算一定要加括号啊 
				f[i][j]+=f[i-1][k];	
			}
	   printf("%lld\n",f[m][0]);
	}
	return 0;
}
