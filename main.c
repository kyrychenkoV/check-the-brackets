#include <stdio.h>
#include <stdbool.h>
#define  MAXSIZE 30


int main(void)
{
    char test[][MAXSIZE]={"][","[]","{}","{{[{{}{}},{},{[],[]}]}}","{[]}}","}{","{][}","[{]}"};
    char (*prt)[MAXSIZE];
    prt=test;
    int sizeArray=sizeof(test)/sizeof(test[0]);

    //printf (validateJSON(prt,sizeArray)==false? "FALSE":"TRUE");
    validateJSON(prt,sizeArray);

    return 0;

}

void validateJSON(char prt[][MAXSIZE],int sizeArray){
    int i,s;
    int j;
    int brace=NULL, square_bracket=NULL,o=NULL;
        for (j=NULL;j<sizeArray;j++){
            //int brace=NULL, square_bracket=NULL,o=NULL;
            printf("%s\n",prt[j]);
            for(i=NULL;i<strlen(prt[j]);i++){
                if(prt[j][i]=='{'||prt[j][i]=='}'||prt[j][i]=='['||prt[j][i]==']'){

                if(prt[j][i]=='}'){
                    brace--;

                }
                if(brace<0){
                    o++;
                }
                if(prt[j][i]=='{'){
                    brace++;
                }
                if(prt[j][i]==']'){
                    square_bracket--;
                }
                if(square_bracket<0){
                    o--;
                }
                if(prt[j][i]=='['){
                    ++square_bracket;
                }
                }

            }
          //printf ("Brace=%d sqb=%d o=%d\n",brace,square_bracket,o);
                if(brace==NULL&&square_bracket==NULL&&o==NULL){
                    printf("TRUE\n");
                }
                else{
                   printf("FALSE\n");
                }
            printf("\n");
            brace=NULL, square_bracket=NULL,o=NULL;

        }
}



