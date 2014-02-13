#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define NUMBER 10
#define MAX 7
#define TURE 1
#define FALSE 0

void askID();
void AskID();
void start();
void Start();
void manage();
void ftguest();
void ftinformation(struct products *);
void ftlist();
void fthistory();
void ftregoods(struct products *);
void ftchose();

FILE*outFile;
FILE*inFile;
FILE*goodsFile;
FILE*listFile;
FILE*intFile;

struct products
{
  char name[20];
  double price;
};

int isvalidInt(char[]);
int isvalidint(char[]);
int store[]={100,100,100,100,100,100,100,100,100,100};
int allnumber[NUMBER],goodslist[1024],goodshistory[1024];
int Papernumber=0;

char *IDnum;
char *Password;
char idnum[MAX];
char password[MAX];
char code[1024];
double allmoney[NUMBER];


int main()
{
  int num;
  char idnum[]="admin";
  char password[]="TurboC";
  IDnum=idnum;
  Password=password;

  outFile=fopen(IDnum,"w+");
  if(outFile==NULL)
  {
    printf("\nFail to open the file.\n");
	getchar();
    exit(1);
  }
   fprintf(outFile,"%-10s %-20s\n",IDnum,Password);
   fclose(outFile);

   char IDnum1[10];
   char Password1[10];
   inFile=fopen(IDnum,"r");
   if(inFile==NULL)
   {
     printf("\nFail to open the file.\n");
	 getchar();
     exit(1);
   }
   while(fscanf(inFile,"%s %s",&IDnum1,&Password1)!=EOF);
   printf("%s %s\n",IDnum1,Password1);

  printf("\nWelcome to our surpermarket!\n(1)Register an ID\n(2)Start\n(3)Exit\n");
  printf("Please enter the number in which the program you want:");
  scanf("%d",&num);
  getchar();

  switch(num)
  {
    case 1:
     askID();
     break;
   case 2:
     Start();
     break;
   case 3:
     exit(1);
     break;
    default:
    printf("\nPlease enter the right number!");
    break;
   }

   return 0;
}

void askID()
{

  int num1;
  printf("\n(1)Ask for an ID.\n(2)Exit\n");
   printf("Please enter the number in which the program you want:");
  scanf("%d",&num1);
  getchar();

  switch(num1)
  {
    case 1:
      AskID();
      break;
    case 2:
      exit(1);
      break;
    default:
      printf("\nPlease enter the right number!");
      break;
   }
}
void AskID()
{
    printf("Now you are going to register an ID!\nThere are some notice,attention please!\n\n");
    printf("(1)You can choose your ID freely.\n\n");
    printf("(2)But the ID must consist of 2 letters and 4 numbers!\nFor example AB1234.\n\n");
    printf("(3)You can set your password freely.\n\n");
    printf("(4)But the password must consist 6 numbers!\nFor example 123456.\n\n");

    printf("Please enter your ID you choose:\n");
    gets(idnum);

    if(isvalidInt(idnum)==TURE)
    {
      printf("Please enter your password you choose:\n");
      gets(password);

      if(isvalidint(password)==TURE)
      {
	    IDnum=idnum;
    	Password=password;

	    outFile=fopen(IDnum,"w+");
        if(outFile==NULL)
        {
	      printf("\nFail to open the file.\n");
	      main();
        }
        fprintf(outFile,"%-10s %-20s\n",IDnum,Password);
        fclose(outFile);

        char IDnum1[10];
        char Password1[10];
        inFile=fopen(IDnum,"r");
        if(inFile==NULL)
        {
	      printf("\nFail to open the file.\n");
	      main();
        }
        while(fscanf(inFile,"%s %s",&IDnum1,&Password1)!=EOF);
        fclose(inFile);
		printf("You have successfully ask an ID!");
		main();
      }
      else
      {printf("You choose the wrong password!");
      askID();}
    }
    else
    {printf("You choose the wrong ID!");
    askID();}
}



int isvalidInt(char id[])
{
  int i;
  int valid=TURE;

  if(id[0]=='\0')
  {valid=FALSE;}

  i=0;
  while(valid==TURE&&i<2)
  {
    if(id[i]<'A'||id[i]>'Z')
    valid=FALSE;
    i++;
  }

  while(valid==TURE&&id[i]!='\0')
  {
    if(id[i]<'0'||id[i]>'9')
    valid=FALSE;
    i++;
  }

  if(i!=6)
  valid=FALSE;

  return valid;
}

int isvalidint(char password1[])
{
  int i;
  int valid=TURE;

  if(password1[0]=='\0')
  {valid=FALSE;}

  i=0;

  while(valid==TURE&&password1[i]!='\0')
  {
    if(password1[i]<'0'||password1[i]>'9')
    valid=FALSE;
    i++;
  }

  if(i!=6)
  valid=FALSE;

  return valid;
}


