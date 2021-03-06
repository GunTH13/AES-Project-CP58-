#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define three 3
#define four 4

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
int rs_box[16][16] = {{0X52, 0x09, 0X6a, 0Xd5, 0X30, 0X36, 0Xa5, 0X38, 0Xbf, 0X40, 0Xa3, 0X9e, 0X81, 0Xf3, 0Xd7, 0Xfb},
  			{0X7c, 0Xe3, 0X39, 0X82, 0X9b, 0X2f, 0Xff, 0X87, 0X34, 0X8e, 0X43, 0X44, 0Xc4, 0Xde, 0Xe9, 0Xcb},
  			{0X54, 0X7b, 0X94, 0X32, 0Xa6, 0Xc2, 0X23, 0X3d, 0Xee, 0X4c, 0X95, 0X0b, 0X42, 0Xfa, 0Xc3, 0X4e},
  			{0X08, 0X2e, 0Xa1, 0X66, 0X28, 0Xd9, 0X24, 0Xb2, 0X76, 0X5b, 0Xa2, 0X49, 0X6d, 0X8b, 0Xd1, 0X25},
  			{0X72, 0Xf8, 0Xf6, 0X64, 0X86, 0X68, 0X98, 0X16, 0Xd4, 0Xa4, 0X5c, 0Xcc, 0X5d, 0X65, 0Xb6, 0X92},
  			{0X6c, 0X70, 0X48, 0X50, 0Xfd, 0Xed, 0Xb9, 0Xda, 0X5e, 0X15, 0X46, 0X57, 0Xa7, 0X8d, 0X9d, 0X84},
  			{0X90, 0Xd8, 0Xab, 0X00, 0X8c, 0Xbc, 0Xd3, 0X0a, 0Xf7, 0Xe4, 0X58, 0X05, 0Xb8, 0Xb3, 0X45, 0X06},
  			{0Xd0, 0X2c, 0X1e, 0X8f, 0Xca, 0X3f, 0X0f, 0X02, 0Xc1, 0Xaf, 0Xbd, 0X03, 0X01, 0X13, 0X8a, 0X6b},
  			{0X3a, 0X91, 0X11, 0X41, 0X4f, 0X67, 0Xdc, 0Xea, 0X97, 0Xf2, 0Xcf, 0Xce, 0Xf0, 0Xb4, 0Xe6, 0X73},
  			{0X96, 0Xac, 0X74, 0X22, 0Xe7, 0Xad, 0X35, 0X85, 0Xe2, 0Xf9, 0X37, 0Xe8, 0X1c, 0X75, 0Xdf, 0X6e},
  			{0X47, 0Xf1, 0X1a, 0X71, 0X1d, 0X29, 0Xc5, 0X89, 0X6f, 0Xb7, 0X62, 0X0e, 0Xaa, 0X18, 0Xbe, 0X1b},
  			{0Xfc, 0X56, 0X3e, 0X4b, 0Xc6, 0Xd2, 0X79, 0X20, 0X9a, 0Xdb, 0Xc0, 0Xfe, 0X78, 0Xcd, 0X5a, 0Xf4},
  			{0X1f, 0Xdd, 0Xa8, 0X33, 0X88, 0X07, 0Xc7, 0X31, 0Xb1, 0X12, 0X10, 0X59, 0X27, 0X80, 0Xec, 0X5f},
  			{0X60, 0X51, 0X7f, 0Xa9, 0X19, 0Xb5, 0X4a, 0X0d, 0X2d, 0Xe5, 0X7a, 0X9f, 0X93, 0Xc9, 0X9c, 0Xef},
  			{0Xa0, 0Xe0, 0X3b, 0X4d, 0Xae, 0X2a, 0Xf5, 0Xb0, 0Xc8, 0Xeb, 0Xbb, 0X3c, 0X83, 0X53, 0X99, 0X61},
  			{0X17, 0X2b, 0X04, 0X7e, 0Xba, 0X77, 0Xd6, 0X26, 0Xe1, 0X69, 0X14, 0X63, 0X55, 0X21, 0X0c, 0X7d}};
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

