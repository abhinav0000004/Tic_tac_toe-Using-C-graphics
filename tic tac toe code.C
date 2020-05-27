#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
int q,i;

void Board();
void PlayerX();
void PlayerO();
void Player_win();
void check();
int win=0,wrong_X=0,wrong_O=0,chk=0;
void T(int ,int);
void C(int ,int);
void A(); void I();
void O(); void E();
void CIR(int);
void start();


char name_X[30];
char name_O[30];
int pos_for_X[3][3];
int pos_for_O[3][3];
int pos_marked[3][3];

void main(){
	int i,ch,j;
	char ans;
	start();
	do
	{
		clrscr();
		printf("\n\t\t\t\tTIC TAC TOE VERSION 1.0");
		printf("\n\t\t\t\t");
		delay(2000);
		for(i=1;i<=23;i++)
		{
			delay(100);
			printf("*");
		}
		printf("\n1.Start The Game");
		printf("\n2.Quit The Game");
		printf("\nEnter your choice(1-2) : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				chk=0;
				win=0;
				for(i=1;i<=3;i++)
				{
					for(j=1;j<=3;j++)
					{
						pos_for_X[i][j]=0;
						pos_for_O[i][j]=0;
						pos_marked[i][j]=0;
					}
				}
				printf("\n\n");
				clrscr();
				printf("\nEnter the name of the player playing for \'X\': ");
				fflush(stdin);
				gets(name_X);
				printf("\nEnter the name of the player playing for \'O\': ");
				fflush(stdin);
				gets(name_O);
				Board();
				for(;;)
				{
					if(win==1)
						break;
					check();
					if(chk==9)
					{
						printf("\n\t\t\tMATCH DRAWS!!");
						printf("\nPress any key....");
						break;
					}
					else
						chk=0;
					printf("\nTURN FOR %s:",name_X);
					PlayerX();
					do
					{
						if(wrong_X!=1)
							break;
						wrong_X=0;
						printf("\nTURN FOR %s:",name_X);
						PlayerX();
					}while(wrong_X==1);
					check();
					if(chk==9)
					{
						printf("\n\t\t\tMATCH DRAWS");
						printf("\nPress any key....");
						break;
					}
					else
						chk=0;
					printf("\nTURN FOR %s:",name_O);
					PlayerO();
					do
					{
						if(wrong_O!=1)
							break;
						wrong_O=0;
						printf("\nTURN FOR %s:",name_O);
						PlayerO();
					}while(wrong_O==1);

					}
				Board();
				if(win!=1)
				{
					printf("\n\t\t\tMATCH DRAWS!!");
					printf("\nPress any key.......");
				}
				getch();
				break;
			case 2:
				printf("\n\n\nThank You For Playing The Game.");
				printf("\n");
				printf("\nCreated By:ABHINAV CHOUDHARY\n");
				printf("INSTITUTION:Dayananda Sagar College of Engineering\n");
				printf("Department: Computer Science & Engineering");
				getch();
				exit(1);
				break;
		}
		printf("\nWant To Play(Y/N) ? ");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y' || ans=='Y');
}


void Board()
{
	int i,j;
	clrscr();
	printf("\n\t\t\t\tTIC TAC TOE BOARD");
	printf("\n\t\t\t\t*****************");
	printf("\n\n\n");
	printf("\n\t\t\t    1\t      2\t        3");
	for(i=1;i<=3;i++)
	{
		printf("\n \t\t\t _____________________________");
		printf("\n \t\t\tº\t  º\t   º\t     º");
		printf("\n\t\t%d\t",i);
		for(j=1;j<=3;j++)
		{

			if(pos_for_X[i][j]==1)
			{
				printf("    X");
				printf("     ");
			}
			else if(pos_for_O[i][j]==1)
			{
				printf("    O");
				printf("     ");
			}
			else
			{
				printf("          ");
				continue;
			}
		}
		printf("\n\t\t\tº\t  º\t   º\t     º");
	}
	printf("\n\t\t\t------------------------------");
	Player_win();
}


void PlayerX()
{
	int row,col;
	if(win==1)
		return;
	printf("\nEnter the row no. : ");
	fflush(stdin);
	scanf("%d",&row);
	printf("Enter the column no. : ");
	fflush(stdin);
	scanf("%d",&col);
	if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
	{
		printf("\nWRONG POSITION!! Press any key.....");
		wrong_X=1;
		getch();
		Board();
	}
	else
	{
		pos_for_X[row][col]=1;
		pos_marked[row][col]=1;
		Board();
	}
}

void PlayerO()
{
	int row,col;
	if(win==1)
		return;
	printf("\nEnter the row no. : ");
	scanf("%d",&row);
	printf("Enter the column no. : ");
	scanf("%d",&col);
	if(pos_marked[row][col]==1 || row<1 || row>3 || col<1 || col>3)
	{
		printf("\nWRONG POSITION!! Press any key....");
		wrong_O=1;
		getch();
		Board();
	}
	else
	{
		pos_for_O[row][col]=1;
		pos_marked[row][col]=1;
		Board();
	}
}
void Player_win()
{
	int i;
	for(i=1;i<=3;i++)
	{
		if(pos_for_X[i][1]==1 && pos_for_X[i][2]==1 && pos_for_X[i][3]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_X);
			printf("\nPress any key............");
			return;
		}
	}
	for(i=1;i<=3;i++)
	{
		if(pos_for_X[1][i]==1 && pos_for_X[2][i]==1 && pos_for_X[3][i]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_X);
			printf("\nPress any key............");
			return;
		}
	}
	if(pos_for_X[1][1]==1 && pos_for_X[2][2]==1 && pos_for_X[3][3]==1)
	{
		win=1;
		printf("\n\nRESULTL: %s wins!!",name_X);
		printf("\nPress any key......");
		return;
	}
	else if(pos_for_X[1][3]==1 && pos_for_X[2][2]==1 &&
pos_for_X[3][1]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_X);
		printf("\nPress any key.....");
		return;
	}

	for(i=1;i<=3;i++)
	{
		if(pos_for_O[i][1]==1 && pos_for_O[i][2]==1 && pos_for_O[i][3]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_O);
			printf("\nPress any key.....");
			return;
		}
	}
	for(i=1;i<=3;i++)
	{
		if(pos_for_O[1][i]==1 && pos_for_O[2][i]==1 && pos_for_O[3][i]==1)
		{
			win=1;
			printf("\n\nRESULT: %s wins!!",name_O);
			printf("\nPress any key.....");
			return;
		}
	}
	if(pos_for_O[1][1]==1 && pos_for_O[2][2]==1 && pos_for_O[3][3]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_O);
		printf("\nPress any key.....");
		return;
	}
	else if(pos_for_O[1][3]==1 && pos_for_O[2][2]==1 &&
pos_for_O[3][1]==1)
	{
		win=1;
		printf("\n\nRESULT: %s wins!!",name_O);
		printf("\nPress any key.....");
		return;
	}
}
void check()
{
	int i,j;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(pos_marked[i][j]==1)
				chk++;
			else
				continue;
		}
	}
}

