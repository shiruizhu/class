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
#include<conio.h> 
#define NUM 50
struct gongzi
{
    char ID[10];         //工号
 	char name[10];   //姓名
 	float postWages;        //岗位工资
 	float paySalary;       //薪级工资
 	float jobAllowance;          // 职务津贴 
    float performancePay;         //绩效工资
 	float shouldPay;         //应发工资
 	float tax;       //个人所得税
	float realWages;      //实发工资
}gz[NUM],newgz;      
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
  
   { system("cls");  
     printf("***菜单***\n\n");
     printf("                           1  查询                           \n");
     printf("                           2  修改                           \n");
     printf("                           3  添加                           \n");
     printf("                           4  删除                           \n");
     printf("                           5  保存                           \n");
     printf("                           6  浏览                           \n");
     printf("                           7  退出                           \n");
}
/*********************************************************
Function:read //函数名称
Description：函数描述。主函数执行时要调用和必须调用的第一个函数。 函数功能。从数据文件中读取职工工资数据、初始化职工工资结构体数组并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他函数使用。
Calls:gx.dat
Called by；gzzg[n]
*********************************************************/

void read()//读取函数
{
     FILE *fp;
     int n,num;
     if((fp=fopen("gx.dat","rb"))==NULL)
     {
         printf("不能打开gx文件\n");
         exit(1);
     }
	 printf("请输入工资数:");
     scanf("%d",&num);
     printf("工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资\n");
     for(
		 n=0;fread(&gz[n],sizeof(struct gongzi),1,fp)!=0;
		 n++
	     )
     if(gz[n],realWages>=num);
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f   %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
     fclose(fp);
}

/*********************************************************
Function:write 
Description:  函数描述。在执行保存功能时被主函数调用。 函数功能。将zggz结构体数组中的记录保存到gz.dat数据文件中。
Calls: gx.dat
*********************************************************/
void write(int m)  /*保存文件函数*/
{
 	int i;
 	FILE*fp;   //声明fp是指针，用来指向FILE类型的对象
 	if ((fp=fopen("gx.dat","wb"))==NULL) //打开职工列表文件为空
 	{
  	printf ("打开失败\n");
     	exit(0);
 	}
 
for (i=0;i<m;i++) /*将内存中职工的信息输出到磁盘文件中去*/
   	if (fwrite(&gz[i],sizeof(struct gongzi),1,fp)!=1)//写入数据块   &gz[i]：是要输出数据的地址  sizeof(struct clerk)：获取一个单体的长度  1：数据项的个数  fp：目标文件指针
   	printf("文件读写错误\n");
   	fclose(fp);// 缓冲区内最后剩余的数据输出到磁盘文件中，并释放文件指针和有关的缓冲区
} 



