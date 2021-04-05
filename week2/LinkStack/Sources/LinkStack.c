#include "LinkStack.h"

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
    scanf("%d`",&a);
    return a;
}

void pau(void){//��ͣ����
    system("pause");
    system("cls");
}

Status initLStack(LinkStack *s){
    s->count=0;
    s->top=NULL;
    printf("��ʼ�����\n");
    return SUCCESS;
}


/************************************************
  s��LinkStack *��
  ��
 top(StackNode *)��next����������NULL
 ************************************************/
Status pushLStack(LinkStack *s,ElemType data){//��ջ
    StackNode *p=s->top;
    s->count++;
    s->top=(StackNode *)malloc(sizeof(StackNode));
    s->top->data=data;
    s->top->next=p;
    return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){//��ջ
    if(s->top==NULL) return ERROR;
    StackNode *p=s->top;
    *data=s->top->data;
    s->count--;
    s->top=s->top->next;
    free(p);//�ͷ�
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){//�ж�ջ�Ƿ�Ϊ��
    if(s->count==0){
        printf("ջΪ��\n");
        return SUCCESS;
    }else{
        printf("ջ��Ϊ��\n���Ϊ:");
        StackNode *p=s->top;
        for(;p!=NULL;p=p->next){
            printf("%d ",p->data);
        }printf("\n");
        return SUCCESS;
    }
}

Status getTopLStack(LinkStack *s,ElemType *e) { //�õ�ջ��Ԫ��
    if(s->top==NULL) return ERROR;
    *e=s->top->data;
    return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length){//���ջ����
    *length=s->count;
    return SUCCESS;
}

Status clearLStack(LinkStack *s) { //���ջ
    StackNode *p=s->top;
    for(;p!=NULL;){
        s->top=s->top->next;
        free(p);
        p=s->top;
    }s->count=0;
    return SUCCESS;
}

Status destroyLStack(LinkStack *s) { //����ջ
    if(clearLStack(s)==SUCCESS)
        free(s);
    return SUCCESS;
}
