#include "LinkStack.h"

int main(){
    LinkStack Ls;
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
                }system("cls");
                initLStack(&Ls);
                pau();
                f=1;
                break;
            case(2)://��ջ
                if(f==0){
                    system("cls");
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }system("cls");
                printf("������Ҫ��ջ������:");
                scanf("%d",&a);
                if(pushLStack(&Ls,a)==SUCCESS)
                    printf(("��ջ�ɹ�\n"));
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
                if(popLStack(&Ls,&a)==SUCCESS){
                    printf("��ջ�ɹ�\n����Ϊ:%d\n",a);
                }else if(popLStack(&Ls,&a)==ERROR){
                    printf("ջΪ��\n");
                }pau();
                break;
            case(4)://�ж�ջ�Ƿ�Ϊ��
                if(f==0){
                    system("cls");
                    printf("δ��ʼ��\n");
                    pau();
                    break;
                }system("cls");
                if(isEmptyLStack(&Ls)==SUCCESS)
                    pau();
                break;
            case(5)://���ջ����
                system("cls");
                if(f!=1){
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }
                if(LStackLength(&Ls,&a)==SUCCESS){
                    printf("����Ϊ:%d\n",a);
                }pau();
                break;
            case(6)://�õ�ջ��Ԫ��
                system("cls");
                if(f!=1){
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }if(getTopLStack(&Ls,&a)==SUCCESS){
                    printf("ջ��Ԫ��Ϊ:%d\n",a);
                }else if(getTopLStack(&Ls,&a)==ERROR){
                    printf("ջΪ��\n");
                } pau();
                break;
            case(7)://���
                system("cls");
                if(f!=1){
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }if(clearLStack(&Ls)==SUCCESS){
                    printf("ջ�����\n");
                }pau();
                break;
            case(8)://����
                system("cls");
                if(f!=1){
                    printf("���ȳ�ʼ��\n");
                    pau();
                    break;
                }if(destroyLStack(&Ls)==SUCCESS){
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