#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* Next;
}Node;
typedef struct
{
    Node* Front;
    Node* Rear;
}Queue;
Queue* MakeNullQueue(Queue *Q){
    Node* Header;
    Header=(Node*)malloc(sizeof(Node));
    Header->Next=NULL;
    Q->Front=Header;
    Q->Rear=Header;
    return Q;
}
int EmptyQueue(Queue* Q){
    return (Q->Front==Q->Rear);
}
Queue* EnQueue(int X, Queue *Q){
    Q->Rear->Next=(Node*)malloc(sizeof(Node));
    Q->Rear=Q->Rear->Next;
    Q->Rear->data=X;
    Q->Rear->Next=NULL;
    return Q;
}
Queue* DeQueue(Queue *Q){
    if (!EmptyQueue(Q)){
        Node* T;
        T=Q->Front;
        Q->Front=Q->Front->Next;
        free(T);
        return Q;
    }
    else {
        printf( "Error: Queue is empty. ");
        return Q;}
}
int main(){
    int k;
    Queue* Q;
    int dem=0;
    Q=MakeNullQueue(Q);
    while(1){
        fflush(stdin);
        scanf("%d",&k);
        while(dem==10){
            printf("%d",Q->Front->data);
            DeQueue(Q);
            EnQueue(k,Q);
        }
        EnQueue(k,Q);
        dem++;
    }
}
