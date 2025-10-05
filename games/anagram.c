/**
 * @brief A simple C program that generates anagrams for a user-entered word.
 *
 * This program reads a word from the user and generates random anagrams (shuffled versions)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Shuffles the characters of a word randomly to create an anagram.
 *
 * Uses the Fisher–Yates (Knuth) shuffle algorithm to ensure each permutation is equally likely.
 *
 * @param word Pointer to the string (character array) to be shuffled.
 *
 * @return void
 */

void shuffle(char *word) {           
    int n = strlen(word);
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);   
        char temp = word[i];      
        word[i] = word[j];
        word[j] = temp;
    }
}

/**
 * @brief The main function of the program.
 *
 * Prompts the user for a word, then generates and displays the anagram
 *
 * @return int Returns 0 on successful execution.
 */

int main() {
    char word[100], guess[100], shuffled[100];

    printf("=== ANAGRAM GENERATOR ===\n");
    printf("Enter a single word: ");
    scanf("%s", word);

    srand(time(0));
    strcpy(shuffled, word);

    do {
        shuffle(shuffled);
    } while (strcmp(shuffled, word) == 0);

    printf("\nAnagram generated: %s\n", shuffled);
    return 0;
}
