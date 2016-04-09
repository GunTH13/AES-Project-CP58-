#include<stdio.h>
#include<windows.h>
#include <string.h>
#include <stdlib.h>

int ch;
char keep_type;
int function_exit();
int function_text();
int function_file();
//----------------------------------------//
void gotoxy(int x, int y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/*
  0 = Black
	1 = Blue
	2 = Green
	3 = Aqua
	4 = Red
	5 = Purple
	6 = Yellow
	7 = White
	8 = Gray
	9 = Light Blue
	A = Light Green
	B = Light Aqua
	C = Light Red
	D = Light Purple
	E = Light Yellow
	F = Bright White
	
	F Gotoxy is Set Position of Text
	F Getch  is Fisiht F
	
	
  */

//----------------------------------------//
int main()
{
  int i;
  system("cls");

  /*for (i=0; i<10; i++){
    gotoxy(35,3+i);
    printf("|");
  }
  for (i=0; i<10; i++){
    gotoxy(85,3+i);
    printf("|");
  }
  for (i=0; i<50; i++){
    gotoxy(35+i,2);
    printf("_");
  }
  for (i=0; i<50; i++){
    gotoxy(35+i,12);
    printf("_");
  }*/
  
  
  system("COLOR A");
  gotoxy(45,4);
  printf("Plase you selec File or Text");
  gotoxy(45,7);
  printf("    File");
  gotoxy(45,9);
  printf("    Text");
  
  while((ch = _getch()) != 13)  /* 13 = Enter key */
  {
  	if(ch == 72){
        keep_type ='0';
        system("cls");
        gotoxy(45,4);
  		printf("Plase you selec File or Text");
		gotoxy(45,7);
  		printf("--> File");
  		gotoxy(45,9);
  		printf("    Text");
  		}
  		
  		
	else if (ch == 80){
        keep_type = '1';
        system("cls");
        gotoxy(45,4);
  		printf("Plase you selec File or Text");
  		gotoxy(45,7);
  		printf("    File");
		gotoxy(45,9);
  		printf("--> Text");
  		}
  
	}
	if (keep_type == '1'){
  		function_text();
	  }
	else if (keep_type == '0'){
		function_file();
	}
  getch();

}
//----------------------------------------//
int function_file(){
	
	FILE *f_ptr;
	char text[50], path[100], new_text[50];
	/*strcpy(path, "C:\\Users\\oat_t\\Desktop\\work\\AES proj test\\test.txt");*/ //reserve path!
	system("cls");
	gotoxy(25,4);
	printf("Drag file here: ");
	scanf("\"%[^\"]\"", path);
	
	f_ptr = fopen(path, "r+t");
	/* open file, mode > r = read exist file, w = create new file, +t = can put new text */
	
	system("cls");
	if (!f_ptr) /* Or use f_ptr == NULL */
	{
		gotoxy(45,4);
		printf("Can't open file! \n\n\n");
		exit(0);
		// don't make a  "Can't open file function"                                !!!!
	}
	else{
	
	gotoxy(25,4);
	printf("This is your path: %s", path);
	fscanf(f_ptr, "%[^\n]", text);

	gotoxy(25,8);
	printf("This is your Text -->  %s", text);
	}
	getch();
}




//----------------------------------------//
int function_text(){
  	system("cls");
  	char name[567899];
  	system("cls");
  	gotoxy(45,4);
 	system("COLOR A");
 	printf("IN PUT YOU TEXT == >");
 	gotoxy(45,8);
 	scanf("%s", name);
 	
 	getch();
  }
//----------------------------------------//
int function_exit(){
	main();
}  
