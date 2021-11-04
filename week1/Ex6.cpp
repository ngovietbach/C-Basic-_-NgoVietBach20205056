#include<stdio.h>
void replace_char(char *str,char c1,char c2){
    if(str==NULL)return;
    while(*str!='\0'){
        if(*str==c1)*str=c2;
        ++str;
    }
}
int main(){
    char s[90]="papa";
    char c1,c2;
    c1='p';
    c2='m';
    replace_char(s,c1,c2);
    printf("%s",s);
    return 0;
}