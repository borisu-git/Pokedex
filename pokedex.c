#include <signal.h>
#include <unistd.h>
#include "main.h"
#define ARRAY_SIZE 3

void bulbizarre(void);
void carapuce(void);
void salameche(void);
void get_arceus(int sig)

{
    signal(sig, SIG_IGN);
    signal(SIGUSR1, get_arceus);
    printf("Wow, je vois que tu as hacké le game!!!\nVoilà ton Arceus !!\n");
    
}

int main(void)
{

    int index = 0;

    signal(SIGUSR1, get_arceus);
    printf("Bonjour, choisis ton Pokemon\n");
    printf("1 - bulbizarre\n");
    printf("2 - carapuce\n");
    printf("3 - salameche\n");

    scanf("%d", &index );

    void (*array_ftpr[ARRAY_SIZE])(void);
    array_ftpr[0] = &bulbizarre;
    array_ftpr[1] = &carapuce;
    array_ftpr[2] = &salameche;

    array_ftpr[index-1]();

    return 0;
}


void bulbizarre(){

    printf("Bravo ! Vous avez attrapé un bulbizarre");

}

void carapuce(){

    printf("Bravo ! Vous avez attrapé un carapuce");

}

void salameche(){

    printf("Bravo ! Vous avez attrapé un salameche");

}