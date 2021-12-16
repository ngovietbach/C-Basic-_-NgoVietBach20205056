#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct 
{
    char name[30];
    char number[30];
    char email[30];

}book;
int main(){
    FILE *p;
    book *phonearr;
    int i,n,irc;
    printf("Read 3rd data to 6th data\n");
    if((p=fopen("phonebook.dat","rb"))==NULL){
        printf("mo file khong thanh cong \n");
        return 0;
    }
    phonearr=(book *)malloc(4*sizeof(book));
    if(phonearr==NULL){
        printf("Memory allocation failed\n");
        return 0;
    }
    if((fseek(p,2*sizeof(book),SEEK_SET))!=0){
        printf("Fseek failed!\n");
        return 0;
    }
    irc=fread(phonearr,sizeof(book),4,p);
    for(i=0;i<4;i++){
        printf("%s-",phonearr[i].name);
        printf("%s-",phonearr[i].number);
        printf("%s\n",phonearr[i].email);
    }
    return 1;
}

