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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 50
struct gongzi
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

void menu() //�˵�����
{  
   int n,w1;
   do
   { system("cls");  
     printf("***�˵�***\n\n");
     printf("                           1  ��ѯ                           \n");
     printf("                           2  �޸�                           \n");
     printf("                           3  ���                           \n");
     printf("                           4  ɾ��                           \n");
     printf("                           5  ����                           \n");
     printf("                           6  ���                           \n");
     printf("                           7  �˳�                           \n");
  printf("       ��������ѡ��(1-7):[ ]\b\b");
  scanf("%d",&n);
  if(n<1||n>7)                                    //��ѡ����������ж�
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
    case 7:printf("\n��������������лл����ӭ�´ι��٣���������������\n\n");
    default:exit(0);  //�˳�ϵͳ,exit(0)�����������˳�����
  }
}
/*********************************************************
Function:read //��������
Description������������������ִ��ʱҪ���úͱ�����õĵ�һ�������� �������ܡ��������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�
Calls:gx.dat
Called by��gzzg[n]
*********************************************************/

void read()
	{
     FILE *fp;
     int n,num;
     if((fp=fopen("gx.dat","rb"))==NULL)
     {
         printf("���ܴ�gx�ļ�\n");
         exit(1);
     }
	 printf("�����빤����:");
     scanf("%d",&num);
     printf("���š���������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������\n");
     for(
		 n=0;fread(&gz[n],sizeof(struct gongzi),1,fp)!=0;
		 n++
	     )
     if(gz[n].wage4>=num);
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f   %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
     fclose(fp);
}

/*********************************************************
Function:write 
Description:  ������������ִ�б��湦��ʱ�����������á� �������ܡ���zggz�ṹ�������еļ�¼���浽gz.dat�����ļ��С�
Calls: gx.dat
*********************************************************/
void write(int m)  /*�����ļ�����*/
{
 	int i;
 	FILE*fp;   //����fp��ָ�룬����ָ��FILE���͵Ķ���
 	if ((fp=fopen("gx.dat","wb"))==NULL) //��ְ���б��ļ�Ϊ��
 	{
  	printf ("��ʧ��\n");
     	exit(0);
 	}
 
for (i=0;i<m;i++) /*���ڴ���ְ������Ϣ����������ļ���ȥ*/
   	if (fwrite(&gz[i],sizeof(struct gongzi),1,fp)!=1)//д�����ݿ�   &gz[i]����Ҫ������ݵĵ�ַ  sizeof(struct clerk)����ȡһ������ĳ���  1��������ĸ���  fp��Ŀ���ļ�ָ��
   	printf("�ļ���д����\n");
   	fclose(fp);// �����������ʣ�����������������ļ��У����ͷ��ļ�ָ����йصĻ�����
} 



/*********************************************************
Function:modify
Description: ������������ִ���޸Ĺ���ʱ������������  �������ܡ�ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��
Calls: gx.dat
*********************************************************/
void modify() /*�޸ĺ���*/ 
{
      FILE *fp;
	 int n,i;
     char num[5];
    printf("Ҫ�޸ĵ�ְ����:");
     scanf("%s",num);
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
    if(!strcmp(emp[i].no,num))break;
     if(feof(fp))
     {
          printf("\tû��%sְ���ŵ�ְ��\n",num);
          exit(2);
     }
     printf("���š���������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������\n");
     printf("%6d%6s%9s%4s%5d%   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
    printf("�����ʽ:���š���������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������ <Enter>\n");
    printf("��%d����¼:",n+1);
    scanf("%s%s%s%d%f%f%f%f%f",newgz.ID,newgz.name,&newgz.age,
               &newgz.postWages,&newgz.paySalary,&newgz.jobAllowance,&newgz.performancePay,&newgz.shouldPay,&newgz.tax,&newgz.realWages);//��ȡ�µ�ְ����¼
             newgz.wage3=newzgz.wage1+newgz.wage2+newgz.funds-newgz.WATERfee-newgz.TAXfee;
    fseek(fp,-(long)sizeof(struct gongzi),SEEK_CUR);  //�ļ�ָ��ָ����޸ĵļ�¼��ͷ
     fwrite(&newemp,sizeof(struct gongzi),1,fp);  //��newgz���ǵ�ǰ��¼
     printf(" �޸ĺ�:\n");
    fseek(fp,0,SEEK_SET);        //��ʾ�޸ĺ���ļ�����
     printf("���š���������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������\n");
     for(i=0;fread(&gz[n],sizeof(struct gongzi),1,fp)!=0;n++)
         printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f  %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
    fclose(fp);
}
/*********************************************************
Function:find
Description: ������������ִ���������ʱ�������������ʡ� �������ܡ���ʾ����ְ���ļ�¼��
Calls: gx.dat
*********************************************************/
void find()
{
	{
     FILE *fp;
     int n; 
     
     if((fp=fopen("gx.dat","rb"))==NULL)
     {
          printf("���ܴ�gx�ļ�\n");
          exit(1);
     }
     printf("Ҫ��ѯ��ְ����:");
     scanf("%s",num);
     for(i=0;fread(&gz[n],sizeof(struct gongzi),1,fp);n++)
         if(!strcmp(gz[n].no,num)) break;
    if(feof(fp))
    {
        printf("\t���޴���\n");
        exit(2);
    }
     printf("���š���������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������\n");
     printf("%6d%6s%9s%4s%5d  %.1f  %.1f  %.1f  %.1f   %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
       fclose(fp);
}