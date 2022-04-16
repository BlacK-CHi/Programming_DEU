#include <stdio.h>
#include <stdlib.h>

int main(void){
	double num1, num2, sum;

	printf("2개의 실수를 공백으로 구분하여 입력하십시오 : ");
	scanf("%lf %lf", &num1, &num2);

	printf("두 실수의 정수부의 합 : %d", (int)num1 + (int)num2);
	return 0;
}
