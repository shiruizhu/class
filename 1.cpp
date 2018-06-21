/*********************************************************
Copyright (C), 2018-2019. 
File name: 工资管理系统
Author: Version: Date:殷伟伟 0.1 2018/6/20 // 作者、版本及完成日期
Function List: read()
（1）函数描述。主函数执行时要调用和必须调用的第一个函数。
（2）函数功能。从数据文件中读取职工工资数据、初始化职工工资结构体数组并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他函数使用。
write()
（1）函数描述。在执行保存功能时被主函数调用。
（2）函数功能。将zggz结构体数组中的记录保存到gz.dat数据文件中。
find()
（1）函数描述。在执行查询功能时被主函数调用。
（2）函数功能。根据工号查询相应职工的工资记录。
list()
（1）函数描述。在执行浏览功能时被主函数调用。
（2）函数功能。显示所用职工的记录。
modify()
（1）函数描述。在执行修改功能时被主函数调用
（2）函数功能。指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。
del()
（1）函数描述。在执行删除功能时被主函数调用
（2）函数功能。删除指定工号职工的记录
add()
（1）函数描述。在执行添加功能时被主函数调用
（2）函数功能。添加工资记录到结构体数组zggz末尾
grsds()
（1）函数描述。在计算个人所得税时被调用
（2）函数功能。计算个人所得税，按照个人所得税税率表来计算
main()
（1）函数描述。主函数是程序执行的开始，在主函数中可调用其他函数来实现用户要求的功能。
（2）函数功能。主函数实现了系统的主界面，用户可在此界面输入查询、浏览、删除等命令。
  // 主要函数列表，每条记录应包括函数名及功能简要说明
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 50
struct gongzi
{
 	char num[10];         //工号
 	char name[10];   //姓名
 	float wage1;        //岗位工资
 	float wage2;       //薪级工资
 	float allowance;          // 职务津贴 
    float insurance;         //绩效保险
 	float wage3;         //应发工资
 	float tax;       //个人所得税
	float wage4;      //实发工资
}gz[NUM];      
void menu();
void read();
void write();
void find();
void list();
void modify(); 
void del();
void add();
void grsds();

void menu() //菜单界面
{  
   int n,w1;
   do
   { system("cls");  
     printf("***菜单***\n\n");
     printf("                           1  查询                           \n");
     printf("                           2  修改                           \n");
     printf("                           3  添加                           \n");
     printf("                           4  删除                           \n");
     printf("                           5  保存                           \n");
     printf("                           6  浏览                           \n");
     printf("                           7  退出                           \n");
  printf("       输入您的选择(1-7):[ ]\b\b");
  scanf("%d",&n);
  if(n<1||n>7)                                    //对选择的数字作判断
	{
    w1=1;
    printf("your choice is not between 1 and 7,Please input again:");
    getchar();
	}
         else    w1=0;
   } 
    while(w1==1);
  switch(n)
  { case 1:find();    break;   
    case 2:modify();   break;  
    case 3:add();   break;    
    case 4:del();   break;    
    case 5:write();    break;    
    case 6:list();    break;     
    case 7:printf("\n×××××××谢谢，欢迎下次光临！×××××××\n\n");
    default:exit(0);  //退出系统,exit(0)函数功能是退出程序。
  }
}
/*********************************************************
Function:read //函数名称
Description：函数描述。主函数执行时要调用和必须调用的第一个函数。 函数功能。从数据文件中读取职工工资数据、初始化职工工资结构体数组并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他函数使用。
Calls:gz.dat
Called by；gzzg[n]
*********************************************************/

void read()
	{
     FILE *fp;
     int n,num;
     if((fp=fopen("gz.dat","rb"))==NULL)
     {
         printf("不能打开gz文件\n");
         exit(1);
     }
	 printf("请输入工资数:");
     scanf("%d",&num);
     printf("工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资\n");
     for(
		 n=0;fread(&gz[n],sizeof(struct gongzi),1,fp)!=0;
		 n++
	     )
     if(gz[n].wage4>=num);
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f   %.1f   %.1f\n",n+1,gz[n].num,gz[n].name,gz[n].wage1,
             gz[n].wage2,gz[n].allowance,gz[n].insurance,gz[n].wage3,gz[n].tax,gz[n].wage4);
     fclose(fp);
}

/*********************************************************
Function:write 
Description:  函数描述。在执行保存功能时被主函数调用。 函数功能。将zggz结构体数组中的记录保存到gz.dat数据文件中。
Calls: gz.dat
*********************************************************/
void write(int m)  /*保存文件函数*/
{
 	int i;
 	FILE*fp;   //声明fp是指针，用来指向FILE类型的对象
 	if ((fp=fopen("gz.dat","wb"))==NULL) //打开职工列表文件为空
 	{
  	printf ("打开失败\n");
     	exit(0);
 	}
 
for (i=0;i<m;i++) /*将内存中职工的信息输出到磁盘文件中去*/
   	if (fwrite(&gz[i],sizeof(struct gongzi),1,fp)!=1)//写入数据块   &gz[i]：是要输出数据的地址  sizeof(struct clerk)：获取一个单体的长度  1：数据项的个数  fp：目标文件指针
   	printf("文件读写错误\n");
   	fclose(fp);// 缓冲区内最后剩余的数据输出到磁盘文件中，并释放文件指针和有关的缓冲区
} 
