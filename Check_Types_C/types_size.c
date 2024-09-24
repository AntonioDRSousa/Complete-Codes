#include<stdio.h>
#include<limits.h>
#include<float.h>

void printfloat(const char * type,int size,long double min,long double max){
	printf("%s = %d bytes [ %f , %f ]\n",type,size,min,max);
}

void main(){
	printf("\n---------------------------------\n\n");
	
	printf("char = %d bytes [ %d , %llu ]\n",sizeof(char),CHAR_MIN,CHAR_MAX);
	printf("unsigned char = %d bytes [ %d , %llu ]\n",sizeof(unsigned char),0,UCHAR_MAX);
	printf("signed char = %d bytes [ %d , %llu ]\n",sizeof(signed char),SCHAR_MIN,SCHAR_MAX);
	
	printf("\n---------------------------------\n\n");
	
	printf("short int = %d bytes [ %d , %llu ]\n",sizeof(short),SHRT_MIN,SHRT_MAX);
	printf("int = %d bytes [ %d , %llu ]\n",sizeof(int),INT_MIN,INT_MAX);
	printf("long int = %d bytes [ %ld , %llu ]\n",sizeof(long),LONG_MIN,LONG_MAX);
	printf("long long int = %d bytes [ %lld , %llu ]\n",sizeof(long long),LLONG_MIN,LLONG_MAX);
	
	printf("\n---------------------------------\n\n");
	
	printf("unsigned short int = %d bytes [ %d , %llu ]\n",sizeof(unsigned short),0,USHRT_MAX);
	printf("unsigned int = %d bytes [ %d , %llu ]\n",sizeof(unsigned),0,UINT_MAX);
	printf("unsigned long int = %d bytes [ %ld , %llu ]\n",sizeof(unsigned long),0,ULONG_MAX);
	printf("unsigned long long int = %d bytes [ %lld , %llu ]\n",sizeof(unsigned long long),0,ULLONG_MAX);
	
	printf("\n---------------------------------\n\n");
	
	printf("signed short int = %d bytes [ %d , %llu ]\n",sizeof(signed short),SHRT_MIN,SHRT_MAX);
	printf("signed int = %d bytes [ %d , %llu ]\n",sizeof(signed),INT_MIN,INT_MAX);
	printf("signed long int = %d bytes [ %ld , %llu ]\n",sizeof(signed long),LONG_MIN,LONG_MAX);
	printf("signed long long int = %d bytes [ %lld , %llu ]\n",sizeof(signed long long),LLONG_MIN,LLONG_MAX);
	
	
	printf("\n---------------------------------\n\n");
	
	printf("float = %d bytes [ %e , %e ]\n",sizeof(float),FLT_MIN,FLT_MAX);
	printf("double = %d bytes [ %le , %le ]\n",sizeof(double),DBL_MIN,DBL_MAX);
	printf("long double = %d bytes [ %Le , %Le ]\n",sizeof(long double),LDBL_MIN,LDBL_MAX);
	
	printf("\n---------------------------------\n\n");
	
	printf("\n---------------------------------\n\n");
	
	printf("radix = %d\n",FLT_RADIX);
	printf("number of decimal digits can be rounded = %d\n",DECIMAL_DIG);
	printf("rounding behavior = ");
	switch(FLT_ROUNDS){
		case -1:
			printf("undetermined\n");
			break;
		case 0:
			printf("toward 0\n");
			break;
		case 1:
			printf("to nearest\n");
			break;
		case 2:
			printf("toward positive infinity\n");
			break;
		case 3:
			printf("toward negative infinity\n");
			break;
	};
	printf("evaluation method = ");
	switch(FLT_EVAL_METHOD){
		case -1:
			printf("undetermined\n");
			break;
		case 0:
			printf("evaluate just to the range and precision type\n");
			break;
		case 1:
			printf("evaluate float and double as double, and long double as long double\n");
			break;
		case 2:
			printf("evaluate all as long double. Other negative values indicate an implementation-defined behavior.\n");
			break;
	};
	
	printf("\nfloat\n");
	printf("\tdigits mantissa = %d\n",FLT_MANT_DIG);
	printf("\tnumber of decimal digits can be rounded = %d\n",FLT_DIG);
	printf("\texponent = [ %d , %d ]\n",FLT_MIN_EXP,FLT_MAX_EXP);
	printf("\texponent in base 10 = [ %d , %d ]\n",FLT_MIN_10_EXP,FLT_MAX_10_EXP);
	printf("\tsmallest possible number>0 = %e\n",FLT_EPSILON);
	
	printf("\ndouble\n");
	printf("\tdigits mantissa = %d\n",DBL_MANT_DIG);
	printf("\tnumber of decimal digits can be rounded = %d\n",DBL_DIG);
	printf("\texponent = [ %d , %d ]\n",DBL_MIN_EXP,DBL_MAX_EXP);
	printf("\texponent in base 10 = [ %d , %d ]\n",DBL_MIN_10_EXP,DBL_MAX_10_EXP);
	printf("\tsmallest possible number>0 = %le\n",DBL_EPSILON);
	
	printf("\nlong double\n");
	printf("\tdigits mantissa = %d\n",LDBL_MANT_DIG);
	printf("\tnumber of decimal digits can be rounded = %d\n",LDBL_DIG);
	printf("\texponent = [ %d , %d ]\n",LDBL_MIN_EXP,LDBL_MAX_EXP);
	printf("\texponent in base 10 = [ %d , %d ]\n",LDBL_MIN_10_EXP,LDBL_MAX_10_EXP);
	printf("\tsmallest possible number>0 = %Le\n",LDBL_EPSILON);
	
	printf("\n---------------------------------\n\n");
}