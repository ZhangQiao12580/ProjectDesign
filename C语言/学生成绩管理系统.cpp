#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct stu
{
	char Name[10];
	long StuNum;
	int StuScore[6];
	int SumScore;
	float AverScore;
}Student;
void PrintfMenue();
void PrintfMenue_s(); 
void InputMessage(Student stu[30],int StuCount,int ClassCount);
void EverClassAverScore(Student stu[],int StuCount,int ClassCount);
void EverStuAverScore(Student stu[],int StuCount,int ClassCount);
void SumScore_Order(Student stu[],int StuCount,int ClassCount);// 顺序
void SumScore_Reverse(Student stu[],int StuCount,int ClassCount);//逆序
void StuNum_Order(Student stu[],int StuCount,int ClassCount);
void StuName_Order(Student stu[],int StuCount,int ClassCount);
void StuName_Search(Student stu[],int StuCount,int ClassCount,char stuname[]);
void StuNum_Search(Student stu[],int StuCount,int ClassCount,long stunum);
void Score_Statistics(Student stu[],int StuCount,int ClassCount);
void Score_Summary(Student stu[],int StuCount,int ClassCount);
void OutputToFile(Student stu[],int StuCount,int ClassCount);
void InputToFile(Student stu[],int StuCount,int ClassCount);
int main()
{
	int menuenum;
	int yet;
	int scnd;
	bool first=true;
	Student stu[30];
	int num_stu,num_class;
	char stuname[10];
	long stunum;
	int inform;
	int menuenum_s,yet_s;
	printf("请选择要登录的对象(1.教师2.学生):");
	scanf("%d",&inform);
	if(inform==1)
	{
		printf("                学生成绩管理系统教师端V6.0\n");
		printf("-----------------------------------------------------------\n");
		while(1)
		{
			PrintfMenue();
			yet=scanf("%d",&menuenum);
			while(menuenum<0||menuenum>13||yet==0)
			{
				getchar();
				printf("菜单序号输入错误，请重新输入:");
				yet=scanf("%d",&menuenum);
			}
			printf("\n-----------------------------------------------------------\n");
			if(menuenum!=1&&first==true)
			{
				printf("需要先输入数据,请输入菜单序号1\n");
				printf("\n-----------------------------------------------------------\n");
				continue;
			}
			first=false;
			if(menuenum==1)
	    	{
		        printf("请输入人数，课程数：");
		        yet=scanf("%d,%d",&num_stu,&num_class);
		        while(yet==0||num_class>6||num_class<0||num_stu>30||num_class<0)
		        {
	        		getchar();
					printf("学生、课程输入有误,请重新输入:\n");
				 	yet=scanf("%d,%d",&num_stu,&num_class);
	        	}
	        	printf("(1)从键盘录入\n(2)从文件读取\n");
	        	scanf("%d",&scnd);
	        	if(scnd==1)
	            {
	                InputMessage(stu,num_stu,num_class);
	            }
	            else
	            {
	                InputToFile(stu,num_stu,num_class);
	            }
	    	}
	    	else if(menuenum==2)
	    	{
		    	EverClassAverScore(stu,num_stu,num_class);
		    }
		    else if(menuenum==3)
		    {
	    		EverStuAverScore(stu,num_stu,num_class);
	    	}
	    	else if(menuenum==4)
	    	{
		    	SumScore_Reverse(stu,num_stu,num_class);
		    }
		    else if(menuenum==5)
		    {
	    		SumScore_Order(stu,num_stu,num_class);
	    	}
	    	else if(menuenum==6)
	    	{
		    	StuNum_Order(stu,num_stu,num_class);
		    }
		    else if(menuenum==7)
		    {
	    		StuName_Order(stu,num_stu,num_class);
	    	}
	    	else if(menuenum==8)
	    	{
		    	printf("请输入要查询的学号:");
		    	yet=scanf("%ld",&stunum);
		    	while(yet==0)
		    	{
		    		getchar();
		    		printf("学号输入有误，请重新输入:\n");
		    		yet=scanf("%ld",&stunum);
		    	}
		    	StuNum_Search(stu,num_stu,num_class,stunum);
		    }
		    else if(menuenum==9)
		    {
		    	getchar();
	    		printf("请输入要查询的姓名:");
		    	gets(stuname);
		    	StuName_Search(stu,num_stu,num_class,stuname);
	    	}
	    	else if(menuenum==10)
	    	{
		    	Score_Statistics(stu,num_stu,num_class);
		    }
		    else if(menuenum==11)
		    {
	    		Score_Summary(stu,num_stu,num_class);
	    	}
		    else if(menuenum==12)
		    {
	    		OutputToFile(stu,num_stu,num_class);
	    	}
	    	else if(menuenum==13)
	    	{
		    	InputToFile(stu,num_stu,num_class);
		    }
		    else
		    {
	    		printf("欢迎下次使用！\n");
	    		printf("-----------------------------------------------------------\n");
	    		return 0;
	    	}
		}
	}
	else if(inform==2)
	{
		printf("                学生成绩管理系统学生端V6.0\n");
		printf("-----------------------------------------------------------\n");
		while(1)
		{
			PrintfMenue_s();
			yet_s=scanf("%d",&menuenum_s);
			while(menuenum_s<0||menuenum_s>2||yet_s==0)
			{
				getchar();
				printf("菜单序号输入错误，请重新输入:");
				yet=scanf("%d",&menuenum_s);
			}
			printf("\n-----------------------------------------------------------\n");
			if(menuenum_s==1)
			{
				printf("请输入要查询的学号:");
		    	yet=scanf("%ld",&stunum);
		    	while(yet==0)
		    	{
		    		getchar();
		    		printf("学号输入有误，请重新输入:\n");
		    		yet=scanf("%ld",&stunum);
		    	}
		    	StuNum_Search(stu,num_stu,num_class,stunum);
			}
			else if(menuenum_s==2)
			{
				getchar();
	    		printf("请输入要查询的姓名:");
		    	gets(stuname);
		    	StuName_Search(stu,num_stu,num_class,stuname);
			}
			else if(menuenum_s==0)
			{
				printf("欢迎下次使用！\n");
	    		printf("-----------------------------------------------------------\n");
	    		return 0;
			} 
		}
	}
	printf("-----------------------------------------------------------\n");
}
void PrintfMenue()
{
	printf("1.录入每个学生的学号、姓名和各科考试成绩；\n");
	printf("2.计算每门课程的总分和平均分；\n");
	printf("3.计算每个学生的总分和平均分；\n");
	printf("4.按每个学生的总分由高到低排出名次表；\n");
	printf("5.按每个学生的总分由低到高排出名次表；\n");
	printf("6.按学号由小到大排出成绩表；\n");
	printf("7.按姓名的字典排序排出成绩表；\n");
	printf("8.按学号查询学生排名及其考试成绩；\n");
	printf("9.按姓名查询学生排名及其考试成绩；\n");
	printf("10.按优秀(90~100)、良好(80~89)、中等(70~79)、及格(60~69)、不及格(0~59)5个类别，对每门课程分别统计每个类别的人数以及所占的百分比；\n");
	printf("11.输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分；\n");
	printf("12.将每个学生的记录信息写入文件；\n");
	printf("13.从文件中读出每个学生的记录信息并显示；\n");
	printf("0.退出\n");
	printf("-----------------------------------------------------------\n");
	printf("请输入序号以选择相应菜单项目:");
}
void InputMessage(Student stu[30],int StuCount,int ClassCount)
{
	int i,j;
	for(i=0;i<StuCount;i++)
	{
		int yet;
		printf("请输入第%d个学生的信息:（姓名，学号，各科考试成绩）\n",i+1);
		scanf("%s",&stu[i].Name);
		getchar();
		scanf("%ld",&stu[i].StuNum);
		stu[i].SumScore=0;
		for(j=0;j<ClassCount;j++)
		{
			yet=scanf("%d",&stu[i].StuScore[j]);
			while(stu[i].StuScore[j]>150||stu[i].StuScore[j]<0||yet==0)
			{
				printf("第%d个学生第%d科成绩输入有误，请重新输入:",i+1,j+1);
				getchar();
				yet=scanf("%d",&stu[i].StuScore[j]);
			}
		}
	}
	printf("-----------------------------------------------------------\n");
}
void EverClassAverScore(Student stu[],int StuCount,int ClassCount)
{
	int i,j;
	float temp;
	for(j=0;j<ClassCount;j++)
	{
		temp=0;
		for(i=0;i<StuCount;i++)
		{
			temp+=stu[i].StuScore[j];
		}
		printf("科目:%d 总分:%3.0f 平均分:%.1f\n",j+1,temp,(float)temp/StuCount);
	}
	printf("\n-----------------------------------------------------------\n");
}
void EverStuAverScore(Student stu[],int StuCount,int ClassCount)
{
	int i,j;
	float temp;
	for(i=0;i<StuCount;i++)
	{
		temp=0;
		for(j=0;j<ClassCount;j++)
		{
			temp+=stu[i].StuScore[j];
		}
		stu[i].AverScore=temp/ClassCount;
		printf("姓名:%-10s总分:%-3.0f平均分:%.1f\n",stu[i].Name,temp,stu[i].AverScore);
		stu[i].AverScore=0;
	}
	printf("\n-----------------------------------------------------------\n");
}
void SumScore_Order(Student stu[],int StuCount,int ClassCount)
{
	int i,j;
	int temp,temp2;
	int ScoreTemp[30][2];
	for(i=0;i<StuCount;i++)
	{
		stu[i].SumScore=0;
		for(j=0;j<ClassCount;j++)
		{
			stu[i].SumScore+=stu[i].StuScore[j];
		}
		ScoreTemp[i][0]=stu[i].SumScore;
		ScoreTemp[i][1]=i;
	}
	for(i=0;i<StuCount-1;i++)
	{
		for(j=i;j<StuCount;j++)
		{
			if(ScoreTemp[i][0]>ScoreTemp[j][0])
			{
				temp=ScoreTemp[i][0];
				temp2=ScoreTemp[i][1];
				ScoreTemp[i][0]=ScoreTemp[j][0];
				ScoreTemp[i][1]=ScoreTemp[j][1];
				ScoreTemp[j][0]=temp;
				ScoreTemp[j][1]=temp2;
			}
		}
	}
	for(i=StuCount-1;i>=0;i--)
	{
		printf("第%02d名:%s总分:%003d\n",i+1,stu[ScoreTemp[StuCount-i-1][1]].Name,ScoreTemp[StuCount-i-1][0]);
		stu[i].AverScore=0;
	}
	printf("\n-----------------------------------------------------------\n");
}
void SumScore_Reverse(Student stu[],int StuCount,int ClassCount)
{
	int i,j;
	int temp,temp2;
	int ScoreTemp[30][2];
	for(i=0;i<StuCount;i++)
	{
		stu[i].SumScore=0;
		for(j=0;j<ClassCount;j++)
		{
			stu[i].SumScore+=stu[i].StuScore[j];
		}
		ScoreTemp[i][0]=stu[i].SumScore;
		ScoreTemp[i][1]=i;
	}
	for(i=0;i<StuCount-1;i++)
	{
		for(j=i;j<StuCount;j++)
		{
			if(ScoreTemp[i][0]<ScoreTemp[j][0])
			{
				temp=ScoreTemp[i][0];
				temp2=ScoreTemp[i][1];
				ScoreTemp[i][0]=ScoreTemp[j][0];
				ScoreTemp[i][1]=ScoreTemp[j][1];
				ScoreTemp[j][0]=temp;
				ScoreTemp[j][1]=temp2;
			}
		}
	}
	for(i=0;i<StuCount;i++)
	{
		printf("第%02d名:%s总分:%003d\n",i+1,stu[ScoreTemp[i][1]].Name,ScoreTemp[i][0]);
	}
	printf("\n-----------------------------------------------------------\n");
}
void StuNum_Order(Student stu[],int StuCount,int ClassCount)
{
	int i;
	int j,k;
	Student asd;
	Student temp[30];
	for(i=0;i<StuCount;i++)
	{
		stu[i].SumScore=0;
		temp[i]=stu[i];
	}
	for(j=0;j<StuCount-1;j++)
	{
		for(k=j;k<StuCount;k++)
		{
			if(temp[j].StuNum>temp[k].StuNum)
			{
				asd=temp[j];
				temp[j]=temp[k];
				temp[k]=asd;
			}
		}
	}
	for(i=0;i<StuCount;i++)
	{
		printf("学号:%10ld 分数",temp[i].StuNum);
		for(j=0;j<ClassCount;j++)
		{
			temp[i].SumScore+=temp[i].StuScore[j];
			printf("%3d",temp[i].StuScore[j]);
		}
		printf(" 总分:%3d\n",temp[i].SumScore);
		stu[i].AverScore=0;
	}
	printf("\n-----------------------------------------------------------\n");
}
void StuName_Order(Student stu[],int StuCount,int ClassCount)
{
	int i,j;
	char temp2[10];
	Student asd;
	Student temp[30];
	for(i=0;i<StuCount;i++)
	{
		temp[i]=stu[i];
	}
	for(i=0;i<StuCount-1;i++)
	{
		for(j=i+1;j<StuCount;j++)
		{
			if(strcmp(temp[i].Name,temp[j].Name)>0)
			{
				asd=temp[i];
				temp[i]=temp[j];
				temp[j]=asd;
			}
		}
	}
	for(i=0;i<StuCount;i++)
	{
		printf("学号:%-10ld 姓名:%-10s分数",temp[i].StuNum,temp[i].Name);
		for(j=0;j<ClassCount;j++)
		{
			temp[i].SumScore+=temp[i].StuScore[j];
			printf("%-3d",temp[i].StuScore[j]);
		}
		printf(" 总分:%-3d\n",temp[i].SumScore);
	}
	printf("\n-----------------------------------------------------------\n");
}
void StuName_Search(Student stu[],int StuCount,int ClassCount,char stuname[])
{
	int i,j,temp2;
	int flag=0;
	Student temp[30];
	Student temp1;
	for(i=0;i<StuCount;i++)
	{
		stu[i].SumScore=0;
		for(j=0;j<ClassCount;j++)
		{
			stu[i].SumScore+=stu[i].StuScore[j];
		}
		temp[i]=stu[i];
	}
	for(i=0;i<StuCount-1;i++)
	{
		for(j=i+1;j<StuCount;j++)
		{
			if(temp[i].SumScore<temp[j].SumScore)
			{
				temp1=temp[i];
				temp[i]=temp[j];
				temp[j]=temp1;
			}
		}
	}
	for(i=0;i<StuCount;i++)
	{
		if(strcmp(temp[i].Name,stuname)==0)
		{
			flag=1;
			temp2=i;
		}
	}
	if(flag==1)
	{
		printf("学号:%10ld 姓名:%10s 分数:",temp[temp2].StuNum,temp[temp2].Name);
		for(j=0;j<ClassCount;j++)
		{
			printf("%3d",temp[temp2].StuScore[j]);
		}
		printf(" 总分:%3d 排名:%d\n",temp[temp2].SumScore,temp2+1);
	}
	else
	{
		printf("输入的姓名有误,无查询结果！\n");
	}
	printf("\n-----------------------------------------------------------\n");
}
void StuNum_Search(Student stu[],int StuCount,int ClassCount,long stunum)
{
	int i,j,temp2;
	int flag=0;
	Student temp[30];
	Student temp1;
	for(i=0;i<StuCount;i++)
	{
		temp[i]=stu[i];
		temp[i].SumScore=0;
		for(j=0;j<ClassCount;j++)
		{
			temp[i].SumScore+=temp[i].StuScore[j];
		}
	}
	for(i=0;i<StuCount-1;i++)
	{
		for(j=i+1;j<StuCount;j++)
		{
			if(temp[i].SumScore<temp[j].SumScore)
			{
				temp1=temp[i];
				temp[i]=temp[j];
				temp[j]=temp1;
			}
		}
	}
	for(i=0;i<StuCount;i++)
	{
		if(stunum==temp[i].StuNum)
		{
			flag=1;
			temp2=i;
		}
	}
	if(flag==1)
	{
		printf("学号:%10ld 姓名:%10s 分数:",temp[temp2].StuNum,temp[temp2].Name);
		for(j=0;j<ClassCount;j++)
		{
			printf("%3d",temp[temp2].StuScore[j]);
		}
		printf(" 总分:%3d 排名:%d\n",temp[temp2].SumScore,temp2+1);
	}
	else
	{
		printf("输入的学号有误,无查询结果！\n");
	}
	printf("\n-----------------------------------------------------------\n");
}
void Score_Statistics(Student stu[],int StuCount,int ClassCount)
{
	int i,j,count[6][5]={0};
	for(i=0;i<ClassCount;i++)
	{
		for(j=0;j<StuCount;j++)
		{
			if(stu[j].StuScore[i]>=90)
			{
				count[i][0]++;
			}
			else if(stu[j].StuScore[i]>=80)
			{
				count[i][1]++;
			}
			else if(stu[j].StuScore[i]>=70)
			{
				count[i][2]++;
			}
			else if(stu[j].StuScore[i]>=60)
			{
				count[i][3]++;
			}
			else
			{
				count[i][4]++;
			}
		}
	}
	for(i=0;i<ClassCount;i++)
	{
			printf("第%d科 优秀:%02d %.1f%% 良好:%02d %.1f%% 中等:%02d %.1f%% 及格:%02d %.1f%% 不及格:%02d %.1f%%\n",i+1,count[i][0],((float)count[i][0]/StuCount)*100,count[i][1],((float)count[i][1]/StuCount)*100,count[i][2],((float)count[i][2]/StuCount)*100,count[i][3],((float)count[i][3]/StuCount)*100,count[i][4],((float)count[i][4]/StuCount)*100);
	}
	printf("\n-----------------------------------------------------------\n");
}
void Score_Summary(Student stu[],int StuCount,int ClassCount)
{
	int i,j;
	for(i=0;i<StuCount;i++)
	{
		stu[i].SumScore=0;
		for(j=0;j<ClassCount;j++)
		{
			stu[i].SumScore+=stu[i].StuScore[j];
		}
		stu[i].AverScore=((float)stu[i].SumScore)/ClassCount;
	}
	for(i=0;i<StuCount;i++)
	{
		printf("姓名:%-10s学号:%-10ld分数:",stu[i].Name,stu[i].StuNum);
		for(j=0;j<ClassCount;j++)
		{
			printf("%-3d",stu[i].StuScore[j]);
		}
		printf("总分:%-3d平均分:%.1f\n",stu[i].SumScore,stu[i].AverScore);
	}
	printf("\n-----------------------------------------------------------\n");
}
void OutputToFile(Student stu[],int StuCount,int ClassCount)
{
	FILE *fp;
	int i,j;
	if((fp=fopen("Student.txt","w"))==NULL)
	{
		printf("打开文件失败！");
		exit(0);
	}
	for(i=0;i<StuCount;i++)
	{
		fprintf(fp,"%-10s %-10ld ",stu[i].Name,stu[i].StuNum);
		for(j=0;j<ClassCount;j++)
		{
			fprintf(fp,"%3d",stu[i].StuScore[j]);
		}
		fprintf(fp,"\n");
	}
	printf("文件写入成功！\n");
	fclose(fp);
	printf("\n-----------------------------------------------------------\n");
}
void InputToFile(Student stu[],int StuCount,int ClassCount)
{
	FILE *fp;
	int i,j;
	if((fp=fopen("Student.txt","r"))==NULL)
	{
		printf("打开文件失败！");
		exit(0);
	}
	for(i=0;i<StuCount;i++)
	{
		fscanf(fp,"%s %ld",&stu[i].Name,&stu[i].StuNum);
		for(j=0;j<ClassCount;j++)
		{
			fscanf(fp,"%d",&stu[i].StuScore[j]);
		}
	}
	fclose(fp);
	for(i=0;i<StuCount;i++)
	{
		printf("姓名:%-10s 学号:%-10ld分数:",stu[i].Name,stu[i].StuNum);
		for(j=0;j<ClassCount;j++)
		{
			printf("%-3d",stu[i].StuScore[j]);
		}
		printf("\n");
	}
	printf("\n-----------------------------------------------------------\n");
}
void PrintfMenue_s()
{
	printf("1.按学号查询学生排名及其考试成绩；\n");
	printf("2.按姓名查询学生排名及其考试成绩；\n");
	printf("0.退出\n");
	printf("-----------------------------------------------------------\n");
}