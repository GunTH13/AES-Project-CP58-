#include <stdio.h>

int main(int before_gen_k[4][4], int round){ /*get key into before_gen_k, get the round of encryption*/
	int r_con[4][10] = {{0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36},
						{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
						{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
						{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
	/*Just a tested matrix*/
	/*int mat[4][4] = {{0x2b, 0x28, 0xab, 0x09},
					   {0x7e, 0xae, 0xf7, 0xcf},
					   {0x15, 0xd2, 0x15, 0x4f},
					   {0x16, 0xa6, 0x88, 0x3c}};*/
	int i, j, temp, after_gen_k[4][4], k_sub_byte[4][1];
	
	/*rot word
	[a]	----- 		[b]
	[b]		|	   	[c]
	[c]		|	   	[d]
	[d] 	-----> 	[a]  */

	temp = before_gen_k[0][3];
	before_gen_k[0][3] = before_gen_k[1][3];
	before_gen_k[1][3] = before_gen_k[2][3];
	before_gen_k[2][3] = before_gen_k[3][3];
	before_gen_k[3][3] = temp;
	
	/*s_box*/

	k_sub_byte = sub_byte(before_gen_k); /*sub_byte only last column*/

	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if (i==0)
			{
				after_gen_k[j][i] = before_gen_k[j][i] ^ k_sub_byte[j][0] ^ r_con[j][round];
				/*put the generated key to after_gen_k*/
			}
			else
			{
				after_gen_k[j][i] = before_gen_k[j][i] ^ after_gen_k[j][i-1];
				/*put the generated key to after_gen_k*/
			}
		}
	}

	return after_gen_k;


}


