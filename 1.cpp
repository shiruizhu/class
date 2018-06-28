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
#include<conio.h> 
#define NUM 50
struct gongzi
{
    char ID[10];         //����
 	char name[10];   //����
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
  
   { system("cls");  
     printf("***�˵�***\n\n");
     printf("                           1  ��ѯ                           \n");
     printf("                           2  �޸�                           \n");
     printf("                           3  ���                           \n");
     printf("                           4  ɾ��                           \n");
     printf("                           5  ����                           \n");
     printf("                           6  ���                           \n");
     printf("                           7  �˳�                           \n");
}
/*********************************************************
Function:read //��������
Description������������������ִ��ʱҪ���úͱ�����õĵ�һ�������� �������ܡ��������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�
Calls:gx.dat
Called by��gzzg[n]
*********************************************************/

void read()//��ȡ����
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
     if(gz[n],realWages>=num);
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
     for(i=0;fread(&gz[i],sizeof(struct emploee),1,fp);i++)
    if(!strcmp(gz[i].ID,num))break;
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
    scanf("%s%s%s%d%f%f%f%f%f",newgz.ID,newgz.name,
               &newgz.postWages,&newgz.paySalary,&newgz.jobAllowance,&newgz.performancePay,&newgz.shouldPay,&newgz.tax,&newgz.realWages);//��ȡ�µ�ְ����¼
             newgz.shouldPay=newgz.postWages+newgz.paySalary+newgz.jobAllowance+newgz.performancePay
             newgz.realWages=newgz.shouldPay-newgz.shouldPay
    fseek(fp,-(long)sizeof(struct gongzi),SEEK_CUR);  //�ļ�ָ��ָ����޸ĵļ�¼��ͷ
     fwrite(&newgz,sizeof(struct gongzi),1,fp);  //��newgz���ǵ�ǰ��¼
     printf(" �޸ĺ�:\n");
    fseek(fp,0,SEEK_SET);        //��ʾ�޸ĺ���ļ�����
     printf("���š���������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������\n");
     for(n=0;fread(&gz[n],sizeof(struct gongzi),1,fp)!=0;n++)
         printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f  %.1f   %.1f\n",n+1,gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
    fclose(fp);
}
/*********************************************************
Function:find
Description: ������������ִ���������ʱ�������������ʡ� �������ܡ���ʾ����ְ���ļ�¼��
Calls: gx.dat
*********************************************************/
void find()//��ѯ����
{
	{
     FILE *fp;
     int n;
	 char num[5];
     if((fp=fopen("gx.dat","rb"))==NULL)
     {
          printf("���ܴ�gx�ļ�\n");
          exit(1);
     }
     printf("Ҫ��ѯ��ְ����:");
     scanf("%s",num);
     for(n=0;fread(&gz[n],sizeof(struct gongzi),1,fp);n++)
         if(!strcmp(gz[n].ID,num)) break;
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
/*********************************************************
Function:list
Description: ������������ִ���������ʱ�����������á��������ܡ���ʾ����ְ���ļ�¼��
Calls: gx.dat
*********************************************************/
void list()//�������
{

	int n; 

    FILE *fp;
     if((fp=fopen("gx.dat","r"))==NULL)
     {     
         printf("���ܴ�emp�ļ�\n");
         exit(0);
     }
     printf("���š���������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������\n");
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
Description: ������������ִ��ɾ������ʱ������������.�������ܡ�ɾ��ָ������ְ���ļ�¼
Calls: gx.dat
*********************************************************/
void del()//ɾ������
{
	
	int n=load(); 

    int i,j,m,t,button; 

    char ID[10]; 

    printf("\n ԭ����ְ����Ϣ:\n"); 

     list(); //��ʾɾ��ǰ��Ա����Ϣ 

     printf("\n"); 

    printf("������ɾ��:\n"); 

    scanf("%s",ID); 

  for(button=1,i=0;button&&i<n;i++)//��������ȷ��button==1ʱ�������ſ��Ա����� 

  { 

   if(strcmp(gz[i].ID,ID)==0)//��Ա���������ҵ�ĳԱ�� ������������ 

   { 

    printf("\n����ԭʼ��¼Ϊ:\n");//��ʾѡ��Ա������Ϣ 

    printf("���š���������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������ \n"); 

    printf("\n  %-6d%-6s  %-8d  %-8d  %-8d  %-8d  %-8d %-8d  ",gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);   

    printf("\nȷ��ɾ�� �밴1,��ɾ���밴0\n");   

    scanf("%d",&n); 

             if(m==1) 

    { 

      for(j=i;j<n-1;j++)//�ӵ�i�ʼ ����һ��ĸ���Ա��ֵ����ǰһ�����Ӧ�ĳ�Ա ��ɶԵ�i���ɾ�� 

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

  if(!button)//button==0����ɾ������� 

     n=n-1;//��Ա��������һ�� 

  else 

     printf("\n���޴���!\n"); 

     printf("\n ɾ���������ְ����Ϣ:\n"); 

     write(m);     //���ñ��溯�� 

     list();  //����������� 

  

printf("\n����ɾ���밴1,����ɾ���밴0\n"); 

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
Description: ��ִ����ӹ���ʱ�����������ú������ܡ���ӹ��ʼ�¼���ṹ������zggzĩβ
Calls: gx.dat
*********************************************************/
void add()/*��Ӻ���*/ 

{
      FILE *fp;
      int n,i,j;
      if((fp=fopen("gx,dat","ab+"))==NULL)
      {
          printf("���ܴ�gx�ļ�\n");
           exit(0);
      }
    printf("Ҫ׷�ӵ�ְ������:");
      scanf("%d",&n);
      for(i=0;i<n;i++) 
      { 
          printf("�����ʽ:���š���������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������    <Enter>\n");
         printf("׷�Ӽ�¼:\n");
         scanf("%s%s%s%d%f%f%f%f%f",gz[n].ID,gz[n].name,gz[n].postWages,
             gz[n].paySalary,gz[n].jobAllowance,gz[n].performancePay,gz[n].shouldPay,gz[n].tax,gz[n].realWages);
             newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;//��ȡһ���µ�ְ����¼
        fwrite(&newgz,sizeof(struct gongzi),1,fp);   //����ְ����¼д���ļ�
      }
      fclose(fp);
}
/*********************************************************
Function:grads
Description: �����������������ǳ���ִ�еĿ�ʼ�����������пɵ�������������ʵ���û�Ҫ��Ĺ��ܡ��������ܡ�������ʵ����ϵͳ�������棬�û����ڴ˽��������ѯ�������ɾ�������
Calls: gx.dat
*********************************************************/
void grads()
{
float Tax;  //Taxָ����������˰//
float shouldPay;    //shouldPayָ���˵�����//
printf("��������������shouldPay:",shouldPay);
scanf("%d",&shouldPay);
if(shouldPay<2000)
printf("��������˰");
else if(shouldPay>=2000&&shouldPay<2500)
{Tax=0.05*(S-2000);
printf("����Ҫ�ϵ�˰Ϊ��%d\n",Tax);
}
else if(shouldPay>=2500&&shouldPay<4000)
{Tax=0.1*(shouldPay-2000)-25;
printf("����Ҫ�ϵ�˰Ϊ��%d\n",Tax);
}
else if(shouldPay>=4000&&S<7000)
{Tax=0.15*(shouldPay-2000)-125;
printf("����Ҫ�ϵ�˰Ϊ��%d\n",Tax);
}
else if(shouldPay>=7000&&shouldPay<22000)
{Tax=0.2*(shouldPay-2000)-375;
printf("����Ҫ�ϵ�˰Ϊ��%d\n",Tax);
}
else if(shouldPay>=22000&&shouldPay<42000)
{Tax=0.25*(shouldPay-2000)-1375;
printf("����Ҫ�ϵ�˰Ϊ��%d\n",Tax);
}
else if(shouldPay>=42000&&shouldPay<62000)
{Tax=0.3*(shouldPay-2000)-3375;
printf("����Ҫ�ϵ�˰Ϊ��%d\n",Tax);
}
else if(shouldPay>=62000&&shouldPay<82000)
{Tax=0.35*(shouldPay-2000)-6375;
printf("����Ҫ�ϵ�˰Ϊ��%d\n",Tax);
}               
else if(shouldPay>=82000&&shouldPay<102000)
{Tax=0.4(shouldPay-2000)-10375;
printf("����Ҫ�ϵ�˰Ϊ��%d\n",Tax);
}   
else if(shouldPay>=102000)
{Tax=0.45*(shouldPay-2000)-15375;
printf("����Ҫ�ϵ�˰Ϊ��%d\n",Tax);
}           
}
/*********************************************************
Function:main
Description: �����������������ǳ���ִ�еĿ�ʼ�����������пɵ�������������ʵ���û�Ҫ��Ĺ��ܡ��������ܡ�������ʵ����ϵͳ�������棬�û����ڴ˽��������ѯ�������ɾ�������
Calls: gx.dat
*********************************************************/
void mian()
{
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