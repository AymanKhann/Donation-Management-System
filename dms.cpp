#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

//GLOBALLY DECLARED FUNCTIONS
void main_menu();
void calculate();
void add();
void list();
void edit();
void delete1();
void search();

//DELAY FUNCTION
void delay(unsigned int mseconds)  // milliseconds
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//GO TO SOME VALUE OF X AND Y ON CONSOLE OUTPUT FUNCTION
void gotoxy(int x, int y)//function used for cursor positioning
{
	COORD CR;   //CCORD predefinied struct
	CR.X=x;
	CR.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CR);
}

//SET FONT COLOR FUNCTION
void setcolor(int ForgC)  //for ground color
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);

}
}

//LOGIN TO THE APPLICATION FUNCTION
void login() {
	int attempts=0,length=0;
    char uname[20],c;
    char pword[20];
    char user[10]="user";
    char pass[10]="pass";
    do
{
setcolor(13);
    printf("\n\n\n  **************************  FOR FURTHER INGRESS  **************************  ");
    printf("\n\n\n                                ENTER USERNAME:-");
	scanf("%s",&uname);
	printf("\n\n\n                                ENTER PASSWORD:-");
	while((c=getch())!=13){
		if(c==8){
			if(length>0){
			printf("\b \b");
			length--;
		}
		}
		else {
			pword[length++]=c;
			printf("*");
		}
	}
	pword[length]='\0';

	length=0;

    if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       ADMITTANCE IS ASSURED ! ");
	printf("\n\n\n\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n\n\n      ACCESS IS DENIED ! ");
		printf("\n\n Note : Username or Password you entered is invalid. ");
		attempts++; //attempt count +1
        printf("\nEnter any key to re-try!");
		getch();//holds the screen

	}
}while(attempts<=2);
	if (attempts>2)
	{
		printf("\n\n CAUTION : Attempt to login is invalidate 3 times.");
		printf("\n\nPress any key to terminate program");
		getch();
		system("cls");
		printf("The program is being terminated...");
		delay(2000);
		printf("\n\nSuccessfully terminated!!");
		delay(2000);
		system("cls");
		exit(0);
    }
}

//STRUCTURE DECLARATION
struct CustomerDetails
{
	int recordnumber;
	char name[30];
	char address[100];
	char phonenumber[11];
	float amount;
	char option[30];
	char email[35];

}s; // struct variable

