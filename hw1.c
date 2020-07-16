#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int fun1(int n);
int fun2(int n);
int fun3(int n);
int fun4(int n);
int fun5(int n);
int main() {

	int num;
	char star;
	
	int *big_o = NULL;
	big_o = (int *)malloc(sizeof(int) * 5);

	FILE *input_fp, *output_fp;

	input_fp = fopen("hw1.inp", "rt");
	output_fp = fopen("hw1.out", "wt");

	if ((input_fp = fopen("hw1.inp", "rt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "hw1.inp");
	}

	if ((output_fp = fopen("hw1.out", "wt")) == NULL) {
		fprintf(stderr, "can't open %s\n", "hw1.out");
	}

	while (1) {
		fscanf(input_fp,"%d", &num);
		fscanf(input_fp, "%c", &star);
		if (star=='*') {
			fprintf(output_fp, "*");
			break;
		}

		big_o[0] = fun1(num);
		big_o[1] = fun2(num);
		big_o[2] = fun3(num);
		big_o[3] = fun4(num);
		big_o[4] = fun5(num);

		for (int i = 0; i < 5; i++) {
			fprintf(output_fp, "%d)%d ", i + 1, big_o[i]);
		}
		fprintf(output_fp, "\n");
	}

	fclose(input_fp);
	fclose(output_fp);
	free(big_o);
}
int fun1(int n) {

	return n;

}
int fun2(int n) {

	return (int)(log(n) / log(2));

}
int fun3(int n) {

	return n * (int)(log(n) / log(2));

}
int fun4(int n) {

	return (int)pow(2, n);
}
int fun5(int n) {

	if (n <= 1)
		return (1);
	else
		return (n*fun5(n - 1));

}

