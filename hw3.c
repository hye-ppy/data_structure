#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#pragma warning(disable:4996)
#define NEXT (index,QSIZE) ((index+1)%QSIZE)
#define alphabet 26

typedef char element;

typedef struct stackNode {
	element data;
	struct stackNode *link;
}stackNode;

stackNode* top;

void push(element item) {
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

element peekS() {
	element item;
	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		item = top->data;
		return item;
	}
}
void delS() {
	stackNode* temp;
	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
	}
	else {
		temp = top;
		top = top->link;
		free(temp);
	}
}

void printStack(FILE* output_fp) {
	stackNode* p = top;
	while (p) {
		fprintf(output_fp, "%c", p->data);
		p = p->link;
		if (p == NULL) {
	//		fprintf(output_fp, "%c", p->data);
			break;
		}
		
	}
	fprintf(output_fp, "\n");
}

typedef struct QNode {
	element data;
	struct QNode *link;
} QNode;
typedef struct {
	QNode *front, *rear;
	int count;
} LQueueType;
LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}
int isEmpty(LQueueType *LQ) {
	if (LQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}
void enQueue(LQueueType *LQ, element item) {
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		newNode->link = LQ->front;
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}
void enQueue2(LQueueType *LQ, element item) {
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}
element deQueue(LQueueType *LQ) {
	QNode *old = LQ->front;
	element item;
	if (isEmpty(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front = NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}
int del(LQueueType *LQ) {
	QNode *old = LQ->front;
	if (isEmpty(LQ)) return 0;
	else {
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return 1;
	}
}
element peek(LQueueType *LQ) {
	element item;
	if (isEmpty(LQ)) return 0;
	else {
		item = LQ->front->data;
		return item;
	}
}
void printLQ(LQueueType *LQ,FILE *output_fp) {
	QNode *temp = LQ->front;
	while (temp) {
		fprintf(output_fp,"%c", temp->data);
		temp = temp->link;
	}
	fprintf(output_fp,"\n");
}
/*int exLQ(char p,int n,FILE *output_fp) { //탐색
	//QNode *temp = LQ->front;
	QNode *temp1 = LQ1->front;
	QNode *temp2 = LQ2->front;
	while (temp1) {
		if (p == temp1->data) {
			for (int i = 0; i < alphabet - n; i++) {
				fprintf(output_fp, "되나1?");
				temp1 = temp1->link;
			}
			return temp1->data;
			break;
		}
		else if (p == temp2->data) {
			for (int i = 0; i < alphabet - n; i++) {
				fprintf(output_fp, "되나2?");
				temp2 = temp2->link;
			}
			return temp2->data;
			break;
		}
		else {
			fprintf(output_fp, "다음");
			temp1 = temp1->link;
			temp2 = temp2->link;
		}
			
	}
}*/
int main() {


	top = NULL;

	FILE *input_fp, *output_fp;

	input_fp = fopen("hw3.inp", "rt");
	output_fp = fopen("hw3.out", "wt");

	if ((input_fp = fopen("hw3.inp", "rt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "hw3.inp");
	}

	if ((output_fp = fopen("hw3.out", "wt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "hw3.out");
	}

	char c;

	while (1) {
		fscanf(input_fp, "%c", &c);
		if (c == '\n') break;
		push(c);
	}
	printStack(output_fp);

	//LQueueType *LQ1 = createLinkedQueue();//소문자
	//LQueueType *LQ2 = createLinkedQueue();//대문자
	LQueueType *LQ3 = createLinkedQueue();//입력받기
	LQueueType *LQ4 = createLinkedQueue();//숫자입력받기
	LQueueType *LQ5 = createLinkedQueue();//암호해독


	/*for (int i = 0; i < alphabet; i++) {
		enQueue(LQ1, input);
		input++;
	}
	for (int i = 0; i < alphabet; i++) {
		enQueue(LQ2, inputt);
		inputt++;
	}*/
	//여기까지
	
	
	
	/*p = 'l';
	int n = 4;	
	p = exLQ(p, LQ1,n);
			
	enQueue2(LQ4,p);
	printLQ(LQ4, output_fp);*/ //이거 되는거

	char p, num, pp;
	int n,newnum;

/*	while (1) {
		fscanf(input_fp, "%c", &star);
		printf("나별");
		if (star == '*') {
			printf("브레엥라");
			break;
		}*/
	//	else {
			while (1) {
				//printf("드러옴");
				fscanf(input_fp, "%c", &p);
				if (p == '\n')break;// { printf(" 끝"); break; }
				enQueue2(LQ3, p);
				
			}
			while (1) {
				//printf("두번");
				fscanf(input_fp, "%c", &num);
				if (num == '\n')break;// { printf("end"); break; }
				enQueue(LQ4, num);
				
			}
		//}
		/*else {
			while (1) {
				printf("두번");
				fscanf(input_fp, "%c", &num);
				enQueue(LQ4, num);
				if (num == '\n') { printf("end"); break; }
			}
		}*/		
//	}
//	fprintf(output_fp, "?888888888?");
	QNode *temp3 = LQ3->front;
	QNode *temp4 = LQ4->front;
	while (temp3) {
		pp = temp3->data;
		n = temp4->data;
		newnum = (int)n - 48; //fprintf(output_fp, "?eee?");
		if (pp == ' ') {
			enQueue2(LQ5, ' ');
			temp3 = temp3->link;
			continue;
		}
		if (pp >= 97 && pp <= 122) {
			pp = pp - newnum;
		//	fprintf(output_fp, "솜누자자자");
			if (pp < 97) {
				pp += 26;
		//		fprintf(output_fp, "솜누자자자"); 
			}
		}
		else if (pp > 65 && pp <= 90) {
			pp = pp - newnum;
			if (pp < 65) {
				pp += 26;
			}
		}
	
	//	fprintf(output_fp, "너너너넌ㄴ????");
		enQueue2(LQ5, pp);
		//deQueue(LQ3);
		temp3 = temp3->link;
		temp4 = temp4->link;
	//	fprintf(output_fp, "너너너넌ㄴ?55555???");
	}

	/*QNode *temp3 = LQ3->front; fprintf(output_fp, "?k?");
	pp = LQ3->front;
	QNode *temp4 = LQ4->front;
	n = LQ4->front;
	newnum = (int)n - 48; fprintf(output_fp, "?eee?");
	fprintf(output_fp, "되나?");
	pp = exLQ(pp, newnum, output_fp);
	fprintf(output_fp, "?");
	enQueue2(LQ5, pp);*/
	//while (1) {
		/*QNode *temp3 = LQ3->front; fprintf(output_fp, "?k?");
		pp = LQ3->front;
		QNode *temp4 = LQ4->front;
		n = LQ4->front;
		newnum = (int)n - 48; fprintf(output_fp, "?eee?");*/
		/*for (;pp!=0 ; element deQueue(LQ3)) {
		fprintf(output_fp, "되나sk?");
		pp = exLQ(pp, LQ1, LQ2, newnum, output_fp);
		fprintf(output_fp, "?");
		enQueue2(LQ5, pp);
		element deQueue(LQ4);
		//temp4 = temp4->link;
		}*/
		/*fprintf(output_fp, "되나?");
		pp = exLQ(pp, LQ1, LQ2, newnum, output_fp);
		fprintf(output_fp, "?");
		enQueue2(LQ5, pp);*/
		/*while (1) {
			if (pp != NULL) {
				fprintf(output_fp, "되나?");
				pp = exLQ(pp, LQ1, LQ2, newnum, output_fp);
				fprintf(output_fp, "?");
				enQueue2(LQ5, pp);
				element deQueue(LQ3);
				element deQueue(LQ4);
				//temp3 = temp3->link;
				//temp4 = temp4->link;
			}
			else
				break;
		}*/
	//}
	
	
		

	//enQueue(LQ4, 'a'); printLQ(LQ4, output_fp);
	//enQueue(LQ4, 'b'); printLQ(LQ4, output_fp);
	//deQueue(LQ1); printLQ(LQ1, output_fp);
	//enQueue(LQ1, 'c'); printLQ(LQ1, output_fp);
	
	/*while (1) {
		scanf(output_fp, "%c", &star);
		if (star == '*') break;
		else {
			while (1) {
				scanf(output_fp, "%c", &cc);
				if (cc == 'wn') break;
				enQueue(LQ1, cc);
				printLQ(LQ1,output_fp);
			}
		}
		
	}*/
	
	/*while (1) {
		scanf(output_fp, "%c", &cc);
		if (cc == '\n') break;
		enQueue(LQ1, cc);
		printLQ(LQ1, output_fp);
	}*/


	printLQ(LQ5, output_fp);
	fprintf(output_fp, "*");
	fclose(input_fp);
	fclose(output_fp);

	return 0;
}