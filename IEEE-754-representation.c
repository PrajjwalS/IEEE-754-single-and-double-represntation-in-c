#include<stdio.h>

void print_bin(unsigned long long num){
	if(num > 1)
	{
		print_bin(num/2); // or num>>1
	}
	printf("%d",num%2);
}

void print_32_bits(float *ptr){
	printf("\nEntered Value:%f", *ptr);
	printf("\nHex Representation:%X", *((unsigned int *)ptr) ); // expecting int to be 32 bits
	printf("\nIEEE Representation in Binaries:");
	// for +ve numbers sign bit loss in conversion to binary 
	if(*(float*)ptr >= 0)
		printf("0");
	print_bin((*(unsigned int *)ptr));
	printf("\n");
}

void print_64_bits(double *ptr){
	
	printf("\nEntered Value:%lf", *ptr);
	printf("\nHex Representation:%lX", *((unsigned long long *)ptr) ); // expecting int to be 64 bits
	printf("\nIEEE Representation in Binaries:");
	// for +ve numbers sign bit loss in conversion to binary 
	if(*(double*)ptr >= 0)
		printf("0");
	print_bin((*(unsigned long long *)ptr));
	printf("\n");
}


int main(){
	float single_precision_input;	//32-bit input
	double double_precision_input;	//64-bit input
	char choice;

	char go_on =1;
	while (go_on){
		printf("\nEnter 'f' for float 'd' for double (enter 'e' to exit): ");
		scanf(" %c",&choice);

		switch(choice){
			case 'f':
				printf("\nEnter float value: ");
				scanf("%f",&single_precision_input);
				print_32_bits(&single_precision_input);
				break;
			case 'd':
				printf("\nEnter double value: ");
				scanf("%lf",&double_precision_input);
				print_64_bits(&double_precision_input);
				break;
			case 'e':
				go_on = 0;
				break;
			default:
				printf("\nbad choice");
				break;
		}
	}
}

