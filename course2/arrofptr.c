#include<stdio.h>
#include<string.h>

/* �ĳ������@�N��ʽ�ᣬ�͛]��֮ǰ�Ć��}��
 * ���H�����˔U���ԣ��`���ԡ�Ҳ���Ӱ�ȫ��
 */

void show_string_table(char **string, int number_of_string)
{
	int i;

	for ( i = 0; i < number_of_string; i++){
		printf("%s\n", string[i]);
	}

}


int main()
{

	char *string[5] = 
		{
				"hello world",
				"This is a good news!",
				"I'm from Taiwan.",
				"Nice to meet you~!",
				"abcdefghijklmnopqrstuvwxyz"
				
		};

	/* ERROR !! */
	//string[0][1] = 'a';

	/* ERROR !! */
	//strncpy(string[3] + 8, "hate", 4);
	show_string_table(string, 5);	
}




