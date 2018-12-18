#include<stdio.h>
int main()
{
	int pages[50],page,frame,frames[10],i=0,k=0,l=0,time[10],fault=0,flag=0,max=0;
	printf("\nEnter no.of pages:");
	scanf("%d",&page);
	printf("\nEnter page values:");
	for(i=0;i<page;i++)
		scanf("%d",&pages[i]);
	printf("\nEnter no.of frames:");
	scanf("%d",&frame);
	for(i=0;i<frame;i++){
		frames[i]=-1;
	}
	for(i=0;i<page;i++)
	{
		for(k=0;k<frame;k++)
		{
			if(frames[k]==pages[i]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			for(l=0;l<frame;l++)
			{
				for(k=i;k<page;k++)
					if(frames[l]==pages[k]){
						time[l]=k;
						break;
					}
					else
						time[l]=page+frame-l;
			}
			for(l=1;l<frame;l++)
				if(time[max]<time[l])
					max=l;
			frames[max]=pages[i];
			fault++;
		}
		flag=max=0;
			printf("\t%d\t\t",pages[i]);
		for(l=0;l<frame;l++)
			printf("%d\t",frames[l]);
		printf("\n");
	}
	printf("Total Page Faults are: %d\n",fault);
}
