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
void SumScore_Order(Student stu[],int StuCount,int ClassCount);// ˳��
void SumScore_Reverse(Student stu[],int StuCount,int ClassCount);//����
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
	printf("��ѡ��Ҫ��¼�Ķ���(1.��ʦ2.ѧ��):");
	scanf("%d",&inform);
	if(inform==1)
	{
		printf("                ѧ���ɼ�����ϵͳ��ʦ��V6.0\n");
		printf("-----------------------------------------------------------\n");
		while(1)
		{
			PrintfMenue();
			yet=scanf("%d",&menuenum);
			while(menuenum<0||menuenum>13||yet==0)
			{
				getchar();
				printf("�˵���������������������:");
				yet=scanf("%d",&menuenum);
			}
			printf("\n-----------------------------------------------------------\n");
			if(menuenum!=1&&first==true)
			{
				printf("��Ҫ����������,������˵����1\n");
				printf("\n-----------------------------------------------------------\n");
				continue;
			}
			first=false;
			if(menuenum==1)
	    	{
		        printf("�������������γ�����");
		        yet=scanf("%d,%d",&num_stu,&num_class);
		        while(yet==0||num_class>6||num_class<0||num_stu>30||num_class<0)
		        {
	        		getchar();
					printf("ѧ�����γ���������,����������:\n");
				 	yet=scanf("%d,%d",&num_stu,&num_class);
	        	}
	        	printf("(1)�Ӽ���¼��\n(2)���ļ���ȡ\n");
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
		    	printf("������Ҫ��ѯ��ѧ��:");
		    	yet=scanf("%ld",&stunum);
		    	while(yet==0)
		    	{
		    		getchar();
		    		printf("ѧ��������������������:\n");
		    		yet=scanf("%ld",&stunum);
		    	}
		    	StuNum_Search(stu,num_stu,num_class,stunum);
		    }
		    else if(menuenum==9)
		    {
		    	getchar();
	    		printf("������Ҫ��ѯ������:");
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
	    		printf("��ӭ�´�ʹ�ã�\n");
	    		printf("-----------------------------------------------------------\n");
	    		return 0;
	    	}
		}
	}
	else if(inform==2)
	{
		printf("                ѧ���ɼ�����ϵͳѧ����V6.0\n");
		printf("-----------------------------------------------------------\n");
		while(1)
		{
			PrintfMenue_s();
			yet_s=scanf("%d",&menuenum_s);
			while(menuenum_s<0||menuenum_s>2||yet_s==0)
			{
				getchar();
				printf("�˵���������������������:");
				yet=scanf("%d",&menuenum_s);
			}
			printf("\n-----------------------------------------------------------\n");
			if(menuenum_s==1)
			{
				printf("������Ҫ��ѯ��ѧ��:");
		    	yet=scanf("%ld",&stunum);
		    	while(yet==0)
		    	{
		    		getchar();
		    		printf("ѧ��������������������:\n");
		    		yet=scanf("%ld",&stunum);
		    	}
		    	StuNum_Search(stu,num_stu,num_class,stunum);
			}
			else if(menuenum_s==2)
			{
				getchar();
	    		printf("������Ҫ��ѯ������:");
		    	gets(stuname);
		    	StuName_Search(stu,num_stu,num_class,stuname);
			}
			else if(menuenum_s==0)
			{
				printf("��ӭ�´�ʹ�ã�\n");
	    		printf("-----------------------------------------------------------\n");
	    		return 0;
			} 
		}
	}
	printf("-----------------------------------------------------------\n");
}
void PrintfMenue()
{
	printf("1.¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ���\n");
	printf("2.����ÿ�ſγ̵��ֺܷ�ƽ���֣�\n");
	printf("3.����ÿ��ѧ�����ֺܷ�ƽ���֣�\n");
	printf("4.��ÿ��ѧ�����ܷ��ɸߵ����ų����α�\n");
	printf("5.��ÿ��ѧ�����ܷ��ɵ͵����ų����α�\n");
	printf("6.��ѧ����С�����ų��ɼ���\n");
	printf("7.���������ֵ������ų��ɼ���\n");
	printf("8.��ѧ�Ų�ѯѧ���������俼�Գɼ���\n");
	printf("9.��������ѯѧ���������俼�Գɼ���\n");
	printf("10.������(90~100)������(80~89)���е�(70~79)������(60~69)��������(0~59)5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱȣ�\n");
	printf("11.���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ���֣�\n");
	printf("12.��ÿ��ѧ���ļ�¼��Ϣд���ļ���\n");
	printf("13.���ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ��\n");
	printf("0.�˳�\n");
	printf("-----------------------------------------------------------\n");
	printf("�����������ѡ����Ӧ�˵���Ŀ:");
}
void InputMessage(Student stu[30],int StuCount,int ClassCount)
{
	int i,j;
	for(i=0;i<StuCount;i++)
	{
		int yet;
		printf("�������%d��ѧ������Ϣ:��������ѧ�ţ����ƿ��Գɼ���\n",i+1);
		scanf("%s",&stu[i].Name);
		getchar();
		scanf("%ld",&stu[i].StuNum);
		stu[i].SumScore=0;
		for(j=0;j<ClassCount;j++)
		{
			yet=scanf("%d",&stu[i].StuScore[j]);
			while(stu[i].StuScore[j]>150||stu[i].StuScore[j]<0||yet==0)
			{
				printf("��%d��ѧ����%d�Ƴɼ�������������������:",i+1,j+1);
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
		printf("��Ŀ:%d �ܷ�:%3.0f ƽ����:%.1f\n",j+1,temp,(float)temp/StuCount);
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
		printf("����:%-10s�ܷ�:%-3.0fƽ����:%.1f\n",stu[i].Name,temp,stu[i].AverScore);
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
		printf("��%02d��:%s�ܷ�:%003d\n",i+1,stu[ScoreTemp[StuCount-i-1][1]].Name,ScoreTemp[StuCount-i-1][0]);
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
		printf("��%02d��:%s�ܷ�:%003d\n",i+1,stu[ScoreTemp[i][1]].Name,ScoreTemp[i][0]);
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
		printf("ѧ��:%10ld ����",temp[i].StuNum);
		for(j=0;j<ClassCount;j++)
		{
			temp[i].SumScore+=temp[i].StuScore[j];
			printf("%3d",temp[i].StuScore[j]);
		}
		printf(" �ܷ�:%3d\n",temp[i].SumScore);
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
		printf("ѧ��:%-10ld ����:%-10s����",temp[i].StuNum,temp[i].Name);
		for(j=0;j<ClassCount;j++)
		{
			temp[i].SumScore+=temp[i].StuScore[j];
			printf("%-3d",temp[i].StuScore[j]);
		}
		printf(" �ܷ�:%-3d\n",temp[i].SumScore);
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
		printf("ѧ��:%10ld ����:%10s ����:",temp[temp2].StuNum,temp[temp2].Name);
		for(j=0;j<ClassCount;j++)
		{
			printf("%3d",temp[temp2].StuScore[j]);
		}
		printf(" �ܷ�:%3d ����:%d\n",temp[temp2].SumScore,temp2+1);
	}
	else
	{
		printf("�������������,�޲�ѯ�����\n");
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
		printf("ѧ��:%10ld ����:%10s ����:",temp[temp2].StuNum,temp[temp2].Name);
		for(j=0;j<ClassCount;j++)
		{
			printf("%3d",temp[temp2].StuScore[j]);
		}
		printf(" �ܷ�:%3d ����:%d\n",temp[temp2].SumScore,temp2+1);
	}
	else
	{
		printf("�����ѧ������,�޲�ѯ�����\n");
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
			printf("��%d�� ����:%02d %.1f%% ����:%02d %.1f%% �е�:%02d %.1f%% ����:%02d %.1f%% ������:%02d %.1f%%\n",i+1,count[i][0],((float)count[i][0]/StuCount)*100,count[i][1],((float)count[i][1]/StuCount)*100,count[i][2],((float)count[i][2]/StuCount)*100,count[i][3],((float)count[i][3]/StuCount)*100,count[i][4],((float)count[i][4]/StuCount)*100);
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
		printf("����:%-10sѧ��:%-10ld����:",stu[i].Name,stu[i].StuNum);
		for(j=0;j<ClassCount;j++)
		{
			printf("%-3d",stu[i].StuScore[j]);
		}
		printf("�ܷ�:%-3dƽ����:%.1f\n",stu[i].SumScore,stu[i].AverScore);
	}
	printf("\n-----------------------------------------------------------\n");
}
void OutputToFile(Student stu[],int StuCount,int ClassCount)
{
	FILE *fp;
	int i,j;
	if((fp=fopen("Student.txt","w"))==NULL)
	{
		printf("���ļ�ʧ�ܣ�");
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
	printf("�ļ�д��ɹ���\n");
	fclose(fp);
	printf("\n-----------------------------------------------------------\n");
}
void InputToFile(Student stu[],int StuCount,int ClassCount)
{
	FILE *fp;
	int i,j;
	if((fp=fopen("Student.txt","r"))==NULL)
	{
		printf("���ļ�ʧ�ܣ�");
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
		printf("����:%-10s ѧ��:%-10ld����:",stu[i].Name,stu[i].StuNum);
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
	printf("1.��ѧ�Ų�ѯѧ���������俼�Գɼ���\n");
	printf("2.��������ѯѧ���������俼�Գɼ���\n");
	printf("0.�˳�\n");
	printf("-----------------------------------------------------------\n");
}