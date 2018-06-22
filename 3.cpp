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
#include<iostream>  
using namespace std; 
#include<fstream>   
#include<conio.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int amount=0;
int ab=0,cd=0,ef=0; ofstream *file[50];
struct Xinxi
{
 	string ID[10];         //工号
 	string name[10];   //姓名
 	float postWages;        //岗位工资
 	float paySalary;       //薪级工资
 	float jobAllowance;          // 职务津贴 
    float performancePay;         //绩效工资
 	float shouldPay;         //应发工资
 	float tax;       //个人所得税
	float realWages;      //实发工资
    struct Xinxi *next;
};  
class worker
{
public:
string name;
string ID;
Xinxi sc1;
class worker *next; };
void read(worker *head); 
void find(worker *head); 
void modify(worker *head); 
void add(worker *head); 
void del(worker *head); 
void write(worker *head); 
void list(worker *head);
void menu();
int main()
{
system("color ff");
int x;
//bool flag2=0;
/*do
{
do
{
cin>>x;
if(x>=0&&x<=10)
flag2=1;
else
{
cout<<"~~~~~~~~~~~~指令错误!!!~~~~~~~~~~"<<endl;
cout<<"请选择相应数字进行操作"<<endl;
}
}
while(flag2==0)*/
worker *head=new worker;
head->next=NULL;
while(1)
{
display();
cin>>x;
if(x==1)
{
cout<<"***************现在进行职工数据的查询*****************\n";
find(head);
cout<<"查询的职工信息为:\n";
list(head);
display(); //break;
}
else if(x==2)
{
cout<<"***************现在进行职工数据的修改******************\n";
modify(head);
display();
}
else if(x==3)
{
cout<<"****************现在进行指定的职工信息的添加******************\n";
add(head);
list(head);
display();
break;//添加
}
else if(x==4)
{
cout<<"***************现在进行指定的职工信息的删除*****************\n";
del(head);
list(head);
display();
//break; //删除
}
else if(x==5)
{
cout<<"***************现在进行指定的职工信息的浏览*****************\n";
list(head);
display();
//break; //浏览
}
else if(x==6)
{
cout<<"**********************现在进行指定的职工信息的保存************\n";
write(head);
display();
// break;保存
}
else if(x=7)
{
cout<<" ╔═══════════════════════════╗\n";
cout<<" ║您已退出职工管理系统, 谢谢您的使用! ║\n";
cout<<" ╚═══════════════════════════╝\n";
cout<<endl;
exit(0);
break;
}
}
return 0;
}
void display()
{
cout<<" ╔═══════════════════════════╗"<<endl;
cout<<" ║☆职工管理系统☆║"<<endl;
cout<<" ║═══════════════════════════║"<<endl;
cout<<" ║║"<<endl;
cout<<" ║(1)职工数据的查询║"<<endl;
cout<<" ║(2)职工数据的修改║"<<endl;
cout<<" ║(3)职工信息的添加║"<<endl;
cout<<" ║(4)职工信息的删除║"<<endl;
cout<<" ║(5)职工信息的浏览║"<<endl;
cout<<" ║(6)职工信息的保存║"<<endl;
cout<<" ║(7)退出程序║"<<endl;
cout<<" ║║"<<endl;
cout<<" ║═══════════════════════════║"<<endl;
cout<<" ║注:请输入相应括号里的阿拉伯数字来执行相关操作!║"<<endl;
cout<<" ║要保存数据请先建立好指定文件:║"<<endl;
cout<<" ║(D:\\职工管理系统\gx.dat\) ║"<<endl;
cout<<" ╟------------------------------------------------------╢"<<endl;
cout<<" ║===================谢谢您的使用=======================║"<<endl;
cout<<" ╚═══════════════════════════╝"<<endl;
cout<<" →请选择相应的数字进行操作: "<<endl;
}
/*********************************************************
Function:read //函数名称
Description：函数描述。主函数执行时要调用和必须调用的第一个函数。 函数功能。从数据文件中读取职工工资数据、初始化职工工资结构体数组并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他函数使用。
Calls:gx.dat
Called by；gzzg[n]
*********************************************************/

