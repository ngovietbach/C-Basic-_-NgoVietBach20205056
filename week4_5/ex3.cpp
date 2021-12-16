#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct StackNode
{
    int data;
    struct StackNode *next;
}Node;
Node* top=NULL;
Node* push(Node* top,int value){
    Node* temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=value;
    temp->next=top;
    top=temp;
    return top;
}
Node* pop(Node* top,int* s){
    Node* temp;
    int value;
    if(top==NULL){
        return top;
    }
    else{
        value=top->data;
        temp=top;
        top=top->next;
        free(temp);
        *s=value;
        return top;
    }
}
int stack_empty(Node* top){
    return(top==NULL);
}
int tinh(int pop1,int pop2,char op){
    int value;
    switch (op)
    {
        case '+': 
        {
            value=pop2+pop1;
            break;
        }
        case '-': 
        {
            value=pop2-pop1;
            break;
        }
        case '*': 
        {
            value=pop2*pop1;
            break;
        }
        case '/': 
        {
            value=pop2/pop1;
            break;
        }
    }
    return value;
}
void giaodien()
{
   printf("=============================================\n");
   printf("1. nhap infix chuyen thanh postfix \n");	
   printf("2. nhap postfix tinh ket qua\n");
   printf("An k de thoat\n");
   printf("=============================================\n"); 	
}
int main(){
    char a[100];
    int value;
    int i;
    int pop1,pop2;
    char ch;
    do {
        printf("\n");
        giaodien();
        printf("Nhap 1 hoac 2 hoac k : ");
        fflush(stdin);
        scanf("%c",&ch);
        switch (ch)
        {
        case '2':{
    printf("Nhap vao xau bieu thuc postfix : ");
    fflush(stdin);
    gets(a);
    for(i=0;i<strlen(a);i++){
        if((a[i]<=57)&&(a[i]>=49)){
            top=push(top,a[i]-48);
        }
        if((a[i]=='+')||(a[i]=='-')||(a[i]=='*')||(a[i]=='/')){
            top=pop(top,&pop1);
            top=pop(top,&pop2);
            value=tinh(pop1,pop2,a[i]);
            top=push(top,value);
        }
    }
    printf("Gia tri cua bieu thuc la %d",value);
    break;}
    case '1':{
        printf("Nhap infix  : \n");
        fflush(stdin);
        gets(a);
        for(i=0;i<=strlen(a);i++){
            if((a[i]==')')){
                top=pop(top,&value);
                printf("%c",value);
            }
            if ((a[i] >= '0') && (a[i] <= '9'))printf("%c", a[i]);
            if ((a[i] == '+') || (a[i] == '*')||(a[i] == '-') ||(a[i] == '/'))top=push(top,a[i]);
        }
        while (top!=NULL)
        {
            top=pop(top,&value);
            printf("%c",value);
        }
        break;
            
    }
        }
    }while(ch!='k');
    return 0;
}
