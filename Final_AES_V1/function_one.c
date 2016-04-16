#include<stdio.h>
#include<windows.h>
#include <string.h>
#include <stdlib.h>

#include "oneDE.c"
#include "oneEN.c"
//----------------------------------------////----------------------------------------//
FILE *f_ptr;
FILE *output;
char text[50000],new_text[50000];
int ch;
char  path[10000], pathout[10000]; 
char keep_type;
char keep_en_de[3];
char name[50000], key[17] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
int function_exit();
int function_text();
int function_file();
int function_name_project();
int de_or_en();
//----------------------------------------////----------------------------------------//
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
	
	
  *//*  gotoxy(0,2);
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
  
//----------------------------------------////----------------------------------------//
void gotoxy(int x, int y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//----------------------------------------////----------------------------------------//
int main()
{
  
  int i;
  system("cls");
  system("COLOR A");
  function_name_project();
  
  
  gotoxy(45,10);
  printf("Plase you selec File or Text");
  gotoxy(45,11);
  printf("----------------------------");
  gotoxy(45,13);
  printf(">   File > import existing text file");
  gotoxy(45,15);
  printf(">   Text > type your text to program");
  
  gotoxy(3, 3);
  printf("     The Advanced Encryption Standard (AES) is an encryption standard adopted by the U.S. government. The standard");
  gotoxy(3, 4);
  printf("comprises three block ciphers, AES-128, AES-192 and AES-256, adopted from a larger collection originally published ");
  gotoxy(3, 5);
  printf("as Rijndael. Each AES cipher has a 128-bit block size, with key sizes of 128, 192 and 256 bits, respectively.");
  gotoxy(3, 6);
  printf("The AES ciphers have been analyzed extensively and are now used worldwide, as was the case with its predecessor,");
  gotoxy(3, 7);
  printf("the Data Encryption Standard (DES).");
  	if (strcmp(keep_en_de, "FD")==0){
  		gotoxy(45, 17);	
		printf("   Plead you close Program AES!");   //AUS
		gotoxy(45, 18);	
		printf("  if you want to open file Des.txt");   //AUS
	}
  
  gotoxy(25, 19);
  printf("******************************************************************");
  gotoxy(25, 20);
  printf("**                                                              **");
  gotoxy(25, 21);
  printf("**     Advanced Encryption Standard implementation in C.        **");
  gotoxy(25, 22);
  printf("**     By AES Project Group                                     **");
  gotoxy(25, 23);
  printf("**     Faculty of Information Technology, KMITL                 **");
  gotoxy(25, 24);
  printf("**     https://github.com/GunTH13/AES-Project-CP58-.git         **");
  gotoxy(25, 25);
  printf("**                                                              **");
  gotoxy(25, 26);
  printf("******************************************************************");

  while((ch = _getch()) != 13)  /* 13 = Enter key */
  {
  	
  	if(ch == 72){
        keep_type ='0';
        //
        gotoxy(45,10);
  		printf("Plase you selec File or Text");
  		gotoxy(45,11);
  		printf("----------------------------");
		gotoxy(45,13);
  		printf("--> File > import existing text file");
  		gotoxy(45,15);
  		printf("    Text > type your text to program");
  		}
  		
  		
	else if (ch == 80){
        keep_type = '1';
        //system("cls");
        gotoxy(45,10);
  		printf("Plase you selec File or Text");
  		gotoxy(45,11);
  		printf("----------------------------");
  		gotoxy(45,13);
  		printf("    File > import existing text file");
		gotoxy(45,15);
  		printf("--> Text > type your text to program");
  		}
  
	}
	if (keep_type == '1'){
  		//
  		strcpy(keep_en_de, "T0");
  		system("cls");
  		de_or_en();
  		//function_text();
	  }
	else if (keep_type == '0'){
		//
		strcpy(keep_en_de, "F0");
		system("cls");
		de_or_en();
		//function_file();
	}
  getch();

}
//----------------------------------------////----------------------------------------//
int de_or_en(int i){
	
  keep_type = '6';
  
  system("COLOR A");
  i = i;  
  function_name_project();
  
  gotoxy(3, 3);
  printf("     The Advanced Encryption Standard (AES) is an encryption standard adopted by the U.S. government. The standard");
  gotoxy(3, 4);
  printf("comprises three block ciphers, AES-128, AES-192 and AES-256, adopted from a larger collection originally published ");
  gotoxy(3, 5);
  printf("as Rijndael. Each AES cipher has a 128-bit block size, with key sizes of 128, 192 and 256 bits, respectively.");
  gotoxy(3, 6);
  printf("The AES ciphers have been analyzed extensively and are now used worldwide, as was the case with its predecessor,");
  gotoxy(3, 7);
  printf("the Data Encryption Standard (DES).");
  
  
  gotoxy(25, 19);
  printf("******************************************************************");
  gotoxy(25, 20);
  printf("**                                                              **");
  gotoxy(25, 21);
  printf("**     Advanced Encryption Standard implementation in C.        **");
  gotoxy(25, 22);
  printf("**     By AES Project Group                                     **");
  gotoxy(25, 23);
  printf("**     Faculty of Information Technology, KMITL                 **");
  gotoxy(25, 24);
  printf("**     https://github.com/GunTH13/AES-Project-CP58-.git         **");
  gotoxy(25, 25);
  printf("**                                                              **");
  gotoxy(25, 26);
  printf("******************************************************************");
  
  gotoxy(45, 10+i);
  printf("Plase you selec encrypt or decrypt");
  gotoxy(45, 12+i);
  printf(">   Encrypt");
  gotoxy(45, 14+i);
  printf(">   Decrypt");
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
  		f_ptr = NULL;
		function_exit();
	}
	}
	if (keep_type == '1'){     // 1 is Decrypt          
  		if (strcmp(keep_en_de, "T0")==0){
  			strcpy(keep_en_de, "TD");    // sent to function_text of De
  			system("cls");
  			gotoxy(50,1);
			printf(" AES Project Group ");
			function_DE(text, keep_en_de, key, pathout);
		  }
  		else {
  			strcpy(keep_en_de, "FD");   // sent to function_file of De
			function_file();
		  }
	  }  
	  
	else if (keep_type == '0'){   // 0 is encrypt       
		if(strcmp(keep_en_de, "T0")==0){          // sent to function_file of En
			strcpy(keep_en_de, "TE");    
			//function_text();
			system("cls");
			function_name_project();
			function_EN(text, keep_en_de, key, pathout);	
		}
		else{
			strcpy(keep_en_de, "FE");    // sent to function_text of En
			function_file();
		}
		
	}	
	
  getch();
}
//----------------------------------------////----------------------------------------//
int function_file(){
	
	int i;
	char new_path[10000];
	/*strcpy(path, "C:\\Users\\oat_t\\Desktop\\work\\AES proj test\\test.txt");*/ //reserve path!
	system("cls");
	function_name_project();
	/*gotoxy(45,15);
  	printf("%c", keep_type);
  	gotoxy(45,16);
  	printf("%s", keep_en_de);
  	*/
  	
	gotoxy(25,4);
	printf("Drag file here: ");
	scanf(" %[^\n]*c", new_path);
	if (new_path[0] == '\"')
  		strncpy(path, &new_path[1], strlen(new_path)-2);
 	else
  		strcpy(path, new_path);
	system("cls");
	f_ptr = fopen(path, "r+t");
	/* open file, mode > r = read exist file, w = create new file, +t = can put new text */

	//system("cls");
	function_name_project();
	if (!f_ptr) /* Or use f_ptr == NULL */
	{
		gotoxy(45,4);
		printf("Can't open file! \n\n\n");
		gotoxy(45,5);
		printf("This is your path: %s", path);
		exit(0);
		// don't make a  "Can't open file function"                                !!!!
	}
	else{
	//gotoxy(25,4);
	//printf("This is your path: %s", path);
	//fscanf(f_ptr, "%[^\n]", text);

	gotoxy(25,3);
	printf("what's in your file:  %s", path);
	gotoxy(25,5);
	printf("---------------------------------------------------------------------------");
	
	strncpy(pathout, path, strlen(path)-4);
	//printf("%s", pathout);
	if (strcmp(keep_en_de, "FE")==0){
		strcat(pathout, "_Cipher.txt");
	}
	
	else{
		strcat(pathout, "_Des.txt");
	}
	
	output = fopen(pathout, "w+t");
	gotoxy(25,7);
	printf("---------------------------------------------------------------------------");
	gotoxy(25,9);
	printf("---------------------------------------------------------------------------");
	gotoxy(45,8);
	printf("IN PUT YOU Key  == >  ");
	scanf("%s", key);

	memset(path,'\0',10000);
	while(fscanf(f_ptr, "%[^\n] ", text) != EOF)
	{
		i++;
		gotoxy(8,14+i);
		printf("%s", text);
	}
	printf("\n\n\n");
	while ((ch = _getch()) != 32){
		printf("                     ---------------------------------------------------------------------------\n");
  		printf("                                             Click > Space < toContinue                        \n     ");
  		printf("                ---------------------------------------------------------------------------\n");	
			
	}
	
	
	fseek(f_ptr, 0, SEEK_SET);
	system("cls");
	function_name_project();
	gotoxy(45, 5);
	printf("This is you Encryption");
	gotoxy(45, 7);
	printf("----------------------\n\n");
	//printf("%s", keep_en_de);
	while(fscanf(f_ptr, "%[^\n] ", text) != EOF)
		{
			if (strcmp(keep_en_de, "FE")==0){
				function_EN(text, keep_en_de, key, pathout);
				fprintf(output, "EN");
				fprintf(output,"%c", '\n');
			}
			else if (strcmp(keep_en_de, "FD")==0){  // "FD"
				
				//strcat(text, "EN");
				//printf("%s \n", text);
				function_DE(text, keep_en_de, key, pathout);
				fprintf(output,"%c", '\n');
			}
		}
	}
	if (strcmp(keep_en_de, "FE")==0){
		printf("EN");   //AUS
	}
	getch();
	while ((ch = _getch()) != 27){
		gotoxy(35, 9);
  		printf("ESC, if you want to back  Main function");
  		gotoxy(35, 8);
  		printf("---------------------------------------");
  		gotoxy(35, 10);
  		printf("---------------------------------------");	
  		
			
	}
	getch();
	function_exit();
}
//----------------------------------------////----------------------------------------//
int function_file_output(){
	char new_text[50000];
	int i;	
}
//----------------------------------------////----------------------------------------//
int function_text(){
  	system("cls");
  	int i;
  	system("cls");
  	function_name_project();
 	i = 0;
 	de_or_en(i);
 	getch();
  }
//----------------------------------------////----------------------------------------//
int function_exit(){
	
	int i;
	char text[50000],new_text[50000];
	int ch;
	char  path[10000], pathout[10000]; 
	char keep_type;
	char keep_en_de[3];
	char name[50000], key[17] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	main();
	
}  

//----------------------------------------////----------------------------------------//
int function_name_project(){
	gotoxy(50,1);
	printf(" AES Project Group ");
	return 1;
}
//----------------------------------------////----------------------------------------//



//----------------------------------------////----------------------------------------//
//----------------------------------------////----------------------------------------//
//----------------------------------------////----------------------------------------//
//----------------------------------------////----------------------------------------//
//----------------------------------------////----------------------------------------//






