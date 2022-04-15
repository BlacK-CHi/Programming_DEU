#include <stdio.h>
#include <stdlib.h>

int main(void){
	int num;
	
	printf("숫자를 입력하십시오 : ");
	scanf("%d", &num);

	printf("변수의 최하위 비트값 : %d", num & (-num));
	return 0;
}
