#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TranficPunishBill
 {
	char carNo[10];    //车牌号
	char driverNo[20];  //驾照号
	char policeNo[10];  //开单交警号码
	char billNo[20];   //处罚单号码
	char time[12];  //处罚时间（yyyymmddhhmm,年月日时分）
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
	printf("请输入要登录的对象(1.交警2.司机):");
	scanf("%d",&inform);
	if(inform==1)
	{
		while(1)
		{
	
			PrintMenue();
			printf("请输入菜单序号以选择相应项目:\n");
			yet=scanf("%d",&menuenum);
			while(yet==0||menuenum<0||menuenum>5)
			{
				getchar();
				printf("菜单序号输入有误!请重新输入:\n");
				yet=scanf("%d",&menuenum);
			}
			printf("----------------------------------------------------------------------------\n");
			if(menuenum==1)
			{
				char ch='Y';
			    while(ch=='Y'||ch=='y')
			    {
			        InputToFile();
			        printf("是否继续输入？(Y/N)\n");
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
				printf("欢迎下次使用！\n");
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
			printf("请输入菜单序号以选择相应项目:\n");
			yet_s=scanf("%d",&menuenum_s);
			while(yet_s==0||menuenum_s<0||menuenum_s>5)
			{
				getchar();
				printf("菜单序号输入有误!请重新输入:\n");
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
				printf("欢迎下次使用！\n");
				printf("----------------------------------------------------------------------------\n");
				return 0;
			}
		}
	}
}
void PrintMenue()
{ 
	printf("                                   交通罚单管理系统交警端V2.0\n");
	printf("1.输入\n");
	printf("2.删除罚单\n");
	printf("3.浏览所有罚单\n");
	printf("4.罚单查询\n");
	printf("5.驾驶员违章统计\n");
	printf("0.退出\n");
	printf("----------------------------------------------------------------------------\n");
}
void PrintMenue_s()
{
	printf("                                   交通罚单管理系统司机端V2.0\n");
	printf("1.驾驶员违章统计\n");
	printf("2.罚单查询\n");
	printf("0.退出\n");
	printf("----------------------------------------------------------------------------\n");
}
int LineOfFile()
{
	FILE *fp;
	int count=0,i=0;
	TPB temp[100];
	if((fp=fopen("TPB.txt","rb"))==NULL)
	{
		printf("文件打开失败!\n");

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
	printf("请输入车牌号、驾照号、开单交警号码、处罚单号码、处罚单时间:\n");
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
		printf("文件打开有误!\n");
		exit(0);
	}
	fprintf(fp,"%-10s%-20s%-10s%-20s%-12s",temp.carNo,temp.driverNo,temp.policeNo,temp.billNo,temp.time);
	fprintf(fp,"\n");
	printf("信息写入成功!\n");
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
		printf("文件打开有误!\n");
		exit(0);
	}
	for(i=0;i<row;i++)
	{
		if((i+1)%10==0)
		{
			printf("按任意键跳转到下一页!\n");
			getchar();
			getchar();
		}
		fscanf(fp,"%10s%20s%10s%20s%12s",&temp[i].carNo,&temp[i].driverNo,&temp[i].policeNo,&temp[i].billNo,temp[i].time);
		printf("车牌号:%-10s驾照号:%-20s开单交警号:%-10s罚单号码:%-20s罚单时间:%-12s\n",temp[i].carNo,temp[i].driverNo,temp[i].policeNo,temp[i].billNo,temp[i].time);
	}
	fclose(fp);
}
void DeleteFile()
{
    int i,flag=0;
	char srctemp[20];
	printf("请输入要删除的罚单号:");
	getchar();
	gets(srctemp);
	FILE *fp,*tp,*wp;
	if((fp=fopen("TPB.txt","r"))==NULL)
    {
        printf("文件读取失败！\n");
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
        printf("文件删除成功！\n");
    }
    else
    {
        printf("文件删除失败！\n");
    }
}
void SearchIntoFile()
{
	int row=LineOfFile(),i,yet;
	FILE *fp;
	TPB temp[row];
	char strtemp[20];
	int num,flag=0;
	printf("1.查询车牌号\n");
 	printf("2.查询驾照号\n");
	printf("3.查询开单交警号\n");
	yet=scanf("%d",&num);
	while(yet==0||num<1||num>3)
	{
		printf("输入的序号有误,请重新输入:");
		getchar();
		yet=scanf("%d",&num);
	}
	getchar();
	printf("请输入要查询的内容:");
	gets(strtemp);
	if((fp=fopen("TPB.txt","rb"))==NULL)
	{
		printf("文件打开有误!\n");
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
		printf("车牌号:%-10s驾照号:%-20s开单交警号:%-10s罚单号码:%-20s罚单时间:%-12s\n",temp[i].carNo,temp[i].driverNo,temp[i].policeNo,temp[i].billNo,temp[i].time);
	else
		printf("输入信息有误,未查找到!\n");
}
void MessageStatistics()
{
	char temp1[20];
	char temp2[20];
	char temp3[20];
	int row=LineOfFile(),i,count=0;
	TPB temp[row];
	FILE *fp;
	printf("请输入要查询的驾照号:\n");
	getchar();
	gets(temp1);
	printf("请输入要查询的时间段:\n");
	gets(temp2);
	gets(temp3);
	if((fp=fopen("TPB.txt","rb"))==NULL)
	{
		printf("文件打开有误!\n");
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
				printf("罚单号为:%-20s\n",temp[i].billNo);
			}
		}
	}
	fclose(fp);
	printf("共%d条处罚记录\n",count);
}