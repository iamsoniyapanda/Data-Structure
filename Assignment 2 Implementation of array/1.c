//Read a 2D array & then represent the same array as sparse metrics
#include<stdio.h>
int main()
int row,col,i,j,a[10],[10],count=0;
printf("Enetr row");
scanf("%d",&row);
printf("Enter column");
scanf("%d",&col);
printf("Enter elements of matrix");
for(i=0;i<row;i++){
for(j=0;j<col;j++){
scanf("%d",&a[i][j]);
}
}
printf("Elements are:");
for(i=0;i<row;i++){
for(j=0;j<col;j++){
printf("%d\t",a[i][j]);
}
printf("");
}
for(i=0;i<row;i++){
for(j=0;j<col;j++){

if(count>(row*col)/2))
  printf("Matrix is a sparse matrix:");
else
  printf("Matrix is not sparse matrix:");
}
  
  
  
  
  
