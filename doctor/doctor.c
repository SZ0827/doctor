#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
//医生管理系统
typedef struct doctor
{
	char ID1[10];        //医生编号
	char name1[100];          //医生姓名
	char work[100];       //医生所属科室及职位名称
	struct doctor* next1;
}node3;
typedef struct patient
{
	char ID[10];
	char name[10];
	char bingli[300];
	int cost[3];
	char zhenz[300];
	struct patient* next;
}node1;
typedef struct storage
{
	int amount[3];
	int price[3];
}node2;
node2 init(node2 temp)
{

	temp.amount[0] = 20;
	temp.amount[1] = 20;
	temp.amount[2] = 10;
	temp.price[0] = 5;
	temp.price[1] = 9;
	temp.price[2] = 16;
	return temp;
}

void mainmeun()
{
	printf("\n");
	printf("      欢迎使用名医管理系统-------患者篇\n");
	printf("********************************\n");
	printf("1.注册新病人信息\n");
	printf("3.写自己症状\n");
	printf("7.保存\n");
	printf("9.离开\n");
	printf("*********************************\n");
}
void mainmeun1()
{
	printf("\n");
	printf("      欢迎使用名医管理系统-------医生篇\n");
	printf("********************************\n");
	printf("1.注册医生信息\n");
	printf("2.按ID查询医生信息\n");
	printf("3.编写医生所属科室及职位名称\n");
	printf("5.列出所有医生信息\n");
	printf("6.查询病人信息\n");
	printf("7.注册病人信息\n");
	printf("10.写病历\n");
	printf("11.病人消费\n");
	printf("4.修改病人病历\n");
	printf("12.列出所有病人信息\n");
	printf("13.载入所有病人信息\n");
	printf("14.保存\n");
	printf("15.查询药品库存\n");
	printf("9.离开\n");
	printf("*********************************\n");
}
void login()

