/* 
 * Array 的名稱他指示出第一個元素的位址
 * pointer 在做++的動作的時候，是針對指向的資料型態做加減
 * 動態分配空間的時候，那個空間是在heap, 但是我們仍然宣告指標變數在stack
 * 像是:
 *		int *ptr = malloc(sizeof(int) * 100);
 *		藉由 malloc 我們向記憶體中的heap區段要取了 sizeof(int) * 100 這樣大小的空間
 *		但是ptr這個變數是存在哪裡呢？ 這個變數是存放在stack的!
 *
 */



#include<stdio.h>
#include<stdlib.h>


int main()
{


	int(*ptr)[4] = malloc(sizeof(int) * 10);
	printf("\nsizeof *ptr : %zu\n", sizeof(*ptr));
	
	/* 試著說明 ptr + 1 記憶體位址的行為 
	 * &ptr 和  ptr 的差別是什麼? ( hint : 觀察數值後 請以記憶體heap, stack 去思考 )
	 */
	printf("ptr    : %p\n", ptr);
	printf("ptr + 1: %p\n", ptr + 1);
	printf("address of ptr : %p\n\n", &ptr);
	free(ptr);


	/* 觀察下面的情況, 有助於理解上面指標+1的變化*/
	double	(*ptr_to_double) = malloc(sizeof(double));
	int 	(*ptr_to_int)	 = malloc(sizeof(int));

	printf("ptr_to_double    : %p\n", ptr_to_double);
	printf("ptr_to_double + 1: %p\n\n", ptr_to_double + 1);

	printf("ptr_to_int     : %p\n", ptr_to_int);
	printf("ptr_to_int + 1 : %p\n\n", ptr_to_int + 1);





	/* 你覺得為什麼下面的情況 和上面不一樣？ 
	 * 同樣的以記憶的的角度分析
	 */
	int32_t	array[10] = {};
	int32_t *stackptr = array;

	printf("stackptr    : %p\n", stackptr);
	printf("stackptr + 1: %p\n\n", stackptr + 1);

	for (int i = 0; i < 10; i++){
		printf("address of array[%d] : %p\n", i, &array[i]);
	}
				


	return 0;
}	
