#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 1000
typedef struct studentrecord
{
   char stuNo[10];  //ѧ��
   char name[20];  //����
   int  age;       //����
   float math;     //��ѧ
   float English;  //Ӣ��
   float physics;  //����
}SR;

typedef struct studenttotal
{
   SR record;     //ѧ����¼
   float total;  //�ܳɼ�
}ST;
ST student [N];

SR stu[N];
int count;
void beforechange(int a) /*��������������޸Ļ�ɾ��ǰ��ѧ����Ϣ*/
{
 printf("%s %s %d %.2f %.2f %.2f %.2f\n",stu[a].stuNo,stu[a].name,stu[a].age,stu[a].math,stu[a].English, stu[a].physics);
}

void input(SR stu[])  /*���༶��¼ͳһ����*/
{
   int i;
   printf("���������ڰ༶Ҫ�Ǽǵ�ѧ������") ;
   scanf("%d",&count);
   printf("�밴Ҫ������(ѧ�ţ����������� ��ѧ Ӣ�� ����)\n");
   for(i=0;i<count;i++)
  {
  	printf("�������%d������Ϣ��(�ո����)\n",i+1);
	//gets( );
	//gets(stu[i].name);
	//scanf("%s",&stu[i].stuNo);
	//getchar();
	//scanf("%s",&stu[i].name);
	//getchar();
	scanf("%s %s %d %f %f %f",&stu[i].stuNo,&stu[i].name,&stu[i].age,&stu[i].math,&stu[i].English,&stu[i].physics);
   }
}
int find(char id[],SR stu[])/*����������ʵ��ͨ��ѧ�Ų��Ҷ�Ӧ��ѧ����¼*/
{
     int i;
     for (i=0;i<count;i++)
     {

         if (strcmp(stu[i].stuNo,id)==0)

         {

              return i;

         }

     }

     return -1;

}
void Insert(SR stu[])/*�����¼*/
{
 int i=count;
  int j=0;
     while(1)
     {
	printf("�������%d����Ҫ��ӵ�ѧ����¼(�ո����)\n",j+1);
	scanf("%s %s %d %f %f %f",&stu[i].stuNo,&stu[i].name,&stu[i].age,&stu[i].math,&stu[i].English,&stu[i].physics);
    count=count+1;
    i=count;
      printf("�Ƿ����?(y/n)");
      getchar();
      if (getchar()=='n')
      {
      	break;
      }
      else
        j=j+1;
     }
}
void Modify(SR stu[])/*���ļ������ļ��ж�һ����¼���ж��Ƿ�Ҫ�޸ģ�����ǣ����޸ĺ�����д���ļ�������ֱ������д���ļ�������һ����¼��*/

