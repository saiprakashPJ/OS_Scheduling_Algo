#include<stdio.h>
int main()
{
	int pages[50],page,frame,frames[10],i=0,k=0,l=0,time[10],fault=0,flag=0,min=0;
	printf("\nEnter no.of pages:");
	scanf("%d",&page);
	printf("\nEnter page values:");
	for(i=0;i<page;i++)
		scanf("%d",&pages[i]);
	printf("\nEnter no.of frames:");
	scanf("%d",&frame);
	for(i=0;i<frame;i++){
		frames[i]=-1;
		time[i]=i;
	}
	printf("\tPage value\tFrames\n");
	for(i=0;i<page;i++)
	{
		for(k=0;k<frame;k++)
		{
			if(frames[k]==pages[i]){
				time[k]=i+frame;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{	
			for(k=1;k<frame;k++)
			{
				if(time[min]>time[k])
					min=k;
			}
			fault++;
			frames[min]=pages[i];
			time[min]=i+frame;
		}
		flag=0;
		min=0;
		printf("\t%d\t\t",pages[i]);
		for(l=0;l<frame;l++)
			printf("%d\t",frames[l]);
		printf("\n");
	}
	printf("Total Page Faults are: %d\n",fault);
}