int main(){
	int rounds, i, j, count, numberround, answer, rconround = 0, subbyteround = 0;;
	char plaintext[17] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char key[17] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	char index[16][3];
	char indexkey[16][3];
	char b[3], a[3];
	printf("Input Text: ");
	gets(plaintext);
	printf("Input Key: ");
	scanf(" %[^\n]s\n", key);
	rounds = ceil(strlen(plaintext)/16);
	for(i=0; i<16; i++){
		sprintf(a, "%x", plaintext[i]); /* keep char ascii to hex base */
		sprintf(b, "%x", key[i]);
		strcpy(index[i], a);
		strcpy(indexkey[i], b);
		//printf("%x\n", index[i]);
		//printf("%s\n", indexkey[i]);
	}
	for(i=0; i<16; i++){//we do add round key first before do 10 loop
			//printf("%d\n", (((tonum(index[i][0]))*10)+(tonum(index[i][1]))));
			answer = (((tonum(index[i][0]))*10)+(tonum(index[i][1])))^(((tonum(indexkey[i][0]))*10)+(tonum(indexkey[i][1])));
			printf("%d\n", answer);
			sprintf(a, "%x", answer);
			printf("%s\n", a);
			strcpy(index[i], a);
			//printf("%s\n", index[i]);
	}
	for(numberround=1; numberround<=10; numberround++){
		printf("%d %d\n", rconround,subbyteround);
		if(numberround==1){
			sub_byte_key(indexkey);
			roundkey(matrixkey, rconround);
		}
		else{
			roundkey(matrixkey, rconround);
		}
		sub_byte(index, subbyteround);
		printf("roundkey:\n");
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				printf("%x ", matrixkey[i][j]);
			}
			printf("\n");
		}
		printf("-------------------------------------------\n");
		printf("Subbyte:\n");
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				printf("%x ", matrix[i][j]);
			}
			printf("\n");
		}
		printf("-------------------------------------------\n");
		shiftrow();
		printf("shiftrow value:\n");
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				printf("%x ", matrix[i][j]);
			}
			printf("\n");
		}
		printf("-------------------------------------------\n");
		if(numberround<10){
			mixcolumn();
			printf("mixcolumn value:\n");
			for(i=0; i<4; i++){
				for(j=0; j<4; j++){
					printf("%x ", matrix[i][j]);
				}
				printf("\n");
			}
		}
		printf("-------------------------------------------\n");
		addroundkey();
		printf("Addroundkey value:\n");
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				printf("%c", matrix[j][i]);
			}
			//printf("\n");
		}
		printf("\n");
		subbyteround++;
		rconround++;
	}

}	

int sub_byte(char index[][three], int subbyteround){
	int count=0, i, j;
  	int a, b;
  	char numbersub[3];
  	//printf("subbyte value:\n");
  	if(subbyteround==0){
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

int mixcolumn(){
	int i, j;
	int tablemultimatrix[4][4] = {{2, 3, 1, 1}, {1, 2, 3, 1}, {1, 1, 2, 3}, {3, 1, 1, 2}};
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			//printf("%d %d %d %d\n", multimatrix(matrix[0][i], tablemultimatrix[j][0]), multimatrix(matrix[1][i], tablemultimatrix[j][1]), multimatrix(matrix[2][i], tablemultimatrix[j][2]), multimatrix(matrix[3][i], tablemultimatrix[j][3]));
			mixcolumnmatrix[j][i] = multimatrix(matrix[0][i], tablemultimatrix[j][0])^multimatrix(matrix[1][i], tablemultimatrix[j][1])^multimatrix(matrix[2][i], tablemultimatrix[j][2])^multimatrix(matrix[3][i], tablemultimatrix[j][3]);
		}
	}
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			matrix[j][i] = mixcolumnmatrix[j][i];
		}
	}
}

int multimatrix(int numbermatrix, int table){
	if(table==1){return numbermatrix;}
	else if(table==2){
		return numtobi(numbermatrix);
	}
	else if(table==3){}
		return (numtobi(numbermatrix)^numbermatrix);


}

int numtobi(int number){
	int bi1[1000], count=0, i=0, bi2[1000], roun=0, ans=0, two=1;
	for(i=0; i<8; i++){
		if(number!=0){
			bi1[i] = number%2;
			number = number/2;
		}
		else{
			bi1[i] = 0;
		}
	}
	count = 8;
	for(i=count-2; i>=0; i--){
		bi2[roun] = bi1[i];
		roun++;
	}
	bi2[7] = 0;
	for(i=7; i>=0; i--){
		if(bi2[i]==1 && i==7){
			ans += (bi2[i]*(two));
		}
		else if(bi2[i]==1 && i<7){
			ans += (bi2[i]*(two));
		}
		two *= 2;
	}
	ans = ans^27;
	return ans;
}



int sub_byte_key(char indexkey[][three]){
	int count=0, i, j;
  	int a, b;
  	//printf("subbyte value key:\n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
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
	int i, ans1, ans2;
	char b[3], a[3];
	for(i=0; i<4; i++){
		sprintf(a, "%x", matrixkey[i][3]);
		ans1 = tonum(a[0]);
		ans2 = tonum(a[1]);
		nextmatrixkey[i][0] = s_box[ans1][ans2];
	}
}


int roundkey(int indexkey[][four], int rconround){
	int i, j;
	matrixkey[0][3] = copykey[3][3];
	matrixkey[1][3] = copykey[0][3];
	matrixkey[2][3] = copykey[1][3];
	matrixkey[3][3] = copykey[2][3];

	sub_roundkey(matrixkey);
	for(i=0; i<4; i++){
		nextmatrixkey[i][0] = nextmatrixkey[i][0]^rconbox[rconround][i]^matrixkey[i][0];
	}
	for(i=1; i<4; i++){
		for(j=0; j<4; j++){
			nextmatrixkey[j][i] = nextmatrixkey[j][i-1]^matrixkey[j][i];
		}
	}
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			matrixkey[j][i] = nextmatrixkey[j][i];
		}
	}
}


int addroundkey(){
	int i, j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			matrix[j][i] = matrixkey[j][i]^matrix[j][i];
		}
	}
	
}
//abcdefghijklmnop