#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char keywords[5][10] = {"int", "float", "if", "else", "while"};

int isKeyword(char buffer[]){
    for(int i=0;i<5;i++){
        if( strcmp(keywords[i],buffer) ==  1){
            return 1;
        }
    }

    return 0;
}


int main(){
    char ch,buffer[20];
    FILE *fp = fopen("input.txt","r");
    int j=0;


    while(  (ch = fgetc(fp)) != EOF ){

        if(ch==' ' || ch=='\t' || ch=='\n'){
            continue;
        }

        if(isalpha(ch) || ch=="_"){
            buffer[j++] = ch;

            while((ch=fgetc(fp)) != EOF && (isalnum(ch) || ch=="_")){
                buffer[j++]=ch;
            }
            buffer[j] = '\0';
            j=0;
            ungetc(ch, fp);


            if(isKeyword(buffer)){
                printf("%s : Keyword\n",buffer);
            }
            else{
                printf("%s: Identifier\n",buffer);
            }

        }

        else if(isdigit(ch)){
            buffer[j++] = ch;
            int has_dot = 0;

            while((ch=fgetc(fp)) != EOF && (isdigit(ch) || (ch=="." && !has_dot) )){
                if(ch==".") has_dot=1;

                buffer[j++] = ch;

            }

            buffer[j] = '\0';
            ungetc(ch,fp);
            j=0;

            if(has_dot){
                printf("%s : Float");
            }else{
                printf("%s : int");
            }
        }



        else if(strchr("<>!=+-*/",ch)){
            char next = fgetc(fp);
            
        }


        
    }
}