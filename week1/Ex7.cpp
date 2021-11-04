#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]){
    double chieudai,chieurong;
    if(argc!=3)
    {
        printf("Wrong number of arguments! \n");
        return 0;
    }
    chieudai=atof(argv[1]);
    chieurong=atof(argv[2]);
    printf("Chu vi hinh chu nhat la %.1f\n",(chieudai+chieurong)*2);
    printf("Dien tich hinh chu nhat la %.1f\n",chieudai*chieurong);
    return 0;
}