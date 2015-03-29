#include<stdio.h>
#include<stdlib.h>


int main(){ 
	int *number;
	int *ptr2;
	{ 
		int *ptr = malloc(sizeof(int));
		*ptr = 10;
		ptr2 = ptr;
		printf("%d\n", *ptr);
		printf("ptr2 : %p\n", ptr2);
		printf("ptr  : %p\n", ptr);
		printf("address of ptr2 : %p\n", &ptr2);
		printf("address of ptr : %p\n", &ptr);
	}
	int *ptr3 = malloc(sizeof(int));
	printf("address of ptr3 : %p\n", &ptr3);

	
	size_t off = ptr2 - ptr3;
	*(ptr3 + off) = 20;
	
	printf("*ptr2 : %d\n", *ptr2);
	

	return 0;
}
