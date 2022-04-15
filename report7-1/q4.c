#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i = 0;
	int score[3];
	double total, avg;

	while(i<3){
		printf("%d번째 과목의 점수를 입력하십시오 : ", i+1);
		scanf("%d", &score[i]);
		i++;
	}

	total = score[0] + score[1] + score[2];
	avg = total / 3.0;

	printf("총점 : %.2lf\n평균 : %.2lf", total, avg);
	return 0;
}
