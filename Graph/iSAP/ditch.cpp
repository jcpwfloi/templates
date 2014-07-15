#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
const int MAX=2100000000,MAXn=200+9;
int n,answer,g[MAXn][MAXn],d[MAXn],gap[MAXn],st=1,ed=n;
int sap(int u,int flow)
{
	if(u==ed)
		    return flow;
	    int res=flow,i,t;
		for(i=1;i<=n;++i)
			    if(g[u][i] && d[u]==d[i]+1)
					{
							t=sap(i,min(res,g[u][i]));
								    g[u][i]-=t,g[i][u]+=t;
										if(!(res-=t))
												    return flow;
											}
		    if(!--gap[d[u]])
				d[st]=n;
			++gap[++d[u]];
			    return flow-res;
}
int main()
{
	int m,i,t1,t2,t3;
	    freopen("ditch.in","r",stdin);freopen("ditch.out","w",stdout);
		scanf("%d%d",&m,&n);
		    for(i=1;i<=m;++i)
			    {
					scanf("%d%d%d",&t1,&t2,&t3);
						g[t1][t2]+=t3;
						    }
			for(gap[0]=n;d[st]<n;)
				    answer+=sap(st,MAX);
			    printf("%d\n",answer);
				return 0;
}
