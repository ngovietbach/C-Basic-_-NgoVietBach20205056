#include<stdio.h>
int main(){
	int A[100],B[10]={0};
    int n,i;
    printf("Nhap so phan tu cua mang so: ");scanf("%d",&n);
    printf("Nhap mang so: \n");
	for(i=0;i<n;i++){
    	scanf("%d",&A[i]);
	}
	for(i=0;i<n;i++){
		B[A[i]]++;
	}
	for(i=0;i<10;i++){
		if(B[i]>0)printf("%5d",i);
	}
	return 0;
}
