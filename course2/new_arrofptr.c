#include<stdio.h>
#include<string.h>


void show_string_table(char **string)
{

	while ( *string != NULL ){
		printf("%s\n", *string++);
	}

}


int main()
{

	char *string[6] = 
			{
				"hello world",
				"This is a good news!",
				"I'm from Taiwan.",
				"Nice to meet you~!",
				"abcdefghijklmnopqrstuvwxyz",
				NULL
			};

	/* ERROR !! */
	//string[0][1] = 'a';

	/* ERROR !! */
	//strncpy(string[3] + 8, "hate", 4);
	show_string_table(string);	
}





