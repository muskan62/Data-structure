#include<stdio.h>
#include<conio.h>
void bubblesort(int[],int);
int main(){
clrscr();
int arr[100],i,n,d,swap;
printf("Enter elements");
scanf("%d",&n);
for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
bubblesort(arr,n);
printf("sorted list in ascending order\n");
for(i=0;i<n;i++)
  printf("%d\n",arr[i]);
getch();
return 0;
}
void bubblesort(int list[],int n){
int i,j,temp;
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(list[j]>list[j+1])
{
temp=list[j];
list[j]=list[j+1];
list[j+1]=temp;
}
}
}
}