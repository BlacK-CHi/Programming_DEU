#include <stdio.h>
#include <stdlib.h>

int main(void){
	int price;
	double disc;

	printf("상품 가격을 입력하십시오 : ");
	scanf("%d", &price);

	printf("상품 할인율을 입력하십시오 : ");
	scanf("%lf", &disc);

	printf("할인된 가격 : %.2lf", price-price*(disc/100.0));
	return 0;
}

