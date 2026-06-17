// -------------------Making A File Encryption Project-----------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct header{
    int AlgoId;
    char FileExt[10];
}header;

void ClearBuffer(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int GetUserInput(int MaxInput, int MinInput){
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

FILE *GetInputFile(char FileName[]){
    char buffer[25];
    while(1){
        printf("Enter Input File Name: ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("Error: File Name Is Too Long!!!!\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        FILE *fp = fopen(buffer, "rb");
        if(fp == NULL){
            printf("Error: File Not Found!!!!\n");
            continue;
        }
        strcpy(FileName, buffer);
        return fp;
    }
}

FILE *GetOutputFile(char FileName[]){
    FILE *fp = fopen(FileName, "wb");
    if(fp == NULL){
        printf("Error: Something Went Wrong!!!!\n");
        return NULL;
    }else{
        return fp;
    }
}

void GetKey(char key[]){
    char buffer[10];
    while(1){
        printf("Enter Key (Character Limit: 8): ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("Error: Key Exceeds Character Limit!!!!\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(key, buffer);
        return;
    }
}

void xor(FILE *input, FILE *output, char key[], int KeyLength){
    int ch;
    int i = 0;
    while((ch = fgetc(input)) != EOF){
        ch ^= key[i++];
        fputc(ch, output);
        if(i == KeyLength){
            i = 0;
        }
    }
}

void MainMenu(){
    printf("--------------------------------------\n");
    printf("      File Encryption Suite\n");
    printf("--------------------------------------\n");
    printf("Press '1' To Encrypt A File\n");
    printf("Press '2' To Decrypt A File\n");
    printf("Press '3' To Exit\n");
}

void Encrypt(){
    char buffer[30];
    FILE *input = GetInputFile(buffer);
    strcat(buffer, ".enc");
    FILE *output = GetOutputFile(buffer);
    if(output == NULL){
        return;
    }
    GetKey(buffer);
    int KeyLength = strlen(buffer);
    xor(input, output, buffer, KeyLength);
    fclose(input);
    fclose(output);
    printf("----------------------------------------\n");
    printf("Successfully Encrypted File\n");
}

void Decrypt(){
    char buffer[30];
    FILE *input = GetInputFile(buffer);
    char *dot = strrchr(buffer, '.');
    *dot = '\0';
    FILE *output = GetOutputFile(buffer);
    if(output == NULL){
        return;
    }
    GetKey(buffer);
    int KeyLength = strlen(buffer);
    xor(input, output, buffer, KeyLength);
    fclose(input);
    fclose(output);
    printf("----------------------------------------\n");
    printf("Successfully Decrypted File\n");
}

int main(){
    while(1){
        MainMenu();
        int UserInput = GetUserInput(3, 1);
        switch (UserInput)
        {
        case 1:
            Encrypt();
            break;
        case 2:
            Decrypt();
            break;
        case 3:
            return 0;
        }
    }
    return 0;
}