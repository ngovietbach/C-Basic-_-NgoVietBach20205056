#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_line 100
typedef struct StackNode
{
    char data[100];
    struct StackNode *next;
}Node;
Node* push(Node* top,char value[]){
    Node* temp;
    temp=(Node*)malloc(sizeof(Node));
    strcpy(temp->data,value);
    temp->next=top;
    top=temp;
    return top;
}
Node* pop(Node* top,FILE*output){
    Node* temp;
    char value[100];
    if(top==NULL){
        printf("Stack empty\n");
        return top;
    }
    else{
        strcpy(value,top->data);
        temp=top;
        top=top->next;
        free(temp);
        fprintf(output,"%s",value);
        return top;
    }
}
int stack_empty(Node* top){
    return(top==NULL);
}
int main(){
    Node* top=NULL;
    char s[100];
    FILE *input,*output;
    input=fopen("vanban.txt","r");
    if(input==NULL){
        printf("Mo file loi\n");
        return 0;
    }
    output=fopen("copy.txt","w");
    if(output==NULL){
        printf("Mo file loi\n");
        return 0;
    }
    while(fgets(s,max_line,input)!=NULL){
        top=push(top,s);
    }
    while (top!=NULL)
    {
        top=pop(top,output);
    }
    
    fclose(input);
    fclose(output);
}