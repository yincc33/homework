#include "linkedList.h"

int main(void){
    int num,p=0,length;//lengthΪ������
    LinkedList L,tem;
    while(1){
        switch(num=menu()) {//����˵�
            if(num<0||num>6)
                num=10;
            case(0)://�˳�����
                return 0;
            case (1)://��ʼ��
                system("cls");//����
                if (InitList(&L) == SUCCESS) {
                    printf("��ʼ�����\n");
                    pau();
                } else {
                    printf("��ʼ��ʧ��\n");
                    pau();
                }
                break;
            case (2)://��������
                system("cls");
                printf("������Ҫ������������:");
                scanf("%d", &length);
                if (CreatList(&L, length) == SUCCESS) {
                    printf("�����������\n");
                    pau();
                }else{
                    printf("��������ʧ��\n");
                    pau();
                }break;
            case(3)://���
                system("cls");
                if(L==NULL){
                    printf("���ʧ��\n");
                    pau();
                }
                else if(PrintList(&L) == SUCCESS){
                    printf("\n������");
                    pau();
                }
                break;
            case(4)://ɾ��
                system("cls");
                DestroyList(&L);
                printf("�����ѱ�ɾ��\n");
                pau();
                break;
            case(5)://�Ƿ�ɻ�
                system("cls");
                if(IsLoopList(L)==SUCCESS)
                    printf("����û�гɻ�\n");
                else if(IsLoopList(L)==ERROR)
                    printf("����ɻ�\n");
                pau();
                break;
            case(6)://�м�ڵ�
                system("cls");
                tem=FindMidNode(&L);
                printf("�м�ڵ�Ϊ:");
                if(length%2==1)
                    printf("%d\n",tem->next->data);
                else if(length%2==0)
                    printf("%d %d\n",tem->next->data,tem->next->next->data);
                pau();
                break;
            case(7)://��ת
                system("cls");
                if(ReverseList(&L)==SUCCESS)
                    printf("��ת���\n");
                pau();
                break;
            case(8)://��ż����
                system("cls");
                L=ReverseEvenList(&L);
                printf("��ż�������\n");
                pau();
                break;
            default:
                system("cls");
                printf("�������\n���������г���\n");//��ֹ������
                pau();
                return 0;
        }


        }
    }