void Start()
{

  int num2;
  printf("\n(1)ID and password identify.\n(2)Manager ID identify.\n(3)Exit\n");
   printf("Please enter the number in which the program you want:");
  scanf("%d",&num2);
  getchar();

  switch(num2)
  {
    case 1:
      start();
      break;
    case 2:
      manage();
      break;
    case 3:
      exit(1);
      break;
    default:
      printf("\nPlease enter the right number!");
      break;
   }
}

void start()
{
   printf("Please enter your ID:\n");
   gets(idnum);

       
   if(isvalidInt(idnum)==TURE)
   {
      printf("Please enter your password you choose:\n");
      gets(password);

      if(isvalidint(password)==TURE)
      {
        IDnum=idnum;
        char IDnum1[10];
        char Password1[10];
        inFile=fopen(IDnum,"r");
        if(inFile==NULL)
        {
	      printf("\nFail to open the file.\n");
		  getchar();
	      main();
        }
        while(fscanf(inFile,"%s %s",&IDnum1,&Password1)!=EOF);
        printf("%10s %10s\n",IDnum1,Password1);
        fclose(inFile);

	int j;
	for(j=0;j<7;j++)
          {	 
             if(password[j]!=Password1[j])
             {printf("You password is wrong,please type again!");
              Start();}
		  } 

		printf("You are success!!");
		ftguest();
		printf("cichudiaoyong!!");
	  }
	  else
	  {printf("Please type the password,it has 6 numbers!");
	  Start();}
   }
   else
   {printf("Please type the IDnum,it has 2 letters and 4 numbers!");
    Start();}
}

void manage()
{
   printf("Please enter your ID:\n");
   gets(idnum);
   printf("Please enter your password:\n");
   gets(password);
   IDnum=idnum;
   char IDnum1[10];
   char Password1[10];
   inFile=fopen(IDnum,"r");
   if(inFile==NULL)
   {
     printf("\nFail to open the file.\n");
	 getchar();
     main();
   }
   while(fscanf(inFile,"%s %s",&IDnum1,&Password1)!=EOF);
   printf("%10s %10s\n",IDnum1,Password1);
   fclose(inFile);

   int j;
   for(j=0;j<7;j++)
   {
      if(password[j]!=Password1[j])
      {printf("You password is wrong,please type again!");
       Start();}
    }

    printf("You are boss!");


}

void ftguest()
{
  char i;
  int w,v;


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

do
{
printf("\nMain Menu:\nA.Purchase Product\nB.Print The Goods List\nC.Look For History\nD.Return The Goods\nE.Return To Upper Menu\n");
    scanf("%c",&i);
    switch(i)
	{
     case 'A':
	  ftinformation(information);
	  break;
     case 'B':
	  ftlist();
	  break;
     case 'C':
	  fthistory();
	  break;
     case 'D':
	  ftregoods(information);
	  break;
     case 'E':
	  main();
	  break;
     default:
	  printf("You input the wrong letter.");
	}
}while(i!='A'&&i!='B'&&i!='C'&&i!='D'&&i!='E');
}

void ftinformation(struct products information1[])
{
 int n,j,t;
 double k,s;
 char sttime[20],kind[9]="Purchase";
 int goods,goodsnumber;

 time_t timep;
 time(&timep);

    printf("\nProduct information:\n\n");
      for(n=0;n<NUMBER;n++)
	printf("%-20s%9.2f\n",
	       information1[n].name,information1[n].price);
	printf("10.Exit");
    Papernumber++;

	printf("\nPlease Choose Your Goods(enter the number of the goods and how many you want):\n");
	do
    {
	printf("\nGoods NO.:");
	scanf("%d",&goods);
	printf("\nHow Many:");
	scanf("%d",&goodsnumber);

	j=goodsnumber;
	s=information1[goods].price;
	k=j*s;
	allnumber[goods]=allnumber[goods]+goodsnumber;
	allmoney[goods]=allmoney[goods]+goodsnumber*information1[goods].price;
	
	intFile=fopen("allnumber","w");
	if(intFile==NULL)
	{
		printf("\nFailed to open the file.\n");
	    getchar();
		main();
	}
	else
	{	
		for(t=0;t<NUMBER;t++)
		fprintf(intFile,"%d",allnumber[t]);
	}
	fclose(intFile);
    intFile=fopen("allmoney","w");
	if(intFile==NULL)
	{
		printf("\nFailed to open the file.\n");
		getchar();
		main();
	}
	else
	{	
		for(s=0;s<NUMBER;s++)
		fprintf(intFile,"%d",allmoney[s]);
	}
	fclose(intFile);

	strcpy(sttime,asctime(gmtime(&timep)));

	goodsFile=fopen(idnum,"a");
	if(goodsFile==NULL)
	{
	    printf("\nFailed to open the file.\n");
		getchar();
		main();
	}
	else
	  fprintf(goodsFile,"%-7s %-9d %-15s %-10d %-6.2lf %9.2lf\n%s\n",
	       kind,Papernumber,information1[goods].name,j,information1[goods].price,k,sttime);
	fclose(goodsFile);
	getchar();

	goodslist[Papernumber]=Papernumber;
	itoa(goodslist[Papernumber],code,10);
	listFile=fopen(code,"a");
	if(listFile==NULL)
	{
	  printf("\nFailed to open the file.\n");
	  getchar();
	  main();
	}
	else
	  fprintf(listFile,"%-7s %-9d %-15s %-10d %-6.2lf %9.2lf\n%s\n",
			   kind,Papernumber,information1[goods].name,j,information1[goods].price,k,sttime);
	fclose(listFile);
	getchar();

    }while(goods<=9&&goods>=0&&goodsnumber>=0);

    ftchose();
}


