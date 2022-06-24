//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//头文件引用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//变量定义
struct Student
{
	char id[20], //学号 
		name[20], //名字 
		date[20], //生日 
		native[20], //籍贯 
		num[20]; //电话号码 
};
struct Student stu[1000];
int count = 0, fcount = 0;
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//函数声明
void Menu_ALL();//总菜单显示 
void Menu_IN();	//录入菜单显示 
void Menu_SL();	//查询菜单显示
void Menu_CH();	//修改菜单显示
void Menu_DE();	//删除菜单显示

void Menu();	//主菜单 
void Start(); //初始化
void Save(); //保存到文件中 
void Select_ALL(int a);	//主菜单选择

void Imform_IN();	//信息录入
void Imform_SL();	//信息查询菜单 
void Imform_SL_id(); //信息查询--按学号查询 

void Imform_CH();	//信息修改菜单
void Imform_CH_id(); //按学号修改信息
void Imform_CH_name(); //按名字修改信息
void CH_id(const int p); //修改学号
void CH_name(const int p); //修改名字
void CH_date(int p); //修改生日
void CH_native(int p); //修改籍贯
void CH_num(int p); //修改号码

void Imform_DE(); //信息删除
void Imform_DE_id(); //按学号删除
void Imform_DE_name(); //按姓名删除

void Statistics(); //统计

void Save_son(int s[1000], const char n[]); //子信息输出 

void Sort(); //排序选择
void Sort_id();
void Sort_id_up();
void Sort_id_down();
void Sort_name();
void Sort_name_up();
void Sort_name_down();
void Sort_date();
void Sort_date_up();
void Sort_date_down();
void Sort_native();
void Sort_native_up();
void Sort_native_down();

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//菜单显示
void Menu_ALL() //总菜单显示 
{
	printf("##### 学生籍贯信息管理系统 #####\n\n");
	printf("##### 1. 录入信息          #####\n");
	printf("##### 2. 查询信息          #####\n");
	printf("##### 3. 修改信息          #####\n");
	printf("##### 4. 删除信息          #####\n");
	printf("##### 5. 统计籍贯          #####\n");
	printf("##### 6. 信息排序          #####\n");
	printf("##### 0. 退出程序          #####\n");
}

void Menu_IN()  //录入菜单显示 
{
	printf("#####       录入信息       #####\n\n");
	printf("##### 0. 返回上一级        #####\n");
	printf("##### 1. 从磁盘导入        #####\n");
	printf("##### 2. 单个录入          #####\n");
}

void Menu_SL()  //查询菜单显示 
{
	printf("#####       查询信息       #####\n\n");
	printf("##### 0. 返回上一级        #####\n");
	printf("##### 1. 按学号查询信息    #####\n");
	printf("##### 2. 按姓名查询信息    #####\n");
	printf("##### 3. 按籍贯查询信息    #####\n");
	printf("##### 4. 输出所有学生籍贯  #####\n");
}

void Menu_CH()  //修改菜单显示 
{
	printf("#####       修改信息       #####\n\n");
	printf("##### 0. 返回上一级        #####\n");
	printf("##### 1. 按学号修改信息    #####\n");
	printf("##### 2. 按姓名修改信息    #####\n");
}

void Menu_DE()	//删除菜单显示 
{
	printf("#####       删除信息       #####\n\n");
	printf("##### 0. 返回上一级        #####\n");
	printf("##### 1. 按学号删除信息    #####\n");
	printf("##### 2. 按姓名删除信息    #####\n");

}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//菜单
void Select_ALL(int a) //主菜单选择
{
	switch (a)
	{
	case 1:Imform_IN(); break;
	case 2:Imform_SL(); break;
	case 3:Imform_CH(); break;
	case 4:Imform_DE(); break;
	case 5:Statistics(); break;
	case 6:Sort(); break;
	case 0:exit(1); break;
	default: printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Menu(); break;

	}
}

