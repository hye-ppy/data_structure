#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef struct treeNode {//ok
	int key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;
void preorder(treeNode* root,FILE *output_fp) {//ok
	if (root) {
		fprintf(output_fp,"%d ", root->key);
		preorder(root->left,output_fp);
		preorder(root->right,output_fp);
	}
	
}
treeNode* insertNode(treeNode* p, int x) {//삽입
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode *)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x > p->key) p->left = insertNode(p->left, x);
	else if (x < p->key) p->right = insertNode(p->right, x);
	
	else printf("같은키 존재");

	return p;
}
/*treeNode* insertNode(treeNode *root, int key) {//삽입
	treeNode* newNode;
	treeNode *p, *t;
	newNode = (treeNode *)malloc(sizeof(treeNode));

	t = root;
	p = NULL;

	while (t) {
		if (key == t->key) return ;
		p = t;

		if (key > p->key) {
			t = p->left;
		}
		else {
			t = p->right;
		}
	}
	if (!newNode) {
		return;
	}
	if (p) {
		if (key > p->key) {
			p->left = newNode;
		}
		else {
			p->right = newNode;
		}
	}
	else
		root = newNode;
}*///xxxxx
void delNode(treeNode *root, int key) {//삭제
	treeNode *parent, *t, *sucL, *sucR, *sucL_p,*sucR_p;
	treeNode *child;

	parent = NULL;
	t = root;
	while ((t != NULL) && (t->key != key)) {
		parent = t;
		t = (key > parent->key) ? parent->left : parent->right;
		//if (key > t->key) t = t->left;
		//else t = t->right;
	}
	if (t==NULL) {
		return;
	}
	if ((t->left == NULL) && (t->right == NULL)) {//단말노드
		if (parent != NULL) {
			if (parent->left == t) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}
	else if ((t->left == NULL) || (t->right == NULL)) {// 한개의 자식
		child = (t->left != NULL) ? t->left : t->right;
		//if (t->left != NULL) child = t->left;
		//else child = t->right;
		if (parent != NULL) {
			if (parent->left == t)parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}
	else {
		sucL_p = t;//왼쪽에서 제일 작은값
		sucL = t->left;
		while (sucL->right != NULL) {
			sucL_p = sucL;
			sucL = sucL->right;
		}
		sucR_p = t;//오른쪽에서 제일 큰값
		sucR = t->right;
		while (sucR->left != NULL) {
			sucR_p = sucR;
			sucR = sucR->left;
		}
		if (sucL->key- t->key <= t->key - sucR->key) {
			if (sucL_p->left==sucL) {
				sucL_p->left = sucL->left;
			}
			else {
				sucL_p->right = sucL->left;
			}
			t->key = sucL->key;
			t = sucL;
		}
		else if(sucL->key - t->key > t->key - sucR->key){//여기 다시
			if (sucR_p->right == sucR) {
				sucR_p->right = sucR->right;
			}
			else {
				sucR_p->left = sucR->right;
			}
			t->key = sucR->key;
			t = sucR;

		}
		/*succ_parent = t;
		succ = t->left;
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}*/
		free(t);
	}
}
treeNode* searchBST(treeNode* root, int x,FILE* output_fp) {//탐색수정해야함
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x > p->key) {
			fprintf(output_fp, "%d ", p->key);
			p = p->left;  
			
		}
		else if (x == p->key) {
			fprintf(output_fp, "%d \nYes", p->key);
			return p;
		}
		else {
			fprintf(output_fp, "%d ", p->key);
			p = p->right;
		}
		
	}

	fprintf(output_fp, "\nNo");
	return p;
}
int main() {
	FILE *input_fp, *output_fp;

	input_fp = fopen("hw4.inp", "rt");
	output_fp = fopen("hw4.out", "wt");

	if ((input_fp = fopen("hw4.inp", "rt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "hw4.inp");
	}

	if ((output_fp = fopen("hw4.out", "wt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "hw4.out");
	}
	treeNode* root = NULL;
	int num;
	char w;

	fscanf(input_fp, "%d%c", &num, &w);
	root = insertNode(root, num);
	while(1) {
		fscanf(input_fp, "%d%c", &num,&w);
		insertNode(root, num);
		if (w == '\n') break;
	}
	preorder(root, output_fp);
	fprintf(output_fp, "\n");
	while (1) {
		fscanf(input_fp, "%d%c", &num, &w);
		delNode(root, num);
		if (w == '\n') break;
	}
	preorder(root, output_fp);
	fprintf(output_fp, "\n");

	fscanf(input_fp, "%d", &num);
	searchBST(root, num, output_fp);
	


	fprintf(output_fp, "\n");
	fprintf(output_fp, "*");
	fclose(input_fp);
	fclose(output_fp);

	return 0;
}