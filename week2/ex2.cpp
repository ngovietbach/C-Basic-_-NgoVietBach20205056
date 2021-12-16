#include<stdio.h>
typedef struct 
{
    float x,y;
}point;
typedef struct 
{
    point center;
    float r;
}circle;
int is_in_circle(point A,circle B){
    float kc;
    kc=(A.x-B.center.x)*(A.x-B.center.x)+(A.y-B.center.y)*(A.y-B.center.y);
    if(kc<=B.r*B.r)return 1;
    else return 0;
}
int main(){
    circle B;
    point A;
    printf("Nhap tam va ban kinh hinh tron \n");
    scanf("%f %f %f",&B.center.x,&B.center.y,&B.r);
    printf("Nhap diem: ");
    scanf("%f %f",&A.x,&A.y);
    if(is_in_circle(A,B)==1)printf("Nam trong \n");
    else printf("nam ngoai\n");
    return 0;
}

