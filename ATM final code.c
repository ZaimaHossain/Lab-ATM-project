#include <stdio.h>
#include <stdlib.h>
void printWelcomeMessage();
int checkAccount(int user_acc);
void login();
void optionsMenu();
void checkBalance();

struct accINFO
{
    int acc_num;
    int pin;
    float balance;
};

struct accINFO acc[1000];
int serial_no;
int index=-1;
FILE *acc_file;

int main()
{
    system("color 3f");

    login();

    return 0;
}

void printWelcomeMessage()
{
    printf("\t * * * * * * * * * * * * * * * *");
    printf("\n\n\t *   WELCOME to our mini ATM   *");
    printf("\n\n\t * * * * * * * * * * * * * * * *\n\n");
}

int checkAccount(int user_acc)
{
    int i;
    for(i=0; i<serial_no; i++)
    {
        if(acc[i].acc_num == user_acc)
            return i;
    }
    return -1;
}

void login()
{
    int u_acc;
    int u_pin;
    printWelcomeMessage();

    acc_file=fopen("INFO.txt","r");

    int i=0;
    while(fscanf(acc_file,"%d %d %f",&acc[i].acc_num, &acc[i].pin,&acc[i].balance)==3)
    {
        i++;
    }
    serial_no=i;


    while(1)
    {
        printf("\nEnter your account number:");
        scanf("%d", &u_acc);
        index=checkAccount(u_acc);

        if(index>=0)
        {
            while(1)
            {
                printf("Enter your 4 digit PIN:");
                scanf("%d", &u_pin);//gets(u_pin);
                if(checkPin(u_acc,u_pin))
                {
                    optionsMenu();
                    break;
                }
                else
                {
                    printf("\nInvalid PIN.\n");
                }
            }
            break;
        }
        else
        {
            printf("\nNo valid accountNo. found.\n");
        }
    }
    fclose(acc_file);

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
        checkBalance();
        break;
    case 2:
        //deposit();
        break;
    case 3:
        //withdraw();
        break;
    case 4:
        //PINchange();
    }
}

void checkBalance()
{
    system("cls");
    printf("\n\nYour current balance is Tk. %.2f\n", acc[index].balance);

    printf("\nPress any key to go back to HOME page...");
    getch();
    optionsMenu();

}
