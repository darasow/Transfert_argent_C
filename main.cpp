#include <iostream>
#include "fonctions.cpp"
using namespace std;

int main()
{

    couleur(BACKGROUND_GREEN);
   // presentation();
   // password();


    menu :menugeneral();
    char input[10], input2[10];
    int choix, choix2; cin>>input;
    choix = controleEntier(input);
    if(choix == 0)
    {
        gotoxy(25,28);cout<<"Veuillez fournir des Entiers ";
        gotoxy(25,29);system("pause");
        goto menu;
    }
    switch(choix)
    {
    case 1 :
             depot();
             goto menu;
    case 2 :
             afficheDepot();
             goto menu;
    case 3 :
             retirerDepot();
             goto menu;
    case 4 :
             comission();
             goto menu;
    case 5 :
             annulerDepot();
             goto menu;
    case 6 : supprimerDepot();
             goto menu;
    case 7 :
                menu2 : menuModification();
                cin>>input2;
                choix2 = controleEntier(input2);
                if(choix2 == 0)
                {
                    gotoxy(col2,16);cout<<"Veuillez fournir des Entiers ";
                    gotoxy(col2,17);system("pause");
                    goto menu2;
                }
                switch(choix2)
                {
                case 1 :
                        modifierNomExpediteur();
                        goto menu2;
                case 2 :
                        modifierAdresseExpediteur();
                        goto menu2;
                case 3 :
                        modifierNomBeneficiaire();
                        goto menu2;
                case 4 :
                        modifierAdresseBeneficiare();
                        goto menu2;
                case 5 :
                        modifierMontantDeposer();
                        goto menu2;
                case 6 :
                        modifierDateDepot();
                        goto menu2;
                case 7 : goto menu;
                default : goto menu2;
                }
    case 8 :
             situationDepot();
             goto menu;
    case 9 :
             situationRetrait();
             goto menu;
    case 10 :
             situationComissions();
             goto menu;
    case 11 :
             listeCodeDeposerAUneDate();
             goto menu;
    case 12 :
             listeCodeDeposerEntreDeuxDate();
             goto menu;
    case 13 :
             listeDeTousLesCodesDeposer();
             goto menu;
    case 14 :
             listeCodeRetirerAUneDate();
             goto menu;
    case 15 :
             listeCodeRetirerEntreDeuxDate();
             goto menu;
    case 16 :
             listeDeTousLesCodesRetirer();
             goto menu;
    case 17 :
             listeCodeAnnulerAUneDate();
             goto menu;
    case 18 :
             listeCodeAnnulerEntreDeuxDate();
             goto menu;
    case 19 :
             listeDeTousLesCodesAnnuler();
             goto menu;

    case 20 :
               quitter();
               break;
    default : goto menu;
    }

  return 0;
}
