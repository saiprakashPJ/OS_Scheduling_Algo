#include<stdio.h>
#include<conio.h>
int main(){
	int n,temp,a[10],ac[10],b[10],bc[10],p[10],pc[10];
	int ord[10],ta[10],w[10],r[10],c[10],f[10],tasum=0,wsum=0,rsum=0;
	float taavg,wavg,ravg;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	int i,j;
	printf("\nEnter process burst times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		bc[i]=b[i];
		ord[i]=i;
	}
	printf("\nEnter process arrival times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		ac[i]=a[i];
	}
	printf("Enter process priority:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		pc[i]=p[i];
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(ac[j]>ac[j+1])
			{
				temp=ac[j+1];
				ac[j+1]=ac[j];
				ac[j]=temp;
				temp=ord[j];
				ord[j]=ord[j+1];
				ord[j+1]=temp;
				temp=pc[j+1];
				pc[j+1]=pc[j];
				pc[j]=temp;
				temp=bc[j+1];
				bc[j+1]=bc[j];
				bc[j]=temp;
			}
			if(ac[j]==ac[j+1])
			{
				if(pc[j]>pc[j+1])
				{
					temp=pc[j+1];
					pc[j+1]=pc[j];
					pc[j]=temp;
					temp=ord[j];
					ord[j]=ord[j+1];
					ord[j+1]=temp;
					temp=ac[j+1];
					ac[j+1]=ac[j];
					ac[j]=temp;
					temp=bc[j+1];
					bc[j+1]=bc[j];
					bc[j]=temp;
				}
				if(pc[j]==pc[j+1])
				{
					temp=pc[j+1];
					pc[j+1]=pc[j];
					pc[j]=temp;
					temp=ord[j];
					ord[j]=ord[j+1];
					ord[j+1]=temp;
					temp=ac[j+1];
					ac[j+1]=ac[j];
					ac[j]=temp;
					temp=bc[j+1];
					bc[j+1]=bc[j];
					bc[j]=temp;
				}
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\t",ord[i]);
	c[ord[0]]=b[ord[0]];
	for(i=1;i<n;i++)
	{
		if(c[ord[i-1]]>a[ord[i]])
		c[ord[i]]=c[ord[i-1]]+b[ord[i]];
		else
		c[ord[i]]=b[ord[i]]+a[ord[i]];
	}
	f[ord[0]]=a[ord[0]];
	for(i=1;i<n;i++)
	{
		if(c[ord[i-1]]<a[ord[i]])
		f[ord[i]]=a[ord[i]];
		else
		f[ord[i]]=c[ord[i-1]];
	}
	for(i=0;i<n;i++)
	{
		ta[ord[i]]=c[ord[i]]-a[ord[i]];
		tasum+=ta[ord[i]];
	}
	for(i=0;i<n;i++)
	{
		w[ord[i]]=ta[ord[i]]-b[ord[i]];
		wsum+=w[ord[i]];
	}
	for(i=0;i<n;i++)
	{
		r[ord[i]]=f[ord[i]]-a[ord[i]];
		rsum+=r[ord[i]];
	}
	taavg=(float)tasum/n;
	wavg=(float)wsum/n;
	ravg=(float)rsum/n;
	printf("\nProcess:\tBurst:\tArrival:\tPriority:\tTurnAround:\tWaiting:\tResponse:");
	for(i=0;i<n;i++)
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,b[i],a[i],p[i],ta[i],w[i],r[i]);
	printf("\nAverage TurnAround Time:%.2f",taavg);
	printf("\nAverage Waiting Time:%.2f",wavg);
	printf("Average Response Time:%.2f",ravg);
}
