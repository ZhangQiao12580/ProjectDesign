#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TranficPunishBill
 {
	char carNo[10];    //���ƺ�
	char driverNo[20];  //���պ�
	char policeNo[10];  //������������
	char billNo[20];   //����������
	char time[12];  //����ʱ�䣨yyyymmddhhmm,������ʱ�֣�
}TPB;
void InputToFile();
void OutputToScreen();
void DeleteFile();
void SearchIntoFile();
void MessageStatistics();
void PrintMenue();
void PrintMenue_s();
int LineOfFile();
int main()
{
	int inform;
	int yet,menuenum;
	int yet_s,menuenum_s; 
	printf("������Ҫ��¼�Ķ���(1.����2.˾��):");
	scanf("%d",&inform);
	if(inform==1)
	{
		while(1)
		{
	
			PrintMenue();
			printf("������˵������ѡ����Ӧ��Ŀ:\n");
			yet=scanf("%d",&menuenum);
			while(yet==0||menuenum<0||menuenum>5)
			{
				getchar();
				printf("�˵������������!����������:\n");
				yet=scanf("%d",&menuenum);
			}
			printf("----------------------------------------------------------------------------\n");
			if(menuenum==1)
			{
				char ch='Y';
			    while(ch=='Y'||ch=='y')
			    {
			        InputToFile();
			        printf("�Ƿ�������룿(Y/N)\n");
			        scanf("%c",&ch);
			    }
	  	        printf("----------------------------------------------------------------------------\n");
			}
			else if(menuenum==2)
			{
				DeleteFile();
				printf("----------------------------------------------------------------------------\n");
			}
			else if(menuenum==3)
			{
				OutputToScreen();
				printf("----------------------------------------------------------------------------\n");
			}
			else if(menuenum==4)
			{
	
				SearchIntoFile();
				printf("----------------------------------------------------------------------------\n");
			}
			else if(menuenum==5)
			{
				MessageStatistics();
				printf("----------------------------------------------------------------------------\n");
			}
			else
			{
				printf("��ӭ�´�ʹ�ã�\n");
				printf("----------------------------------------------------------------------------\n");
				return 0;
			}
		}
	} 
	else
	{
		while(1)
		{
	
			PrintMenue_s();
			printf("������˵������ѡ����Ӧ��Ŀ:\n");
			yet_s=scanf("%d",&menuenum_s);
			while(yet_s==0||menuenum_s<0||menuenum_s>5)
			{
				getchar();
				printf("�˵������������!����������:\n");
				yet=scanf("%d",&menuenum_s);
			}
			printf("----------------------------------------------------------------------------\n");
			if(menuenum_s==2)
			{
				SearchIntoFile();
			}
			else if(menuenum_s==1)
			{
				MessageStatistics();
			}
			else if(menuenum_s==0)
			{
				printf("��ӭ�´�ʹ�ã�\n");
				printf("----------------------------------------------------------------------------\n");
				return 0;
			}
		}
	}
}
void PrintMenue()
{ 
	printf("                                   ��ͨ��������ϵͳ������V2.0\n");
	printf("1.����\n");
	printf("2.ɾ������\n");
	printf("3.������з���\n");
	printf("4.������ѯ\n");
	printf("5.��ʻԱΥ��ͳ��\n");
	printf("0.�˳�\n");
	printf("----------------------------------------------------------------------------\n");
}
void PrintMenue_s()
{
	printf("                                   ��ͨ��������ϵͳ˾����V2.0\n");
	printf("1.��ʻԱΥ��ͳ��\n");
	printf("2.������ѯ\n");
	printf("0.�˳�\n");
	printf("----------------------------------------------------------------------------\n");
}
int LineOfFile()
{
	FILE *fp;
	int count=0,i=0;
	TPB temp[100];
	if((fp=fopen("TPB.txt","rb"))==NULL)
	{
		printf("�ļ���ʧ��!\n");

	}
	while(fscanf(fp,"%10s%20s%10s%20s%12s",&temp[i].carNo,&temp[i].driverNo,&temp[i].policeNo,&temp[i].billNo,&temp[i].time)!=EOF)
	{
		i++;
		count++;
	}
	return count;
}
void InputToFile()
{
	FILE *fp;
	TPB temp;
	printf("�����복�ƺš����պš������������롢���������롢������ʱ��:\n");
	scanf("%s",&temp.carNo);
	getchar();
	scanf("%s",&temp.driverNo);
	getchar();
	scanf("%s",&temp.policeNo);
	getchar();
	scanf("%s",&temp.billNo);
	getchar();
	scanf("%s",&temp.time);
	getchar();
	if((fp=fopen("TPB.txt","ab"))==NULL)
	{
		printf("�ļ�������!\n");
		exit(0);
	}
	fprintf(fp,"%-10s%-20s%-10s%-20s%-12s",temp.carNo,temp.driverNo,temp.policeNo,temp.billNo,temp.time);
	fprintf(fp,"\n");
	printf("��Ϣд��ɹ�!\n");
	fclose(fp);
}
void OutputToScreen()
{
	FILE *fp;
	TPB temp[100];
	int i;
	int row=LineOfFile();
	if((fp=fopen("TPB.txt","rb"))==NULL)
	{
		printf("�ļ�������!\n");
		exit(0);
	}
	for(i=0;i<row;i++)
	{
		if((i+1)%10==0)
		{
			printf("���������ת����һҳ!\n");
			getchar();
			getchar();
		}
		fscanf(fp,"%10s%20s%10s%20s%12s",&temp[i].carNo,&temp[i].driverNo,&temp[i].policeNo,&temp[i].billNo,temp[i].time);
		printf("���ƺ�:%-10s���պ�:%-20s����������:%-10s��������:%-20s����ʱ��:%-12s\n",temp[i].carNo,temp[i].driverNo,temp[i].policeNo,temp[i].billNo,temp[i].time);
	}
	fclose(fp);
}
void DeleteFile()
{
    int i,flag=0;
	char srctemp[20];
	printf("������Ҫɾ���ķ�����:");
	getchar();
	gets(srctemp);
	FILE *fp,*tp,*wp;
	if((fp=fopen("TPB.txt","r"))==NULL)
    {
        printf("�ļ���ȡʧ�ܣ�\n");
        exit(0);
    }
    TPB temp[100];
    int len=LineOfFile();
    for(i=0;i<len;i++)
    {
        fscanf(fp,"%10s%20s%10s%20s%12s",&temp[i].carNo,&temp[i].driverNo,&temp[i].policeNo,&temp[i].billNo,temp[i].time);
    }
    fclose(fp);
    tp=fopen("TPB.txt","w");
    fclose(tp);
    wp=fopen("TPB.txt","w");
    for(i=0;i<len;i++)
    {
        if(strcmp(temp[i].billNo,srctemp)==0)
        {
            flag=1;
            continue;
        }
        else
        {
            fprintf(wp,"%-10s%-20s%-10s%-20s%-12s",temp[i].carNo,temp[i].driverNo,temp[i].policeNo,temp[i].billNo,temp[i].time);
        }
    }
    fclose(wp);
    if(flag==1)
    {
        printf("�ļ�ɾ���ɹ���\n");
    }
    else
    {
        printf("�ļ�ɾ��ʧ�ܣ�\n");
    }
}
void SearchIntoFile()
{
	int row=LineOfFile(),i,yet;
	FILE *fp;
	TPB temp[row];
	char strtemp[20];
	int num,flag=0;
	printf("1.��ѯ���ƺ�\n");
 	printf("2.��ѯ���պ�\n");
	printf("3.��ѯ����������\n");
	yet=scanf("%d",&num);
	while(yet==0||num<1||num>3)
	{
		printf("������������,����������:");
		getchar();
		yet=scanf("%d",&num);
	}
	getchar();
	printf("������Ҫ��ѯ������:");
	gets(strtemp);
	if((fp=fopen("TPB.txt","rb"))==NULL)
	{
		printf("�ļ�������!\n");
		exit(0);
	}
	for(i=0;i<row;i++)
	{
		fscanf(fp,"%10s%20s%10s%20s%12s",&temp[i].carNo,&temp[i].driverNo,&temp[i].policeNo,&temp[i].billNo,temp[i].time);
		if(num==1)
		{
			if(strcmp(temp[i].carNo,strtemp)==0)
			{
				flag=1;
				break;
			}
		}
		else if(num==2)
		{
			if(strcmp(temp[i].driverNo,strtemp)==0)
			{
				flag=1;
				break;
			}
		}
		else if(num==3)
		{
			if(strcmp(temp[i].policeNo,strtemp)==0)
			{
				flag=1;
				break;
			}
		}
	}
	fclose(fp);
	if(flag==1)
		printf("���ƺ�:%-10s���պ�:%-20s����������:%-10s��������:%-20s����ʱ��:%-12s\n",temp[i].carNo,temp[i].driverNo,temp[i].policeNo,temp[i].billNo,temp[i].time);
	else
		printf("������Ϣ����,δ���ҵ�!\n");
}
void MessageStatistics()
{
	char temp1[20];
	char temp2[20];
	char temp3[20];
	int row=LineOfFile(),i,count=0;
	TPB temp[row];
	FILE *fp;
	printf("������Ҫ��ѯ�ļ��պ�:\n");
	getchar();
	gets(temp1);
	printf("������Ҫ��ѯ��ʱ���:\n");
	gets(temp2);
	gets(temp3);
	if((fp=fopen("TPB.txt","rb"))==NULL)
	{
		printf("�ļ�������!\n");
		exit(0);
	}
	for(i=0;i<row;i++)
	{
		fscanf(fp,"%10s%20s%10s%20s%12s",&temp[i].carNo,&temp[i].driverNo,&temp[i].policeNo,&temp[i].billNo,temp[i].time);
		if(strcmp(temp1,temp[i].driverNo)==0)
		{
			long numtemp=(long)temp3;
			long numtemp1=(long)temp[i].driverNo;
			if(strcmp(temp[i].driverNo,temp2)>=0&&numtemp1<=numtemp1)//strcmp(temp[i].driverNo,temp3)<0)
			{
				count++;
				printf("������Ϊ:%-20s\n",temp[i].billNo);
			}
		}
	}
	fclose(fp);
	printf("��%d��������¼\n",count);
}