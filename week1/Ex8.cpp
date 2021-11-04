#include<stdio.h>
int main(){
     FILE *input,*output;
     input=fopen("vanban.txt","r");
     output=fopen("vanbanw.txt","w+");
     char ch;
     ch=fgetc(input);
     while(!feof(input)){
         fputc(ch,output);
         ch=fgetc(input);
     }
     fclose(input);
     fclose(output);
     return 0;
}