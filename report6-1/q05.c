#include <stdio.h>
#include <stdlib.h>

int main(void){
	char ch;

	printf("문자를 입력하십시오 : ");
	ch = getchar();

	printf("ASCII 코드 : %d", ch);
	return 0;
}
