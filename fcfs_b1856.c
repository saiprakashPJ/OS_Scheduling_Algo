#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int i,j,n,*b,*a,*ta,*w,*r,*c,tasum=0,wsum=0,rsum=0;
    float taavg,wavg,ravg;
    printf("Enter number of processes:");
    scanf("%d",&n);
    b=malloc(n*sizeof(*b));
    a=malloc(n*sizeof(*a));
    ta=malloc(n*sizeof(*ta));
    w=malloc(n*sizeof(*w));
    r=malloc(n*sizeof(*r));
    c=malloc(n*sizeof(*c));
    for(i=0;i<n;i++)
    c[i]=0;
    for(i=0;i<n;i++)
    {
            printf("Enter the burst time for process %d: ",i+1);
            scanf("%d",&b[i]);
            printf("Enter the arrival time for process %d: ",i+1);
            scanf("%d",&a[i]);
    }
    c[0]=b[0];
    for(i=0;i<n;i++)
    {
    if(c[i]>a[i])
    c[i]=c[i-1]+b[i];
    else
    c[i]=c[i-1]+(a[i]-c[i-1])+b[i];
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
            if(i==0)
            {
                    r[i]=0-a[i];
                    rsum+=r[i];
                    continue;
            }
            r[i]=c[i-1]-a[i];
            rsum+=r[i];    
    }
    taavg=(float)tasum/n;
    wavg=(float)wsum/n;
    ravg=(float)rsum/n;
     printf("Process\tBurst Time\tArrival Time\tTurnaround Time\tWaiting Time\tResponseTime\n");
    for(i=0;i<n;i++)
    {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,b[i],a[i],ta[i],w[i],r[i]);
    }
    printf("Average TurnAround Time:%f\n",taavg);
    printf("Average Waiting Time:%f\n",wavg);
    printf("Average Response Time:%f\n",ravg);
    getch();
    }
           
            
                           
    
