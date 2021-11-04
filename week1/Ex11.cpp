#include<stdio.h>
#include<string.h>
#define max_line 100
int main(){
     FILE *input,*output;
     input=fopen("vanban.txt","r");
     output=fopen("vanbanw.txt","w+");
     char s[max_line];
     while(fgets(s,max_line,input)!=NULL){
         int dem=strlen(s);
         fprintf(output,"%d %s",dem,s);
     }
     fclose(input);
     fclose(output);
     return 0;
}