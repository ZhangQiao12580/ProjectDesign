#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define N 1000
typedef struct studentrecord
{
   char stuNo[10];  //学号
   char name[20];  //姓名
   int  age;       //年龄
   float math;     //数学
   float English;  //英语
   float physics;  //物理
}SR;

typedef struct studenttotal
{
   SR record;     //学生纪录
   float total;  //总成绩
}ST;
ST student [N];

SR stu[N];
int count;
void beforechange(int a) /*公共函数，输出修改或删出前的学生信息*/
{
 printf("%s %s %d %.2f %.2f %.2f %.2f\n",stu[a].stuNo,stu[a].name,stu[a].age,stu[a].math,stu[a].English, stu[a].physics);
}

void input(SR stu[])  /*将班级记录统一输入*/
{
   int i;
   printf("请输人所在班级要登记的学生人数") ;
   scanf("%d",&count);
   printf("请按要求输入(学号，姓名，年龄 数学 英语 物理)\n");
   for(i=0;i<count;i++)
  {
  	printf("请输入第%d个人信息：(空格隔开)\n",i+1);
	//gets( );
	//gets(stu[i].name);
	//scanf("%s",&stu[i].stuNo);
	//getchar();
	//scanf("%s",&stu[i].name);
	//getchar();
	scanf("%s %s %d %f %f %f",&stu[i].stuNo,&stu[i].name,&stu[i].age,&stu[i].math,&stu[i].English,&stu[i].physics);
   }
}
int find(char id[],SR stu[])/*公共函数，实现通过学号查找对应的学生记录*/
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
void Insert(SR stu[])/*插入记录*/
{
 int i=count;
  int j=0;
     while(1)
     {
	printf("请输入第%d个需要添加的学生记录(空格隔开)\n",j+1);
	scanf("%s %s %d %f %f %f",&stu[i].stuNo,&stu[i].name,&stu[i].age,&stu[i].math,&stu[i].English,&stu[i].physics);
    count=count+1;
    i=count;
      printf("是否继续?(y/n)");
      getchar();
      if (getchar()=='n')
      {
      	break;
      }
      else
        j=j+1;
     }
}
void Modify(SR stu[])/*打开文件，从文件中读一条记录，判断是否要修改，如果是，则修改后重新写入文件；否则直接重新写入文件，读下一条记录。*/

