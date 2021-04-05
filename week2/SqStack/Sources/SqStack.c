#include "SqStack.h"

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
    scanf("%d",&a);
    return a;
}

void pau(void){//暂停操作
    system("pause");
    system("cls");
}

Status initStack(SqStack *s,int sizes){
    s->elem=(int *)malloc(sizeof(int[sizes]));
    if(!s->elem)     return ERROR;
    s->top=s->elem;//top初始为base，空栈
    s->size=sizes;
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data){//入栈
    if(s->top-s->elem==s->size) return ERROR;//达到最大
    if(s->top==s->elem&&s->top==0){
        *(s->top)=data;
    }
    else{
        (s->top)++;
        *(s->top)=data;
    }
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data){//出栈
//    if(s->top-s->elem==0&&*(s->top)==0) return ERROR;
    if(s->top-s->elem==0) return ERROR;
    *data=*(s->top);
    *(s->top)=0;
    if(s->top==s->elem){
        return SUCCESS;
    }
    (s->top)--;
    return SUCCESS;
}

Status isEmptyStack(SqStack *s) {
//    if(s->top-s->elem==0&&*(s->top)==0)
    if(s->top-s->elem==0)
        printf("栈为空\n");
    else{
        ElemType *t;
        t=s->top;
        printf("栈不为空\n存储的元素为:");
        for(;;){
            if(t-s->elem!=0) {
                printf("%d ", *t);
                t--;
            }
            else if(t==s->elem) {
                printf("\n");
                break;
            }
        }
    }
    return SUCCESS;
}
Status getTopStack(SqStack *s,ElemType *e) {  //得到栈顶元素
    if(s->top!=s->elem){
        e=s->top;
        return SUCCESS;
    }
    else
        return ERROR;
}

Status clearStack(SqStack *s){//清空栈
    for(;s->top!=s->elem;){
        *(s->top)=0;
        (s->top)--;
    }return SUCCESS;
}

Status destroyStack(SqStack *s){//销毁栈
    int i=0;
    for(;i<s->size;i++,s->elem++){
        free(s->elem);
        return SUCCESS;
    }
}

Status stackLength(SqStack *s,int *length){//检测栈长度
    if(s->top==s->elem){
        *length=0;
        return SUCCESS;
    }
    *length=s->top-s->elem;
    return SUCCESS;
}