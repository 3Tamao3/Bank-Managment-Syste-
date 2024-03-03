#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


void account(void);
void transfermoney(void);
void checkbalance(char*);
void login(void);
void display(char*);
void person(char*);
void loginsu(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


struct pass
{
	char username[50];
	int date, month, year;
	char pnumber[15];
	char adharnum[20];
	char fname[20];
	char lname[20];
	char fathname[20];
	char mothname[20];
	char address[50];
	char typeaccount[20];
};

struct money
{
	char usernameto[50];
	char userpersonfrom[50];
	long int money1;
};

struct userpass
{
	char password[50];
}

int main (void)
{
	int i, a, b, choice;
	int passwordlength;

	gotoxy(20, 3);
	

	printf("WELCOME TO BANK ACCOUNT SYSTEM");
	gotoxy(18, 5);

	printf("******************************");
	gotoxy(25, 7);

	gotoxy(20, 10);
	printf("1.... CREATE A BANK ACCOUNT");

	gotoxy(20, 12);
	printf("2.... ALREADY A USER? SIGN IN");
	gotoxy(20, 14);
	printf("3.... EXIT\n\n");

	printf("\n\nENTER YOUR CHOICE: ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
			system("cls");
			printf("\n\n USERNAME 50 CHARACTERS MAX!");
			printf("\n\n PASSWORD 50 CHARACTERS MAX!");
			acount();
			break;

		case 2:
			login();
			break;
		
		case 3:
			exit(0);
			break;

			getch();
	}
}

void account(void)
{
	char password[20]
	int passwordlength, i, seek = 0;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass p1;

	struct userpass u2;

	fp = fopen("username.txt", "ab");

	system("cls");
	printf("\n\n!CREATE ACCOUNT!");

	printf("\n\nFIRST NAME: ");
	scanf("%s", &u1.fname);

	printf("\n\nLAST NAME: ");
	scanf("%s", &u1.lname);

	printf("\n\nADDRESS: ");
	scanf("%s", &u1.address);

	printf("\n\nACCOUNT TYPE: ");
	scanf("%s", &u1.typeaccount);

	printf("\n\nDATE OF BIRTH: ");
	printf("\nDATE-");
	scanf("%d", &u1.date);
	printf("\nMONTH-");
	scanf("%d", &u1.month);
	printf("\nYEAR-");
	scanf("%d", &u1.year);

	printf("\n\nPHONE NUMBER: ");
	scanf("%s", &u1.pnumber);

	printf("\n\nUSERNAME: ");
	scanf("%s", &u1.username);

	printf("\n\nPASSWORD: ");

	for(i = 0; i < 50; i++)
	{
		ch = getch();
		if (ch != 13)
		{
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
		{
			break;
		}
	}
	fwrite(&u1, sizeof(u1), 1, fp);

	fclose(fp);

	accountcreated();
}

void transfermoney(void)
{
	int i, j;
	FILE *fm, *fp;
	struct pass u1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");

	fp = fopen("username.txt", "rb");

	fm = fopen("mon.txt", "ab");

	gotoxy(33, 4);
	printf("---- TRANSFER MONEY ----");
	gotoxy(33, 5);
	printf("========================");

	gotoxy(33, 11);
	printf("FROM (your username): ");
	scanf("%s", &usernamet);


	gotoxy(33, 13);
	printf("TO (username of person): ");
	scanf("%s", &usernamep);

	while (fread(&u1, sizeof(u1), 1, fp))
	{
		if (strcmp(usernamep, u1.username) == 0)
		{
			strcpy(m1.usernameto, u1.username);
			strcpy(m1.userpersonfrom, usernamet);
		}
	}
	gotoxy(33, 16);

	printf("ENTER THE AMOUNT TO BE TRANSFERRED: ");
	scanf("%d", &m1.money1);

	fwrite(&m1, sizeof(m1), 1, fm);

	gotoxy(0, 26);
	printf("-----------------------------------------------------------------------------------");

	gotoxy(0, 28);
	printf("-----------------------------------------------------------------------------------");

	gotoxy(0, 29);
	printf("transferring amount, Please wait...");

	gotoxy(10, 27);
	for (i = 0; i < 70; i++)
	{
		for (j = 0; j < 1200000; j++)
		{
			j++;
			j--;
		}
	printf("*");
	}
	gotoxy(33, 40);
	printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
	getch();

	fclose(fp);
	fclose(fm);

	display(usernamet);
}

void checkbalance(char username2[])
{
	system("cls");
	FILE* fm;
	struct money m1;
	char ch;
	int i = 1, sommoney = 0;

	fm = fopen("mon.txt", "rb")

	int k = 5, l = 10;
	int m = 30, n = 10;
	int u = 60, v = 10;

	gotoxy(30, 2)
	printf("==== BALANCED DASHBOARD ====");
	gotoxy(30, 3);
	printf("****************************");
	gotoxy(k, 1);
	printf("S no.");
	gotoxy(m, n);
	printf("TRANSACTION ID");
	gotoxy(u, v);
	printf("AMOUNT");

	while (fread(&m1, sizeof(m1), 1, fm))
	{
		if (strcmp(username2, m1.usernameto) == 0)
		{
			gotoxy(k, ++l);
			printf("%d", i);
			i++;
			gotoxy(m, ++n);
			printf("%s", m1.userpersonfrom);

			gotoxy(u, ++v);
			printf("%d", m1.money1);
			summoney = sommoney + m1.money1;
		}
	}

	gotoxy(80, 10);
	printf("TOTAL AMOUNT");

	gotoxy(80, 12);
	printf("%d", sommoney);

	getch();

	fclose(fm);
	display(username2);
}

void login(void)
{
	system("cls");
	
	char username[50];
	char password[50];

	int i, j, k;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass u2;

	fp = fopen("username.txt", "rb");


	if (fp == NULL)
	{
		printf("ERROR IN OPENING FILE");
	}

	gotoxy(34, 2);
	printf(" ACCOUNT LOGIN");
	gotoxy(7, 5);
	printf("**********************************************************************************************************");

	gotoxy(35, 10);
	printf("==== LOG IN ====");


	gotoxy(35, 12);
	printf("USERNAME: ");
	scanf("%s", &username);
	for (i = 0; i < 50; i++)
	{
		ch = getch();
		if (ch != 13)
		{
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}

	while (fread(&u1, sizeof(u1), 1, fp))
	{
		if (strcmp(username, u1.username) == 0)
		{
			loginsu();
			display(username);
		}
	}

	fclose(fp);
}

void loginsu(void)
{
	int i;
	FILE* fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++)
	{
		i++;
		i--;
	}
	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(0, 20);
	printf("Press enter to continue");

	getch();
}
