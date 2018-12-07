#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>




int port = 5700;
SSL_CTX *ctx;
char* cert = "cert.pem";
	int connection;

char* key = "cert.pem";

void load(){
	if (SSL_CTX_use_PrivateKey_file(ctx, key, SSL_FILETYPE_PEM) > 0) {
		if (SSL_CTX_use_certificate_file(ctx, cert, SSL_FILETYPE_PEM) >0) {
			if (SSL_CTX_check_private_key(ctx)) {
		
			}
			else{
				perror("Match error\n");
				exit(1);
			}
		
		}
		else{
			perror("Certificate error\n");
		exit(1);
		}
		
	}
	else{
		perror("Key error\n");
		exit(1);
	}
}

void CTX_init() {
	 int lock=0;
	SSL_METHOD *method;
	if (lock==1){
		lock++;
	}

	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();

	if (lock==0){
		lock--;
	}

	method = TLSv1_2_server_method();

	if ((ctx = SSL_CTX_new(method)) != NULL) {
		load();

	}
	else{
		exit(1);
	}
}


int main() {

	struct sockaddr_in server_socket;

	SSL_library_init();
	CTX_init();

	server_socket.sin_family = AF_INET;
	char message[1024] = "";
	server_socket.sin_port = htons(port);
	server_socket.sin_addr.s_addr = INADDR_ANY;

		int fd = socket(AF_INET, SOCK_STREAM, 0);


	if (fd <= 0) {
			printf("Error3\n");
	}
	else {
		if(bind(fd, (struct sockaddr *) &server_socket, sizeof(server_socket)) == 0) {

			if(listen(fd, 10) == 0) {
				while (connection = accept(fd, (struct sockaddr *)NULL, NULL)) {
			int pid = fork();
						int check=0;

			SSL *ssl;
			check++;
			if (pid != 0) {
				ssl = SSL_new(ctx);
				SSL_set_fd(ssl, connection);

				if(SSL_accept(ssl) != -1) {
					int bytes;
				while((bytes = SSL_read(ssl, message, sizeof(message))) > 0) {
					check++;
					message[bytes] = 0;
					printf("Message from %d: %s\n", connection, message);
					check++;
					SSL_write(ssl, message, strlen(message));
					message[0] = '\0';\
					check++;
				}

				int client_fd = SSL_get_fd(ssl);
				check++;
				SSL_free(ssl);
				close(client_fd);
				check=0;
					
				}
				else{
					printf("Error ssl accept\n");
					exit(1);
				}

				
			}
			else{

			}
		}

		close(fd);
		SSL_CTX_free(ctx);

			
			}
			else{
				printf("Error2\n");
				exit(1);
			}
			
		}
		else{
			printf("Error1\n");
			exit(1);
		}

		
	
	}

	return 0;
}