/* *********************************
 * �������IĿ�ģ�
 * 	���� gdb ��鿴���N׃�����̈́e
 *
 * *********************************/



#include<stdio.h>

int main(){ 

	/* What is the type of the followint variable ? 
	 * Please use gdb to Answering it
	 */

	int *array[100]; 	// array : 
	int (*array)[100]; 	// array :
	
	char *(*str)[100]; 	// str 	 :

	void *comp();		// comp  :

	void (*comp2)();	// comp2 :

	char (*(*x())[])(); 	// x     :

	return 0;
}
