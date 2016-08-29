#include <stdio.h>
#include <stdbool.h>
#define  MAXSIZE 30
#define  NULL 0

int main(void)
{
    char test[][MAXSIZE]={"{}[]"};
    char truearraytest[][MAXSIZE]={"[]","{[]}","{}","{{[{{}{}}{}{[][]}]}}","{}{}","[][]","{{}}","{[[{[]}]]}"};
    char falsearraytest[][MAXSIZE]={"][","]}[","}{}{","{{[{{}{}},{]},{[],[]}]}}","{[]}}","}{","{][}","[{]}","{[}]"};

    char (*prt)[MAXSIZE],(*prt1)[MAXSIZE],(*prt2)[MAXSIZE];

    prt=test;
    prt1=truearraytest;
    prt2=falsearraytest;


    int sizeArray=sizeof(test)/sizeof(test[0]);
    int sizeArray1=sizeof(truearraytest)/sizeof(truearraytest[0]);
    int sizeArray2=sizeof(falsearraytest)/sizeof(falsearraytest[0]);

    testOnestring(prt,sizeArray);
    trueTestsringArray(prt1,sizeArray1);
    falseTestsringArray(prt2,sizeArray2);

    return 0;

}

int validateJSON(char prt[][MAXSIZE],int sizeArray){
    int i,s;
    int j;
    int brace=NULL, square_bracket=NULL,o=NULL;
        for (j=NULL;j<sizeArray;j++){
            int brace=NULL, square_bracket=NULL,o=NULL;
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
                if(brace==NULL&&square_bracket==NULL&&o==NULL){
                    return true;
                }
                else{
                   return false;
                }
            printf("\n");
        }
}

void trueTestsringArray(char prt1[][MAXSIZE],int sizeArray1){
    int i;
    printf("\nTest the correct string array. The result should be True\n");
        for(i=0;i<sizeArray1;i++){
            printf("%d string=",i+1);
            printf (validateJSON(prt1[i],sizeArray1)==true? "True":"False");
            if (validateJSON(prt1[i],sizeArray1)==false){
                printf(" %s No valid string",prt1[i]);
            }
            printf("\n");
        }
}

void falseTestsringArray(char prt2[][MAXSIZE],int sizeArray2){
    int i;
    printf("\nTest the false string array. The result should be True\n");
        for(i=0;i<sizeArray2;i++){
            printf("%d string=",i+1);
            printf (validateJSON(prt2[i],sizeArray2)==false? "True":"False");
                if (validateJSON(prt2[i],sizeArray2)==true){
                    printf(" %s No valid string",prt2[i]);
                }
            printf("\n");

        }
}
void testOnestring(char prt[][MAXSIZE],int sizeArray){
    printf("Test one string\n");
    printf (validateJSON(prt,sizeArray)==false? "False":"True");
    printf("\n");
}
