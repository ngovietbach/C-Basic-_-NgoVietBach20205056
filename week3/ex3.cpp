#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
    int number;
    struct Node* next;
    struct Node* prev;    
}Node;
Node* head,*tail;
void remove_node(Node* p){
    if(p->next==NULL)tail=p->prev;
    else p->next->prev=p->prev;
    if(p->prev==NULL)head=p->next;
    else p->prev->next=p->next;
}
void insert_node(Node*lnode,Node*after){
    lnode->next=after->next;
    lnode->prev=after;
    if(after->next!=NULL)after->next->prev=lnode;
    else tail=lnode;
    after->next=lnode;
}
void appennd_node(Node *Lnode){
    if(head==NULL){
        head=Lnode;
        Lnode->prev=NULL;
    }
    else{
        tail->next=Lnode;
        Lnode->prev=tail;
    }
    tail=Lnode;
    Lnode->next=NULL;
}
int main(){
    Node *Lnode;int i=0;
    for(i=0;i<=5;i++){
        Lnode=(Node*)malloc(sizeof(Node));
        Lnode->number=i;
        appennd_node(Lnode);
        while(head!=NULL){
            remove_node(head);
        }
        return 0;
    }
}
