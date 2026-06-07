// --------------Project - Telephone directory-------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct contact{
    char name[51];
    char num[15]; 
    char email[51];
}contact;

void FileError(){
    (printf("_____________________________________________\n"));
    printf("Error: Failed To Open Contacts File!!!\n");
    (printf("_____________________________________________\n"));
    return;
}

void ClearBuffer(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

void LowerCase(char string[]){
    for(int i = 0; string[i] != '\0'; i++){
        string[i] = tolower((unsigned char)string[i]);
    }
}

void PrintContact(contact new){
    printf("_____________________________________________\n");
    printf("Contact Details:-\n");
    printf("Contact's Name: %s\n", new.name);
    printf("Contact's Number: ");
    int NumLen = strlen(new.num);
    if(NumLen == 10){
        printf("%s\n", new.num);
    }else{
        printf("+");
        int extra = NumLen - 10;
        for(int i = 0; i < NumLen; i++){
            if(i == extra){
                printf(" ");
            }
            printf("%c", new.num[i]);
        }
        printf("\n");
    }
    printf("Contact's Email: %s\n", new.email);
    printf("_____________________________________________\n");
    return;
}

void ContactMenu(){
    printf("TELEPHONE DIRECTORY\n");
    printf("Press The Number To Select The Option:- \n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Show All Contacts\n");
    printf("4. Update Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
}

int GetUserIntInput/*Single digit*/(int MaxInput, int MinInput){ 
    char buffer[3];
    while(1){
        printf("Enter Option: ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("Error: Invalid Input!!!!!\n");
            continue;
        }
        char *end;
        int TempUserInput = strtol(buffer, &end, 10);
        if(end == buffer){
            printf("Error: Invalid Input!!!!!\n");
            continue;
        }
        if(TempUserInput > MaxInput || TempUserInput < MinInput){
            printf("Error: Invalid Input!!!!!\n");
            continue;
        }
        return TempUserInput;
    }
}

void GetContactName(char name[]){
    while(1){
        char buffer[52];
        printf("Enter Contact's Name (Limit: 50 characters): ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("_____________________________________________\n");
            printf("Error: Name Too Long!!!!!!!\n");
            printf("_____________________________________________\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        int i = 0, j = 0, space = 0;
        while(isspace(buffer[i])){
            i++;
        }
        while(buffer[i] != '\0'){
            if(isspace(buffer[i])){
                if(!space){
                    buffer[j++] = ' ';
                    space = 1;
                }
            }else{
                buffer[j++] = buffer[i];
                space = 0;
            }
            i++;
        }
        if(j > 0 && buffer[j-1] == ' '){
            j--;
        }
        buffer[j] = '\0';
        if(strlen(buffer) == 0){
            printf("_____________________________________________\n");
            printf("Error: Invalid Input!!!!!!!\n");
            printf("_____________________________________________\n");
            continue;
        }
        strcpy(name, buffer);
        break;
    } 
}

void GetContactNumber(char num[]){
    while(1){
        char buffer[20];
        printf("Enter Contact's Number (Strictly With Country Code): ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("_____________________________________________\n");
            printf("Error: Invalid Number!!!!!\n");
            printf("_____________________________________________\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        int i = 0, j = 0, length = 0;
        while(buffer[i] != '\0'){
            if(isdigit(buffer[i])){
                length++;
                buffer[j++] = buffer[i];
            }
            i++;
        }
        buffer[j] = '\0';
        if(length < 11 || length > 13){
            printf("_____________________________________________\n");
            printf("Error: Invalid Number!!!!!!\n");
            printf("_____________________________________________\n");
            continue;
        }
        strcpy(num, buffer);  
        break;
    }
}

void GetContactEmail(char email[]){
    while(1){
        char buffer[52];
        printf("Enter Contact's Email (Limit: 50 Characters): ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("_____________________________________________\n");
            printf("Error: Email Too Long!!!!\n");
            printf("_____________________________________________\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        int i = 0, space = 0, AtSymbol = 0, DotSymbol = 0;
        while(buffer[i] != '\0'){
            if(isspace(buffer[i])){
                space = 1;
                break;
            }
            if(buffer[i] == '@'){
                if(i == 0){
                    break;
                }
                AtSymbol++;
            }
            if(AtSymbol){
                if(buffer[i] == '.'){
                    DotSymbol = 1;
                }
            }
            i++;
        }
    if(space == 1 || AtSymbol != 1 || DotSymbol != 1){
        printf("_____________________________________________\n");
        printf("Error: Invalid Input!!!!!\n");
        printf("_____________________________________________\n");
        continue;
    }
    strcpy(email, buffer);
    break;
    }
}

int SearchContactByName(FILE *fp, char name[]){
    LowerCase(name);
    int found = 0;
    contact new;
    while(fread(&new, sizeof(new), 1, fp)){
        LowerCase(new.name);
        if(strcmp(name, new.name) == 0){
            found = 1;
            return found;
        }
    }
    if(!found){
        fseek(fp, 0, SEEK_SET);
        return found;
    }
}

int SearchContactByNum(FILE *fp, char num[]){
    int found = 0;
    contact new;
    while(fread(&new, sizeof(new), 1, fp)){
        if(strcmp(new.num, num) == 0){
            found = 1;
            return found;
        }
    }
    if(!found){
        fseek(fp, 0, SEEK_SET);
        return found;
    }
}

void AddContact(){
    FILE *fp = fopen("13_project3.dat", "ab+");
    if(fp == NULL){
        FileError();
        return;
    }
    contact new;
    int found = 1;
    while(found){
        GetContactName(new.name);
        char copy[51];
        strcpy(copy, new.name);
        found = SearchContactByName(fp, copy);
        if(found){
            (printf("_____________________________________________\n"));
            printf("Error: Name Already Exists!!!!!\n");
            fseek(fp, -sizeof(contact), SEEK_CUR);
            contact temp;
            fread(&temp, sizeof(contact), 1, fp);
            PrintContact(temp);
            rewind(fp);
        }
    }
    found = 1;
    while(found){
        GetContactNumber(new.num);
        found = SearchContactByNum(fp, new.num);
        if(found){
            (printf("_____________________________________________\n"));
            printf("Error: Phone Number Already Exists!!!!\n");
            fseek(fp, -sizeof(contact), SEEK_CUR);
            contact temp;
            fread(&temp, sizeof(contact), 1, fp);
            PrintContact(temp);
            rewind(fp);
        }
    }
    GetContactEmail(new.email);
    fwrite(&new, sizeof(new), 1, fp);
    fclose(fp);
    printf("_____________________________________________\n");
    printf("Contact Saved Successfully!!!!\n");
    PrintContact(new);
    return;
}

int SearchContact(FILE *fp){
    printf("Press '1' To Search Contact By Name\n");
    printf("Press '2' To Search Contact By Phone Number\n");
    int UserInput = GetUserIntInput(2, 1);
    int found;
    switch(UserInput){
        case 1:;
            char name[51];
            GetContactName(name);
            found = SearchContactByName(fp, name);
            break;
        case 2:;
            char num[15];
            GetContactNumber(num);
            found = SearchContactByNum(fp, num);
            break;
    }
    return found;
}

void SearchAndShowContact(){
    FILE *fp = fopen("13_project3.dat", "ab+");
    if(fp == NULL){
        FileError();
        return;
    }
    int found = SearchContact(fp);
    if(!found){
        printf("_____________________________________________\n");
        printf("Error: Contact Not Found\n");
        printf("_____________________________________________\n");
    }else{
        fseek(fp, -sizeof(contact), SEEK_CUR);
        contact new;
        fread(&new, sizeof(contact), 1, fp);
        printf("_____________________________________________\n");
        printf("Contact Found Successfully!!!!!!\n");
        PrintContact(new);
    }
    fclose(fp);
    return;
}

void ShowAllContacts(){
    FILE *fp = fopen("13_project3.dat", "ab+");
    if(fp == NULL){
        FileError();
        return;
    }
    contact new;
    int found = 0;
    while(fread(&new, sizeof(new), 1, fp) == 1){
        found = 1;
        PrintContact(new);
    }
    if(!found){
        printf("_____________________________________________\n");
        printf("Error: No Contacts Found!!!!!!\n");
        printf("_____________________________________________\n");
    }
    fclose(fp);
    return;
}

void UpdateContact(FILE *fp){
    contact temp;
    fread(&temp, sizeof(contact), 1, fp);
    fseek(fp, -sizeof(contact), SEEK_CUR);
    printf("________________________________________\n");
    printf("Press 1 to Update Contact's Name\n");
    printf("Press 2 to Update Contact's Phone Number\n");
    printf("Press 3 to Update Contact's Email\n");
    printf("Press 4 to Update Entire Contact\n");
    printf("________________________________________\n");
    int UserInput = GetUserIntInput(4, 1);
    switch (UserInput)
    {
    case 1:
        GetContactName(temp.name);
        fwrite(&temp, sizeof(contact), 1, fp);
        printf("________________________________________\n");
        printf("Contact's Name Successfully Updated!!!!\n");
        PrintContact(temp);
        break;
    case 2:
        GetContactNumber(temp.num);
        fwrite(&temp, sizeof(contact), 1, fp);
        printf("________________________________________\n");
        printf("Contact's Phone Number Successfully Updated!!!!\n");
        PrintContact(temp);
        break;
    case 3:
        GetContactEmail(temp.email);
        fwrite(&temp, sizeof(contact), 1, fp);
        printf("________________________________________\n");
        printf("Contact's Email Successfully Updated!!!!\n");
        PrintContact(temp);
        break;
    case 4:
        GetContactName(temp.name);
        GetContactNumber(temp.num);
        GetContactEmail(temp.email);
        fwrite(&temp, sizeof(contact), 1, fp);
        printf("________________________________________\n");
        printf("Contact Successfully Updated!!!!\n");
        PrintContact(temp);
        break;
    }
}

void SearchAndUpdateContact(){
    FILE *fp = fopen("13_project3.dat", "ab+");
    if(fp == NULL){
        FileError();
        return;
    }
    printf("_____________________________________________\n");
    printf("Search The Contact To Update It\n");
    int found = SearchContact(fp);
    if(!found){
        printf("_____________________________________________\n");
        printf("Error: Contact Not Found\n");
        printf("_____________________________________________\n");
    }else{
        fseek(fp, -sizeof(contact), SEEK_CUR);
        long pos = ftell(fp); //pos = file pointer position
        fclose(fp);
        FILE *fp = fopen("13_project3.dat", "r+b");
        if(fp == NULL){
            FileError();
            return;
        }
        fseek(fp, pos, SEEK_SET);
        UpdateContact(fp);
        fclose(fp);
    }
}

void DeleteContact(FILE *fp){
    fseek(fp, -sizeof(contact), SEEK_CUR);
    contact delete;
    fread(&delete, sizeof(contact), 1, fp);
    fseek(fp, 0, SEEK_SET);
    FILE *temp = fopen("temp.dat", "ab+");
    if(temp == NULL){
        FileError();
        return;
    }
    contact new;
    while(fread(&new, sizeof(contact), 1, fp)){
        if(strcmp(new.name, delete.name) == 0){
            continue;
        }
        fwrite(&new, sizeof(contact), 1, temp);
    }
    printf("_______________________________________\n");
    printf("Contact Successfully Deleted\n");
    printf("_______________________________________\n");
    fclose(fp);
    fclose(temp);
    remove("13_project3.dat");
    rename("temp.dat", "13_project3.dat");
}

void SearchAndDeleteContact(){
    FILE *fp = fopen("13_project3.dat", "ab+");
    if(fp == NULL){
        FileError();
        return;
    }
    printf("_____________________________________________\n");
    printf("Search The Contact To Delete It\n");
    int found = SearchContact(fp);
    if(!found){
        printf("_____________________________________________\n");
        printf("Error: Contact Not Found\n");
        printf("_____________________________________________\n");
    }else{
        DeleteContact(fp);
    }
}

int main(){
    while(1){
        ContactMenu();
        int UserInput = GetUserIntInput(6, 1);
        switch(UserInput)
        {
        case 1: 
            AddContact();
            break;
        case 2: 
            SearchAndShowContact();
            break;
        case 3: 
            ShowAllContacts();
            break;
        case 4:
            SearchAndUpdateContact();
            break;
        case 5:
            SearchAndDeleteContact();
            break;
        case 6:
            printf("Successfully Exited\n");
            return 0;
        }
    }
    return 0;
}