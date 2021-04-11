#include <stdio.h>
#include <stdlib.h>
#include"AQueue.h"


int main()
{
    AQueue *Q=(AQueue*)malloc(sizeof(AQueue));
    while (1) {
		menu();
		char x;
		scanf("%s", &x);
		if(x!='8'&&x!='1'&&x!='2'&&x!='3'&&x!='4'&&x!='5'&&x!='6'&&x!='7'){
            printf("%s\n","请正确输入数字");
		}
		switch (x) {
		case '1': {
			InitAQueue(Q);
			break;
		}
		case '2': {
			DestoryAQueue(Q);
			break;
		}
		case '3': {
		    ClearAQueue(Q);
			break;
		}
		case '4': {
		    InAQueue(Q);
			break;
		}
		case '5': {
			DeAQueue(Q);
			break;
		}
		case '6': {
			void *e=(void *)malloc(21);
			GetHeadAQueue(Q,e);
			APrint(e,Q->type[Q->front]);
			break;
		}
		case '7': {
			TraverseAQueue(Q);
			break;
		}
		case '8':
			return 0;
		}
		system("pause");
		system("cls");
	}

}
