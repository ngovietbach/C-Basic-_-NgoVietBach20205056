#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
    {
        char name[30];
        char number[30];
        char email[30];
    }info;
typedef struct addressList
{
    info data;
    struct addressList* next;
}node;
node* insert_after(node *cur,node *head,info X){
    node *news;
    news=(node*)malloc(sizeof(node));
    news->data=X;news->next=NULL;
    if(head==NULL){
        head=news;
        cur=news;
        return head;
    }
    else{
        cur->next=news->next;
        cur->next=news;
        cur=news;
        return cur;
    }
}
node* insert_before(node *cur,node *head,info X){
    node *news;
    news=(node*)malloc(sizeof(node));
    news->data=X;news->next=NULL;
    if(head==NULL){
        head=news;
        cur=news;
        return head;
    }
    else{
        node* prev;
        prev=head;
        while(prev->next!=cur){
            prev=prev->next;
        }
        news->next=cur;
        prev->next=news;
        cur=news;
        return cur;
    }
}
void Print(node *head){
    node* news;
    news=head;
    while(news!=NULL){
        printf("%s-%s-%s\n",news->data.name,news->data.number,news->data.email);
        news=news->next;
    }
}
node* detelen(node* cur,node* head){
    if(cur==head){
        head=head->next;
       free(cur);
       return head;
    }
    else{
        node* prev;
        prev=head;
        while(prev->next!=cur){
            prev=prev->next;
        }
        prev->next=cur->next;
        free(cur);
        return head;
    }
}
void insert(node * head, info X, int n){
    int i=0;
    node *news;
    news=(node*)malloc(sizeof(node));
    news->data=X;news->next=NULL;
    node *cur;
    cur=head;
    while(i!=n){
        i++;
        cur=cur->next;
    }
    news->next=cur->next;
    cur->next=news;
    cur=news;
}
void deletej(node * head,int n){
    int i=0;
    node *cur;
    cur=head;
    while(i!=n){
        i++;
        cur=cur->next;
    }
    node *news;
    news=cur->next;
    cur->next=news->next;
    free(news);
}
node* makenull(node* head){
    node* news;
    news=head;
    while(news!=NULL){
        head=head->next;
        free(news);
        news=head;
    }
    return head;
}
node* reverse(node* head){
    node* cur,*prev;
    cur=prev=NULL;
    while(head!=NULL){
        cur=head;
        head=head->next;
        cur->next=prev;
        prev=cur;
    }
    return head;
}
int main(){
    int n;
    node *head,*cur;
    head=NULL;
    cur=NULL;
    info X;
    int i=1;
    printf("Nhap so nguoi co trong danh ba: ");scanf("%d",&n);
    printf("Nhap danh sach nguoi thu %d\n",i);
    printf("Name: ");fflush(stdin);gets(X.name);
    printf("Number: ");fflush(stdin);gets(X.number);
    printf("Email: ");fflush(stdin);gets(X.email);
    head=insert_after(cur,head,X);
    cur=head;
    for(i=2;i<=n;i++){
        printf("Nhap danh sach nguoi thu %d\n",i);
        printf("Name: ");fflush(stdin);gets(X.name);
        printf("Number: ");fflush(stdin);gets(X.number);
        printf("Email: ");fflush(stdin);gets(X.email);
        cur=insert_after(cur,head,X);
    }
    Print(head);
    printf("\n");
    int k;
    while(1){
        printf("1,Them vao vi tri sau so k \n");
        printf("2,Xoa vi tri sau so k \n");
        printf("3, Hien thi danh sach hien tai\n");
        printf("0,thoat ra \n");
        printf("chon chuc nang: "); 
        fflush(stdin);
        scanf("%d",&k);
        int j;
        if(k==1){
            printf("Nhap so : ");
            fflush(stdin);
            scanf("%d",&j);
            printf("nhap thong tin danh ba muon nhap vao \n");
            printf("Name: ");fflush(stdin);gets(X.name);
            printf("Number: ");fflush(stdin);gets(X.number);
            printf("Email: ");fflush(stdin);gets(X.email);
            insert(head,X,j);
            continue;
        }
        if(k==2){
            printf("Nhap so : ");
            fflush(stdin);
            scanf("%d",&j);
            deletej(head,j);
            continue;        
        }
        if(k==3){
            Print(head);
            continue;
        }
        if(k==0){
            break;
        }
    }
    return 0;
}


