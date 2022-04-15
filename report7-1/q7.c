#include <stdio.h>
#include <stdlib.h>

int main(void){
	double x;

	printf("x의 값을 입력하십시오 : ");
	scanf("%lf", &x);

	printf("수식의 값은 %lf입니다.", ((x*x*x)-20) /(x-7));
	return 0;
}