void Menu()	//主菜单 
{
	system("cls");
	int n;
	Menu_ALL();
	scanf("%d", &n);
	Select_ALL(n);
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//信息查询及保存
void Imform_SL_all() //信息查询--输出所有
{
	system("cls");
	int flag = 0, s[1000] = { 0 };
	for (int i = 0; i < count; i++)
	{
		if (flag == 0) printf("         序号              学号        姓名            生日            籍贯             电话\n--------------------------------------------------------------------------------------------\n");
		printf("\t%4d|\t%14s|\t%10s|\t%10s|\t%10s|\t%11s|\n", i + 1, stu[i].id, stu[i].name, stu[i].date, stu[i].native, stu[i].num);
		printf("--------------------------------------------------------------------------------------------\n");
		s[flag] = i + 1;
		flag++;
	}
	if (flag == 0) printf("\033[41;3930;5m 未找到学生信息！！！\033[0m\n");
	else Save_son(s, "Output_ALL.txt"); //输出文件 
	system("pause");
	Imform_SL();
}

void Imform_SL_id() //信息查询--按学号查询 
{
	system("cls");
	char n[20];
	int flag = 0, s[1000] = { 0 };
	printf("请输入所要查询的学号：");
	scanf("%s", n);
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(n, stu[i].id))
		{
			if (flag == 0) printf("         序号              学号        姓名            生日            籍贯             电话\n--------------------------------------------------------------------------------------------\n");
			printf("\t%4d|\t%14s|\t%10s|\t%10s|\t%10s|\t%11s|\n", i + 1, stu[i].id, stu[i].name, stu[i].date, stu[i].native, stu[i].num);
			printf("--------------------------------------------------------------------------------------------\n");
			s[flag] = i + 1;
			flag++;
		}
	}
	if (flag == 0)
	{
		printf("\033[41;3930;5m 未找到学生信息！！！\033[0m\n");
		system("pause");
	}
	else
	{
		Save_son(s, "Output_ID.txt"); //输出文件
		system("pause");
	}
	Imform_SL();
}

void Imform_SL_name() //信息查询--按姓名查询 
{
	system("cls");
	char n[20];
	int flag = 0, s[1000] = { 0 };
	printf("请输入所要查询的姓名：");
	scanf("%s", n);
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(n, stu[i].name))
		{
			if (flag == 0) printf("         序号              学号        姓名            生日            籍贯             电话\n--------------------------------------------------------------------------------------------\n");
			printf("\t%4d|\t%14s|\t%10s|\t%10s|\t%10s|\t%11s|\n", i + 1, stu[i].id, stu[i].name, stu[i].date, stu[i].native, stu[i].num);
			printf("--------------------------------------------------------------------------------------------\n");
			s[flag] = i + 1;
			flag++;
		}
	}
	if (flag == 0) printf("\033[41;3930;5m 未找到学生信息！！！\033[0m\n");
	else Save_son(s, "Output_NAME.txt");
		system("pause");
	Imform_SL();
}

void Imform_SL_native() //信息查询--按籍贯查询 
{
	system("cls");
	char n[20];
	int flag = 0, s[1000] = { 0 };
	printf("请输入所要查询的籍贯：");
	scanf("%s", n);
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(n, stu[i].native))
		{
			if (flag == 0) printf("         序号              学号        姓名            生日            籍贯             电话\n--------------------------------------------------------------------------------------------\n");
			printf("\t%4d|\t%14s|\t%10s|\t%10s|\t%10s|\t%11s|\n", i + 1, stu[i].id, stu[i].name, stu[i].date, stu[i].native, stu[i].num);
			printf("--------------------------------------------------------------------------------------------\n");
			s[flag] = i + 1;
			flag++;
		}
	}
	if (flag == 0) printf("\033[41;3930;5m 未找到学生信息！！！\033[0m\n");
	else Save_son(s, "Output_NATIVE.txt");
		system("pause");
	Imform_SL();
}

void Imform_SL() //信息查询 
{
	system("cls");
	Menu_SL();
	int n;
	scanf("%d", &n);
	switch (n)
	{
	case 0: Menu(); break;
	case 1: Imform_SL_id(); break;
	case 2: Imform_SL_name(); break;
	case 3: Imform_SL_native(); break;
	case 4: Imform_SL_all(); break;
	default:printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Imform_SL(); break;
	}
}

