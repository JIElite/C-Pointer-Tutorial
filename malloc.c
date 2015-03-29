#include<stdio.h>


int main(){ 

	/* wrong 
   		int *a;
		*a = 10;
	*/
				        Memory
		     		|--------------------|
				|		     |
			Stack	|		     |
				----------------------
			------	|  ///////a //////// | <--- 位置為 &a  ，因為 a 在 stack 中可能保有之前用過的亂數
			|	----------------------      所以 C 語言說 int *a;  		
			|	|                    |      *a = 10; 這樣的 code 是未定義的行為，運氣好不會發生錯誤
			|	|	             |      運氣不好假如存取到系統的某個數值就掛了		
			|	|                    |
			|       . 		     .						
			|	.                    .
			|	.                    .
	 	malloc	|	----------------------	
		完會指向|	|                    |
		heap 的	|	|                    |   Heap 有很多破碎的記憶體片段可以使用
		某個空間|	|   Heap             |   malloc 就是向 heap 要求這些可用的記憶體片段
			|	|		     |	 
			|	----------------------
			|----->	| XXXXXXXXXXXXXXXXXX | <---  假如這個破碎的記憶體滿足我們要的空間
				----------------------	     malloc 就會回傳這個位置給 指標型態的變數 
				|                    |       malloc 回傳的型態是 void * 這是一個通用的指標變數
				|                    |       任何指標變數都可以用 void * 的形式宣告，但是我們必須轉型
							     才可以使用這樣的指標變數因為:
							     int number = 10;
							     void *ptr;
							     ptr = &number;
							     *ptr = 10 // wrong 因為 ptr 是一個指向 void 的指標
								     	  他並不知道他指向的空間有多大多小，又怎麼存取數值呢？
						             所以要這樣使用:
							     *((int *)ptr) = 10; 先將 ptr 轉成指向int就可以存取了

}				
