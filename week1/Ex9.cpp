#include<stdio.h>
#include<string.h>
#include<ctype.h>
void charreadwrite(FILE *input,FILE *output){
    char c;
    c=fgetc(input);
    while(!feof(input)){
        if(islower(c))c=toupper(c);
        if(isupper(c))c=tolower(c);
        fputc(c,output);  
        c=fgetc(input);
    }
}
int main(){
    FILE *input;FILE *output;
    if((input=fopen("vanban.txt","r"))==NULL){
        printf("Khong the mo file \n");
        return 1;
    }
    if((output=fopen("vanbanw.txt","w"))==NULL){
        printf("Khong the mo file \n");
        return 1;
    }
    charreadwrite(input,output);
    fclose(input);
    fclose(output);
    return 0;
}