#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stdbool.h>
//couleur e C
#define c31 "\033[1;31m"
#define c32 "\033[1;32m"
#define c33 "\033[1;33m"
#define c34 "\033[1;34m"
#define c35 "\033[1;35m"
#define c0 "\033[0m" 
#define max 100
//definition de struct 
typedef struct{
    char Nom [max][500];
    char N_tel[max][20];
    char email[max][500];
}Contact;
void affichage_Menu(){ //fonction d'affichage
    printf("\tLes Menus proposés dans notre programme sont: \n\n");
    printf(c34"\t\t1. Ajouter un Contact\n");
    printf("\t\t2. Modifier un Contact\n");
    printf("\t\t3. Supprimer un Contact\n");
    printf("\t\t4. Afficher Tous les Contacts\n");
    printf("\t\t5. Rechercher un Contact\n\n"c0);

    
} 
bool isValidEmail(char email[]) {
    int atIndex = -1;
    int dotIndex = -1;
    int len = strlen(email);

    // Parcourir la chaîne pour trouver le '@' et le '.'
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            atIndex = i;
        } else if (email[i] == '.' && atIndex != -1) { // Chercher '.' après '@'
            dotIndex = i;
        }
    }

    // Vérifier les conditions de validité
    if (atIndex == -1 || dotIndex == -1) {  // '@' et '.' doivent être présents
        return false;
    }
    if (atIndex == 0 || dotIndex == atIndex + 1) {  // '@' ne doit pas être au début, et '.' ne doit pas être juste après '@'
        return false;
    }
    if (dotIndex == len - 1) {  // Il doit y avoir quelque chose après le '.'
        return false;
    }

    return true;
}
void choisir_nb_choix(int *choix) {
    printf("\tVeuillez entrer votre choix : ");
    while (scanf("%d", choix) != 1) {
        while (getchar() != '\n');  // Vider le buffer
        printf(c31"Erreur : Veuillez entrer un entier valide.\n"c0);
        printf("\tVeuillez entrer votre choix : ");
    }
    while (getchar() != '\n');  // Vider le buffer pour éviter les erreurs
}

void verifier_nb_saisir_0_ou_1() {
    char saisie[100];
    int nb_saisir, valide;

    printf("\tEst-ce que vous souhaitez ajouter un ou plusieurs contacts :\n");
    printf("\t\t0 : Pour ajouter un contact\n");
    printf("\t\t1 : Pour ajouter plusieurs contacts\n");

    while (1) {
        printf("\tDonnez-moi un numéro de votre choix (0 ou 1) : ");
        fgets(saisie, sizeof(saisie), stdin);  // Lecture de la saisie en tant que chaîne

        // Validation : s'assurer que la saisie est un nombre valide (0 ou 1)
        if (strlen(saisie) == 2 && (saisie[0] == '0' || saisie[0] == '1') && isdigit(saisie[0])) {
            nb_saisir = saisie[0] - '0';  // Convertir le caractère en entier
            break;
        } else {
            printf(c31"\n\n\t\tErreur : Veuillez entrer 0 ou 1.\033[0m\n\n");
        }
    }

    if (nb_saisir == 0) {
        printf("\tVous avez choisi d'ajouter un contact.\n");
    } else {
        do {
            printf("\tCombien de contacts voulez-vous ajouter ? ");
            valide = scanf("%d", &nb_saisir);

            while (getchar() != '\n');  // Vider le buffer pour éviter les problèmes de lecture

            if (valide != 1 || nb_saisir < 2) {
                printf(c31"\n\n\t\tErreur : Veuillez entrer un entier supérieur ou égal à 2.\033[0m\n\n");
            }
        } while (valide != 1 || nb_saisir < 2);

        printf("\tVous avez choisi d'ajouter %d contacts.\n", nb_saisir);
    }
}

int main(){
    
   printf(c31"\n\n\t\t\tMini-Projet : Système de Gestion de Contacts\n\n"c0);
   affichage_Menu();
   int choix ;
   e:  choisir_nb_choix(&choix); //demande de saisir le nombre de choix;
   
   switch(choix){
     case 1:{ //case 1 : Ajout d'un contact  
          
          printf(c33"\n\n\n\t\tBienvenue dans le menu d'ajout de contacts \n\n"c0);
          //demande de saisir 
          int nb_saisir;
          printf("Donner moi le nombre de ssaisr: "); scanf("%d",&nb_saisir);
          verifier_nb_saisir_0_ou_1(nb_saisir);
          break;
   }
   default: {
       printf("Erreur!!!!\n"); 
       goto e;
       break ;
   }
       
   
    return 0;
}
}

