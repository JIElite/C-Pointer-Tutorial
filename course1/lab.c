#include<stdio.h>


int main(){ 
	
	int number = 10;
	/* ���N�ӌ�һ�� function �� number �ĳ�����Ҫ�ĵ�ֵ�� */



	/* Ո���Լ����뷨�f�������@�� code ����˼ */
	char *str = "hello world";
	
	while ( *str ) { 
		printf("%c\n", *str++);
	}
	
	
	/* �����@�� code �� str2 ��һ��ָ�� char ��ָ��
	 * ��ֻ�����ִ� "hello world" �ĵ�һ��λַ
	 * ���@�e "hello world" ���������� .text ��λ��
	 * ������һ�� const �̈́e��Ψ�x�ִ��������M���κ��޸�
	 * ���� pointer to char : str2 �s����һֱ�Ƅ�
	 */

	char *str2 = "hello world";
	int i = 0;
	while ( i < 100 ){ 
		printf("%c\n", *str2++);
	}
	return 0;

}
