#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int max;

typedef enum Status
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack 
{
	ElemType *elem;//ջ��ָ��
	int *top;//ջ��ָ��
	int size;//���ô�С
} SqStack;

void pau(void);

int menu(void);
//���������˳��ջ
Status initStack(SqStack *s,int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s,ElemType *e); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack *s);//����ջ
Status stackLength(SqStack *s,int *length);//���ջ����
Status pushStack(SqStack *s,ElemType data);//��ջ
Status popStack(SqStack *s,ElemType *data);//��ջ


#endif 
