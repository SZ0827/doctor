#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
//ҽ������ϵͳ
typedef struct doctor
{
	char ID1[10];        //ҽ�����
	char name1[100];          //ҽ������
	char work[100];       //ҽ���������Ҽ�ְλ����
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
	printf("      ��ӭʹ����ҽ����ϵͳ-------����ƪ\n");
	printf("********************************\n");
	printf("1.ע���²�����Ϣ\n");
	printf("3.д�Լ�֢״\n");
	printf("7.����\n");
	printf("9.�뿪\n");
	printf("*********************************\n");
}
void mainmeun1()
{
	printf("\n");
	printf("      ��ӭʹ����ҽ����ϵͳ-------ҽ��ƪ\n");
	printf("********************************\n");
	printf("1.ע��ҽ����Ϣ\n");
	printf("2.��ID��ѯҽ����Ϣ\n");
	printf("3.��дҽ���������Ҽ�ְλ����\n");
	printf("5.�г�����ҽ����Ϣ\n");
	printf("6.��ѯ������Ϣ\n");
	printf("7.ע�Ს����Ϣ\n");
	printf("10.д����\n");
	printf("11.��������\n");
	printf("4.�޸Ĳ��˲���\n");
	printf("12.�г����в�����Ϣ\n");
	printf("13.�������в�����Ϣ\n");
	printf("14.����\n");
	printf("15.��ѯҩƷ���\n");
	printf("9.�뿪\n");
	printf("*********************************\n");
}
void login()

