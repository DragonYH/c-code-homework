#include <stdio.h>

//char - 字符类型
//%d - 打印整形
//%c - 打印字符
//%f - 打印浮点数字 - 小数
//%p - 以地址的形式打印
//%x - 打印16进制数字...
int main()
{
	char ch = 'A';//分配内存，为存储地命名为ch，存储内容为A
	printf("%c\n",ch);//%c - 打印字符格式的数据
	int age = 20;
	printf("%d\n", age);//%d - 打印整形十进制数据
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