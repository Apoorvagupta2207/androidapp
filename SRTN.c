#include<stdio.h>
#include<stdlib.h>
struct process
{
	int pt;
	int at;
	int rt;
	int ct;
	int tat;
	int wt;
	struct process*next;
};

struct process* getnode(int,int);
void main()
{
	int util;
	float avg_tat,avg_wt;
	int x,y,count=0,j,min;
	int n,i,t=0,it=0,busy;
	float thr;
	struct process *head;
	struct process *p,*q;
	head=NULL;
	printf("enter number of process");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter arrival time of each process");
		scanf("%d",&x);
	  
		printf("enter processing time of each process");
		scanf("%d",&y);
		q=getnode(x,y);
		if(head==NULL)
			head=q;

		else
		{
			for(p=head;p->next!=NULL;p=p->next)
			{
			}

			p->next=q;
		}
	}	
			
	while(count<n)
	{
		min=999;
		j=-1;
		for(p=head,i=0;p!=NULL;i++,p=p->next)
		{
			if(p->at<=t && min>p->rt && p->rt>0)
			{
				min=p->rt;
				j=i;
			}
		}
		if(j!=-1)
		{
			for(i=0,p=head;i<j && p!=NULL;p=p->next,i++)
			{
			}
			
			printf("%d  %d  ",p->at,p->pt);

			p->rt=p->rt-1;
			t=t+1;
			p->ct=t;
			
			if(p->rt<=0)
				count++;
		}
		else
		{
			printf("it=%d",it);
			it=it+1;
			t=t+1;
		}
		printf("%d\t",t);
	}

	thr=(float)n/t;
	util=(t-it)/t;
	util=util*100;
	
	for(p=head;p!=NULL;p=p->next)
	{
		p->tat=(p->ct)-(p->at);
		avg_tat=avg_tat+(p->tat);
		p->wt=(p->tat)-(p->pt);
		avg_wt=avg_wt+(p->wt);
	}
	
	avg_tat=avg_tat/(float)n;
	avg_wt=avg_wt/(float)n;
	
	printf("\nThroughput of the system=%0.3f\n",thr);
	printf("Utilization of the system=%d\n",util);
	printf("Average Turn Around time of the system=%0.2f\n",avg_tat);
	printf("Average Waiting time of the system=%0.2f\n",avg_wt);	
}



struct process* getnode(int x,int y)
{
	struct process *q;
	q=(struct process*)malloc(sizeof(struct process));
	q->at=x;
	q->pt=y;
	q->ct=0;
	q->rt=y;
	q->tat=0;
	q->wt=0;
	q->next=NULL;
	return(q);
}
