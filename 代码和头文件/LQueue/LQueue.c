#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include<string.h>
#include"LQueue.h"

//初始化带头结点的链队列

void InitLQueue(LQueue *Q) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	Q->length=0;
	return;
}

//判断是否为空

Status IsEmptyLQueue(const LQueue *Q) {
	return (Q->front == Q->rear? TRUE: FALSE);
}

//入队

Status EnLQueue(LQueue *Q, void *data) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void *)malloc(Q->data_size[Q->length-1]);
	memcpy(p->data, data, Q->data_size[Q->length-1]);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}
void InLQueue(LQueue *Q)
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
	Q->length++;
    switch(t)
    {
    case 1:{
        int a;
        scanf("%d", &a);
        Q->data_size[Q->length-1]=4;
        EnLQueue(Q, &a);
    break;
    }
    case 2:{
        char a;
        scanf("%s", &a);
        Q->data_size[Q->length-1]=1;
        EnLQueue(Q, &a);
        break;
    }
    case 3:{
        double a ;
        scanf("%lf", &a);
        Q->data_size[Q->length-1]=8;
        EnLQueue(Q, &a);
        break;
    }
    case 4:{
        char a[20];
        printf("最大长度为20哦！\n");
        scanf("%s", a);
        Q->data_size[Q->length-1]=20;
        EnLQueue(Q, a);
        break;
    }
    }
}

//出队

Status DeLQueue(LQueue *Q) {
	if(IsEmptyLQueue(Q))
		return FALSE;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (NULL == Q->front->next)
		Q->rear = Q->front;
	free(p);
	return TRUE;
}

//获得链队列头元素

Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, Q->data_size[0]);//在头结点下一个节点指向的位置赋予字节数
	return TRUE;
}

//队列长度

int LengthLQueue(LQueue *Q) {
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next;
	return length;
}

//销毁队列

void DestoryLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return;
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}

//清空队列

void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return;
	Node *p, *q;
	Q->rear = Q->front;
	p = Q->front->next;
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}

//遍历链队列

Status TraverseLQueue(const LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return FALSE;
    Node* p = (void *)malloc(Q->data_size[0]);
    p = Q->front->next;
    int i = 1;
    while (p != NULL) {
        if (i % 5 == 0) printf("\n");
        LPrint(p->data, Q->data_size[i-1]);
        p = p->next;
        i++;
    }
    printf("\n");
	return TRUE;
}

//根据字节数来实现遍历
void LPrint(void *q, int size) {
	if (size == sizeof(double))
		printf("%lf", *(double *)q);
	if (size == sizeof(char))
		printf("%c", *(char *)q);
	if (size == sizeof (int))
		printf("%d", *(int *)q);
    if (size == 20)
		printf("%s", (char*)q);
    printf("<-");
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
