#include<stdio.h>
#include<string.h>


/* ���@�ӵĉ�̎��:
 * 	1. ��һ�������� pointer to char[30] ����춌��@��function
 * 	   ���õ�������r��
 *
 * 	2. �҂���string ���L�ж̣����ÿһ���ִ����L�ȶ���30��Ԓ��
 * 	   ��Щ����30�ľ����M�˿��g
 *
 * 	3. ������� array�e�����bһ��array( 2-dimension array)
 * 	   �ķ�ʽ������string literal��׃�ɿ��Ը��ĵ���r��!!
 * 	   �O��Σ�U
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
