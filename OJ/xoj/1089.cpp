#include<stdio.h>
#include<string.h>

#define V 300
#define INF 100000000

int n, m;
int c[V][V];

int EK( int s, int t )
{
    int queue[V],pre[V],u,v,p,q,aug;
    int flow=0;

	while(1)
    {
		memset(pre,-1,sizeof(pre));

		for(queue[p=q=0]=s;p<=q;p++)
        {
			u=queue[p];
			for(v=0;v<m&&pre[t]<0;v++)
				if(c[u][v]>0&&pre[v]<0)
				{
					pre[v]=u;
					queue[++q]=v;
				}

			if(pre[t]>=0)
				break;
        }
        if(pre[t]<0)    break;
        //while


        aug=INF;                                      
        for(u=pre[v=t];v!=s;v=u,u=pre[u])
            if(aug>c[u][v])
				aug=c[u][v];


        for(u=pre[v=t];v!=s;v=u,u=pre[u])
        {
			c[u][v]-=aug;
			c[v][u]+=aug;
		}
		flow+=aug;
	}
	return flow;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int x,y,cost;
		memset(c,0,sizeof(c));

		for(int i=0;i<n;i++)
		{	scanf("%d%d%d",&x,&y,&cost);
		    c[x-1][y-1]+=cost;
		}

		printf("%d\n",EK(0,m-1));
	}
	return 0;
}
