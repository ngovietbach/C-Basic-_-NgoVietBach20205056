#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
typedef struct 
{
    char name[30];
    char number[30];
    char email[30];

}book;
book A[max];
book B[max];
int main(){
    int n,i;
    printf("nhap so phan tu muon nhap: "),scanf("%d",&n);
    FILE *p=fopen("phonebook.dat","wb");
    if(p==NULL){
        printf("open file fail \n");
        return 1;
    }
    for(i=0;i<n;i++){
        printf("Nhap du lieu nguoi thu %d \n",i+1);
        printf("Name: ");fflush(stdin);gets(A[i].name);
        printf("Number: ");fflush(stdin);gets(A[i].number);
        printf("Email: ");fflush(stdin);gets(A[i].email);
    }
    int irc;
    irc=fwrite(A,sizeof(book),n,p);
    printf("fwrite return = %d",irc);
    fclose(p);
    FILE *ptr=fopen("phonebook.dat","rb");
    if(ptr==NULL){
        printf("open file fail \n");
        return 1;
    }
    irc=fread(B,sizeof(book),n,ptr);
    for(i=0;i<n;i++){
        printf("%s-",B[i].name);
        printf("%s-",B[i].number);
        printf("%s\n",B[i].email);
    }
    fclose(p);
    return 1;
}