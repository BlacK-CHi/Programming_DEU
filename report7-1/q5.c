#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i = 0;
	int num[2];

	while(i<2){
		printf("%d번째 정수를 입력하십시오 : ", i+1);
		scanf("%d", &num[i]);
		i++;
	}

	printf("몫은 %d, 나머지는 %d입니다.", num[0]/num[1], num[0]%num[1]);
	return 0;
}
