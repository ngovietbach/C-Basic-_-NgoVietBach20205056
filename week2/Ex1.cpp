#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char* cat(char* s1,char* s2){
    char* p;
    int len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    p=(char *)malloc((len1+len2+1)*sizeof(char));
    if(p==NULL){
        printf("fail");
        return NULL;
    }
    strcpy(p,s1);
    strcpy(p+len1,s2);
    return p;
}
int main(){
    char s1[1000],s2[1000];
    char* p;
    printf("Nhap xau 1: ");
    gets(s1);
    printf("Nhap xau 2 :");
    gets(s2);
    p=cat(s1,s2);
    if(p==NULL){
        printf("fail");
        return 1;
    }
    printf("xau sau khi noi la : %s\n",p);
    free(p);
    return 0;
}