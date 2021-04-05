#include "LinkStack.h"

int menu(void){//菜单界面
    int a;
    system("cls");
    printf("***************************************\n");
    printf("************ 请输入对应序号 ***********\n");
    printf("***************************************\n");
    printf("1----------初始化栈\n");
    printf("2----------入栈\n");
    printf("3----------出栈\n");
    printf("4----------判断是否为空\n");
    printf("5----------检测长度\n");
    printf("6----------得到栈顶元素\n");
    printf("7----------清空栈\n");
    printf("8----------销毁栈\n");
    printf("0----------结束程序\n");
    printf("***************************************\n");
    printf("输入的序号为:");
    scanf("%d`",&a);
    return a;
}

void pau(void){//暂停操作
    system("pause");
    system("cls");
}

Status initLStack(LinkStack *s){
    s->count=0;
    s->top=NULL;
    printf("初始化完成\n");
    return SUCCESS;
}


/************************************************
  s（LinkStack *）
  ↓
 top(StackNode *)→next→。。。→NULL
 ************************************************/
Status pushLStack(LinkStack *s,ElemType data){//入栈
    StackNode *p=s->top;
    s->count++;
    s->top=(StackNode *)malloc(sizeof(StackNode));
    s->top->data=data;
    s->top->next=p;
    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){//出栈
    if(s->top==NULL) return ERROR;
    StackNode *p=s->top;
    *data=s->top->data;
    s->count--;
    s->top=s->top->next;
    free(p);//释放
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){//判断栈是否为空
    if(s->count==0){
        printf("栈为空\n");
        return SUCCESS;
    }else{
        printf("栈不为空\n输出为:");
        StackNode *p=s->top;
        for(;p!=NULL;p=p->next){
            printf("%d ",p->data);
        }printf("\n");
        return SUCCESS;
    }
}

Status getTopLStack(LinkStack *s,ElemType *e) { //得到栈顶元素
    if(s->top==NULL) return ERROR;
    *e=s->top->data;
    return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length){//检测栈长度
    *length=s->count;
    return SUCCESS;
}

Status clearLStack(LinkStack *s) { //清空栈
    StackNode *p=s->top;
    for(;p!=NULL;){
        s->top=s->top->next;
        free(p);
        p=s->top;
    }s->count=0;
    return SUCCESS;
}

Status destroyLStack(LinkStack *s) { //销毁栈
    if(clearLStack(s)==SUCCESS)
        free(s);
    return SUCCESS;
}
