#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>


int port = 5700;
SSL_CTX *ctx;
SSL *ssl;

void CTX_init() {
	int flag=0;
	SSL_METHOD *method;

	if (flag==0)
	{
		flag=1;
	}
	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();
	flag++;
	method = TLSv1_2_client_method();

	if ((ctx = SSL_CTX_new(method)) != NULL) 
	{	
		if (flag==1)
		{
			flag++;
		}

	}
	else
	{
		perror("Error");
		exit(1);
	}


}

void main() {

	int connection;

	SSL_library_init();
	CTX_init();
	struct sockaddr_in client_socket;

	ssl = SSL_new(ctx);

	int fd = socket(AF_INET, SOCK_STREAM, 0);

	char message[1024] = "";
	if (fd > 0) 
	{
		client_socket.sin_family = AF_INET;
		client_socket.sin_port = htons(port);

		if (inet_pton(AF_INET, "127.0.0.1", &client_socket.sin_addr) > 0) 
		{
			if(connect(fd, (struct sockaddr *) &client_socket, sizeof(client_socket)) == 0) 
			{
				int check=0;
				SSL_set_fd(ssl, fd);
				check++;
				if (SSL_connect(ssl) != -1) 
				{
					check++;
					for(;;) {

					printf("Message:");

					if (check==2)
					{
						fgets(message, 1024, stdin);
						SSL_write(ssl, message, strlen(message));
						message[0] = '\0';
					}

					int bytes = SSL_read(ssl, message, sizeof(message));

					if (check==2)
					{
						
						if (bytes > 0) {
						message[bytes] = 0;
						printf("Message: %s\n", message);
						message[0] = '\0';
						}
					

					

					
					}
					}	

					SSL_free(ssl);
					close(fd);
					SSL_CTX_free(ctx);	
				}
				else
				{
					exit(1);
				}
	
			}
			else
			{
				exit(1);
			}

			
		}
		else
		{
			exit(1);
		}

	
	}
	else
	{
		exit(1);
	}

	

}
	
