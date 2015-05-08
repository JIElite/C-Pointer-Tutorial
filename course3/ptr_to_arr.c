#include<stdio.h>


int main(){
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int (*ptr)[10] = &arr;

	printf("%d\n", (*ptr)[0]);
	return 0;

}
