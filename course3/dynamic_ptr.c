/* 
 * Array �����Q��ָʾ����һ��Ԫ�ص�λַ
 * pointer ����++�Ą����ĕr����ᘌ�ָ����Y���͑B���Ӝp
 * �ӑB������g�ĕr���ǂ����g����heap, �����҂���Ȼ����ָ��׃����stack
 * ����:
 *		int *ptr = malloc(sizeof(int) * 100);
 *		���� malloc �҂���ӛ���w�е�heap�^��Ҫȡ�� sizeof(int) * 100 �@�Ӵ�С�Ŀ��g
 *		����ptr�@��׃���Ǵ������e�أ� �@��׃���Ǵ����stack��!
 *
 */



#include<stdio.h>
#include<stdlib.h>


int main()
{


	int(*ptr)[4] = malloc(sizeof(int) * 10);
	printf("\nsizeof *ptr : %zu\n", sizeof(*ptr));
	
	/* ԇ���f�� ptr + 1 ӛ���wλַ���О� 
	 * &ptr ��  ptr �Ĳ�e��ʲ�N? ( hint : �^�씵ֵ�� Ո��ӛ���wheap, stack ȥ˼�� )
	 */
	printf("ptr    : %p\n", ptr);
	printf("ptr + 1: %p\n", ptr + 1);
	printf("address of ptr : %p\n\n", &ptr);
	free(ptr);


	/* �^���������r, ������������ָ��+1��׃��*/
	double	(*ptr_to_double) = malloc(sizeof(double));
	int 	(*ptr_to_int)	 = malloc(sizeof(int));

	printf("ptr_to_double    : %p\n", ptr_to_double);
	printf("ptr_to_double + 1: %p\n\n", ptr_to_double + 1);

	printf("ptr_to_int     : %p\n", ptr_to_int);
	printf("ptr_to_int + 1 : %p\n\n", ptr_to_int + 1);





	/* ���X�Þ�ʲ�N�������r �����治һ�ӣ� 
	 * ͬ�ӵ���ӛ���ĵĽǶȷ���
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
