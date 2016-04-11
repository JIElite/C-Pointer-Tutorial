/*
 * 這份程式碼可以幫助你了解 this pointer
 * 雖然 C++ 的實做不一定是如此，如果有興趣的話可以搜尋：Vtable
 * C++ 實做時會大量使用到 void pointer 
 *
 * 這份 code 要留意的地方是 const 的使用。會變動的就不加 const
 * 不會變動的就要加 const。程式碼要精確，讓人家容易一目了然。
 * 
 *步的內容可以查閱：
 * https://shengwen1997.gitbooks.io/program_with_c/content/oop.html
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
	unsigned year;
	unsigned month;
	unsigned day;
}BirthDay;


// predefine the structure 
typedef struct student Student;

// implement the predefined structure Student.
struct student{

	/* member data 
	 * In C, there is not concept about public and private
	 * however, in C++, the structure is default public
	 * rather than private in class. */
	char id[10];
	char name[30];
	BirthDay birthday;


	/* member function below 
	 * I use function pointer here to implement the
	 * member function (aka method).
	 */
	int (*set_id)(Student *, const char *);
	const char *(*get_id)(const Student *);

	int (*set_name)(Student *, const char *name);
	const char *(*get_name)(const Student *);


	int (*set_birthday)(Student *, unsigned, unsigned, unsigned);
	const BirthDay (*get_birthday)(const Student *);
	
};



int initial(Student *s, 
		int (*set_id)(Student *, const char *),
		const char *(*get_id)(const Student *),
		int (*set_name)(Student *, const char *name),
		const char *(*get_name)(const Student *),
		int (*set_birthday)(Student *, unsigned, unsigned, unsigned),
		const BirthDay (*get_birthday)(const Student *)
          	);

int set_id(Student *s, const char *id);
const char *get_id(const Student *s);

int set_name(Student *s, const char *name);
const char *get_name(const Student *s);

int set_birthday(Student *s, 
		unsigned year, unsigned month, unsigned day);
const BirthDay get_birthday(const Student *s);



int main()
{
	Student s1;
	initial(&s1, set_id, get_id, set_name, get_name,
			set_birthday, get_birthday);
		
	s1.set_id(&s1, "F74016077");
	s1.set_name(&s1, "jielite");
	s1.set_birthday(&s1, 2017, 2, 1);

	printf("Student id: %s\n", s1.get_id(&s1));
	printf("Student name: %s\n", s1.get_name(&s1));
	
	BirthDay birthday = s1.get_birthday(&s1);
	printf("BirthDay: %u/ %u/ %u\n",  birthday.month,
			birthday.day, birthday.year);

	
	return 0;

}





/* The following is the implementation of funciton */

int initial(Student *s, 
		int (*set_id)(Student *, const char *),
		const char *(*get_id)(const Student *),
		int (*set_name)(Student *, const char *name),
		const char *(*get_name)(const Student *),
		int (*set_birthday)(Student *, unsigned, unsigned, unsigned),
		const BirthDay (*get_birthday)(const Student *)
          	)

{
	s->set_id = set_id;
	s->get_id = get_id;

	s->set_name = set_name;
	s->get_name = get_name;

	s->set_birthday = set_birthday;
	s->get_birthday = get_birthday;
	
	return 0;
}


int set_id(Student *s, const char *id)
{
	/* means something error */
	if (strlen(id) > 9) {
		fprintf(stderr, "Error: out of the range of id\n");
		return -1;
	}
	
	strncpy(s->id, id, 10);
	return 0;
}


const char *get_id(const Student *s)
{
	return s->id;
}

int set_name(Student *s, const char *name)
{
	// 查查看 TODO 是什麼意思吧 
	/* TODO check length 
	 * 	
	 * if the length is out of range: return -1
	 * else pass it!
	 * you can also use assert.
	 */
	strncpy(s->name, name, 29);
	return 0;
}
	

const char *get_name(const Student *s)
{	
	return s->name;
}


int set_birthday(Student *s, 
		unsigned year, unsigned month, unsigned day)
{
	/* Verify the datetime, 實際上要更加嚴謹例如檢查
	 * 閏年, 229 等等
	 * 還有出生的年份不可能超過今年
	 */
	assert(month < 13 && month > 0);

	s->birthday.day = day;
	s->birthday.month = month;
	s->birthday.year = year;

	return 0;
}

/* 為什麼回傳的不是指標？ 單純只是設計上的問題 */
const BirthDay get_birthday(const Student *s)
{
	return s->birthday;
}


