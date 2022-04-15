#include <stdio.h>
#include <stdlib.h>

int main(void){
	int num, n;

	printf("숫자를 입력하십시오 : ");
	scanf("%d", &num);

	printf("바꿀 비트의 위치를 입력하십시오 : ");
	scanf("%d", &n);

	num |= 1 << n;

	printf("비트 변경 후 값 : %d", num);
	return 0;
}
