#include <stdio.h>
#include <stdlib.h>

int main(void){
	double x;

	printf("x의 값을 입력하십시오 : ");
	scanf("%lf", &x);

	printf("다항식의 값은 %lf입니다.", (3*x*x*x)-(7*x*x)+9);
	return 0;
}	
