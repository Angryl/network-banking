//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//				PROJECT NET BANKING
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//		INCLUDED HEADER FILES
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


#include <graphics.h>
#include <dos.h>
#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>


	void gra1();
	void gra2();			//Program segment to display some graphic
	void box(int,int);
  
	//**********************************************************
	// THIS CLASS CONTAINS FUNCTIONS RELATED TO DRAW BOX ETC.
	//**********************************************************

class shape
{
	public :					   //Public member functions
		void line_hor(int, int, int, char) ;
		void line_ver(int, int, int, char) ;
		void box(int,int,int,int,char) ;
} ;


	//**********************************************************
	// THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU
	//**********************************************************

class control
{
	public :
		void main_menu(void) ;	     //Public member functions
		void help(void) ;
	private :
		void edit_menu(void) ;       //Private member functions

} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO INITIAL DEPOSIT
//**********************************************************

class initial
{
	public :
		void add_to_file(int, char t_name[30], char t_address[60], float) ;
		void display_list(void) ;
		void delete_account(int) ;
		void update_balance(int, float) ;
		void modify(void) ;
		int  last_accno(void) ;
		int  found_account(int) ;
		char *return_name(int) ;	   //So that the private members of class
		char *return_address(int) ;	   //can be used in required segments.
		float give_balance(int) ;
		int  recordno(int) ;			void display(int) ;
	private :
		  void  modify_account(int, char t_name[30], char t_address[60]) ;
		  void  box_for_list(void) ;

		  int   accno ;                  //Private member elements
		  char  name[30], address[60] ;
		  float balance ;
} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO TRANSACTIONS
//**********************************************************

class account
{
	public :
		void new_account(void) ;
		void close_account(void) ;
		void display_account(void) ;
		void transaction(void) ;
		void clear(int,int) ;
	private :
		void  add_to_file(int, int, int, int, char, char t_type[10], float, float, float) ;
		void  delete_account(int) ;
		int   no_of_days(int, int, int, int, int, int) ;
		float calculate_interest(int, float) ;
		void  display(int) ;
		void  box_for_display(int) ;

			int   accno ;
			char  type[10] ;      // Cheque or Cash
			int   dd, mm, yy ;   // Date
			char  tran ;	    // Deposit or Withdraw
			float interest, amount, balance ;
} ;



//**********************************************************
// CLASS SHAPE :: FUNCTION TO DRAW HORIZONTAL LINE
//**********************************************************

void shape :: line_hor(int column1, int column2, int row, char c)
{
	for ( column1; column1<=column2; column1++ )
	{
		gotoxy(column1,row) ;
		cout <<c ;
	}
}


//**********************************************************
// CLASS SHAPE :: FUNCTION TO DRAW VERTICAL LINE
//**********************************************************

void shape :: line_ver(int row1, int row2, int column, char c)
{

	for ( row1; row1<=row2; row1++ )
	{
		gotoxy(column,row1) ;
		cout <<c ;
	}
}


//**********************************************************
// CLASS SHAPE :: FUNCTION TO DRAW BOX LINE
//**********************************************************

void shape :: box(int column1, int row1, int column2, int row2, char
c)
{
	char ch=218 ;
	char c1, c2, c3, c4 ;
	char l1=196, l2=179 ;
	if (c == ch)
	{
		c1=218 ;
		c2=191 ;
		c3=192 ;
		c4=217 ;
		l1 = 196 ;
		l2 = 179 ;
	}
	else
	{
		c1=c ;
		c2=c ;
		c3=c ;
		c4=c ;
		l1 = c ;
		l2 = c ;
	}
	gotoxy(column1,row1) ;
	cout <<c1 ;
	gotoxy(column2,row1) ;
	cout <<c2 ;
	gotoxy(column1,row2) ;
	cout <<c3 ;
	gotoxy(column2,row2) ;
	cout <<c4 ;
	column1++ ;
	column2-- ;
	line_hor(column1,column2,row1,l1) ;
	line_hor(column1,column2,row2,l1) ;
	column1-- ;
	column2++ ;
	row1++ ;
	row2-- ;
	line_ver(row1,row2,column1,l2) ;
	line_ver(row1,row2,column2,l2) ;
}


//*************************************************************************

// CLASS CONTROL :: FUNCTION TO DISPLAY MAIN MENU AND CALL OTHER FUNCTIONS
//*************************************************************************


