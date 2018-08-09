/* Header files 
   stdio.h - for input and output
   string.h - for strlen, strncmp, strstr, etc
   malloc.h - for memcpy */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* Main function */
int main(int argc, char *argv[]) {

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

	/* Cloning variable since we need to use strstr twice */
	if(initialclone != NULL) {

		/* allocate same size as source to target and copy data */
		memcpy(initialclone, initialurl, strlen(initialurl) + 1);
		initialclone[strlen(argv[1]) + 1] = '\0';
	}

	/* Constant variables */
	const char *starthttp = "http://";	
	const char *starthttps = "https://";
	
	/* check if argument input starts with http, https or none */
	if(strncmp(initialurl, starthttp, strlen(starthttp)) == 0) {
		
		/* In order to ignore first n chars */
		initialurl = initialurl + strlen(starthttp);
		initialclone = initialclone + strlen(starthttp);
		printf("REMOVED HTTP: %s\n", initialurl);	    
		
		/* Split based on colon */
		char *argport = strstr(initialurl, ":");
    		if(argport) {
			printf("PORT: %s\n", strtok(argport, "/") + 1);
    		} else {
			/* default values */
			argport = "80";
			printf("PORT: %s\n", argport);
		}	 
		
		/* split based on colon */
		char *webtoken = strtok(initialurl, ":");
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

	} else if(strncmp(initialurl, "https://", strlen(starthttps)) == 0) {
        
		initialurl = initialurl + strlen(starthttps);
                initialclone = initialclone + strlen(starthttps);
                printf("REMOVED HTTPS: %s\n", initialurl);

		/* split based on colon */
                char *argport = strstr(initialurl, ":");
                if(argport) {
                        printf("PORT: %s\n", strtok(argport, "/") + 1);
                } else {
			argport = "443";
                        printf("PORT: %s\n", argport);
		}

		/* split based on colon */
                char *webtoken = strtok(initialurl, ":");
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
		
	} else {
		
		/* split based on colon */
		char *argport = strstr(initialurl, ":");
                if(argport) {
                        printf("PORT: %s\n", strtok(argport, "/") + 1);
                } else {
			argport = "80";
                        printf("PORT: %s\n", argport);
		}

		/* split based on colon */
                char *webtoken = strtok(initialurl, ":");
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
	}	

	/* Return success code */
   	return 0;
}
