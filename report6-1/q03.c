#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592

int main(){
	double rad, suf, vol;

	printf("반지름을 입력하십시오 : ");
	scanf("%lf", &rad);

	suf = 4 * PI * rad * rad;
	vol = (4.0/3.0) * PI * rad * rad * rad;

	printf("구의 표면적 : %lf\n", suf);
	printf("구의 부피 : %lf", vol);

	return 0;
}
