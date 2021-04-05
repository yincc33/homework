#include "linkedList.h"

int main(void){
    int num,p=0,length;//length为链表长度
    LinkedList L,tem;
    while(1){
        switch(num=menu()) {//输出菜单
            if(num<0||num>6)
                num=10;
            case(0)://退出程序
                return 0;
            case (1)://初始化
                system("cls");//清屏
                if (InitList(&L) == SUCCESS) {
                    printf("初始化完成\n");
                    pau();
                } else {
                    printf("初始化失败\n");
                    pau();
                }
                break;
            case (2)://创建链表
                system("cls");
                printf("请输入要创建的链表长度:");
                scanf("%d", &length);
                if (CreatList(&L, length) == SUCCESS) {
                    printf("创建链表完成\n");
                    pau();
                }else{
                    printf("创建链表失败\n");
                    pau();
                }break;
            case(3)://输出
                system("cls");
                if(L==NULL){
                    printf("输出失败\n");
                    pau();
                }
                else if(PrintList(&L) == SUCCESS){
                    printf("\n输出完成");
                    pau();
                }
                break;
            case(4)://删除
                system("cls");
                DestroyList(&L);
                printf("链表已被删除\n");
                pau();
                break;
            case(5)://是否成环
                system("cls");
                if(IsLoopList(L)==SUCCESS)
                    printf("链表没有成环\n");
                else if(IsLoopList(L)==ERROR)
                    printf("链表成环\n");
                pau();
                break;
            case(6)://中间节点
                system("cls");
                tem=FindMidNode(&L);
                printf("中间节点为:");
                if(length%2==1)
                    printf("%d\n",tem->next->data);
                else if(length%2==0)
                    printf("%d %d\n",tem->next->data,tem->next->next->data);
                pau();
                break;
            case(7)://倒转
                system("cls");
                if(ReverseList(&L)==SUCCESS)
                    printf("反转完成\n");
                pau();
                break;
            case(8)://奇偶调换
                system("cls");
                L=ReverseEvenList(&L);
                printf("奇偶调换完成\n");
                pau();
                break;
            default:
                system("cls");
                printf("输入错误\n请重新运行程序\n");//防止乱输入
                pau();
                return 0;
        }


        }
    }


