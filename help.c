/* Header files 
   stdio.h - for printf
   stdlib.h - for exit function */
#include <stdio.h>
#include <stdlib.h>

/* Help function */
void help_function() {

	/* Print help details and exit */
        printf("Usage: cfs <URL>\n");
       	printf("<URL>\t\t Support http, https, port, path \n");
        printf("If no arguments, print help\n");

       	/* Exit safely */
       	exit(0);
}
