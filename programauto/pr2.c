#include <stdio.h>
int main() {
    /*This program will check if the student studies in Brazil
    If yes, it will greet it, if not, will taunt/provoke it*/
    int number;
    printf("Answer the question: \n");
    printf("If you study in Brasil, type 1 \n");
    printf("If you study somewhere else, type 2 \n");
    printf("Enter your option: \n");
    scanf("%d", &number);

    
    if  (number == 1) {
        printf(" Great! Brasil is a great place to study!");
    }
    else {
        printf(" It is a shame to not study in Brazil !");
    }

    return 0;
}