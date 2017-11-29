#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <windows.h>

int main()
{
int userChoice, pin, k, i, j, n, allMoney, transaction, deposit, withdraw;
const int ZERO = 0;
const int MAX_TRY = 2;
const int USER = 6000;
const int PIN_ADMIN = 8888;

int user[USER][3];

for(i = 1000; i < USER;i++){
    for(j = ZERO;j < 3;j++){
        if(j == ZERO){// pass
            user[i][j] = i;
        }
        if (j == 1){ // name
            user[i][j] = i;
        }
        if(j == 2){ // balanace
        user[i][j] = rand() % 10000 + 1;;
        }
    }
    j = ZERO;
}

    for(n = ZERO; n < 3; n++){
            Beep(247, 500);
            printf("ENTER YOUR SECRET PIN NUMBER:");
            fflush(stdin);
            scanf("%d", &pin);
            printf("<<<<<<<<%d >>>>>>>>>>>>>>>>>>>>\n", &pin);

            for(i = 1000;i < USER;i++){
                if (pin == user[i][0])
                {
                printf("\n hello user nomber - %d\n", user[i][1]);
                printf(" balance %d\n", user[i][2]);
                    break;
                }
                if(n == MAX_TRY){
                    printf("Vu vveli 3 raza ne pravelnui parol\n");
                    printf(" <<<<za vami vuehali...>>>> \n");
                    return 0;
                }
                if(PIN_ADMIN == pin){
                    break;
                }
            }
            if(PIN_ADMIN == pin){
                break;
            }
            if(user[i][1] == pin){
                break;
            }
        }
        if(PIN_ADMIN == pin){
            for(i = 1000; i < USER; i++){
                allMoney = allMoney + user[i][2];
                }
                do{
        printf("**********WELCOME TO TINbKOV BANK*****************\n");
        printf("                user - ADMIN                     |\n");
        printf("1 PROVERIT Balance                               |\n");
        printf("2 ZABRAT cash                                    |\n");
        printf("3 obnylit                                        |\n ");
        printf("4 quit                                           |\n ");
        printf("*************************************************\n");
        printf("             Enter your choice - ");
        scanf("%d", &userChoice);

        switch(userChoice)
        {
            case 1:
                printf("\n balance vseh klientov %d $ : ", allMoney);
                break;
            case 2:
                printf("\n skolko zabrat: ");
                fflush(stdin);
                scanf("%d", &withdraw);
                if(withdraw %100 != ZERO){
                    printf("\n mozho zabirat po 100$");
                }
                else if (withdraw > (allMoney - 100)){
                    printf("\n INSUFFICENT BALANCE");
                }
                else if(withdraw > (withdraw - 100)){
                    printf("ppp");
                }
                if (withdraw %100 != 0 && withdraw > (allMoney - 100) && withdraw != 0 && withdraw > 99){
                    allMoney = allMoney - withdraw;
                    printf("\n\n  poluchite vashi denbgi ");
                    printf("\n TVOI TEKUSHII BALANCE  %lu ", allMoney);
                }
                break;
            case 3:
                printf("\n vu zabrali: %d", allMoney);
                allMoney = allMoney - allMoney;
                break;
            case 4:
                printf("\n THANKS FOR YOU USING TINbKOV BANK");
                break;
                default:
                printf("\n bay bay");
        }

        printf("\n\n\n DO U WISH TO HAVE ANOTHER TRANSCATION? (1/0): \n");
        fflush(stdin);
        scanf(" %d", &transaction);
        if(transaction == 1){
                k -1;
            }
        else if(transaction == ZERO){
             return ZERO;
            }
    }
            while(!k);
            printf("\n\n goodbay");
        }
        else{
     do{
        printf("**********WELCOME TO TINbKOV BANK*****************\n");
        printf("                user - %d                      |\n", user[i][1]);
        printf("1 PROVERIT Balance                               |\n");
        printf("2 ZABRAT cash                                    |\n");
        printf("3 polozit Cash                                   |\n");
        printf("4 Quit                                           |\n ");
        printf("*************************************************\n");
        printf("             Enter your choice - ");
        scanf("%d", &userChoice);

        switch(userChoice){
            case 1:
                printf("\n tvoi balance %d $ : ", user[i][2]);
                break;
            case 2:
                printf("\n ENTER THEE AMOUNT TO WITHDRAW: ");
                fflush(stdin);
                scanf("%lu", &withdraw);
                if(withdraw %100 != ZERO){
                    printf("\n PLEAE ENTER THE AMOUNT IN MULTIPLES OF 100");
                }
                else if (withdraw > (user[i][2] - 100)){
                    printf("\n na balance doljno ostatsa ne menshe 100$");
                }
                if (withdraw > ZERO){
                    user[i][2] = user[i][2] - withdraw;
                    printf("\n\n  poluchite vashi denbgi ");
                    printf("\n TVOI TEKUSHII BALANCE  %lu ", user[i][2]);
                    withdraw = ZERO;
                }
                break;
            case 3:
                printf("\n skolko vu hotite polozhit ");
                fflush(stdin);
                scanf("%d", &deposit);
                if ( deposit > ZERO){
                user[i][2] = user[i][2] + deposit;
                printf("YOUR BALANCE IS %d ", user[i][2]);
                deposit = ZERO;
                }
                break;
            case 4:
                printf("\n THANKS FOR YOU USING TINbKOV BANK");
                break;
                default:
                    printf("\n");
        }
        printf("\n\n\n prodolzit? (1/0): \n");
        fflush(stdin);
        scanf(" %d", &transaction);
        if(transaction == 1){
                k - 1;
            }
        else if(transaction == ZERO){
             return ZERO;
            }
    }
            while(!k);
    }
}
