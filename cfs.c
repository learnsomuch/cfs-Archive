/* Header files */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* Main function */
int main(int argc, char *argv[]) {


	if(argv[1] == NULL) {
		
		printf("Usage: cfs <URL>\n");
		printf("<URL>\t\t Support http, https, port, path \n");
		printf("If no arguments, print help\n");

		return 1;
	}

	char *initialurl = argv[1];
	char *initialclone = malloc(sizeof(initialurl) + 1);

	/* Cloning variable since we need to use strstr twice */
	if(initialclone != NULL) {

		memcpy(initialclone, initialurl, strlen(initialurl) + 1);
		initialclone[strlen(argv[1]) + 1] = '\0';
	}

	const char *starthttp = "http://";	
	const char *starthttps = "https://";
	
	if(strncmp(initialurl, starthttp, strlen(starthttp)) == 0) {
		
		initialurl = initialurl + strlen(starthttp);
		initialclone = initialclone + strlen(starthttp);
		printf("REMOVED HTTP: %s\n", initialurl);	    
		
		char *argport = strstr(initialurl, ":");
    		if(argport) {
			printf("PORT: %s\n", strtok(argport, "/") + 1);
    		} else {
			argport = "80";
			printf("PORT: %s\n", argport);
		}	 
	
		char *webtoken = strtok(initialurl, ":");
		if(webtoken) {
    			printf("WEB: %s\n", strtok(webtoken, "/"));
		}

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

                char *argport = strstr(initialurl, ":");
                if(argport) {
                        printf("PORT: %s\n", strtok(argport, "/") + 1);
                } else {
			argport = "443";
                        printf("PORT: %s\n", argport);
		}

                char *webtoken = strtok(initialurl, ":");
		if(webtoken) {
                        printf("WEB: %s\n", strtok(webtoken, "/"));
                }

                char *argpath = strstr(initialclone, "/");
		if(argpath) {
                        printf("PATH: %s\n", argpath);
                } else {
                        argpath = "/";
			printf("PATH: %s\n", argpath);
                }
		
	} else {
		
		char *argport = strstr(initialurl, ":");
                if(argport) {
                        printf("PORT: %s\n", strtok(argport, "/") + 1);
                } else {
			argport = "80";
                        printf("PORT: %s\n", argport);
		}

                char *webtoken = strtok(initialurl, ":");
                if(webtoken) {
                        printf("WEB: %s\n", strtok(webtoken, "/"));
                }

                char *argpath = strstr(initialclone, "/");
    		if(argpath) {
                        printf("PATH: %s\n", argpath);
                } else {
                        argpath = "/";
			printf("PATH: %s\n", argpath);
                }
	}	

   	return 0;
}