{
	system("cls");
	system("color f5");
	char name[10];
	char password[10];
	printf("\n\n\n\n\n\n\n\n\n\n\n");
in:printf("请输入用户名：");
	gets(name);
	printf("请输入密码：");
	gets(password);
	if (strcmp(name, "SZ") == 0 && strcmp(password, "2001827") == 0)
	{
		printf("登录成功！！！");
		system("cls");       //清屏
	}
	else
	{
		printf("用户名或密码错误，登录失败！！！\n");
		printf("请重新输入：\n");
		goto in;
	}
}
node3* create1(node3* p2)
{
	node3* p3;
	p3 = (node3*)malloc(sizeof(node3));
	printf("请输入医生ID\n");
	scanf("%s", p3->ID1);

	while (p2->ID1 && strcmp(p2->ID1, p3->ID1))
	{
		p2 = p2->next1;
	}
	if (p2 == NULL)
	{
		printf("请输入医生姓名\n");
		scanf("%s", p3->name1);
		p3->next1 = NULL;
		printf("已注入您的信息\n");
		return p3;
	}
	else
	{
		printf("输入医生ID以存在,注册失败\n");
		return p3;
	}
}
node3* insert1(node3* head1, node3* p3)
{
	node3* p2;
	if (head1 == NULL)
	{
		head1 = p3;
		p3->next1 = NULL;
	}
	else
	{
		p2 = head1;
		while (p2->next1)
		{
			p2 = p2->next1;
		}
		p2->next1 = p3;
		p3->next1 = NULL;
	}
	return(head1);
}
//ID查找医生
void search1(node3* p2)
{

	char a[10];
	printf("请输入医生ID\n");
	scanf("%s", a);
	while (p2->ID1 && strcmp(p2->ID1, a))
	{
		p2 = p2->next1;
	}
	if (p2)
	{
		printf("ID:%s\n", p2->ID1);
		printf("姓名:%s\n", p2->name1);
		printf("科室:%s\n", p2->work);

	}
	else
		printf("该医生没有注册\n");


}
void work(node3* p3)
{
	char a[10];
	char work[300];
	char enter[5] = "\n";
	printf("请输入医生ID\n");
	scanf("%s", a);
	while (p3->ID1 && strcmp(p3->ID1, a))
	{
		p3 = p3->next1;
	}
	if (p3 == NULL)
	{
		printf("无该医生信息\n");
	}
	else
	{
		printf("请写科室名称:\n");
		scanf("%s", work);
		strcpy(p3->work, work);
		strcat(p3->work, enter);
	}
}
void list1(node3* p3)
{

	if (p3 == NULL)
		printf("尚无医生信息\n");
	else
	{
		do {
			printf("医生ID:%s\n", p3->ID1);
			printf("医生姓名:%s\n", p3->name1);
			printf("医生科室及相关职称:%s\n", p3->work);
			printf("\n");
			p3 = p3->next1;
		} while (p3 != NULL);
	}
}
node1* create(node1* p1)
{
	node1* p;
	p = (node1*)malloc(sizeof(node1));
	printf("请输入病人ID\n");
	scanf("%s", p->ID);

	while (p1->ID && strcmp(p1->ID, p->ID))
	{
		p1 = p1->next;
	}
	if (p1 == NULL)
	{
		printf("请输入病人姓名\n");
		scanf("%s", p->name);
		strcpy(p->bingli, "0");
		p->cost[0] = 0;
		p->cost[1] = 0;
		p->cost[2] = 0;
		p->next = NULL;
		printf("已注入您的信息\n");
		return p;
	}
	else
	{
		printf("输入病人ID以存在,注册失败\n");
		return p;
	}
}
node1* insert(node1* head, node1* p)
{
	node1* p1;
	if (head == NULL)
	{
		head = p;
		p->next = NULL;
	}
	else
	{
		p1 = head;
		while (p1->next)
		{
			p1 = p1->next;
		}
		p1->next = p;
		p->next = NULL;
	}
	return(head);
}
void search(node1* p1)
{
	int sum;
	char a[10];
	printf("请输入病人ID\n");
	scanf("%s", a);
	while (p1->ID && strcmp(p1->ID, a))
	{
		p1 = p1->next;
	}
	if (p1)
	{
		printf("ID:%s\n", p1->ID);
		printf("姓名:%s\n", p1->name);
		printf("病例:%s\n", p1->bingli);
		printf("消费记录:\n");
		if (p1->cost[0])
			printf("云南白药\t%d\n", p1->cost[0]);
		if (p1->cost[1])
			printf("天麻\t%d\n", p1->cost[1]);
		if (p1->cost[2])
			printf("阿莫西林\t%d\n", p1->cost[2]);
		sum = p1->cost[0] + p1->cost[1] + p1->cost[2];
		printf("总费用\t%d\n", sum);
	}
	else
		printf("该病人没有注册\n");


}
//编写病历
void bingli(node1* p)
{
	char a[10];
	char bingli[300];
	char enter[5] = ":\n";
	printf("请输入病人ID\n");
	scanf("%s", a);
	while (p->ID && strcmp(p->ID, a))
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("无该病人信息\n");
	}
	else
	{
		printf("病人姓名为:%s\n", p->name);
		printf("请写病例:\n");
		scanf("%s", bingli);
		strcpy(p->bingli, bingli);
		strcat(p->bingli, enter);
	}
}
//修改病人病历
void xiugai(node1* p1)
{

	char a[10];
	printf("请输入病人ID\n");
	scanf("%s", a);
	while (p1->ID && strcmp(p1->ID, a))
	{
		p1 = p1->next;
	}
	if (p1)
	{
		printf("病人原来病历为：%s\n", p1->bingli);
		printf("请输入现在要修改的病历:\n");
		scanf("%s", p1->bingli);
		printf("病人现在病历为：%s\n", p1->bingli);
		printf("修改完成\n");

	}
	else
		printf("该病人没有注册\n");


}
//患者症状
void zhenz(node1* p)
{
	char a[10];
	char zhenz[300];
	char enter[5] = ":\n";
	printf("请输入病人ID\n");
	scanf("%s", a);
	while (p->ID && strcmp(p->ID, a))
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("无该病人信息\n");
	}
	else
	{
		printf("请写症状:\n");
		scanf("%s", zhenz);
		strcpy(p->zhenz, zhenz);
		strcat(p->zhenz, enter);
	}
}
node2 buy(node1* p, node2 temp)
{
	char i[10];
	printf("请输入病人ID\n");
	scanf("%s", i);
	while (p->ID && strcmp(p->ID, i))
	{
		p = p->next;
	}

	while (1)
	{
	in:
		int a;
		printf("1.购买云南白药\n");
		printf("2.购买天麻\n");
		printf("3.购买阿莫西林\n");
		printf("0.退出\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("现有库存%d\n", temp.amount[0]);
			printf("购买云南白药数量:");
			int b;
			scanf("%d", &b);
			if (b > 0 && b <= temp.amount[0])
			{

				temp.amount[0] = temp.amount[0] - b;
				p->cost[0] += b * 5;
			}
			else
				printf("药品数量不够或输入有误\n");
			goto in;
			break;
		case 2:
			printf("现有库存%d\n", temp.amount[1]);
			printf("购买天麻数量:");
			int c;
			scanf("%d", &c);
			if (c > 0 && b <= temp.amount[1])
			{

				temp.amount[1] = temp.amount[1] - c;
				p->cost[1] += c * 9;
			}
			else
				printf("药品数量不够或输入有误\n");
			goto in;
			break;
		case 3:
			printf("现有库存%d\n", temp.amount[2]);
			printf("购买阿莫西林数量:");
			int e;
			scanf("%d", &e);
			if (e > 0 && b <= temp.amount[2])
			{

				temp.amount[2] = temp.amount[2] - e;
				p->cost[2] += e * 16;
			}
			else
				printf("药品数量不够或输入有误\n");
			goto in;
			break;
		case 0:
			return temp;
		}
	}

}
void list(node1* p)
{

	if (p == NULL)
		printf("尚无病人信息\n");
	else
	{
		do {
			printf("病人ID:%s\n", p->ID);
			printf("病人姓名:%s\n", p->name);

			printf("病人病例:%s\n", p->bingli);

			printf("购买云南白药费用:%d\n", p->cost[0]);

			printf("购买天麻费用:%d\n", p->cost[1]);

			printf("购买阿莫西林费用:%d\n", p->cost[2]);
			printf("\n");
			p = p->next;
		} while (p != NULL);
	}
}
node1* load(node1* p)
{
	char ID[10], name[10], bingli[300];
	int cost0, cost1, cost2;
	FILE* fp;
	fp = fopen("E:/information.txt", "r");
	int n = 0;
	node1* p1, * p2 = NULL;;

	while (!feof(fp))
	{
		n++;
		p1 = (node1*)malloc(sizeof(node1));
		fscanf(fp, "%s", ID);
		fscanf(fp, "%s", name);
		fscanf(fp, "%s", bingli);
		fscanf(fp, "%d", &cost0);
		fscanf(fp, "%d", &cost1);
		fscanf(fp, "%d", &cost2);

		strcpy(p1->ID, ID);
		strcpy(p1->name, name);
		strcpy(p1->bingli, bingli);
		p1->cost[0] = cost0;
		p1->cost[1] = cost1;
		p1->cost[2] = cost2;
		p1->next = NULL;

		if (n == 1)
		{
			p = p1;
			p2 = p1;
		}

		else
		{
			p2->next = p1;
			p2 = p1;

		}
	}

	fclose(fp);

	return p;
}
void save(node1* p)
{
	FILE* fp;
	fp = fopen("information.txt", "w");
	if (p != NULL)
		do {
			fprintf(fp, "%s\n", p->ID);
			fprintf(fp, "%s\n", p->name);
			fprintf(fp, "%s\n", p->bingli);
			fprintf(fp, "%s\n", p->zhenz);
			fprintf(fp, "%d\n", p->cost[0]);
			fprintf(fp, "%d\n", p->cost[1]);
			fprintf(fp, "%d\n", p->cost[2]);
			p = p->next;
			printf("信息保存成功\n");
		} while (p != NULL);
		fclose(fp);
}

