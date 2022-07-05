//
//  main.c
//  puissance4
//
//  Created by Jude Kabeya on 26/02/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// Constantes fixant le nombre max  de colonne/ligne
#define L 6
#define C 7




// Le plateau de type grille
typedef char plateau[L][C];
plateau grille;



void affichage_menu()
{
    
    printf("        WELCOME TO FOUR IN A ROW !! ");
    printf("\n\n\n");
    printf("\n1) Charge a game\n");
    printf("2) Save the game\n");
    printf("3) Replay a game \n");
    
  
    printf("4) quit\n\n");
    printf("-> ");
    
    fflush(stdout);
}

//Initialisation de la grille vide

void init_grille(plateau grille)

{
    int i,j;
    for (i=1; i<=L; i++){
        for(j=1;j<=C; j++){
        grille[i][j] = ' ';
        }
    }
}

//Affichage la grille
 void affiche_grille(plateau grille)
{
    int i,j; // entiers utilises pour la boucle

    printf("\n    1   2    3    4    5    6     7 \n");

    for (i=1; i<=L; i ++){ //parcours chaque ligne
        printf("%d |", i);
        
        for (j=1;j<=C; j ++) {//parcours chaque colonne
        printf(" %c | ", grille[i][j]); // pour printer les pipes pour créer la grille

        }
        printf("\n\n"); //saut de ligne
        }

}


int grille_pleine(plateau grille)


{
    //retourne 0 si la grille est vide ou 1 le cas inverse


    int col;
    int lgn;
    
    for (col = 0; col < C; ++col) //parcours de ma grille
        for (lgn = 0; lgn < L; ++lgn)
            if(grille[col][lgn]==' ')// Vérifie pendant ma boucle si les indexes de la liste correspondent à du 'vide', 0 --> non 1 --> oui
                return 0;
    
    return 1;
}


    
void ajoute_jeton( plateau grille, int joueur)


{

        int i,column;
        //Déclaration des variables locales
   
    

        if (grille_pleine(grille) == 1) {// fait appel a grille pleine pour determiner si le joueur peut placer un jeton sur la colonne, return 1 pleine, on affiche le msg suivant
            printf("\n grid is filled, game over ! \n");

        } else {
            printf("\n Please make a move. (1-7): ");//on demande à l'utilisateur de saisir un déplacement
            scanf("%d", &column);//on enregistre ce déplacement
        
            
            
            if ( column < 1 ||  column > C ){
                
                printf("Sorry! Invalid Move. Try Again \n");
                
                return;
            }
            
            
            
            for (i = L; i > 0 ; i --) {

                if (grille[i][column] == ' ') { // si la grille est vide alors :

                    if (joueur == 1) { //joueur 1 place le jeton O
                        grille[i][column] = 'O';
                        affiche_grille(grille);
                        return;


                    } else if( joueur == 2) { // joueur 2 place le jeton X
                        grille[i][column] = 'X';
                        affiche_grille(grille);
                        return;
                    }

                } else if (grille[1][column] != ' ') {  //grille remplie
                    printf("this column is filled, choose another \n");
                    return;

            }
        }
    }
}






