#include "duLinkedList.h"

int main(){
    int num,p,q;
    DuLinkedList L,PN,PT;
    while(1){
        switch(num=menu()){//����˵�
            if(num<0||num>6)
                num=10;
            case (0)://�˳�����
                return 0;
            case(1):
                system("cls");//����
                if(InitList_DuL(&L)==SUCCESS)
                    printf("��ʼ�����\n");
                else {
                    printf("��ʼ��ʧ��\n");
                }
                 pau();
                break;
            case(2):
                system("cls");
                printf("������Ҫ������������(���ڵ���2):");//�����޷���Ϊ˫��
                scanf("%d", &length);
                if(length<2){
                    printf("�������\n");
                    pau();
                    break;
                }
                else if (CreateDuL(&L, length) == SUCCESS) {
                    printf("�����������\n");
                    pau();
                }else{
                    printf("��������ʧ��\n");
                    pau();
                }break;
            case(3):
                system("cls");
                if(L==NULL){
                    printf("���ʧ��\n");
                    pau();
                }
                else if(PrintDuList(&L) == SUCCESS){
                    printf("\n������");
                    pau();
                }
                break;
            case(4):
                system("cls");
                DestroyList_DuL(&L);
                printf("�����ѱ�ɾ��\n");
                pau();
                break;
            case(5):
                system("cls");
                printf("������Ҫ���������:");
                scanf("%d",&p);
                printf("������ǰһλ������:");
                scanf("%d",&q);
                PN=(DuLNode *)malloc(sizeof(DuLNode));//�½ڵ�
                PN->data=p;
                PT=SearchNode(&L,q);//���ҽڵ�λ��
                if(InsertAfterList_DuL(PT,PN,&L)==SUCCESS)//���뺯��
                    printf("����ɹ�");
                pau();
                break;
            case(6)://��������
                system("cls");
                printf("������Ҫ���������:");
                scanf("%d",&p);
                printf("�������һλ������:");
                scanf("%d",&q);
                PN=(DuLNode *)malloc(sizeof(DuLNode));
                PN->data=p;
                PT=SearchNode(&L,q);
                if(InsertBeforeList_DuL(PT,PN,&L)==SUCCESS)
                    printf("����ɹ�");
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