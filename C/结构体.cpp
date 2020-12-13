// 结构体练习
// 20200505

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct zb {
	double x;
	double y;
	double z;
};

struct Monster {
	char name[20];
	int id;
	int level;
	int hp;
	zb zuob;

};
Monster guai[10];
void func1()
{
	srand(time(0));
	int i;
	for (i = 0; i < 10; i++)
	{
		strcpy(guai[i].name, "guai");
		guai[i].name[4] = i + '0';
		guai[i].id = i;
		guai[i].hp = rand() % 100;
		guai[i].level = rand() % 100;
		guai[i].zuob.x = rand() % 10000 / 100;
		guai[i].zuob.y = rand() % 10000 / 100;
		guai[i].zuob.z = rand() % 10000 / 100;
	}


}
void func2(int id)
{
	printf("姓名：%s\n", guai[id].name);
	printf("等级：%d\n", guai[id].level);
	printf("血量：%d\n", guai[id].hp);
	printf("坐标x：%.2f\n", guai[id].zuob.x);
	printf("坐标y：%.2f\n", guai[id].zuob.y);
	printf("坐标z：%.2f\n", guai[id].zuob.z);

}

int main()
{
	func1();
	printf("请输入怪物ID来查看其属性,输入10退出\n");
	int id;
	scanf("%d", &id);
	while (id != 10)
	{
		func2(id);
		scanf("%d", &id);
	}

	return 0;
}
