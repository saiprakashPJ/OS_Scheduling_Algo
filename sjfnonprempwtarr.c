#include<stdio.h>
int flagging(int flag[],int n)
{
	int i,temp=0;
	for(i=0;i<n;i++)
	if(flag[i]==0)
	temp=1;
	return temp;
}
int main()
{
	int n,i,j,k,temp=0,time=0,tasum=0,wsum=0,rsum=0;
	float tavg,wavg,ravg;
	printf("\nEnter the number of processs:");
	scanf("%d",&n);
	int b[n],ord[n],a[n],c[n],f[n],t[n],r[n],w[n],flag[n];
	printf("\nEnter the burst times:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		flag[i]=0;
	}
	k=0;
	printf("\nEnter the arrival timings:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(flagging(flag,n))
	{
		for(i=0;i<n;i++)
		{
			if(flag[i]==0)
			{
				temp=i;
			}
			else
			{
				continue;
			}
			for(j=0;j<n;j++)
			{
				if(a[j]<=time&&flag[j]==0)
				{
					if(b[temp]>=b[j])
					temp=j;
				}
			}
			ord[k++]=temp;
			flag[temp]=1;
			time+=b[temp];
			printf("%d\t",b[temp]);
		}
	}
	c[ord[0]]=b[ord[0]];
	for(i=1;i<n;i++)
	{
	if(a[ord[i]]<c[ord[i-1]])
	c[ord[i]]=c[ord[i-1]]+b[ord[i]];
	else
	c[ord[i]]=a[ord[i]]+b[ord[i]];
	}
	for(i=0;i<n;i++)
	{
		t[ord[i]]=c[ord[i]]-a[ord[i]];
		tasum+=t[ord[i]];
	}
	for(i=0;i<n;i++)
	{
		w[ord[i]]=t[ord[i]]-b[ord[i]];
		wsum+=w[ord[i]];
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			r[ord[i]]=0;
			continue;
		}
		r[ord[i]]=c[ord[i-1]]-a[ord[i]];
		rsum+=r[ord[i]];
	}
	tavg=(float)tasum/n;
	wavg=(float)wsum/n;
	ravg=(float)rsum/n;
	printf("\nProcess:\tBurst:\tArrival:\tTurnAround:\tWaiting:\tResponse:\n");
	for(i=0;i<n;i++)
	printf("%d\t\t%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,b[i],a[i],t[i],w[i],r[i]);
	printf("Average TurnAround Time: %.2f\n",tavg);
	printf("Average waiting Time: %.2f\n",wavg);
	printf("Average Response Time: %.2f\n",ravg);
}
