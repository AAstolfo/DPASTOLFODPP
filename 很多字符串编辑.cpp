#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =15,M=1010;
int n,m;
char a[M][N],b[N];
int f[N][N];
int solve(char* aa,char* bb)
{
	int la=strlen(aa+1);
	int lb=strlen(bb+1);
	//printf("la=%d lb=%d\n",la,lb);
	for(int i=1;i<=la;i++)f[i][0]=i;
	for(int i=1;i<=lb;i++)f[0][i]=i;
	
	for(int i=1;i<=la;i++)
		for(int j=1;j<=lb;j++)
		 	{
		 		f[i][j]=min(f[i-1][j],f[i][j-1])+1;
		 		f[i][j]=min(f[i][j],f[i-1][j-1]+(aa[i]!=bb[j]));
			} 
	
	/*for(int i=0;i<=la;i++)
	{
		for(int j=0;j<=lb;j++)
		printf("%d ",f[i][j]);
		puts(""); 
	}*/
		
	return f[la][lb];
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=0;i<n;i++)
	{
		//gets(a[i]+1);
		scanf("%s",a[i]+1);
		//printf("/////%s\n",a[i]+1);
		getchar();
	}
	
	
	while(m--)
	{
		int res=0;
		scanf("%s",b+1);//'\0'注意！
		int lb=strlen(b+1);
    	b[lb+1]='\0';
		int limit=0;
		scanf("%d",&limit);
		getchar();
		//printf("%s\n%d\n",b+1,limit);
		for(int i=0;i<n;i++)
			if(solve(a[i],b)<=limit)//题目有问题，说是以内但却包括了limit 
			res++;
			
		cout<<res<<endl;
	}
	return 0;
}
