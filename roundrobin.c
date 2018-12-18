#include<stdio.h>
#include<conio.h>
int flagging(int bc[],int n)
{
    int i,t=0;
    for(i=0;i<n;i++)
    if(bc[i]!=0)
    return t+1;
    return t;
}
int main()
{
    int n,i,q,temp,k=0,tsum=0,wsum=0,rsum=0,t=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    printf("Enter Quantum Value: ");
    scanf("%d",&q);
    int b[n],bc[n],ta[n],w[n],r[n],c[n],fi[n],flag[n];
    float tavg,wavg,ravg;
    printf("Enter burst times:\n");
    for(i=0;i<n;i++)
    {
                    scanf("%d",&b[i]);
                    bc[i]=b[i];
                    flag[i]=0;
    }
    while(flagging(bc,n))
    {
        for(i=0;i<n;i++)
        {
            if(bc[i]==0)
        		continue;
            if(!flag[i])
            {
                fi[i]=t;
                flag[i]=1;
            }       
            if(bc[i]>q)
            {
            	bc[i]-=q;
				t+=q;
            }
            else
            {
                temp=bc[i];
                bc[i]=0;
                t+=temp;
                c[i]=t;
            }
                k++;
    }
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
            r[i]=fi[i];
            rsum+=r[i];    
    }
    tavg=(float)tsum/n;
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