void start(){
	int gdrive=DETECT,gmode;
/*gdrive is a int value which basically tells us that graphics are used ,gmode used to initialize graphics and if gdrive=detect then intigraph will set graphics to its highest reso;ution and path will specify the path where we will find graphics driver*/
	initgraph(&gdrive,&gmode,"c:\\turboc3\\bgi");//it initialize the graphics which load the graphics driver from the disk and put it in graphics mode

	delay(2000);
	T(50,50); delay(100);
	I(); delay(100);
	C(160,50);delay(100);
	T(300,50); delay(100);
	A();delay(100);
	C(455,50);delay(100);
	T(160,200);delay(100);
	O();delay(100);
	C(250,200);delay(100);
	E();delay(200);

	
	closegraph();
}


void I(){
	for(i=0;i<20;i++){
		setcolor(2);
		circle(130+i,50,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		circle(140,50+i,3);
		delay(10);
	}
	for(i=0;i<20;i++){
		setcolor(2);
		circle(130+i,120,3);
		delay(10);
	}
}

void C(int c1,int c2){
	for(i=0;i<10;i++){
		setcolor(2);
		circle(c1+50,c2+10-i,3);
		delay(10);
	}
	for(i=0;i<50;i++){
		circle(c1+50-i,c2,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		circle(c1,c2+i,3);
		delay(10);
	}
	for(i=0;i<45;i++){
		circle(c1+i,c2+70,3);
		delay(10);
	}
}

void O(){
	for(i=0;i<70;i++){
		circle(300,270-i,3);
		delay(10);
	}
}

void T(int t1,int t2){
	for(i=0;i<70;i++){
		setcolor(2);
		circle(t1+i,t2,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		setcolor(2);
		circle(t1+35,t2+i,3);
		delay(10);
	}
}

void A(){
	for(i=0;i<35;i++){
		circle(410-i,50+(i*2),3);
		delay(10);
	}
	for(i=0;i<35;i++){
		circle(410+i,50+(i*2),3);
		delay(10);
	}
	for(i=0;i<20;i++){
		circle(400+i,80,3);
		delay(10);
	}
}

void E(){
	for(i=0;i<50;i++){
		circle(365-i,200,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		circle(315,200+i,3);
		delay(10);
	}
	for(i=0;i<50;i++){
		circle(315+i,270,3);
		delay(10);
	}
	for(i=0;i<25;i++){
		circle(315+i,235,3);
		delay(10);
	}
}