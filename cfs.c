/* Header files 
   stdio.h - for input and output
   string.h - for strlen, strncmp, strstr, etc
   stdlib.h - for memcpy, malloc, free */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

/* wget clone for index file */
void wget(char *weburl, char *argport, char *argpath) {

	/* Variables */
	struct addrinfo hints, *res;
	int sockfd;
	/* response for output of content, header is for GET request */
    	char response[2048];
    	char header[100];

	/* get info */
	memset(&hints, 0,sizeof hints);
	hints.ai_family = AF_UNSPEC;
    	hints.ai_socktype = SOCK_STREAM;
	
	/* get address info */
	getaddrinfo(weburl, argport, &hints, &res);
	
	/* create and connect socket */
	sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	connect(sockfd,res->ai_addr,res->ai_addrlen);

	/* appened dynamic url content to header request */
	sprintf(header, "GET %s/ HTTP/1.1\r\nHost: %s\r\nContent-Type: text/plain\r\n\r\n", argpath, weburl);

	/* send header details and receive data */
    	send(sockfd, header, strlen(header), 0);
	recv(sockfd, response, sizeof(response)-1, 0);

	/* Print data for debugging (temporary) */
	printf("%s", response);
}

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
		
		/* In order to ignore first n chars */
		initialurl = initialurl + strlen(starthttp);
		initialclone = initialclone + strlen(starthttp);
		initialagain = initialagain + strlen(starthttp);
		printf("REMOVED HTTP: %s\n", initialurl);	    
		
		/* Split based on colon */
        	char *argport = strstr(initialurl, ":");
        	if(argport) {
			argport = strtok(argport, "/") + 1;
                	printf("PORT: %s\n", argport);
        	} else {
                	/* default values */
                	argport = "80";
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
		wget(webtoken, argport, argpath);

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
                wget(webtoken, argport, argpath);

	} else {
		
		/* split based on colon */
		char *argport = strstr(initialurl, ":");
                if(argport) {
			argport = strtok(argport, "/") + 1;
                        printf("PORT: %s\n", argport);
                } else {
			argport = "80";
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

		printf("%s %s %s",webtoken, argport, argpath); 
		/* calling wget function with specified arguments */
                wget(webtoken, argport, argpath);	
	}

	/* Return success code */
   	return 0;
}
