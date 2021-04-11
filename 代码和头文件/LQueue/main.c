#include <stdio.h>
#include <stdlib.h>
#include"LQueue.h"


int main()
{
    LQueue *Q=(LQueue*)malloc(sizeof(LQueue));
    while (1) {
		menu();
		char x;
		scanf("%s", &x);
		if(x!='8'&&x!='1'&&x!='2'&&x!='3'&&x!='4'&&x!='5'&&x!='6'&&x!='7'){
            printf("%s\n","请重新输入一个数");
		}
		switch (x) {
		case '1': {
			InitLQueue(Q);
			break;
		}
		case '2': {
			DestoryLQueue(Q);
			break;
		}
		case '3': {
		    ClearLQueue(Q);
			break;
		}
		case '4': {
		    InLQueue(Q);
			break;
		}
		case '5': {
			DeLQueue(Q);
			break;
		}
		case '6': {
			void *e=(void *)malloc(21);
			GetHeadLQueue(Q,e);
			LPrint(e,Q->data_size[0]);
			break;
		}
		case '7': {
			TraverseLQueue(Q);
			break;
		}
		case '8':
			return 0;
		}
		system("pause");
		system("cls");
	}

}
