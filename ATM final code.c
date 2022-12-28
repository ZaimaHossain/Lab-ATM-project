#include <stdio.h>
#include <stdlib.h>
void printWelcomeMessage();
void optionsMenu();


struct accINFO
{
    int acc_num;
    int pin;
    float balance;
};

struct accINFO acc[1000];

int main()
{
    void printWelcomeMessage();
}
void printWelcomeMessage()
{
    printf("\t * * * * * * * * * * * * * * * *");
    printf("\n\n\t *   WELCOME to our mini ATM   *");
    printf("\n\n\t * * * * * * * * * * * * * * * *\n\n");
}

void optionsMenu()
{
    system("cls");
    int opt;
    printf("\n\nPlease choose one of the options below\n\n");
    printf("1.Balance inquiry\n");
    printf("2.Cash deposit\n");
    printf("3.Cash withdrawal\n");
    printf("4.PIN change\n");
    printf("0.Exit\n\n");

    printf("Enter your choice:");
    scanf("%d",&opt);


    switch(opt)
    {
    case 0:
        exit(0);
    case 1:
        //checkBalance();
        break;
    case 2:
        //deposit();
        break;
    case 3:
        //withdraw();
        break;
    case 4:
        //PINchange();
        break;
    }
}
