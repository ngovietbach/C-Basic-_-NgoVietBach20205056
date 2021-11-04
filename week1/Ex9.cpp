#include<stdio.h>
int main(){
    FILE *input,*output;
    input=fopen("vanban.txt","r");
    output=fopen("vanbanw.txt","w+");
    char ch;
    ch=fgetc(input);
    while(!feof(input)){
        if(ch>=65&&ch<=90){
            ch=ch-'A'+'a';
            fputc(ch,output);
            ch=fgetc(input);
        }
        else if(ch>=97&&ch<=122){
            ch=ch-'a'+'A';
            fputc(ch,output);
            ch=fgetc(input);
        }
        else {
           fputc(ch,output);
           ch=fgetc(input); 
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}