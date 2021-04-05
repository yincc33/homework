#include "linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {//初始化
    (*L)=(LinkedList)malloc(sizeof (LNode));
    (*L)->next=NULL;
    return SUCCESS;
}

void pau(void){//暂停操作
    system("pause");
    system("cls");
}

int menu(void){//菜单界面
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
    printf("5----------判断链表是否成环\n");
    printf("6----------找到中间节点\n");
    printf("7----------反转链表\n");
    printf("8----------链表奇偶调换\n");
    printf("9----------插入一个节点\n");
    printf("***************************************\n");
    printf("输入的序号为:");
    scanf("%d",&a);
    return a;
}

Status CreatList(LinkedList *L,int n) {
    int temp,data;
    LinkedList head,node,end;
    head=(LNode *)malloc(sizeof(LNode));
    (*L)=head;
    end=head;
    for (temp = 0; temp < n; temp++) {//循环创建节点并连接
        printf("请输入第 %d 个链表储存的数据:",temp+1);
        scanf("%d",&data);
        node=(LNode *)malloc(sizeof(LNode));
        node->data=data;
        end->next=node;//连接
        end=node;
    }end->next=NULL;
    return SUCCESS;
}

Status PrintList(LinkedList *L){
    LinkedList temp;
    temp=(*L)->next;
    for(;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
    }
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList head,p;
    head=(*L);
    p=(*L);
    for(;head!=NULL;){//销毁第一个转到下一个再销毁做循环
        head=p->next;
        free(p);
        p=head;
    }
    (*L)=NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LinkedList p,pre,pn;
    pre=(*L)->next;
    p=(*L)->next->next;
    pre->next=NULL;
    pn=p->next;
    for(;p!=NULL;){
        p->next=pre;
        (*L)->next=p;
        pre=p;
        p=pn;
        if(pn!=NULL)
            pn=pn->next;
    }
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LinkedList fast,slow;
    fast=L->next;
    slow=L;
    for(;;){
        if(fast->next==NULL||fast->next->next==NULL)
            return SUCCESS;
        else if(fast==slow)
            return ERROR;
        fast=fast->next->next;
        slow=slow->next;
    }
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    LinkedList oddHeadPointer=(*L)->next;//单数头指针
    LinkedList oddPointer=NULL;//单数指针
    LinkedList evenPointer=NULL;//双数头指针
    LinkedList evenHeadPointer=(*L)->next->next;//双数头指针
    int temp=oddHeadPointer->data;
    oddHeadPointer->data=evenHeadPointer->data;
    evenHeadPointer->data=temp;//双数指针单数指针交换数据
    if(evenHeadPointer->next!=NULL&&//判断后面还有没有一对
        evenHeadPointer->next->next!=NULL){
            oddPointer=oddHeadPointer->next->next;
            evenPointer=evenHeadPointer->next->next;
    }
    else return *L;
    for(;;)
    {
        if(evenPointer->next!=NULL&&
           evenPointer->next->next!=NULL){
            temp=oddPointer->data;
            oddPointer->data=evenPointer->data;
            evenPointer->data=temp;
            oddPointer=oddPointer->next->next;
            evenPointer=evenPointer->next->next;
            continue;
        }
        else{
            temp=oddPointer->data;
            oddPointer->data=evenPointer->data;
            evenPointer->data=temp;
            return *L;
        }
    }

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LinkedList temp1,temp2;//快慢指针
    for(temp1=(*L),temp2=(*L)->next;;){
        if(temp2->next==NULL||temp2->next->next==NULL)//快指针到尾节点
            return temp1;
        temp1=temp1->next;
        temp2=temp2->next->next;
    }
}