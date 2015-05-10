#include<stdio.h>

typedef struct{
		int *data;
		int age;
} people;


int main()
{
	people p1 = { .data = (int[]){1, 2, 3, 4, 5} , .age = 22 };
	people p2 = p1;
	p2.data[3] = 9;

	printf("%d\n", p1.data[3]);
	return 0;
}

