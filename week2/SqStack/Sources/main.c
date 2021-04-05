#include "SqStack.h"

int main(){
    SqStack sq;
    int num=0,f=0;
    ElemType a=0;
    while(1){
        setbuf(stdout,NULL);
        switch (num=menu()) {
            case(1)://初始化
                if(f!=0){
                    system("cls");
                    printf("请勿重复初始化\n");
                    pau();
                    break;
                }
                system("cls");
                printf("请输入栈的最大容量:");
                scanf("%d",&max);
                if (initStack(&sq,max)==SUCCESS)
                    printf("初始化成功\n");
                else
                    printf("初始化失败\n");
                f=1;
                pau();
                break;
            case(2)://入栈
                if(f==0){
                    system("cls");
                    printf("请先初始化\n");
                    pau();
                    break;
                }
                system("cls");
                printf("请输入要入栈的数据:");
                scanf("%d",&a);
                if(pushStack(&sq,a)==SUCCESS)
                    printf(("入栈成功\n"));
                else
                    printf("入栈失败,栈已满\n");
                pau();
                break;
            case(3)://出栈
                if(f==0){
                    system("cls");
                    printf("请先初始化\n");
                    pau();
                    break;
                }
                system("cls");
                if(popStack(&sq,&a)==SUCCESS){
                    printf("出栈成功\n数据为:%d\n",a);
                }else if(popStack(&sq,&num)==ERROR){
                    printf("栈为空\n");
                }pau();
                break;
            case(4)://判断栈是否为空
                if(f==0){
                    system("cls");
                    printf("请先初始化\n");
                    pau();
                    break;
                }
                system("cls");
                if(isEmptyStack(&sq)==SUCCESS)
                    pau();
                break;
            case(5)://检测栈长度
                system("cls");
                if(f!=1){
                    printf("请先初始化\n");
                    pau();
                    break;
                }
                if(stackLength(&sq,&a)==SUCCESS){
                    printf("长度为:%d\n",a);
                }pau();
                break;
            case(6)://得到栈顶元素
                system("cls");
                if(f!=1){
                    printf("请先初始化\n");
                    pau();
                    break;
                }
                if(getTopStack(&sq,&a)==SUCCESS){
                    printf("栈顶元素为:%d\n",a);
                }pau();
                break;
            case(7)://清空
                system("cls");
                if(f!=1){
                    printf("请先初始化\n");
                    pau();
                    break;
                }
                if(clearStack(&sq)==SUCCESS){
                    printf("栈已清空\n");
                }pau();
                break;
            case(8)://清空
                system("cls");
                if(f!=1){
                    printf("请先初始化\n");
                    pau();
                    break;
                }
                if(destroyStack(&sq)==SUCCESS){
                    printf("栈已销毁\n");
                    f=0;
                }pau();
                break;
            case (0):
                return 0;
            default:
                system("cls");
                printf("输入错误\n请重新运行程序\n");//防止乱输入
                pau();
                return 0;
        }
    }
}

