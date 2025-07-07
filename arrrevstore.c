#include<stdio.h>
#include<stdlib.h>

void revarr(int cop[], int arr[], int n)
{
for(int i=0;i<n;i++)
{
cop[n-i-1] = arr[i];
}
}

void prints(int rev[],int n)
{
for(int i=0; i<n;i++)
{
printf("%d  ",rev[i]);
}
}

void acc(int rev[],int n)
{
for(int i=0; i<n;i++)
{
scanf("%d",&rev[i]);
}
}


int main()
{
 int n;
printf("enter size  ");
scanf("%d" , &n);
int* arr= (int*)malloc(n*sizeof(int));
int* rev= (int*)malloc(n*sizeof(int));


acc(arr,n);

revarr(rev , arr , n);


printf("\nreversed\n");
prints(rev,n);

free(arr);
free(rev);
return 0;
}
