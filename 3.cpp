/*********************************************************
Copyright (C), 2018-2019. 
File name: ���ʹ���ϵͳ
Author: Version: Date:��ΰΰ 0.1 2018/6/20 // ���ߡ��汾���������
Function List: read()
��1������������������ִ��ʱҪ���úͱ�����õĵ�һ��������
��2���������ܡ��������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�
write()
��1��������������ִ�б��湦��ʱ�����������á�
��2���������ܡ���zggz�ṹ�������еļ�¼���浽gz.dat�����ļ��С�
find()
��1��������������ִ�в�ѯ����ʱ�����������á�
��2���������ܡ����ݹ��Ų�ѯ��Ӧְ���Ĺ��ʼ�¼��
list()
��1��������������ִ���������ʱ�����������á�
��2���������ܡ���ʾ����ְ���ļ�¼��
modify()
��1��������������ִ���޸Ĺ���ʱ������������
��2���������ܡ�ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��
del()
��1��������������ִ��ɾ������ʱ������������
��2���������ܡ�ɾ��ָ������ְ���ļ�¼
add()
��1��������������ִ����ӹ���ʱ������������
��2���������ܡ���ӹ��ʼ�¼���ṹ������zggzĩβ
grsds()
��1�������������ڼ����������˰ʱ������
��2���������ܡ������������˰�����ո�������˰˰�ʱ�������
main()
��1�������������������ǳ���ִ�еĿ�ʼ�����������пɵ�������������ʵ���û�Ҫ��Ĺ��ܡ�
��2���������ܡ�������ʵ����ϵͳ�������棬�û����ڴ˽��������ѯ�������ɾ�������
  // ��Ҫ�����б�ÿ����¼Ӧ���������������ܼ�Ҫ˵��
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
 	string ID[10];         //����
 	string name[10];   //����
 	float postWages;        //��λ����
 	float paySalary;       //н������
 	float jobAllowance;          // ְ����� 
    float performancePay;         //��Ч����
 	float shouldPay;         //Ӧ������
 	float tax;       //��������˰
	float realWages;      //ʵ������
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
cout<<"~~~~~~~~~~~~ָ�����!!!~~~~~~~~~~"<<endl;
cout<<"��ѡ����Ӧ���ֽ��в���"<<endl;
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
cout<<"***************���ڽ���ְ�����ݵĲ�ѯ*****************\n";
find(head);
cout<<"��ѯ��ְ����ϢΪ:\n";
list(head);
display(); //break;
}
else if(x==2)
{
cout<<"***************���ڽ���ְ�����ݵ��޸�******************\n";
modify(head);
display();
}
else if(x==3)
{
cout<<"****************���ڽ���ָ����ְ����Ϣ�����******************\n";
add(head);
list(head);
display();
break;//���
}
else if(x==4)
{
cout<<"***************���ڽ���ָ����ְ����Ϣ��ɾ��*****************\n";
del(head);
list(head);
display();
//break; //ɾ��
}
else if(x==5)
{
cout<<"***************���ڽ���ָ����ְ����Ϣ�����*****************\n";
list(head);
display();
//break; //���
}
else if(x==6)
{
cout<<"**********************���ڽ���ָ����ְ����Ϣ�ı���************\n";
write(head);
display();
// break;����
}
else if(x=7)
{
cout<<" �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n";
cout<<" �U�����˳�ְ������ϵͳ, лл����ʹ��! �U\n";
cout<<" �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n";
cout<<endl;
exit(0);
break;
}
}
return 0;
}
void display()
{
cout<<" �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�["<<endl;
cout<<" �U��ְ������ϵͳ��U"<<endl;
cout<<" �U�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�U"<<endl;
cout<<" �U�U"<<endl;
cout<<" �U(1)ְ�����ݵĲ�ѯ�U"<<endl;
cout<<" �U(2)ְ�����ݵ��޸ĨU"<<endl;
cout<<" �U(3)ְ����Ϣ����ӨU"<<endl;
cout<<" �U(4)ְ����Ϣ��ɾ���U"<<endl;
cout<<" �U(5)ְ����Ϣ������U"<<endl;
cout<<" �U(6)ְ����Ϣ�ı���U"<<endl;
cout<<" �U(7)�˳�����U"<<endl;
cout<<" �U�U"<<endl;
cout<<" �U�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�U"<<endl;
cout<<" �Uע:��������Ӧ������İ�����������ִ����ز���!�U"<<endl;
cout<<" �UҪ�����������Ƚ�����ָ���ļ�:�U"<<endl;
cout<<" �U(D:\\ְ������ϵͳ\gx.dat\) �U"<<endl;
cout<<" �c------------------------------------------------------�f"<<endl;
cout<<" �U===================лл����ʹ��=======================�U"<<endl;
cout<<" �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a"<<endl;
cout<<" ����ѡ����Ӧ�����ֽ��в���: "<<endl;
}
/*********************************************************
Function:read //��������
Description������������������ִ��ʱҪ���úͱ�����õĵ�һ�������� �������ܡ��������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�
Calls:gx.dat
Called by��gzzg[n]
*********************************************************/

