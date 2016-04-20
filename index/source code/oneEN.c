#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
//#include "function_one.c"
#define three 3
#define four 4


FILE *output;
int ch;
int position=0;
int cipher[4][4];
int matrix[4][4];
int matrixkey[4][4];
int secondmatrix[4][4];//copy the first matrix
int mixcolumnmatrix[4][4];//to recieve ans from mixcolumn function
int copykey[4][4];//copy value in key
int nextmatrixkey[4][4];//next matrix 
int rconbox[10][4] = {{0x01, 0x00, 0x00, 0x00},
					{0x02, 0x00, 0x00, 0x00},
					{0x04, 0x00, 0x00, 0x00},
					{0x08, 0x00, 0x00, 0x00},
					{0x10, 0x00, 0x00, 0x00},
					{0x20, 0x00, 0x00, 0x00},
					{0x40, 0x00, 0x00, 0x00},
					{0x80, 0x00, 0x00, 0x00},
					{0x1b, 0x00, 0x00, 0x00},
					{0x36, 0x00, 0x00, 0x00}
					};

int s_box[16][16] = {
			{0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
			{0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
			{0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
			{0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
  			{0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
 	 		{0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
  			{0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
  			{0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
  			{0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
  			{0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
  			{0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
  			{0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
  			{0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
  			{0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
  			{0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
  			{0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}
		};
int manual_box[16][16] = {
			{0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0xf},
			{0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f},
			{0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f},
			{0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f},
  			{0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f},
 	 		{0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f},
  			{0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f},
  			{0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f},
  			{0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f},
  			{0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f},
  			{0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf},
  			{0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf},
  			{0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf},
  			{0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf},
  			{0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef},
  			{0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff}
		};


int tonum(char text);
int sub_byte(char index[][three], int subbyteround);
int shiftrow();
int mixcolumn();
int roundkey(int indexkey[][four], int rconround);
int sub_byte_key(char matrixkey[][three]);
int sub_roundkey(int matrixkey[][four]);


//GUI of program
int function_EN(char text[50000], char keep_en_de[3], char key[17], char pathout[10000]){
	int i, j, count, numberround, answer, rconround = 0, subbyteround = 0, allcycle, plusindex=0, countsixteen=0, checkascii, checkasciikey;
	double rounds;
	char plaintext[17] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	//char key[17] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char inputtext[10000];
	char index[16][3];
	char indexkey[16][3];
	char b[3], a[3];

	if (strcmp(keep_en_de, "FE")==0){
		strcpy(inputtext, text);
		
	}
	else{
		position=0;
		gotoxy(1,1);
		printf(" AES Project Group ");
		gotoxy(20, 5);
		printf("Input Text: ");

		gets(inputtext);

		
		gotoxy(20, 6);
		printf("--------------------------------------------------------------------");
		gotoxy(20, 9);
		printf("Input Key: ");
		scanf(" %[^\n]s\n", key);
		
		gotoxy(20, 10);
		printf("--------------------------------------------------------------------");
		gotoxy(45, 13);
		printf("This is you Encryption");
		gotoxy(45, 14);
		printf("***********************");
		
	}
	
	
	
	//to calculate number of rounds that program have to do.
	rounds = ceil(strlen(inputtext)/16.0);
	//printf("%lf\n", ceil(rounds));
	//printf("%d\n", strlen(inputtext));
	for(allcycle=0; allcycle<rounds; allcycle++){
		countsixteen = 0;
		rconround = 0;
		countsixteen=0;
		subbyteround = 0;
		char index[16][3] = {{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'},{'\0','\0'}};
		char plaintext[17] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
		for(i=0+(16*plusindex); i<(16*(plusindex+1)); i++){
			checkascii = (256 + ((int) inputtext[i]))%256;
			checkasciikey = (256 + ((int) key[countsixteen]))%256;
			//printf("%d\n", checkascii);
			sprintf(a, "%x", checkascii);
			sprintf(b, "%x", checkasciikey);
			strcpy(index[countsixteen], a);
			strcpy(indexkey[countsixteen], b);
			//printf("%s\n", index[countsixteen]);
			countsixteen++;
		}
		plusindex++;

		//printf("-------------------------------------------\n");
		for(i=0; i<16; i++){//we do add round key first before do 10 loop
			if(strlen(index[i])==1){
				index[i][1] = index[i][0];
				index[i][0] = '0';
			}
			if(strlen(indexkey[i])==1){
				indexkey[i][1] = indexkey[i][0];
				indexkey[i][0] = '0';
			}
			//printf("%x\n", manual_box[(tonum(indexkey[i][0]))][(tonum(indexkey[i][1]))]^manual_box[(tonum(index[i][0]))][(tonum(index[i][1]))]);
			answer = manual_box[(tonum(index[i][0]))][(tonum(index[i][1]))]^manual_box[(tonum(indexkey[i][0]))][(tonum(indexkey[i][1]))];
			//printf("%d\n", answer);
			sprintf(a, "%x", answer);
			//printf("%s\n", a);
			strcpy(index[i], a);
			//printf("%s\n", index[i]);
		}
		for(numberround=1; numberround<=10; numberround++){
			//printf("%d %d\n", rconround,subbyteround);
			if(numberround==1){
				sub_byte_key(indexkey);
				roundkey(matrixkey, rconround);
			}
			else{
				roundkey(matrixkey, rconround);
			}
			//printf("roundkey:\n");
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					//printf("%x ", matrixkey[i][j]);
				}
				//printf("\n");
			}
			sub_byte(index, subbyteround);
			//printf("-------------------------------------------\n");
			//printf("Subbyte:\n");
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					//printf("%x ", matrix[i][j]);
				}
				//printf("\n");
			}
			//printf("-------------------------------------------\n");
			shiftrow();
			//printf("shiftrow value:\n");
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					//printf("%x ", matrix[i][j]);
				}
				//printf("\n");
			}
			//printf("-------------------------------------------\n");
			if(numberround<10){
				mixcolumn();
				//printf("mixcolumn value:\n");
				for(i=0; i<4; i++){
					for(j=0; j<4; j++){
						//printf("%x ", matrix[i][j]);
				}
					//printf("\n");
				}
			}
			//printf("-------------------------------------------\n");
			addroundkey();
			//printf("Addroundkey value:\n");
			if(numberround==10){
	        for(i=0; i<4; i++){
	          for(j=0; j<4; j++){
			  position = position + 3;
			  gotoxy(17 + position,15);
				printf("%02x ", matrix[j][i]);   //AUS
	            fprintf(output, "%02x ", matrix[j][i]);
  
	          }
	          //printf("\n");
	        }
	        
	      //printf("\n");
	      }
	      subbyteround++;
	      rconround++;

		}
		
	}
	if (strcmp(keep_en_de, "TE")==0){
		printf("EN");
		while ((ch = _getch()) != 27){
		gotoxy(40, 3);
  		printf("ESC, if you want to back  Main function");
  		gotoxy(40, 2);
  		printf("---------------------------------------");
  		gotoxy(40, 4);
  		printf("---------------------------------------");	
			
	}
	function_exit();
	}
	
}	



int sub_byte(char index[][three], int subbyteround){
	/*we do subbyte in this function we change the value if number by look in s_box table
	Ex: 0x00 --> 0x63;
*/
	int count=0, i, j, k;
  	int a, b;
  	char numbersub[3];
  	//printf("subbyte value:\n");
  	if(subbyteround==0){
  		for(k=0; k<16; k++){
  			if(strlen(index[k])==1){
					index[k][1] = index[k][0];
					index[k][0] = '0';
				}
  		}
  		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				a = tonum(index[count][0]);
				b = tonum(index[count][1]);
				//printf("%d %d %d\n", a, b, s_box[a][b]);
				matrix[j][i] = s_box[a][b];
				secondmatrix[j][i] = s_box[a][b];
				count++;
			}
		}
  	}
  	else{ 
  		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				sprintf(numbersub, "%x", matrix[j][i]);
				if(strlen(numbersub)==1){
					numbersub[1] = numbersub[0];
					numbersub[0] = '0';
				}
				a = tonum(numbersub[0]);
				b = tonum(numbersub[1]);
				//printf("%d %d\n", a, b);
				//printf("%d %d %d\n", a, b, s_box[a][b]);
				matrix[j][i] = s_box[a][b];
				secondmatrix[j][i] = s_box[a][b];
			}
		}
  	}
	
}

int tonum(char text){
	/* we change a str number in to int number we cannot use atoi function because we use hexadecimalnumber*/
	if(text == 'a'){return 10;}
	else if(text == 'b'){return 11;}
	else if(text == 'c'){return 12;}
	else if(text == 'd'){return 13;}
	else if(text == 'e'){return 14;}
	else if(text == 'f'){return 15;}
	else if(text == '\0') return '\0';
	else return (int)(text - 48);
}

int shiftrow(){
	/*we do shiftrow in this function we change the index like
	1 2 3 4 --> 1 2 3 4
	5 6 7 8 --> 6 7 8 5
	9 a b c --> b c 9 a
	d e f 0 --> 0 d e f 
*/
	matrix[1][0] = secondmatrix[1][1];
	matrix[1][1] = secondmatrix[1][2];
	matrix[1][2] = secondmatrix[1][3];
	matrix[1][3] = secondmatrix[1][0];

	matrix[2][0] = secondmatrix[2][2];
	matrix[2][1] = secondmatrix[2][3];
	matrix[2][2] = secondmatrix[2][0];
	matrix[2][3] = secondmatrix[2][1];

	matrix[3][0] = secondmatrix[3][3];
	matrix[3][1] = secondmatrix[3][0];
	matrix[3][2] = secondmatrix[3][1];
	matrix[3][3] = secondmatrix[3][2];

}


// xtime is a macro that finds the product of {02} and the argument to xtime modulo {1b}  
#define xtime(x)   ((x<<1) ^ (((x>>7) & 1) * 0x1b))

// MixColumns function mixes the columns of the state matrix
int mixcolumn()
{
	int i;
	unsigned char Tmp,Tm,t;
	for(i=0;i<4;i++)
	{	
		t=matrix[0][i];
		Tmp = matrix[0][i] ^ matrix[1][i] ^ matrix[2][i] ^ matrix[3][i] ;
		Tm = matrix[0][i] ^ matrix[1][i] ; Tm = xtime(Tm); matrix[0][i] ^= Tm ^ Tmp ;
		Tm = matrix[1][i] ^ matrix[2][i] ; Tm = xtime(Tm); matrix[1][i] ^= Tm ^ Tmp ;
		Tm = matrix[2][i] ^ matrix[3][i] ; Tm = xtime(Tm); matrix[2][i] ^= Tm ^ Tmp ;
		Tm = matrix[3][i] ^ t ; Tm = xtime(Tm); matrix[3][i] ^= Tm ^ Tmp ;
	}
}


int sub_byte_key(char indexkey[][three]){
	/* we use this function to change value of str key to int key*/
	int count=0, i, j;
  	int a, b;
  	//printf("subbyte value key:\n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if(strlen(indexkey[count])==1){
				indexkey[count][1] = indexkey[count][0];
				indexkey[count][0] = '0';
			}
			a = tonum(indexkey[count][0]);
			b = tonum(indexkey[count][1]);
			//printf("%d %d %d\n", a, b, s_box[a][b]);
			matrixkey[j][i] = manual_box[a][b];
			copykey[j][i] = manual_box[a][b];
			count++;
		}
	}
}

int sub_roundkey(int matrixkey[][four]){
	/*we have to subbyte the first row of the matrix to do a round keys function*/
	int i, ans1, ans2;
	char b[3], a[3];
	for(i=0; i<4; i++){
		sprintf(a, "%x", matrixkey[i][3]);
		if(strlen(a)==1){
			a[1] = a[0];
			a[0] = '0' ;
		}
		ans1 = tonum(a[0]);
		ans2 = tonum(a[1]);
		nextmatrixkey[i][0] = s_box[ans1][ans2];
	}
}


int roundkey(int indexkey[][four], int rconround){
	/*we have to get value of key in 10 round by use this function
		1. we arrange index if row 1  > 4
								   2  >	1
								   3  >	2
								   4  >	3

		2.we use row that arrange xor with row that before it.
	*/
	int i, j;
	matrixkey[0][3] = copykey[1][3];
	matrixkey[1][3] = copykey[2][3];
	matrixkey[2][3] = copykey[3][3];
	matrixkey[3][3] = copykey[0][3];
	
	sub_roundkey(matrixkey);
	for(i=0; i<4; i++){
		nextmatrixkey[i][0] = nextmatrixkey[i][0]^rconbox[rconround][i]^matrixkey[i][0];
	}
	for(i=1; i<4; i++){
		for(j=0; j<4; j++){
			//printf("%x %x\n", nextmatrixkey[j][i-1], copykey[j][i]);
			nextmatrixkey[j][i] = nextmatrixkey[j][i-1]^copykey[j][i];
		}
	}
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			matrixkey[j][i] = nextmatrixkey[j][i];
			copykey[j][i] = nextmatrixkey[j][i];
		}
	}
}


int addroundkey(){
	/*we get answer from mix column xor with round key from each round*/
	int i, j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			matrix[j][i] = matrixkey[j][i]^matrix[j][i];
		}
	}
	
}

