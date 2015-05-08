#include<stdio.h>
#include<string.h>


/* 寫這樣的壞處是:
 * 	1. 第一個參數是 pointer to char[30] 不利於將這個function
 * 	   套用到其他情況上
 *
 * 	2. 我們的string 有長有短，如果每一個字串的長度都是30的話，
 * 	   有些不足30的就浪費了空間
 *
 * 	3. 因為是用 array裡面在裝一個array( 2-dimension array)
 * 	   的方式編寫，string literal就變成可以更改的情況了!!
 * 	   極度危險
 */

void show_string_table(char (*string)[30], int number_of_string)
{
	int i;

	for ( i = 0; i < number_of_string; i++){
		printf("%s\n", string[i]);
	}

}



int main()
{
	char string_Table[5][30] = 
			{
				"hello world",
				"This is a good news!",
				"I'm from Taiwan.",
				"Nice to meet you~!",
				"abcdefghijklmnopqrstuvwxyz"
			};


	show_string_table(string_Table, 5);
	/*
	string_Table[3][8] = 'h';
	string_Table[3][9] = 'a';
	string_Table[3][10] = 't';
	string_Table[3][11] = 'e';
	*/
	strncpy(&string[3][8], "hate", 4);


	printf("\nAfter changing the string : \n");
	show_string_table(string_Table, 5);
}
