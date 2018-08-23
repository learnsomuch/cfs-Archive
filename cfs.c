/* Header files 
   stdio.h - for input and output
   string.h - for strlen, strncmp, strstr, etc
   stdlib.h - for memcpy, malloc, free */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Main function */
int main(int argc, char *argv[]) {

	char str[2048];

	/* Validate argument input */
	if(argv[1] == NULL) {

		/* Print help details and exit */
		help_function();
	}

	/* Variables - argument */
	char *initialurl = argv[1];

	/* Constant variables */
	const char *starthttp = "http://";	
	const char *starthttps = "https://";
	
	/* check if argument input starts with http, https or none */
	if(strncmp(initialurl, starthttp, strlen(starthttp)) == 0) {
		
		char webtoken[1048];
		char argpath[1048];
		int port = 80;
		sscanf(argv[1], "http://%99[^:]:%99d/%99[^\n]", webtoken, &port, argpath);
		
		char argport[100];
		sprintf(argport, "%d", port);
		
		/* calling wget function with specified arguments */
		wget(webtoken, argport, argpath, str);
		
		/* calling filter function in order to get file name */
		filter(str);		

	} else if(strncmp(initialurl, starthttps, strlen(starthttps)) == 0) {
        
		char webtoken[1048];
                char argpath[1048];
                int port = 443;
                sscanf(argv[1], "https://%99[^:]:%99d/%99[^\n]", webtoken, &port, argpath);

                char argport[100];
                sprintf(argport, "%d", port);

		printf("%s %d %s", webtoken, port, argpath);

		/* calling wget function with specified arguments */
                wget(webtoken, argport, argpath, str);

		/* calling filter function in order to get file name */
		filter(str);

	} else {
		
		char webtoken[1048];
                char argpath[1048];
                int port = 80;
                sscanf(argv[1], "%99[^:]:%99d/%99[^\n]", webtoken, &port, argpath);

//                printf("%s %d %s", webtoken, port, argpath);

                char argport[100];
                sprintf(argport, "%d", port);

                /* calling wget function with specified arguments */
                wget(webtoken, argport, argpath, str);

                /* calling filter function in order to get file name */
                filter(str);


	}

	/* Return success code */
   	return 0;
}
