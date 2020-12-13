#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define tea_DELTA 0x9e3779b9
#define xxtea_MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (key[(p&3)^e] ^ z)))
const char biao[] = "ace_yunTh5";
const char aput0[] = "What will you do when your partner becomes your enemy?";
char aput1[] = {84,104,114,112,62,70,105,106,109,41,107,101,104,45,124,106,102,116,96,96,113,53,98,127,113,106,58,111,115,114,114,63,89,78,87,3,81,86,67,67,9};
const char aput2[] = "Please enter your flag:";
const char asuccess[] = "Congratulations, you successfully solved this little problem!";
const char error[] = "Illegal input!";
const char astart[] = "\nI believe the previous dessert won't beat you.Now we begin to eat a big meal.";


void z16(char* str, const int str_len, uint32_t* p);
void jiami(char* str0, char* str);
void xxtea(uint32_t* origin, int n, uint32_t const key[4]);
void jiaohuan(char* str);
void jiami1(char* s, char* s0, char* s1);
void start()
{
	puts(astart);
	for (int i = 0; i < strlen(aput1); i++)
		printf("%c", aput1[i] ^ i);
	printf("\n\n");
}
int main(void)
{
	int len_s;
	char s[23] = { 0 };
	char* key, * s0 = NULL, * s1 = NULL;
	unsigned char* xx, * xx0;
	int ii0, ii1, i0, j0, i1, data[3] = {0};
	uint32_t* enstr, * key0;
    printf("%s\n", aput0);
	printf("%s", aput2);
	scanf("%s", &s);
	len_s = -1;
	do
		len_s++;
	while (*(s + len_s));
	if (
		(len_s != 22) ||
		(*s != 'f') ||
		(*(s + 1) != 'l') ||
		(*(s + 2) != 'a') ||
		(*(s + 3) != 'g') ||
		(*(s + 4) != '{') ||
		(*(s + 21) != '}')
		)
	{
	fail:
		puts(error);
		exit(0);
	}
	for (ii0 = 5; ii0 < strlen(s) - 1; ii0++)
		if (!strchr(biao, s[ii0]))
			goto fail;
	s0 = (char*)calloc(17, sizeof(char));
	s1 = (char*)calloc(9, sizeof(char));
	jiami1(s, s0, s1);
	start();
	i1 = strchr(s, '{') - s + 1;
	key = (char*)calloc(i1, sizeof(s[0]));
	memcpy(key, s, 4);//
	key0 = (uint32_t*)calloc(4, sizeof(uint32_t));
	enstr = (uint32_t*)calloc(2, sizeof(uint32_t));
	z16(s1, strlen(s1), enstr);
	z16(key, strlen(key), key0);
	xxtea(enstr, 2, key0);
	puts("I hope this big meals can make you satisfied.\n");
	data[0] = 0x946ef21f;
	xx = (unsigned char*)data;
	data[1] = 0x58cd91af;
	xx0 = (unsigned char*)enstr;

	ii0 = -1;
	do
		ii0++;
	while (xx[ii0]);
	for (ii1 = 0; ii1 < ii0; ii1++)
		*(xx + ii1) ^= 100 + ii1;
	for (ii1 = 0; ii1 < ii0; ii1++)
		if (*(xx + ii1) != *(xx0 + ii1))
			goto fail;
	puts(asuccess);
	return 0;

}
void jiami1(char* s, char* s0, char* s1)
{
	memcpy(s0, strchr(s, '{') + 1, 16);
	jiaohuan(s0);
	jiaohuan(s0 + 1);
	jiami(s1, s0);
}
void z16(char* str, const int str_len, uint32_t* p)
{
	int i, j;
	for (i = 0; 4 * i < str_len; i++)
	{
		int k = 0;
		for (j = 0; j < 4; j++)
		{
			p[i] += (unsigned int)str[4 * i + j] << k;
			k += 8;
		}
	}
}
void jiaohuan(char* str)
{
	int i;
	char k;
	for (i = 0; i < strlen(str); i += 4)
	{
		k = str[i];
		str[i] = str[i + 2];
		str[i + 2] = k;
	}
}
void jiami(char* str0, char* str)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		*(str + 2 * i) = strchr(biao, *(str + 2 * i)) - biao;
		*(str0 + i) = *(str + 2 * i) * 10 + strchr(biao, *(str + 2 * i + 1)) - biao;
	}
}
void xxtea(uint32_t* origin, int n, uint32_t const key[4])
{
	uint32_t y, z, sum;
	unsigned p, rounds, e;
	if (n < -1)            /* Coding Part */
	{
		n = -n;
		rounds = 6 + 52 / n;
		sum = 0;
		z = origin[n - 1];
		do
		{
			sum += tea_DELTA;
			e = (sum >> 2) & 3;
			for (p = 0; p < n - 1; p++)
			{
				y = origin[p + 1];
				z = origin[p] += xxtea_MX;
			}
			y = origin[0];
			z = origin[n - 1] += xxtea_MX;
		} while (--rounds);
	}
	else if (n > 1)      /* Decoding Part */
	{
		rounds = 6 + 52 / n;
		sum = rounds * tea_DELTA;
		y = origin[0];
		do
		{
			e = (sum >> 2) & 3;
			for (p = n - 1; p > 0; p--)
			{
				z = origin[p - 1];
				y = origin[p] -= xxtea_MX;
			}
			z = origin[n - 1];
			y = origin[0] -= xxtea_MX;
			sum -= tea_DELTA;
		} while (--rounds);
	}
}
