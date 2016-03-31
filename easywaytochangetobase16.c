#include <stdio.h>
#include <string.h>

int main() {
	char plaintext[16] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'}, b[3], a[16];
	int i;
	scanf("%s", plaintext);
	sprintf(a,"%x", plaintext[0]);
	for(i=0; i<16; i++){
		sprintf(a, "%x", plaintext[i]);
		printf("%s\n", a);
	}
	printf("%s\n", a);
	sprintf(b, "%s", a);
	printf("%s %c 	%c \n",b, b[0], b[1]);

}
