#include<stdio.h>
#include<stdlib.h>

void largest(int *large,int *seclarge,int arr[],int size)
{

*large = *seclarge = -1;
for(int i=0;i<size;i++)
{


if(arr[i] > *large)
{
*seclarge = *large;
*large = arr[i];
}
else if(arr[i] > *seclarge && arr[i] != *large)
{
*seclarge = arr[i];
}


}
if(*seclarge == *large)
{
*seclarge = -1;
}
}

void print(int arr[],int size)
{
for(int i=0;i<size;i++)
{
printf("%d  ",arr[i]);
}
}

void acc(int arr[],int size)
{
for(int i=0;i<size;i++)
{
scanf("%d",&arr[i]);
}
}


int main()
{
int l=0;
int s=0, size;
printf("size  ");
scanf("%d",&size);

int* arr=(int *)calloc(size,sizeof(int));
if(arr == NULL)
{
printf("error");
}
acc(arr, size);
print(arr,size);
largest(&l,&s,arr,size);
printf("\n%d %d\n",l, s);
free(arr);
 
return 0;
} 



