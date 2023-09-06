#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =1e5+10;
int n,c;
int v[N],w[N],m[N];
int v2[N],w2[N];
int f[N];                                                                                  
int main()
{
    int T ;
    cin>>T;
    
    while(T--)
    {
    	memset(f,0,sizeof(f));
    	cin>>n>>c;
		for(int i=1;i<=n;i++)
		scanf("%d%d%d",v+i,w+i,m+i);
		
		int cnt=1;
		for(int i=1;i<=n;i++)
		{
			int s=m[i];
			int t=1;
			while(s>=t)
			{
			   v2[cnt]=t*v[i];
			   w2[cnt]=t*w[i];
			   s-=t;
			   t*=2;
			   cnt++;
			}
			
			if(s!=0)
			{
			   v2[cnt]=s*v[i];
			   w2[cnt]=s*w[i];
			   s=0;
			   cnt++;
			}
		}
		
		int n=cnt-1;
		
		for(int i=1;i<=n;i++)
		for(int j=c;j>=v2[i];j--)
		f[j]=max(f[j],f[j-v2[i]]+w2[i]);
	
		
	   cout<<f[c]<<endl;
	}
		
	return 0;
}
