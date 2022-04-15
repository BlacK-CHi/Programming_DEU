#include <stdio.h>
#include <stdlib.h>

int main(void){
	int x, y, z;

	printf("세 개의 정수를 공백으로 구분하여 입력하십시오 : ");
	scanf("%d %d %d", &x, &y, &z);

	printf("%d * %d - %d = %d", x, y, z, x*y-z);
	return 0;
}
