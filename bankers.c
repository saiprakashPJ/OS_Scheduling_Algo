#include<stdio.h>
int flagging(int flag[],int n)
{int i;
	for(i=0;i<n;i++)
	{
		if(flag[i]==0)
		return 1;
	}
	return 0;
}
int main(){
	printf("\nEnter number of processes and resources: ");
	int n,m,i,j,t=0,counter=0;
	scanf("%d %d",&n,&m);
	int need[n][m],alloc[n][m],max[n][m],avail[m],flag[n];
	printf("\nEnter available resorces: ");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	printf("\nEnter maximum resources needed for ");
	for(i=0;i<n;i++)
	{
		printf("Process %d: ",i+1);
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
		flag[i]=0;
	}
	printf("\nEnter allocated resources needed for ");
	for(i=0;i<n;i++)
	{
		printf("\nProcess %d: ",i+1);
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	while(flagging(flag,n))
	{
		for(i=0;i<n;i++)
		{
			if(flag[i]!=1)
			{
				for(j=0;j<m;j++)
				{
					if(need[i][j]<=avail[j])
					t+=1;
				}
			}
			else
			continue;
			if(t==m)
			break;
			t=0;
			counter++;
			if(counter==n-1)
			{
				printf("\nUnsafe state\n");
				return 0;
			}
		}
		printf("---%d---",i+1);
		flag[i]=1;
		for(j=0;j<m;j++)
		{
			avail[j]+=alloc[i][j];
			alloc[i][j]=0;
			need[i][j]=0;
		}
		t=0;
		counter=0;
	}
return 0;	
}