void liststock(node2 temp)
{
	printf("药品\t数量\t价格\t\n");
	printf("云南白药\t%d\t%d\t\n", temp.amount[0], temp.price[0]);
	printf("天麻\t%d\t%d\t\n", temp.amount[1], temp.price[1]);
	printf("阿莫西林\t%d\t%d\t\n", temp.amount[2], temp.price[2]);

}
chose()
{

	login();
	printf("\n");
in:	printf("      欢迎使用名医管理系统\n");
	printf("********************************\n");
	printf("1.进入患者篇\n");
	printf("2.进入医生篇\n");
	printf("0.退出\n");
	node1* head = NULL, * p;
	node2 temp = {0,0};
	temp = init(temp);
	node3* head1 = NULL, * p3;
	int t;
	scanf("%d", &t);
	switch (t)
	{
	case  1:
		while (1)
		{
			mainmeun();
			int a;
			scanf("%d", &a);
			switch (a)
			{
			case 1:
				p = create(head);
				head = insert(head, p);
				break;
			case 3:
				system("cls");
				zhenz(head);
				break;
			case 7:
				system("cls");
				save(head);
				break;
			case 9:
				system("cls");
				goto in;
				break;
			default:
				printf("输入有误，重新输入\n");
				break;
			}
		}
		break;
	case 2:
		while (1)
		{
		on:	mainmeun1();
			int a;
			scanf("%d", &a);
			switch (a)
			{
			case 7:
				p = create(head);
				head = insert(head, p);
				break;
			case 1:
				p3 = create1(head1);
				head1 = insert1(head1, p3);
				break;
			case 2:
				system("cls");
				search1(head1);
				break;
			case 3:
				system("cls");
				work(head1);
				break;
			case 4:
				system("cls");
				xiugai(head);
				goto on;
				break;
			case 5:
				system("cls");
				list1(head1);
				break;
			case 6:
				system("cls");
				search(head);
				break;
			case 10:
				system("cls");
				bingli(head);
				buy(head, temp);
				break;
			case 11:
				system("cls");
				temp = buy(head, temp);
				break;
			case 12:
				system("cls");
				list(head);
				break;
			case 13:
				system("cls");
				head = load(head);
				break;
			case 14:
				system("cls");
				save(head);
				break;
			case 15:
				system("cls");
				liststock(temp);
				break;
			case 9:
				system("cls");
				printf("谢谢使用\n");
				return(0);
			default:
				printf("输入有误，重新输入\n");
				break;
			}
		}     break;
	case 0:
		printf("谢谢使用\n");
		return(0);
	default:
		printf("输入有误，重新输入\n");
		break;
	}
}
void main()
{

	chose();
}