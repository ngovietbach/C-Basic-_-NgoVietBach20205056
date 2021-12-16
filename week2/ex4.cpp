#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    FILE *input,*output;
    if(argc!=3){
        printf("Fail");
        return 0;
    }
    input=fopen(argv[1],"r");
    output=fopen(argv[2],"w");
    char F[1000];
    int num;
    while(!feof(input)){
        num=fread(F,sizeof(char),1000,input);
    }
    fwrite(F,sizeof(char),num,output);
    fclose(input);
    fclose(output);
    return 0;
}