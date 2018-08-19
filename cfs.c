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
		printf("Usage: cfs <URL>\n");
		printf("<URL>\t\t Support http, https, port, path \n");
		printf("If no arguments, print help\n");
	
		/* Failed return code */
		return 1;
	}

	/* Variables - argument */
	char *initialurl = argv[1];
	char *initialclone = malloc(sizeof(initialurl) + 1);
	char *initialagain = malloc(strlen(initialurl) + 1);

	/* Cloning variable since we need to use strstr twice */
	if(initialclone != NULL) {

		/* allocate same size as source to target and copy data */
		memcpy(initialclone, initialurl, strlen(initialurl) + 1);
		initialclone[strlen(initialurl) + 1] = '\0';
	}

	if(initialagain != NULL) {

                /* allocate same size as source to target and copy data */
                memcpy(initialagain, initialurl, strlen(initialurl) + 1);
                initialagain[strlen(initialurl) + 1] = '\0';
        }

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
/*	
        	char *argport = strstr(initialurl, ":");
        	if(argport) {
			argport = strtok(argport, "/") + 1;
                	printf("PORT: %s\n", argport);
        	} else {
                	argport = "80";
                	printf("PORT: %s\n", argport);
        	}

        	char *webtoken = strtok(initialagain, ":");
        	if(webtoken) {
                	printf("WEB: %s\n", strtok(webtoken, "/"));
        	}

        	char *argpath = strstr(initialclone, "/");
        	if(argpath) {
			printf("PATH: %s\n", argpath);
        	} else {
			printf("PATH: %s\n", argpath);
                	argpath = "/";
               		printf("PATH: %s\n", argpath);
        	}
*/
		/* calling wget function with specified arguments */
		wget(webtoken, argport, argpath, str);
		filter(str);		

	} else if(strncmp(initialurl, "https://", strlen(starthttps)) == 0) {
        
		initialurl = initialurl + strlen(starthttps);
                initialclone = initialclone + strlen(starthttps);
        	initialagain = initialagain + strlen(starthttps);
	        printf("REMOVED HTTPS: %s\n", initialurl);

		/* split based on colon */
                char *argport = strstr(initialurl, ":");
                if(argport) {
                	argport = strtok(argport, "/") + 1;
		        printf("PORT: %s\n", argport);
                } else {
			argport = "443";
                        printf("PORT: %s\n", argport);
		}

		/* split based on colon */
                char *webtoken = strtok(initialagain, ":");
		if(webtoken) {
                        printf("WEB: %s\n", strtok(webtoken, "/"));
                }

		/* split based on slash */
                char *argpath = strstr(initialclone, "/");
		if(argpath) {
                        printf("PATH: %s\n", argpath);
                } else {
                        argpath = "/";
			printf("PATH: %s\n", argpath);
                }
		
		/* calling wget function with specified arguments */
                wget(webtoken, argport, argpath, str);
		filter(str);

	} else {
		
		/* split based on colon */
		char *argport = strstr(initialurl, ":");
                if(argport) {
			argport = strtok(argport, "/") + 1;
//                        printf("PORT: %s\n", argport);
                } else {
			argport = "80";
//                        printf("PORT: %s\n", argport);
		}

		/* split based on colon */
                char *webtoken = strtok(initialagain, ":");
                if(webtoken) {
			webtoken = strtok(webtoken, "/");
//   	                  printf("WEB: %s\n", strtok(webtoken, "/"));
                }

		/* split based on slash */
                char *argpath = strstr(initialclone, "/");
    		if(argpath) {
			argpath = argpath;
//                        printf("PATH: %s\n", argpath);
                } else {
                        argpath = "/";
//			printf("PATH: %s\n", argpath);
                }

//		printf("%s %s %s",webtoken, argport, argpath); 

		/* calling wget function with specified arguments */
		wget(webtoken, argport, argpath, str);
		filter(str);

	}

	/* Return success code */
   	return 0;
}