{
     while(1)
     {

        char id[10];
         int a;
         printf("������Ҫ�޸ĵ�ѧ����ѧ��:");
         scanf("%s",&id);
         getchar();
         a=find(id,stu);
         if (a==-1)
         {
              printf("ѧ��������!\n");
         }
         else
         {
              printf("��Ҫ�޸ĵ�ѧ����ϢΪ:\n");
              beforechange(a);
              printf("\n");
              printf("-- ��������ֵ(�ո����)--\n");
			  scanf("%s %s %d %f %f %f",&stu[a].stuNo,&stu[a].name,&stu[a].age,&stu[a].math,&stu[a].English,&stu[a].physics);
         }
         printf("�Ƿ����?(y/n)");
         getchar();
         if (getchar()=='n')
         {
              break;
         }
     }
}
void Delete(SR stu[])
{
     int i;
     while(1)
     {
         char id[10];
         int a;
         printf("������Ҫɾ����ѧ����ѧ��:");
         scanf("%s",&id);
         getchar();
         a=find(id,stu);
         if (a==-1)
         {
              printf("ѧ��������!\n");
         }
         else
         {
              printf("��Ҫɾ����ѧ����ϢΪ:\n");
              beforechange(a);
              printf("�Ƿ����Ҫɾ��?(y/n)");
              if (getchar()=='y')
              {
                   for (i=a;i<count-1;i++)
                   {
                       stu[i]=stu[i+1];
                   }
                   count--;
              }
              getchar();
         }
         printf("�Ƿ����?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}

void Addgrades(SR stu[])
{
 while(1)

     {

        char id[10];

         int a;

         printf("������Ҫ�Ǽǳɼ���ѧ����ѧ��:");

         scanf("%s",&id);

         getchar();

         a=find(id,stu);

         if (a==-1)

         {

              printf("ѧ��������!\n");

         }

         else

         {

printf("-- ������ɼ�--\n");

  scanf("%f%f%f",&stu[a].math,&stu[a].English,&stu[a].physics);
         }

         printf("�Ƿ����?(y/n)");

         if (getchar()=='n')

         {

              break;

         }

     }




}

void Changegrades(SR stu[])

{
    while(1)

     {

        char id[10];

         int a;

         printf("������Ҫ�޸ĵ�ѧ����ѧ��:");

         scanf("%s",&id);

         getchar();

         a=find(id,stu);

         if (a==-1)

         {

              printf("ѧ��������!\n");

         }

         else

         {

              printf("��Ҫ�޸ĵ�ѧ����ϢΪ:\n");

              beforechange(a);

              printf("-- �������³ɼ�--\n");

scanf("%f %f %f",&stu[a].math,&stu[a].English,&stu[a].physics);

         }

         printf("�Ƿ����?(y/n)");

         if (getchar()=='n')

         {

              break;

         }

     }
}

void liulanjiru(SR stu[])/*���ѧ���ɼ���Ϣ�ļ���������ÿ��10��*/
{
    int i;
    for(i=0;i<count;i++)
  {
      printf("%s %s %d %.2f %.2f %.2f\n",stu[i].stuNo,stu[i].name,stu[i].age,stu[i].math,stu[i].English, stu[i].physics);
      //if(i%10==0)
        //system("pause");
  }
}
void chengjitongji(SR stu[],ST student[])/*�����ܳɼ���*/
{
    int i;
   for(i=0;i<count;i++)
    {
    student[i].total=stu[i].math+stu[i].English+stu[i].physics;
	}
}
void printtotal(SR stu[],ST student[])
{

    int i;
   for(i=0;i<count;i++)
    {
    	printf("%s %s %d %.2f %.2f %.2f %.2f\n",stu[i].stuNo,stu[i].name,stu[i].age,stu[i].math,stu[i].English, stu[i].physics,student[i].total);
    }


}
void paixushucu(SR stu[], ST student[])/*�Գɼ����򣬴�ѧ���ɼ���Ϣ�ļ��ж�ȡ������¼��total�д�ż���õ����ܳɼ�*/
{
  int i,j,k,temp;
  chengjitongji(stu,student);
  	for(i=0;i<count-1;i++)
	{
	  	k=i;
		  for(j=i+1;j<count;j++)
		  {
			  if(   student[j].total>student[k].total    )
			  {
			  	k=j;
			  }
		  }
		if(k!=i)
		{
			temp=student[k].total;
			student[k].total=student[j].total;
			student[j].total=temp;
		}
	}
	 for(i=0;i<count;i++)
	 {
	 	printf("%s %s %d %.2f %.2f %.2f %.2f\n",stu[i].stuNo,stu[i].name,stu[i].age,stu[i].math,stu[i].English, stu[i].physics,student[i].total);
	 }
}

void Readfromfile( SR stu[])
{
	FILE *fp;
	int i,j;
	fp=fopen("Datebase.txt","r");
	if(fp==NULL)
	{
			printf("��ʧ��");
			exit(0);
	}
	for(i=0;i<count;i++)
	{
		fscanf(fp,"%s %s %d %f %f %f\n",&stu[i].stuNo,&stu[i].name,&stu[i].age,&stu[i].math,&stu[i].English,&stu[i].physics);
	}
	fclose(fp);
}
void  Writetofile( SR stu[])
{

    FILE *fp;
    int i;
	fp=fopen("Datebase.txt","w");
	if(fp==NULL)
	{
			printf("��ʧ��");
			exit(0);
	}
	for(i=0;i<count;i++)
	{
		fprintf(fp,"%s %s %d %f %f %f\n",stu[i].stuNo,stu[i].name,stu[i].age,stu[i].math,stu[i].English, stu[i].physics);
	}
	fclose(fp);
}
int getStuCount()`//�����ļ���ѧ���ĸ��� 
{
	int c;
    FILE *fp;
    int lines=0;
    fp=fopen("Datebase.txt", "rb");
    if(fp)
    {
        while((c=fgetc(fp)) != EOF)
            if(c=='\n') lines++;
        fclose(fp);
    }
    else
    {
    	printf("�����ļ���ʧ�ܣ������²������ݣ�\n");
		return 0;
    }
	return lines;
} 
int main()
{
   int choice;
   char c;
   printf("��ʼ���༶ѧ����¼�����򽫴��ļ���ȡ�������ݣ�(y/n)");
   scanf("%c",&c);
   if(c=='y')
   {
	   	input(stu);
	    Writetofile(stu);
   }
   else
   {
		count=getStuCount();
 		Readfromfile(stu);
   }
while(1)
{
printf("--------------------------------------------------\n");
printf("��ӭ����ӱ���ѧѧ������ϵͳ\n") ;
printf("\n");
printf("      �˵�\n");
printf("1.����ѧ����¼\n"  );
printf("2.�޸�ѧ����¼\n") ;
printf("3.ɾ��ѧ����¼\n" ) ;
printf("4.�Ǽǳɼ�\n");
printf("5.�޸ĳɼ�\n" ) ;
printf("6.���ѧ����¼\n" ) ;
printf("7.�鿴�ܳɼ�\n" ) ;
printf("8.�鿴�ɼ���\n");
printf("9.�˳�\n");
printf("\n");
printf("�������Ӧѡ��ǰ�����ֽ��й���ѡ��\n");
printf("--------------------------------------------------\n");
scanf("%d",&choice);
getchar();
switch(choice)
         {

         case 1:
            Insert(stu);/*Ҫ�����׷�ӵķ�ʽ��ѧ���ɼ���Ϣд��ѧ���ɼ���Ϣ�ļ���*/
           Writetofile( stu);
              break;

         case 2:

              Modify(stu);/*ͨ���˵�ѡ���޸�ѧ����¼���򿪸��ļ������ļ��ж�һ����¼���ж��Ƿ�Ҫ�޸ģ�����ǣ����޸ĺ�����д���ļ�������ֱ������д���ļ�������һ����¼��*/
            Writetofile(stu);
              break;

         case 3:

              Delete(stu);/*ͨ���˵�ѡ��ɾ��ѧ����¼���򿪸��ļ������ļ��ж�һ����¼���ж��Ƿ�Ҫɾ��������ǣ�����������������д���ļ�������һ����¼��*/
              Writetofile(stu);
              break;
         case 4:
            Addgrades(stu);/*�ɼ��Ǽ�,���������޸�ģ�飬ֻ���޸��ֶ�Ϊ������Ŀ�ĳɼ���*/
            break;

         case 5 :
	   		Changegrades(stu);/*�ɼ��޸�ģ��*/
	          Writetofile(stu);
	         break;
         case 6:
            liulanjiru(stu);/*�������ģ��,��ȡѧ���ɼ���Ϣ�ļ������������ÿ��10����¼��*/
            break;
         case 7:
            chengjitongji(stu,student);/*�ɼ�ͳ��ģ��,��ѧ���ɼ���Ϣ�ļ��ж�ȡһ��ѧ����¼�������ѧ�����ܳɼ����򵥵ĳɼ���ӣ��������Ȼ���ȡ��һ����¼��*/
          printtotal(stu,student);
          break;
         case 8:
            paixushucu(stu,student);/*��ѧ���ɼ���Ϣ�ļ��ж�ȡ������¼��total�д�ż���õ����ܳɼ���Ȼ����������㷨��ð�ݡ����롢ѡ��ȣ������鰴���ܳɼ������������˳�������*/
                 system("pause");
         break;

             case 9:
                printf("�رճ���");
                exit(0);
                break;
         }
     }
}

