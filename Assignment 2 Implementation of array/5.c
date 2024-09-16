//A program that reads a 2D metrics and check if the metrics is a symmetric metrics or not
#include<stdio.h>
int amin(){
  int n,i,j;
printf("Enter the dimension of the matrix(n*n):");
scanf("%d",&n);

int matrix[n][n];
printf("Enter the elements of the matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
for(j=0;j<n;j++)
{
scanf("%d",&matrix[i][j]);
}
}
if(is symmetric)break;
}
if(issymmetric){
printf("The matrix is symmetric\n");
}else{
printf("The matrix is not symmetric\n");
}
return 0;
}
  
