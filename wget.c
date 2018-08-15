#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

/* wget clone for index file */
char *wget(char *weburl, char *argport, char *argpath, char *str) {

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
	memcpy(str, response,sizeof(response));
}
