//To check duplicate number in an array
#include<stdio.h>
int main()
{
  int n ,i,j,found=0;
prinf(enter the number of elements in the array:");
  scanf("%d",&n);

int arr[n];
printf("Enter the elements of the array:\n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(arr[i]==arr[j]){
found=1;
printf("Duplicate found:%d\n",arr[i]);
}
}
}
if(!found){
printf("No duplicates found in the array\n");
}
return 0;
}

  
  
  