void jeuFini(plateau grille){
    
  
    int i;
    int j ;
   
   
  //parcours de la grille
    for (i=0; i < C ;i++){
        for (j = 0; j< L; j ++){
            
            
            //  Vérification des jetons X, O, si ils sont égals aux prochaines cases, si 4 cases sont égaux le joueur X ou O gagne.

            
            //hozizontal win
        if ( grille[i][j] == 'X' && grille[i][j+1] == 'X' && grille[i][j+2] == 'X' && grille[i][j+3]== 'X'){
        printf("Player X wins");
            exit(0); // On quitte le programme, quand un joueur a gagner.
            
        } else if ( grille[i][j] == 'O' && grille[i][j+1] == 'O' && grille[i][j+2] == 'O' && grille[i][j+3]== 'O'){
                
                
        printf("Player O wins");
            exit(0);
            
        }
            
            // vertical win
             
            else if( grille[i][j] == 'O' && grille[i+1][j] == 'O' && grille[i+2][j] == 'O' && grille[i+3][j]== 'O'){
                printf("Player O wins");
                printf("\n\n");

                printf("Want to play again ? press 1");


                    exit(0);
            }
                
                // du joueur X
                else if (grille[i][j] == 'X' && grille[i+1][j] == 'X' && grille[i+2][j] == 'X' && grille[i+3][j]== 'X'){
                    
                printf("Player X wins");
                    printf("\n\n");
                   

                    exit(0);
                    
            }
            
        
            //diagonal win
               else  if(grille[i][j] =='X' && grille[i+1][j-1] == 'X' && grille[i+2][j-2] == 'X' && grille[i+3][j-3] == 'X'){
                printf("Player X wins");
            exit(0);
            
                  
                }
        else if(grille[i][j] == 'X' && grille[i-1][j+1] == 'X' &&grille[i-2][j+2] == 'X' && grille[i-3][j+3] == 'X' ){
            printf("Payer X wins");
            exit(0);
                }
            
            
        else  if(grille[i][j] =='O' && grille[i+1][j-1] == 'O' && grille[i+2][j-2] == 'O' && grille[i+3][j-3] == 'O'){
         printf("Player O wins");
     exit(0);
     
           
         }
            
        else if(grille[i][j] == 'O' && grille[i-1][j+1] == 'O' &&grille[i-2][j+2] == 'O' && grille[i-3][j+3] == 'O' ){
            printf("Payer O wins");
            exit(0);
            
                }
     
            
            
            }
        
    
        }
        
            
    }
  

    
    

//Fonction qui permet de sauvegarder sa partie
void sauvegardePartie(plateau grille, char nomfichier[]) {
    FILE *f;   //Creation d'un fichier qui contiendra la sauvegarde
    int i,j,overwrite;
    char choix;
    char path[50] = "saves/";
    char prenom[100], nom [100];
    int a ;
    //Declaration des variables locales

    overwrite = 0;   //Overwrite determine si le programme est autorise a reecrire par dessus un fichier de sauvegarde existant s'il y en a un

    strcat(path,nomfichier);

    if ((f = fopen((path),"r")) != NULL) {   //Si le programme tente d'ouvrir un fichier de sauvegarde en lecture et que le resultat n'est pas nul (donc qu'un fichier de sauvegarde existe deja)
        fclose(f);   //Fermeture du fichier
        
        printf("\nSouhaitez-vous ecraser la sauvegarde precedente ? o/n : \n");   //Ici, il demandera l'autorisation de reecrire par dessus le fichier existant
        do {
            scanf("%c",&choix);
        } while (choix != 'n' && choix != 'o');
        //Tant que l'utilisateur ne repondra pas 'o' ou 'n', le programme continuera

        if (choix == 'n') {
            overwrite = 0;   //Si l'utilisateur refuse, le programme ne pourra pas reecrire le fichier de sauvegarde et la partie ne sera pas sauvegardee
            printf("\nImpossible de sauvegarder la partie,\n");
        
        } else {
            overwrite = 1;   //Si l'utilisateur accepte, le programme pourra reecrire le fichier de sauvegarde et sauvegardera la partie
        }
    }
    
    if ((overwrite == 1) || (f = fopen((path),"r")) == NULL) {   //Si le programme a l'autorisation de reecrire le fichier de sauvegarde existant ou qu'il n'y en a tout simplement pas

        f = fopen((path),"w");   //Ouvre le fichier en ecriture

        for (i = 0; i < L; i ++) {   //Parcours des lignes

            for (j = 0; j < C; j ++) {   //Parcours des colonnes

                fprintf(f,"%c",grille[i][j]);   //Ecriture des valeurs des cases
            }
           
            
            printf("Donner votre nom, prenom et age "); // enregistre le nom et prénom de l'utilisateur
            scanf("%s%s%d", nom, prenom,&a);
            
            fprintf(f,"%s - %s - %d ", nom, prenom,a);
        
        //ecrit la grille dans le fichier, même procede que la fonction AfficheGrille mais dans un fichier
        
        } printf("\nLa partie a bien ete sauvegarde dans : %s \n",path);
    
    } fclose(f);   //Fermeture du fichier
}


