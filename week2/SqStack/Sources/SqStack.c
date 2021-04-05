#include "SqStack.h"

int menu(void){//�˵�����
    int a;
    system("cls");
    printf("***************************************\n");
    printf("************ �������Ӧ��� ***********\n");
    printf("***************************************\n");
    printf("1----------��ʼ��ջ\n");
    printf("2----------��ջ\n");
    printf("3----------��ջ\n");
    printf("4----------�ж��Ƿ�Ϊ��\n");
    printf("5----------��ⳤ��\n");
    printf("6----------�õ�ջ��Ԫ��\n");
    printf("7----------���ջ\n");
    printf("8----------����ջ\n");
    printf("0----------��������\n");
    printf("***************************************\n");
    printf("��������Ϊ:");
    scanf("%d",&a);
    return a;
}

void pau(void){//��ͣ����
    system("pause");
    system("cls");
}

Status initStack(SqStack *s,int sizes){
    s->elem=(int *)malloc(sizeof(int[sizes]));
    if(!s->elem)     return ERROR;
    s->top=s->elem;//top��ʼΪbase����ջ
    s->size=sizes;
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data){//��ջ
    if(s->top-s->elem==s->size) return ERROR;//�ﵽ���
    if(s->top==s->elem&&s->top==0){
        *(s->top)=data;
    }
    else{
        (s->top)++;
        *(s->top)=data;
    }
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data){//��ջ
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
        printf("ջΪ��\n");
    else{
        ElemType *t;
        t=s->top;
        printf("ջ��Ϊ��\n�洢��Ԫ��Ϊ:");
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
Status getTopStack(SqStack *s,ElemType *e) {  //�õ�ջ��Ԫ��
    if(s->top!=s->elem){
        e=s->top;
        return SUCCESS;
    }
    else
        return ERROR;
}

Status clearStack(SqStack *s){//���ջ
    for(;s->top!=s->elem;){
        *(s->top)=0;
        (s->top)--;
    }return SUCCESS;
}

Status destroyStack(SqStack *s){//����ջ
    int i=0;
    for(;i<s->size;i++,s->elem++){
        free(s->elem);
        return SUCCESS;
    }
}

Status stackLength(SqStack *s,int *length){//���ջ����
    if(s->top==s->elem){
        *length=0;
        return SUCCESS;
    }
    *length=s->top-s->elem;
    return SUCCESS;
}