// -------------------Making a Bank Account Management System--------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

typedef struct BankAccount{
    char userId[51];
    char pin[5];
    int balance;
}BankAccount;

typedef struct transaction{
    char userId[51];
    char recipient[51];
    char TimeStamp[20];
    int type;
    int amount;
    int balance;
}transaction;

void ClearBuffer(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int GetUserIntInput(int MaxInput, int MinInput){
    char buffer[3];
    while(1){
        printf("Enter Option: ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("Error: Invalid Input!!!!\n");
            continue;
        }
        char *end;
        int UserInput = strtol(buffer, &end, 10);
        if(end == buffer){
            printf("Error: Invalid Input!!!!\n");
            continue;
        }
        if(UserInput > MaxInput || UserInput < MinInput){
            printf("Error: Invalid Input!!!!\n");
            continue;
        }
        return UserInput;
    }
}

int AllDigits(char array[]){
    for(int i = 0; array[i] != '\0'; i++){
        if(isdigit(array[i]) == 0){
            return 0;
        }
    }
    return 1;
}

void MainMenu(){
    printf("BANK ACCOUNT MANAGEMENT SYSTEM\n");
    printf("_________________________________________________\n");
    printf("Press '1' to Create New Bank Account\n");
    printf("Press '2' to Login to Existing Bank Account\n");
    printf("Press '3' to Exit\n");
    printf("_________________________________________________\n");
}

void AccountMenu(){
    printf("_____________________________________\n");
    printf("Press '1' to Check Account Balance\n");
    printf("Press '2' to Deposit Money\n");
    printf("Press '3' to Withdraw Money\n");
    printf("Press '4' to Transfer Money\n");
    printf("Press '5' to View Transaction History\n");
    printf("Press '6' to Update Account PIN\n");
    printf("Press '7' to Logout\n");
    printf("_____________________________________\n");
}

int GetUserId(char UserId[]){
    char buffer[52];
    fgets(buffer, sizeof(buffer), stdin);
    if(strchr(buffer, '\n') == NULL){
        ClearBuffer();
        printf("Error: User ID too long!!!!\n");
        return 0;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    if(strchr(buffer, ' ') != NULL){
        printf("Error: Space not allowed in User ID!!!!\n");
        return 0;
    }
    strcpy(UserId, buffer);
    return 1;
}

int SearchUserId(char UserId[], FILE *fp){
    BankAccount temp;
    while(fread(&temp, sizeof(temp), 1, fp)){
        if(strcmp(temp.userId, UserId) == 0){
            return 1;
        }
    }
    return 0;
}

int GetPin(char pin[]){
    char buffer[6];
    fgets(buffer, sizeof(buffer), stdin);
    if(strchr(buffer, '\n') == NULL){
        ClearBuffer();
        printf("Error: PIN too long!!!!!\n");
        return 0;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    if(!AllDigits(buffer)){
        printf("Error: Invalid Input!!!!!\n");
        return 0;
    }
    strcpy(pin, buffer);
    return 1;
}

void CreateAccount(){
    FILE *fp = fopen("14_BankAccounts.dat", "ab+");
    if(fp == NULL){
        printf("Error: Unable to Create New Account!!!!\n");
        printf("_________________________________________________\n");
        return;
    }
    BankAccount user;
    while(1){
        printf("_________________________________________________\n");
        printf("Create your User ID (Limit: 50 characters): ");
        int GotUserId = GetUserId(user.userId);
        if(!GotUserId){
            continue;
        }
        int found = SearchUserId(user.userId, fp);
        if(found){
            printf("Error: User ID already exists!!!!\n");
            rewind(fp);
        }else{
            break;
        }
    }
    while(1){
        printf("Create your Account PIN (4 digits): ");
        int GotPin = GetPin(user.pin);
        if(!GotPin){
            continue;
        }else{
            break;
        }
    }
    user.balance = 0;
    fwrite(&user, sizeof(user), 1, fp);
    printf("_________________________________________________\n");
    printf("Account Created Successfully!!!!\n");
    printf("_________________________________________________\n");
    fclose(fp);
    return;
}

void GetTimeStamp(char TimeStamp[], size_t size){
    time_t now;
    struct tm *local;
    time(&now);
    local = localtime(&now);
    strftime(TimeStamp, size, "%Y-%m-%d %H:%M:%S", local);
    return;
}

int SaveTransaction(char userId[], char recipient[], int type, int amount, int balance){
    FILE *fp = fopen("14_transactions.dat", "ab");
    if(fp == NULL){
        printf("Error: Transaction Failed!!!!!\n");
        printf("_________________________________________________\n");
        return 0;
    }
    transaction new;
    strcpy(new.userId, userId);
    new.type = type;
    new.amount = amount;
    new.balance = balance;
    if(recipient != NULL){
        strcpy(new.recipient, recipient);
    }else{
        strcpy(new.recipient, "NA");
    }
    GetTimeStamp(new.TimeStamp, sizeof(new.TimeStamp));
    fwrite(&new, sizeof(new), 1, fp);
    fclose(fp);
    return 1;
}

void UpdateAccount(FILE *fp, BankAccount user){
    fwrite(&user, sizeof(user), 1, fp);
    fflush(fp);
    fseek(fp, -sizeof(user), SEEK_CUR);
}

BankAccount UserLogin(FILE *fp){
    BankAccount user;
    while(1){
        printf("Enter your User ID (Limit: 50 characters): ");
        int GotUserId = GetUserId(user.userId);
        if(!GotUserId){
            continue;
        }
        int found = SearchUserId(user.userId, fp);
        if(!found){
            printf("Error: User ID does not exist!!!!\n");
            rewind(fp);
        }else{
            fseek(fp, -sizeof(user), SEEK_CUR);
            fread(&user, sizeof(user), 1, fp);
            fseek(fp, -sizeof(user), SEEK_CUR);
            break;
        }
    }
    while(1){
        char TempPin[5];
        printf("Enter your Account PIN (4 digits): ");
        int GotPin = GetPin(TempPin);
        if(!GotPin){
            continue;
        }
        if(strcmp(TempPin, user.pin) == 0){
            return user;
        }else{
            printf("Error: Incorrect PIN\n");
        }
    }
}

int GetAmount(){
    char buffer[7];
    while(1){
        printf("Enter Amount (Limit: 10,000 Rupees): ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("Error: Invalid Amount!!!!\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        char *end;
        int bal = strtol(buffer, &end, 10);
        if(end == buffer || *end != '\0'){
            printf("Error: Invalid Amount!!!!\n");
            continue;
        }
        if(bal > 10000 || bal < 1){
            printf("Error: Enter An Amount Between 1 to 10,000!!!!\n");
            continue;
        }
        return bal;
    }
}

BankAccount GetRecipient(FILE *fp, char UserId[]){
    BankAccount recipient;
    while(1){
        printf("Enter the recipient's User ID: ");
        int GotUserId = GetUserId(recipient.userId);
        if(!GotUserId){
            continue;
        }
        if(strcmp(recipient.userId, UserId) == 0){
            printf("Error: User ID And Recipient User ID Can't Be Same!!!!\n");
            continue;
        }
        int found = SearchUserId(recipient.userId, fp);
        if(!found){
            printf("Error: User ID does not exist!!!!\n");
            rewind(fp);
        }else{
            fseek(fp, -sizeof(recipient), SEEK_CUR);
            fread(&recipient, sizeof(recipient), 1, fp);
            fseek(fp, -sizeof(recipient), SEEK_CUR);
            return recipient;
        }
    }
}

void TransferMoney(BankAccount user, FILE *UserFp){
    if(user.balance == 0){
        printf("Error: Insufficient Balance!!!!\n");
        return;
    }
    printf("Account Balance (in Rupees): %d\n", user.balance);
    FILE *fp = fopen("14_BankAccounts.dat", "rb+");
    if(fp == NULL){
        printf("Error: Unable to Transfer Money!!!\n");
        printf("_________________________________________________\n");
        return;
    }
    BankAccount recipient = GetRecipient(fp, user.userId);
    int amount;
    while(1){
        amount = GetAmount();
        if(amount > user.balance){
            printf("Error: Insufficient Balance!!!!\n");
            continue;
        }else{
            user.balance -= amount;
            if(SaveTransaction(user.userId, recipient.userId, 2, amount, user.balance) == 0){
                user.balance += amount;
                return;
            }
            UpdateAccount(UserFp, user);
            break;
        }
    }
    recipient.balance += amount;
    if(SaveTransaction(recipient.userId, user.userId, 1, amount, recipient.balance)){
        fwrite(&recipient, sizeof(recipient), 1, fp);
        fclose(fp);
        printf("_____________________________________\n");
        printf("Money Transfered Successfully!!!!\n");
    }
    return;
}

void TransactionHistory(char UserId[]){
    FILE *fp = fopen("14_transactions.dat", "rb");
    if(fp == NULL){
        printf("Transaction History not available currently\n");
        printf("_________________________________________________\n");
        return;
    }
    transaction user;
    int i = 1;
    while(fread(&user, sizeof(user), 1, fp)){
        if(strcmp(user.userId, UserId) == 0){
            printf("_____________________________________\n");
            printf("Transaction Number: %d\n", i++);
            printf("Time Stamp: %s\n", user.TimeStamp);
            if(user.type == 1){
                printf("Amount (in Rupees): +%d\n", user.amount);
            }
            if(user.type == 2){
                printf("Amount (in Rupees): -%d\n", user.amount);
            }
            printf("Recipient: %s\n", user.recipient);
            printf("Balance: %d\n", user.balance);
            printf("_____________________________________\n");
        }
    }
    fclose(fp);
}

void AccountManage(){
    FILE *fp = fopen("14_BankAccounts.dat", "rb+");
    if(fp == NULL){
        printf("Error: Unable to Log into Account!!!\n");
        printf("_________________________________________________\n");
        return;
    }
    BankAccount user = UserLogin(fp);
    printf("_____________________________________\n");
    printf("Successfully logged into Account\n");
    while(1){
        AccountMenu();
        int UserInput = GetUserIntInput(7, 1);
        switch (UserInput)
        {
        case 1:
            printf("Account Balance (in Rupees): %d\n", user.balance);
            break;
        case 2:
        {
            int amount = GetAmount();
            user.balance += amount;
            if(SaveTransaction(user.userId, NULL, 1, amount, user.balance)){
                UpdateAccount(fp, user);
                printf("_____________________________________\n");
                printf("Rupees %d Added Successfully!!!!\n", amount);
            }
            break;
        }
        case 3:
        {
            if(user.balance == 0){
                printf("Error: Insufficient Balance!!!!\n");
                break;
            }
            printf("Account Balance (in Rupees): %d\n", user.balance);
            int withdrawn = 0;
            while(!withdrawn){
                int amount = GetAmount();
                if(amount > user.balance){
                    printf("Error: Insufficient Balance!!!!\n");
                }else{
                    user.balance -= amount;
                    withdrawn = 1;
                    if(SaveTransaction(user.userId, NULL, 2, amount, user.balance)){
                        UpdateAccount(fp, user);
                        printf("_____________________________________\n");
                        printf("Rupees %d Withdrawn Successfully!!!!\n", amount);
                    }
                }
            }
            break;
        }
        case 4:
            TransferMoney(user, fp);
            break;
        case 5:
            TransactionHistory(user.userId);
            break;
        case 6:
        {
            char TempPin[5];
            while(1){
                printf("Enter New PIN (4 digits): ");
                int GotPin = GetPin(TempPin);
                if(GotPin){
                    strcpy(user.pin, TempPin);
                    break;
                }else{
                    continue;
                }
            }
            UpdateAccount(fp, user);
            printf("_____________________________________\n");
            printf("Account PIN Updated Successfully\n");
            break;
        }
        case 7:
            fclose(fp);
            printf("Logged Out Successfully\n");  
            printf("_____________________________________\n");
            return;
        }
    }
}

int main(){
    while(1){
        MainMenu();
        int UserInput = GetUserIntInput(3, 1);
        switch (UserInput)
        {
        case 1:
            CreateAccount();
            break;
        case 2:;
            AccountManage();
            break;
        case 3:
            return 0;
        }
    }
}