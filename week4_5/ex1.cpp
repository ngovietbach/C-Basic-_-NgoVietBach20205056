#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct StackNode
{
    char data;
    struct StackNode *next;
}Node;
Node* push(Node* top,char value){
    Node* temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=value;
    temp->next=top;
    top=temp;
    return top;
}
Node* pop(Node* top){
    Node* temp;
    char value;
    if(top==NULL){
        printf("Stack empty\n");
        return top;
    }
    else{
        value=top->data;
        temp=top;
        top=top->next;
        free(temp);
        printf("%c",value);
        return top;
    }
}
int stack_empty(Node* top){
    return(top==NULL);
}
void giaodien()
{
   printf("=============================================\n");
   printf("1. push\n");	
   printf("2. pop only top\n");
   printf("3. pop all\n");
   printf("An k de thoat\n");
   printf("=============================================\n"); 	
}
int main(){
    char ch;
    Node* top=NULL;
    do{
        giaodien();
        printf("Chon [1...4] hoac k ");
        fflush(stdin);
        scanf("%c",&ch);
        switch (ch){
            case '1':{
                char g;
                printf("Nhap vao chuoi muon push: \n");
                fflush(stdin);
                for(;(g=getchar())!='\n';){
                    top=push(top,g);
                }
                break;
            }
            case '2':{
                top=pop(top);
                printf("\n");
                break;
            }
            case '3':{
                while(top!=NULL){
                    top=pop(top);
                }
                printf("\n");
                break;
            }
        }
    }while(ch!='k');
}



