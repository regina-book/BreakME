#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define WELCOME "welcome, please enter password : "
#define GOOD    "congratz ! u got me :)\n"
#define BAD     "no pain no gain, try again ...\n"

int main() {
    char password[] = "th3_f1r$t_dr4ft_0f_4nyth1ng_is_$h1t!";
    unsigned int nbrClient = 0;
    int hsocket, hcsocket, port = 10101;
    struct sockaddr_in server_addr = {0},
                       client_addr = {0};

    if((hsocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("[-] ERROR socket()");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if((bind(hsocket, (struct sockaddr*) &server_addr, sizeof(server_addr))) < 0) {
        perror("[-] ERROR bind()");
        return -1;
    }

    listen(hsocket, 5);

    while(1) {
        int len = sizeof(client_addr);
        if((hcsocket = accept(hsocket, (struct sockaddr*) &client_addr, &len)) < 0) {
            perror("[-] ERROR accept()");
            return -1;
        }
        printf("%d\n", nbrClient++);
        write(hcsocket, WELCOME, strlen(WELCOME));

        char buffer[64];
        memset(buffer, 0, 64);
        int n;
        n = read(hcsocket, buffer, 64);
        buffer[n-1] = '\0';

        /*
         * Determine la taille du check
         */
        int i;
        if(n > strlen(password)) {
            i = strlen(password);
        } else {
            i = n-1;
        }
        /*
         * si le dernier char est correct, on sleep()
         */
        i--; // supp null-byte
        if(buffer[i]==password[i]) {
            sleep(1);
        }

        if(strcmp(buffer, password)==0) {
            write(hcsocket, GOOD, strlen(GOOD));
        } else {
            write(hcsocket, BAD, strlen(BAD));
        }
        close(hcsocket);
    }
    return 0;
}