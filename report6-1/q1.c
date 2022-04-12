#include <stdio.h>
#include <stdlib.h>

int main(void){
	double i;

	printf("실수를 입력하시오 : ");
	scanf("%lf", &i);
	printf("지수 형식으로 표현하면 %le입니다.", i);
	
	return 0;
}
