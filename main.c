#include "header.h"

extern USER* activeUser;  // Declare the global active user pointer

int main() {
    int choice;

    while (1) {
        clearScreen();  // Clear the screen before showing the menu
        printf("==== ASCII Pet Menu ====\n");

        if (activeUser != NULL) {
            printf("Current User: %s (ID: %d)\n", activeUser->name, activeUser->id);
        }
        else {
            printf("No active user.\n");
        }

        printf("========================\n");
        printf("1. Add User\n");
        printf("2. Choose User\n");
        printf("3. Add Question\n");
        printf("4. Interact\n");
        printf("5. Quiz Me!\n");
        printf("6. Premade quiz\n");
        printf("7. Leaderboard\n");
        printf("8. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the newline left by scanf

        switch (choice) {
        case 1:
            clearScreen();
            addUser();
            break;
        case 2:
            clearScreen();
            chooseUser();
            break;
        case 3:
            clearScreen();
            addQuestion();
            break;
        case 4:
            clearScreen();
            interact();
            break;
        case 5:
            clearScreen();
            interact();
            break;
        case 6:
            clearScreen();
            startQuiz();
            break;
        case 7:
            clearScreen();
            showLeaderboard();
            break;
        case 8:
            printf("Goodbye!\n");
            if (activeUser != NULL) {
            free(activeUser);
    }
    return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}

