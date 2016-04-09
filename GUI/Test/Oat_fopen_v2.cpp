#include <stdio.h> //"C:\\Users\\oat_t\\Desktop\\work\\AES proj test\\test.txt"
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *f_ptr;
	char text[500000], path[500000], new_text[500000];
	
	/*strcpy(path, "C:\\Users\\oat_t\\Desktop\\work\\AES proj test\\test.txt");*/ //reserve path!
	
	printf("Drag file here: ");
	scanf("\"%[^\"]\"%*c", path);
	
	
	f_ptr = fopen(path, "r+t");
	/* open file, mode > r = read exist file, w = create new file, +t = can put new text */
	
	if (!f_ptr) /* Or use f_ptr == NULL */
	{
		printf("Can't open file.\n");
		printf("This is your path: %s", path);
		exit(0);
	}
	
	printf("\nThis is your path: %s", path);
	
	/*--------------------------------*/ /*bring text from ptr to variable*/
	fscanf(f_ptr, "%[^\n]", text);
	printf("\n%s", text);
	//fgets(text,50,f_ptr);
	/*--------------------------------*/ /*that fscanf and fgets is the same*/
	
	//printf("\nEnter your text: ");
	//scanf("%[^\n]%*c", new_text);
	
	/*--------------------------------*/ /* put the text to file */
//	fputs(new_text, f_ptr); 
	//fprintf(f_ptr, "%s", new_text);
	/*--------------------------------*/ /*that fprintf and fputs is the same*/
	
	printf("\nPut new text Success!");
	
	
}

