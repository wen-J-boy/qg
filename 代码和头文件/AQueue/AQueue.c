#include <stdio.h>
#include <stdlib.h>
#include"AQueue.h"


//��ʼ������

void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++)
        //��֪���û��������������ʹ�С�����Ը���20
        Q->data[i] = (void *)malloc(21);
	Q->front = Q->rear = 0;
}

void DestoryAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return;
    }
	for(int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
	Q->data[0] = NULL;
}

//�ж�Ϊ��

Status IsFullAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
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

//�ж�Ϊ��

Status IsEmptyAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
	return (LengthAQueue(Q) == 0 ? TRUE : FALSE);
}

//�鿴��ͷԪ��

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		printf("����Ϊ�գ�û�ж�ͷ��\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front],20);
    return TRUE;
}

//��ȡ���г���

int LengthAQueue(AQueue *Q)
{
    return (Q->rear-Q->front+Q->length)%Q->length;
}

//���

Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		printf("�������ˣ�����������ˣ�\n");
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
    printf("��������������ͣ�:\n");
    printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���\n");
    scanf("%d", &t);
    while(t<1 || t>4)
    {
     	printf("Ӧ������[1,4]֮���������\n�����䣺");
      	scanf("%d", &t);
    }
	printf("����ӵ����� :");
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
        printf("��󳤶�Ϊ20Ŷ��\n");
        scanf("%s", a);
        Q->type[Q->rear]=t;
        EnAQueue(Q, a);
        break;
    }
    }
}

//���Ӳ���

Status DeAQueue(AQueue *Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("�����ǿյģ������˶ӣ�\n");
        return FALSE;
    }
    Q->front = (Q->front+1)%Q->length;
    return TRUE;
}

//��ն���

void ClearAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf("�����Ѿ��ǿյ��ˣ�\n");
		return;
	}
    Q->front = Q->rear = 0;
}

//��������

Status TraverseAQueue(const AQueue *Q)
{
    if(Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("��������ʲô��û��!\n");
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
    printf("1.��ʼ��һ������\n");
    printf("2.����һ������\n");
    printf("3.���һ������\n");
    printf("4.���\n");
    printf("5.����\n");
    printf("6.�鿴��ͷԪ��\n");
    printf("7.��������\n");
    printf("8.�˳�\n");
}