{
     while(1)
     {

        char id[10];
         int a;
         printf("请输入要修改的学生的学号:");
         scanf("%s",&id);
         getchar();
         a=find(id,stu);
         if (a==-1)
         {
              printf("学生不存在!\n");
         }
         else
         {
              printf("你要修改的学生信息为:\n");
              beforechange(a);
              printf("\n");
              printf("-- 请输入新值(空格隔开)--\n");
			  scanf("%s %s %d %f %f %f",&stu[a].stuNo,&stu[a].name,&stu[a].age,&stu[a].math,&stu[a].English,&stu[a].physics);
         }
         printf("是否继续?(y/n)");
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
         printf("请输入要删除的学生的学号:");
         scanf("%s",&id);
         getchar();
         a=find(id,stu);
         if (a==-1)
         {
              printf("学生不存在!\n");
         }
         else
         {
              printf("你要删除的学生信息为:\n");
              beforechange(a);
              printf("是否真的要删除?(y/n)");
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
         printf("是否继续?(y/n)");
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

         printf("请输入要登记成绩的学生的学号:");

         scanf("%s",&id);

         getchar();

         a=find(id,stu);

         if (a==-1)

         {

              printf("学生不存在!\n");

         }

         else

         {

printf("-- 请输入成绩--\n");

  scanf("%f%f%f",&stu[a].math,&stu[a].English,&stu[a].physics);
         }

         printf("是否继续?(y/n)");

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

         printf("请输入要修改的学生的学号:");

         scanf("%s",&id);

         getchar();

         a=find(id,stu);

         if (a==-1)

         {

              printf("学生不存在!\n");

         }

         else

         {

              printf("你要修改的学生信息为:\n");

              beforechange(a);

              printf("-- 请输入新成绩--\n");

scanf("%f %f %f",&stu[a].math,&stu[a].English,&stu[a].physics);

         }

         printf("是否继续?(y/n)");

         if (getchar()=='n')

         {

              break;

         }

     }
}

void liulanjiru(SR stu[])/*浏览学生成绩信息文件，分屏，每屏10条*/
{
    int i;
    for(i=0;i<count;i++)
  {
      printf("%s %s %d %.2f %.2f %.2f\n",stu[i].stuNo,stu[i].name,stu[i].age,stu[i].math,stu[i].English, stu[i].physics);
      //if(i%10==0)
        //system("pause");
  }
}
void chengjitongji(SR stu[],ST student[])/*计算总成绩的*/
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
void paixushucu(SR stu[], ST student[])/*对成绩排序，从学生成绩信息文件中读取各个纪录，total中存放计算得到的总成绩*/
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
			printf("打开失败");
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
			printf("打开失败");
			exit(0);
	}
	for(i=0;i<count;i++)
	{
		fprintf(fp,"%s %s %d %f %f %f\n",stu[i].stuNo,stu[i].name,stu[i].age,stu[i].math,stu[i].English, stu[i].physics);
	}
	fclose(fp);
}
int getStuCount()`//返回文件中学生的个数 
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
    	printf("数据文件打开失败，请重新插入数据！\n");
		return 0;
    }
	return lines;
} 
int main()
{
   int choice;
   char c;
   printf("初始化班级学生记录？否则将从文件读取已有数据！(y/n)");
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
printf("欢迎进入河北大学学生管理系统\n") ;
printf("\n");
printf("      菜单\n");
printf("1.插入学生纪录\n"  );
printf("2.修改学生纪录\n") ;
printf("3.删除学生纪录\n" ) ;
printf("4.登记成绩\n");
printf("5.修改成绩\n" ) ;
printf("6.浏览学生纪录\n" ) ;
printf("7.查看总成绩\n" ) ;
printf("8.查看成绩表\n");
printf("9.退出\n");
printf("\n");
printf("请输入对应选项前的数字进行功能选择\n");
printf("--------------------------------------------------\n");
scanf("%d",&choice);
getchar();
switch(choice)
         {

         case 1:
            Insert(stu);/*要求采用追加的方式把学生成绩信息写入学生成绩信息文件。*/
           Writetofile( stu);
              break;

         case 2:

              Modify(stu);/*通过菜单选择修改学生纪录，打开该文件，从文件中读一条记录，判断是否要修改，如果是，则修改后重新写入文件；否则直接重新写入文件，读下一条记录。*/
            Writetofile(stu);
              break;

         case 3:

              Delete(stu);/*通过菜单选择删除学生纪录，打开该文件，从文件中读一条记录，判断是否要删除，如果是，则舍弃；否则重新写入文件，读下一条记录。*/
              Writetofile(stu);
              break;
         case 4:
            Addgrades(stu);/*成绩登记,类似数据修改模块，只是修改字段为各个科目的成绩。*/
            break;

         case 5 :
	   		Changegrades(stu);/*成绩修改模块*/
	          Writetofile(stu);
	         break;
         case 6:
            liulanjiru(stu);/*数据浏览模块,读取学生成绩信息文件，分屏输出，每屏10条纪录。*/
            break;
         case 7:
            chengjitongji(stu,student);/*成绩统计模块,从学生成绩信息文件中读取一个学生纪录，计算该学生的总成绩（简单的成绩相加），输出，然后读取下一条纪录。*/
          printtotal(stu,student);
          break;
         case 8:
            paixushucu(stu,student);/*从学生成绩信息文件中读取各个纪录，total中存放计算得到的总成绩。然后采用排序算法（冒泡、插入、选择等）对数组按照总成绩进行排序。最后顺序输出。*/
                 system("pause");
         break;

             case 9:
                printf("关闭程序");
                exit(0);
                break;
         }
     }
}

