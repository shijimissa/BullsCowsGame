#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGITS 4

// Function to generate a random four-digit number
int generateRandomNumber() {
    int number = 0;
    for (int i = 0; i < DIGITS; ++i) {
        int digit;
        do {
            digit = rand() % 10;
        } while (digit == 0 && i == 0);  // Ensure the first digit is not zero
        number = number * 10 + digit;
    }
    return number;
}

// Function to count bulls and cows
void countBullsAndCows(int secretNumber, int guess, int *bulls, int *cows) {
    *bulls = 0;
    *cows = 0;

    int secretDigits[DIGITS];
    int guessDigits[DIGITS];

    // Parse the numbers into digits
    for (int i = 0; i < DIGITS; ++i) {
        secretDigits[i] = secretNumber % 10;
        guessDigits[i] = guess % 10;
        secretNumber /= 10;
        guess /= 10;
    }

    // Count bulls and cows
    for (int i = 0; i < DIGITS; ++i) {
        if (guessDigits[i] == secretDigits[i]) {
            (*bulls)++;
        } else {
            for (int j = 0; j < DIGITS; ++j) {
                if (guessDigits[i] == secretDigits[j]) {
                    (*cows)++;
                    break;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int secretNumber = generateRandomNumber();
    int attempts = 0;
    int guess;

    printf("Welcome to the 'Bulls and Cows' game!\n");
    printf("Try to guess the four-digit number.\n");

    do {
        // Get the user's guess
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // Check the input
        if (guess < 1000 || guess > 9999) {
            printf("Please enter a four-digit number.\n");
            continue;
        }

        // Count bulls and cows
        int bulls, cows;
        countBullsAndCows(secretNumber, guess, &bulls, &cows);

        // Display the result
        printf("Result of attempt: %d bull(s) and %d cow(s)\n", bulls, cows);

        // Increase the number of attempts
        attempts++;
    } while (secretNumber != guess);

    // Display the congratulations message
    printf("Congratulations! You guessed the number %d in %d attempts.\n", secretNumber, attempts);

    return 0;
}
