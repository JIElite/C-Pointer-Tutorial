#include<stdio.h>
#include<string.h>

/* 改成下面這種形式後，就沒有之前的問題了
 * 不僅增加了擴充性，靈活性。也更加安全！
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

