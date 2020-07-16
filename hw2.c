#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct ListNode {
	float coef;
	int expo;
	struct ListNode* link;
}ListNode;

typedef struct ListHead {
	ListNode* head;
}ListHead;

ListHead* creatLinkedList(void) {
	ListHead* L;
	L = (ListHead *)malloc(sizeof(ListHead));
	L->head = NULL;
	return L;
}
void freeLinkedList_h(ListHead* L) {
	ListNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}
void addLastNode(ListHead* L, float coef, int expo) {
	ListNode* newNode;
	ListNode* p;
	newNode = (ListNode *)malloc(sizeof(ListNode));

	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	else {
		p = L->head;
		while (p->link != NULL) {
			p = p->link;
		}
		if (p->expo != newNode->expo) {
			p->link = newNode;
		}
		
	}
	
}
void addPoly2(ListHead* A, ListHead* B, ListHead* C) {
	ListNode* pA = A->head;
	ListNode* pB = B->head;
	float sum;

	while (pA&&pB) {
		if (pA->expo == pB->expo) {
			sum = pA->coef + pB->coef;
			/*if (sum == 0) continue;
			addLastNode(C, sum, pA->expo);
			pA = pA->link; pB = pB->link;*/
			if (sum != 0) {
				addLastNode(C, sum, pA->expo);
				pA = pA->link; pB = pB->link;
			}
			else if (sum == 0) {
				pA = pA->link; pB = pB->link;
			}
		}
		else if (pA->expo > pB->expo) {
			if (pA->coef != 0) {
				addLastNode(C, pA->coef, pA->expo);
				pA = pA->link;
			}
			else if (pA->coef == 0) {
				pA = pA->link;
			}
			
		}
		else {
			if (pB->coef != 0) {
				addLastNode(C, pB->coef, pB->expo);
				pB = pB->link;
			}
			else if (pB->coef == 0) {
				pB = pB->link;
			}
		}
	}
	for (; pA != NULL; pA = pA->link) {
		if (pA->coef != 0) {
			addLastNode(C, pA->coef, pA->expo);
		}
	}
	for (; pB != NULL; pB = pB->link) {
		if (pB->coef != 0) {
			addLastNode(C, pB->coef, pB->expo);
		}
	}
}
void addPoly(ListHead* A, ListHead* B, ListHead* C) {
	ListNode* pA = A->head;
	ListNode* pB = B->head;


	while (pA&&pB) {
		
		if (pA->expo == pB->expo) {
			/*if (pA->expo != C->head->expo) {
				addLastNode(C, pA->coef, pA->expo);
				pA = pA->link; pB = pB->link;
			}
			else
				pA = pA->link; pB = pB->link;*/
			addLastNode(C, pA->coef, pA->expo);
			pA = pA->link; pB = pB->link;
		}
		else if (pA->expo > pB->expo) {
			/*if (pA->expo != C->head->expo) {
				addLastNode(C, pA->coef, pA->expo);
				pA = pA->link; 
			}
			else {
				
				pA = pA->link;
			}*/
				
			addLastNode(C, pA->coef, pA->expo);
			pA = pA->link;
		}
		else {
			addLastNode(C, pB->coef, pB->expo);
			pB = pB->link;
		}
	}
	for (; pA != NULL; pA = pA->link) {
		addLastNode(C, pA->coef, pA->expo);
	}
	for (; pB != NULL; pB = pB->link) {
		/*if (pA->expo != C->head->expo) {
			addLastNode(C, pA->coef, pA->expo);
			pA = pA->link; pB = pB->link;
		}
		else
			pA = pA->link; pB = pB->link;*/
		/*if (pB->expo != C->head->expo) {
			addLastNode(C, pB->coef, pB->expo);
		}
		else
			continue;*/
		addLastNode(C, pB->coef, pB->expo);

		
	}
}
void subPoly(ListHead* A, ListHead* B, ListHead* C) {
	ListNode* pA = A->head;
	ListNode* pB = B->head;

	while (pA&&pB) {
		if (pA->expo == pB->expo) {
			pA = pA->link; pB = pB->link;
		}
		else if (pA->expo > pB->expo) {
			addLastNode(C, pA->coef, pA->expo);
			pA = pA->link;
		}
		else {
			
			pB = pB->link;
		}
	}
	for (; pA != NULL; pA = pA->link) {
		addLastNode(C, pA->coef, pA->expo);
	}
	/*for (; pB != NULL; pB = pB->link) {
		addLastNode(C, pB->coef, pB->expo);
	}*/
}
void printPoly(ListHead* L,FILE *output_fp) {
	ListNode* p = L->head;
	for (; p; p = p->link) {
		fprintf(output_fp,"%0.0f %d ", p->coef, p->expo);
	}
	fprintf(output_fp,"\n");
}
int main() {

	FILE *input_fp, *output_fp;

	input_fp = fopen("hw2.inp", "rt");
	output_fp = fopen("hw2.out", "wt");

	if ((input_fp = fopen("hw2.inp", "rt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "hw2.inp");
	}

	if ((output_fp = fopen("hw2.out", "wt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "hw2.out");
	}

	ListHead *A, *B, *C, *D, *E;

	A = creatLinkedList();
	B = creatLinkedList();
	C = creatLinkedList();
	D = creatLinkedList();
	E = creatLinkedList();

	char star, v;
	int num[2];
	
	while (1) {
	
		while (1) {
			fscanf(input_fp, "%d %d%c", &num[0], &num[1], &v);
			addLastNode(A, num[0], num[1]);
			if (v == '\n') break;
		}

		fscanf(input_fp, "%c", &star);
		if (star == '*') {
			
			break;
		}
		if (star == 'I') {
			while (1) {
				fscanf(input_fp, "%d %d%c", &num[0], &num[1], &v);
				addLastNode(B, num[0], num[1]);
				if (v == '\n') break;
				
			}
			if (C->head == NULL) {
				addPoly(A, B, C);
				printPoly(C, output_fp);
				freeLinkedList_h(A);
				freeLinkedList_h(B);
			}
			else {
				addPoly(A, B, D);
				printPoly(D, output_fp);
			}
		}
		else if (star == 'D') {
			while (1) {
				fscanf(input_fp, "%d%c", &num[0], &v);
				addLastNode(B, 1, num[0]);
				if (v == '\n') break;
			}
			if (C->head == NULL) {
				subPoly(A, B, C);
				printPoly(C, output_fp);
				freeLinkedList_h(A);
				freeLinkedList_h(B);
			}
			else {
				subPoly(A, B, D);
				printPoly(D,output_fp);
			}
		}
		else
			break;
	}
	addPoly2(C, D, E);
	printPoly(E,output_fp);
	fprintf(output_fp, "*");

	fclose(input_fp);
	fclose(output_fp);

	return 0;
}