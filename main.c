#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "input.h"

int main(void)
{
    int count = 0;
    int capacity = 3;

    struct Contact *contacts = malloc(capacity * sizeof(struct Contact));
    if (contacts == NULL) {
        printf("Allocation failed.\n");
        return 1;
    }

    if (!load_contacts(&contacts, &count, &capacity)) {

        strcpy(contacts[0].name, "Max Mustermann");
        strcpy(contacts[0].phone, "0123456789");
        strcpy(contacts[0].email, "max@muster.de");

        strcpy(contacts[1].name, "Anna Schmidt");
        strcpy(contacts[1].phone, "0987654321");
        strcpy(contacts[1].email, "anna@muster.de");

        strcpy(contacts[2].name, "Peter Müller");
        strcpy(contacts[2].phone, "0155555555");
        strcpy(contacts[2].email, "peter@muster.de");

        count = 3;
    }

    int end = 0;
    while (end == 0) {
        printf("===== CONTACT MANAGER =====\n");
        printf("\n");

        printf("1. Kontakte anzeigen\n");
        printf("2. Kontakt hinzufügen\n");
        printf("3. Telefonnummer ändern\n");
        printf("4. Kontakt suchen\n");
        printf("5. Kontakt löschen\n");
        printf("6. Kontakte speichern\n");
        printf("7. Beenden\n");
        printf("\n");

        int auswahl = get_int("Eingabe: ");
        printf("\n");

        switch (auswahl)
        {
        case 1:
            print_contacts(contacts, count);
            break;

        case 2:
            if (add_contact(&contacts, &count, &capacity)) {
                printf("Kontakt erfolgreich hinzugefügt.\n");
                printf("\n");
            } else {
                printf("Kontakt konnte nicht hinzugefügt werden.\n");
                printf("\n");
            }
            break;

        case 3:
            int korrekt = 0;
            int eingabe;

            while (!korrekt) {
                eingabe = get_int("Welcher Kontakt soll angepasst werden? ");
                if (eingabe >= count) {
                    printf("Ungültige Eingabe.\n");
                } else {
                    korrekt = 1;
                }
            }

            char new_number[30];
            get_string("Neue Nummer: ", new_number, sizeof(new_number));
            
            change_phone(&contacts[eingabe], new_number);
            break;

        case 4:
            search_contacts(contacts, count);
            break;

        case 5:
            if (delete_contact(&contacts, &count, &capacity)) {
                printf("Kontakt erfolgreich gelöscht.\n");
                printf("\n");
            } else {
                printf("Kontakt konnte nicht gelöscht werden.\n");
                printf("\n");
            }
            break;

        case 6:
            if (save_contacts(contacts, count)) {
                printf("Kontakte erfolgreich gespeichert.\n");
                printf("\n");
            } else {
                printf("Kontakte konnten nicht gespeichert werden.\n");
                printf("\n");
            }
            break;

        case 7:
            end = 1;
            printf("Bis zum nächsten mal.");
            break;

        default:
            printf("Ungültige Eingabe.\n");
            break;
        }
    }

    free(contacts);

    return 0;
}