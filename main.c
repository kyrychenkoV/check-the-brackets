#include <stdio.h>

#define   N 1
#define   M 0
#define  S 40
int validateJSON(char mass[]);

int main(void)
{
    char mass [S]={"{{[]}}"};

    printf(validateJSON(mass)==N?"*TRUE*":"!FOLSE");


    return 0;

}

int validateJSON(char mass[]){
    int i;
    char brace=M,square_bracket=M;
    char o=M;

            for(i=M;mass[i]!=M;i++){
                if(mass[i]=='{'||mass[i]=='}'||mass[i]=='['||mass[i]==']'){

                if(mass[i]=='}'){
                    brace--;

                }
                if(brace<M){
                    o++;
                }
                if(mass[i]=='{'){
                    brace++;

                }


                if(mass[i]==']'){
                    --square_bracket;

                }
                if(square_bracket<M){
                    o++;

                }

                if(mass[i]=='['){
                    ++square_bracket;

               }
           }
    }


    printf ("Brace=%d sqb=%d o=%d\n",brace,square_bracket,o);

        if(brace==M&&square_bracket==M&&o==M){

            return N;
        }
        else{

            return M;
        }


}


