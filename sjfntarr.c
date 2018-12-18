#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,n,temp,tasum=0,wsum=0,rsum=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int b[n],cb[n],ord[n],c[n],t[n],r[n],w[n];
    float tavg,ravg,wavg;
    printf("Enter burst times:");
    for(i=0;i<n;i++)
    {
     scanf("%d",&b[i]);
     cb[i]=b[i];
     ord[i]=i;
    }
    for(i=0;i<n-1;i++)       
       for(j=0; j<n-i-1;j++) 
           if(cb[j]>cb[j+1])
           {
              temp=cb[j+1];
              cb[j+1]=cb[j];
              cb[j]=temp;
              temp=ord[j+1];
              ord[j+1]=ord[j];
              ord[j]=temp;
           }
   for(i=0;i<n;i++)
   printf("%d\t",ord[i]); 
   c[ord[0]]=b[ord[0]];
	for(i=1;i<n;i++)
	{
	c[ord[i]]=c[ord[i-1]]+b[ord[i]];
	}
	for(i=0;i<n;i++)
	{
		t[ord[i]]=c[ord[i]];
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
		r[ord[i]]=c[ord[i-1]];
		rsum+=r[ord[i]];
	}
	tavg=(float)tasum/n;
	wavg=(float)wsum/n;
	ravg=(float)rsum/n;
	printf("\nProcess:\tBurst:\tTurnAround:\tWaiting:\tResponse:\n");
	for(i=0;i<n;i++)
	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,b[i],t[i],w[i],r[i]);
	printf("Average TurnAround Time: %.2f\n",tavg);
	printf("Average waiting Time: %.2f\n",wavg);
	printf("Average Response Time: %.2f\n",ravg);
}
