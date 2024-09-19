#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <inttypes.h>

/*
	Logarithm with generic base.
	
	Args:
		y (long double): argument of logarithm.
		x (long double): base.
		
	Returns:
		long double: log_x y logarithm of y with base x.
		
	Raises:
*/
long double logx(long double y, long double x){
	/* 
		Change of base of logarithm.
		C only have base e and 10 for logarithms.
	*/
	return log(y)/log(x);
}

/*
	Calculate number of digits of a^x without calculate a^x .
	
	Args:
		a (uint64_t): base.
		x (uint64_t): exponent.
		
	Returns:
		uint64_t: number of digits of a^x.
		
	Raises:
*/
uint64_t ndigits(uint64_t a, uint64_t x){
	// log a^x = x * log a
	return 1+(x*log10l((long double)a));
}

/*
	Calculate the most significant digit in a^x without calculate a^x .
	
	Args:
		a (uint64_t): base.
		x (uint64_t): exponent.
		n (uint64_t): big exponent number in base 10 of a^x .
		
	Returns:
		 uint8_t: most significant digit in a^x . 
*/
uint8_t most_significant(uint64_t a, uint64_t x, uint64_t n){
	/*
		b*10^n < a^x
		log_a (b*10^n) < log_a (a^x) = x
		log_a (b*10^n) = log_a (b) + n*log_a (10)
		log_a (b) + n*log_a (10) < x
	*/
	uint8_t i;
	long double sl10 = n*logx(10,a);
	for(i=2;(logx(i,a)+sl10)<=x;i++){
		;
	}
	return i-1;
}

void main(){
	uint64_t exp;
	uint64_t number;
	
	while(true){
		printf("a = ");
		scanf("%"SCNu64,&number);
		printf("x = ");
		scanf("%"SCNu64,&exp);
		
		if((number>1)&&(exp>1)){
			break;
		}
	}

	uint64_t ndig = ndigits(number,exp);
	uint8_t msig = most_significant(number,exp,ndig-1);
	uint64_t ndigh = (msig==9) ? (ndig+1) : ndig;
	uint8_t msigh = (msig==9) ? 1 : (msig+1);
	
	printf("%"PRIu64"^%"PRIu64" in ",number,exp);
	printf("[ %"PRIu8" * 10^%"PRIu64,msig,ndig-1);
	printf(" , %"PRIu8" * 10^%"PRIu64" ]\n",msigh,ndigh-1);
}
