#include <stdio.h>
#include <string.h>
#include <regex.h>

#define MAX_CONTACTS 120

typedef struct {
    char nom[50];
    char telephone[15];
    char email[50];
} Contact;

Contact contacts[MAX_CONTACTS];
<<<<<<< HEAD
int nb = 5;
=======
int nb_C = 5;
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98

void initialize_contacts() {
    strcpy(contacts[0].nom, "Alice");
    strcpy(contacts[0].telephone, "0612345678");
    strcpy(contacts[0].email, "alice@example.com");

    strcpy(contacts[1].nom, "Bob");
    strcpy(contacts[1].telephone, "0712345678");
    strcpy(contacts[1].email, "bob@example.com");

    strcpy(contacts[2].nom, "Charlie");
    strcpy(contacts[2].telephone, "0612345679");
    strcpy(contacts[2].email, "charlie@example.com");

    strcpy(contacts[3].nom, "David");
    strcpy(contacts[3].telephone, "0712345670");
    strcpy(contacts[3].email, "david@example.com");

    strcpy(contacts[4].nom, "Eve");
    strcpy(contacts[4].telephone, "0612345680");
    strcpy(contacts[4].email, "eve@example.com");
}

int validate_email(char email[]) {
    regex_t regex;
    int reti;
    reti = regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$", REG_EXTENDED);
    if (reti) return 0;
    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    return reti == 0;
}

int validate_phone(char phone[]) {
    return strncmp(phone, "06", 2) == 0 || strncmp(phone, "07", 2) == 0;
}

void saisir_contact(Contact contact) {
    printf("Nom: ");
    scanf("%s", contact.nom);
    while (1) {
        printf("Telephone (doit commencer par 06 ou 07): ");
        scanf("%s", contact.telephone);
        if (validate_phone(contact.telephone)) {
            break;
        } else {
            printf("Erreur: le numero doit commencer par 06 ou 07.\n");
        }
    }
    while (1) {
        printf("Email: ");
        scanf("%s", contact.email);
        if (validate_email(contact.email)) {
            break;
        } else {
            printf("Erreur: format d'email invalide.\n");
        }
    }
}

