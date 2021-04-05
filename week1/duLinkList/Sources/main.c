#include "duLinkedList.h"

int main(){
    int num,p,q;
    DuLinkedList L,PN,PT;
    while(1){
        switch(num=menu()){//输出菜单
            if(num<0||num>6)
                num=10;
            case (0)://退出程序
                return 0;
            case(1):
                system("cls");//清屏
                if(InitList_DuL(&L)==SUCCESS)
                    printf("初始化完成\n");
                else {
                    printf("初始化失败\n");
                }
                 pau();
                break;
            case(2):
                system("cls");
                printf("请输入要创建的链表长度(大于等于2):");//单个无法成为双链
                scanf("%d", &length);
                if(length<2){
                    printf("输入错误\n");
                    pau();
                    break;
                }
                else if (CreateDuL(&L, length) == SUCCESS) {
                    printf("创建链表完成\n");
                    pau();
                }else{
                    printf("创建链表失败\n");
                    pau();
                }break;
            case(3):
                system("cls");
                if(L==NULL){
                    printf("输出失败\n");
                    pau();
                }
                else if(PrintDuList(&L) == SUCCESS){
                    printf("\n输出完成");
                    pau();
                }
                break;
            case(4):
                system("cls");
                DestroyList_DuL(&L);
                printf("链表已被删除\n");
                pau();
                break;
            case(5):
                system("cls");
                printf("请输入要插入的数据:");
                scanf("%d",&p);
                printf("请输入前一位的数据:");
                scanf("%d",&q);
                PN=(DuLNode *)malloc(sizeof(DuLNode));//新节点
                PN->data=p;
                PT=SearchNode(&L,q);//查找节点位置
                if(InsertAfterList_DuL(PT,PN,&L)==SUCCESS)//插入函数
                    printf("插入成功");
                pau();
                break;
            case(6)://与上类似
                system("cls");
                printf("请输入要插入的数据:");
                scanf("%d",&p);
                printf("请输入后一位的数据:");
                scanf("%d",&q);
                PN=(DuLNode *)malloc(sizeof(DuLNode));
                PN->data=p;
                PT=SearchNode(&L,q);
                if(InsertBeforeList_DuL(PT,PN,&L)==SUCCESS)
                    printf("插入成功");
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