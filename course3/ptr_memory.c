/*
 * using this picture to illustrate concept : 
 * http://pananq.com/wp-content/uploads/2012/05/merge-relocation-obj.png
 *
 */


#include<stdio.h>
#include<stdlib.h>


int global_data_bss;
int initilized_var = 10;
static int global_static_data;


int main()
{
	const int *ptr;
	const int const_num = 10;
	ptr = &const_num;
	printf("address of const int data : \t\t%p\n", ptr);

	int *ptr_dynamic = malloc(sizeof(int));
	printf("address of dynamic data : \t\t%p\n", ptr_dynamic);
	
	int *ptr_to_global = &global_data_bss;
	printf("address of global_data_bss : \t\t%p\n", ptr_to_global);


	/* The global variable has not been initialized  with "static" specifier
	 * is still localed in .data section 
	 *
	 * This condition is as same as initialized global variable */
	static int *ptr_global_static = &global_static_data;
	printf("address of global static : \t\t%p\n", ptr_global_static);

	static int data = 10;  // this is a static data, which has been initialized.
	static int *ptr_static = &data;
	printf("address of static data: \t\t%p\n", ptr_static);

	
	int *ptr_g_initialized = &initilized_var;
	printf("address of initilized_var : \t\t%p\n", ptr_g_initialized);

	
	/* string literal is localed in rodata, this section is lower than data section */
	char *ptr_string = "hello";
	printf("address of string literal : \t\t%p\n", ptr_string);



			
}
