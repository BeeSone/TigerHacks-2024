#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "asciiHangman.c"

#define NUM_WORDS 10
#define MAX_ATTEMPTS 6

const char* random_word() {
    const char* words[NUM_WORDS] = {
        "farming",
        "crops",
        "harvest",
        "livestock",
        "tractors",
        "greenhouse",
        "irrigation",
        "fertilizer",
        "barn",
        "soil"
    };

    int randomIndex = rand() % NUM_WORDS; // Generate a random index
    return words[randomIndex]; // Return the random word
}

// Function to check if the guessed letter is in the word
int is_letter_in_word(char letter, const char* word) {
    return strchr(word, letter) != NULL; // Returns 1 if letter is found, 0 otherwise
}

void play_hangman() {
    srand(time(NULL)); // Seed the random number generator

    const char* word = random_word(); // Get a random word
    int wordLength = strlen(word);
    char guessedWord[wordLength + 1]; // Array to hold the guessed word
    char guessedLetters[26] = {0}; // Array to hold guessed letters
    int attemptsLeft = MAX_ATTEMPTS;
    int correctGuesses = 0;

    // Initialize guessedWord with underscores
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0'; // Null-terminate the string

    printf("Welcome to Hangman!\n");

    while (attemptsLeft > 0 && correctGuesses < wordLength) {
        printf("\nCurrent word: %s\n", guessedWord);
        printHangman(MAX_ATTEMPTS - attemptsLeft);
        printf("Attempts left: %d\n", attemptsLeft);
        printf("Guessed letters: %s\n", guessedLetters);

        char guess;
        printf("Guess a letter: ");
        scanf(" %c", &guess); // Read a single character input

        // Check if the letter was already guessed
        if (strchr(guessedLetters, guess) != NULL) {
            printf("You already guessed that letter. Try again.\n");
            continue;
        }

        // Add the guessed letter to the guessedLetters array
        guessedLetters[strlen(guessedLetters)] = guess;

        if (is_letter_in_word(guess, word)) {
            // If the letter is in the word, update guessedWord
            for (int i = 0; i < wordLength; i++) {
                if (word[i] == guess) {
                    guessedWord[i] = guess; // Update guessedWord
                    correctGuesses++;
                }
            }
            printf("Good guess! The letter '%c' is in the word.\n", guess);
        } 
        else {
            attemptsLeft--; // Decrease attempts if the letter is not found
            printf("Wrong guess! The letter '%c' is not in the word.\n", guess);
        }
    }

    // Game result
    if (correctGuesses == wordLength) {
        printHangman(MAX_ATTEMPTS - attemptsLeft);
        printf("\n\n\n");
        printf("-----------------------");
        printf("\nCongratulations! You've guessed the word: %s\n", word);
        printf("-----------------------");
        printf("\n\n\n");

    } else {
        printHangman(MAX_ATTEMPTS - attemptsLeft);
        printf("\n\n\n");
        printf("-----------------------");
        printf("\nOut of attempts! The word was: %s\n", word);
        printf("-----------------------");
        printf("\n\n\n");
    }
}

int main() {
    play_hangman(); // Start the Hangman game
    return 0;
}
