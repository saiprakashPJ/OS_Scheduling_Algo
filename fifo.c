#include<stdio.h>
int main()
{
	int frame,frames[10],pages[50],page,hit=0,i=0,j=0,k=0,l=0,fault=0,flag=0;
	printf("\nEnter no.of pages:");
	scanf("%d",&page);
	printf("\nEnter page values:");
	for(i=0;i<page;i++)
		scanf("%d",&pages[i]);
	printf("\nEnter no.of frames:");
	scanf("%d",&frame);
	for(i=0;i<frame;i++)
		frames[i]=-1;
	printf("\tPage value\tFrames\n");
	for(i=0;i<page;i++)
	{
		for(k=0;k<frame;k++)
		{
			if(frames[k]==pages[i]){
				hit++;
				flag=1;
			}
		}
		if(flag==0)
		{
			frames[j]=pages[i];
			j=(j+1)%frame;
			fault++;
		}
		flag=0;
		printf("\t%d\t\t",pages[i]);
		for(l=0;l<frame;l++)
			printf("%d\t",frames[l]);
		printf("\n");
	}
	printf("Total Page Faults are: %d\n",fault);
}
