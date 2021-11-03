#include<stdio.h>
#include<math.h>
void tach(float a,int* n,float* k){
	*n=(int)a;
	*k=a-*n;
}
int main(){
	float a;
	int t;
	float p;
	scanf("%f",&a);
	tach(a,&t,&p);
	printf("Phan nguyen la: %d, Phan phan so la: %f\n",t,p);
	return 0;
}
