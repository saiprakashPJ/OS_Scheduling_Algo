#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,j,k=0,tsum=0,wsum=0,rsum=0,t=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    proc=n;
    int b[n],ta[n],w[n],r[n],c[n],f[n],p[n],ord[n];
    float tavg,wavg,ravg;
    printf("Enter burst times:\n");
    for(i=0;i<n;i++)
                    scanf("%d",&b[i]);
    printf("Enter priority order:\n");
     for(i=0;i<n;i++)
    {
                    scanf("%d",&p[i]);
                    ord[i]=i;
    }
    int temp;
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j]>=p[j+1])
			{
				if(p[j]==p[j+1])
				if(ord[j]<=ord[j+1])
				continue;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=b[j+1];
				b[j+1]=b[j];
				b[j]=temp;
				temp=ord[j+1];
				ord[j+1]=ord[j];
				ord[j]=temp;
			}
		}
	}
    for(i=0;i<n;i++)
    {
    	f[i]=t;
    	t+=b[i];
    	c[i]=t;
	}
    for(i=0;i<n;i++)
    {
            ta[i]=c[i];
            tsum+=ta[i];
    }
    for(i=0;i<n;i++)
    {
            w[i]=ta[i]-b[i];
            wsum+=w[i];
    }
    for(i=0;i<n;i++)
    {
            r[i]=f[i];
            rsum+=r[i];
    }
    tavg=(float)tsum/n;
    wavg=(float)wsum/n;
    ravg=(float)rsum/n;
     printf("Process\tBurst\tPriority\tTurnaround\tWaiting\tResponse\n");
    for(i=0;i<n;i++)
     printf("%d\t%d\t%d\t\t%d\t\t%d\t%d\n",ord[i]+1,b[ord[i]],p[ord[i]],ta[ord[i]],w[ord[i]],r[ord[i]]);
    printf("Average TurnAround Time:%.2f\n",tavg);
    printf("Average Waiting Time:%.2f\n",wavg);
    printf("Average Response Time:%.2f\n",ravg);
    }
