#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void printWelcomeMessage();
int checkAccount(int user_acc);
int checkPin(int user_acc, int PIN);
void login();
void optionsMenu();
void checkBalance();
void deposit();
void withdraw();
void PINchange();

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

int checkPin(int user_acc, int PIN)
{
    int i=checkAccount(user_acc);
    if(i==-1)
    {
        return 0;
    }

    if(acc[i].pin == PIN)
    {
        return 1;
    }
    else
    {
        return 0;
    }

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
                scanf("%d", &u_pin);
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
        deposit();
        break;
    case 3:
        withdraw();
        break;
    case 4:
        PINchange();
    }
}

void checkBalance()
{
    system("cls");
    printf("\n\nYour current balance is Tk. %.2f\n", acc[index].balance);

    printf("\nPress any key to go back to options page...");
    getch();
    optionsMenu();

}

void deposit()
{
    float d;
    FILE *fileD;
    system("cls");

    fileD = fopen("INFO.txt", "w");

    printf("\n\nHow much money do you want to deposit: ");
    scanf("%f", &d);

    acc[index].balance += d;
    int i;
    for(i=0; i< serial_no;i++){
        fprintf(fileD, "%d %d %f\n", acc[i].acc_num, acc[i].pin, acc[i].balance);
    }
    printf("Your current balance is Tk.%.2f\n",acc[index].balance);


    fclose(fileD);
    printf("\nPress any key to go back to options page...");
    getch();

    optionsMenu();

}

void withdraw()
{
    float w;
    FILE *fileW;
    system("cls");

    fileW = fopen("INFO.txt", "w");

    printf("\n\nHow much money do you want to withdraw: ");
    scanf("%f", &w);

    int i;
    acc[index].balance -= w;
    for(i=0;i<serial_no;i++)
    {
        fprintf(fileW, "%d %d %f\n", acc[i].acc_num, acc[i].pin, acc[i].balance);
    }
    printf("Your current balance is Tk.%.2f\n",acc[index].balance);

    fclose(fileW);
    printf("\nPress any key to go back to options page...");
    getch();

    optionsMenu();
}

void PINchange()
{

    int user_pin, new_pin;
    system("cls");

    printf("\n\nEnter your current PIN: ");
    scanf("%d", &user_pin);
    int i;

    if(user_pin == acc[index].pin)
    {
        printf("Please enter your new PIN: ");
        scanf("%d", &new_pin);
        acc[index].pin = new_pin;
        printf("PIN changed!\n");
        FILE *filet;
        filet = fopen("INFO.txt", "w");
        for(i=0;i<serial_no;i++){
            fprintf(filet, "%d %d %.2f\n", acc[i].acc_num, acc[i].pin, acc[i].balance);
        }
        fclose(filet);
    }
    else
    {
        printf("Invalid PIN\n");
        PINchange();

    }
    printf("\nPress any key to go back to options page...");
    getch();

    optionsMenu();

}

