// ts1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* in, *out;
	in = fopen("./notepad.exe","rb");//打开输入文件
	if(in == NULL)
	{
		printf("打开文件失败\n");
		exit(1);
	}
	fseek(in,0,SEEK_END);//将文件指针定位在程序的末尾，方便用ftell计算偏移
	long len =  ftell(in);//此时的偏移即为文件的大小
	printf("%ld\n",len);
	char* p = (char*)malloc(len);//动态申请一段空间来存放文件
	if(p == NULL)
	{
		printf("申请空间失败");
		exit(1);
	}
	out = fopen("./out.exe","wb");
	int i=0;
	char temp;    //定义一个char变量，来保存每次读取的字节
	for(i=0;i<len;i++)
	{
		fseek(in,i,SEEK_SET);//对指针进行定位
		fseek(out,i,SEEK_SET);
		temp = getc(in);//获得输入文件当前的一个字节数据
		p[i] = temp;//将文件的二进制数据全部存到内存（堆）中
		putc(temp,out);//将输入文件的每个字节转存到输出文件中
	}
	printf("\n%p\n",p);   //打印在内存中的文件数据的首地址
	fclose(in);
	fclose(out);//关闭文件
	return 0;
}