void control :: main_menu(void)
{
void selected(int);
void toggle(int,int);
	char m1[]="1:   SEE ACCOUNT     ",m2[]="2: LIST OF ACCOUNTS",m3[]="3:   TRANSACTIONS    ",
		 m4[]="4:   OPEN NEW ACCOUNT",m5[]="5: EDIT ACCOUNT	",m6[]="6:   HELP	       ",
	     m7[]="7:   QUIT            ";
	static int counter=0;
	while(1)
	{
	int gd=DETECT,gm=DETECT;
	initgraph(&gd,&gm,"..\\bgi");
	counter++;
	setfillstyle(1,7);
	floodfill(320,240,1);
	settextjustify(1,1);
	setcolor(8);
	settextstyle(7,0,0);
	setusercharsize(27,10,5,3);
	if (counter==1)
	{
		outtextxy(320,35,"B            ");  delay(200);
		outtextxy(320,35,"  A          ");  delay(200);
		outtextxy(320,35,"    N        ");  delay(200);
		outtextxy(320,35,"      K      ");  delay(200);
		outtextxy(320,35,"        I    ");  delay(200);
		outtextxy(320,35,"          N  ");  delay(200);
		outtextxy(320,35,"            G");
		for(int i=0,j=640;i<610;i++,j--)
		{
			sound(2*i);
			setcolor(8);
			line(i,15,i-570,15);
			line(j,65,j+570,65);  delay(5);
			putpixel(i-570,15,7);
			putpixel(j+570,65,7);
		}
		nosound();
	}
	else
	{
		setusercharsize(27,12,5,3);
		outtextxy(320,35,"B A N K I N G");
		setcolor(8);
		line(610,15,40,15);
		line(600,65,30,65);
	}
	settextstyle(7,1,5);
	outtextxy(90,270,"O P T I O N S");
	outtextxy(550,270,"O P T I O N S");
	settextstyle(1,0,2);
	char ch;
	int choice=1,temp;
	box(1,9);
	box(2,7);
	box(3,7);
	box(4,7);
	box(5,7);
	box(6,7);
	box(7,7);
	setcolor(1);
	outtextxy(320,90,m1);
	setcolor(15);
	outtextxy(320,150,m2);
	outtextxy(320,210,m3);
	outtextxy(320,270,m4);
	outtextxy(320,330,m5);
	outtextxy(320,390,m6);
	outtextxy(320,450,m7);
	//72  up
	//80  down
	//75  left
	//77  right
	//13  enter
	//49  1
	//71  Home
	//79  End
	//73 PgUp
	//81 PgDown
	//27 Escape
	do
	{
		temp=choice;
		ch=getch();
		switch (ch)
		{
			case 72:
			case 75: choice=((--choice+7)%7);
				 toggle(choice,temp);
				 continue;
			case 77:
			case 80: choice=(++choice%7);
				 toggle(choice,temp);
				 continue;
			case 73: choice=(choice+12)%7;
				 toggle(choice,temp);
				 break;
			case 81: choice=(choice+2)%7;
				 toggle(choice,temp);
				 break;
			case 71:
			case 49: choice=1;
				 toggle(choice,temp);
				 break;
			case 50: choice=2;
				 toggle(choice,temp);
				 break;
			case 51: choice=3;
				 toggle(choice,temp);
				 break;
			case 52: choice=4;
				 toggle(choice,temp);
				 break;
			case 53: choice=5;
				 toggle(choice,temp);
				 break;
			case 54: choice=6;
				 toggle(choice,temp);
				 break;
			case 79:
			case 55: choice=0;
				 toggle(choice,temp);
				 break;
			case 27: choice=0;
				 toggle(choice,temp);
			case 13: selected(choice);
				 delay(500);
		}
	}while (ch!=13&&ch!=27);
	for(int i=320;i>0;i--)
		{
		if((counter==1)||(choice==0))
		sound(3*i);
		setcolor(1);
		line(320-i,0,320-i,480);
		line(320+i,0,320+i,480);
		line(0,320-i,640,320-i);
		line(0,160+i,640,160+i);
		delay(2);
		}
	nosound();
	closegraph();
	if (choice == 1)
		{
			account a ;
			a.display_account() ;
		}
		else
		if (choice == 2)
		{
			initial ini ;
			ini.display_list() ;
		}
		else
		if (choice == 3)
		{
			account a ;
			a.transaction() ;
		}
		else
		if (choice == 4)
		{
			account a ;
			a.new_account() ;
		}
		else
		if (choice == 5)
			edit_menu() ;
		else
		if (choice == 6)
			help() ;
		else
		if (choice == 0)
		{
			break;
		}
		}
	}
