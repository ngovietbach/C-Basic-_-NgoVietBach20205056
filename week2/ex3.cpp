#include<stdio.h>
int main(){
    FILE *input=fopen("lab1.txt","r");
    FILE *output=fopen("lab1a.txt","w");
    char F[1000];
    int num;
    while(!feof(input)){
        num=fread(F,sizeof(char),1000,input);
    }
    fwrite(F,sizeof(char),num,output);
    fclose(input);
    fclose(output);
}