void ajouter_contact_simple() {
<<<<<<< HEAD
    if (nb < MAX_CONTACTS) {
        saisir_contact(contacts[nb]);
        nb++;
=======
    if (nb_C < MAX_CONTACTS) {
        saisir_contact(contacts[nb_C]);
        nb_C++;
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
    } else {
        printf("Le carnet de contacts est plein.\n");
    }
}

void ajouter_contact_multiple() {
    int count;
    printf("Combien de contacts voulez-vous ajouter ? ");
    scanf("%d", &count);
<<<<<<< HEAD
    if (count <= 0 || count + nb > MAX_CONTACTS) {
=======
    if (count <= 0 || count + nb_C > MAX_CONTACTS) {
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
        printf("Erreur: nombre de contacts invalide ou depassement de capacite.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
<<<<<<< HEAD
        if (nb < MAX_CONTACTS) {
            printf("Ajout du contact %d:\n", i + 1);
            saisir_contact(contacts[nb]);
            nb++;
=======
        if (nb_C < MAX_CONTACTS) {
            printf("Ajout du contact %d:\n", i + 1);
            saisir_contact(contacts[nb_C]);
            nb_C++;
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
        }
    }
}

void afficher_contacts() {
<<<<<<< HEAD
    for (int i = 0; i < nb; i++) {
=======
    for (int i = 0; i < nb_C; i++) {
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
        printf("Nom: %s, Telephone: %s, Email: %s\n", 
               contacts[i].nom, 
               contacts[i].telephone, 
               contacts[i].email);
    }
}

void afficher_statistiques() {
    int count_06 = 0, count_07 = 0;
<<<<<<< HEAD
    for (int i = 0; i < nb; i++) {
=======
    for (int i = 0; i < nb_C; i++) {
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
        if (strncmp(contacts[i].telephone, "06", 2) == 0) {
            count_06++;
        } else if (strncmp(contacts[i].telephone, "07", 2) == 0) {
            count_07++;
        }
    }
    printf("Nombre de contacts avec telephone commençant par 06: %d\n", count_06);
    printf("Nombre de contacts avec telephone commençant par 07: %d\n", count_07);
}

void modifier_contact() {
    char nom[50];
    printf("Entrez le nom du contact à modifier: ");
    scanf("%s", nom);
<<<<<<< HEAD
    for (int i = 0; i < nb; i++) {
=======
    for (int i = 0; i < nb_C; i++) {
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
        if (strcmp(contacts[i].nom, nom) == 0) {
            saisir_contact(contacts[i]);
            return;
        }
    }
    printf("Contact non trouve.\n");
}

void supprimer_contact() {
    char nom[50];
    printf("Entrez le nom du contact à supprimer: ");
    scanf("%s", nom);
<<<<<<< HEAD
    for (int i = 0; i < nb; i++) {
=======
    for (int i = 0; i < nb_C; i++) {
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
        if (strcmp(contacts[i].nom, nom) == 0) {
            char confirmation;
            printf("Êtes-vous sûr de vouloir supprimer le contact %s ? (o/n): ", nom);
            scanf(" %c", &confirmation);
            if (confirmation == 'o' || confirmation == 'O') {
<<<<<<< HEAD
                for (int j = i; j < nb - 1; j++) {
                    contacts[j] = contacts[j + 1];
                }
                nb--;
=======
                for (int j = i; j < nb_C - 1; j++) {
                    contacts[j] = contacts[j + 1];
                }
                nb_C--;
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
                printf("Contact supprime.\n");
            } else {
                printf("Suppression annulee.\n");
            }
            return;
        }
    }
    printf("Contact non trouve.\n");
}

void rechercher_contact_par_nom() {
    char nom[50];
    printf("Entrez le nom du contact à rechercher: ");
    scanf("%s", nom);
<<<<<<< HEAD
    for (int i = 0; i < nb; i++) {
=======
    for (int i = 0; i < nb_C; i++) {
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
        if (strcmp(contacts[i].nom, nom) == 0) {
            printf("Nom: %s, Telephone: %s, Email: %s\n", 
                   contacts[i].nom, 
                   contacts[i].telephone, 
                   contacts[i].email);
            return;
        }
    }
    printf("Contact non trouve.\n");
}

void rechercher_contact_par_id() {
    int id;
<<<<<<< HEAD
    printf("Entrez l'ID (index) du contact à rechercher (0 à %d): ", nb - 1);
    scanf("%d", &id);
    if (id >= 0 && id < nb) {
=======
    printf("Entrez l'ID (index) du contact à rechercher (0 à %d): ", nb_C - 1);
    scanf("%d", &id);
    if (id >= 0 && id < nb_C) {
>>>>>>> adfcb9ff17516886551dc9a9f56f6c35e7454d98
        printf("Nom: %s, Telephone: %s, Email: %s\n", 
               contacts[id].nom, 
               contacts[id].telephone, 
               contacts[id].email);
    } else {
        printf("ID non valide.\n");
    }
}

void menu_ajouter() {
    int choix;
    printf("\n--- Menu d'ajout ---\n");
    printf("1. Ajouter un contact (simple)\n");
    printf("2. Ajouter plusieurs contacts\n");
    printf("Choisissez une option: ");
    scanf("%d", &choix);
    switch (choix) {
        case 1: ajouter_contact_simple(); break;
        case 2: ajouter_contact_multiple(); break;
        default: printf("Choix invalide.\n");
    }
}

void menu_recherche() {
    int choix;
    printf("\n--- Menu de recherche ---\n");
    printf("1. Rechercher par nom\n");
    printf("2. Rechercher par ID\n");
    printf("Choisissez une option: ");
    scanf("%d", &choix);
    switch (choix) {
        case 1: rechercher_contact_par_nom(); break;
        case 2: rechercher_contact_par_id(); break;
        default: printf("Choix invalide.\n");
    }
}

int main() {
    initialize_contacts();
    int choix;
    do {
        printf("\n--- Système de Gestion de Contacts ---\n");
        printf("1. Ajouter un contact\n");
        printf("2. Modifier un contact\n");
        printf("3. Supprimer un contact\n");
        printf("4. Afficher tous les contacts\n");
        printf("5. Afficher statistiques\n");
        printf("6. Rechercher un contact\n");
        printf("0. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1: menu_ajouter(); break;
            case 2: modifier_contact(); break;
            case 3: supprimer_contact(); break;
            case 4: afficher_contacts(); break;
            case 5: afficher_statistiques(); break;
            case 6: menu_recherche(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 0);
    return 0;
}
