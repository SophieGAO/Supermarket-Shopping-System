#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  FILE *outFile;
  FILE *inFile;
  /*diaoyong struct*/
  char *name[]={"pen",
		"pencil",
		"shanpoo",
		"bush",
		"cup",
		"bow",
		"neck",
		"toothbrush",
		"mirror",
		"TV"};
  double inprice[]={32.00,0.20,12.40,8.50,2.12,1.90,52.80,6.80,7.58,2499.98};
  double price[]={50.00,0.50,24.80,13.00,5.28,4.90,60.00,14.80,10.00,4999.98};

  int number[]={100,100,100,100,100,100,100,100,100,100};

  /*diaoyong outgoods*/
  outFile=fopen("prices.dat","w");

  if(outFile==NULL)
  {
    printf("\nFailed to open the file.\n");
    exit(1);
  }
  for(i=0;i<10;i++)
    fprintf(outFile,"%-10s %-20.2f %-30.2f %-40.2d\n",name[i],inprice[i],price[i],number[i]);
  fclose(outFile);

  double total;
  char name1[10];
  double price1,inprice1;
  int number1;
    inFile=fopen("prices.dat","r");
    if (inFile==NULL)
    {
      printf("\nFailed to open the file.\n");
      exit(1);
    }
     total=0;
     int j;
     j=0;
     double price2[10];
    while (fscanf(inFile,"%s %lf %lf %d",name1,&inprice1,&price1,&number1)!=EOF)
     { printf("%9s %5.2f %5.2f %5d\n",name1,inprice1,price1,number1);
       price2[j]=price1;
       j++;
      total=total+price1;}

      printf("The total money is %lf\n",total);
      for(j=0;j<10;j++)
      {

	printf("%lf\n",price2[j]);
      }
      double A,B;
      int k=0;
      A=price2[0];
      for(j=0;j<10;j++)
      {
	if(price2[j+1]>price2[j])
	{
	  A=price[j+1];
	  k=j+1;
	}
      }
	 printf("%s\n",name[k]);
	 printf("The highest price is %lf\n",A);

       B=price2[9];
       int g=0;
       for(j=9;j>0;j--)
      {
	if(price2[j-1]<price2[j])
	{
	  B=price[j-1];
	  g=j-1;
	}
      }
       printf("%s\n",name[g]);
       printf("The lowest price is %lf\n",B);


  double tem;
  int n=10;

  for(j=0;j<n-1;j++)
  {
    i=j;
    for(k=j+1;k<n;k++)
    {
      if(price[i]>price[k])
      i=k;
    }

    if(i!=j)
    {
      tem=price[i];price[i]=price[j];price[j]=tem;
    }
  }
  for(i=0;i<10;i++)
  {
    printf("%10s",name[i]);
    printf("%10.2lf\n",price[i]);
  }

      fclose(inFile);

  return 0;
}