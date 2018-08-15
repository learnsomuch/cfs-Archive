#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void filter(char *str) {

	char *sub = "<a href=";
	char *submid = ">";
	char *subend = "</a>";
	char *p, *q;

	/* A - Start, B - End, C - Number of chars */
	int A[1000], B[1000], C[1000], K[1000];

	if (str && sub && subend) {

		int a, b = 0;

		for(p = str; (p = strstr(p, sub)) != NULL; p++) {
	
			A[a] = p - str;
	
			/* special case for the empty string */	
			if (*p == '\0') {
        	    		break;
    			}
	
			const char ch = '>';
			char *pos_angle;
	
			pos_angle=strchr(p, ch);
			K[a] = (p - str) + (pos_angle - p) + 1;
	
//	printf("Array K[%d]: %tu\n", a, (p - str) + (pos_angle - p) + 1);
	
//	printf("CONTENT:%.*s\n", 10, p + (pos_angle - p) + 1);	
	//printf("Start : %tu\n", p - str);

			a++;	
		}


		for(q = str; (q = strstr(q, subend)) != NULL; q++) {

			B[b] = q - str;
			b++;

//	printf("Array B[%d]: %tu\n", b, q - str);
	
	/* special case for the empty string */
			if (*q == '\0') {
            			break;
    			}
		}


		int i;
		if (a == b) {

//	printf("EQUAL\n");
	
			for(i = 0; i < a; i++) {
		
				C[i] = B[i] - K[i];
//		printf("Array C[%d]: %d\n", i, C[i]);
		
				printf("%.*s\n", C[i], str + K[i]);
			}
		}
	}

}
