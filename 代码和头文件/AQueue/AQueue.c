#include <stdio.h>
#include <stdlib.h>
#include"AQueue.h"


//初始化队列

void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)
        //不知道用户想放入的数据类型大小，所以给个20
        Q->data[i] = (void *)malloc(21);
	Q->front = Q->rear = 0;
}

void DestoryAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return;
    }
	for(int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
}

//判断为满

Status IsFullAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q))
        return FALSE;
    if(LengthAQueue(Q)==MAXQUEUE-1)
    {
        return TRUE;
    }
    else
        return FALSE;
}

//判断为空

Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
	return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}

//查看队头元素

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列为空！没有队头！\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front],20);
    return TRUE;
}

//获取队列长度

int LengthAQueue(AQueue *Q)
{
    return (Q->rear-Q->front+Q->length)%Q->length;
}

//入队

Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		printf("队列满了！不能再入队了！\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		memcpy(Q->data[Q->front], data, 20);
		Q->rear = (Q->rear + 1) % Q->length;
		return TRUE;
	}
    memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}

void InAQueue(AQueue *Q)
{
    int t;
    printf("你想入队哪种类型？:\n");
    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
    scanf("%d", &t);
    while(t<1 || t>4)
    {
     	printf("应输入在[1,4]之间的整数！\n请重输：");
      	scanf("%d", &t);
    }
	printf("想入队的数据 :");
    switch(t)
    {
    case 1:{
        int a;
        scanf("%d", &a);
        Q->type[Q->rear]=t;
        EnAQueue(Q, &a);
    break;
    }
    case 2:{
        char a;
        scanf("%s", &a);
        Q->type[Q->rear]=t;
        EnAQueue(Q, &a);
        break;
    }
    case 3:{
        double a ;
        scanf("%lf", &a);
        Q->type[Q->rear]=t;
        EnAQueue(Q, &a);
        break;
    }
    case 4:{
        char a[20];
        printf("最大长度为20哦！\n");
        scanf("%s", a);
        Q->type[Q->rear]=t;
        EnAQueue(Q, a);
        break;
    }
    }
}

//出队操作

Status DeAQueue(AQueue *Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列是空的！出不了队！\n");
        return FALSE;
    }
    Q->front = (Q->front+1)%Q->length;
    return TRUE;
}

//清空队列

void ClearAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("队列已经是空的了！\n");
		return;
	}
    Q->front = Q->rear = 0;
}

//遍历队列

Status TraverseAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("队列里面什么都没有!\n");
        return FALSE;
    }
    int i = 0;
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
        APrint(Q->data[Q->front+i], Q->type[Q->front+i]);
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}

void APrint(void *q, int typeData)
{
    if(typeData == 1)
        printf("--> %d\n", *(int*)q);
    if(typeData == 2)
        printf("--> %c\n", *(char*)q);
    if(typeData == 3)
        printf("--> %.2lf\n", *(double*)q);
    if(typeData == 4)
        printf("--> %s\n", (char*)q);                      //1-->INT   2-->CHAR    3-->DOUBLE     4-->STRING
}

void menu()
{
    printf("1.初始化一个队列\n");
    printf("2.销毁一个队列\n");
    printf("3.清空一个队列\n");
    printf("4.入队\n");
    printf("5.出队\n");
    printf("6.查看队头元素\n");
    printf("7.遍历队列\n");
    printf("8.退出\n");
}

