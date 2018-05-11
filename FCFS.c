#include<stdio.h>
#include<stdlib.h>
struct process
{
	int num;
	float t_arvl;
	float t_prcs;
	float t_com;
	float turn_t;
	float t_w;
	struct process *next;
};

struct process * getnode(float,float,int);
void main()
{
	struct process *head,*q,*p;
	float t=0.0,x,y,it=0.0,thrpt,utl,avg_tat=0.0,avg_wt=0.0;
	int i,n,j;
	head=NULL;
	printf("Enter number of process:");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++)
	{
		printf("Enter arrival time for %d process:",i+1);
		scanf("%f",&x);
		
		printf("Enter prossesing time for %d process:",i+1);
		scanf("%f",&y);
		
		q=getnode(x,y,i+1);
		if(head==NULL)
			head=q;
			
		else
		{
			for(p=head;p->next!=NULL;p=p->next);
			
			p->next=q;
		}	
	}
	printf("Gantt Chart:\n");

	for(p=head;p!=NULL;p=p->next)
	{
		if(p->t_arvl<=t)
		{
			t=t+p->t_prcs;
			p->t_com=t;
			printf("p%d,%f\t",p->num,t);
		}
		else
		{
			it=it+(p->t_arvl-t);
			t=p->t_arvl;
			t=t+p->t_prcs;
			p->t_com=t;
			printf("p%d,%f\t",p->num,t);
		}
	}
	thrpt=(float)n/t;
	utl=(t-it)*100/t;
	
	for(p=head;p!=NULL;p=p->next)
	{
		p->turn_t=(p->t_com)-(p->t_arvl);
		avg_tat=avg_tat+(p->turn_t);
		p->t_w=(p->turn_t)-(p->t_prcs);
		avg_wt=avg_wt+(p->t_w);
	}
	
	avg_tat=avg_tat/(float)n;
	avg_wt=avg_wt/(float)n;
	
	printf("\nThroughput of the system=%0.2f\n",thrpt);
	printf("Utilization of the system=%0.2f\n",utl);
	printf("Average Turn Around time of the system=%0.2f\n",avg_tat);
	printf("Average Waiting time of the system=%0.2f\n",avg_wt);	
}

struct process * getnode(float x,float y,int n)
{
	struct process *q;
	q=(struct process *)malloc(sizeof(struct process));
	q->num=n;
	q->t_arvl=x;
	q->t_prcs=y;
	q->t_com=0;
	q->turn_t=0;
	q->t_w=0;
	q->next=NULL;
	
	return q;
}
