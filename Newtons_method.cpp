#include <stdio.h>
#include <math.h>

double f(double x) {			  // f(x) = x - 3^(-x)
	return x - pow(3, x * (-1));
}
double derivative_f(double x) {	  // f'(x) = 1 + 3^(-x)*ln3
	return 1 + pow(3, x * (-1)) * log(3); // log() 함수 : ln
}

int main()
{
	double p_n = 0.5;

	printf(" n      pn       |pn - pn-1|\n");
	printf("%2d  %.9f\n", 0, p_n);

	for(int n = 1; ; n++) {

		double p_nminus1 = p_n; // 이전 단계의 pn을 pn-1에 저장

		p_n = p_nminus1 - f(p_nminus1) / derivative_f(p_nminus1); // pn
		// pn을 소수점 아래 10번째 자리에서 반올림
		p_n = round(p_n * pow(10, 9)) * pow(10, -9);	
		
		double error = fabs(p_n - p_nminus1);	// 오차

		printf("%2d  %.9f  %.9f\n", n, p_n, error);

		// 오차 범위가 10^(-8)이 되면 반복문 종료
		if (error < pow(10, -7)) break;

	}
}