//Fonction qui charge une partie depuis un fichier
int lecturePartie(plateau  grille, char nomfichier[]) {
    FILE *f;   //Pointeur vers le fichier qui contient la sauvegarde
    int i,j;
    char c;
    char path[50] = "sauvegarde/";
    //Declaration des variables locales

    strcat(path,nomfichier);

    f = fopen(path,"r");   //Ouverture du fichier en lecture
    
    if (f == NULL) {   //Si le programme renvoie un resultat nul, c'est que le fichier n'existe pas ou qu'il y a eu un souci durant l'ouverture de celui-ci
        return 1;
    } else {   //Si le programme arrive a lire le fichier
        
        for (i = 0; i < L; i ++) {

            for (j = 0; j < C; j ++) {
                c = fgetc(f);   //c contiendra un caractere du fichier de sauvegarde
                grille[i][j] = c; //Chaque caractere est place dans une case du tableau dans l'ordre de lecture
            }
        }
    } return 0;
}

  
    
    
//***********************************************************MAIN**********************************************************************
int main()
    
{

        int joueur;
        char nomfichier[100];
        int sortie=0; /* pour gerer la sortie de la boucle du menu : 0 donc faux par defaut */
        char choix; /* choix du menu saisi par l'utilisateur */
        affichage_menu();
        
        

   
        while (!sortie)
        {
           

            scanf(" %c",&choix); /* lecture du choix de l'utilisateur */
            switch (choix) /* test du choix */
            {
            /**************** CHOIX 1 ****************/
           
                case '1':
                    init_grille(grille);
                    grille_pleine(grille);
                    printf("          FOUR IN A ROW 🏆 ");
                    affiche_grille(grille);
                   // sauvegarde(grille);
                        
                    
                    

                    // boucle de jeu

                    while(
                          grille_pleine(grille)==0)
                        
                    {       jeuFini(grille);
                            joueur=1;
                            if (joueur==1){ // tour du joueur 1 qui doit placer son jeton
                                    ajoute_jeton( grille, joueur);
                                    jeuFini(grille);

                                   
                                    joueur=2;
                                } else if (joueur==2){ // tour du joueur 2 qui doit placer son jeton
                                        ajoute_jeton( grille, joueur);
                                        jeuFini(grille);

                                    

                                    joueur=1; // et on reprend
                                                       
                        }
                            ajoute_jeton(grille, joueur);
      
                        }
                        
                    

                
            case '2': /* sauvegarder la partie */
                printf("Entrer le nom du fichier a sauvegarder : ");
                scanf("%s",nomfichier); // lecture du nom du fichier a utiliser pour la sauvegarde
                sauvegardePartie(grille, nomfichier); // tableaux et entiers passes par valeur
                break;
                    
            
                    
                case '3'://charge une partie
                    printf("Entrez le nom du fichier de la sauvegarde");
                    scanf("%s" ,nomfichier);
                    lecturePartie(grille, nomfichier);
                    break;
                    

                    
                    
            case '4': /* quitter */
                do // attente de confirmation pour quitter
                {
                    printf("Are you sure? (y/n) ");
                    scanf(" %c",&choix);
                }
                while ((choix!='y') && (choix!='n')); // tant que la reponse n'est ni 'o' ni 'n'

                if (choix=='y') // si la reponse est 'o' alors la variable sortie est mise a 1 afin de sortir de la boucle du menu
                    sortie=1;

                break;

            /*************** AUTRE CHOIX ***************/
            default : /* erreur de saisie */
                printf("Error : tapez 1 a 8.\n");
            }
      
            
        }

        return(1); // sortie du programme en retournant 1
    }





