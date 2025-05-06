#include "header.h"

// Function to talk to Luna
void talkToLuna() {
    if (activeUser == NULL) {
        printf("No active user. Please choose a user first.\n");
        return;
    }

    char choice[50];
    int talkChoice;

    while (1) {
        clearScreen();
        printf("==== Talking to Luna ====\n");
        printf("Hi! I'm happy to see you here\n");
        printf("1. How are you feeling today, Luna?\n");
        printf("2. What's your favorite thing to do?\n");
        printf("3. Do you want to play a game?\n");
        printf("4. Go back to interaction menu\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &talkChoice);
        getchar(); // Consume leftover newline

        switch (talkChoice) {
        case 1:
            clearScreen();
            printf("Luna: 'I'm feeling great today, thank you for asking!'\n");
            break;
        case 2:
            clearScreen();
            printf("Luna: 'I love playing games and getting attention from you!'\n");
            break;
        case 3:
            clearScreen();
            printf("Luna: 'Sure! I love playing games with you!'\n");
            break;
        case 4:
            return;  // Go back to interaction menu
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

        // Ask if the user wants to continue talking to Luna
        printf("Would you like to ask Luna something else? (Y/y for Yes, any other key to go back to the menu): ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0;

        if (choice[0] != 'Y' && choice[0] != 'y') {
            return;  // Exit to interaction menu
        }
    }
}
