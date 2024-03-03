i#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void checkbalance(char*);
void transfermoney(void);
void display(char*);
void person(char*);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct pass {
	char username[50];
	int date, month, year;
	char pnumber[15];
	char fname[20];
	char lname[20];
	char address[50];
};

struct money {
	char usernameto[50];
	char userpersonfrom[50];
	long long int money1;
};

struct userpass {
	char password[50];
};

int main()
{
	int i, a, b, choice;
	int passwordlength;

	gotoxy(20, 3);

	printf("==== BANK ACCOUNT SYSTEM ====\n\n");
	gotoxy(18, 5);

	printf("**********************************");
	gotoxy(25, 7);

	gotoxy(20, 8);
	printf("1. CREATE A BANK ACCOUNT");

	gotoxy(20, 10);
	printf("2. ALREADY A USER? SIGN IN");

	gotoxy(20, 12);
	printf("3. EXIT\n\n");

	gotoxy(18, 14);
    printf("**********************************");

	printf("\n\n                   ENTER YOUR CHOICE: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		system("cls");
		printf("\n\n USERNAME 50 CHARACTERS MAX!");
		printf("\n\n PASSWORD 50 CHARACTERS MAX!");
		account();
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
	char password[20];
	int passwordlength, i, seek = 0;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass p1;

	struct userpass u2;

	fp = fopen("username.txt", "ab");

	system("cls");
	printf("\n\n ==== CREATE ACCOUNT ====");

	printf("\n\n FIRST NAME: ");
	scanf("%s", &u1.fname);

	printf("\n\n LAST NAME: ");
	scanf("%s", &u1.lname);

	printf("\n\n ADDRESS: ");
	scanf("%s", &u1.address);

	printf("\n\n DATE OF BIRTH");
	printf("\n DAY: ");
	scanf("%d", &u1.date);
	printf("\n MONTH: ");
	scanf("%d", &u1.month);
	printf("\n YEAR: ");
	scanf("%d", &u1.year);

	printf("\n\n PHONE NUMBER: ");
	scanf("%s", u1.pnumber);

	printf("\n\n USERNAME: ");
	scanf("%s", &u1.username);

	printf("\n\n PASSWORD: ");

	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}

	fwrite(&u1, sizeof(u1),
		1, fp);

	fclose(fp);

	accountcreated();
}

void accountcreated(void)
{
	int i;
	char ch;
	system("cls");
	printf(
		"PLEASE WAIT...\n\nYOUR DATA IS PROCESSING...");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY!");
	gotoxy(0, 20);

	printf("Press enter to login");

	getch();
	login();
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

	fp = fopen("username.txt",
			"rb");

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	gotoxy(34, 2);
	printf(" ACCOUNT LOGIN ");
	gotoxy(7, 5);
	printf("***********************************************"
		"********************************");

	gotoxy(35, 10);
	printf("==== LOG IN ====");

	gotoxy(35, 12);
	printf("USERNAME.. ");
	scanf("%s", &username);

	gotoxy(35, 14);
	printf("PASSWORD..");

	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}

		else
			break;
	}

	while (fread(&u1, sizeof(u1),
				1, fp)) {
		if (strcmp(username,
				u1.username)
			== 0) {
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
	printf("Fetching account details...\n");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL!");
	gotoxy(0, 20);
	printf("Press enter to continue");

	getch();
}

void display(char username1[])
{
	system("cls");
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	struct pass u1;

	if (fp == NULL) {
		printf("error in opening file");
	}

	while (fread(&u1, sizeof(u1),
				1, fp)) {
		if (strcmp(username1,
				u1.username)
			== 0) {
			gotoxy(30, 1);
			printf("WELCOME, %s %s",
				u1.fname, u1.lname);
			gotoxy(28, 2);
			printf("**************************");
			gotoxy(55, 6);
			printf("==== YOUR ACCOUNT INFO ====");
			gotoxy(55, 8);
			printf("***************************");
			gotoxy(55, 10);
			printf("NAME - %s %s", u1.fname,
				u1.lname);

			gotoxy(55, 12);
			printf("MOBILE NUMBER - %s",
				u1.pnumber);

			gotoxy(55, 14);
			printf("DATE OF BIRTH - %d-%d-%d",
				u1.date, u1.month, u1.year);

			gotoxy(55, 16);
			printf("ADDRESS - %s", u1.address);

		}
	}

	fclose(fp);

	gotoxy(2, 6);
	printf("==== HOME ====");
	gotoxy(1, 8);
	printf("****************");
	gotoxy(2, 10);
	printf(" 1. CHECK BALANCE");
	gotoxy(2, 12);
	printf(" 2. TRANSFER MONEY");
	gotoxy(2, 14);
	printf(" 3. LOG OUT\n\n");
	gotoxy(2, 16);
	printf(" 4. EXIT\n\n");

	printf(" ENTER YOUR CHOICES: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		checkbalance(username1);
		break;

	case 2:
		transfermoney();
		break;

	case 3:
		logout();
		login();
		break;

	case 4:
		exit(0);
		break;
	}
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
	printf("FROM (your username):  ");
	scanf("%s", &usernamet);

	gotoxy(33, 13);
	printf(" TO (username of person): ");
	scanf("%s", &usernamep);

	while (fread(&u1, sizeof(u1),
				1, fp))

	{
		if (strcmp(usernamep,
				u1.username)
			== 0) {
			strcpy(m1.usernameto,
				u1.username);
			strcpy(m1.userpersonfrom,
				usernamet);
		}
	}
	gotoxy(33, 16);

	printf("ENTER THE AMOUNT TO BE TRANSFERRED: ");
	scanf("%d", &m1.money1);

	fwrite(&m1, sizeof(m1),
		1, fm);

	gotoxy(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 28);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 29);
	printf("transferring amount, Please wait...");

	gotoxy(10, 27);
	for (i = 0; i < 70; i++) {
		for (j = 0; j < 1200000; j++) {
			j++;
			j--;
		}
		printf("*");
	}

	gotoxy(33, 40);
	printf("AMOUNT SUCCESSFULLY TRANSFERRED!");
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
	int i = 1, summoney = 0;

	fm = fopen("mon.txt", "rb");

	int k = 5, l = 10;
	int m = 30, n = 10;
	int u = 60, v = 10;

	gotoxy(30, 2);
	printf("==== BALANCE DASHBOARD ====");
	gotoxy(30, 3);
	printf("***************************");
	gotoxy(k, l);
	printf("S no.");
	gotoxy(m, n);
	printf("TRANSACTION ID");
	gotoxy(u, v);
	printf("AMOUNT");

	while (fread(&m1, sizeof(m1),
				1, fm)) {
		if (strcmp(username2,
				m1.usernameto)
			== 0) {
			gotoxy(k, ++l);
			printf("%d", i);
			i++;
			gotoxy(m, ++n);
			printf("%s", m1.userpersonfrom);

			gotoxy(u, ++v);
			printf("%lld", m1.money1);

			summoney = summoney + m1.money1;
		}
	}

	gotoxy(80, 10);
	printf("TOTAL AMOUNT");

	gotoxy(80, 11);
	printf("%d", summoney);

	getch();

	fclose(fm);
	display(username2);
}

void logout(void)
{
	int i, j;
	system("cls");
	printf("please wait, logging out");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	gotoxy(30, 10);
	printf("SIGN OUT SUCCESSFULLY!\n");

	gotoxy(0, 20);
	printf("press any key to continue");

	getch();
}