/*********************************************************
Function:modify
Description: 函数描述。在执行修改功能时被主函数调用  函数功能。指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。
Calls: gx.dat
*********************************************************/
void modify() /*修改函数*/ 
{
     FILE *fp;
	 int n,i;
     char num[5];
    printf("要修改的职工号:");
     scanf("%s",num);
     for(i=0;fread(&gz[i],sizeof(struct emploee),1,fp);i++)
    if(!strcmp(gz[i].ID,num))break;
     if(feof(fp))
     {
          printf("\t没有%s职工号的职工\n",num);
          exit(2);
     }
     printf("工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资\n");
     printf("%6d%6s%9s%4s%5d%   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
    printf("输入格式:工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资 <Enter>\n");
    printf("第%d个记录:",n+1);
    scanf("%s%s%s%d%f%f%f%f%f",newgz.ID,newgz.name,
               &newgz.postWages,&newgz.paySalary,&newgz.jobAllowance,&newgz.performancePay,&newgz.shouldPay,&newgz.tax,&newgz.realWages);//获取新的职工记录
             newgz.shouldPay=newgz.postWages+newgz.paySalary+newgz.jobAllowance+newgz.performancePay
             newgz.realWages=newgz.shouldPay-newgz.shouldPay
    fseek(fp,-(long)sizeof(struct gongzi),SEEK_CUR);  //文件指针指向该修改的记录开头
     fwrite(&newgz,sizeof(struct gongzi),1,fp);  //用newgz覆盖当前记录
     printf(" 修改后:\n");
    fseek(fp,0,SEEK_SET);        //显示修改后的文件数据
     printf("工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资\n");
     for(n=0;fread(&gz[n],sizeof(struct gongzi),1,fp)!=0;n++)
         printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f  %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
    fclose(fp);
}
/*********************************************************
Function:find
Description: 函数描述。在执行浏览功能时被主函数调用率。 函数功能。显示所用职工的记录。
Calls: gx.dat
*********************************************************/
void find()//查询函数
{
	{
     FILE *fp;
     int n;
	 char num[5];
     if((fp=fopen("gx.dat","rb"))==NULL)
     {
          printf("不能打开gx文件\n");
          exit(1);
     }
     printf("要查询的职工号:");
     scanf("%s",num);
     for(n=0;fread(&gz[n],sizeof(struct gongzi),1,fp);n++)
         if(!strcmp(gz[n].ID,num)) break;
    if(feof(fp))
    {
        printf("\t查无此人\n");
        exit(2);
    }
     printf("工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资\n");
     printf("%6d%6s%9s%4s%5d  %.1f  %.1f  %.1f  %.1f   %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
       fclose(fp);
}
/*********************************************************
Function:list
Description: 函数描述。在执行浏览功能时被主函数调用。函数功能。显示所用职工的记录。
Calls: gx.dat
*********************************************************/
void list()//浏览函数
{

	int n; 

    FILE *fp;
     if((fp=fopen("gx.dat","r"))==NULL)
     {     
         printf("不能打开emp文件\n");
         exit(0);
     }
     printf("工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资\n");
     for(n=0;fread(&emp[i],sizeof(struct gongzi),1,fp)!=0;n++)
     {
          printf("%6d%6s%9s%4s%5d  %.1f  %.1f     %.1f    %.1f    %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
    }
    fclose(fp);
}

} 
/*********************************************************
Function:del
Description: 函数描述。在执行删除功能时被主函数调用.函数功能。删除指定工号职工的记录
Calls: gx.dat
*********************************************************/
void del()//删除函数
{
	
	int n=load(); 

    int i,j,m,t,button; 

    char ID[10]; 

    printf("\n 原来的职工信息:\n"); 

     list(); //显示删除前的员工信息 

     printf("\n"); 

    printf("按工号删除:\n"); 

    scanf("%s",ID); 

  for(button=1,i=0;button&&i<n;i++)//主函数中确定button==1时各函数才可以被调用 

  { 

   if(strcmp(gz[i].ID,ID)==0)//按员工姓名查找到某员工 并调出其资料 

   { 

    printf("\n此人原始记录为:\n");//显示选定员工的信息 

    printf("工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资 \n"); 

    printf("\n  %-6d%-6s  %-8d  %-8d  %-8d  %-8d  %-8d %-8d  ",gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);   

    printf("\n确定删除 请按1,不删除请按0\n");   

    scanf("%d",&n); 

             if(m==1) 

    { 

      for(j=i;j<n-1;j++)//从第i项开始 将后一项的各成员的值赋给前一项各对应的成员 完成对第i项的删除 

      { 

                strcpy(gz[j].ID,gz[j+1].ID); 

                 gz[j].name=gz[j+1].name; 

                 gz[j].postWages=gz[j+1].postWages; 

                 gz[j].paySalary=gz[j+1].paySalary; 

                 gz[j].jobAllowance=gz[j+1].jobAllowance; 

                gz[j].performancePay=gz[j+1].performancePay;   

                gz[j].shouldPay=gz[j+1].shouldPay; 

                gz[j].tax=gz[j+1].tax; 
				gz[j].realWages=gz[j+1].realWages;

      } 

     . button=0; 

    } 

   } 

  } 

  if(!button)//button==0表明删除已完成 

     n=n-1;//总员工数减少一人 

  else 

     printf("\n查无此人!\n"); 

     printf("\n 删除后的所有职工信息:\n"); 

     write(m);     //调用保存函数 

     list();  //调用浏览函数 

  

printf("\n继续删除请按1,不再删除请按0\n"); 

  scanf("%d",&t); 

  switch(t) 

  { 

     case 1:del();break; 

     case 0:break; 

     default :break; 

  } 

} 
/*********************************************************
Function:add
Description: 在执行添加功能时被主函数调用函数功能。添加工资记录到结构体数组zggz末尾
Calls: gx.dat
*********************************************************/
void add()/*添加函数*/ 

{
      FILE *fp;
      int n,i,j;
      if((fp=fopen("gx,dat","ab+"))==NULL)
      {
          printf("不能打开gx文件\n");
           exit(0);
      }
    printf("要追加的职工人数:");
      scanf("%d",&n);
      for(i=0;i<n;i++) 
      { 
          printf("输入格式:工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税、实发工资    <Enter>\n");
         printf("追加记录:\n");
         scanf("%s%s%s%d%f%f%f%f%f",gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
             newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;//获取一个新的职工记录
        fwrite(&newgz,sizeof(struct gongzi),1,fp);   //将该职工记录写入文件
      }
      fclose(fp);
}
/*********************************************************
Function:grads
Description: 函数描述。主函数是程序执行的开始，在主函数中可调用其他函数来实现用户要求的功能。函数功能。主函数实现了系统的主界面，用户可在此界面输入查询、浏览、删除等命令。
Calls: gx.dat
*********************************************************/
void grads()
{
float Tax;  //Tax指个人所交的税//
float shouldPay;    //shouldPay指个人的收入//
printf("请输入您的收入shouldPay:",shouldPay);
scanf("%d",&shouldPay);
if(shouldPay<2000)
printf("您不用上税");
else if(shouldPay>=2000&&shouldPay<2500)
{Tax=0.05*(S-2000);
printf("您需要上的税为：%d\n",Tax);
}
else if(shouldPay>=2500&&shouldPay<4000)
{Tax=0.1*(shouldPay-2000)-25;
printf("您需要上的税为：%d\n",Tax);
}
else if(shouldPay>=4000&&S<7000)
{Tax=0.15*(shouldPay-2000)-125;
printf("您需要上的税为：%d\n",Tax);
}
else if(shouldPay>=7000&&shouldPay<22000)
{Tax=0.2*(shouldPay-2000)-375;
printf("您需要上的税为：%d\n",Tax);
}
else if(shouldPay>=22000&&shouldPay<42000)
{Tax=0.25*(shouldPay-2000)-1375;
printf("您需要上的税为：%d\n",Tax);
}
else if(shouldPay>=42000&&shouldPay<62000)
{Tax=0.3*(shouldPay-2000)-3375;
printf("您需要上的税为：%d\n",Tax);
}
else if(shouldPay>=62000&&shouldPay<82000)
{Tax=0.35*(shouldPay-2000)-6375;
printf("您需要上的税为：%d\n",Tax);
}               
else if(shouldPay>=82000&&shouldPay<102000)
{Tax=0.4(shouldPay-2000)-10375;
printf("您需要上的税为：%d\n",Tax);
}   
else if(shouldPay>=102000)
{Tax=0.45*(shouldPay-2000)-15375;
printf("您需要上的税为：%d\n",Tax);
}           
}
/*********************************************************
Function:main
Description: 函数描述。主函数是程序执行的开始，在主函数中可调用其他函数来实现用户要求的功能。函数功能。主函数实现了系统的主界面，用户可在此界面输入查询、浏览、删除等命令。
Calls: gx.dat
*********************************************************/
void mian()
{
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