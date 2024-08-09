#include<math.h>
#include<stdio.h>
#include<stdlib.h>
/*int copy(int a[10],int n)
{
	int temp[10];
	int i;
	for(i=0;i<n;i++)
	{
		temp[i]=a[i];
	}
	return temp;
} */
/*void fcfs(int q[10],int n, int h)
{
	int i;
	int total=0;
	for(i=0;i<n;i++)
	{
		total=total+abs(q[i]-h);
		h=q[i];
	}
	printf("tottal head movement:%d ",total);
}
*/
void scan(int q[10],int n, int h, int m)
{
//	copy(a,n);
	int j,i,total=0;
	int index,initial,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(q[j]>q[j+1])
			{
				temp=q[j];
				q[j]=q[j+1];
				q[j+1]=temp;
			}
		}
	}
	 for(i=0;i<n;i++)   
	{
 		if(h<q[i])
		{
			index=i;
			break;
		}
	}
	 for(i=index;i<n;i++)   
	{
		total=total+abs(q[i]-h);
		h=q[i];	

	}
	total=total+abs(m-q[i-1]);
	  printf("tottal head movement:%d ",total);     
	initial=m;
	 for(i=index-1;i>=0;i--)
	  {
		 total=total+abs(q[i]-initial);   
		initial=q[i];
	}
	   printf("tottal head movement:%d ",total);     
}

void cscan(int q[10],int n, int h, int m)
{
 int j,i,total=0;
        int index,initial,temp;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(q[j]>q[j+1])
                        {
                                temp=q[j];
                                q[j]=q[j+1];
                                q[j+1]=temp;
                        }
                }
        }
         for(i=0;i<n;i++)
        {
                if(h<q[i])
                {
                        index=i;
                        break;
                }
        }
         for(i=index;i<n;i++)
        {
                total=total+abs(q[i]-h);
                h=q[i];

        }
 	total=total+abs(m-q[i-1]);
	total=total+abs(m-0);
	initial=0;
         printf("tottal head movement:%d ",total);
        //initial=m;
         for(i=0;i<index;i++)
          {
                 total=total+abs(q[i]-initial);
                initial=q[i];
        }
           printf("tottal head movement:%d ",total);

}
void main()
{
	int i,j,n,m,a,q[10],h;
	printf("Enter the size of request: ");
	scanf("%d",&n);
	printf("Enter the order:");
	for(i=0;i<n;i++)
	{
		  scanf("%d",&q[i]);
		}
	printf("Etner the curent head position: ");
	scanf("%d",&h);
	printf("Enter the maximum dsik size: ");
	scanf("%d",&m);
//	fcfs(q,n,h);
	scan(q,n,h,m);
}
