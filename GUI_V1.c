#include<stdio.h>
#include<windows.h>
#include <string.h>
#include <stdlib.h>

int ch;
char keep_type;
char keep_en_de[3];
char name[50000], key[50000];
int function_exit();
int function_text();
int function_file();
int de_or_en();
//----------------------------------------////----------------------------------------//
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
  

//----------------------------------------////----------------------------------------//
int main()
{
  int i;
  system("cls");
  system("COLOR A");
/*  gotoxy(0,2);
  printf("      ___  __      __   __   __        ___  __  ___     __   __   __        __  ");
  gotoxy(1,3);
  //printf("/ _ \ |  ___/  ___| | ___ \        (_)         | |   |  __ \                      ");
  gotoxy(1,4);
  //printf("/ /_\ \| |__ \ `--.  | |_/ / __ ___  _  ___  ___| |_  | |  \/_ __ ___  _   _ _ __ ");
  gotoxy(1,5);
  //printf("|  _  ||  __| `--. \ |  __/ '__/ _ \| |/ _ \/ __| __| | | __| '__/ _ \| | | | '_ \ ");
  gotoxy(1,6);
  //printf("| | | || |___/\__/ / | |  | | | (_) | |  __/ (__| |_  | |_\ \ | | (_) | |_| | |_) |");
  gotoxy(1,7);
  //printf("\_| |_/\____/\____/  \_|  |_|  \___/| |\___|\___|\__|  \____/_|  \___/ \__,_| .__/ ");
  gotoxy(1,8);
  //printf("                                   _/ |                                     | |    ");
  gotoxy(1,9);
  //printf("                                  |__/                                      |_|    ");
  
  */
  
  
  gotoxy(45,10);
  printf("Plase you selec File or Text");
  gotoxy(45,13);
  printf("--> File");
  gotoxy(45,15);
  printf("    Text");
  
  while((ch = _getch()) != 13)  /* 13 = Enter key */
  {
  	if(ch == 72){
        keep_type ='0';
        //system("cls");
        gotoxy(45,10);
  		printf("Plase you selec File or Text");
		gotoxy(45,13);
  		printf("--> File");
  		gotoxy(45,15);
  		printf("    Text");
  		}
  		
  		
	else if (ch == 80){
        keep_type = '1';
        //system("cls");
        gotoxy(45,10);
  		printf("Plase you selec File or Text");
  		gotoxy(45,13);
  		printf("    File");
		gotoxy(45,15);
  		printf("--> Text");
  		}
  
	}
	if (keep_type == '1'){
  		//
  		strcpy(keep_en_de, "T0");
  		//de_or_en();
  		function_text();
	  }
	else if (keep_type == '0'){
		//
		strcpy(keep_en_de, "F0");
		//de_or_en();
		function_file();
	}
  getch();

}
//----------------------------------------////----------------------------------------//
int de_or_en(int i){
	
  keep_type = '6';

  system("COLOR C");
  i = i+3;  

  
  gotoxy(45, 10+i);
  printf("Plase you selec encrypt or decrypt");
  gotoxy(45, 12+i);
  printf("--> Encrypt");
  gotoxy(45, 14+i);
  printf("    Decrypt");
  gotoxy(45, 16+i);
  printf("ESC, if you want to back  Main function");
  gotoxy(45, 15+i);
  printf("---------------------------------------");
  gotoxy(45, 17+i);
  printf("---------------------------------------");
  
  while((ch = _getch()) != 13)  /* 13 = Enter key */
  {
  	if(ch == 72){
        keep_type ='0';  // 0 is encrypt
        //system("cls");
        gotoxy(45,10+i);
  		printf("Plase you selec encrypt or decrypt");
		gotoxy(45,12+i);
  		printf("--> Encrypt");
  		gotoxy(45,14+i);
  		printf("    Decrypt");
  		gotoxy(45, 16+i);
  		printf("ESC, if you want to back  Main function");
  		gotoxy(45, 15+i);
  		printf("---------------------------------------");
  		gotoxy(45, 17+i);
  		printf("---------------------------------------");
  		}
  		
  		
	else if (ch == 80){
        keep_type = '1';  // 1 is Decrypt
        //system("cls");
        gotoxy(45, 10+i);
  		printf("Plase you selec encrypt or decrypt");
  		gotoxy(45, 12+i);
  		printf("    Encrypt");
		gotoxy(45, 14+i);
  		printf("--> Decrypt");
  		gotoxy(45, 16+i);
  		printf("ESC, if you want to back  Main function");
  		gotoxy(45, 15+i);
  		printf("---------------------------------------");
  		gotoxy(45, 17+i);
  		printf("---------------------------------------");
  		}
  	else if (ch==27){
		gotoxy(45, 16+i);
  		printf("ESC");
		function_exit();
	}
	}
	if (keep_type == '1'){     // 1 is Decrypt          
  		if (strcmp(keep_en_de, "T0")==0){
  			strcpy(keep_en_de, "TD");    // sent to function_text of De
			//function_text();
		  }
  		else {
  			strcpy(keep_en_de, "FD");   // sent to function_file of De
			//function_file();
		  }
	  }  
	  
	else if (keep_type == '0'){   // 0 is encrypt       
		if(strcmp(keep_en_de, "T0")==0){          // sent to function_file of En
			strcpy(keep_en_de, "TE");    
			//function_text();	
		}
		else{
			strcpy(keep_en_de, "FE");    // sent to function_text of En
			//function_file();
		}
		
	}	
	
  getch();
}
//----------------------------------------////----------------------------------------//
int function_file(){
	
	FILE *f_ptr;
	int i;
	char text[50000], path[10000], new_text[50000];
	/*strcpy(path, "C:\\Users\\oat_t\\Desktop\\work\\AES proj test\\test.txt");*/ //reserve path!
	system("cls");
	
	/*gotoxy(45,15);
  	printf("%c", keep_type);
  	gotoxy(45,16);
  	printf("%s", keep_en_de);
  	*/
  	
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
	//gotoxy(25,4);
	//printf("This is your path: %s", path);
	//fscanf(f_ptr, "%[^\n]", text);

	gotoxy(25,6);
	printf("what's in your file:  %s", path);
	gotoxy(25,7);
	printf("---------------------------------------------------------------------------");
	while(fscanf(f_ptr, "%[^\n] ", text) != EOF)
	{
		i++;
		gotoxy(8,8+i);
		printf("%s", text);		
	}
	}

	gotoxy(25,8+i+2);
	printf("---------------------------------------------------------------------------");
	gotoxy(25,8+i+4);
	printf("---------------------------------------------------------------------------");
	gotoxy(45,8+i+3);
	printf("IN PUT YOU Key  == >  ");
	scanf("%s", key);
	//while ((ch = _getch()) != 13){
		
	//}

	de_or_en(i);

	getch();
}

//----------------------------------------////----------------------------------------//
int function_text(){
  	system("cls");
  	int i;
  	system("cls");
	
	/*gotoxy(45,15);
  	printf("%c", keep_type);
  	gotoxy(45,16);
  	printf("%s", keep_en_de);
  	*/
  	gotoxy(35, 2);
  	printf("AES Text");
  	
 	system("COLOR A");
	gotoxy(35,4);
 	printf("IN PUT YOU TEXT == >  ");
 	scanf("%s", name);
 	
 	gotoxy(35,6);
 	printf("------------------------------------------------------");
 	
 	system("COLOR A");
 	gotoxy(35,8);
 	printf("IN PUT YOU Key  == >  ");
 	scanf("%s", key);
 	i = 0;
 	de_or_en(i);
 	getch();
  }
//----------------------------------------////----------------------------------------//
int function_exit(){
	
	int i;
	char text[50000], path[10000], new_text[50000];
	
	
	int ch;
	char keep_type;
	char keep_en_de[3];
	char name[50000], key[50000];
	
	main();
}  