{
	system("cls");
	system("color f5");
	char name[10];
	char password[10];
	printf("\n\n\n\n\n\n\n\n\n\n\n");
in:printf("�������û�����");
	gets(name);
	printf("���������룺");
	gets(password);
	if (strcmp(name, "SZ") == 0 && strcmp(password, "2001827") == 0)
	{
		printf("��¼�ɹ�������");
		system("cls");       //����
	}
	else
	{
		printf("�û�����������󣬵�¼ʧ�ܣ�����\n");
		printf("���������룺\n");
		goto in;
	}
}
node3* create1(node3* p2)
{
	node3* p3;
	p3 = (node3*)malloc(sizeof(node3));
	printf("������ҽ��ID\n");
	scanf("%s", p3->ID1);

	while (p2->ID1 && strcmp(p2->ID1, p3->ID1))
	{
		p2 = p2->next1;
	}
	if (p2 == NULL)
	{
		printf("������ҽ������\n");
		scanf("%s", p3->name1);
		p3->next1 = NULL;
		printf("��ע��������Ϣ\n");
		return p3;
	}
	else
	{
		printf("����ҽ��ID�Դ���,ע��ʧ��\n");
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
//ID����ҽ��
void search1(node3* p2)
{

	char a[10];
	printf("������ҽ��ID\n");
	scanf("%s", a);
	while (p2->ID1 && strcmp(p2->ID1, a))
	{
		p2 = p2->next1;
	}
	if (p2)
	{
		printf("ID:%s\n", p2->ID1);
		printf("����:%s\n", p2->name1);
		printf("����:%s\n", p2->work);

	}
	else
		printf("��ҽ��û��ע��\n");


}
void work(node3* p3)
{
	char a[10];
	char work[300];
	char enter[5] = "\n";
	printf("������ҽ��ID\n");
	scanf("%s", a);
	while (p3->ID1 && strcmp(p3->ID1, a))
	{
		p3 = p3->next1;
	}
	if (p3 == NULL)
	{
		printf("�޸�ҽ����Ϣ\n");
	}
	else
	{
		printf("��д��������:\n");
		scanf("%s", work);
		strcpy(p3->work, work);
		strcat(p3->work, enter);
	}
}
void list1(node3* p3)
{

	if (p3 == NULL)
		printf("����ҽ����Ϣ\n");
	else
	{
		do {
			printf("ҽ��ID:%s\n", p3->ID1);
			printf("ҽ������:%s\n", p3->name1);
			printf("ҽ�����Ҽ����ְ��:%s\n", p3->work);
			printf("\n");
			p3 = p3->next1;
		} while (p3 != NULL);
	}
}
node1* create(node1* p1)
{
	node1* p;
	p = (node1*)malloc(sizeof(node1));
	printf("�����벡��ID\n");
	scanf("%s", p->ID);

	while (p1->ID && strcmp(p1->ID, p->ID))
	{
		p1 = p1->next;
	}
	if (p1 == NULL)
	{
		printf("�����벡������\n");
		scanf("%s", p->name);
		strcpy(p->bingli, "0");
		p->cost[0] = 0;
		p->cost[1] = 0;
		p->cost[2] = 0;
		p->next = NULL;
		printf("��ע��������Ϣ\n");
		return p;
	}
	else
	{
		printf("���벡��ID�Դ���,ע��ʧ��\n");
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
	printf("�����벡��ID\n");
	scanf("%s", a);
	while (p1->ID && strcmp(p1->ID, a))
	{
		p1 = p1->next;
	}
	if (p1)
	{
		printf("ID:%s\n", p1->ID);
		printf("����:%s\n", p1->name);
		printf("����:%s\n", p1->bingli);
		printf("���Ѽ�¼:\n");
		if (p1->cost[0])
			printf("���ϰ�ҩ\t%d\n", p1->cost[0]);
		if (p1->cost[1])
			printf("����\t%d\n", p1->cost[1]);
		if (p1->cost[2])
			printf("��Ī����\t%d\n", p1->cost[2]);
		sum = p1->cost[0] + p1->cost[1] + p1->cost[2];
		printf("�ܷ���\t%d\n", sum);
	}
	else
		printf("�ò���û��ע��\n");


}
//��д����
void bingli(node1* p)
{
	char a[10];
	char bingli[300];
	char enter[5] = ":\n";
	printf("�����벡��ID\n");
	scanf("%s", a);
	while (p->ID && strcmp(p->ID, a))
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("�޸ò�����Ϣ\n");
	}
	else
	{
		printf("��������Ϊ:%s\n", p->name);
		printf("��д����:\n");
		scanf("%s", bingli);
		strcpy(p->bingli, bingli);
		strcat(p->bingli, enter);
	}
}
//�޸Ĳ��˲���
void xiugai(node1* p1)
{

	char a[10];
	printf("�����벡��ID\n");
	scanf("%s", a);
	while (p1->ID && strcmp(p1->ID, a))
	{
		p1 = p1->next;
	}
	if (p1)
	{
		printf("����ԭ������Ϊ��%s\n", p1->bingli);
		printf("����������Ҫ�޸ĵĲ���:\n");
		scanf("%s", p1->bingli);
		printf("�������ڲ���Ϊ��%s\n", p1->bingli);
		printf("�޸����\n");

	}
	else
		printf("�ò���û��ע��\n");


}
//����֢״
void zhenz(node1* p)
{
	char a[10];
	char zhenz[300];
	char enter[5] = ":\n";
	printf("�����벡��ID\n");
	scanf("%s", a);
	while (p->ID && strcmp(p->ID, a))
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf("�޸ò�����Ϣ\n");
	}
	else
	{
		printf("��д֢״:\n");
		scanf("%s", zhenz);
		strcpy(p->zhenz, zhenz);
		strcat(p->zhenz, enter);
	}
}
node2 buy(node1* p, node2 temp)
{
	char i[10];
	printf("�����벡��ID\n");
	scanf("%s", i);
	while (p->ID && strcmp(p->ID, i))
	{
		p = p->next;
	}

	while (1)
	{
	in:
		int a;
		printf("1.�������ϰ�ҩ\n");
		printf("2.��������\n");
		printf("3.����Ī����\n");
		printf("0.�˳�\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("���п��%d\n", temp.amount[0]);
			printf("�������ϰ�ҩ����:");
			int b;
			scanf("%d", &b);
			if (b > 0 && b <= temp.amount[0])
			{

				temp.amount[0] = temp.amount[0] - b;
				p->cost[0] += b * 5;
			}
			else
				printf("ҩƷ������������������\n");
			goto in;
			break;
		case 2:
			printf("���п��%d\n", temp.amount[1]);
			printf("������������:");
			int c;
			scanf("%d", &c);
			if (c > 0 && b <= temp.amount[1])
			{

				temp.amount[1] = temp.amount[1] - c;
				p->cost[1] += c * 9;
			}
			else
				printf("ҩƷ������������������\n");
			goto in;
			break;
		case 3:
			printf("���п��%d\n", temp.amount[2]);
			printf("����Ī��������:");
			int e;
			scanf("%d", &e);
			if (e > 0 && b <= temp.amount[2])
			{

				temp.amount[2] = temp.amount[2] - e;
				p->cost[2] += e * 16;
			}
			else
				printf("ҩƷ������������������\n");
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
		printf("���޲�����Ϣ\n");
	else
	{
		do {
			printf("����ID:%s\n", p->ID);
			printf("��������:%s\n", p->name);

			printf("���˲���:%s\n", p->bingli);

			printf("�������ϰ�ҩ����:%d\n", p->cost[0]);

			printf("�����������:%d\n", p->cost[1]);

			printf("����Ī���ַ���:%d\n", p->cost[2]);
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
			printf("��Ϣ����ɹ�\n");
		} while (p != NULL);
		fclose(fp);
}

void liststock(node2 temp)
{
	printf("ҩƷ\t����\t�۸�\t\n");
	printf("���ϰ�ҩ\t%d\t%d\t\n", temp.amount[0], temp.price[0]);
	printf("����\t%d\t%d\t\n", temp.amount[1], temp.price[1]);
	printf("��Ī����\t%d\t%d\t\n", temp.amount[2], temp.price[2]);

}
chose()
{

	login();
	printf("\n");
in:	printf("      ��ӭʹ����ҽ����ϵͳ\n");
	printf("********************************\n");
	printf("1.���뻼��ƪ\n");
	printf("2.����ҽ��ƪ\n");
	printf("0.�˳�\n");
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
				printf("����������������\n");
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
				printf("ллʹ��\n");
				return(0);
			default:
				printf("����������������\n");
				break;
			}
		}     break;
	case 0:
		printf("ллʹ��\n");
		return(0);
	default:
		printf("����������������\n");
		break;
	}
}
void main()
{

	chose();
}