//MAIN FUNCTION
int main()
{
	int i=0;

	time_t t;
	time(&t);
	system("cls");   // FOR CLEARING SCREEN
	setcolor(13);
	printf("\n\n\n");
	printf("\t\t\t\t\t\t ========================================================================= \n");
	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|     ---------------------------------------------------------------     |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|      [ D O N A T I O N S    M A N A G E M E N T    S Y S T E M  ]       |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|     ---------------------------------------------------------------     |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                         { GIVING IS THE GREATEST }                      |\n");
 	printf("\t\t\t\t\t\t|                              { ACT OF GRACE }                           |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
 	printf("\t\t\t\t\t\t|                                                                         |\n");
	printf("\t\t\t\t\t\t ========================================================================= \n\n\n");
		setcolor(07);
		for(i=0;i<105;i++)
		printf(" -");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    setcolor(07);
		for(i=0;i<105;i++)
		printf(" -");
	setcolor(11);
    printf("\t\t\t\t\t   Project Submitted by: CT-070 MUNIBA FAHEEM SIDDIQUE   CT -017 RBIYA KHAN  CT-030 AYMAN ASAD KHAN");
	printf("\n");
	printf("\t\t\t\t\tClass: FCIT 2018");
	printf("\n");
	printf("\t\t\t\t\tProject Submitted to: Sir. Waseemullah ");
	setcolor(13);
	printf("\n \n Press any key to continue:");

	getch();

	printf("\nGoing to login menu in 3...2...1...\n");
	setcolor(07);
	for(i=0;i<105;i++)
		printf(" -");
	delay(2000);

    system("cls");
    login();
    main_menu();
}

//MAIN MENU FUNCTION
void main_menu()
{
	int i=0;

	time_t t;
	time(&t);

	char choice;
    system("cls");
	while (1)      // infinite loop
	{
		system("cls");
		setcolor(13);
		 for(i=0;i<80;i++)
		printf("=");
		printf("\n\n");
		printf("   **************************  [ M A I N   M E N U ] ************************* \n");
		printf("\n");
		for(i=0;i<80;i++)
		printf("=");
		printf("\n\n\n");
		setcolor(13);
		printf("\t\t\t > SPECIFY YOUR PREFERED OPTION <");
		printf("\n\n");
		printf("\n\t\t\t Enter 0 -> Enumerate Za'kah");
		printf("\n\t\t\t-----------------------------------");
		printf("\n\t\t\t Enter 1 -> Deposit Donation");
		printf("\n\t\t\t-----------------------------------");
		printf("\n\t\t\t Enter 2 -> View Donor Record");
		printf("\n\t\t\t-----------------------------------");
		printf("\n\t\t\t Enter 3 -> Erase Donor Record");
		printf("\n\t\t\t-----------------------------------");
		printf("\n\t\t\t Enter 4 -> Search Donor Record");
		printf("\n\t\t\t-----------------------------------");
		printf("\n\t\t\t Enter 5 -> Modify Donor Record");
		printf("\n\t\t\t-----------------------------------");
		printf("\n\t\t\t Enter 6 -> Exit");
		printf("\n\t\t\t-----------------------------------");
		printf("\n\n\n");
		setcolor(07);
		for(i=0;i<80;i++)
		printf("-");
		setcolor(13);
	    printf("\nCurrent date and time : %s",ctime(&t));
	    setcolor(07);
		for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		switch(choice)           // SWITCH STATEMENT
		{
		    case '0':
				calculate();
				break;
			case '1':
				add();
				break;
			case '2':
				list();
				break;
			case '3':
				delete1();
				break;
			case '4':
				search();
				break;
			case '5':
				edit();
				break;
			case '6':
				system("cls");
				setcolor(13);
				printf("\n\n\t *^*^*^*^*^THANK YOU*^*^*^*^*^");
				delay(1000);
				setcolor(13);
				printf("\n\n    *^*^*^*^*^FOR TRUSTING OUR SERVICE*^*^*^*^*^ ~\n\n");

				exit(0);
				break;

			default:
				system("cls");
				setcolor(13);
				printf("\n\n\t\tINCORRECT INPUT!");
				printf("\n\n Press any key to continue");
				getch();
		}
	}
}

//OPTION [0] FUNCTION DEFINITION
void calculate()
{
	system("cls");
  float amount,z1,dep,z2,gold,z3,sil,z4;
  char c='%';
  setcolor(11);
      printf("\n\n\n");
      printf("\t\t*************************************************\n");
	  printf("\t\t*                                               *\n");
	  printf("\t\t*        -----------------------------          *\n");
      printf("\t\t*          COMPUTE ZA'KAT OVERDUE               *\n");
	  printf("\t\t*        -----------------------------          *\n");
	  printf("\t\t*                                               *\n");
	  printf("\t\t*************************************************\n");
setcolor(13);
	  printf("\n\n\n TOTAL ANNUAL GROSS INCOME (in PKR) = ");
      scanf("%f",&amount);
      z1=amount/40;
      printf("     2.5 %c = %.3f PKR",c,z1);

      printf("\n\n SAVINGS AND DEPOSITS (in PKR) = ");
      scanf("%f",&dep);
      z2=dep/40;
      printf("     2.5 %c = %.3f PKR",c,z2);

      printf("\n\n AMOUNT OF GOLD (in grams) = ");
      scanf("%f",&gold);
      if(gold>=87.49)
      { float cp;
        printf("\n Current gold price per gram ( up-to-date 4628 PKR) = ");
        scanf("%f",&cp);
        z3=gold*cp*0.025;
        printf("     2.5 %c = %.3f PKR",c,z3);
	  }
	  else
	  { printf("Less than Nisaab !");
	    z3=0;
	  }

	  printf("\n\n AMOUNT OF SILVER (in grams) = ");
      scanf("%f",&sil);
      if(sil>=613.350)
      { float cp;
        printf("\n Current silver rate per gram ( up-to-date 68.571 PKR) = ");
        scanf("%f",&cp);
        z4=sil*cp*0.025;
        printf("     2.5 %c = %.3f PKR",c,z4);
	  }
	  else
	  { printf("  Less than Nisaab !");
	    z4=0;
	  }
	 printf("\n\n");
     int i;
     for(i=0;i<80;i++)
		printf("-");
		printf("\ncalculating...");
		delay(2000);
	printf("\n\t\t\tTOTAL AMOUNT LIABLE FOR ZAKAT IS %.3f PKR\n",z1+z2+z3+z4);
	for(i=0;i<80;i++)
		printf("-");
		getch();
}

//OPTION [1] FUNCTION DEFINITION
void add()
{setcolor(13);
	FILE *f;
	int recordnumber, n, i, valid=0;
	char test;
	f=fopen("add.dat","r+");
	if(f==NULL)
	{   f=fopen("add.dat","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		delay(2000);
		printf("\n\n Process completed press any key to continue!! ");
		getch();
	}
	system("cls");
	printf("\n\n\n\t\t               REGISTER DONOR'S SPECIFICATIONS:");
	printf("\n\n");

	for(i=0;i<80;i++)
		     printf("=");


		ADD:     //using goto function
		printf("\n\n ENTER RECORD NUMBER \t: ");
		scanf("%d",&recordnumber);
		while(fread(&s,sizeof(s),1,f)==1)
	    {
	    	if(recordnumber == s.recordnumber)
	    	{
	    		printf("\n\n This record number already holds data !");
	    		goto ADD;
			}
		}
		s.recordnumber = recordnumber;


		Q:             //using goto function
		printf("\n ENTER NAME \t\t: ");
		fflush(stdin);
		gets(s.name);
		if(strlen(s.name)>20||strlen(s.name)<2)
		{
			printf("\n\n Name must hold 20 charachters !\n");
			goto Q;
		}
		else
		{
			for (i=0;i<strlen(s.name);i++)
			{
				if(s.name[i]== ' '){
					valid=1;
				}
				else if(isalpha(s.name[i]))
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\n Name contain invalid character. Please enter again! \n");
				goto Q;
			}
		}

		do
		{
			A:                    //using goto function
			printf("\n ENTER ADDRESS \t\t:");
			fflush(stdin);
			gets(s.address);
			if(strlen(s.address)>100 || strlen(s.address)<2)
			{
				printf("\n\n \t\t Invalid!! \n Note: Address should obtain less than 40 charachters. \n");
				goto A;
			}
			else
			{
				for (i=0;i<strlen(s.address); ++i)
				{
					if((s.address[i]==' ')||(s.address[i]=='-')||(s.address[i]=='/')){
                            valid = 1;
					}
					else if(s.address[i]=='0'||s.address[i]=='1'||s.address[i]=='2'||s.address[i]=='3'||s.address[i]=='4'||s.address[i]=='5'||s.address[i]=='6'||s.address[i]=='7'||s.address[i]=='8'||s.address[i]=='9'){
						valid = 1;
					}
					else if(isalpha(s.address[i]))
					{
						valid = 1;
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\n\n Address contain invalid character. Please enter again.\n");
				}
				}
		}while(!valid);

		do
		{
			P:                        //using goto function
			printf("\n ENTER MOBILE NUMBER \t: ");
			fflush(stdin);
			scanf("%s",s.phonenumber);
			if (strlen(s.phonenumber)<11 || strlen(s.phonenumber)>11)
			{
				printf("\n\n Mobile number should be of 11 digits. Please, enter valid number.\n");
				goto P;
			}
			for(i=0;i<strlen(s.phonenumber); i++)
			{
				if(!isalpha(s.phonenumber[i]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\n This mobile number is invalid. Please, enter numbers only.\n");
			}
		}while(!valid);

		do                //using goto function
		{
			X:
		    printf("\n\n     [ RECOMMENDED ALTERNATIVES FOR YOUR DONATION ]");
		    printf("\n\n \t > Non Governmental Organizations");
		    printf("\n \t > Non Profitable Schools");
		    printf("\n \t > Welfare Hospitals");
		    printf("\n \t > Humanitarian Old Houses");
		    printf("\n \t > Charitable Organizations");
			printf("\n\n\n OPT FOR DONATIONS \t: ");
			fflush(stdin);
			gets(s.option);
			if(strlen(s.option)>30 || strlen(s.option)<2)
			{
				printf("\n\n Invalid Input ! \n");
				goto X;
			}
			for(i=0;i<strlen(s.option); i++)
			{
				if(isalpha(s.option[i])||s.option[i]==' ')
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\n The option name contains only character. Please, enter again. \n");
			}
		}while(!valid);
		do
		{
			printf("\n ENTER EMAIL\t\t: ");
			fflush(stdin);
			scanf(" %s",s.email);
			if(strlen(s.email)>35||strlen(s.email)<10)
			{
				printf("\n\n\t Invalid!!\n The maximum number for donor's email is less than 31 and more than 10.\n");
			}
		}while(strlen(s.email)>35||strlen(s.email)<2);

	    	 for(i=0;i<80;i++)
		     printf("-");
		do
		{
			printf("\n\n ENTER CHARITABLE AMOUNT \t: ");
			scanf("%f",&s.amount);
			if(s.amount>1000000 || s.amount<=0)
			{
				printf(" NOTE : Maximum amount of donation is 1,000,000 PKR .\n");
			}
		}while(s.amount>1000000 || s.amount<=0);
        fseek(f,0,SEEK_END);
		fwrite(&s,sizeof(s),1,f);
		printf("\nGenerating record, please wait.");
		delay(2000);
		printf("\n\n RECORD GENERATED ! ");
		fclose(f);

	printf("\n\n\n PRESS 'esc' KEY TO EXIT ! \n\n  To add another donor details press any other key:");
	test=getche();
	if(test==27)//ascii code for esc
		main_menu();
	else
		add();
}

//OPTION [2] FUNCTION DEFINITION
void list()
{setcolor(13);
	FILE *f;
	int i, q;
	f = fopen("add.dat","r");
	if(f==NULL){
        printf("failed to open database.");
        printf("\nTerminating program");
        delay(1000);
        exit(3);
	}
	system("cls");
	for(i=0;i<110;i++)
	{
		printf("-");
	}
		printf("\t\t\nCOMPLETE LIST OF DONOR'S INFORMATION\n");
	for(i=0;i<110;i++)
	{
		printf("-");
	}

	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n\n\n");

		printf("\n\n\nRecord num = %d\n",s.recordnumber);
		for(i=0;i<110;i++)
	{
		printf("-");
	}
		printf("\nDonor's name : %s\n",s.name);

		printf("Address : %s\n",s.address);

		printf("Phone number : %s\n",s.phonenumber);

		printf("Option :   %s\n",s.option);

		printf("Email : %s\n",s.email);

		printf("Amount = %.3f\n",s.amount);

	}
	printf("\n\n\n");
	for(i=0;i<110;i++)
		printf("-");

	fclose(f);
	printf("\nPress any key to go back to main menu");
	getch();
}

//OPTION [3] DELETE FUNCTION DEFINITION
void delete1()
{setcolor(13);
	FILE *f,*t;
	f=fopen("add.dat","r");
	int i=0;
	int recordnumber;
	t=fopen("temp.dat","w");
	if(t==NULL){
        printf("Failed to load database.\n");
        printf("\nTerminating program");
        delay(2000);
        printf("\nProgram terminated");
        exit(3);
	}

	else

		system("cls");
		printf("\n\n\n\n \t Enter the RECORD NUMBER of the donor to be deleted from the database: ");
		fflush(stdin);
		scanf("%d",&recordnumber);
		while(fread(&s,sizeof(s),1,f)==1)
		{
			if(recordnumber != s.recordnumber)
			{
				fwrite(&s,sizeof(s),1,t);
			}
			else
			{
				i=1;
			}
		}
		if(!i)
		{
			printf("\n\n Donor's Record of this  record number is not found !!");
			printf("\nPress any key to go back to main menu");
			getch();
			fclose(f);
			fclose(t);
			main_menu();
		}
		else
		{
			printf("\n\n\tSUCCESSFULLY DELETED !.\n");
		}
		fclose(f);
		fclose(t);
		remove("add.dat");
		rename("temp.dat","add.dat");
		printf("Press any key to contiue");
		getch();
}

//OPTION [4] FUNCTION DEFINITION
void search()
{setcolor(13);
system("cls");
	FILE *f;
	int recordnumber;
	int flag=1;
	f=fopen("add.dat","r");
	if(f==NULL)
	{
		printf("NO RECORD ADDED.");
		main_menu();
	}
	else
	{
		fflush(stdin);
		printf("Enter recordnumber of the customer to search its details: \n");
		scanf("%d", &recordnumber);
		while(fread(&s,sizeof(s),1,f)==1)
		{
			if(recordnumber==s.recordnumber)
			{
				flag=0;
				printf("\n\tRecord Found\n");
				printf("\nRecord Number\t:    %d",s.recordnumber);
				printf("\nName\t\t:    %s",s.name);
				printf("\nAddress\t\t:    %s",s.address);
				printf("\nPhone number\t:    %s",s.phonenumber);
				printf("\nOption\t\t:    %s",s.option);
				printf("\nEmail\t\t:    %s",s.email);
				printf("\nAmount\t\t:    %.3f",s.amount);
				break;
			}
		}
		if(flag==1){
			printf("\n\tRequested Customer could not be found!");
		}
		getch();
		fclose(f);
		main_menu();
	}

}

//OPTION [5] FUNCTION DEFINITION
void edit()
{setcolor(13);
	FILE *f, *r;
	int flag=0;
	char ed;
	int recordnumber;
	long int size=sizeof(s);
	f= fopen("add.dat","r+");
	if(f==NULL)
	{
		printf("NO RECORD ADDED.");
		main_menu();
	}
	else
	{
		r = fopen("temp.dat","a");
		system("cls");
		printf("Enter recordnumber of the customer to edit:\n\n");
		scanf("%d",&recordnumber);
		fflush(stdin);
		while(fread(&s,sizeof(s),1,f)==1)
		{
			if(recordnumber==s.recordnumber)
			{

				flag=1;
				printf("\n\t*** Existing Record ***");
				printf("\nRecord Number\t: %d",s.recordnumber);
				printf("\nName\t\t: %s",s.name);
				printf("\nAddress\t\t: %s",s.address);
				printf("\nPhone number\t: %s",s.phonenumber);
				printf("\nOption\t: %s",s.option);
				printf("\nEmail\t\t: %s",s.email);
				printf("\nPeriod\t\t: %.3f",s.amount);
				printf("\n\n\t*** New Record ***");
				printf("\nEnter New Name           : ");
				fflush(stdin);
				gets(s.name);
				printf("\nEnter New Address        : ");
				fflush(stdin);
				gets(s.address);
				printf("\nEnter New Phone number   : ");
				fflush(stdin);
				scanf("%s",s.phonenumber);
				printf("\nEnter New Option    : ");
				printf("\n\n     [ RECOMMENDED ALTERNATIVES FOR YOUR DONATION ]");
		    printf("\n\n \t > Non Governmental Organizations");
		    printf("\n \t > Non Profitable Schools");
		    printf("\n \t > Welfare Hospitals");
		    printf("\n \t > Humanitarian Old Houses");
		    printf("\n \t > Charitable Organizations");
			printf("\n\n\n OPT FOR DONATIONS \t: ");
				fflush(stdin);
				gets(s.option);
				printf("\nEnter New Email          : ");
				fflush(stdin);
				scanf("%s",s.email);
				printf("\nEnter New Amount         : ");
				scanf("%f",&s.amount);
				printf("Press 'm' to confirm edit existing record or any key to cancel...");
				ed=getche();
				if(ed=='m' || ed=='M')
				{
					fwrite(&s,sizeof(s),1,r);
					fflush(stdin);
					printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
				}
			}
			else
			{
				fwrite(&s,sizeof(s),1,r);
				fflush(stdin);
			}

		}
		if(!flag)
		{
			printf("\n\nTHE RECORD DOESN'T EXIST");
		}
		fclose(r);
		fclose(f);
		remove("add.dat");
		rename("temp.dat","add.dat");

		getch();
	}
	main_menu();
}