void toggle(int i,int temp)
{
	char m1[]="1:   SEE ACCOUNT     ",m2[]="2: LIST OF ACCOUNTS",m3[]="3:   TRANSACTIONS    ",
	     m4[]="4:   OPEN NEW ACCOUNT",m5[]="5: EDIT ACCOUNT	",m6[]="6:   HELP	       ",
	     m7[]="7:   QUIT            ";
	if (i==0) i=7;
	if (temp==0) temp=7;
		box(temp,7);
	switch(temp)
	{
		case 1: box(1,7);
			setcolor(15);
			outtextxy(320,90,m1);
			break;
		case 2: box(2,7);
			setcolor(15);
			outtextxy(320,150,m2);
			break;
		case 3: box(3,7);
			setcolor(15);
			outtextxy(320,210,m3);
			break;
		case 4: box(4,7);
			setcolor(15);
			outtextxy(320,270,m4);
			break;
		case 5: box(5,7);
			setcolor(15);
			outtextxy(320,330,m5);
			break;
		case 6: box(6,7);
			setcolor(15);
			outtextxy(320,390,m6);
			break;
		case 7: box(7,7);
			setcolor(15);
			outtextxy(320,450,m7);
			break;
	}

	switch(i)
	{
		case 1: box(1,9);
			setcolor(1);
			outtextxy(320,90,m1);
			break;
		case 2: box(2,9);
			setcolor(1);
			outtextxy(320,150,m2);
			break;
		case 3: box(3,9);
			setcolor(1);
			outtextxy(320,210,m3);
			break;
		case 4: box(4,9);
			setcolor(1);
			outtextxy(320,270,m4);
			break;
		case 5: box(5,9);
			setcolor(1);
			outtextxy(320,330,m5);
			break;
		case 6: box(6,9);
			setcolor(1);
			outtextxy(320,390,m6);
			break;
		case 7: box(7,9);
			setcolor(1);
			outtextxy(320,450,m7);
			break;
	}
}
void selected(int i)
{
	if(i==0) i=7;
	delay(350);
	setcolor(0);
		line(180,60*(i+.5)-20,180,60*(i+.5)+20);
		line(180,60*(i+.5)-20,460,60*(i+.5)-20);
	setcolor(15);
		line(460,60*(i+.5)-20,460,60*(i+.5)+20);
		line(180,60*(i+.5)+20,460,60*(i+.5)+20);
		line(461,60*(i+.5)-20,461,60*(i+.5)+21);
		line(180,60*(i+.5)+21,461,60*(i+.5)+21);
	delay(350);
	setcolor(15);
		line(180,60*(i+.5)-20,180,60*(i+.5)+20);
		line(180,60*(i+.5)-20,460,60*(i+.5)-20);
	setcolor(0);
		line(460,60*(i+.5)-20,460,60*(i+.5)+20);
		line(180,60*(i+.5)+20,460,60*(i+.5)+20);
		line(461,60*(i+.5)-20,461,60*(i+.5)+21);
		line(180,60*(i+.5)+21,461,60*(i+.5)+21);
}
void box(int i,int color)
{
	setcolor(5);
		line(180,60*(i+.5)-20,180,60*(i+.5)+20);
		line(180,60*(i+.5)-20,460,60*(i+.5)-20);
		line(460,60*(i+.5)-20,460,60*(i+.5)+20);
		line(180,60*(i+.5)+20,460,60*(i+.5)+20);
	setfillstyle(1,color);
	floodfill(320,60*(i+.5),5);
	setcolor(15);
		line(180,60*(i+.5)-20,180,60*(i+.5)+20);
		line(180,60*(i+.5)-20,460,60*(i+.5)-20);
	setcolor(0);
		line(460,60*(i+.5)-20,460,60*(i+.5)+20);
		line(180,60*(i+.5)+20,460,60*(i+.5)+20);
		line(461,60*(i+.5)-20,461,60*(i+.5)+21);
		line(180,60*(i+.5)+21,461,60*(i+.5)+21);
}


