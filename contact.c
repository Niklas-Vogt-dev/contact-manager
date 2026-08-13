#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "input.h"

void print_contacts(struct Contact *contacts, int count) {

    int i;

    for (i = 0; i < count; i++) {
        printf("Kontakt Nummer: %d\n", i);
        printf("Name: %s\n", contacts[i].name);
        printf("Telefon: %s\n", contacts[i].phone);
        printf("E-Mail: %s\n\n", contacts[i].email);
    }
    printf("\n");
}

void change_phone(struct Contact *contact, char new_phone[30]) {
    strcpy(contact->phone, new_phone);
}

int add_contact(struct Contact **contacts, int *count, int *capacity) {

    if (*count >= *capacity) {

        int new_capacity = *capacity * 2;
        struct Contact *helper = realloc(*contacts, new_capacity * sizeof(struct Contact));

        if (helper == NULL) {
            printf("Reallocation failed.\n");
            return 0;
        } else {
            *contacts = helper;
            *capacity = new_capacity;
        }
    }

    get_string("Name: ", (*contacts)[*count].name, sizeof((*contacts)[*count].name));

    get_string("Telefon: ", (*contacts)[*count].phone, sizeof((*contacts)[*count].phone));

    get_string("E-Mail: ", (*contacts)[*count].email, sizeof((*contacts)[*count].email));

    (*count)++;

    return 1;
}

void search_contacts(struct Contact *contacts, int count) {

    char searched_name[50];
    int found = 0;

    get_string("Name suchen: ", searched_name, sizeof(searched_name));

    for (int i = 0; i < count; i++) {

        if (strstr(contacts[i].name, searched_name) != NULL) {

            found = 1;

            printf("\n");
            printf("Gefundener Kontakt:\n");
            printf("Kontakt Nummer: %d\n", i);
            printf("Name: %s\n", contacts[i].name);
            printf("Telefon: %s\n", contacts[i].phone);
            printf("E-Mail: %s\n\n", contacts[i].email);
        }
    }
    
    if (!found) {
        printf("Keinen Kontakt gefunden.\n");
    }
}

int delete_contact(struct Contact **contacts, int *count, int *capacity) {
    
    int korrekt = 0;

    while (!korrekt) {

        int eingabe = get_int("Welcher Kontakt soll gelöscht werden? ");

        if (eingabe >= *count) {
            printf("Ungültige Eingabe.\n");
        } else {
            korrekt = 1;

            for (int i = eingabe; i < *count - 1; i++) {
                (*contacts)[i] = (*contacts)[i + 1];
            }

            (*count)--;

            if (*count <= *capacity / 2 && *capacity > 1) {

                int new_capacity = *capacity / 2;

                struct Contact *helper =
                    realloc(*contacts, new_capacity * sizeof(struct Contact));

                if (helper == NULL) {
                    printf("Reallocation failed.\n");
                    return 0;
                }

                *contacts = helper;
                *capacity = new_capacity;
            }
        }
    }

    return 1;
}

int save_contacts(struct Contact *contacts, int count) {

    FILE *file = fopen("contacts.txt", "w");

    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < count; i++) {
        
        if (fprintf(file, "%s\n", contacts[i].name) < 0 ||
            fprintf(file, "%s\n", contacts[i].phone) < 0 ||
            fprintf(file, "%s\n", contacts[i].email) < 0) {

            fclose(file);
            return 0;
        }
    }

    if (fclose(file) == EOF) {
        return 0;
    }

    return 1;
}

int load_contacts(struct Contact **contacts, int *count, int *capacity) {

    FILE *file = fopen("contacts.txt", "r");

    if (file == NULL) {
        return 0;
    }

    char content[100];

    int contact_number = 0;
    int line = 1;
    while (fgets(content, 100, file)) {

        content[strcspn(content, "\n")] = '\0';

        if (contact_number >= *capacity) {
            int new_capacity = *capacity * 2;
            struct Contact *helper = realloc(*contacts, new_capacity * sizeof(struct Contact));

            if (helper == NULL) {
                printf("Reallocation failed.\n");
                fclose(file);
                return 0;
            } else {
                *contacts = helper;
                *capacity = new_capacity;
            }
        }

        if (line == 1) {
            strcpy((*contacts)[contact_number].name, content);
            line++;
        } else if (line == 2) {
            strcpy((*contacts)[contact_number].phone, content);
            line++;
        } else {
            strcpy((*contacts)[contact_number].email, content);
            line = 1;
            contact_number++;
        }
    }

    *count = contact_number;

    if (line != 1) {
        fclose(file);
        return 0;
    }

    if (ferror(file)) {
        fclose(file);
        return 0;
    }

    fclose(file);

    return 1;
}
