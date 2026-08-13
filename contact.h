#ifndef CONTACT_H
#define CONTACT_H

struct Contact {
    char name[50];
    char phone[30];
    char email[100];
};

void print_contacts(struct Contact *contacts, int count);
void change_phone(struct Contact *contact, char new_phone[30]);
int add_contact(struct Contact **contacts, int *count, int *capacity);
void search_contacts(struct Contact *contacts, int count);
int delete_contact(struct Contact **contacts, int *count, int *capacity);
int save_contacts(struct Contact *contacts, int count);
int load_contacts(struct Contact **contacts, int *count, int *capacity);

#endif