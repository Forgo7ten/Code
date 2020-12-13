#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int data[81] = {
	2,5,0,1,4,0,6,8,9,
	0,0,8,9,0,6,2,0,5,
	6,7,9,2,5,8,1,4,3,
	3,1,2,5,8,4,7,0,0,
	0,8,0,7,9,0,5,3,2,
	5,9,7,0,6,2,8,1,0,
	7,2,4,0,1,3,0,5,8,
	8,6,5,4,7,9,3,0,1,
	9,3,1,8,2,5,4,0,0
};
const char aput[] = "Please enter your flag:";
const char asuccess[] = "Congratulations, you successfully solved this little problem!";
const char error[] = "Illegal input!";
void panduan(int* data);
void pdhang(int* data);
void pdlie(int* data);
void pdkuai(int* data);
void zhuanhuan(char* str);
void charu(char* str,int*data);
void fail();
int main()
{
	char s[19],flag[19];
	int len;
	printf("%s", aput);
	scanf("%s",s);
	len = -1;
	do {
		len++;
		flag[len] = s[len];
	}while (s[len]);
	zhuanhuan(s);
	charu(s,data);
	panduan(data);
	puts(asuccess);
	printf("flagÎª£ºflag{%s",flag);
	printf("}");
	return 0;
}
void zhuanhuan(char* str)
{
	int len,i;
	len = -1;
	do
		len++;
	while (str[len]);
	for (i = 0; i < len; i++)
	{
		if (str[i] < 65 || str[i] > 90)
			if (str[i] >= 97 && str[i] < 107)
				str[i] -= 96;
	}
}
void charu(char* str, int* data)
{
	int i, j;
	for (i = 0,j=0; i < 81; i++)
	{
		if (data[i] == 0)
			data[i] = str[j++];
	}
}
void pdkuai(int* data)
{
	char pd[12];
	int  i, j,k,h=0,l=0,n;
	for (i = 0; i < 9; i++)
	{
		memset(pd, 0, 10);
		for (j = h; j < h + 3; j++)
			for (k = l; k < l + 3; k++)
				pd[data[j * 9 + k]] = 1;
		for (n = 0; n < 9; n++)
			if (pd[n + 1] == 0)
				fail();
		if (l + 3 == 9)
		{
			h += 3;
			l = 0;
		}
		else
			l += 3;
	}
}
void pdlie(int* data)
{
	char pd[12];
	int i, j,k;
	for (k = 0; k < 9; k++)
	{
		memset(pd, 0, 10);
		for (j = 0; j < 9; j++)
			pd[data[j * 9 + k]] = 1;
		for (i = 0; i < 9; i++)
			if (pd[i + 1] == 0)
				fail();
	}
		
}
void pdhang(int* data)
{
	char pd[12];
	int i, j,k;
	for (k = 0; k < 9; k++)
	{
		memset(pd, 0, 10);
		for (j = 0; j < 9; j++)
			pd[data[k * 9 + j]] = 1;
		for (i = 0; i < 9; i++)
			if (pd[i + 1] == 0)
				fail();
	}
}
void panduan(int* data)
{
	pdhang(data);
	pdlie(data);
	pdkuai(data);
}
void fail()
{
	puts(error);
	exit(0);
}