void read()
{
	int n;
	ofstream outfile("D:\\职工管理系统\\gx.dat",ios::out);
    if(! outfile)
    {
      cout<<"!!!!!!!!打开文件不存在!!!!!!!\n";
      exit(0);
    }
    cout<<"职工ID号"<<"职工姓名"<<"岗位工资"<<"薪级工资"<<"职务津贴"<<"绩效工资"<<"应发工资"<<"个人所得税"<<"实发工资"<<endl;
     for(n=0;n++;);
		 
    outfile.close();
}



/*********************************************************

Function:write 
Description:  函数描述。在执行保存功能时被主函数调用。 函数功能。将zggz结构体数组中的记录保存到gz.dat数据文件中。
Calls: gx.dat
*********************************************************/
void write(worker *head)  /*保存文件函数*/
{
 	char a;
worker *work=head->next;
cout<<"现在保存输入职工数据,是否继续操作?(y/n)";
cin>>a;
ofstream outfile("gx.dat",ios::out);
if(! outfile)
{
cout<<"!!!!!!!!打开文件错误!!!!!!!\n";
cout<<"!!!要保存数据请先建立好指定文件:gx.dat\\!!!\n";
exit(0);
}
while(a!='n')
{
while(work!=NULL)
{
outfile<<"****************第"<<amount<<"个职工的数据:***************\n";
outfile<<"职工ID号"<<"职工姓名"<<"岗位工资"<<"薪级工资"<<"职务津贴"<<"绩效工资"<<"应发工资"<<"个人所得税"<<"实发工资"<<endl; 
outfile<<" 职工信息: \n" <<" | "<<setw(4)<<(*work).ID<<" | "<<setw(4)<<(*work).name<<"| "<<setw(4)<<(*work).sc1.postWages<< " | "<<setw(4)<<(*work).sc1.paySalary<<" | "<<setw(4)<<(*work).sc1.jobAllowance <<"|"<<setw(4)<<(*work).sc1.performancePay <<"|" <<setw(4)<<(*work).sc1.shouldPay <<"|"<<setw(4)<<(*work).sc1.tax<<"|"<<setw(4)<<(*work).sc1.realWages<<"|"<< endl;
amount++;
work=work->next;
}
break;
}
cout<<"......成功将学生数据保存到<职工信息.txt>中! ";
outfile.close();
}
/*********************************************************
Function:modify
Description: 函数描述。在执行修改功能时被主函数调用  函数功能。指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。
Calls: gx.dat
*********************************************************/
void modify(worker *head)//修改函数
{
string name;
char c;
do
{
bool flag2=0;
worker *work=head->next;
Xinxi sc1;
cout<<"请输入你要修改的职工的姓名:";
cin>>name;
do{
if(name==(*work).name)
{
flag2=1;
cout<<"请输入新的岗位工资:";
cin>>sc1.postWages;
cout<<"请输入新的薪级工资:";
cin>>sc1.paySalary;
cout<<"请输入新的职务津贴:";
cin>>sc1.jobAllowance;
cout<<"请输入新的绩效工资:";
cin>>sc1.performancePay;
(*work).sc1.postWages=sc1.postWages;
(*work).sc1.paySalary=sc1.paySalary;
(*work).sc1.jobAllowance=sc1.jobAllowance;
(*work).sc1.performancePay=sc1.performancePay;
cout<<" | name | ID |基本工资|职务工资|岗位津贴|医疗保险|公积金|总工资|平均工资|"<<endl;
cout<<" | "<<setw(4)<<(*work).name;
cout<<" | "<<setw(4)<<(*work).ID;
cout<<" | "<<setw(4)<<(*work).sc1.postWages;
cout<<" | "<<setw(4)<<(*work).sc1.paySalary;
cout<<" | "<<setw(4)<<(*work).sc1.jobAllowance;
cout<<" | "<<setw(4)<<(*work).sc1.performancePay;
cout<<" | "<<endl;
cout<<"数据修改成功......";
break;
}
work=work->next;
}while(work!=NULL);
if(flag2==0)
{
cout<<"!!!!对不起!您要修改的职工不存在!请检查重新输入!!!!!"<<endl;
}
cout<<"想继续修改吗?(y/n)";
cin>>c;
if(c!='y'&&c!='n')
{
cout<<"!!!!!!!!!!!!!!!指令错误!请重新输入<y/n>!!!!!!!!!!!!!";
cin>>c;
}
}while(c=='y');
}