void Imform_IN() //信息录入
{
	system("cls");
	int n;
	Menu_IN();
	scanf("%d", &n);
	if (n == 0) //返回上一级 
	{
		Menu();
	}
	else if (n == 1)//从磁盘导入
	{
		int i;
		system("cls");
		printf("请将文件命名为Input.txt放在程序根目录下。\n");
		printf("1. 确认\n");
		printf("2. 取消\n");
		scanf("%d", &i);
		if (i == 1)  //确认 
		{
			FILE* fp1;
			fp1 = fopen("Input.txt", "r");
			if (!fp1) //无文件报错 
			{
				printf("\033[41;3930;5m 未发现此文件！！！\033[0m\n\n");
				system("pause");
				Imform_IN();
			}
			else
			{
				for (count; !feof(fp1); count++)
				{
					fscanf(fp1, "%s %s %s %s %s", stu[count].id, stu[count].name, stu[count].date, stu[count].native, stu[count].num);
				}
				//存入文件
				Save();
				printf("信息录入成功！\n");
				fclose(fp1);
				system("pause");
				Menu();
			}
		}
		else if (i == 2) //返回 
		{
			Imform_IN();
		}
		else
		{
			printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n\n");
			system("pause");
			Imform_IN();
		}
	}
	else if (n == 2) //单个导入 
	{
		system("cls");
		printf("请输入学号：");
		scanf("%s", stu[count].id);
		system("cls");
		printf("请输入名字：");
		scanf("%s", stu[count].name);
		system("cls");
		printf("请输入生日：");
		scanf("%s", stu[count].date);
		system("cls");
		printf("请输入籍贯：");
		scanf("%s", stu[count].native);
		system("cls");
		printf("请输入号码：");
		scanf("%s", stu[count].num);
		system("cls");
		count++;
		Save();
		printf("录入成功！\n");
		system("pause");
		Menu();
	}
	else
	{
		printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n");
		system("pause");
		Imform_IN();
	}
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//修改信息
void Imform_CH() //信息修改
{
	system("cls");
	if(count == 0)
	{
		printf("\033[41;3930;5m 无数据存在！\033[0m\n");
		system("pause");
		Menu();
	}
	Menu_CH();
	int n;
	scanf("%d", &n);
	switch (n)
	{
	case 0: Menu(); break;
	case 1: Imform_CH_id(); break;
	case 2: Imform_CH_name(); break;
	default:printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Imform_SL(); break;
	}
}

void Imform_CH_id() //按学号修改
{
	system("cls");
	char n[20];
	int flag = 0, s[1000] = { 0 };
	printf("请输入所要查询的学号：");
	scanf("%s", n);
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(n, stu[i].id))
		{
			if (flag == 0) printf("         序号              学号        姓名            生日            籍贯             电话\n--------------------------------------------------------------------------------------------\n");
			printf("\t%4d|\t%14s|\t%10s|\t%10s|\t%10s|\t%11s|\n", i + 1, stu[i].id, stu[i].name, stu[i].date, stu[i].native, stu[i].num);
			printf("--------------------------------------------------------------------------------------------\n");
			s[flag] = i + 1;
			flag++;
		}
	}
	if (flag == 0) printf("\033[41;3930;5m 未找到学生信息！！！\033[0m\n");
	else
	{
		int n;
		printf("请选择修改内容：\n");
		printf("1. 学号\n2. 姓名\n3. 生日\n4. 籍贯\n5. 电话\n");
		scanf("%d", &n);
		switch (n)
		{
			case 1: CH_id(s[flag-1]-1); break;
			case 2: CH_name(s[flag-1]-1); break;
			case 3: CH_date(s[flag-1]-1); break;
			case 4: CH_native(s[flag-1]-1); break;
			case 5: CH_num(s[flag-1]-1); break;
			default: printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Menu(); break;
		}
	}
	system("pause");
	Imform_CH();
}

