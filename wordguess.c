#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main() {
    char words[4][40] = {"Algorithm", "Quarantine", "Photosynthesis", "Eclipse"};
    char hints[4][50] = {"Step by step method to solve a problem", "Isolation to prevent spread of disease", "Plants make food using sunlight", "When the moon hides the sun"};
    
    char guess[20];
    int choice, playMore = 1;
    int tries, maxTries = 3;
    
    srand(time(0));
    
    printf("Word Guessing Game\n");
    printf("==================\n");
    
    while(playMore) {
        choice = rand() % 4;
        tries = 0;
        
        printf("\nHint: %s\n", hints[choice]);
        printf("You have %d tries.\n", maxTries);
        
        while(tries < maxTries) {
            printf("Enter guess: ");
            scanf("%s", guess);
            tries++;
            
            if(strcmp(guess, words[choice]) == 0) {
                printf("Correct! The word was %s\n", words[choice]);
                break;
            } else {
                printf("Wrong! Tries left: %d\n", maxTries - tries);
            }
        }
        
        if(tries == maxTries && strcmp(guess, words[choice]) != 0) {
            printf("Game over! The word was %s\n", words[choice]);
        }
        
        printf("Play again? (1=yes, 0=no): ");
        scanf("%d", &playMore);
    }
    
    printf("Thanks for playing!\n");
    return 0;
}