#include <stdio.h>

struct Player {
    char name[50];
    int wins;
    int losses;
};

// Function to display player information and win-loss ratio
void displayPlayer(struct Player player) {
    double ratio = (player.losses > 0) ? (double)player.wins / player.losses : (double)player.wins;

    // Display player's information
    printf("\n%-20s %-10s %-10s %-15s\n", "Name", "Wins", "Losses", "Win/Loss Ratio");
    printf("---------------------------------------------\n");
    printf("%-20s %-10d %-10d %.2f\n", player.name, player.wins, player.losses, ratio);
}

int main() {
    struct Player player;

    // Input player data
    printf("Enter player details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", player.name);  // Read string with spaces
    printf("Wins: ");
    scanf("%d", &player.wins);
    printf("Losses: ");
    scanf("%d", &player.losses);

    // Display player information
    displayPlayer(player);

    return 0;
}