void Imform_CH_name() //按名字修改
{
	system("cls");
	char n[20];
	int flag = 0, s[1000] = { 0 };
	printf("请输入所要查询的姓名：");
	scanf("%s", n);
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(n, stu[i].name))
		{
			if (flag == 0) printf("         序号              学号        姓名            生日            籍贯             电话\n--------------------------------------------------------------------------------------------\n");
			printf("\t%4d|\t%14s|\t%10s|\t%10s|\t%10s|\t%11s|\n", i + 1, stu[i].id, stu[i].name, stu[i].date, stu[i].native, stu[i].num);
			printf("--------------------------------------------------------------------------------------------\n");
			s[flag] = i + 1;
			flag++;
		}
	}
	if (flag == 0) printf("\033[41;3930;5m 未找到学生信息！！！\033[0m\n");
	else
	{
		int n;
		printf("请选择修改内容：\n");
		printf("1. 学号\n2. 姓名\n3. 生日\n4. 籍贯\n5. 电话\n");
		scanf("%d", &n);
		switch (n)
		{
			case 1: CH_id(s[flag-1]-1); break;
			case 2: CH_name(s[flag-1]-1); break;
			case 3: CH_date(s[flag-1]-1); break;
			case 4: CH_native(s[flag-1]-1); break;
			case 5: CH_num(s[flag-1]-1); break;
			default: printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Menu(); break;
		}
	}
	system("pause");
	Imform_CH();
}

void CH_id(int p) //修改学号
{
	char n[20];
	printf("修改为：");
	scanf("%s", stu[p].id);
	printf("修改成功！\n");
	system("pause");
	Save();
	Imform_CH();
}

void CH_name(int p) //修改名字
{
	char n[20];
	printf("修改为：");
	scanf("%s", stu[p].name);
	printf("修改成功！\n");
	system("pause");
	Save();
	Imform_CH();
}

void CH_date(int p) //修改生日
{
	char n[20];
	printf("修改为：");
	scanf("%s", stu[p].date);
	printf("修改成功！");
	system("pause");
	Save();
	Imform_CH();
}

void CH_native(int p) //修改籍贯
{
	char n[20];
	printf("修改为：");
	scanf("%s", stu[p].native);
	printf("修改成功！\n");
	system("pause");
	Save();
	Imform_CH();
}

void CH_num(int p) //修改号码
{
	char n[20];
	printf("修改为：");
	scanf("%s", stu[p].num);
	printf("修改成功！\n");
	system("pause");
	Save();
	Imform_CH();
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//删除
void Imform_DE() //删除
{
	system("cls");
	if(count == 0)
	{
		printf("\033[41;3930;5m 无数据存在！\033[0m\n");
		system("pause");
		Menu();
	}
	Menu_DE();
	int n;
	scanf("%d",&n);
	switch (n)
	{
		case 0: Menu(); break;
		case 1: Imform_DE_id(); break;
		case 2: Imform_DE_name(); break;
		default:printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Imform_DE(); break;
	}
}

void Imform_DE_id() //按学号删除
{
	system("cls");
	char n[20];
	int flag = 0, s[1000] = { 0 };
	printf("请输入所要删除的学号：");
	scanf("%s", n);
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(n, stu[i].id))
		{
			if (flag == 0) printf("         序号              学号        姓名            生日            籍贯             电话\n--------------------------------------------------------------------------------------------\n");
			printf("\t%4d|\t%14s|\t%10s|\t%10s|\t%10s|\t%11s|\n", i + 1, stu[i].id, stu[i].name, stu[i].date, stu[i].native, stu[i].num);
			printf("--------------------------------------------------------------------------------------------\n");
			s[flag] = i + 1;
			flag++;
		}
	}
	if (flag == 0) printf("\033[41;3930;5m 未找到学生信息！！！\033[0m\n");
	else
	{
		for(int i = s[flag-1]-1; i < count; i++)
		{
			stu[i]=stu[i+1];
		}
		count--;
		printf("删除成功！\n");
	}
	Save();
	system("pause");
	Imform_DE();
}

