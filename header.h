// header.h
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the USER structure
typedef struct {
    char name[30];
    int id;
    int highScore;
    int credits;
    int health;
} USER;

extern USER* activeUser;  // Declare activeUser as an external variable

// Function declarations
void loadASCII();
void addUser();
void saveUserToFile(USER* user);
void clearScreen();
void addQuestion();
void testQuiz();
void interact();
void startQuiz();
void showLeaderboard();
void talkToLuna();

#endif