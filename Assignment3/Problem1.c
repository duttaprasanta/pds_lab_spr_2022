/*
* Programmer : Prasanta Dutta
* In this program, I am using functions from <string.h>
* you should implement them by yourself
*/
#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool upperCase(char c){
    return c>='A' && c<='Z';
}
bool lowerCase(char c){
    return c>='a' && c<='z';
}
bool isAlpha(char c){
    return upperCase(c) || lowerCase(c);
}
bool isDigit(char c){
    return c>='0' && c<='9';
}
bool isAlphanumeric(char c){
    return isAlpha(c) || isDigit(c);
}
bool isSpecial(char c){
    return c=='$' || c=='*' || c=='+' || c=='/' || c=='#' || c=='@' || c=='<' || c=='>' || c=='?' || c=='_' || c=='!';
}

char toLower(char c){
    if(upperCase(c)){
        return c+32;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    char username[52]; char password[52];
    printf("username : ");
    fgets(username, 50, stdin);
    printf("password : ");
    fgets(password, 50, stdin);
    username[strlen(username)-1] = '\0';
    password[strlen(password)-1] = '\0';
    int nameLen = strlen(username);
    int passLen = strlen(password);

    bool acceptable = true;
    if(passLen>15){
        printf("The maximum length of the password can be 15 \n");
        acceptable = false;
       
    }
    if(passLen<8){
        printf("Password should be at least 8 character long \n");
        acceptable = false;
    }
    if(strcasestr(password, username)!=NULL || strcasestr(username, password)!=NULL){
        printf("Password should not contain the username \n");
        acceptable = false;
    }
    char specialChars[] = {'$', '*', '+', '/', '#', '@', '<', '>', '?', '_', '!'};
    bool hasUpperCase, hasLowerCase;
    int has2specialChar=0, hasMax5consecutiveDigit=0; 
    int hasMax5repeatedChar;
    int charFreq[26];

    for(int i = 0; i < 26; i++)
    {
        charFreq[i] = 0;
    }
    
    for(int i=0; i<passLen; i++){
        if(upperCase(password[i])){
            hasUpperCase = true;
        }
        else if(lowerCase(password[i])){
            hasLowerCase = true;
        }
        else if(isSpecial(password[i])){
            has2specialChar++;
        }
        if(isDigit(password[i])){
            hasMax5consecutiveDigit++;
        }
        else{ 
            hasMax5consecutiveDigit=0;
        }
        charFreq[toLower(password[i])-(int)'a']++;
    }
    if(!hasLowerCase){
        puts("Password should contain at least one lower case letter");
        acceptable = false;
    }
    if(!hasUpperCase){
        puts("Password should contain at least one upper case letter");
        acceptable = false;
    }
    if(has2specialChar<2){
        puts("Password should contain at least two special characters");
        acceptable = false;
    }
    if(hasMax5consecutiveDigit>5){
        puts("Password should contain max. five consecutive digits");
        acceptable = false;
    }
    
    hasMax5repeatedChar = 0;
    for(int i=0; i<26; i++){
        if(charFreq[i]>1){
            hasMax5repeatedChar++;
        }
    }

    if(hasMax5repeatedChar>5){
        puts("Password should contain max. five repeated characters");
        acceptable = false;
    }

    if(acceptable){
        puts("Acceptable");
    }
    else{
        puts("Not acceptable");
    }
    return 0;
}
