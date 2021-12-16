#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char id[30];
    char name[30];
    int grade;
}student;
typedef struct student_t
{
    student data;
    struct student_t *next;
}node;
node* head;
node* add_student(node* head,student A){
    node* news;
    news=(node*)malloc(sizeof(node));
    news->data=A;
    news->next=NULL;
    if(head==NULL){
        head=news;
        return head;
    }
    if(A.grade>head->data.grade){
        news->next=head;
        head=news;
        return head;
    }
    else{
        node* cur;
        cur=head;
        while(cur->data.grade>news->data.grade){
            cur=cur->next;
        }
        node* prev;
        prev=head;
        while(prev->next!=cur)prev=prev->next;
        news->next=cur;
        prev->next=news;
        return head;
    }
}
void Print(node* head);
node * find_id(node* head,char a[30]){
    node* cur;
    cur=head;
    if(strcmp(a,head->data.id)==0){
        printf("tim thay\n");
        printf("%s - %s - %d \n",head->data.name,head->data.id,head->data.grade);
        return cur;
    }
    else{
        for(;cur!=NULL;cur=cur->next){
        if(strcmp(a,cur->data.id)==0){
            printf("Tim thay \n");
            printf("%s - %s - %d \n",cur->data.name,cur->data.id,cur->data.grade);
            return cur;
        }
    }
    }
    printf("Khong tim thay \n");
    return NULL;
}
node* delete_id(node* head,char a[30]){
    node* cur;
    cur=head;
    if(head==NULL){
        return head;
    }
    if(strcmp(head->data.id,a)==0){
        node* cur;
        cur=head;
        head=head->next;
        free(cur);
        return head;
    }
    else{
        for(;cur!=NULL;cur=cur->next){
        if(strcmp(a,cur->data.id)==0){
            printf("Xoa thanh cong \n");
            node* prev;
            prev=head;
            while(prev->next!=cur)prev=prev->next;
            prev->next=cur->next;
            free(cur);
            return head;
        }
    }
    printf("Khong tim thay \n");
    return head;}
}
node* change_grade(node* head,char id[30],int new_grade){
    node* cur;
    cur=find_id(head,id);
    if(cur==NULL)return head;
    else{
    node* news;
    news=(node*)malloc(sizeof(node));
    strcpy(news->data.id,id);
    strcpy(news->data.name,cur->data.name);
    news->data.grade=new_grade;
    delete_id(head,id);
    head=add_student(head,news->data);
    return head;}
}
void Print(node* head){
    node* news;
    news=head;
    while(news!=NULL){
        printf("%s - %s - %d \n",news->data.name,news->data.id,news->data.grade);
        news=news->next;
    }
}
void giaodien()
{
   printf("=============================================\n");
   printf("1. Them sinh vien\n");	
   printf("2. Tim sinh vien\n");
   printf("3. Xoa sinh vien\n");
   printf("4. Thay doi diem\n");		
   printf("5. In danh sach \n");
   printf("=============================================\n"); 	
}
int main(){
    node* cur;
    head=NULL;
    int n,i=1;
    student A;
    printf("Nhap so sinh vien: ");scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("sinh vien thu %d: \n",i);
        printf("Name: ");fflush(stdin);gets(A.name);
        printf("Id: ");fflush(stdin);gets(A.id);
        printf("Grade: ");fflush(stdin);scanf("%d",&A.grade);
        head=add_student(head,A);
    }
    char ch;
	do{
		giaodien();
		printf("Nhan so cau [1..5] de tiep tuc hoac phim 'k' de ket thuc: ");
		fflush(stdin);
		scanf("%c",&ch);
		switch(ch){
			case '1':{
				printf("Nhap thong tin sinh vien muon them \n");
				printf("Name: ");fflush(stdin);gets(A.name);
                printf("Id: ");fflush(stdin);gets(A.id);
                printf(":Grade ");fflush(stdin);scanf("%d",&A.grade);
                head=add_student(head,A);
                break;
			}
			case '2':{
				printf("Nhap id sinh vien muon tim :");fflush(stdin);
                gets(A.id);
                find_id(head,A.id);
				break;
			}
			case '3':{
				printf("Nhap id sinh vien muon xoa ");fflush(stdin);
                gets(A.id);
                head=delete_id(head,A.id);
				break;
			}
			case '4':{
				printf("Nhap id sinh vien muon thay doi diem ");fflush(stdin);gets(A.id);
                printf("Nhap diem muon thay doi thanh ");fflush(stdin);scanf("%d",&A.grade);
                head=change_grade(head,A.id,A.grade);
				break;
			}
			case '5':{
				Print(head);
				break;
			}
		}
	}while(ch!='k');
	return 0;

}

