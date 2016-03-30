#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char plaintext[10000], answer[1000], matrix[5][5][3];
	int i=0, ans, num, j, letter, lenth, count, rounds=0, column=0, digit=0, k;
	scanf(" %[^\n]s", plaintext);
	for(j=0; j<strlen(plaintext); 	){
		i = 0;
		count = 0;
		letter = (int)plaintext[j];
		while(letter != 0){
			ans = letter%16;
			letter = letter/16;
			if(ans==10){
				answer[i] = 'A';
			}
			else if(ans==11){
				answer[i] = 'B';
			}
			else if(ans==12){
				answer[i] = 'C';
			}
			else if(ans==13){
				answer[i] = 'D';
			}
			else if(ans==14){
				answer[i] = 'E';
			}
			else if(ans==15){
				answer[i] = 'F';
			}
			else{
				answer[i] = ans;
			}
			i++;
			count++;
		}
		for(i=count-1; i>=0; i--){
			if(answer[i]>=65 && answer[i]<=70){
				matrix[rounds][column][digit] = answer[i];
			}
			else{
				matrix[rounds][column][digit] = answer[i];
			}
			printf("\n");
			digit++;
		}
		digit = 0;
		if(rounds<3){
			rounds++;
		}
		else{
			rounds = 0;
			column++;
		}
	}
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			for(k=0; k<2; k++){
				if(matrix[i][j][k]>=65 && matrix[i][j][k]<=70){
					printf("%c", matrix[i][j][k]);
				}
				else{
					printf("%d", matrix[i][j][k]);
				}
			}
			printf(" ");
		}
		printf("\n");
	}
}