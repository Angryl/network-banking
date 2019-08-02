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

