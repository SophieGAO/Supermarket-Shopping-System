#include<stdio.h>
#include<stdlib.h>
#define MAX 7
#define TURE 1
#define FALSE 0
void askID();
void AskID();
void start();
void Start();
int isvalidInt(char[]);
int isvalidint(char[]);
FILE*outFile;
FILE*inFile;
char *IDnum;
char *Password;
char idnum[MAX];
char password[MAX];

int main()
{
  int num;
  printf("Welcome to our surpermarket!\n(1)Register an ID\n(2)Start\n(3)Exit\n");
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
	      exit(1);
        }
        while(fscanf(inFile,"%s %s",&IDnum1,&Password1)!=EOF);
        printf("%10s %10s\n",IDnum1,Password1);
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
  printf("\n(1)ID and password identify.\n(2)Exit\n");
   printf("Please enter the number in which the program you want:");
  scanf("%d",&num2);
  getchar();

  switch(num2)
  {
    case 1:
      start();
      break;
    case 2:
      exit(1);
      break;
    default:
      printf("\nPlease enter the right number!");
      break;
   }
}

void start()
{
   printf("Please enter your ID!\n");
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
	      exit(1);
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
	  }
	  else
	  {printf("Please type the password,it has 6 numbers!");
	  Start();}
   }
   else
   {printf("Please type the IDnum,it has 2 letters and 4 numbers!");
    Start();}
}



