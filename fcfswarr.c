#include<stdio.h>
#include<conio.h>
int main(){
	int i,j,n,temp,a[10],b[10],p[10],ta[10],w[10],r[10],c[10],f[10];
	float tasum=0,wsum=0,rsum=0,taavg,wavg,ravg;
	
	printf("Enter number of processes:");
    scanf("%d",&n);
	printf("Enter the burst times:");
	for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        p[i]=i;
	}
	printf("Enter the arrival times");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>=a[j+1])
			{
				if(a[j]==a[j+1])
				if(p[j]<=p[j+1])
				continue;
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=b[j+1];
				b[j+1]=b[j];
				b[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%d\t",p[i]);
	printf("\n");
    c[0]=a[0]+b[0];
    for(i=1;i<n;i++)
    {
    	if(c[i-1]<a[i])
    		c[i]=a[i]+b[i];
    	else
    		c[i]=c[i-1]+b[i];
    }
    for(i=0;i<n;i++)
    {
    	if(i==0)
    	f[i]=a[i];
    	else if(c[i-1]<a[i])
    	f[i]=a[i];
    	else
    	f[i]=c[i-1];
	}
    for(i=0;i<n;i++)
    {
            ta[i]=c[i]-a[i];
            tasum+=ta[i];
    }
    for(i=0;i<n;i++)
    {
            w[i]=ta[i]-b[i];
            wsum+=w[i];
    }
    for(i=0;i<n;i++)
    {
            r[i]=f[i]-a[i];
            rsum+=r[i];    
    }
    taavg=tasum/n;
    wavg=wsum/n;
    ravg=rsum/n;
     printf("Process\tBurst\tArrival\tTurnaround\tWaiting\tResponse\n");
    for(i=0;i<n;i++)
    {
            printf("%d\t%d\t%d\t%d\t\t%d\t%d\n",p[i]+1,b[i],a[i],ta[i],w[i],r[i]);
    }
    printf("Average TurnAround Time:%f\n",taavg);
    printf("Average Waiting Time:%f\n",wavg);
    printf("Average Response Time:%f\n",ravg);
}
