#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char itemType[50];
    int quantity;
    char expiryDate[20];
    char donorName[50];
    int isPerishable;
    int isExpired;
} Donation;

Donation donations[MAX_ITEMS];
int donationCount = 0;

int isExpired(char expiryDate[]) {
    return 0; // Dummy expiry checker
}

void addDonation() {
    if (donationCount >= MAX_ITEMS) {
        printf("Donation storage full.\n");
        return;
    }

    Donation d;
    printf("Enter item type: ");
    scanf(" %[^\n]", d.itemType);
    printf("Enter quantity: ");
    scanf("%d", &d.quantity);
    printf("Enter expiry date (YYYY-MM-DD): ");
    scanf(" %[^\n]", d.expiryDate);
    printf("Enter donor name: ");
    scanf(" %[^\n]", d.donorName);
    printf("Is item perishable? (1 = Yes, 0 = No): ");
    scanf("%d", &d.isPerishable);

    d.isExpired = isExpired(d.expiryDate);
    donations[donationCount++] = d;

    printf("Donation recorded successfully.\n");
}
