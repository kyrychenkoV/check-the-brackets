#include <stdio.h>
#include <stdbool.h>
#define  MAXSIZE 30
#define  NULL 0

int main(void)
{
    testSuite();
    return 0;
}

int validateJSON(char test[]){
    int i,s;
    int j;
    int brace=NULL, square_bracket=NULL,o=NULL;
    for(i=NULL;i<strlen(test);i++){
        if(test[i]=='{'||test[i]=='}'||test[i]=='['||test[i]==']'){

            if(test[i]=='}'){
                brace--;
            }
            if(brace<0){
                o++;
            }
            if(test[i]=='{'){
                brace++;
            }
            if(test[i]==']'){
                square_bracket--;
            }
            if(square_bracket<0){
                o--;
            }
            if(test[i]=='['){
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

void trueTestsringArray(){
    char testarray[][MAXSIZE]={"[]","[{[]}]","{}","{{[{{}{}}{}{[][]}]}}","{}{}","[][]","{{}}","{[[[][[]]}"};
    int size=sizeof(testarray)/sizeof(testarray[0]);
    printf("\nTest the correct string array. The result should be True\n");
    testCommon(testarray,size);
}

void falseTestsringArray(){
    char testarray[][MAXSIZE]={"][","]}[","}{}{","{{[{{}{}},{]},{[],[]}]}}","{[]}}","}{","{][}","[{]}","{[}]"};
    int sizeArray2=sizeof(testarray)/sizeof(testarray[0]);
    printf("\nTest the false string array. The result should be False\n");
    testCommon(testarray,sizeArray2);
}
void testOnestring(){
    char test[]={"{}"};
    printf("Test one string\n");
    printf(validateJSON(test)==false? "False":"True");
    printf("\n");
}
void testSuite(){
    testOnestring();
    trueTestsringArray();
    falseTestsringArray();
}
void testCommon(char testarray [][MAXSIZE],int size){
    int i=0;
    for(i=0;i<size;i++){
        printf("%d string=",i+1);
        char temp[MAXSIZE];
        strcpy (temp,testarray[i]);
        if (validateJSON(temp)==true){
            printf(" True ");
        }
        else{
            printf("False");
        }
        printf("\n");
    }
}