void Imform_DE_name() //按姓名删除
{
		system("cls");
	char n[20];
	int flag = 0, s[1000] = { 0 };
	printf("请输入所要删除的姓名：");
	scanf("%s", n);
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(n, stu[i].name))
		{
			if (flag == 0) printf("         序号              学号        姓名            生日            籍贯             电话\n--------------------------------------------------------------------------------------------\n");
			printf("\t%4d|\t%14s|\t%10s|\t%10s|\t%10s|\t%11s|\n", i + 1, stu[i].id, stu[i].name, stu[i].date, stu[i].native, stu[i].num);
			printf("--------------------------------------------------------------------------------------------\n");
			s[flag] = i + 1;
			flag++;
		}
	}
	if (flag == 0) printf("\033[41;3930;5m 未找到学生信息！！！\033[0m\n");
	else
	{
		for(int i = s[flag-1]-1; i < count; i++)
		{
			stu[i]=stu[i+1];
		}
		count--;
		printf("删除成功！\n");
	}
	Save();
	system("pause");
	Imform_DE();
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//通用
void Start() //初始化 
{
	FILE* fp;
	fp = fopen("Saved.txt", "a+");
	for (count = 0; !feof(fp); count++)
	{
		fscanf(fp, "%s %s %s %s %s", stu[count].id, stu[count].name, stu[count].date, stu[count].native, stu[count].num);
	}
	count--;
	fcount = count;
}

void Save() //信息保存 
{
	// FILE* fp;
	// fp = fopen("Saved.txt", "a+");
	// for (fcount; fcount < count; fcount++)
	// {
	// 	fprintf(fp, "%s %s %s %s %s\n", stu[fcount].id, stu[fcount].name, stu[fcount].date, stu[fcount].native, stu[fcount].num);
	// }
	// fclose(fp);
	// Start();

	FILE* fp;
	fp = fopen("Saved.txt", "w");
	for (int i=0; i < count; i++)
	{
		fprintf(fp, "%s %s %s %s %s\n", stu[i].id, stu[i].name, stu[i].date, stu[i].native, stu[i].num);
	}
	fclose(fp);
	Start();
}

void Save_son(int s[1000], const char* p) //子信息输出 
{
	FILE* fp;
	fp = fopen(p, "w");
	int flag = 0;
	for (int i = 0; s[i] != 0; i++)
	{
		int k = s[i] - 1;
		if (!flag) fprintf(fp, "         序号              学号        姓名            生日            籍贯             电话\n--------------------------------------------------------------------------------------------\n");
		fprintf(fp, "\t%4d|\t%14s|\t%10s|\t%10s|\t%10s|\t%11s|\n", i + 1, stu[k].id, stu[k].name, stu[k].date, stu[k].native, stu[k].num);
		fprintf(fp, "--------------------------------------------------------------------------------------------\n");
		flag = 1;
	}
	fclose(fp);
	printf("已输出为：");
	printf(p);
	printf("\n\n");
}

