#include<stdio.h>


int main(){ 
	
	int number = 10;
	/* 怎麼樣寫一個 function 將 number 改成你想要改的值？ */



	/* 請用自己的想法說明下面這段 code 的意思 */
	char *str = "hello world";
	
	while ( *str ) { 
		printf("%c\n", *str++);
	}
	
	
	/* 下面這段 code ， str2 是一個指向 char 的指標
	 * 他只向了字串 "hello world" 的第一個位址
	 * 在這裡 "hello world" 會被分配在 .text 段位，
	 * 當作是一個 const 型別的唯讀字串，不能進行任何修改
	 * 但是 pointer to char : str2 卻可以一直移動
	 */

	char *str2 = "hello world";
	int i = 0;
	while ( i < 100 ){ 
		printf("%c\n", *str2++);
	}
	return 0;

}
