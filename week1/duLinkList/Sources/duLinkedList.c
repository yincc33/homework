#include "duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    (*L)=(DuLinkedList)malloc(sizeof (DuLNode));
    (*L)->next=NULL;
    (*L)->prior=NULL;
    return SUCCESS;
}

int menu(void){
    int a;
    system("cls");
    printf("***************************************\n");
    printf("************ �������Ӧ��� ***********\n");
    printf("***************************************\n");
    printf("0----------��������\n");
    printf("1----------��ʼ������\n");
    printf("2----------��������\n");
    printf("3----------�������\n");
    printf("4----------ɾ������\n");
    printf("5----------��Ԫ�غ����һ���ڵ�\n");
    printf("6----------��Ԫ��ǰ����һ���ڵ�\n");
    printf("***************************************\n");
    printf("��������Ϊ:");
    scanf("%d",&a);
    return a;
}


void pau(void){//��ͣ����
    system("pause");
    system("cls");
}

Status CreateDuL(DuLinkedList *L,int n){
    int temp,data;
    DuLinkedList head,p1,p2;
    head=(DuLNode *)malloc(sizeof(DuLNode));
    printf("������� 1 �������������:");
    scanf("%d",&data);
    p1=head;
    head->prior=NULL;
    p1->data=data;
    p2=(DuLNode *)malloc(sizeof(DuLNode));
    p1->next=p2;
    printf("������� 2 �������������:");
    scanf("%d",&data);
    p2->data=data;
    p2->prior=p1;//����ǰ�����ڵ㻥��
    p2->next=NULL;
    if(n>2){
        for(temp=2;temp<n;temp++){
            p1=p2;
            p2=(DuLNode *)malloc(sizeof(DuLNode));
            printf("������� %d �������������:",temp+1);
            scanf("%d",&data);
            p1->next=p2;
            p2->prior=p1;
            p2->data=data;
            p2->next=NULL;
        }
    }
    (*L)->next=head;//��ʼ���ڵ��nextָ��ͷ���
    (*L)->prior=p2;//��ʼ���ڵ��priorָ��β���
    return SUCCESS;
}

DuLinkedList SearchNode(DuLinkedList *L,ElemType a){
    DuLinkedList temp=(*L)->next;
    for(;;){
        if(temp->data==a)
        {
            return temp;
        }
        else if (temp->next==NULL){
            return NULL;//�ڵ㲻���ڵ��ж�
        }
        temp=temp->next;
    }
}


/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList head,p;
    head=(*L);
    p=(*L);
    for(;head!=NULL;){
        head=p->next;
        free(p);
        p=head;
    }
    (*L)=NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q,DuLinkedList *L) {
    DuLNode *temp;
    if (p->prior != NULL) {
        temp = p->prior;
        p->prior = q;
        q->prior = temp;
        q->next = p;
        temp->next = q;
        length++;//���ȼ�1
        return SUCCESS;
    } else if (p->prior == NULL) {//�ڵ��ڿ�ͷʱ��ʼ���ڵ�Ҳ��Ҫ�ı�
        p->prior = q;
        q->prior = NULL;
        q->next = p;
        (*L)->next = q;
        length++;//���ȼ�1
        return SUCCESS;
    }
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p,DuLNode *q,DuLinkedList *L) {
    DuLNode *temp;
    if(p->next!=NULL){
        temp=p->next;
        p->next=q;
        q->prior=p;
        q->next=temp;
        temp->prior=q;
        length++;//���ȼ�1
        return SUCCESS;
    } else if(p->next==NULL){//�ڵ���ĩβʱ��ʼ���ڵ�Ҳ��Ҫ�ı�
        p->next=q;
        q->prior=p;
        q->next=NULL;
        (*L)->prior=q;
        length++;//���ȼ�1
        return SUCCESS;
    }

}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
Status PrintDuList(DuLinkedList *L){//�������
    DuLinkedList posi,neg;
    posi=(*L)->next;
    neg=(*L)->prior;
    printf("�������:\n");
    for(;posi!=NULL;posi=posi->next){
        printf("%d ",posi->data);
    }
    printf("\n�������:\n");
    for(;neg!=NULL;neg=neg->prior){
        printf("%d ",neg->data);
    }
    return SUCCESS;
}





void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {

}
