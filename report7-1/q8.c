#include <stdio.h>
#include <stdlib.h>

int main(void){
	double num1, num2, sum;

	printf("2개의 실수를 공백으로 구분하여 입력하십시오 : ");
	scanf("%lf %lf", &num1, &num2);

	sum = num1 + num2;

	printf("두 실수의 합의 정수부 : %d", (int)sum);
	return 0;
}
