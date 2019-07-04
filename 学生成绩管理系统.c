#define HEADER1 "|================================================学生及其选修课程信息================================================|\n"
#define HEADER2 "|------------|--------|------------|------|------|----------|----------------|------|----------|----------|----------|\n"
#define HEADER3 "|    学号    |  姓名  |    班级    | 性别 | 年龄 | 课程编号 |    课程名称    | 学分 | 平时成绩 | 考试成绩 | 综合成绩 |\n"
#define HEADER4 "|------------|--------|------------|------|------|----------|----------------|------|----------|----------|----------|\n"
#define FORMAT1 "|%-12s|%-8s|%-12s|  %2s  |  %2d  |%-10s|%-16s|  %2d  |  %-8.2lf|  %-8.2lf|  %-8.2lf|\n"
#define FORMAT2 "|            |        |            |      |      |%-10s|%-16s|  %2d  |  %-8.2lf|  %-8.2lf|  %-8.2lf|\n"
#define FORMAT3 "|            |        |            |      |      |%-10s|%-16s|  %2d  |  %-8.2lf|  %-8.2lf|  %-8.2lf|\n"
#define HEADER5 "|====================================================================================================================|\n"
#define DATA1 p->data.num,p->data.name,p->data.classes,p->data.sex,p->data.age,h->data.num1,h->data.name1,h->data.score1,h->data.usual1,h->data.test1,h->data.result1
#define DATA2 h->data.num2,h->data.name2,h->data.score2,h->data.usual2,h->data.test2,h->data.result2
#define DATA3 h->data.num3,h->data.name3,h->data.score3,h->data.usual3,h->data.test3,h->data.result3
#define HEADER6 "|==================不及格学生清单=================|\n"
#define HEADER7 "|------------|--------|----------------|----------|\n"
#define HEADER8 "|    学号    |  姓名  |    课程名称    | 综合成绩 |\n"
#define HEADER9 "|------------|--------|----------------|----------|\n"
#define FORMAT4 "|%-12s|%-8s|%-16s|  %-8.2lf|\n"
#define FORMAT5 "|            |        |%-16s|  %-8.2lf|\n"
#define FORMAT6 "|            |        |%-16s|  %-8.2lf|\n"
#define HEADER10 "|=================================================|\n"
#define DATA4 p->data.num,p->data.name,h->data.name1,h->data.result1
#define DATA5 p->data.num,p->data.name,h->data.name2,h->data.result2
#define DATA6 p->data.num,p->data.name,h->data.name3,h->data.result3
#define DATA8 h->data.name2,h->data.result2
#define DATA9 h->data.name3,h->data.result3
#define HEADER11 "|========================学生各门功课平均成绩=====================|\n"
#define HEADER12 "|------------|--------|------------|----------|----------|--------|\n"
#define HEADER13 "|    学号    |  姓名  |    班级    | 课程数目 | 平均成绩 |  排名  |\n"
#define HEADER14 "|------------|--------|------------|----------|----------|--------|\n"
#define FORMAT7 "|%-12s|%-8s|%-12s|    %2d    |  %-8.2lf|   %2d   |\n"
#define HEADER15 "|=================================================================|\n"
#define DATA7 p->data.num,p->data.name,p->data.classes,p->data.m,h->data.aver,p->data.NO
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
//学生个人信息
struct student             
{
	char num[20];          /*学号*/
	char name[10];         /*姓名*/
	char classes[20];      /*班级*/
	char sex[5];           /*性别*/
	int age;               /*年龄*/
	int m;                 /*选修课程数目*/
	int NO;                /*排名*/
};
//学生选修课成绩信息
struct course             
{
	char num[20];          /*学号*/
	char name[10];         /*姓名*/
	double aver;           /*平均分*/
	char num1[10];         /*第一门课程编号*/   
	int score1;	           /*第一门课程学分*/
	char name1[15];        /*第一门课程名称*/
	double usual1;         /*第一门选修平时成绩*/
	double test1;          /*第一门选修考试成绩*/
	double result1;        /*第一门选修综合成绩*/
	char num2[10];               
	int score2;	         
	char name2[15]; 
    double usual2;   
	double test2;
	double result2;
    char num3[10];               
	int score3;	         
	char name3[15]; 
    double usual3;   
	double test3;
	double result3;
};
typedef struct node   
{
	struct student data;
	struct node *next;
}Node;
typedef struct Course
{
	struct course data;
	struct Course *next;
}Courselink;
/*新录入基本信息个数*/
int count1=0;
//显示学生及选修课信息头部
void printheader1()
{
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
	printf(HEADER4);
}
//显示不及格学生头部
void printheader2()
{
	printf(HEADER6);
	printf(HEADER7);
	printf(HEADER8);
	printf(HEADER9);
}
//显示平均成绩头部
void printheader3()
{
	printf(HEADER11);
	printf(HEADER12);
	printf(HEADER13);
	printf(HEADER14);
}
//用于操作修改和删除信息时同名同姓的学生信息的输出
void printdata(Node *p,Courselink *h)
{
	
	if(p->data.m==1)
		printf(FORMAT1,DATA1);
    else if(p->data.m==2)
	{
		printf(FORMAT1,DATA1);
		printf(FORMAT2,DATA2);
	}
	else if(p->data.m==3)
	{
		printf(FORMAT1,DATA1);
		printf(FORMAT2,DATA2);
		printf(FORMAT3,DATA3);
	}
}
//菜单
void menu()
{
	printf("\n\n");
	printf("\t\t|———————————————————|\n");
	printf("\t\t|         学生成绩信息管理系统         |\n");
	printf("\t\t|———————————————————|\n");
	printf("\t\t|     1.录入学生及其选修课程信息       |\n");
	printf("\t\t|     2.修改学生或者选修课程信息       |\n");
	printf("\t\t|     3.插入学生及其选修课程信息       |\n");
	printf("\t\t|     4.查询学生及其选修课程信息       |\n");
	printf("\t\t|     5.删除学生及其选修课程信息       |\n");
	printf("\t\t|     6.显示学生及其选修课程信息       |\n");
	printf("\t\t|     7.计算学生各门功课平均成绩并排序 |\n");
	printf("\t\t|     8.列出不及格学生的名单           |\n");
	printf("\t\t|     9.保存已更改的所有信息           |\n");
	printf("\t\t|     10.附录：选修课程编号对应表      |\n");
	printf("\t\t|     0.退出程序                       |\n");
	printf("\t\t|______________________________________|\n");
}
//附录
void tips()
{
	printf("\n\n");
	printf("\t\t|————————————|\n");
	printf("\t\t|   编号|课程名称        |\n");
	printf("\t\t|————————————|\n");
	printf("\t\t|    001|大学语文        |\n");
	printf("\t\t|    002|数学建模        |\n");
	printf("\t\t|    003|市场营销        |\n");
	printf("\t\t|    004|自然地理学      |\n");
	printf("\t\t|    005|中国陶瓷史      |\n");
	printf("\t\t|————————————|\n");
}
//录入学生及其选修课程信息
void info(Node *head,Courselink *head2)
{
	Node *p,*r,*s;
    Courselink *k,*h;
	char num[20],ch;
	r=head;
	k=head2;
	while(r->next!=NULL && k->next!=NULL)
	{
		r=r->next;
        k=k->next;
	}
    while(1)
	{	
lab1:printf("\n请输入学生学号(输入0则返回):");    /*学生学号唯一，对录入相同学号的容错性处理*/
	 scanf("%s",num);
	 if(strcmp(num,"0")==0)
		 return;
	 s=head->next;
	 while(s)
	 {
		 if(strcmp(s->data.num,num)==0)
		 {
			 printf("【学号为%s的学生已经存在!】\n",num);
			 do
			 {
				 printf("请问需要重新录入吗?<y/n>:");
				 getchar();
				 scanf("%c",&ch);
				 if(ch=='y' || ch=='Y')
					 goto lab1;
				 else if(ch=='n' || ch=='N')
					 return;
				 else
					 printf("【您的输入有误!请重新输入!】\n");
			 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
		 }	
		 s=s->next;
	 }
	 p=(Node*)malloc(sizeof(Node));
	 h=(Courselink*)malloc(sizeof(Courselink));
	 strcpy(p->data.num,num);
	 strcpy(h->data.num,p->data.num);
	 printf("请输入学生的姓名:");
	 scanf("%s",p->data.name);
	 strcpy(h->data.name,p->data.name);
	 printf("请输入学生的班级:");
	 scanf("%s",p->data.classes);
	 do
	 {
		 printf("请输入学生的性别(男或女):");
		 scanf("%s",p->data.sex);
		 if((strcmp(p->data.sex,"男")!=0) && (strcmp(p->data.sex,"女")!=0))
			 printf("【您输入的性别格式有误!请重新输入!】\n");
	 }while((strcmp(p->data.sex,"男")!=0) && (strcmp(p->data.sex,"女")!=0));
	 do
	 {
		 printf("请输入学生的年龄:");
		 scanf("%d",&p->data.age);
		 if(p->data.age<=0 || p->data.age>=120)
			 printf("【您输入的年龄不符合实际!请重新输入!】\n");
	 }while(p->data.age<=0 || p->data.age>=120);
	 p->next=NULL;
	 r->next=p;    
	 r=p;
	 do
	 {	
		 printf("该学生选择多少门选修课(0<m<=3):");
		 scanf("%d",&p->data.m);
		 if(p->data.m<=0 || p->data.m>3)
			 printf("【您输入的数据有误!请重新输入!】\n");
	 }while(p->data.m<=0 || p->data.m>3);
	 switch(p->data.m)
	 {
	 case 1:
		 do
		 {
			 printf("请输入这门选修课的编号:");
			 scanf("%s",h->data.num1);
			 if(strcmp(h->data.num1,"001")==0 || strcmp(h->data.num1,"002")==0 || strcmp(h->data.num1,"003")==0 || strcmp(h->data.num1,"004")==0 || strcmp(h->data.num1,"005")==0)
				 break;
			 else
				 printf("【你的输入的编号不存在!请重新输入!】\n");
		 }while(h->data.num1!="001" || h->data.num1!="002" || h->data.num1!="003" || h->data.num1!="004" || h->data.num1!="005");
		 do
		 {
			 printf("请输入这门选修课的名称:");
			 scanf("%s",h->data.name1);
			 if(strcmp(h->data.num1,"001")==0)
			 {
				 if(strcmp(h->data.name1,"大学语文")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"002")==0)
			 {
				 if(strcmp(h->data.name1,"数学建模")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"003")==0)
			 {
				 if(strcmp(h->data.name1,"市场营销")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"004")==0)
			 {
				 if(strcmp(h->data.name1,"自然地理学")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"005")==0)
			 {
				 if(strcmp(h->data.name1,"中国陶瓷史")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
		 }while(strcmp(h->data.name1,"大学语文")!=0 || strcmp(h->data.name1,"数学建模")!=0 || strcmp(h->data.name1,"市场营销")!=0 || strcmp(h->data.name1,"自然地理学")!=0 || strcmp(h->data.name1,"中国陶瓷史")!=0);
		 do
		 {
			 printf("请输入这门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score1);
			 if(h->data.score1<=0 || h->data.score1>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score1<=0 || h->data.score1>4);
		 do
		 {
			 printf("请输入这门选修课的考试成绩:");
			 scanf("%lf",&h->data.test1);
			 if(h->data.test1<0 || h->data.test1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test1<0 || h->data.test1>100);
		 do
		 {
			 printf("请输入这门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual1);
			 if(h->data.usual1<0 || h->data.usual1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual1<0 || h->data.usual1>100);
		 h->data.result1=0.7*h->data.test1+0.3*h->data.usual1;
		 printf("该学生这门课的综合成绩为%0.2lf\n",h->data.result1);
		 break;
	 case 2:
		 do
		 {
			 printf("请输入第一门选修课的编号:");
			 scanf("%s",h->data.num1);
			 if(strcmp(h->data.num1,"001")==0 || strcmp(h->data.num1,"002")==0 || strcmp(h->data.num1,"003")==0 || strcmp(h->data.num1,"004")==0 || strcmp(h->data.num1,"005")==0)
				 break;
			 else
				 printf("【你的输入的编号不存在!请重新输入!】\n");
		 }while(h->data.num1!="001" || h->data.num1!="002" || h->data.num1!="003" || h->data.num1!="004" || h->data.num1!="005");
		 do
		 {
			 printf("请输入第一门选修课的名称:");
			 scanf("%s",h->data.name1);
			 if(strcmp(h->data.num1,"001")==0)
			 {
				 if(strcmp(h->data.name1,"大学语文")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"002")==0)
			 {
				 if(strcmp(h->data.name1,"数学建模")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"003")==0)
			 {
				 if(strcmp(h->data.name1,"市场营销")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"004")==0)
			 {
				 if(strcmp(h->data.name1,"自然地理学")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"005")==0)
			 {
				 if(strcmp(h->data.name1,"中国陶瓷史")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
		 }while(strcmp(h->data.name1,"大学语文")!=0 || strcmp(h->data.name1,"数学建模")!=0 || strcmp(h->data.name1,"市场营销")!=0 || strcmp(h->data.name1,"自然地理学")!=0 || strcmp(h->data.name1,"中国陶瓷史")!=0);
		 do
		 {	
			 printf("请输入第一门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score1);
			 if(h->data.score1<=0 || h->data.score1>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score1<=0 || h->data.score1>4);
		 do
		 {
			 printf("请输入第一门选修课的考试成绩:");
			 scanf("%lf",&h->data.test1);
			 if(h->data.test1<0 || h->data.test1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test1<0 || h->data.test1>100);
		 do
		 {
			 printf("请输入第一门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual1);
			 if(h->data.usual1<0 || h->data.usual1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual1<0 || h->data.usual1>100);
		 h->data.result1=0.7*h->data.test1+0.3*h->data.usual1;
		 printf("该学生第一门课的综合成绩为%0.2lf\n",h->data.result1);
		 do
		 {
			 do
			 {
				 printf("请输入第二门选修课的编号:");
				 scanf("%s",h->data.num2);
				 if(strcmp(h->data.num2,"001")==0 || strcmp(h->data.num2,"002")==0 || strcmp(h->data.num2,"003")==0 || strcmp(h->data.num2,"004")==0 || strcmp(h->data.num2,"005")==0)
					 break;
				 else
					 printf("【你的输入的编号不存在!请重新输入!】\n");
			 }while(h->data.num2!="001" || h->data.num2!="002" || h->data.num2!="003" || h->data.num2!="004" || h->data.num2!="005");
			 if(strcmp(h->data.num1,h->data.num2)==0)
				 printf("【编号有重复,请重新输入!】\n");
		 }while(strcmp(h->data.num1,h->data.num2)==0);
		 do
		 {
			 do
			 {
				 printf("请输入第二门选修课的名称:");
				 scanf("%s",h->data.name2);
				 if(strcmp(h->data.num2,"001")==0)
				 {
					 if(strcmp(h->data.name2,"大学语文")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"002")==0)
				 {
					 if(strcmp(h->data.name2,"数学建模")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"003")==0)
				 {
					 if(strcmp(h->data.name2,"市场营销")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"004")==0)
				 {
					 if(strcmp(h->data.name2,"自然地理学")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"005")==0)
				 {
					 if(strcmp(h->data.name2,"中国陶瓷史")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
		 }while(strcmp(h->data.name2,"大学语文")!=0 || strcmp(h->data.name2,"数学建模")!=0 || strcmp(h->data.name2,"市场营销")!=0 || strcmp(h->data.name2,"自然地理学")!=0 || strcmp(h->data.name2,"中国陶瓷史")!=0);
		 if(strcmp(h->data.name1,h->data.name2)==0)
			 printf("【名称有重复,请重新输入!】\n");
		 }while(strcmp(h->data.name1,h->data.name2)==0);
		 do
		 {	
			 printf("请输入第二门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score2);
			 if(h->data.score2<=0 || h->data.score2>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
			 
		 }while(h->data.score2<=0 || h->data.score2>4);
		 do
		 {
			 printf("请输入第二门选修课的考试成绩:");
			 scanf("%lf",&h->data.test2);
			 if(h->data.test2<0 || h->data.test2>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test2<0 || h->data.test2>100);
		 do
		 {
			 printf("请输入第二门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual2);
			 if(h->data.usual2<0 || h->data.usual2>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual2<0 || h->data.usual2>100);
		 h->data.result2=0.7*h->data.test2+0.3*h->data.usual2;
		 printf("该学生第二门课的综合成绩为%0.2lf\n",h->data.result2);
		 break;
	 case 3:
		 do
		 {
			 printf("请输入第一门选修课的编号:");
			 scanf("%s",h->data.num1);
			 if(strcmp(h->data.num1,"001")==0 || strcmp(h->data.num1,"002")==0 || strcmp(h->data.num1,"003")==0 || strcmp(h->data.num1,"004")==0 || strcmp(h->data.num1,"005")==0)
				 break;
			 else
				 printf("【你的输入的编号不存在!请重新输入!】\n");
		 }while(h->data.num1!="001" || h->data.num1!="002" || h->data.num1!="003" || h->data.num1!="004" || h->data.num1!="005");
		 do
		 {
			 printf("请输入第一门选修课的名称:");
			 scanf("%s",h->data.name1);
			 if(strcmp(h->data.num1,"001")==0)
			 {
				 if(strcmp(h->data.name1,"大学语文")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"002")==0)
			 {
				 if(strcmp(h->data.name1,"数学建模")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"003")==0)
			 {
				 if(strcmp(h->data.name1,"市场营销")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"004")==0)
			 {
				 if(strcmp(h->data.name1,"自然地理学")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
			 else if(strcmp(h->data.num1,"005")==0)
			 {
				 if(strcmp(h->data.name1,"中国陶瓷史")==0)
					 break;
				 else
				 {
					 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
					 do
					 {
						 printf("需要查看《选修课程编号对应表》吗<y/n>?");
						 getchar();
						 scanf("%c",&ch);
						 if(ch=='y' || ch =='Y')
						 {
							 tips();
							 printf("\n");
							 break;
						 }
						 else if(ch=='n' || ch=='N')
							 break;
						 else
							 printf("【你的输入有误请重新输入!】\n");
					 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
				 }
			 }
		 }while(strcmp(h->data.name1,"大学语文")!=0 || strcmp(h->data.name1,"数学建模")!=0 || strcmp(h->data.name1,"市场营销")!=0 || strcmp(h->data.name1,"自然地理学")!=0 || strcmp(h->data.name1,"中国陶瓷史")!=0);
		 do
		 {	
			 printf("请输入第一门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score1);
			 if(h->data.score1<=0 || h->data.score1>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score1<=0 || h->data.score1>4);
		 do
		 {
			 printf("请输入第一门选修课的考试成绩:");
			 scanf("%lf",&h->data.test1);
			 if(h->data.test1<0 || h->data.test1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test1<0 || h->data.test1>100);
		 do
		 {
			 printf("请输入第一门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual1);
			 if(h->data.usual1<0 || h->data.usual1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual1<0 || h->data.usual1>100);
		 h->data.result1=0.7*h->data.test1+0.3*h->data.usual1;
		 printf("该学生第一门课的综合成绩为%0.2lf\n",h->data.result1);
		 do
		 {
			 do
			 {
				 printf("请输入第二门选修课的编号:");
				 scanf("%s",h->data.num2);
				 if(strcmp(h->data.num2,"001")==0 || strcmp(h->data.num2,"002")==0 || strcmp(h->data.num2,"003")==0 || strcmp(h->data.num2,"004")==0 || strcmp(h->data.num2,"005")==0)
					 break;
				 else
					 printf("【你的输入的编号不存在!请重新输入!】\n");
			 }while(h->data.num2!="001" || h->data.num2!="002" || h->data.num2!="003" || h->data.num2!="004" || h->data.num2!="005");
			 if(strcmp(h->data.num1,h->data.num2)==0)
				 printf("【编号有重复,请重新输入!】\n");
		 }while(strcmp(h->data.num1,h->data.num2)==0);
		 do
		 {
			 do
			 {
				 printf("请输入第二门选修课的名称:");
				 scanf("%s",h->data.name2);
				 if(strcmp(h->data.num2,"001")==0)
				 {
					 if(strcmp(h->data.name2,"大学语文")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"002")==0)
				 {
					 if(strcmp(h->data.name2,"数学建模")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"003")==0)
				 {
					 if(strcmp(h->data.name2,"市场营销")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"004")==0)
				 {
					 if(strcmp(h->data.name2,"自然地理学")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"005")==0)
				 {
					 if(strcmp(h->data.name2,"中国陶瓷史")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
		 }while(strcmp(h->data.name2,"大学语文")!=0 || strcmp(h->data.name2,"数学建模")!=0 || strcmp(h->data.name2,"市场营销")!=0 || strcmp(h->data.name2,"自然地理学")!=0 || strcmp(h->data.name2,"中国陶瓷史")!=0);
		 if(strcmp(h->data.name1,h->data.name2)==0)
			 printf("【名称有重复,请重新输入!】\n");
		 }while(strcmp(h->data.name1,h->data.name2)==0);
		 do
		 {	
			 printf("请输入第二门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score2);
			 if(h->data.score2<=0 || h->data.score2>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score2<=0 || h->data.score2>4);
		 do
		 {
			 printf("请输入第二门选修课的考试成绩:");
			 scanf("%lf",&h->data.test2);
			 if(h->data.test2<0 || h->data.test2>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test2<0 || h->data.test2>100);
		 do
		 {
			 printf("请输入第二门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual2);
			 if(h->data.usual2<0 || h->data.usual2>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual2<0 || h->data.usual2>100);
		 h->data.result2=0.7*h->data.test2+0.3*h->data.usual2;
		 printf("该学生第二门课的综合成绩为%0.2lf\n",h->data.result2);
		 do
		 {
			 do
			 {
				 printf("请输入第三门选修课的编号:");
				 scanf("%s",h->data.num3);
				 if(strcmp(h->data.num3,"001")==0 || strcmp(h->data.num3,"002")==0 || strcmp(h->data.num3,"003")==0 || strcmp(h->data.num3,"004")==0 || strcmp(h->data.num3,"005")==0)
					 break;
				 else
					 printf("【你的输入的编号不存在!请重新输入!】\n");
			 }while(h->data.num3!="001" || h->data.num3!="002" || h->data.num3!="003" || h->data.num3!="004" || h->data.num3!="005");
			 if(strcmp(h->data.num3,h->data.num1)==0 || strcmp(h->data.num3,h->data.num2)==0)
				 printf("【编号有重复,请重新输入!】\n");
		 }while(strcmp(h->data.num3,h->data.num1)==0 || strcmp(h->data.num3,h->data.num2)==0);
		 do
		 {
			 do
			 {
				 printf("请输入第三门选修课的名称:");
				 scanf("%s",h->data.name3);
				 if(strcmp(h->data.num3,"001")==0)
				 {
					 if(strcmp(h->data.name3,"大学语文")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num3,"002")==0)
				 {
					 if(strcmp(h->data.name3,"数学建模")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num3,"003")==0)
				 {
					 if(strcmp(h->data.name3,"市场营销")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num3,"004")==0)
				 {
					 if(strcmp(h->data.name3,"自然地理学")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num3,"005")==0)
				 {
					 if(strcmp(h->data.name3,"中国陶瓷史")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
		 }while(strcmp(h->data.name3,"大学语文")!=0 || strcmp(h->data.name3,"数学建模")!=0 || strcmp(h->data.name3,"市场营销")!=0 || strcmp(h->data.name3,"自然地理学")!=0 || strcmp(h->data.name3,"中国陶瓷史")!=0);
		 if(strcmp(h->data.name3,h->data.name1)==0 && strcmp(h->data.name3,h->data.name2)==0)
			 printf("【名称有重复,请重新输入!】\n");
		 }while(strcmp(h->data.name3,h->data.name1)==0 && strcmp(h->data.name3,h->data.name2)==0);
		 do
		 {	
			 printf("请输入第三门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score3);
			 if(h->data.score3<=0 || h->data.score3>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score3<=0 || h->data.score3>4);
		 do
		 {
			 printf("请输入第三门选修课的考试成绩:");
			 scanf("%lf",&h->data.test3);
			 if(h->data.test3<0 || h->data.test3>=100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test3<0 || h->data.test3>=100);
		 do
		 {
			 printf("请输入第三门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual3);
			 if(h->data.usual3<0 || h->data.usual3>=100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual3<0 || h->data.usual3>=100);
		 h->data.result3=0.7*h->data.test3+0.3*h->data.usual3;
		 printf("该学生第三门课的综合成绩为%0.2lf\n",h->data.result3);
		 break;
        }
		h->next=NULL;
		k->next=h;    
		k=h;
	 }
}
//修改学生或者选修课程信息
void modify(Node *head,Courselink *head2)
{
	Node *p,*s[10];
	Courselink *h,*k[10];
	int j,i=0;
	char sel,ch,tnum[20],tnum1[20],tnum2[10],tname[10],tname1[10];
	p=head->next;
	h=head2->next;
	if(!p && !h)
	{
		printf("无记录!\n");
		return;
	}
lab2:printf("\n请选择修改内容:\n1:学生基本信息;\t\t2.选修基本信息;\t\t*其余任意键回车返回菜单.\n");
	 getchar();
	 scanf("%c",&sel);
	 /*根据学生基本信息修改*/
	 if(sel=='1')
	 {
lab3:printf("\n请选择修改的信息:\n1.学号;\t2.姓名;\t3.班级;\t4.性别;\t5.年龄;\t*其余任意键回车返回上一级.\n");
	 getchar();
	 scanf("%c",&sel);
	 /*学号*/
	 if(sel=='1')
	 {
		 printf("您是否确定修改学生信息?(y/n):");
		 getchar();
		 scanf("%c",&ch);
		 if(ch=='y' || ch=='Y')
		 {
			 printf("请输入学生原来的学号:");
			 scanf("%s",tnum);
			 while((p!=NULL)&&(h!=NULL))
			 {
				 if(strcmp(tnum,p->data.num)==0 && strcmp(tnum,h->data.num)==0)    /*查找需要修改的学号*/
				 {
					 printheader1();
					 printdata(p,h);
					 printf(HEADER5);
					 do
					 {
						 printf("请输入新的学生学号:");
						 scanf("%s",p->data.num);
						 if(strcmp(p->data.num,"0")==0)
							 printf("【您输入的学号有误!请重新输入!】\n");
					 }while(strcmp(p->data.num,"0")==0);
					 strcpy(h->data.num,p->data.num);
					 printf("\n新学号已成功保存!\n");
					 break;
				 }
				 else
				 {
					 p=p->next;
					 h=h->next;
					 if(p==NULL && h==NULL)
						 printf("【您输入的学生学号不存在!】\n");
				 }	
			 }
		 }
		 else if(ch=='n' || ch=='N')
		 { 
			 printf("【返回上一级!】\n");
			 goto lab3;
		 }
		 else
		 {
			 printf("【您的输入有误!返回上一级!】\n");
			 goto lab3;
		 }
	 }
	 /*姓名*/
	 else if(sel=='2')
	 {
		 printf("您是否确定修改学生信息?(y/n):");
		 getchar();
		 scanf("%c",&ch);
		 if(ch=='y' || ch=='Y')
		 {
			 printf("请输入学生原来的姓名:");
			 scanf("%s",tname);
			 while(p!=NULL && h!=NULL)
			 {
				 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)      /*把同名同姓的学生及选修信息放进数组里*/
				 {
					 s[i]=p;
					 k[i]=h;
					 i++;
				 }
				 p=p->next;
				 h=h->next;
			 }
			 if(i==0)
				 printf("【您输入的姓名有误!找不到相关信息!】\n");
			 else
			 {
				 printf("\n同名同姓的学生一共有%d个!\n",i);                /*对同名同姓者的数据统计，再对用户输入的学号进行信息修改*/
				 printheader1();
				 for(j=0;j<i;j++)
					 printdata(s[j],k[j]);
				 printf(HEADER5);
				 printf("请输入您要修改的学生学号:");
				 scanf("%s",tnum1);
				 for(j=0;j<i;j++)
				 {
					 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
					 {
						 printf("请输入新的学生姓名:");
						 scanf("%s",s[j]->data.name);
						 strcpy(k[j]->data.name,s[j]->data.name);
						 printf("\n新姓名已成功保存!\n");
						 break;
					 }
					 else
					 {
						 s[j]=s[j]->next;
						 k[j]=k[j]->next;
						 if(++j==i)
						 {
							 printf("【您输入的学生学号不存在!】\n");
							 break;
						 }
					 }
				 }
			 }
		 }
		 else if(ch=='n' || ch=='N')
		 {
			 printf("【返回上一级!】\n");
			 goto lab3;
		 }
		 else
		 {
			 printf("【您的输入有误!返回上一级!】\n");
			 goto lab3;
		 }
	 }
	 /*班级*/
	 else if(sel=='3')
	 {
		 printf("\n请选择修改的方式:\n1:根据学生学号修改信息;\t\t2:根据学生姓名修改信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号修改*/
		 if(sel=='1')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);
				 while((p!=NULL)&&(h!=NULL))
				 {
					 if(strcmp(tnum,p->data.num)==0 && strcmp(tnum,h->data.num)==0)
					 {
						 printheader1();
						 printdata(p,h);
						 printf(HEADER5);
						 printf("请输入新的学生班级:");
						 scanf("%s",p->data.classes);
						 printf("\n新班级已成功保存!\n");
						 break;
					 }
					 else
					 {
						 p=p->next;
						 h=h->next;
						 if(p==NULL && h==NULL)
							 printf("【您输入的学生学号不存在!】\n");
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab3;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab3;
			 }
		 }
		 /*根据姓名修改*/
		 else if(sel=='2')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)      /*把同名同姓的学生及选修信息放进数组里*/
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
					 printf("【您输入的姓名有误!找不到相关信息!】\n");
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);                /*对同名同姓者的数据统计，再对用户输入的学号进行信息修改*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要修改的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 printf("请输入新的学生班级:");
							 scanf("%s",s[j]->data.classes);
							 printf("\n新班级已成功保存!\n");
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab3;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab3;
			 }
		 }
		 else
			 goto lab3;
	 }
	 /*性别*/
	 else if(sel=='4')
	 {
		 printf("\n请选择修改的方式:\n1:根据学生学号修改信息;\t\t2:根据学生姓名修改信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号修改*/
		 if(sel=='1')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);
				 while((p!=NULL)&&(h!=NULL))
				 {
					 if(strcmp(tnum,p->data.num)==0 && strcmp(tnum,h->data.num)==0)
					 {
						 printheader1();
						 printdata(p,h);
						 printf(HEADER5);
						 do
						 {
							 printf("请输入新的学生性别(男或女):");
							 scanf("%s",p->data.sex);
							 if((strcmp(p->data.sex,"男")!=0) && (strcmp(p->data.sex,"女")!=0))
								 printf("【您输入的性别格式有误!请重新输入!】\n");
						 }while((strcmp(p->data.sex,"男")!=0) && (strcmp(p->data.sex,"女")!=0));
						 printf("\n新性别已成功保存!\n");
						 break;
					 }
					 else
					 {
						 p=p->next;
						 h=h->next;
						 if(p==NULL && h==NULL)
							 printf("【您输入的学生学号不存在!】\n");
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab3;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab3;
			 }
		 }
		 /*根据姓名修改*/
		 else if(sel=='2')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)      /*把同名同姓的学生及选修信息放进数组里*/
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
					 printf("【您输入的姓名有误!找不到相关信息!】\n");
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);                /*对同名同姓者的数据统计，再对用户输入的学号进行信息修改*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要修改的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 do
							 {
								 printf("请输入新的学生性别:");
								 scanf("%s",s[j]->data.sex);
								 if((strcmp(s[j]->data.sex,"男")!=0) && (strcmp(s[j]->data.sex,"女")!=0))
									 printf("【您输入的性别格式有误!请重新输入!】\n");
							 }while((strcmp(s[j]->data.sex,"男")!=0) && (strcmp(s[j]->data.sex,"女")!=0));
							 printf("\n新性别已成功保存!\n");
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab3;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab3;
			 }
		 }
		 else
			 goto lab3;
	 }
	 /*年龄*/
	 else if(sel=='5')
	 {
		 printf("\n请选择修改的方式:\n1:根据学生学号修改信息;\t\t2:根据学生姓名修改信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号修改*/
		 if(sel=='1')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);
				 while((p!=NULL)&&(h!=NULL))
				 {
					 if(strcmp(tnum,p->data.num)==0 && strcmp(tnum,h->data.num)==0)
					 {
						 printheader1();
						 printdata(p,h);
						 printf(HEADER5);
						 do
						 {
							 printf("请输入新的学生年龄:");
							 scanf("%d",&p->data.age);
							 if(p->data.age<=0 || p->data.age>120)
								 printf("【您输入的年龄不符合实际!请重新输入!】\n");
						 }while(p->data.age<=0 || p->data.age>120);
						 printf("\n新年龄已成功保存!\n");
						 break;
					 }
					 else
					 {
						 p=p->next;
						 h=h->next;
						 if(p==NULL && h==NULL)
							 printf("【您输入的学生学号不存在!】\n");
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab3;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab3;
			 }
		 }
		 /*根据姓名修改*/
		 else if(sel=='2')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)      /*把同名同姓的学生及选修信息放进数组里*/
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
					 printf("【您输入的姓名有误!找不到相关信息!】\n");
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);                /*对同名同姓者的数据统计，再对用户输入的学号进行信息修改*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要修改的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 do
							 {
								 printf("请输入新的学生年龄:");
								 scanf("%d",&s[j]->data.age);
								 if(s[j]->data.age<=0 || s[j]->data.age>120)
									 printf("【您输入的年龄不符合实际!请重新输入!】\n");
							 }while(s[j]->data.age<=0 || s[j]->data.age>120);
							 printf("\n新年龄已成功保存!\n");
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab3;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab3;
			 }
		 }
		 else
			 goto lab3;
	 }
	 else
		 goto lab2;
		 }
		 /*根据选修基本信息修改*/
		 else if(sel=='2')
		 {
lab4:printf("\n请选择修改的信息:\n1.课程编号;\t2.课程名称;\t3.课程学分;\t4.平时成绩;\t5.考试成绩;\t*其余任意键回车返回上一级.\n");
	 getchar();
	 scanf("%c",&sel);
	 /*课程编号*/
	 if(sel=='1')
	 {
		 printf("\n请选择修改的方式:\n1:根据学生学号修改信息;\t\t2:根据学生姓名修改信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号修改*/
		 if(sel=='1')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);                                                            
				 while((p!=NULL)&&(h!=NULL))
				 {
					 if(strcmp(tnum,p->data.num)==0 && strcmp(tnum,h->data.num)==0)
					 {
						 printheader1();
						 printdata(p,h);
						 printf(HEADER5);
						 do
						 {
							 printf("请输入你要修改的课程编号:");
							 scanf("%s",tnum2);
							 if(strcmp(h->data.num1,tnum2)!=0 && strcmp(h->data.num2,tnum2)!=0 && strcmp(h->data.num3,tnum2)!=0)
								 printf("【您输入的课程编号有误!请重新输入!】\n");
						 }while(strcmp(h->data.num1,tnum2)!=0 && strcmp(h->data.num2,tnum2)!=0 && strcmp(h->data.num3,tnum2)!=0);
						 if((strcmp(tnum2,h->data.num1))==0)
						 {
							 do
							 {
								 do
								 {
									 printf("请输入新的选修课编号:");
									 scanf("%s",h->data.num1);
									 if(strcmp(h->data.num1,"001")==0 || strcmp(h->data.num1,"002")==0 || strcmp(h->data.num1,"003")==0 || strcmp(h->data.num1,"004")==0 || strcmp(h->data.num1,"005")==0)
										 break;
									 else
										 printf("【你输入的编号不存在!请重新输入!】\n");
								 }while(h->data.num1!="001" || h->data.num1!="002" || h->data.num1!="003" || h->data.num1!="004" || h->data.num1!="005");
								 if(strcmp(h->data.num1,h->data.num2)==0 || strcmp(h->data.num1,h->data.num3)==0)
									 printf("【编号有重复!请重新输入!】\n");
							 }while(strcmp(h->data.num1,h->data.num2)==0 || strcmp(h->data.num1,h->data.num3)==0);
							 if(strcmp(h->data.num1,"001")==0)
								 strcpy(h->data.name1,"大学语文");
							 else if(strcmp(h->data.num1,"002")==0)
								 strcpy(h->data.name1,"数学建模");
							 else if(strcmp(h->data.num1,"003")==0)
								 strcpy(h->data.name1,"市场营销");
							 else if(strcmp(h->data.num1,"004")==0)
								 strcpy(h->data.name1,"自然地理学");
							 else if(strcmp(h->data.num1,"005")==0)
								 strcpy(h->data.name1,"中国陶瓷史");
							 printf("\n新选修编号已成功保存!\n");
						 }
						 else if((strcmp(tnum2,h->data.num2))==0)
						 {
							 do
							 {
								 do
								 {
									 printf("请输入新的选修课编号:");
									 scanf("%s",h->data.num2);
									 if(strcmp(h->data.num2,"001")==0 || strcmp(h->data.num2,"002")==0 || strcmp(h->data.num2,"003")==0 || strcmp(h->data.num2,"004")==0 || strcmp(h->data.num2,"005")==0)
										 break;
									 else
										 printf("【你输入的编号不存在!请重新输入!】\n");
								 }while(h->data.num2!="001" || h->data.num2!="002" || h->data.num2!="003" || h->data.num2!="004" || h->data.num2!="005");
								 if(strcmp(h->data.num2,h->data.num1)==0 || strcmp(h->data.num2,h->data.num3)==0)
									 printf("【编号有重复!请重新输入!】\n");
							 }while(strcmp(h->data.num2,h->data.num1)==0 || strcmp(h->data.num2,h->data.num3)==0);
							 if(strcmp(h->data.num2,"001")==0)
								 strcpy(h->data.name2,"大学语文");
							 else if(strcmp(h->data.num2,"002")==0)
								 strcpy(h->data.name2,"数学建模");
							 else if(strcmp(h->data.num2,"003")==0)
								 strcpy(h->data.name2,"市场营销");
							 else if(strcmp(h->data.num2,"004")==0)
								 strcpy(h->data.name2,"自然地理学");
							 else if(strcmp(h->data.num2,"005")==0)
								 strcpy(h->data.name2,"中国陶瓷史");
							 printf("\n新选修编号已成功保存!\n");
						 }
						 else if((strcmp(tnum2,h->data.num3))==0)
						 {
							 do
							 {
								 do
								 {
									 printf("请输入新的选修课编号:");
									 scanf("%s",h->data.num3);
									 if(strcmp(h->data.num3,"001")==0 || strcmp(h->data.num3,"002")==0 || strcmp(h->data.num3,"003")==0 || strcmp(h->data.num3,"004")==0 || strcmp(h->data.num3,"005")==0)
										 break;
									 else
										 printf("【你输入的编号不存在!请重新输入!】\n");
								 }while(h->data.num3!="001" || h->data.num3!="002" || h->data.num3!="003" || h->data.num3!="004" || h->data.num3!="005");
								 if(strcmp(h->data.num3,h->data.num1)==0 || strcmp(h->data.num3,h->data.num2)==0)
									 printf("【编号有重复!请重新输入!】\n");
							 }while(strcmp(h->data.num3,h->data.num1)==0 || strcmp(h->data.num3,h->data.num2)==0);
							 if(strcmp(h->data.num3,"001")==0)
								 strcpy(h->data.name3,"大学语文");
							 else if(strcmp(h->data.num3,"002")==0)
								 strcpy(h->data.name3,"数学建模");
							 else if(strcmp(h->data.num3,"003")==0)
								 strcpy(h->data.name3,"市场营销");
							 else if(strcmp(h->data.num3,"004")==0)
								 strcpy(h->data.name3,"自然地理学");
							 else if(strcmp(h->data.num3,"005")==0)
								 strcpy(h->data.name3,"中国陶瓷史");
							 printf("\n新选修编号已成功保存!\n");
						 }
						 break;
					 }
					 else
					 {
						 p=p->next;
						 h=h->next;
						 if(p==NULL && h==NULL)
							 printf("【您输入的学生学号不存在!】\n");
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 /*根据姓名修改*/
		 else if(sel=='2')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)      /*把同名同姓的学生及选修信息放进数组里*/
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
					 printf("【您输入的姓名有误!找不到相关信息!】\n");
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);                /*对同名同姓者的数据统计，再对用户输入的学号进行信息修改*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要修改的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 do
							 {
								 printf("请输入你要修改的课程编号:");
								 scanf("%s",tnum2);
								 if(strcmp(k[j]->data.num1,tnum2)!=0 && strcmp(k[j]->data.num2,tnum2)!=0 && strcmp(k[j]->data.num3,tnum2)!=0)
									 printf("【您输入的课程编号有误!请重新输入!】\n");
							 }while(strcmp(k[j]->data.num1,tnum2)!=0 && strcmp(k[j]->data.num2,tnum2)!=0 && strcmp(k[j]->data.num3,tnum2)!=0);
							 if((strcmp(tnum2,k[j]->data.num1))==0)
							 {
								 do
								 {
									 do
									 {
										 printf("请输入新的选修课编号:");
										 scanf("%s",k[j]->data.num1);
										 if(strcmp(k[j]->data.num1,"001")==0 || strcmp(k[j]->data.num1,"002")==0 || strcmp(k[j]->data.num1,"003")==0 || strcmp(k[j]->data.num1,"004")==0 || strcmp(k[j]->data.num1,"005")==0)
											 break;
										 else
											 printf("【你输入的编号不存在!请重新输入!】\n");
									 }while(k[j]->data.num1!="001" || k[j]->data.num1!="002" || k[j]->data.num1!="003" || k[j]->data.num1!="004" || k[j]->data.num1!="005");
									 if(strcmp(k[j]->data.num1,k[j]->data.num2)==0 || strcmp(k[j]->data.num1,k[j]->data.num3)==0)
										 printf("【编号有重复!请重新输入!】\n");
								 }while(strcmp(k[j]->data.num1,k[j]->data.num2)==0 || strcmp(k[j]->data.num1,k[j]->data.num3)==0);
								 if(strcmp(k[j]->data.num1,"001")==0)
									 strcpy(k[j]->data.name1,"大学语文");
								 else if(strcmp(k[j]->data.num1,"002")==0)
									 strcpy(k[j]->data.name1,"数学建模");
								 else if(strcmp(k[j]->data.num1,"003")==0)
									 strcpy(k[j]->data.name1,"市场营销");
								 else if(strcmp(k[j]->data.num1,"004")==0)
									 strcpy(k[j]->data.name1,"自然地理学");
								 else if(strcmp(k[j]->data.num1,"005")==0)
									 strcpy(k[j]->data.name1,"中国陶瓷史");
								 printf("\n新选修编号已成功保存!\n");
							 }
							 else if((strcmp(tnum2,k[j]->data.num2))==0)
							 {
								 do
								 {
									 do
									 {
										 printf("请输入新的选修课编号:");
										 scanf("%s",k[j]->data.num2);
										 if(strcmp(k[j]->data.num2,"001")==0 || strcmp(k[j]->data.num2,"002")==0 || strcmp(k[j]->data.num2,"003")==0 || strcmp(k[j]->data.num2,"004")==0 || strcmp(k[j]->data.num2,"005")==0)
											 break;
										 else
											 printf("【你输入的编号不存在!请重新输入!】\n");
									 }while(k[j]->data.num2!="001" || k[j]->data.num2!="002" || k[j]->data.num2!="003" || k[j]->data.num2!="004" || k[j]->data.num2!="005");
									 if(strcmp(k[j]->data.num2,k[j]->data.num1)==0 || strcmp(k[j]->data.num2,k[j]->data.num3)==0)
										 printf("【编号有重复!请重新输入!】\n");
								 }while(strcmp(k[j]->data.num2,k[j]->data.num1)==0 || strcmp(k[j]->data.num2,k[j]->data.num3)==0);
								 if(strcmp(k[j]->data.num2,"001")==0)
									 strcpy(k[j]->data.name2,"大学语文");
								 else if(strcmp(k[j]->data.num2,"002")==0)
									 strcpy(k[j]->data.name2,"数学建模");
								 else if(strcmp(k[j]->data.num2,"003")==0)
									 strcpy(k[j]->data.name2,"市场营销");
								 else if(strcmp(k[j]->data.num2,"004")==0)
									 strcpy(k[j]->data.name2,"自然地理学");
								 else if(strcmp(k[j]->data.num2,"005")==0)
									 strcpy(k[j]->data.name2,"中国陶瓷史");
								 printf("\n新选修编号已成功保存!\n");
							 }
							 else if((strcmp(tnum2,k[j]->data.num3))==0)
							 {
								 do
								 {
									 do
									 {
										 printf("请输入新的选修课编号:");
										 scanf("%s",k[j]->data.num3);
										 if(strcmp(k[j]->data.num3,"001")==0 || strcmp(k[j]->data.num3,"002")==0 || strcmp(k[j]->data.num3,"003")==0 || strcmp(k[j]->data.num3,"004")==0 || strcmp(k[j]->data.num3,"005")==0)
											 break;
										 else
											 printf("【你输入的编号不存在!请重新输入!】\n");
									 }while(k[j]->data.num3!="001" || k[j]->data.num3!="002" || k[j]->data.num3!="003" || k[j]->data.num3!="004" || k[j]->data.num3!="005");
									 if(strcmp(k[j]->data.num3,k[j]->data.num2)==0 || strcmp(k[j]->data.num3,k[j]->data.num1)==0)
										 printf("【编号有重复!请重新输入!】\n");
								 }while(strcmp(k[j]->data.num3,k[j]->data.num2)==0 || strcmp(k[j]->data.num3,k[j]->data.num1)==0);
								 if(strcmp(k[j]->data.num3,"001")==0)
									 strcpy(k[j]->data.name3,"大学语文");
								 else if(strcmp(k[j]->data.num3,"002")==0)
									 strcpy(k[j]->data.name3,"数学建模");
								 else if(strcmp(k[j]->data.num3,"003")==0)
									 strcpy(k[j]->data.name3,"市场营销");
								 else if(strcmp(k[j]->data.num3,"004")==0)
									 strcpy(k[j]->data.name3,"自然地理学");
								 else if(strcmp(k[j]->data.num3,"005")==0)
									 strcpy(k[j]->data.name3,"中国陶瓷史");
								 printf("\n新选修编号已成功保存!\n");
							 }
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 else
			 goto lab4;
	 }
	 /*课程名称*/
	 else if(sel=='2')
	 {
		 printf("\n请选择修改的方式:\n1:根据学生学号修改信息;\t\t2:根据学生姓名修改信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号修改*/
		 if(sel=='1')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);
				 while((p!=NULL)&&(h!=NULL))
				 {
					 if(strcmp(tnum,p->data.num)==0 && strcmp(tnum,h->data.num)==0)
					 {
						 printheader1();
						 printdata(p,h);
						 printf(HEADER5);
						 do
						 {
							 printf("请输入课程名称:");
							 scanf("%s",tname1);
							 if(strcmp(h->data.name1,tname1)!=0 && strcmp(h->data.name2,tname1)!=0 && strcmp(h->data.name3,tname1)!=0)
								 printf("【您输入的课程名称有误!请重新输入!】\n");
						 }while(strcmp(h->data.name1,tname1)!=0 && strcmp(h->data.name2,tname1)!=0 && strcmp(h->data.name3,tname1)!=0);
						 if(strcmp(tname1,h->data.name1)==0)
						 {
							 do
							 {
								 do
								 {
									 printf("请输入新的选修课名称:");
									 scanf("%s",h->data.name1);
									 if(strcmp(h->data.name1,"大学语文")==0 || strcmp(h->data.name1,"数学建模")==0 || strcmp(h->data.name1,"市场营销")==0 || strcmp(h->data.name1,"自然地理学")==0 || strcmp(h->data.name1,"中国陶瓷史")==0)
										 break;
									 else
										 printf("【你输入的课程不存在!请重新输入!】\n");
								 }while(strcmp(h->data.name1,"大学语文")!=0 || strcmp(h->data.name1,"数学建模")!=0 || strcmp(h->data.name1,"市场营销")!=0 || strcmp(h->data.name1,"自然地理学")!=0 || strcmp(h->data.name1,"中国陶瓷史")!=0);
								 if(strcmp(h->data.name1,h->data.name2)==0 || strcmp(h->data.name1,h->data.name3)==0)
									 printf("【课程已存在!请重新输入!】\n");
							 }while(strcmp(h->data.name1,h->data.name2)==0 || strcmp(h->data.name1,h->data.name3)==0);
							 if(strcmp(h->data.name1,"大学语文")==0)
								 strcpy(h->data.num1,"001");
							 else if(strcmp(h->data.name1,"数学建模")==0)
								 strcpy(h->data.num1,"002");
							 else if(strcmp(h->data.name1,"市场营销")==0)
								 strcpy(h->data.num1,"003");
							 else if(strcmp(h->data.name1,"自然地理学")==0)
								 strcpy(h->data.num1,"004");
							 else if(strcmp(h->data.name1,"中国陶瓷史")==0)
								 strcpy(h->data.num1,"005");
						 }
						 if(strcmp(tname1,h->data.name2)==0)
						 {
							 do
							 {
								 do
								 {
									 printf("请输入新的选修课名称:");
									 scanf("%s",h->data.name2);
									 if(strcmp(h->data.name2,"大学语文")==0 || strcmp(h->data.name2,"数学建模")==0 || strcmp(h->data.name2,"市场营销")==0 || strcmp(h->data.name2,"自然地理学")==0 || strcmp(h->data.name2,"中国陶瓷史")==0)
										 break;
									 else
										 printf("【你输入的课程不存在!请重新输入!】\n");
								 }while(strcmp(h->data.name2,"大学语文")!=0 || strcmp(h->data.name2,"数学建模")!=0 || strcmp(h->data.name2,"市场营销")!=0 || strcmp(h->data.name2,"自然地理学")!=0 || strcmp(h->data.name2,"中国陶瓷史")!=0);
								 if(strcmp(h->data.name2,h->data.name1)==0 || strcmp(h->data.name2,h->data.name3)==0)
									 printf("【课程已存在!请重新输入!】\n");
							 }while(strcmp(h->data.name2,h->data.name1)==0 || strcmp(h->data.name2,h->data.name3)==0);
							 if(strcmp(h->data.name2,"大学语文")==0)
								 strcpy(h->data.num2,"001");
							 else if(strcmp(h->data.name2,"数学建模")==0)
								 strcpy(h->data.num2,"002");
							 else if(strcmp(h->data.name2,"市场营销")==0)
								 strcpy(h->data.num2,"003");
							 else if(strcmp(h->data.name2,"自然地理学")==0)
								 strcpy(h->data.num2,"004");
							 else if(strcmp(h->data.name2,"中国陶瓷史")==0)
								 strcpy(h->data.num2,"005");
						 }
						 if(strcmp(tname1,h->data.name3)==0)
						 {
							 do
							 {
								 do
								 {
									 printf("请输入新的选修课名称:");
									 scanf("%s",h->data.name3);
									 if(strcmp(h->data.name3,"大学语文")==0 || strcmp(h->data.name3,"数学建模")==0 || strcmp(h->data.name3,"市场营销")==0 || strcmp(h->data.name3,"自然地理学")==0 || strcmp(h->data.name3,"中国陶瓷史")==0)
										 break;
									 else
										 printf("【你输入的课程不存在!请重新输入!】\n");
								 }while(strcmp(h->data.name3,"大学语文")!=0 || strcmp(h->data.name3,"数学建模")!=0 || strcmp(h->data.name3,"市场营销")!=0 || strcmp(h->data.name3,"自然地理学")!=0 || strcmp(h->data.name3,"中国陶瓷史")!=0);
								 if(strcmp(h->data.name3,h->data.name1)==0 || strcmp(h->data.name3,h->data.name2)==0)
									 printf("【课程已存在!请重新输入!】\n");
							 }while(strcmp(h->data.name3,h->data.name1)==0 || strcmp(h->data.name3,h->data.name1)==0);
							 if(strcmp(h->data.name3,"大学语文")==0)
								 strcpy(h->data.num3,"001");
							 else if(strcmp(h->data.name3,"数学建模")==0)
								 strcpy(h->data.num3,"002");
							 else if(strcmp(h->data.name3,"市场营销")==0)
								 strcpy(h->data.num3,"003");
							 else if(strcmp(h->data.name3,"自然地理学")==0)
								 strcpy(h->data.num3,"004");
							 else if(strcmp(h->data.name3,"中国陶瓷史")==0)
								 strcpy(h->data.num3,"005");
						 }
						 printf("\n新选修课名称已成功保存!\n");
						 break;
					 }
					 else
					 {
						 p=p->next;
						 h=h->next;
						 if(p==NULL && h==NULL)
							 printf("【您输入的学生学号不存在!】\n");
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 /*根据姓名修改*/
		 else if(sel=='2')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)      /*把同名同姓的学生及选修信息放进数组里*/
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
					 printf("【您输入的姓名有误!找不到相关信息!】\n");
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);                /*对同名同姓者的数据统计，再对用户输入的学号进行信息修改*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要修改的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 do
							 {
								 printf("请输入课程名称:");
								 scanf("%s",tname1);
								 if(strcmp(k[j]->data.name1,tname1)!=0 && strcmp(k[j]->data.name2,tname1)!=0 && strcmp(k[j]->data.name3,tname1)!=0)
									 printf("【您输入的课程名称有误!请重新输入!】\n");
							 }while(strcmp(k[j]->data.name1,tname1)!=0 && strcmp(k[j]->data.name2,tname1)!=0 && strcmp(k[j]->data.name3,tname1)!=0);
							 if(strcmp(tname1,k[j]->data.name1)==0)
							 {
								 do
								 {
									 do
									 {
										 printf("请输入新的选修课名称:");
										 scanf("%s",k[j]->data.name1);
										 if(strcmp(k[j]->data.name1,"大学语文")==0 || strcmp(k[j]->data.name1,"数学建模")==0 || strcmp(k[j]->data.name1,"市场营销")==0 || strcmp(k[j]->data.name1,"自然地理学")==0 || strcmp(k[j]->data.name1,"中国陶瓷史")==0)
											 break;
										 else
											 printf("【你输入的课程不存在!请重新输入!】\n");
									 }while(strcmp(k[j]->data.name1,"大学语文")!=0 || strcmp(k[j]->data.name1,"数学建模")!=0 || strcmp(k[j]->data.name1,"市场营销")!=0 || strcmp(k[j]->data.name1,"自然地理学")!=0 || strcmp(k[j]->data.name1,"中国陶瓷史")!=0);
									 if(strcmp(k[j]->data.name1,k[j]->data.name2)==0 || strcmp(k[j]->data.name1,k[j]->data.name3)==0)
										 printf("【课程已存在!请重新输入!】\n");
								 }while(strcmp(k[j]->data.name1,k[j]->data.name2)==0 || strcmp(k[j]->data.name1,k[j]->data.name3)==0);
								 if(strcmp(k[j]->data.name1,"大学语文")==0)
									 strcpy(k[j]->data.num1,"001");
								 else if(strcmp(k[j]->data.name1,"数学建模")==0)
									 strcpy(k[j]->data.num1,"002");
								 else if(strcmp(k[j]->data.name1,"市场营销")==0)
									 strcpy(k[j]->data.num1,"003");
								 else if(strcmp(k[j]->data.name1,"自然地理学")==0)
									 strcpy(k[j]->data.num1,"004");
								 else if(strcmp(k[j]->data.name1,"中国陶瓷史")==0)
									 strcpy(k[j]->data.num1,"005");
							 }
							 if(strcmp(tname1,k[j]->data.name2)==0)
							 {
								 do
								 {
									 do
									 {
										 printf("请输入新的选修课名称:");
										 scanf("%s",k[j]->data.name2);
										 if(strcmp(k[j]->data.name2,"大学语文")==0 || strcmp(k[j]->data.name2,"数学建模")==0 || strcmp(k[j]->data.name2,"市场营销")==0 || strcmp(k[j]->data.name2,"自然地理学")==0 || strcmp(k[j]->data.name2,"中国陶瓷史")==0)
											 break;
										 else
											 printf("【你输入的课程不存在!请重新输入!】\n");
									 }while(strcmp(k[j]->data.name2,"大学语文")!=0 || strcmp(k[j]->data.name2,"数学建模")!=0 || strcmp(k[j]->data.name2,"市场营销")!=0 || strcmp(k[j]->data.name2,"自然地理学")!=0 || strcmp(k[j]->data.name2,"中国陶瓷史")!=0);
									 if(strcmp(k[j]->data.name2,k[j]->data.name1)==0 || strcmp(k[j]->data.name2,k[j]->data.name3)==0)
										 printf("【课程已存在!请重新输入!】\n");
								 }while(strcmp(k[j]->data.name2,k[j]->data.name1)==0 || strcmp(k[j]->data.name2,k[j]->data.name3)==0);
								 if(strcmp(k[j]->data.name2,"大学语文")==0)
									 strcpy(k[j]->data.num2,"001");
								 else if(strcmp(k[j]->data.name2,"数学建模")==0)
									 strcpy(k[j]->data.num2,"002");
								 else if(strcmp(k[j]->data.name2,"市场营销")==0)
									 strcpy(k[j]->data.num2,"003");
								 else if(strcmp(k[j]->data.name2,"自然地理学")==0)
									 strcpy(k[j]->data.num2,"004");
								 else if(strcmp(k[j]->data.name2,"中国陶瓷史")==0)
									 strcpy(k[j]->data.num2,"005");
							 }
							 if(strcmp(tname1,k[j]->data.name3)==0)
							 {
								 do
								 {
									 do
									 {
										 printf("请输入新的选修课名称:");
										 scanf("%s",k[j]->data.name3);
										 if(strcmp(k[j]->data.name3,"大学语文")==0 || strcmp(k[j]->data.name3,"数学建模")==0 || strcmp(k[j]->data.name3,"市场营销")==0 || strcmp(k[j]->data.name3,"自然地理学")==0 || strcmp(k[j]->data.name3,"中国陶瓷史")==0)
											 break;
										 else
											 printf("【你输入的课程不存在!请重新输入!】\n");
									 }while(strcmp(k[j]->data.name3,"大学语文")!=0 || strcmp(k[j]->data.name3,"数学建模")!=0 || strcmp(k[j]->data.name3,"市场营销")!=0 || strcmp(k[j]->data.name3,"自然地理学")!=0 || strcmp(k[j]->data.name3,"中国陶瓷史")!=0);
									 if(strcmp(k[j]->data.name3,k[j]->data.name1)==0 || strcmp(k[j]->data.name3,k[j]->data.name2)==0)
										 printf("【课程已存在!请重新输入!】\n");
								 }while(strcmp(k[j]->data.name3,k[j]->data.name1)==0 || strcmp(k[j]->data.name3,k[j]->data.name1)==0);
								 if(strcmp(k[j]->data.name3,"大学语文")==0)
									 strcpy(k[j]->data.num3,"001");
								 else if(strcmp(k[j]->data.name3,"数学建模")==0)
									 strcpy(k[j]->data.num3,"002");
								 else if(strcmp(k[j]->data.name3,"市场营销")==0)
									 strcpy(k[j]->data.num3,"003");
								 else if(strcmp(k[j]->data.name3,"自然地理学")==0)
									 strcpy(k[j]->data.num3,"004");
								 else if(strcmp(k[j]->data.name3,"中国陶瓷史")==0)
									 strcpy(k[j]->data.num3,"005");
							 }
							 printf("\n新选修课名称已成功保存!\n");
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 else
			 goto lab4;
	 }
	 /*课程学分*/
	 else if(sel=='3')
	 {
		 printf("\n请选择修改的方式:\n1:根据学生学号修改信息;\t\t2:根据学生姓名修改信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号修改*/
		 if(sel=='1')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);
				 while((p!=NULL)&&(h!=NULL))
				 {
					 if(strcmp(tnum,p->data.num)==0 && strcmp(tnum,h->data.num)==0)
					 {
						 printheader1();
						 printdata(p,h);
						 printf(HEADER5);
						 do
						 {
							 printf("请输入课程编号:");
							 scanf("%s",tnum2);
							 if(strcmp(h->data.num1,tnum2)!=0 && strcmp(h->data.num2,tnum2)!=0 && strcmp(h->data.num3,tnum2)!=0)
								 printf("【您输入的课程编号有误!请重新输入!】\n");
						 }while(strcmp(h->data.num1,tnum2)!=0 && strcmp(h->data.num2,tnum2)!=0 && strcmp(h->data.num3,tnum2)!=0);
						 if(strcmp(tnum2,h->data.num1)==0)
						 {
							 do
							 {
								 printf("请输入新的选修课学分(0<=score<=4):");
								 scanf("%d",&h->data.score1);
								 if(h->data.score1<=0 || h->data.score1>4)
									 printf("【您输入的学分不合实际!请重新输入!】\n");
							 }while(h->data.score1<=0 || h->data.score1>4);
							 printf("\n新选修课学分已成功保存!\n");
						 }
						 else if(strcmp(tnum2,h->data.num2)==0)
						 {
							 do
							 {
								 printf("请输入新的选修课学分(0<=score<=4):");
								 scanf("%d",&h->data.score2);
								 if(h->data.score2<=0 || h->data.score2>4)
									 printf("【您输入的学分不合实际!请重新输入!】\n");
							 }while(h->data.score2<=0 || h->data.score2>4);
							 printf("\n新选修课学分已成功保存!\n");
						 }
						 else if(strcmp(tnum2,h->data.num3)==0)
						 {
							 do
							 {
								 printf("请输入新的选修课学分(0<=score<=4):");
								 scanf("%d",&h->data.score3);
								 if(h->data.score3<=0 || h->data.score3>4)
									 printf("【您输入的学分不合实际!请重新输入!】\n");
							 }while(h->data.score3<=0 || h->data.score3>4);
							 printf("\n新选修课学分已成功保存!\n");
						 }
						 break;
					 }
					 else
					 {
						 p=p->next;
						 h=h->next;
						 if(p==NULL && h==NULL)
							 printf("【您输入的学生学号不存在!】\n");
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 /*根据姓名修改*/
		 else if(sel=='2')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)      /*把同名同姓的学生及选修信息放进数组里*/
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
					 printf("【您输入的姓名有误!找不到相关信息!】\n");
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);                /*对同名同姓者的数据统计，再对用户输入的学号进行信息修改*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要修改的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 do
							 {
								 printf("请输入课程编号:");
								 scanf("%s",tnum2);
								 if(strcmp(k[j]->data.num1,tnum2)!=0 && strcmp(k[j]->data.num2,tnum2)!=0 && strcmp(k[j]->data.num3,tnum2)!=0)
									 printf("【您输入的课程编号有误!请重新输入!】\n");
							 }while(strcmp(k[j]->data.num1,tnum2)!=0 && strcmp(k[j]->data.num2,tnum2)!=0 && strcmp(k[j]->data.num3,tnum2)!=0);
							 if(strcmp(tnum2,k[j]->data.num1)==0)
							 {
								 do
								 {
									 printf("请输入新的选修课学分(0<=score<=4):");
									 scanf("%d",&k[j]->data.score1);
									 if(k[j]->data.score1<=0 || k[j]->data.score1>4)
										 printf("【您输入的学分不合实际!请重新输入!】\n");
								 }while(k[j]->data.score1<=0 || k[j]->data.score1>4);
								 printf("\n新选修课学分已成功保存!\n");
							 }
							 else if(strcmp(tnum2,k[j]->data.num2)==0)
							 {
								 do
								 {
									 printf("请输入新的选修课学分(0<=score<=4):");
									 scanf("%d",&k[j]->data.score2);
									 if(k[j]->data.score2<=0 || k[j]->data.score2>4)
										 printf("【您输入的学分不合实际!请重新输入!】\n");
								 }while(k[j]->data.score2<=0 || k[j]->data.score2>4);
								 printf("\n新选修课学分已成功保存!\n");
							 }
							 else if(strcmp(tnum2,k[j]->data.num3)==0)
							 {
								 do
								 {
									 printf("请输入新的选修课学分(0<=score<=4):");
									 scanf("%d",&k[j]->data.score3);
									 if(k[j]->data.score3<=0 || k[j]->data.score3>4)
										 printf("【您输入的学分不合实际!请重新输入!】\n");
								 }while(k[j]->data.score3<=0 || k[j]->data.score3>4);
								 printf("\n新选修课学分已成功保存!\n");
							 }
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 else
			 goto lab4;
	 }
	 /*平时成绩*/
	 else if(sel=='4')
	 {
		 printf("\n请选择修改的方式:\n1:根据学生学号修改信息;\t\t2:根据学生姓名修改信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号修改*/
		 if(sel=='1')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);
				 while((p!=NULL)&&(h!=NULL))
				 {
					 if(strcmp(tnum,p->data.num)==0 && strcmp(tnum,h->data.num)==0)
					 {
						 printheader1();
						 printdata(p,h);
						 printf(HEADER5);
						 do
						 {
							 printf("请输入课程编号:");
							 scanf("%s",tnum2);
							 if(strcmp(h->data.num1,tnum2)!=0 && strcmp(h->data.num2,tnum2)!=0 && strcmp(h->data.num3,tnum2)!=0)
								 printf("【您输入的课程编号有误!请重新输入!】\n");
						 }while(strcmp(h->data.num1,tnum2)!=0 && strcmp(h->data.num2,tnum2)!=0 && strcmp(h->data.num3,tnum2)!=0);
						 if(strcmp(tnum2,h->data.num1)==0)
						 {
							 do
							 {
								 printf("请输入新的选修课的平时成绩:");
								 scanf("%lf",&h->data.usual1);
								 if(h->data.usual1<0 || h->data.usual1>100)
									 printf("【您输入的成绩有误!请重新输入!】\n");
							 }while(h->data.usual1<0 || h->data.usual1>100);
							 h->data.result1=0.7*h->data.test1+0.3*h->data.usual1;
							 printf("\n新平时成绩已成功保存!\n");
						 }
						 if(strcmp(tnum2,h->data.num2)==0)
						 {
							 do
							 {
								 printf("请输入新的选修课的平时成绩:");
								 scanf("%lf",&h->data.usual2);
								 if(h->data.usual2<0 || h->data.usual2>100)
									 printf("【您输入的成绩有误!请重新输入!】\n");
							 }while(h->data.usual2<0 || h->data.usual2>100);
							 h->data.result2=0.7*h->data.test2+0.3*h->data.usual2;
							 printf("\n新平时成绩已成功保存!\n");
						 }
						 if(strcmp(tnum2,h->data.num3)==0)
						 {
							 do
							 {
								 printf("请输入新的选修课的平时成绩:");
								 scanf("%lf",&h->data.usual3);
								 if(h->data.usual3<0 || h->data.usual3>100)
									 printf("【您输入的成绩有误!请重新输入!】\n");
							 }while(h->data.usual3<0 || h->data.usual3>100);
							 h->data.result3=0.7*h->data.test3+0.3*h->data.usual3;
							 printf("\n新平时成绩已成功保存!\n");
						 }
						 break;
					 }
					 else
					 {
						 p=p->next;
						 h=h->next;
						 if(p==NULL && h==NULL)
							 printf("【您输入的学生学号不存在!】\n");
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 /*根据姓名修改*/
		 else if(sel=='2')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)      /*把同名同姓的学生及选修信息放进数组里*/
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
					 printf("【您输入的姓名有误!找不到相关信息!】\n");
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);                /*对同名同姓者的数据统计，再对用户输入的学号进行信息修改*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要修改的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 do
							 {
								 printf("请输入课程编号:");
								 scanf("%s",tnum2);
								 if(strcmp(k[j]->data.num1,tnum2)!=0 && strcmp(k[j]->data.num2,tnum2)!=0 && strcmp(k[j]->data.num3,tnum2)!=0)
									 printf("【您输入的课程编号有误!请重新输入!】\n");
							 }while(strcmp(k[j]->data.num1,tnum2)!=0 && strcmp(k[j]->data.num2,tnum2)!=0 && strcmp(k[j]->data.num3,tnum2)!=0);
							 if(strcmp(tnum2,k[j]->data.num1)==0)
							 {
								 do
								 {
									 printf("请输入新的选修课的平时成绩:");
									 scanf("%lf",&k[j]->data.usual1);
									 if(k[j]->data.usual1<0 || k[j]->data.usual1>100)
										 printf("【您输入的成绩有误!请重新输入!】\n");
								 }while(k[j]->data.usual1<0 || k[j]->data.usual1>100);
								 k[j]->data.result1=0.7*k[j]->data.test1+0.3*k[j]->data.usual1;
								 printf("\n新平时成绩已成功保存!\n");
							 }
							 if(strcmp(tnum2,k[j]->data.num2)==0)
							 {
								 do
								 {
									 printf("请输入新的选修课的平时成绩:");
									 scanf("%lf",&k[j]->data.usual2);
									 if(k[j]->data.usual2<0 || k[j]->data.usual2>100)
										 printf("【您输入的成绩有误!请重新输入!】\n");
								 }while(k[j]->data.usual2<0 || k[j]->data.usual2>100);
								 k[j]->data.result2=0.7*k[j]->data.test2+0.3*k[j]->data.usual2;
								 printf("\n新平时成绩已成功保存!\n");
							 }
							 if(strcmp(tnum2,k[j]->data.num3)==0)
							 {
								 do
								 {
									 printf("请输入新的选修课的平时成绩:");
									 scanf("%lf",&k[j]->data.usual3);
									 if(k[j]->data.usual3<0 || k[j]->data.usual3>100)
										 printf("【您输入的成绩有误!请重新输入!】\n");
								 }while(k[j]->data.usual3<0 || k[j]->data.usual3>100);
								 k[j]->data.result3=0.7*k[j]->data.test3+0.3*k[j]->data.usual3;
								 printf("\n新平时成绩已成功保存!\n");
							 }
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 else
			 goto lab4;
	 }
	 /*考试成绩*/
	 else if(sel=='5')
	 {
		 printf("\n请选择修改的方式:\n1:根据学生学号修改信息;\t\t2:根据学生姓名修改信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号修改*/
		 if(sel=='1')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);
				 while((p!=NULL)&&(h!=NULL))
				 {
					 if(strcmp(tnum,p->data.num)==0 && strcmp(tnum,h->data.num)==0)
					 {
						 printheader1();
						 printdata(p,h);
						 printf(HEADER5);
						 do
						 {
							 printf("请输入课程编号:");
							 scanf("%s",tnum2);
							 if(strcmp(h->data.num1,tnum2)!=0 && strcmp(h->data.num2,tnum2)!=0 && strcmp(h->data.num3,tnum2)!=0)
								 printf("【您输入的课程编号有误!请重新输入!】\n");
						 }while(strcmp(h->data.num1,tnum2)!=0 && strcmp(h->data.num2,tnum2)!=0 && strcmp(h->data.num3,tnum2)!=0);
						 if(strcmp(tnum2,h->data.num1)==0)
						 {
							 do
							 {
								 printf("请输入新的选修课的考试成绩:");
								 scanf("%lf",&h->data.test1);
								 if(h->data.test1<0 || h->data.test1>100)
									 printf("【您输入的成绩有误!请重新输入!】\n");
							 }while(h->data.test1<0 || h->data.test1>100);
							 h->data.result1=0.7*h->data.test1+0.3*h->data.usual1;
							 printf("\n新考试成绩已成功保存!\n");
						 }
						 if(strcmp(tnum2,h->data.num2)==0)
						 {
							 do
							 {
								 printf("请输入新的选修课的考试成绩:");
								 scanf("%lf",&h->data.test2);
								 if(h->data.test2<0 || h->data.test2>100)
									 printf("【您输入的成绩有误!请重新输入!】\n");
							 }while(h->data.test2<0 || h->data.test2>100);
							 h->data.result2=0.7*h->data.test2+0.3*h->data.usual2;
							 printf("\n新考试成绩已成功保存!\n");
						 }
						 if(strcmp(tnum2,h->data.num3)==0)
						 {
							 do
							 {
								 printf("请输入新的选修课的考试成绩:");
								 scanf("%lf",&h->data.test3);
								 if(h->data.test3<0 || h->data.test3>100)
									 printf("【您输入的成绩有误!请重新输入!】\n");
							 }while(h->data.test3<0 || h->data.test3>100);
							 h->data.result3=0.7*h->data.test3+0.3*h->data.usual3;
							 printf("\n新考试成绩已成功保存!\n");
						 }
						 break;
					 }
					 else
					 {
						 p=p->next;
						 h=h->next;
						 if(p==NULL && h==NULL)
							 printf("【您输入的学生学号不存在!】\n");
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 /*根据姓名修改*/
		 else if(sel=='2')
		 {
			 printf("您是否确定修改学生信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)      /*把同名同姓的学生及选修信息放进数组里*/
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
					 printf("【您输入的姓名有误!找不到相关信息!】\n");
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);                /*对同名同姓者的数据统计，再对用户输入的学号进行信息修改*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要修改的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 do
							 {
								 printf("请输入课程编号:");
								 scanf("%s",tnum2);
								 if(strcmp(k[j]->data.num1,tnum2)!=0 && strcmp(k[j]->data.num2,tnum2)!=0 && strcmp(k[j]->data.num3,tnum2)!=0)
									 printf("【您输入的课程编号有误!请重新输入!】\n");
							 }while(strcmp(k[j]->data.num1,tnum2)!=0 && strcmp(k[j]->data.num2,tnum2)!=0 && strcmp(k[j]->data.num3,tnum2)!=0);
							 if(strcmp(tnum2,k[j]->data.num1)==0)
							 {
								 do
								 {
									 printf("请输入新的选修课的考试成绩:");
									 scanf("%lf",&k[j]->data.test1);
									 if(k[j]->data.test1<0 || k[j]->data.test1>100)
										 printf("【您输入的成绩有误!请重新输入!】\n");
								 }while(k[j]->data.test1<0 || k[j]->data.test1>100);
								 k[j]->data.result1=0.7*k[j]->data.test1+0.3*k[j]->data.usual1;
								 printf("\n新考试成绩已成功保存!\n");
							 }
							 if(strcmp(tnum2,k[j]->data.num2)==0)
							 {
								 do
								 {
									 printf("请输入新的选修课的考试成绩:");
									 scanf("%lf",&k[j]->data.test2);
									 if(k[j]->data.test2<0 || k[j]->data.test2>100)
										 printf("【您输入的成绩有误!请重新输入!】\n");
								 }while(k[j]->data.test2<0 || k[j]->data.test2>100);
								 k[j]->data.result2=0.7*k[j]->data.test2+0.3*k[j]->data.usual2;
								 printf("\n新考试成绩已成功保存!\n");
							 }
							 if(strcmp(tnum2,k[j]->data.num3)==0)
							 {
								 do
								 {
									 printf("请输入新的选修课的考试成绩:");
									 scanf("%lf",&k[j]->data.test3);
									 if(k[j]->data.test3<0 || k[j]->data.test3>100)
										 printf("【您输入的成绩有误!请重新输入!】\n");
								 }while(k[j]->data.test3<0 || k[j]->data.test3>100);
								 k[j]->data.result3=0.7*k[j]->data.test3+0.3*k[j]->data.usual3;
								 printf("\n新考试成绩已成功保存!\n");
							 }
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab4;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab4;
			 }
		 }
		 else
			 goto lab4;
	 }
	 else
		 goto lab2;
	 }
	 }
	 //采用头插法插入用户输入的学生个数的选修课程信息
	 void insert(Node *head,Courselink *head2)
	 {
		 Node *p,*s,*r;
		 Courselink *h,*q,*k;
		 char ch,tnum[20],tnum1[20];
		 int i,n;
		 printf("\n请输入要插入信息的学生个数(输入0则返回):");
		 scanf("%d",&n);
		 if(n!=0)
		 {
			 for(i=0;i<n;i++)
			 {
				 do
				 {
					 printf("请输入学生学号:");
					 scanf("%s",tnum);
					 if(strcmp(tnum,"0")==0)
						 printf("【您输入的学号有误!请重新输入!】\n");
				 }while(strcmp(tnum,"0")==0);
				 s=head->next;
				 while(s)
				 {
					 if(strcmp(s->data.num,tnum)==0)
					 {
						 printf("【学号为%s的学生已经存在!】\n",tnum);
						 return;
					 }
					 s=s->next;
				 }
				 p=(Node*)malloc(sizeof(Node));
				 h=(Courselink*)malloc(sizeof(Courselink));
				 strcpy(p->data.num,tnum);
				 strcpy(h->data.num,p->data.num);
				 printf("请输入学生的姓名:");
				 scanf("%s",p->data.name);
				 strcpy(h->data.name,p->data.name);
				 printf("请输入学生的班级:");
				 scanf("%s",p->data.classes);
				 do
				 {
					 printf("请输入学生的性别(男或女):");
					 scanf("%s",p->data.sex);
					 if((strcmp(p->data.sex,"男")!=0) && (strcmp(p->data.sex,"女")!=0))
						 printf("【您输入的性别格式有误!请重新输入!】\n");
				 }while((strcmp(p->data.sex,"男")!=0) && (strcmp(p->data.sex,"女")!=0));
				 do
				 {
					 printf("请输入学生的年龄:");
					 scanf("%d",&p->data.age);
					 if(p->data.age<=0 || p->data.age>120)
						 printf("【您输入的年龄有误!请重新输入!】\n");
				 }while(p->data.age<=0 || p->data.age>120);
				 do
				 {	
					 printf("该学生选择多少门选修课(m<=3):");
					 scanf("%d",&p->data.m);
					 if(p->data.m<=0 || p->data.m>3)
						 printf("【您输入的数据有误!请重新输入!】\n");
				 }while(p->data.m<=0 || p->data.m>3);
				 switch(p->data.m)
				 {
				 case 1:
					 do
					 {
						 printf("请输入这门选修课的编号:");
						 scanf("%s",h->data.num1);
						 if(strcmp(h->data.num1,"001")==0 || strcmp(h->data.num1,"002")==0 || strcmp(h->data.num1,"003")==0 || strcmp(h->data.num1,"004")==0 || strcmp(h->data.num1,"005")==0)
							 break;
						 else
							 printf("【你的输入的编号不存在!请重新输入!】\n");
					 }while(h->data.num1!="001" || h->data.num1!="002" || h->data.num1!="003" || h->data.num1!="004" || h->data.num1!="005");
					 do
					 {
						 printf("请输入这门选修课的名称:");
						 scanf("%s",h->data.name1);
						 if(strcmp(h->data.num1,"001")==0)
						 {
							 if(strcmp(h->data.name1,"大学语文")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"002")==0)
						 {
							 if(strcmp(h->data.name1,"数学建模")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"003")==0)
						 {
							 if(strcmp(h->data.name1,"市场营销")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"004")==0)
						 {
							 if(strcmp(h->data.name1,"自然地理学")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"005")==0)
						 {
							 if(strcmp(h->data.name1,"中国陶瓷史")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
		 }while(strcmp(h->data.name1,"大学语文")!=0 || strcmp(h->data.name1,"数学建模")!=0 || strcmp(h->data.name1,"市场营销")!=0 || strcmp(h->data.name1,"自然地理学")!=0 || strcmp(h->data.name1,"中国陶瓷史")!=0);
		 do
		 {
			 printf("请输入这门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score1);
			 if(h->data.score1<=0 || h->data.score1>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score1<=0 || h->data.score1>4);
		 do
		 {
			 printf("请输入这门选修课的考试成绩:");
			 scanf("%lf",&h->data.test1);
			 if(h->data.test1<0 || h->data.test1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test1<0 || h->data.test1>100);
		 do
		 {
			 printf("请输入这门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual1);
			 if(h->data.usual1<0 || h->data.usual1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual1<0 || h->data.usual1>100);
		 h->data.result1=0.7*h->data.test1+0.3*h->data.usual1;
		 printf("该学生这门课的综合成绩为%0.2lf\n",h->data.result1);
		 break;
				 case 2:
					 do
					 {
						 printf("请输入第一门选修课的编号:");
						 scanf("%s",h->data.num1);
						 if(strcmp(h->data.num1,"001")==0 || strcmp(h->data.num1,"002")==0 || strcmp(h->data.num1,"003")==0 || strcmp(h->data.num1,"004")==0 || strcmp(h->data.num1,"005")==0)
							 break;
						 else
							 printf("【你的输入的编号不存在!请重新输入!】\n");
					 }while(h->data.num1!="001" || h->data.num1!="002" || h->data.num1!="003" || h->data.num1!="004" || h->data.num1!="005");
					 do
					 {
						 printf("请输入第一门选修课的名称:");
						 scanf("%s",h->data.name1);
						 if(strcmp(h->data.num1,"001")==0)
						 {
							 if(strcmp(h->data.name1,"大学语文")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"002")==0)
						 {
							 if(strcmp(h->data.name1,"数学建模")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"003")==0)
						 {
							 if(strcmp(h->data.name1,"市场营销")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"004")==0)
						 {
							 if(strcmp(h->data.name1,"自然地理学")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"005")==0)
						 {
							 if(strcmp(h->data.name1,"中国陶瓷史")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
		 }while(strcmp(h->data.name1,"大学语文")!=0 || strcmp(h->data.name1,"数学建模")!=0 || strcmp(h->data.name1,"市场营销")!=0 || strcmp(h->data.name1,"自然地理学")!=0 || strcmp(h->data.name1,"中国陶瓷史")!=0);
		 do
		 {	
			 printf("请输入第一门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score1);
			 if(h->data.score1<=0 || h->data.score1>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score1<=0 || h->data.score1>4);
		 do
		 {
			 printf("请输入第一门选修课的考试成绩:");
			 scanf("%lf",&h->data.test1);
			 if(h->data.test1<0 ||h->data.test1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test1<0 || h->data.test1>100);
		 do
		 {
			 printf("请输入第一门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual1);
			 if(h->data.usual1<0 || h->data.usual1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual1<0 || h->data.usual1>100);
		 h->data.result1=0.7*h->data.test1+0.3*h->data.usual1;
		 printf("该学生第一门课的综合成绩为%0.2lf\n",h->data.result1);
		 do
		 {
			 do
			 {
				 printf("请输入第二门选修课的编号:");
				 scanf("%s",h->data.num2);
				 if(strcmp(h->data.num2,"001")==0 || strcmp(h->data.num2,"002")==0 || strcmp(h->data.num2,"003")==0 || strcmp(h->data.num2,"004")==0 || strcmp(h->data.num2,"005")==0)
					 break;
				 else
					 printf("【你的输入的编号不存在!请重新输入!】\n");
			 }while(h->data.num2!="001" || h->data.num2!="002" || h->data.num2!="003" || h->data.num2!="004" || h->data.num2!="005");
			 if(strcmp(h->data.num1,h->data.num2)==0)
				 printf("【编号有重复,请重新输入!】\n");
		 }while(strcmp(h->data.num1,h->data.num2)==0);
		 do
		 {
			 do
			 {
				 printf("请输入第二门选修课的名称:");
				 scanf("%s",h->data.name2);
				 if(strcmp(h->data.num2,"001")==0)
				 {
					 if(strcmp(h->data.name2,"大学语文")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"002")==0)
				 {
					 if(strcmp(h->data.name2,"数学建模")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"003")==0)
				 {
					 if(strcmp(h->data.name2,"市场营销")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"004")==0)
				 {
					 if(strcmp(h->data.name2,"自然地理学")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"005")==0)
				 {
					 if(strcmp(h->data.name2,"中国陶瓷史")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
		 }while(strcmp(h->data.name2,"大学语文")!=0 || strcmp(h->data.name2,"数学建模")!=0 || strcmp(h->data.name2,"市场营销")!=0 || strcmp(h->data.name2,"自然地理学")!=0 || strcmp(h->data.name2,"中国陶瓷史")!=0);
		 if(strcmp(h->data.name1,h->data.name2)==0)
			 printf("【名称有重复,请重新输入!】\n");
		 }while(strcmp(h->data.name1,h->data.name2)==0);
		 do
		 {	
			 printf("请输入第二门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score2);
			 if(h->data.score2<=0 || h->data.score2>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score2<=0 || h->data.score2>4);
		 do
		 {
			 printf("请输入第二门选修课的考试成绩:");
			 scanf("%lf",&h->data.test2);
			 if(h->data.test2<0 || h->data.test2>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test2<0 || h->data.test2>100);
		 do
		 {
			 printf("请输入第二门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual2);
			 if(h->data.usual2<0 || h->data.usual2>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual2<0 || h->data.usual2>100);
		 h->data.result2=0.7*h->data.test2+0.3*h->data.usual2;
		 printf("该学生第二门课的综合成绩为%0.2lf\n",h->data.result2);
		 break;
				 case 3:
					 do
					 {
						 printf("请输入第一门选修课的编号:");
						 scanf("%s",h->data.num1);
						 if(strcmp(h->data.num1,"001")==0 || strcmp(h->data.num1,"002")==0 || strcmp(h->data.num1,"003")==0 || strcmp(h->data.num1,"004")==0 || strcmp(h->data.num1,"005")==0)
							 break;
						 else
							 printf("【你的输入的编号不存在!请重新输入!】\n");
					 }while(h->data.num1!="001" || h->data.num1!="002" || h->data.num1!="003" || h->data.num1!="004" || h->data.num1!="005");
					 do
					 {
						 printf("请输入第一门选修课的名称:");
						 scanf("%s",h->data.name1);
						 if(strcmp(h->data.num1,"001")==0)
						 {
							 if(strcmp(h->data.name1,"大学语文")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"002")==0)
						 {
							 if(strcmp(h->data.name1,"数学建模")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"003")==0)
						 {
							 if(strcmp(h->data.name1,"市场营销")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"004")==0)
						 {
							 if(strcmp(h->data.name1,"自然地理学")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
						 else if(strcmp(h->data.num1,"005")==0)
						 {
							 if(strcmp(h->data.name1,"中国陶瓷史")==0)
								 break;
							 else
							 {
								 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
								 do
								 {
									 printf("需要查看《选修课程编号对应表》吗<y/n>?");
									 getchar();
									 scanf("%c",&ch);
									 if(ch=='y' || ch =='Y')
									 {
										 tips();
										 printf("\n");
										 break;
									 }
									 else if(ch=='n' || ch=='N')
										 break;
									 else
										 printf("【你的输入有误请重新输入!】\n");
								 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
							 }
						 }
		 }while(strcmp(h->data.name1,"大学语文")!=0 || strcmp(h->data.name1,"数学建模")!=0 || strcmp(h->data.name1,"市场营销")!=0 || strcmp(h->data.name1,"自然地理学")!=0 || strcmp(h->data.name1,"中国陶瓷史")!=0);
		 do
		 {	
			 printf("请输入第一门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score1);
			 if(h->data.score1<=0 || h->data.score1>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score1<=0 || h->data.score1>4);
		 do
		 {
			 printf("请输入第一门选修课的考试成绩:");
			 scanf("%lf",&h->data.test1);
			 if(h->data.test1<0 || h->data.test1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test1<0 || h->data.test1>100);
		 do
		 {
			 printf("请输入第一门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual1);
			 if(h->data.usual1<0 || h->data.usual1>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual1<0 || h->data.usual1>100);
		 h->data.result1=0.7*h->data.test1+0.3*h->data.usual1;
		 printf("该学生第一门课的综合成绩为%0.2lf\n",h->data.result1);
		 do
		 {
			 do
			 {
				 printf("请输入第二门选修课的编号:");
				 scanf("%s",h->data.num2);
				 if(strcmp(h->data.num2,"001")==0 || strcmp(h->data.num2,"002")==0 || strcmp(h->data.num2,"003")==0 || strcmp(h->data.num2,"004")==0 || strcmp(h->data.num2,"005")==0)
					 break;
				 else
					 printf("【你的输入的编号不存在!请重新输入!】\n");
			 }while(h->data.num2!="001" || h->data.num2!="002" || h->data.num2!="003" || h->data.num2!="004" || h->data.num2!="005");
			 if(strcmp(h->data.num1,h->data.num2)==0)
				 printf("【编号有重复,请重新输入!】\n");
		 }while(strcmp(h->data.num1,h->data.num2)==0);
		 do
		 {
			 do
			 {
				 printf("请输入第二门选修课的名称:");
				 scanf("%s",h->data.name2);
				 if(strcmp(h->data.num2,"001")==0)
				 {
					 if(strcmp(h->data.name2,"大学语文")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"002")==0)
				 {
					 if(strcmp(h->data.name2,"数学建模")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"003")==0)
				 {
					 if(strcmp(h->data.name2,"市场营销")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"004")==0)
				 {
					 if(strcmp(h->data.name2,"自然地理学")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num2,"005")==0)
				 {
					 if(strcmp(h->data.name2,"中国陶瓷史")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
		 }while(strcmp(h->data.name2,"大学语文")!=0 || strcmp(h->data.name2,"数学建模")!=0 || strcmp(h->data.name2,"市场营销")!=0 || strcmp(h->data.name2,"自然地理学")!=0 || strcmp(h->data.name2,"中国陶瓷史")!=0);
		 if(strcmp(h->data.name1,h->data.name2)==0)
			 printf("【名称有重复,请重新输入!】\n");
		 }while(strcmp(h->data.name1,h->data.name2)==0);
		 do
		 {	
			 printf("请输入第二门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score2);
			 if(h->data.score2<=0 || h->data.score2>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score2<=0 || h->data.score2>4);
		 do
		 {
			 printf("请输入第二门选修课的考试成绩:");
			 scanf("%lf",&h->data.test2);
			 if(h->data.test2<0 || h->data.test2>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test2<0 || h->data.test2>100);
		 do
		 {
			 printf("请输入第二门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual2);
			 if(h->data.usual2<0 || h->data.usual2>100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual2<0 || h->data.usual2>100);
		 h->data.result2=0.7*h->data.test2+0.3*h->data.usual2;
		 printf("该学生第二门课的综合成绩为%0.2lf\n",h->data.result2);
		 do
		 {
			 do
			 {
				 printf("请输入第三门选修课的编号:");
				 scanf("%s",h->data.num3);
				 if(strcmp(h->data.num3,"001")==0 || strcmp(h->data.num3,"002")==0 || strcmp(h->data.num3,"003")==0 || strcmp(h->data.num3,"004")==0 || strcmp(h->data.num3,"005")==0)
					 break;
				 else
					 printf("【你的输入的编号不存在!请重新输入!】\n");
			 }while(h->data.num3!="001" || h->data.num3!="002" || h->data.num3!="003" || h->data.num3!="004" || h->data.num3!="005");
			 if(strcmp(h->data.num3,h->data.num1)==0 || strcmp(h->data.num3,h->data.num2)==0)
				 printf("【编号有重复,请重新输入!】\n");
		 }while(strcmp(h->data.num3,h->data.num1)==0 || strcmp(h->data.num3,h->data.num2)==0);
		 do
		 {
			 do
			 {
				 printf("请输入第三门选修课的名称:");
				 scanf("%s",h->data.name3);
				 if(strcmp(h->data.num3,"001")==0)
				 {
					 if(strcmp(h->data.name3,"大学语文")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num3,"002")==0)
				 {
					 if(strcmp(h->data.name3,"数学建模")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num3,"003")==0)
				 {
					 if(strcmp(h->data.name3,"市场营销")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num3,"004")==0)
				 {
					 if(strcmp(h->data.name3,"自然地理学")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
				 else if(strcmp(h->data.num3,"005")==0)
				 {
					 if(strcmp(h->data.name3,"中国陶瓷史")==0)
						 break;
					 else
					 {
						 printf("【你输入的课程名称与编号不对应!请重新输入!】\n");
						 do
						 {
							 printf("需要查看《选修课程编号对应表》吗<y/n>?");
							 getchar();
							 scanf("%c",&ch);
							 if(ch=='y' || ch =='Y')
							 {
								 tips();
								 printf("\n");
								 break;
							 }
							 else if(ch=='n' || ch=='N')
								 break;
							 else
								 printf("【你的输入有误请重新输入!】\n");
						 }while(ch!='y' || ch!='Y' || ch!='n' || ch!='N');
					 }
				 }
		 }while(strcmp(h->data.name3,"大学语文")!=0 || strcmp(h->data.name3,"数学建模")!=0 || strcmp(h->data.name3,"市场营销")!=0 || strcmp(h->data.name3,"自然地理学")!=0 || strcmp(h->data.name3,"中国陶瓷史")!=0);
		 if(strcmp(h->data.name3,h->data.name1)==0 && strcmp(h->data.name3,h->data.name2)==0)
			 printf("【名称有重复,请重新输入!】\n");
		 }while(strcmp(h->data.name3,h->data.name1)==0 && strcmp(h->data.name3,h->data.name2)==0);
		 do
		 {	
			 printf("请输入第三门选修课的学分(0<score<=4):");
			 scanf("%d",&h->data.score3);
			 if(h->data.score3<=0 || h->data.score3>4)
				 printf("【您输入的学分不合实际!请重新输入!】\n");
		 }while(h->data.score3<=0 || h->data.score3>4);
		 do
		 {
			 printf("请输入第三门选修课的考试成绩:");
			 scanf("%lf",&h->data.test3);
			 if(h->data.test3<0 || h->data.test3>=100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.test3<0 || h->data.test3>=100);
		 do
		 {
			 printf("请输入第三门选修课的平时成绩:");
			 scanf("%lf",&h->data.usual3);
			 if(h->data.usual3<0 || h->data.usual3>=100)
				 printf("【您输入的成绩有误!请重新输入!】\n");
		 }while(h->data.usual3<0 || h->data.usual3>=100);
		 h->data.result3=0.7*h->data.test3+0.3*h->data.usual3;
		 printf("该学生第三门课的综合成绩为%0.2lf\n",h->data.result3);
		 break;
}
printf("请问您要将信息插入到哪个学号的学生之前?请输入其学号:");
do
{
	scanf("%s",tnum1);
	if(strcmp(tnum1,"0")==0)
		printf("【您输入的学号有误!请重新输入!】\n");
}while(strcmp(tnum1,"0")==0);
r=head;
q=head2;
s=r->next;
k=q->next;
while(s!=NULL && k!=NULL)
{
	if(strcmp(s->data.num,tnum1)!=0 && strcmp(k->data.num,tnum1)!=0)
	{
		r=s;
		s=s->next;
		q=k;
		k=k->next;
		if(s==NULL && k==NULL)
		{	 
			printf("【您输入的学号有误!信息未插入并返回主菜单!】\n");
			return;
		}
	}
	else if(strcmp(s->data.num,tnum1)==0 && strcmp(k->data.num,tnum1)==0)
	{
		p->next=r->next;
		r->next=p;
		h->next=q->next;
		q->next=h;
		break;
	}
}
}
printf("\n已成功插入%d个学生及其选修课的信息!\n",n);
}
else
return;
}
//查询学生或者选修课程信息
void search(Node *head,Courselink *head2)
{
	Node *p,*s[10];
	Courselink *h,*k[10];
	int i=0,j;
	int sel;
	char tnum[20],tname[10];
	if((!head->next) && (!head2->next))
	{
		printf("无记录!\n");
		return;
	}
	printf("\n请输入查询的方式:\n1:根据学生学号查询信息;\t\t2:根据学生姓名查询信息;\t\t*其余任意数字键返回菜单.\n");
	scanf("%d",&sel);
	if(sel==1)
	{
		printf("请输入学生的学号:");
		scanf("%s",tnum);
		p=head->next;
        h=head2->next;
		while((p!=NULL) && (h!=NULL))
		{
			if(strcmp(p->data.num,tnum)==0 && strcmp(h->data.num,tnum)==0)
			{
				printheader1();
				while((p!=NULL) && (h!=NULL))
				{
					if(p->data.m==1)
					{
						printf(FORMAT1,DATA1);
						break;
					}
					else if(p->data.m==2)
					{
						printf(FORMAT1,DATA1);
						printf(FORMAT2,DATA2);
						break;
					}
					else if(p->data.m==3)
					{
						printf(FORMAT1,DATA1);
						printf(FORMAT2,DATA2);
						printf(FORMAT3,DATA3);
						break;
					}
				}
				printf(HEADER5);
				break;
			}
			else
			{
				p=p->next;
				h=h->next;
				if((p==NULL) && (h==NULL))
					printf("【您输入的学号有误!找不到相关信息!】\n");
			}
		}
	}
	else if(sel==2)
	{
		printf("请输入学生的姓名:");
		scanf("%s",tname);
		p=head->next;
        h=head2->next;
		while((p!=NULL) && (h!=NULL))
		{
			if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)
			{
				while(p!=NULL && h!=NULL)
				{
					if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)
					{
						s[i]=p;
						k[i]=h;
						i++;
					}
					p=p->next;
					h=h->next;
				}
				printf("\n同名同姓的学生一共有%d个!\n",i);
				printheader1();
				for(j=0;j<i;j++)
					printdata(s[j],k[j]);
				printf(HEADER5);
				break;
			}
			else
			{
				p=p->next;
				h=h->next;
				if((p==NULL) && (h==NULL))
					printf("【您输入的姓名有误!找不到相关信息!】\n");
			}
		}
	}
	else
		return;
}
//删除学生及其选修课程信息
void del(Node *head,Courselink *head2)
{
	Node *p,*r,*s[10];
	Courselink *h,*q,*k[10];
	int j,i=0;
	char sel,ch,tnum[20],tname[10],tnum1[20];
	if((head->next==NULL) && (head2->next==NULL))
	{
		printf("无记录!\n");	
        return;
	}
lab5:printf("\n请选择删除的内容:\n1:删除所有选修课信息;\t2.删除第一门选修课成绩;\t3.删除第二门选修课成绩;\t4.删除第三门选修课成绩;\t*其余任意键回车返回菜单.\n");
	 getchar();
	 scanf("%c",&sel);
	 /*删除所有选修课信息*/
	 if(sel=='1')
	 {
lab6:printf("\n请选择删除的方式:\n1:根据学生学号删除信息;\t\t2:根据学生姓名删除信息;\t\t*其余任意键回车返回上一级.\n");
	 getchar();
	 scanf("%c",&sel);
	 /*根据学号删除*/
	 if(sel=='1')
	 { 
		 printf("您是否确定删除学生选修课信息?(y/n):");
		 getchar();
		 scanf("%c",&ch);
		 if(ch=='y' || ch=='Y')
		 {
			 printf("请输入学生的学号:");
			 scanf("%s",tnum);
			 r=head;
			 p=r->next;
			 q=head2;
			 h=q->next;
			 while(p!=NULL && h!=NULL)
			 {
				 if(strcmp(p->data.num,tnum)!=0 && strcmp(h->data.num,tnum)!=0)
				 {
					 r=p;
					 p=p->next;
					 q=h;
					 h=h->next;
					 if(p==NULL && h==NULL)
					 {	 
						 printf("【您输入的学号有误!信息未删除并返回主菜单!】\n");
						 return;
					 }
				 }
				 else if(strcmp(p->data.num,tnum)==0 && strcmp(h->data.num,tnum)==0)
				 {
					 printheader1();
					 if(p->data.m==1)
						 printf(FORMAT1,DATA1);
					 else if(p->data.m==2)
					 {
						 printf(FORMAT1,DATA1);
						 printf(FORMAT2,DATA2);
					 }
					 else if(p->data.m==3)
					 {
						 printf(FORMAT1,DATA1);
						 printf(FORMAT2,DATA2);
						 printf(FORMAT3,DATA3);
					 }
					 printf(HEADER5);
					 
					 r->next=p->next;
					 q->next=h->next;
					 free(p);
					 free(h);
					 printf("已成功删除全部选修课信息!\n");
					 break;
				 }
				 
			 }
		 }
		 else if(ch=='n' || ch=='N')
		 { 
			 printf("【返回上一级!】\n");
			 goto lab6;
		 }
		 else
		 {
			 printf("【您的输入有误!返回上一级!】\n");
			 goto lab6;
		 }
	 }
	 /*根据姓名删除*/
	 else if(sel=='2')
	 {
		 printf("您是否确定删除学生选修课信息?(y/n):");
		 getchar();
		 scanf("%c",&ch);
		 if(ch=='y' || ch=='Y')
		 {
			 printf("请输入学生原来的姓名:");
			 scanf("%s",tname);
			 r=head;
			 p=r->next;
			 q=head2;
			 h=q->next;
			 while(p!=NULL && h!=NULL)
			 {
				 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)
				 {
					 s[i]=p;
					 k[i]=h;
					 i++;
				 }
				 p=p->next;
				 h=h->next;
			 }
			 if(i==0)
			 {	 
				 printf("【您输入的姓名有误!信息未删除并返回主菜单!】\n");
				 return;
			 }
			 else
			 {
				 printf("\n同名同姓的学生一共有%d个!\n",i);          /*对同名同姓者的数据统计，再对用户输入的学号进行信息删除*/
				 printheader1();
				 for(j=0;j<i;j++)
					 printdata(s[j],k[j]);
				 printf(HEADER5);
				 printf("请输入您要删除的学生学号:");
				 scanf("%s",tnum1);
				 for(j=0;j<i;j++)
				 { 
					 r=head;
					 q=head2;
					 while(r->next!=s[j] && q->next!=k[j])
					 {
						 r=r->next;
						 q=q->next;
					 }
					 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
					 {
						 r->next=s[j]->next;
						 free(s[j]);
						 q->next=k[j]->next;
						 free(k[j]);
						 printf("已成功删除!\n");
						 break;
					 }
					 else
					 {
						 s[j]=s[j]->next;
						 k[j]=k[j]->next;
						 if(++j==i)
						 {
							 printf("【您输入的学生学号不存在!】\n");
							 break;
						 }
					 }
				 }
			 }
		 }
		 else if(ch=='n' || ch=='N')
		 {
			 printf("【返回上一级!】\n");
			 goto lab6;
		 }
		 else
		 {
			 printf("【您的输入有误!返回上一级!】\n");
			 goto lab6;
		 }
	 }
	 else
		 goto lab5;
}
/*删除第一门选修课信息*/
else if(sel=='2')
{
lab7:printf("\n请选择删除的方式:\n1:根据学生学号删除信息;\t\t2:根据学生姓名删除信息;\t\t*其余任意键回车返回上一级.\n");
	 getchar();
	 scanf("%c",&sel);
	 /*根据学号删除*/
	 if(sel=='1')
	 { 
		 printf("您是否确定删除学生选修课信息?(y/n):");
		 getchar();
		 scanf("%c",&ch);
		 if(ch=='y' || ch=='Y')
		 {
			 printf("请输入学生的学号:");
			 scanf("%s",tnum);
			 r=head;
			 p=r->next;
			 q=head2;
			 h=q->next;
			 while(p!=NULL && h!=NULL)
			 {
				 if(strcmp(p->data.num,tnum)!=0 && strcmp(h->data.num,tnum)!=0)
				 {
					 r=p;
					 p=p->next;
					 q=h;
					 h=h->next;
					 if(p==NULL && h==NULL)
					 {	 
						 printf("【您输入的学号有误!信息未删除并返回主菜单!】\n");
						 return;
					 }
				 }
				 else if(strcmp(p->data.num,tnum)==0 && strcmp(h->data.num,tnum)==0)
				 {
					 if(p->data.m==1)
					 {	 
						 r->next=p->next;
						 q->next=h->next;
						 free(p);
						 free(h);
						 printf("已成功删除第一门选修课信息!\n");
					 }
					 else if(p->data.m==2)
					 {
						 strcpy(h->data.num1,h->data.num2);
                         strcpy(h->data.name1,h->data.name2);
                         h->data.score1=h->data.score2;
						 h->data.usual1=h->data.usual2;
						 h->data.test1=h->data.test2;
						 h->data.result1=h->data.result2;
						 p->data.m=1;
						 printf("已成功删除第一门选修课信息!\n");
					 }
					 else if(p->data.m==3)
					 {
						 strcpy(h->data.num1,h->data.num2);
                         strcpy(h->data.name1,h->data.name2);
                         h->data.score1=h->data.score2;
						 h->data.usual1=h->data.usual2;
						 h->data.test1=h->data.test2;
						 h->data.result1=h->data.result2;
						 strcpy(h->data.num2,h->data.num3);
                         strcpy(h->data.name2,h->data.name3);
                         h->data.score2=h->data.score3;
						 h->data.usual2=h->data.usual3;
						 h->data.test2=h->data.test3;
						 h->data.result2=h->data.result3;
						 p->data.m=2;
						 printf("已成功删除第一门选修课信息!\n");
					 }
					 break;
				 }
			 }
		 }
		 else if(ch=='n' || ch=='N')
		 { 
			 printf("【返回上一级!】\n");
			 goto lab7;
		 }
		 else
		 {
			 printf("【您的输入有误!返回上一级!】\n");
			 goto lab7;
		 }
	 }
	 /*根据姓名删除*/
	 else if(sel=='2')
	 {
		 printf("您是否确定删除学生选修课信息?(y/n):");
		 getchar();
		 scanf("%c",&ch);
		 if(ch=='y' || ch=='Y')
		 {
			 printf("请输入学生原来的姓名:");
			 scanf("%s",tname);
			 r=head;
			 p=r->next;
			 q=head2;
			 h=q->next;
			 while(p!=NULL && h!=NULL)
			 {
				 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)
				 {
					 s[i]=p;
					 k[i]=h;
					 i++;
				 }
				 p=p->next;
				 h=h->next;
			 }
			 if(i==0)
			 {	 
				 printf("【您输入的姓名有误!信息未删除并返回主菜单!】\n");
				 return;
			 }
			 else
			 {
				 printf("\n同名同姓的学生一共有%d个!\n",i);          /*对同名同姓者的数据统计，再对用户输入的学号进行信息删除*/
				 printheader1();
				 for(j=0;j<i;j++)
					 printdata(s[j],k[j]);
				 printf(HEADER5);
				 printf("请输入您要删除的学生学号:");
				 scanf("%s",tnum1);
				 for(j=0;j<i;j++)
				 {
					 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
					 {
						 if(s[j]->data.m==1)
						 {	 
							 r=head;
							 q=head2;
							 while(r->next!=s[j] && q->next!=k[j])
							 {
								 r=r->next;
								 q=q->next;
							 }
							 r->next=s[j]->next;
							 free(s[j]);
							 q->next=k[j]->next;
							 free(k[j]);
							 printf("已成功删除第一门选修课信息!\n");
							 break;
						 }
						 else if(s[j]->data.m==2)
						 {
							 strcpy(k[j]->data.num1,k[j]->data.num2);
							 strcpy(k[j]->data.name1,k[j]->data.name2);
							 k[j]->data.score1=k[j]->data.score2;
							 k[j]->data.usual1=k[j]->data.usual2;
							 k[j]->data.test1=k[j]->data.test2;
							 k[j]->data.result1=k[j]->data.result2;
							 s[j]->data.m=1;
							 printf("已成功删除第一门选修课信息!\n");
							 break;
						 }
						 else if(s[j]->data.m==3)
						 {
							 strcpy(k[j]->data.num1,k[j]->data.num2);
							 strcpy(k[j]->data.name1,k[j]->data.name2);
							 k[j]->data.score1=k[j]->data.score2;
							 k[j]->data.usual1=k[j]->data.usual2;
							 k[j]->data.test1=k[j]->data.test2;
							 k[j]->data.result1=k[j]->data.result2;
							 strcpy(k[j]->data.num2,k[j]->data.num3);
							 strcpy(k[j]->data.name2,k[j]->data.name3);
							 k[j]->data.score2=k[j]->data.score3;
							 k[j]->data.usual2=k[j]->data.usual3;
							 k[j]->data.test2=k[j]->data.test3;
							 k[j]->data.result2=k[j]->data.result3;
							 s[j]->data.m=2;
							 printf("已成功删除第一门选修课信息!\n");
							 break;
						 }
					 }
					 else
					 {
						 s[j]=s[j]->next;
						 k[j]=k[j]->next;
						 if(++j==i)
						 {
							 printf("【您输入的学生学号不存在!】\n");
							 break;
						 }
					 }
				 }
			 }
		 }
		 else if(ch=='n' || ch=='N')
		 {
			 printf("【返回上一级!】\n");
			 goto lab7;
		 }
		 else
		 {
			 printf("【您的输入有误!返回上一级!】\n");
			 goto lab7;
		 }
	 }
	 else
		 goto lab5;
	 }
	 /*删除第二门选修课信息*/
	 else if(sel=='3')
	 {
		 printf("\n请选择删除的方式:\n1:根据学生学号删除信息;\t\t2:根据学生姓名删除信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号删除*/
		 if(sel=='1')
		 { 
			 printf("您是否确定删除学生选修课信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);
				 r=head;
				 p=r->next;
				 q=head2;
				 h=q->next;
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.num,tnum)!=0 && strcmp(h->data.num,tnum)!=0)
					 {
						 r=p;
						 p=p->next;
						 q=h;
						 h=h->next;
						 if(p==NULL && h==NULL)
						 {	 
							 printf("【您输入的学号有误!信息未删除并返回主菜单!】\n");
							 return;
						 }
					 }
					 else if(strcmp(p->data.num,tnum)==0 && strcmp(h->data.num,tnum)==0)
					 {
						 if(p->data.m==1)
						 {	 
							 printf("【只有一门选修课,无法删除第二门选修课信息!】\n");
							 break;
						 }
						 else if(p->data.m==2)
						 {
							 p->data.m=1;
							 printf("已成功删除第二门选修课信息!\n");
							 break;
						 }
						 else if(p->data.m==3)
						 {
							 strcpy(h->data.num2,h->data.num3);
							 strcpy(h->data.name2,h->data.name3);
							 h->data.score2=h->data.score3;
							 h->data.usual2=h->data.usual3;
							 h->data.test2=h->data.test3;
							 h->data.result2=h->data.result3;
							 p->data.m=2;
							 printf("已成功删除第二门选修课信息!\n");
							 break;
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 { 
				 printf("【返回上一级!】\n");
				 goto lab7;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab7;
			 }
		 }
		 /*根据姓名删除*/
		 else if(sel=='2')
		 {
			 printf("您是否确定删除学生选修课信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 r=head;
				 p=r->next;
				 q=head2;
				 h=q->next;
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
				 {	 
					 printf("【您输入的姓名有误!信息未删除并返回主菜单!】\n");
					 return;
				 }
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);          /*对同名同姓者的数据统计，再对用户输入的学号进行信息删除*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要删除的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 if(s[j]->data.m==1)
								 printf("【只有一门选修课,无法删除第二门选修课信息!】\n");
							 else if(s[j]->data.m==2)
							 {
								 s[j]->data.m=1;
								 printf("已成功删除第二门选修课信息!\n");
							 }
							 else if(s[j]->data.m==3)
							 {
								 strcpy(k[j]->data.num2,k[j]->data.num3);
								 strcpy(k[j]->data.name2,k[j]->data.name3);
								 k[j]->data.score2=k[j]->data.score3;
								 k[j]->data.usual2=k[j]->data.usual3;
								 k[j]->data.test2=k[j]->data.test3;
								 k[j]->data.result2=k[j]->data.result3;
								 s[j]->data.m=2;
								 printf("已成功删除第二门选修课信息!\n");
							 }
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab7;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab7;
			 }
		 }
		 else
			 goto lab5;
	 }
	 /*删除第三门选修课信息*/
	 else if(sel=='4')
	 {
		 printf("\n请选择删除的方式:\n1:根据学生学号删除信息;\t\t2:根据学生姓名删除信息;\t\t*其余任意键回车返回上一级.\n");
		 getchar();
		 scanf("%c",&sel);
		 /*根据学号删除*/
		 if(sel=='1')
		 { 
			 printf("您是否确定删除学生选修课信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生的学号:");
				 scanf("%s",tnum);
				 r=head;
				 p=r->next;
				 q=head2;
				 h=q->next;
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.num,tnum)!=0 && strcmp(h->data.num,tnum)!=0)
					 {
						 r=p;
						 p=p->next;
						 q=h;
						 h=h->next;
						 if(p==NULL && h==NULL)
						 {	 
							 printf("【您输入的学号有误!信息未删除并返回主菜单!】\n");
							 return;
						 }
					 }
					 else if(strcmp(p->data.num,tnum)==0 && strcmp(h->data.num,tnum)==0)
					 {
						 if(p->data.m==1)
							 printf("【只有一门选修课,无法删除第三门选修课信息!】\n");
						 else if(p->data.m==2)
							 printf("【只有两门选修课,无法删除第三门选修课信息!】\n");
						 else if(p->data.m==3)
						 {
							 p->data.m=2;
							 printf("已成功删除第三门选修课信息!\n");
						 }
						 break;
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 { 
				 printf("【返回上一级!】\n");
				 goto lab7;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab7;
			 }
		 }
		 /*根据姓名删除*/
		 else if(sel=='2')
		 {
			 printf("您是否确定删除学生选修课信息?(y/n):");
			 getchar();
			 scanf("%c",&ch);
			 if(ch=='y' || ch=='Y')
			 {
				 printf("请输入学生原来的姓名:");
				 scanf("%s",tname);
				 r=head;
				 p=r->next;
				 q=head2;
				 h=q->next;
				 while(p!=NULL && h!=NULL)
				 {
					 if(strcmp(p->data.name,tname)==0 && strcmp(h->data.name,tname)==0)
					 {
						 s[i]=p;
						 k[i]=h;
						 i++;
					 }
					 p=p->next;
					 h=h->next;
				 }
				 if(i==0)
				 {	 
					 printf("【您输入的姓名有误!信息未删除并返回主菜单!】\n");
					 return;
				 }
				 else
				 {
					 printf("\n同名同姓的学生一共有%d个!\n",i);          /*对同名同姓者的数据统计，再对用户输入的学号进行信息删除*/
					 printheader1();
					 for(j=0;j<i;j++)
						 printdata(s[j],k[j]);
					 printf(HEADER5);
					 printf("请输入您要删除的学生学号:");
					 scanf("%s",tnum1);
					 for(j=0;j<i;j++)
					 {
						 if(strcmp(s[j]->data.num,tnum1)==0 && strcmp(k[j]->data.num,tnum1)==0)
						 {
							 if(s[j]->data.m==1)
								 printf("【只有一门选修课,无法删除第三门选修课信息!】\n");
							 else if(s[j]->data.m==2)
								 printf("【只有两门选修课,无法删除第三门选修课信息!】\n");
							 else if(s[j]->data.m==3)
							 {
								 s[j]->data.m=2;
								 printf("已成功删除第三门选修课信息!\n");
							 }
							 break;
						 }
						 else
						 {
							 s[j]=s[j]->next;
							 k[j]=k[j]->next;
							 if(++j==i)
							 {
								 printf("【您输入的学生学号不存在!】\n");
								 break;
							 }
						 }
					 }
				 }
			 }
			 else if(ch=='n' || ch=='N')
			 {
				 printf("【返回上一级!】\n");
				 goto lab7;
			 }
			 else
			 {
				 printf("【您的输入有误!返回上一级!】\n");
				 goto lab7;
			 }
		 }
		 else
			 goto lab5;
	 }
	 }
	 
	 //显示所有学生及其选修课程信息
	 void showall(Node *head,Courselink *head2)
	 {
		 Node *p;
		 Courselink *h;
		 p=head->next;
		 h=head2->next;
		 if((head->next==NULL) && (head2->next==NULL))
		 {
			 printf("无记录!\n");	
			 return;
		 }
		 else
		 {
			 printheader1();
			 while((p!=NULL) && (h!=NULL))
			 {
				 if(p->data.m==1)
					 printf(FORMAT1,DATA1);
				 else if(p->data.m==2)
				 {
					 printf(FORMAT1,DATA1);
					 printf(FORMAT2,DATA2);
				 }
				 else if(p->data.m==3)
				 {
					 printf(FORMAT1,DATA1);
					 printf(FORMAT2,DATA2);
					 printf(FORMAT3,DATA3);
				 }
				 p=p->next;
				 h=h->next;
			 }
			 printf(HEADER5);
		 }
	 }
	 //计算学生各门功课平均成绩并降序排序，采用直接插入排序，稳定的排序，为多项式级时间复杂度
	 void orderaver(Node *head,Courselink *head2)
	 {
		 Node *p,*f,*s;
		 Courselink *h,*pre,*r;
		 int re=1;              /*记录学生名次的变量*/
		 p=head->next;
		 h=head2->next;
		 if((head->next==NULL) && (head2->next==NULL))
		 {
			 printf("无记录!\n");
			 return;
		 }
		 while(p&&h)
		 {
			 if(p->data.m==1)
				 h->data.aver=h->data.result1;
			 else if(p->data.m==2)
				 h->data.aver=(h->data.result1+h->data.result2)/2;
			 else if(p->data.m==3)
				 h->data.aver=(h->data.result1+h->data.result2+h->data.result3)/3;
			 p=p->next;
			 h=h->next;
		 }
		 h=head2->next;
		 r=h->next;        /*r保持*h后继结点指针，以保证不断链*/
		 h->next=NULL;     /*构造只含一个数据结点的有序表*/
		 h=r;
		 p=head->next;
		 s=p->next;
		 p->next=NULL;
		 p=s;
		 while(p!=NULL && h!=NULL)
		 {
			 r=h->next;       /*保存*h的后继结点指针*/
			 pre=head2;
			 s=p->next;
			 f=head;
			 while(f->next!=NULL && pre->next!=NULL && pre->next->data.aver>h->data.aver)
			 {	
				 pre=pre->next;    /*在有序表中查找插入*h的前驱结点*pre*/
				 f=f->next;
			 }
			 h->next=pre->next;   /*将*h插入到*pre之后*/
			 pre->next=h;
			 h=r;                 /*扫描原单链表中剩下的结点*/
			 p->next=f->next;
			 f->next=p;
			 p=s;
		 }
		 printf("\n***按平均成绩由高到低排序***\n");
		 printheader3();
		 p=head->next;
		 h=head2->next;
		 while(p&&h)
		 {
			 p->data.NO=re++;
			 printf(FORMAT7,DATA7);
			 p=p->next;
			 h=h->next;
		 }
		 printf(HEADER15);
	 }
	 //列出不及格学生的名单
	 void showbad(Node *head,Courselink *head2)
	 {
		 Node *p;
		 Courselink *h;
		 p=head->next;
		 h=head2->next;
		 if((head->next==NULL) && (head2->next==NULL))
		 {
			 printf("无记录!\n");
			 return;
		 }
		 else
		 {
			 printheader2();
			 while((p!=NULL) && (h!=NULL))
			 {
				 if(p->data.m==1)
				 {
					 if(h->data.result1<60)
					 {
						 printf(FORMAT4,DATA4);
						 p=p->next;
						 h=h->next;
					 }
					 else
					 {
						 p=p->next;
						 h=h->next;
					 }
				 }
				 else if(p->data.m==2)
				 {
					 if(h->data.result1<60 && h->data.result2>=60)
						 printf(FORMAT4,DATA4);
					 if(h->data.result1>=60 && h->data.result2<60)
						 printf(FORMAT4,DATA5);
					 if(h->data.result1<60 && h->data.result2<60)
					 {
						 printf(FORMAT4,DATA4);
						 printf(FORMAT5,DATA8);
					 }
					 p=p->next;
					 h=h->next;
				 }
				 else if(p->data.m==3)
				 {
					 if(h->data.result1<60)
					 {
						 if(h->data.result2>=60)
						 {
							 if(h->data.result3>=60)
								 printf(FORMAT4,DATA4);
							 else
							 {
								 printf(FORMAT4,DATA4);
								 printf(FORMAT5,DATA9);
							 }
						 }
						 else
						 {
							 if(h->data.result3>=60)
							 {
								 printf(FORMAT4,DATA4);
								 printf(FORMAT5,DATA8);
							 }
							 else
							 {
								 printf(FORMAT4,DATA4);
								 printf(FORMAT5,DATA8);
								 printf(FORMAT6,DATA9);
							 }
						 }
					 }
					 else
					 {
						 if(h->data.result2>=60)
						 {
							 if(h->data.result3<0)
								 printf(FORMAT4,DATA6);
						 }
						 else
						 {
							 if(h->data.result3>=0)
								 printf(FORMAT4,DATA5);
							 else
							 {
								 printf(FORMAT4,DATA5);
								 printf(FORMAT5,DATA9);
							 }
						 }
					 }
					 p=p->next;
					 h=h->next;
				 }
				 else
				 {
					 p=p->next;
					 h=h->next;
					 if(p==NULL && h==NULL)
						 printf("无不及格的学生!\n");
				 }
			 }
			 printf(HEADER10);
		 }
}
//读取“基本信息”的文件内容
void read(Node *l,Courselink *k)
{
	FILE *fp1;
	Node *r,*p;
	Courselink *q,*h;
	r=l;
	q=k;
	fp1=fopen("基本信息.txt","rb+");/*打开存储基本信息的文件*/
	if(fp1==NULL)
	{
		printf("【没有基本信息!】\n");
		return ;
	}
	while(feof(fp1)==0)
	{
		p=(Node *)malloc(sizeof(Node));
		h=(Courselink *)malloc(sizeof(Courselink));
		if(fread(p,sizeof(Node),1,fp1)==1 && fread(h,sizeof(Courselink),1,fp1)==1)/*从指定磁盘文件读取记录*/
		{
			p->next=NULL;/*构造链表*/
			r->next=p;
			r=p;
			h->next=NULL;
			q->next=h;
			q=h;
			count1++;
		}
	}
	fclose(fp1);
}
//保存学生及其选修课程信息
void save(Node *l,Courselink *k)
{
	FILE *fp;
	Node *p;
	Courselink *h;
	int count=0,flag=1;
	fp=fopen("基本信息.txt","wb+");
	if(fp==NULL)
	{
		printf("【无法打开基本信息文件!】\n");
		return;
	}
	p=l->next;
	h=k->next;
	while(p && h)
	{
		if(fwrite(p,sizeof(Node),1,fp)==1 && fwrite(h,sizeof(Courselink),1,fp)==1)
		{
			p=p->next;
			h=h->next;
			count++;
		}
		else
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		printf("已保存%d个学生的基本信息!\n",count-count1);
	}
	fclose(fp);
}
//主函数
main()
{
	int ch,i;
	char pr[20],word;
	Node *L;
	Courselink *k;
	L=(Node*)malloc(sizeof(Node));
	L->next=NULL;
	k=(Courselink*)malloc(sizeof(Courselink));
	k->next=NULL;
	while(1)
	{
		printf("\n\n");
		printf("\t\t|————————————————————|\n");
		printf("\t\t|                                        |\n");
		printf("\t\t|   【 欢迎使用学生成绩信息管理系统 】   |\n");
		printf("\t\t|                                        |\n");
		printf("\t\t|         制作人：林溢漫 郭晓莹          |\n");
		printf("\t\t|                                        |\n");
		printf("\t\t|————————————————————|\n");
		printf("\t\t 请输入系统密码：");
		i=0;
		while((word=getch())!='\r') 
		{
            if(word=='\b' && i>0) 
			{
                printf("\b \b");                 /*'\b'后面跟了一个空格' '来替换了最后一个字符*/
                --i;
            }
            else if(word!='\b') 
			{
                pr[i++]=word;
                printf("*");
            }
		}
        pr[i]='\0';
		if(strcmp(pr,"123456")==0)
		{
			printf("\n\t\t 【密码正确!】\n");
			Sleep(500);
			system("CLS");
			break;
		}
		else
		{
			printf("\n\t\t 【密码有误!】\n");
			printf("\n\t\t 还有2秒可以重新输入密码...");
			Sleep(1000);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b1秒可以重新输入密码...");
			Sleep(1000);
			system("CLS");
		}
	}
	read(L,k);
	while(1)
	{
		menu();
		do
		{
			printf("\n请输入您的选择(0~10):");
			scanf("%d",&ch);
			if(ch<0 ||ch>10)
				printf("【您的输入有误!请重新输入!】\n");
		}while(ch<0 ||ch>10);
		switch(ch)
		{
		case 1:
			info(L,k);
            break;
		case 2:
			modify(L,k);
			break;
		case 3:
			insert(L,k);
			break;
		case 4:
			search(L,k);
			break;
		case 5:
			del(L,k);
			break;
		case 6:
			showall(L,k);
			break;
		case 7:
			orderaver(L,k);
			break;
		case 8:
			showbad(L,k);
			break;
		case 9:
			save(L,k);
			break;
		case 10:
			tips();
			break;
		case 0:
			printf("\n感谢使用学生成绩信息管理系统!\n");
			return 0;
		}
		printf("Press any key to continue...\n");
		getch();
	}
	return 0;
}
