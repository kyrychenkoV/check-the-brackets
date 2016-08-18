#include <stdio.h>

#define   N 1
#define   M 0

void jsonVoid(char*c);

int main(void)
{
    char a;
    char *c;
    c=&a;
    jsonVoid(c);

    return 0;
}

void jsonVoid(char *c){
    printf(" After the introduction of a flow hit ENTER then Ctr+Z for Windows or Ctr+D for Linux\n");

    char brace=M,square_bracket=M;
    char o=M;

        while ((c = getchar()) != EOF){

            if(c=='{'||c=='}'||c=='['||c==']'){

                if(c=='}'){
                    brace--;

                }
                if(brace<M){
                    o++;
                }
                if(c=='{'){
                    brace++;

                }



                if(c==']'){
                    --square_bracket;

                }
                if(square_bracket<M){
                    o++;

                }

                if(c=='['){
                    ++square_bracket;

                }

           }
      }


        if(brace==M&&square_bracket==M&&o==M){
            printf ("TRUE*\n");
        }
        else{
            printf ("FALSE");
        }

     fflush(stdin);
}


