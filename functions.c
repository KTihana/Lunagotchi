#include "header.h"

// Global variable to track the active user
USER* activeUser = NULL;

// Function to clear the screen (platform dependent)
void clearScreen() {
#ifdef _WIN32
    system("cls");  // Windows
#else
    system("clear");  // Unix-based (Linux/macOS)
#endif
}

// Function to load ASCII art (assuming you have it in another file)
void loadASCII() {
    printf("Loading ASCII art...\n");
    // ASCII art logic here
}

// Function to add a new user
void addUser() {
    USER newUser;
    printf("Enter username: ");
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0;  // Remove newline character
    newUser.id = rand() % 900000 + 1;  // Random ID between 1 and 1000
    newUser.highScore = 0;
    newUser.credits = 200;
    newUser.health = 100;  // Starting health

    // Save the user to a file
    saveUserToFile(&newUser);
}

// Function to save the user to a file
void saveUserToFile(USER* user) {
    FILE* file = fopen("users.dat", "ab");
    if (file == NULL) {
        perror("Error opening file.\n");
        return;
    }
    fwrite(user, sizeof(USER), 1, file);
    fclose(file);
    printf("User saved successfully.\n");
}

// Function to add a question to the quiz
void addQuestion() {
    // Code to add a question
    printf("Adding a question...\n");
}

// Function to test the quiz
void testQuiz() {
    // Quiz logic goes here
    printf("Testing quiz...\n");
}

// Function for the "Interact" menu (feeding pet, talking to Luna, etc.)
void interact() {
    int choice;
    while (1) {
        clearScreen();
        printf("==== Interaction Menu ====\n");
        printf("1. Feed Pet\n");
        printf("2. Talk to Luna\n");
        printf("3. Go Back\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
        case 1:
            printf("Feeding the pet...\n");
            // Code for feeding pet (not implemented yet)
            break;
        case 2:
            talkToLuna();  // Call to the function you moved to Luna.c
            break;
        case 3:
            return;  // Go back to the main menu
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}

// Function to start a quiz
void startQuiz() {
    // Code for starting the quiz
    printf("Starting quiz...\n");
}

// Function to show the leaderboard
void showLeaderboard() {
    // Code to show the leaderboard
    printf("Showing leaderboard...\n");
}

// Function to choose a user from the list
void chooseUser() {
    FILE* file = fopen("users.dat", "rb");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }

    USER users[100];
    int userCount = 0;

    while (fread(&users[userCount], sizeof(USER), 1, file)) {
        userCount++;
    }
    fclose(file);

    if (userCount == 0) {
        printf("No users to choose from.\n");
        return;
    }

    printf("Choose a user:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%d. %s\n", i + 1, users[i].name);
    }

    int choice;
    printf("Enter user number: ");
    scanf("%d", &choice);
    getchar(); // Consume leftover newline

    if (choice < 1 || choice > userCount) {
        printf("Invalid choice.\n");
        return;
    }

    activeUser = &users[choice - 1];  // Set active user
    printf("Active user set to: %s\n", activeUser->name);
}