void ftlist()
{
	char line1[10000];

	listFile=fopen(code,"r");
		if(listFile==NULL)
		{
	      printf("\nSorry,you don't have a list.\n");
	      getchar();
	      main();
		}
		else
		{
	      printf("\nYour Last Goods List:");
	      printf("\nService PaperNO.  Name          How Many  Price(Per)  Total Price\n");
	      while(fgets(line1,10000,goodsFile)!=NULL)
	      printf("%s",line1);
		}
	fclose(listFile);
  
	ftchose();
}

void fthistory()
{    
	char line[10000];

	printf("Service PaperNO.  Name          How Many  Price(Per)  Total Price\n");
	goodsFile=fopen(idnum,"r");
	if(goodsFile==NULL)
	{
	  printf("\nSorry,you don't have a list.\n");
	  getchar();
	  main();
	}
	else
	{
	  while(fgets(line,10000,goodsFile)!=NULL)
	  printf("%s",line);
	}
	fclose(goodsFile);

	ftchose();
}

void ftregoods(struct products information2[])
{
	char textcode[1024],recode[1024],reIDcode[1024],resttime[20],rekind[9]="Return",line2[10000];
    int regoods,regoodsnumber;
    int rej,l,p,q;
    double rek,res;
	time_t retimep;
    time(&retimep);

	printf("Please input your list number\n");
	scanf("%d",l);
    itoa(l,textcode,10);
	listFile=fopen(textcode,"r");
	if(listFile==NULL)
	{
	    printf("\nSorry,you don't have a list.\n");
		getchar();
		main();
	}
    else
	  {
	    printf("Service PaperNO.  Name          How Many  Price(Per)  Total Price\n");
	    while(fgets(line2,10000,listFile)!=NULL)
	    printf("%s",line2);	  

	    printf("Now,please input the number of what you want to return and how many.\n");
        do
		{
	      printf("\nGoods NO.:");
	      scanf("%d",&regoods);
	      printf("\nHow Many:");
	      scanf("%d",&regoodsnumber);

	      rej=regoodsnumber;
	      res=information2[regoods].price;
	      rek=rej*res;
	      allnumber[regoods]=allnumber[regoods]-regoodsnumber;
	      allmoney[regoods]=allmoney[regoods]-regoodsnumber*information2[regoods].price;

	      intFile=fopen("allnumber","w");
	      if(intFile==NULL)
		  {
		   printf("\nFailed to open the file.\n");
		   getchar();
		   main();
		  }
	      else
		  {	
		   for(p=0;p<NUMBER;p++)
		   fprintf(intFile,"%d",allnumber[p]);
		  }
	      fclose(intFile);
          intFile=fopen("allmoney","w");
	      if(intFile==NULL)
		  {
		  printf("\nFailed to open the file.\n");
		  getchar();
		  main();
		  }
	      else
		  {	
		   for(q=0;q<NUMBER;q++)
		   fprintf(intFile,"%d",allmoney[q]);
		  }
	      fclose(intFile);

          strcpy(resttime,asctime(gmtime(&retimep)));

	      itoa(goodshistory[l],reIDcode,10);
	      goodsFile=fopen(reIDcode,"a");
	      if(goodsFile==NULL)
		  {
	        printf("\nFailed to open the file.\n");
			getchar();
			main();
		  }
	      else
	        fprintf(goodsFile,"%-7s %-9d %-15s %-10d %-6.2lf %9.2lf\n%s\n",
	                rekind,l,information2[regoods].name,rej,information2[regoods].price,rek,resttime);
	      fclose(goodsFile);

	      itoa(goodslist[l],recode,10);
	      listFile=fopen(recode,"a");
	      if(listFile==NULL)
		  {
	       printf("\nFailed to open the file.\n");
		   getchar();
		   main();
		  }
	      else
	      fprintf(listFile,"%-7s %-9d %-15s %-10d %-6.2lf %9.2lf\n%s\n",
			    rekind,l,information2[regoods].name,rej,information2[regoods].price,rek,resttime);
	      fclose(listFile);
		}while(regoods<=9&&regoods>=0&&regoodsnumber>=0);
	  }
	fclose(listFile); 
    ftchose();   
}
  


void ftchose()
{
  int key;
  
  do
  {
  printf("\n1.Return to upper menu.\n2.Exit\n");
  scanf("%d",&key);
  getchar();
    switch(key)
	{
	case 1:
	  ftguest();
	  break;
	case 2:
	  exit(1);
	  break;
    default:
	  printf("You input the wrong number.");
	}
  }while(key!=1&&key!=2);
}

