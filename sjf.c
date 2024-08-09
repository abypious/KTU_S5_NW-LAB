#include<stdio.h>
typedef struct{
int no,bt,at,tat,c,wt,ct,pr,id;
}process;
process p[20],temp;
int n,i,ct,total,sh,j,ttat,ttwt;
/* void sort()
{
	struct process temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;

			}
		}
	}
}*/
int main()
{
	printf("Enter the number of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i].id=i;
	}
	for(i=0;i<n;i++)
        {
                printf("\nEnter the arrival time and burst time of proess p%d   ",p[i].id);
		scanf("%d%d",&p[i].at,&p[i].bt);
		//temp=p[i].bt;

       }
	 for(i=0;i<n;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].at>p[j+1].at)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;

                        }
                }
        }
	total=0;
	sh=0;
	for(i=0;i<n;i++)
		p[i].c=1;
	 for(i=0;i<n;i++)
	{
		sh=i;
		while(total<p[i].at)
		{
			total++;
		}
		for(j=i;j<n;j++)
			if(p[j].at<=total&&p[sh].bt>p[j].bt&&p[sh].c==1)
			{
				sh=j;
			}

			temp=p[sh];
			p[sh]=p[i];
			p[i]=temp;
			p[i].c=0;
			

			p[i].ct=total+p[i].bt;
			total=p[i].ct;
			p[i].tat=p[i].ct-p[i].at;
			p[i].wt=p[i].tat-p[i].bt;


	}
  for(i=0;i<n;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].at>p[j+1].at)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;

                        }
                }
        }

	printf("pid  | arr  | burst | comp | turn | wait\n");

	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);


		}

  /*for(i=0;i<n;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].at>p[j+1].at)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;

                        }
                }
        }*/


}






