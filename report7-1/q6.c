#include <stdio.h>
#include <stdlib.h>

void divider (int num);

int main(void){
	int number;

	printf("정수를 입력하십시오 : ");
	scanf("%d", &number);

	divider(number);
	return 0;
}

void divider(int num){
	int hund = num/100;
	int ten = (num%100)/10;
	int one = (num%100)%10;

	printf("백의 자릿수 : %d\n", hund);
	printf("십의 자릿수 : %d\n", ten);
	printf("일의 자릿수 : %d", one);
}
