#include "SqStack.h"

int main(){
    SqStack sq;
    int num=0,f=0;
    ElemType a=0;
    while(1){
        setbuf(stdout,NULL);
        switch (num=menu()) {
            case(1)://��ʼ��
                if(f!=0){
                    system("cls");
                    printf("�����ظ���ʼ��\n");
                    pau();
                    break;
                }
                system("cls");
                printf("������ջ���������:");
                scanf("%d",&max);
                if (initStack(&sq,max)==SUCCESS)
                    printf("��ʼ���ɹ�\n");
                else
                    printf("��ʼ��ʧ��\n");
                f=1;
                pau();
                break;
            case(2)://��ջ
                if(f==0){
                    system("cls");
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }
                system("cls");
                printf("������Ҫ��ջ������:");
                scanf("%d",&a);
                if(pushStack(&sq,a)==SUCCESS)
                    printf(("��ջ�ɹ�\n"));
                else
                    printf("��ջʧ��,ջ����\n");
                pau();
                break;
            case(3)://��ջ
                if(f==0){
                    system("cls");
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }
                system("cls");
                if(popStack(&sq,&a)==SUCCESS){
                    printf("��ջ�ɹ�\n����Ϊ:%d\n",a);
                }else if(popStack(&sq,&num)==ERROR){
                    printf("ջΪ��\n");
                }pau();
                break;
            case(4)://�ж�ջ�Ƿ�Ϊ��
                if(f==0){
                    system("cls");
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }
                system("cls");
                if(isEmptyStack(&sq)==SUCCESS)
                    pau();
                break;
            case(5)://���ջ����
                system("cls");
                if(f!=1){
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }
                if(stackLength(&sq,&a)==SUCCESS){
                    printf("����Ϊ:%d\n",a);
                }pau();
                break;
            case(6)://�õ�ջ��Ԫ��
                system("cls");
                if(f!=1){
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }
                if(getTopStack(&sq,&a)==SUCCESS){
                    printf("ջ��Ԫ��Ϊ:%d\n",a);
                }pau();
                break;
            case(7)://���
                system("cls");
                if(f!=1){
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }
                if(clearStack(&sq)==SUCCESS){
                    printf("ջ�����\n");
                }pau();
                break;
            case(8)://���
                system("cls");
                if(f!=1){
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }
                if(destroyStack(&sq)==SUCCESS){
                    printf("ջ������\n");
                    f=0;
                }pau();
                break;
            case (0):
                return 0;
            default:
                system("cls");
                printf("�������\n���������г���\n");//��ֹ������
                pau();
                return 0;
        }
    }
}

