#include<stdio.h>
void main()
{
	int elements[50],n,i,j,temp,order=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&elements[i]);
	for(i=0;i<n-1;i++)
	{
	order=0;
	for(j=0;j<n-i-1;j++)
	{
		if(elements[j]>elements[j+1])
		{
			temp = elements[j];
			elements[j] = elements[j+1];
			elements[j+1] = temp;
			order++;
		}	
	}
	if (order==0)
	break;		
	}
	for(i=0;i<n;i++)
	printf("%d\t",elements[i]);
}
