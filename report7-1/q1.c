#include <stdio.h>
#include <stdlib.h>

int main(void){
	double height, weight, bmi;

	printf("체중을 입력하십시오 : ");
	scanf("%lf", &weight);

	printf("신장을 입력하십시오 (미터 단위) : ");
	scanf("%lf", &height);

	bmi = weight / (height * height);

	printf("BMI : %.2lf", bmi);
	return 0;
}
