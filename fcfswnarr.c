#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,n,tasum=0,wsum=0,rsum=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int b[n],c[n],ta[n],r[n],w[n];
    float tavg,ravg,wavg;
    printf("Enter burst times:");
    for(i=0;i<n;i++)
    {
     scanf("%d",&b[i]);
     c[i]=0;
    }
    for(i=0;i<n;i++)
    {
            for(j=0;j<=i;j++)
            {
                    c[i]+=b[j];
            }
    }
    for(i=0;i<n;i++)
    {
            ta[i]=c[i];
            tasum+=ta[i];
    }
    for(i=0;i<n;i++)
    {
            w[i]=ta[i]-b[i];
            wsum+=w[i];
    }
    for(i=0;i<n;i++)
    {
            if(i==0)
            {
                    r[i]=0;
                    continue;
            }
            r[i]=c[i-1];
            rsum+=r[i];    
    }
    tavg=(float)tasum/n;
    wavg=(float)wsum/n;
    ravg=(float)rsum/n;
     printf("Process\tBurstTime\tTurnaround\tWaiting\tResponse\n");
    for(i=0;i<n;i++)
     printf("%d\t%d\t\t%d\t\t%d\t%d\n",i+1,b[i],ta[i],w[i],r[i]);
    printf("Average TurnAround Time:%.2f\n",tavg);
    printf("Average Waiting Time:%.2f\n",wavg);
    printf("Average Response Time:%.2f\n",ravg);
    getch();
    }
