#include<stdio.h>
#include<string.h>
void copy(FILE *input,FILE *output){
    char s[100];
    int i=1;
    while(fgets(s,100,input)!=NULL){
        fprintf(output,"%d %s",i,s);
        i++;
    }
}
int main(int argc,char* argv[]){
    FILE *input;FILE *output;
    if(argc!=3){
        printf("du lieu vao khong hop le \n");
        return 0;
    }
    if((input=fopen(argv[1],"r"))==NULL){
        printf("Khong the mo tep\n");
        return 0;
    }
    if((output=fopen(argv[2],"w"))==NULL){
        printf("Khong the mo tep\n");
        return 0;
    }
    copy(input,output);
    fclose(input);
    fclose(output);
    return 1;
}