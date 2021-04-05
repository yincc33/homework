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
    printf("************ 请输入对应序号 ***********\n");
    printf("***************************************\n");
    printf("0----------结束程序\n");
    printf("1----------初始化链表\n");
    printf("2----------创建链表\n");
    printf("3----------输出链表\n");
    printf("4----------删除链表\n");
    printf("5----------在元素后插入一个节点\n");
    printf("6----------在元素前插入一个节点\n");
    printf("***************************************\n");
    printf("输入的序号为:");
    scanf("%d",&a);
    return a;
}


void pau(void){//暂停操作
    system("pause");
    system("cls");
}

Status CreateDuL(DuLinkedList *L,int n){
    int temp,data;
    DuLinkedList head,p1,p2;
    head=(DuLNode *)malloc(sizeof(DuLNode));
    printf("请输入第 1 个链表储存的数据:");
    scanf("%d",&data);
    p1=head;
    head->prior=NULL;
    p1->data=data;
    p2=(DuLNode *)malloc(sizeof(DuLNode));
    p1->next=p2;
    printf("请输入第 2 个链表储存的数据:");
    scanf("%d",&data);
    p2->data=data;
    p2->prior=p1;//先让前两个节点互连
    p2->next=NULL;
    if(n>2){
        for(temp=2;temp<n;temp++){
            p1=p2;
            p2=(DuLNode *)malloc(sizeof(DuLNode));
            printf("请输入第 %d 个链表储存的数据:",temp+1);
            scanf("%d",&data);
            p1->next=p2;
            p2->prior=p1;
            p2->data=data;
            p2->next=NULL;
        }
    }
    (*L)->next=head;//初始化节点的next指向头结点
    (*L)->prior=p2;//初始化节点的prior指向尾结点
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
            return NULL;//节点不存在的判断
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
        length++;//长度加1
        return SUCCESS;
    } else if (p->prior == NULL) {//节点在开头时初始化节点也需要改变
        p->prior = q;
        q->prior = NULL;
        q->next = p;
        (*L)->next = q;
        length++;//长度加1
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
        length++;//长度加1
        return SUCCESS;
    } else if(p->next==NULL){//节点在末尾时初始化节点也需要改变
        p->next=q;
        q->prior=p;
        q->next=NULL;
        (*L)->prior=q;
        length++;//长度加1
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
Status PrintDuList(DuLinkedList *L){//输出函数
    DuLinkedList posi,neg;
    posi=(*L)->next;
    neg=(*L)->prior;
    printf("正向输出:\n");
    for(;posi!=NULL;posi=posi->next){
        printf("%d ",posi->data);
    }
    printf("\n负向输出:\n");
    for(;neg!=NULL;neg=neg->prior){
        printf("%d ",neg->data);
    }
    return SUCCESS;
}





void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {

}