void read()
{
	int n;
	ofstream outfile("D:\\ְ������ϵͳ\\gx.dat",ios::out);
    if(! outfile)
    {
      cout<<"!!!!!!!!���ļ�������!!!!!!!\n";
      exit(0);
    }
    cout<<"ְ��ID��"<<"ְ������"<<"��λ����"<<"н������"<<"ְ�����"<<"��Ч����"<<"Ӧ������"<<"��������˰"<<"ʵ������"<<endl;
     for(n=0;n++;);
		 
    outfile.close();
}



/*********************************************************

Function:write 
Description:  ������������ִ�б��湦��ʱ�����������á� �������ܡ���zggz�ṹ�������еļ�¼���浽gz.dat�����ļ��С�
Calls: gx.dat
*********************************************************/
void write(worker *head)  /*�����ļ�����*/
{
 	char a;
worker *work=head->next;
cout<<"���ڱ�������ְ������,�Ƿ��������?(y/n)";
cin>>a;
ofstream outfile("gx.dat",ios::out);
if(! outfile)
{
cout<<"!!!!!!!!���ļ�����!!!!!!!\n";
cout<<"!!!Ҫ�����������Ƚ�����ָ���ļ�:gx.dat\\!!!\n";
exit(0);
}
while(a!='n')
{
while(work!=NULL)
{
outfile<<"****************��"<<amount<<"��ְ��������:***************\n";
outfile<<"ְ��ID��"<<"ְ������"<<"��λ����"<<"н������"<<"ְ�����"<<"��Ч����"<<"Ӧ������"<<"��������˰"<<"ʵ������"<<endl; 
outfile<<" ְ����Ϣ: \n" <<" | "<<setw(4)<<(*work).ID<<" | "<<setw(4)<<(*work).name<<"| "<<setw(4)<<(*work).sc1.postWages<< " | "<<setw(4)<<(*work).sc1.paySalary<<" | "<<setw(4)<<(*work).sc1.jobAllowance <<"|"<<setw(4)<<(*work).sc1.performancePay <<"|" <<setw(4)<<(*work).sc1.shouldPay <<"|"<<setw(4)<<(*work).sc1.tax<<"|"<<setw(4)<<(*work).sc1.realWages<<"|"<< endl;
amount++;
work=work->next;
}
break;
}
cout<<"......�ɹ���ѧ�����ݱ��浽<ְ����Ϣ.txt>��! ";
outfile.close();
}
/*********************************************************
Function:modify
Description: ������������ִ���޸Ĺ���ʱ������������  �������ܡ�ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��
Calls: gx.dat
*********************************************************/
void modify(worker *head)//�޸ĺ���
{
string name;
char c;
do
{
bool flag2=0;
worker *work=head->next;
Xinxi sc1;
cout<<"��������Ҫ�޸ĵ�ְ��������:";
cin>>name;
do{
if(name==(*work).name)
{
flag2=1;
cout<<"�������µĸ�λ����:";
cin>>sc1.postWages;
cout<<"�������µ�н������:";
cin>>sc1.paySalary;
cout<<"�������µ�ְ�����:";
cin>>sc1.jobAllowance;
cout<<"�������µļ�Ч����:";
cin>>sc1.performancePay;
(*work).sc1.postWages=sc1.postWages;
(*work).sc1.paySalary=sc1.paySalary;
(*work).sc1.jobAllowance=sc1.jobAllowance;
(*work).sc1.performancePay=sc1.performancePay;
cout<<" | name | ID |��������|ְ����|��λ����|ҽ�Ʊ���|������|�ܹ���|ƽ������|"<<endl;
cout<<" | "<<setw(4)<<(*work).name;
cout<<" | "<<setw(4)<<(*work).ID;
cout<<" | "<<setw(4)<<(*work).sc1.postWages;
cout<<" | "<<setw(4)<<(*work).sc1.paySalary;
cout<<" | "<<setw(4)<<(*work).sc1.jobAllowance;
cout<<" | "<<setw(4)<<(*work).sc1.performancePay;
cout<<" | "<<endl;
cout<<"�����޸ĳɹ�......";
break;
}
work=work->next;
}while(work!=NULL);
if(flag2==0)
{
cout<<"!!!!�Բ���!��Ҫ�޸ĵ�ְ��������!������������!!!!!"<<endl;
}
cout<<"������޸���?(y/n)";
cin>>c;
if(c!='y'&&c!='n')
{
cout<<"!!!!!!!!!!!!!!!ָ�����!����������<y/n>!!!!!!!!!!!!!";
cin>>c;
}
}while(c=='y');
}

