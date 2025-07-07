#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char *name;
    int wins;
    int losses;
};

// Function to display player information and win-loss ratio
void displayPlayer(struct Player player) {
    double ratio = (player.losses > 0) ? (double)player.wins / player.losses : (double)player.wins;

    // Display player's information
    printf("%-20s %-10d %-10d %.2f\n", player.name, player.wins, player.losses, ratio);
}

// Function to display the header
void displayHeader() {
    printf("\n%-20s %-10s %-10s %-15s\n", "Name", "Wins", "Losses", "Win/Loss Ratio");
    printf("---------------------------------------------\n");
}

int main() {
    int N;
    printf("Enter the number of players: ");
    scanf("%d", &N);
    getchar();  // To consume the newline left by scanf

    // Dynamically allocate memory for N players
    struct Player *players = (struct Player*) malloc(N * sizeof(struct Player));

    for (int i = 0; i < N; i++) {
        players[i].name = NULL;  // Initialize the name pointer to NULL
        size_t len = 0;

        // Input player data
        printf("\nEnter details for player %d:\n", i + 1);
        printf("Name: ");
        getline(&players[i].name, &len, stdin);  // Use getline to read the name

        // Remove newline character if present
        if (players[i].name[strlen(players[i].name) - 1] == '\n') {
            players[i].name[strlen(players[i].name) - 1] = '\0';
        }

        printf("Wins: ");
        scanf("%d", &players[i].wins);
        printf("Losses: ");
        scanf("%d", &players[i].losses);
        getchar();  // To consume the newline left by scanf
    }

    // Display all players' information
    displayHeader();
    for (int i = 0; i < N; i++) {
        displayPlayer(players[i]);
    }

    // Free dynamically allocated memory for player names and the player array
    for (int i = 0; i < N; i++) {
        free(players[i].name);
    }
    free(players);

    return 0;
}