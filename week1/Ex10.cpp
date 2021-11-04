#include<stdio.h>
#define max_line 100
int main(){
     FILE *input,*output;
     input=fopen("vanban.txt","r");
     output=fopen("vanbanw.txt","w+");
     char s[max_line];
     while(fgets(s,max_line,input)!=NULL){
         fputs(s,output);
     }
     fclose(input);
     fclose(output);
     return 0;
}