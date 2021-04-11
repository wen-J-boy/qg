#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include<string.h>
#include"LQueue.h"

//��ʼ����ͷ����������

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

//�ж��Ƿ�Ϊ��

Status IsEmptyLQueue(const LQueue *Q) {
	return (Q->front == Q->rear? TRUE: FALSE);
}

//���

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
    printf("��������������ͣ�:\n");
    printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���\n");
    scanf("%d", &t);
    while(t<1 || t>4)
    {
     	printf("Ӧ������[1,4]֮���������\n�����䣺");
      	scanf("%d", &t);
    }
	printf("����ӵ����� :");
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
        printf("��󳤶�Ϊ20Ŷ��\n");
        scanf("%s", a);
        Q->data_size[Q->length-1]=20;
        EnLQueue(Q, a);
        break;
    }
    }
}

//����

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

//���������ͷԪ��

Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, Q->data_size[0]);//��ͷ�����һ���ڵ�ָ���λ�ø����ֽ���
	return TRUE;
}

//���г���

int LengthLQueue(LQueue *Q) {
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next;
	return length;
}

//���ٶ���

void DestoryLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return;
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}

//��ն���

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

//����������

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

//�����ֽ�����ʵ�ֱ���
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
    printf("1.��ʼ��һ������\n");
    printf("2.����һ������\n");
    printf("3.���һ������\n");
    printf("4.���\n");
    printf("5.����\n");
    printf("6.�鿴��ͷԪ��\n");
    printf("7.��������\n");
    printf("8.�˳�\n");
}
