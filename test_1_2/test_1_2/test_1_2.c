#include <stdio.h>

//char - �ַ�����
//%d - ��ӡ����
//%c - ��ӡ�ַ�
//%f - ��ӡ�������� - С��
//%p - �Ե�ַ����ʽ��ӡ
//%x - ��ӡ16��������...
int main()
{
	char ch = 'A';//�����ڴ棬Ϊ�洢������Ϊch���洢����ΪA
	printf("%c\n",ch);//%c - ��ӡ�ַ���ʽ������
	int age = 20;
	printf("%d\n", age);//%d - ��ӡ����ʮ��������
	float f = 5.0;
	printf("%f\n", f);
	double d = 5.0;
	printf("%lf\n", d);

	printf("%d\n", sizeof(char));//1B
	printf("%d\n", sizeof(short));//2B
	printf("%d\n", sizeof(int));//4B
	printf("%d\n", sizeof(long));//4B
	printf("%d\n", sizeof(long long));//8B
	printf("%d\n", sizeof(float));//4B
	printf("%d\n", sizeof(double));//8B
	return 0;
}