void End()	//结尾回车 
{
	FILE* fp;
	fp = fopen("Saved.txt", "a");
	fprintf(fp, "\n");
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//统计
void Statistics() //统计人数排名前三的籍贯
{
	system("cls");
	if(count == 0)
	{
		printf("无数据存在！\n");
		system("pause");
		Menu();
	}
	int s[1000]={0};
	char st[1000][20];
	int sum1=0, sum2=0, sum3=0;
	for (int i=0; i<count; i++)
	{
		int flag=0;
		strcpy(st[i],stu[i].native);
		s[i]=1;
		if(flag==0)
		{
			for(int j=i; j<count; j++)
			{
				for(int k=0; k<i; k++)
				{
					if(strcmp(st[i],st[k])==0)
					{
						s[i]=0;
						flag=1;
						break;
					}
				}
				if(flag==1) break;
				else if(strcmp(st[i],stu[j+1].native)==0 && s[i]!=0) s[i]++;
			}
		}
	}
	for(int k=1; k<count; k++)
	{
		if(s[sum1]<s[k]) sum1=k;
	}
	for(int k=1; k<count; k++)
	{
		if(s[sum2]<s[k] && k!=sum1) sum2=k;
	}
	for(int k=1; k<count; k++)
	{
		if(s[sum3]<s[k] && k!=sum1 && k!=sum2) sum3=k;
	}
	int renshu=0;
	for(int i=0; i<count; i++)
	{
		if(s[i]==s[sum1])
		{
			printf("人数排名第一的籍贯：%s\t人数为：%d\n", stu[i].native, s[sum1]);
			renshu++;
		}
	}
	for(int i=0; i<count; i++)
	{
		if(s[i]==s[sum2] && s[i]!=s[sum1])
		{
			printf("人数排名第二的籍贯：%s\t人数为：%d\n", stu[i].native, s[sum2]);
			renshu++;
		}
	}
	for(int i=0; i<count; i++)
	{
		if(s[i]==s[sum3] && s[i]!=s[sum1] && s[i]!=s[sum2])
		{
			printf("人数排名第三的籍贯：%s\t人数为：%d\n", stu[i].native, s[sum3]);
			renshu++;
		}
	}
	system("pause");
	Menu();
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//扩展——排序
void Sort() //排序
{
	system("cls");
	if(count == 0)
	{
		printf("\033[41;3930;5m 无数据存在！\033[0m\n");
		system("pause");
		Menu();
	}
	printf("请选择要排序的内容：\n");
	printf("0. 返回上一级\n1. 按学号排序\n2. 按姓名排序\n3. 按生日排序\n4. 按籍贯排序\n");
	int n;
	scanf("%d", &n);
	switch (n)
	{
		case 0: Menu(); break;
		case 1: Sort_id(); break;
		case 2: Sort_name(); break;
		case 3: Sort_date(); break;
		case 4: Sort_native(); break;
		default:printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Imform_DE(); break;
		break;
	}
}

void Sort_id() //按学号排序
{
	system("cls");
	printf("0. 返回上一级\n1. 升序\n2. 降序\n");
	int n;
	scanf("%d", &n);
	switch (n)
	{
		case 0: Sort(); break;
		case 1: Sort_id_up(); break;
		case 2: Sort_id_down(); break;
		default:printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Sort(); break;
	}
}

void Sort_id_up() //按学号升序
{
	struct Student p[count];
	char s_id[20];
	int temp;
	for (int i = 0; i < count; i++)
	{
		temp=i;
		for(int j = i+1; j < count; j++)
		{
			if(strcmp(stu[temp].id, stu[j].id) > 0) temp=j;
		}
		if(temp!=i)
		{
			strcpy(s_id, stu[i].id);
			strcpy(stu[i].id, stu[temp].id);
			strcpy(stu[temp].id, s_id);
		}
	}
	Save();
	printf("排序成功！\n");
	system("pause");
	Sort();
}

void Sort_id_down() //按学号降序
{
	struct Student p[count];
	char s_id[20];
	int temp;
	for (int i = 0; i < count; i++)
	{
		temp=i;
		for(int j = i+1; j < count; j++)
		{
			if(strcmp(stu[temp].id, stu[j].id) < 0) temp=j;
		}
		if(temp!=i)
		{
			strcpy(s_id, stu[i].id);
			strcpy(stu[i].id, stu[temp].id);
			strcpy(stu[temp].id, s_id);
		}
	}
	Save();
	printf("排序成功！\n");
	system("pause");
	Sort();
}

void Sort_name() //按姓名排序
{
	system("cls");
	printf("0. 返回上一级\n1. 升序\n2. 降序\n");
	int n;
	scanf("%d", &n);
	switch (n)
	{
		case 0: Sort(); break;
		case 1: Sort_name_up(); break;
		case 2: Sort_name_down(); break;
		default:printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Sort(); break;
	}
}

void Sort_name_up() //按姓名升序
{
	struct Student p[count];
	char s_name[20];
	int temp;
	for (int i = 0; i < count; i++)
	{
		temp=i;
		for(int j = i+1; j < count; j++)
		{
			if(strcmp(stu[temp].name, stu[j].name) > 0) temp=j;
		}
		if(temp!=i)
		{
			strcpy(s_name, stu[i].name);
			strcpy(stu[i].name, stu[temp].name);
			strcpy(stu[temp].name, s_name);
		}
	}
	Save();
	printf("排序成功！\n");
	system("pause");
	Sort();
}

void Sort_name_down() //按姓名降序
{
	struct Student p[count];
	char s_name[20];
	int temp;
	for (int i = 0; i < count; i++)
	{
		temp=i;
		for(int j = i+1; j < count; j++)
		{
			if(strcmp(stu[temp].name, stu[j].name) < 0) temp=j;
		}
		if(temp!=i)
		{
			strcpy(s_name, stu[i].name);
			strcpy(stu[i].name, stu[temp].name);
			strcpy(stu[temp].name, s_name);
		}
	}
	Save();
	printf("排序成功！\n");
	system("pause");
	Sort();
}

void Sort_date() //按生日排序
{
	system("cls");
	printf("0. 返回上一级\n1. 升序\n2. 降序\n");
	int n;
	scanf("%d", &n);
	switch (n)
	{
		case 0: Sort(); break;
		case 1: Sort_date_up(); break;
		case 2: Sort_date_down(); break;
		default:printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Sort(); break;
	}
}

void Sort_date_up() //按生日升序
{
	struct Student p[count];
	char s_date[20];
	int temp;
	for (int i = 0; i < count; i++)
	{
		temp=i;
		for(int j = i+1; j < count; j++)
		{
			if(strcmp(stu[temp].date, stu[j].date) > 0) temp=j;
		}
		if(temp!=i)
		{
			strcpy(s_date, stu[i].date);
			strcpy(stu[i].date, stu[temp].date);
			strcpy(stu[temp].date, s_date);
		}
	}
	Save();
	printf("排序成功！\n");
	system("pause");
	Sort();
}

void Sort_date_down() //按生日降序
{
	struct Student p[count];
	char s_date[20];
	int temp;
	for (int i = 0; i < count; i++)
	{
		temp=i;
		for(int j = i+1; j < count; j++)
		{
			if(strcmp(stu[temp].date, stu[j].date) < 0) temp=j;
		}
		if(temp!=i)
		{
			strcpy(s_date, stu[i].date);
			strcpy(stu[i].date, stu[temp].date);
			strcpy(stu[temp].date, s_date);
		}
	}
	Save();
	printf("排序成功！\n");
	system("pause");
	Sort();
}

void Sort_native() //按籍贯排序
{
	system("cls");
	printf("0. 返回上一级\n1. 升序\n2. 降序\n");
	int n;
	scanf("%d", &n);
	switch (n)
	{
		case 0: Sort(); break;
		case 1: Sort_native_up(); break;
		case 2: Sort_native_down(); break;
		default:printf("\033[41;3930;5m 请正确输入对应序号！！！\033[0m\n"); system("pause"); Sort(); break;
	}
}

void Sort_native_up() //按籍贯升序
{
	struct Student p[count];
	char s_native[20];
	int temp;
	for (int i = 0; i < count; i++)
	{
		temp=i;
		for(int j = i+1; j < count; j++)
		{
			if(strcmp(stu[temp].native, stu[j].native) > 0) temp=j;
		}
		if(temp!=i)
		{
			strcpy(s_native, stu[i].native);
			strcpy(stu[i].native, stu[temp].native);
			strcpy(stu[temp].native, s_native);
		}
	}
	Save();
	printf("排序成功！\n");
	system("pause");
	Sort();
}

void Sort_native_down() //按籍贯降序
{
	struct Student p[count];
	char s_native[20];
	int temp;
	for (int i = 0; i < count; i++)
	{
		temp=i;
		for(int j = i+1; j < count; j++)
		{
			if(strcmp(stu[temp].native, stu[j].native) < 0) temp=j;
		}
		if(temp!=i)
		{
			strcpy(s_native, stu[i].native);
			strcpy(stu[i].native, stu[temp].native);
			strcpy(stu[temp].native, s_native);
		}
	}
	Save();
	printf("排序成功！\n");
	system("pause");
	Sort();
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//主函数
int main()
{
	system("chcp 65001"); //初始化终端编码为UTF-8
	printf("正在初始化......");
	Start();
	Menu();
	End();
}