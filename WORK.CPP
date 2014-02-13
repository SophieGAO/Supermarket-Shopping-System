#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define NUMBER 10

int store[]={100,100,100,100,100,100,100,100,100,100};
void ftinformation();
void ftlist();
void fthistory();
void ftregoods();
void ftchose();

struct products
{
  char name[20];
  double price;
};

int main()
{
  char A,B,C,i,skey,fkey,tkey,tkey1,tkey2,tkey3,tkey4;
  char sttime[20],code[1024],IDcode[1024],textcode[1024],recode[1024],reIDcode[1024];
  int n,j,rej,w,v,p,l,chose,chose1,chose2,chose3,chose4,goods,goodsnumber,regoods,regoodsnumber;
  int allnumber[NUMBER];
  double allmoney[NUMBER];
  double k,s,rek,res;
  FILE*goodsFile;
  FILE*listFile;
  int Papernumber=0;
  int goodslist[1024];
  int goodshistory[1024];

  struct products information[NUMBER]={{"0.Pen",50.00},
				     {"1.Pencil",0.50},
				     {"2.Shampoo",24.80},
				     {"3.Bush",13.00},
				     {"4.Bow",5.28},
				     {"5.Cup",4.90},
				     {"6.Nail Polish",60.00},
				     {"7.Toothbrash",14.80},
				     {"8.Mirror",10.00},
				     {"9.Television",4999.98}
				    };

  for(w=0;w<NUMBER;w++)
    allnumber[w]=0;
  for(v=0;v<NUMBER;v++)
    allmoney[v]=0.00;

  printf("\nMain Menu:\nA.Product Information\nB.Print The Goods List\nC.Look For History\nD.Return The Goods\nE.Return To Upper Menu\n");
    scanf("%c",&i);
    

return 0;
}

void ftinformation()
{
 
 time_t timep;
 time(&timep);

    printf("\nProduct information:\n\n");
      for(n=0;n<NUMBER;n++)
	printf("%-20s%9.2f\n",
	       information[n].name,information[n].price);
	printf("10.Exit")
    Papernumber++;
   
	printf("\nPlease Choose Your Goods(enter the number of the goods and how many you want):\nFor Example:\n1(Pencil)\n5");
	do
    {
	scanf("%d%d",&goods,&goodsnumber);

	j=goodsnumber;
	s=information[goods].price;
	k=j*s;
	allnumber[goods]=allnumber[goods]+goodsnumber;
	allmoney[goods]=allmoney[goods]+goodsnumber*information[goods].price;

	sttime=asctime(gmtime(&timep))

	goodshistory[Papernumber]=Papernumber;
	itoa(goodshistory[Papernumber],IDcode,10);
	goodsFile=fopen(IDcode,"a");
	if(goodsFile==NULL)
	    printf("\nFailed to open the file.\n");
	else
	  fprintf(goodsFile,"%d %s %d %lf %lf\n%s\n",
	       Papernumber,information[goods].name,j,information[goods].price,k,sttime);
	fclose(goodsFile);
	getchar();

	goodslist[Papernumber]=Papernumber;
	itoa(goodslist[Papernumber],code,10);
	listFile=fopen(code,"a");
	if(listFile==NULL)
	  printf("\nFailed to open the file.\n");
	else
	  fprintf(listFile,"%d %s %d %lf %lf\n%s\n",
			   Papernumber,information[goods].name,j,information[goods].price,k,sttime);
	fclose(listFile);
	getchar();

    }while(goods<=9&&goods>=0);

    ftchose();
}

void ftlist()
{
	listFile=fopen(code,"r");
		if(listFile==NULL)
	  printf("\nSorry,you don't have a list.\n");
		else
		{
	printf("\nYour Last Goods List:");
	printf("\nPaperNO.  Name          How Many  Price(Per)  Total Price\n");
    fscanf(listFile,"%d %s %d %lf %lf %s\n",
	     &Papernumber,information[goods].name,&j,&information[goods].price,&k,sttime);
	  printf("%-9d %-15s %-10d %-6.2lf %9.2lf\n%s\n",
		Papernumber,information[goods].name,j,information[goods].price,k,sttime);
        }
	fclose(listFile);
  
	ftchose();
}

void fthistory()
{    
	printf("PaperNO.  Name          How Many  Price(Per)  Total Price\n");
	goodsFile=fopen(IDcode,"r");
	if(goodsFile==NULL)
	printf("\nSorry,you don't have a list.\n");
	else
	{
	  fscanf(goodsFile,"%d %s %d %lf %lf %s\n",
	     Papernumber,information[goods].name,j,information[goods].price,k,sttime);
	  printf("%-9d %-15s %-10d %-6.2lf %9.2lf\n%s\n",
		Papernumber,information[goods].name,j,information[goods].price,k,sttime);
	}
	fclose(goodsFile);

	ftchose();
}

void ftregoods()
{
	printf("Please input your list number\n");
	scanf("%d",l);
	itoa(l,textcode,10);
	listFile=fopen(textcode,"r");
	if(listFile==NULL)
	  printf("\nSorry,you don't have a list.\n");
	else
	{
	  fscanf(listFile,"%d %s %d %lf %lf %s\n",
	     l,information[goods].name,rej,information[goods].price,rek,sttime);
	  printf("%-9d %-15s %-10d %-6.2lf %9.2lf\n%s\n",
		l,information[goods].name,rej,information[goods].price,rek,sttime);
	}
	fclose(listFile);

	printf("Now,please input the number of what you want to return and how many.\nFor Example:\n1(Pencil)\n5\nWarning:You can just return one kind of the goods.\n");
	scanf("%d%d",&regoods,&regoodsnumber);

	rej=regoodsnumber;
	res=information[goods].price;
	rek=rej*res;
	allnumber[goods]=allnumber[goods]-regoodsnumber;
	allmoney[goods]=allmoney[goods]+regoodsnumber*information[goods].price;

	itoa(goodshistory[l],reIDcode,10);
	goodsFile=fopen(reIDcode,"a");
	if(goodsFile==NULL)
	  {
	    printf("\nFailed to open the file.\n");
	  }
	else
	  fprintf(goodsFile,"%d %s %d %lf %lf\n%s\n",
	       l,information[goods].name,rej,information[goods].price,rek,asctime(gmtime(&timep)));
	fclose(goodsFile);
	getchar();

	itoa(goodslist[l],recode,10);
	listFile=fopen(recode,"a");
	if(listFile==NULL)
	{
	  printf("\nFailed to open the file.\n");
	}
	else
	  fprintf(listFile,"%-9d %-15s %-10d %-6.2lf %9.2lf\n%s\n",
			   l,information[goods].name,rej,information[goods].price,rek,asctime(gmtime(&timep)));
	fclose(listFile);
    
	ftchose();     
}

void ftchose()
{
do
  {
  printf("\n1.Return to upper menu.\n2.Exit");
  scan("%d",key);
    switch(key1)
	{
     case 1;
	  main();
	  break;
     case 2;
	  exit(1);
	  break;
     default:
	  printf("You input the wrong number.");
	}
  } while(key1!=1&&key1!=2)
}