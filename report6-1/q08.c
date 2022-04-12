#include <stdio.h>
#include <stdlib.h>

#define h2sec 3600

int main(void){
	int dist, m, s;
	double h;

	printf("거리를 미터 단위로 입력하십시오 : "); scanf("%d", &dist);
	printf("시간을 입력하십시오 : "); scanf("%lf", &h);
	printf("분을 입력하십시오   : "); scanf("%d", &m);
	printf("초를 입력하십시오   : "); scanf("%d", &s);

	h = (h * h2sec) + (m * 60) + s;
	h = h/h2sec;
	
	printf("속도 : %lf km/h", (dist/1000)/h);
	return 0;
}	
