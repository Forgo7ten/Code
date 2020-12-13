// 结构体对齐
//

/*
- 原则一：数据成员对齐规则：结构的数据成员，第一个数据成员放在offset为0的地方，以后每个数据成员存储的起始位置要从该成员大小的整数倍开始(比如int在32位机为４字节，则要从4的整数倍地址开始存储).
- 原则二：结构体的总大小，也就是sizeof的结果，必须是其内部最大成员的整数倍，不足的要补齐。
- 原则三：如果一个结构里有某些结构体成员，则结构体成员要从其内部最大元素大小的整数倍地址开始存储。(struct a里存有struct  b，b里有char，int，double等元素，那b应该从8的整数倍开始存储.)
- 原则四：对齐参数如果比结构体成员的sizeof值小，该成员的偏移量应该以此值为准.也就是说，结构体成员的偏移量应该取二者的最小值.
*/


#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct s1
{
	char c;
	double i;
};

struct s4
{
	int c1;
	char c2[10];
};

struct s3
{
	char c1;
	s1 s;
	char c2;
	char c3;
};

struct s2
{
	char c1;
	s1 s;
	char c2;
	double c3;
};

int main()
{
	s1 one;
	one.c = 10;
	one.i = 10.5;
	printf("%d\n",sizeof(one));
	s4 two;
	two.c1 = 0x55555555;
	strcpy(two.c2,"5555555555");
	printf("%d\n",sizeof(two));
	s3 san;
	printf("%d\n",sizeof(san));
	s2 si;
	printf("%d\n",sizeof(si));
	return 0;
}