#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <winuser.h>
#include <string.h>
#include <ctime>
#include "transfert.h"
using namespace std;
const int col = 32;
const int col2 = 25;


void couleur(int col)
{
    SetConsoleTitle("TRANSFERT D'ARGENT SECURISER");
    //HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(h,col);
    system("cls");
}
//fonction pour positionner le curseur
void gotoxy(int abs, int ord)
{
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD c;
      c.X = abs;
      c.Y = ord;
      SetConsoleCursorPosition(h,c);

}
int anneeEnCours()
{
    // date / heure actuelle basée sur le système actuel
   time_t actuel = time(0);
   tm *ltm = localtime(&actuel);
   unsigned int annee = (1900 + ltm->tm_year);
   return (annee);
}
int moisEnCours()
{
    // date / heure actuelle basée sur le système actuel
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);
    unsigned int mois = (1 + ltm->tm_mon);
   return (mois);
}
int jourEnCours()
{
    // date / heure actuelle basée sur le système actuel
   time_t actuel = time(0);
   tm *ltm = localtime(&actuel);
   unsigned int jours = (ltm->tm_mday );
   return (jours);
}
int heureEnCours()
{
    // date / heure actuelle basée sur le système actuel
   time_t actuel = time(0);
   tm *ltm = localtime(&actuel);
   unsigned int heures = (ltm->tm_hour );
   return (heures);
}
int minuteEnCours()
{
    // date / heure actuelle basée sur le système actuel
   time_t actuel = time(0);
   tm *ltm = localtime(&actuel);
   unsigned int minutes = (ltm->tm_min );
   return (minutes);
}
int secondeEnCours()
{
    // date / heure actuelle basée sur le système actuel
   time_t actuel = time(0);
   tm *ltm = localtime(&actuel);
   unsigned int secondes = (ltm->tm_sec );
   return (secondes);
}
int controleDateMois(char mmchar[])
{
    unsigned int cpt = 0;
     int n = atoi(mmchar);
     int val(n);
     while ( val != 0)
     {
         cpt++;
         val /= 10;
     }
     if(strlen(mmchar) != cpt) n = 0;
     return n;
}
int controleDateJour(char jjchar[], char mmchar[])
{
     unsigned int cpt = 0;
     int jj = atoi(jjchar);
     int val(jj);
     while ( val != 0)
     {
         cpt++;
         val /= 10;
     }
    if(strlen(jjchar) != cpt) jj = 0;
    switch(controleDateMois(mmchar))
    {
    case 2 : if(jj > 28 || jj <= 0) return 0; else return jj;  break;
    case 1 :
    case 3 :
    case 5 :
    case 7 :
    case 8 :
    case 10 :
    case 12 : if(jj > 31 || jj <= 0) return 0; else return jj; break;
    case 4 :
    case 6 :
    case 9 :
    case 11 : if(jj > 30 || jj <= 0) return 0; else return jj; break;
    default : return 0;
    }
}
int controleDateAnnee(char aaaachar[])
{


     int aa = atoi(aaaachar);

     unsigned int cpt = 0;
     int val(aa);
     while ( val != 0)
     {
         cpt++;
         val /= 10;
     }
     if(strlen(aaaachar) != cpt) aa = 0;

    if(aa == 0) return 0;
    else return aa;
}
//fonction de presentation
void calendrier()
{
   const int col_calendrier = 1;
   const int row_calendrier = 1;
   switch(moisEnCours())
              {
                case 1 :  gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Janvier "<<anneeEnCours();break;
                case 2 :  gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Fevrier "<<anneeEnCours();break;
                case 3 :  gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Mars "<<anneeEnCours();break;
                case 4 :  gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Avril "<<anneeEnCours();break;
                case 5 :  gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Mai "<<anneeEnCours();break;
                case 6 :  gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Juin "<<anneeEnCours();break;
                case 7 :  gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Juillet "<<anneeEnCours();break;
                case 8 :  gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Aout "<<anneeEnCours();break;
                case 9 :  gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Septembre "<<anneeEnCours();break;
                case 10 : gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Octobre "<<anneeEnCours();break;
                case 11 : gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Novembre "<<anneeEnCours();break;
                case 12 : gotoxy(col_calendrier,row_calendrier);cout<<jourEnCours()<<" Decembre "<<anneeEnCours();break;
              }

                gotoxy(col_calendrier,2);
                switch(minuteEnCours())
                {
                    case 0 : cout<<heureEnCours()<<"H:00mn"; break;
                    case 1 : cout<<heureEnCours()<<"H:01mn"; break;
                    case 2 : cout<<heureEnCours()<<"H:02mn"; break;
                    case 3 : cout<<heureEnCours()<<"H:03mn"; break;
                    case 4 : cout<<heureEnCours()<<"H:04mn"; break;
                    case 5 : cout<<heureEnCours()<<"H:05mn"; break;
                    case 6 : cout<<heureEnCours()<<"H:06mn"; break;
                    case 7 : cout<<heureEnCours()<<"H:07mn"; break;
                    case 8 : cout<<heureEnCours()<<"H:08mn"; break;
                    case 9 : cout<<heureEnCours()<<"H:09mn"; break;
                    default : cout<<heureEnCours()<<"H:"<<minuteEnCours()<<"mn";

                }


}
void nettoyer()
{
    system("cls");
    calendrier();
}
void presentation()
{
    char aut1[100] = {'1','-','D','I','A','L','L','O',' ','M','A','R','I','A','M','A','-','B','1','0','2','0',' ','1','3','M','I'};
    char aut2[100] = {'2','-','B','A','L','D','E',' ','A','L','P','H','A',' ','O','U','M','A','R','-','B','1','0','2','0',' ','1','6','G','I'};
    char aut3[100] = {'3','-','D','I','A','L','L','O',' ','O','U','M','O','U','E',' ','D','J','I','B','A','-','B','1','0','2','0',' ','1','0','M','I'};
    char aut4[100] = {'4','-','B','A','L','D','E',' ','I','B','R','A','H','I','M','A',' ','S','O','R','Y','-','B','1','0','2','0',' ','2','3','G','I'};
    char aut5[100] = {'5','-','K','A','D','I','J','A',' ','F','A','D','I','G','A','-','B','1','0','2','0',' ','6','G','I'};

    calendrier();
    Sleep(2000);
    gotoxy(col,7);
    cout << "BIENVENUE DANS NOTRE PROJET DE TRANSFERT D'ARGENT" << endl;
    Sleep(2000);
    gotoxy(col,9);
    cout << "EFFECTUER VOS DEPOTS ET RETRAITS EN TOUTE SECURITE" << endl;
    Sleep(2000);
    gotoxy(col,11);
    cout << "REALISER PAR : " << endl;

    Sleep(2000);
    gotoxy(col,13);
    cout<<aut1;
    Sleep(2000);
    gotoxy(col,14);
    cout<<aut2;
    Sleep(2000);
    gotoxy(col,15);
    cout<<aut3;
    Sleep(2000);
    gotoxy(col,16);
    cout<<aut4;
    Sleep(2000);
    gotoxy(col,17);
    cout<<aut5;
    Sleep(1000);
    gotoxy(col,20);
    system("pause");
}
//fonction password
void password()
{

    pass :
    nettoyer();
    string  login;
    gotoxy(col-5,10);cout<<"|======================CONNEXION=====================|"<<endl;
    gotoxy(col-5,11);cout<<"|  LOGIN    : |                                      |"<<endl;
    gotoxy(col-5,12);cout<<"|=============|======================================|"<<endl;
    gotoxy(col-5,13);cout<<"|  password : |                                      |"<<endl;
    gotoxy(col-5,14);cout<<"|====================================================|"<<endl;
    gotoxy(45,11);
    getline(cin,login);
    char passwd[9]; char ch;
   int i = 0;
   for(; i<8 ;)
   {
       gotoxy(45+i,13);ch = getch();
             if((int)ch == 13) break;
        if((int)ch != 8)
        {
           gotoxy(45+i,13);cout<<"*";
           passwd[i] = ch;
           i++;
        }
        else
            {
                if(i != 0)
                {
                   i--;
                   gotoxy(45+i,13);cout<<" ";
                }

            }

   }

   if(i < 8 || i> 8)
   {
      gotoxy(col,7); cout<<"Votre Mot de passe doit comporter 8 caractères";
      getchar();
      goto pass;
   }

   if(strcmpi(passwd,"Dmariama") == 0 && (login == "groupe4"))
   {
       gotoxy(30,16);cout<<"vous etes connecter"<<endl;
       gotoxy(30,17);system("pause");
       nettoyer();

   }
   else
    {
         gotoxy(40,16);cout<<"Login ou Mot de passe incorecte"<<endl;
         gotoxy(40,17);system("pause");
         goto pass;

    }
}
void menuModification()
{
    nettoyer();
    gotoxy(col2,5);cout<<"========== MODIFICATION DEPOT ===================="<<endl;
    gotoxy(col2,6);cout<<"== 1-Nom Expediteur                             =="<<endl;
    gotoxy(col2,7);cout<<"== 2-Adresse Expediteur                         =="<<endl;
    gotoxy(col2,8);cout<<"== 3-Nom Beneficiaire                           =="<<endl;
    gotoxy(col2,9);cout<<"== 4-Adresse Beneficiaire                       =="<<endl;
    gotoxy(col2,10);cout<<"== 5-Montant deposer                            =="<<endl;
    gotoxy(col2,11);cout<<"== 6-date d'Expedition                          =="<<endl;
    gotoxy(col2,12);cout<<"== 7-Retour                                     =="<<endl;
    gotoxy(col2,13);cout<<"=================================================="<<endl;
    gotoxy(col2,14);cout<<"votre choix : ";
}
//fonction menu general
void menugeneral()
{
    nettoyer();
    calendrier();
    gotoxy(col2,5);cout<<"================== MENU PRINCIPAL ================="<<endl;
    gotoxy(col2,6);cout<<"== 1-Enregistrer un depot                        =="<<endl;
    gotoxy(col2,7);cout<<"== 2-Afficher un depot                           =="<<endl;
    gotoxy(col2,8);cout<<"== 3-Retirer un depot                            =="<<endl;
    gotoxy(col2,9);cout<<"== 4-Enregistrer les comissions                  =="<<endl;
    gotoxy(col2,10);cout<<"== 5-Annuler un depot                            =="<<endl;
    gotoxy(col2,11);cout<<"== 6-Supprimer un depot                          =="<<endl;
    gotoxy(col2,12);cout<<"== 7-Modifier un depot                           =="<<endl;
    gotoxy(col2,13);cout<<"== 8-Situation des depots                        =="<<endl;
    gotoxy(col2,14);cout<<"== 9-Situation des retraits                      =="<<endl;
    gotoxy(col2,15);cout<<"== 10-Situation des Comissions                   =="<<endl;
    gotoxy(col2,16);cout<<"== 11-Liste des codes deposer a une date         =="<<endl;
    gotoxy(col2,17);cout<<"== 12-Liste des codes deposer entre deux dates   =="<<endl;
    gotoxy(col2,18);cout<<"== 13-Liste de tous les codes deposer            =="<<endl;
    gotoxy(col2,19);cout<<"== 14-Liste des codes retirer a une date donner  =="<<endl;
    gotoxy(col2,20);cout<<"== 15-Liste des codes retirer entre deux dates   =="<<endl;
    gotoxy(col2,21);cout<<"== 16-Liste de tous les codes retirer            =="<<endl;
    gotoxy(col2,22);cout<<"== 17-Liste des codes annuler a une date         =="<<endl;
    gotoxy(col2,23);cout<<"== 18-Liste des codes annuler entre deux dates   =="<<endl;
    gotoxy(col2,24);cout<<"== 19-Liste de tous les codes annuler            =="<<endl;
    gotoxy(col2,25);cout<<"== 20-Quitter                                    =="<<endl;
    gotoxy(col2,26);cout<<"==================================================="<<endl;
    gotoxy(25,27);cout<<"Votre choix : ";
}
int compareDate(DateOperation date_debut, DateOperation date_fin)
{
    if(date_debut.aaaa == date_fin.aaaa)
        if(date_debut.mm == date_fin.mm)
           if(date_debut.jj == date_fin.jj) return 0;
           else if(date_debut.jj > date_fin.jj) return 1;
                else return -1;
        else if(date_debut.mm > date_fin.mm) return 1;
             else return -1;
    else if(date_debut.aaaa > date_fin.aaaa) return 1;
         else return -1;
}
int controleEntier(char alphanum[])
 {   unsigned int cpt = 0;
     int n = atoi(alphanum);
     int val(n);
     while ( val != 0)
     {
         cpt++;
         val /= 10;
     }
     if(strlen(alphanum) != cpt) n = 0;
     return n;
 }
bool rechercheCode(string code)
{
    ifstream f("tranfert.txt"); bool res = false; Transfert T;
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
    {
        if(T.code == code)
        {
            res = true;
            break;
        }
    }
    f.close();
    return res;
}
int taille()
{
   ifstream f("tranfert.txt"); int cpt = 0; Transfert T;
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
    {
        cpt++;
    }
    f.close();
    return cpt;
}
 void depot()
{
    calendrier();
    Transfert T;
    nettoyer();
    if(taille()==500)
    {
       gotoxy(15,2); cout<<"Impossible d'effectuer un depot le nombre de depot est limiter a 500";
       gotoxy(15,3);system("pause");
    }
    else
    {
         saisi : gotoxy(col2,1);cout<<"donner le code du depot : ";
    cin>>T.code;
    if(rechercheCode(T.code))
    {
        gotoxy(col2,2); cout<<"Ce code existe deja ";
        gotoxy(col2,3); system("pause");
        nettoyer();
        goto saisi;
    }
    cin.ignore();
    gotoxy(col2,2);cout<<"donner le nom de l'expedieteur : ";
    cin>>T.nom_expediteur;
    gotoxy(col2,3);cout<<"donner l'adresse de l'expedieteur : ";
    cin>>T.adresse_expediteur;
    gotoxy(col2,4);cout<<"donner le nom du beneficiaire : ";
    cin>>T.nom_beneficiaire;
    gotoxy(col2,5);cout<<"donner l'adresse du beneficiaire : ";
    cin>>T.adresse_beneficiaire;
    s1 : gotoxy(col2,6);cout<<"donner le numero de la carte du beneficiaire  : ";
    char input [50];

    cin>>input;
    T.numero_carte_beneficiaire = controleEntier(input);
    if(T.numero_carte_beneficiaire == 0)
    {
        gotoxy(col2,7);cout<<"SVP veuillez saisir des entiers";
        gotoxy(col2+33,7); getch();
        nettoyer();
        goto s1;
    }

    T.date_expedition.jj = jourEnCours();
    T.date_expedition.mm = moisEnCours();
    T.date_expedition.aaaa = anneeEnCours();

    T.date_annulation.jj = 0;
    T.date_annulation.mm = 0;
    T.date_annulation.aaaa = 0;

    T.date_retrait.jj = 0;
    T.date_retrait.mm = 0;
    T.date_retrait.aaaa = 0;
    s5 : gotoxy(col2,11);cout<<"donner le montant deposer : ";
    cin>>input;
    T.montant_depose = controleEntier(input);
    if(T.montant_depose == 0)
    {
        gotoxy(col2,12);cout<<"SVP veuillez saisir des entiers";
        gotoxy(col2+33,12); getch();
        nettoyer();
        goto s5;
    }
    T.montant_payable = 0;
    T.commission = 0;
    T.retirer = false;
    T.annuler = false;
    ofstream fich("tranfert.txt",ios::app);
    fich<<T.code<<"\t"<<T.nom_expediteur<<"\t"<<T.adresse_expediteur
    <<"\t"<<T.nom_beneficiaire<<"\t"<<T.adresse_beneficiaire
    <<"\t"<<T.numero_carte_beneficiaire<<"\t"<<T.date_expedition.jj
    <<"\t"<<T.date_expedition.mm<<"\t"<<T.date_expedition.aaaa
    <<"\t"<<T.date_annulation.jj<<"\t"<<T.date_annulation.mm<<"\t"<<T.date_annulation.aaaa
    <<"\t"<<T.date_retrait.jj<<"\t"<<T.date_retrait.mm<<"\t"<<T.date_retrait.aaaa
    <<"\t"<<T.montant_depose<<"\t"<<T.montant_payable<<"\t"<<T.commission<<"\t"
    <<T.retirer<<"\t"<<T.annuler<<endl;
    gotoxy(col2,12);cout<<"depot effectuer avec succes";
    gotoxy(col2,14);system("pause");

    fich.close();
    }

}
int afficheDepot()
{   calendrier();
    nettoyer(); Transfert T; bool trouver = false;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,1); cout<<"donner le code du depot a afficher : ";
    string code_depot;
    cin>>code_depot;

    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
    {
        if(T.code == code_depot)
        {
            trouver = true;
            gotoxy(col2,3);cout<<"Nom Expediteur : "<<T.nom_expediteur;
            gotoxy(col2,4);cout<<"Adresse Expediteur : "<<T.adresse_expediteur;
            gotoxy(col2,5);cout<<"Nom Beneficiaire : "<<T.nom_beneficiaire;
            gotoxy(col2,6);cout<<"Adresse beneficiaire : "<<T.adresse_beneficiaire;
            gotoxy(col2,7);cout<<"Montant Depot : "<<T.montant_depose<<" GNF";
            gotoxy(col2,8);cout<<"Date d'expedition : "<<T.date_expedition.jj<<"/"<<T.date_expedition.mm<<"/"<<T.date_expedition.aaaa;

            if(T.retirer)
            {
                gotoxy(col2,9);cout<<"Comission : "<<T.commission<<" GNF";
                gotoxy(col2,10);cout<<"Montant Payable : "<<T.montant_payable<<" GNF";
                gotoxy(col2,11);cout<<"Retirer : Oui";
            }
            else
            {
                if(T.commission > 0)
                {
                gotoxy(col2,9);cout<<"Comission : "<<T.commission<<" GNF";
                gotoxy(col2,10);cout<<"Montant Payable : "<<T.montant_payable<<" GNF";
                gotoxy(col2,11);cout<<"Retirer : Non";
                }
                else
                {
                gotoxy(col2,9);cout<<"Comission : #######";
                gotoxy(col2,10);cout<<"Montant Payable : ####### ";
                gotoxy(col2,11);cout<<"Retirer : Non";
                }

            }

            if(T.annuler)
            {
                gotoxy(col2,12);
                cout<<"Annuler : Oui ";
            }
            else
                {
                    gotoxy(col2,12);
                    cout<<"Annuler : Non ";
                }

            gotoxy(col2,13);system("pause");
            break;

        }
    }
    if(trouver == false)
    {
        gotoxy(col2,3);
        cout<<"Ce code ne correspond a aucun depot ! ";
        gotoxy(col2,4);system("pause");
    }

    f.close();
    return 1;
}
int comission()
{
    calendrier();
    nettoyer(); string code_depot; int comission; char com[10];
    Transfert tab[500]; Transfert T; int nb; int pos;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,2); cout<<"donner le code du depot : ";
    cin>>code_depot;
    if(rechercheCode(code_depot))
    {


                 nb = 0;
                while
                (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                 >>T.nom_beneficiaire>>T.adresse_beneficiaire
                 >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                 >>T.date_expedition.mm>>T.date_expedition.aaaa
                 >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                 >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                 >>T.montant_depose>>T.montant_payable>>T.commission
                 >>T.retirer>>T.annuler)
                 {
                     tab[nb] = T;
                     if(T.code == code_depot) pos = nb;
                     nb++;
                 }
                 f.close();
                 if(tab[pos].retirer)
                         {
                            gotoxy(col2,4);
                            cout<<"Ce depot a deja ete retirer le "<<tab[pos].date_retrait.jj
                            <<"/"<<tab[pos].date_retrait.mm<<"/"<<tab[pos].date_retrait.aaaa;
                            gotoxy(col2,5); system("pause");
                         }
                     else if(tab[pos].annuler)
                     {
                            gotoxy(col2,4);
                            cout<<"Ce depot a ete Annuler le "<<tab[pos].date_annulation.jj
                            <<"/"<<tab[pos].date_annulation.mm<<"/"<<tab[pos].date_annulation.aaaa;
                            gotoxy(col2,5); system("pause");
                     }
                 else if(tab[pos].commission > 0)
                 {
                            gotoxy(col2,4);
                            cout<<"La comission de ce depot est deja enregistrer ";
                            gotoxy(col2,5); system("pause");
                 }
                 else
                    {

                          co : gotoxy(col2,3); cout<<"donner le montant de la comission : ";
                          cin>>com;
                          comission = controleEntier(com);
                            if(comission == 0)
                            {
                                gotoxy(col2,4); cout<<"Svp veuillez saisir un entier : ";
                                gotoxy(col2,5);system("pause");
                                nettoyer();
                                goto co;
                            }
                             if(comission > tab[pos].montant_depose)
                             {
                                 gotoxy(col2,4);
                                 cout<<"le montant de la comission doit etre inferieur au montant deposer ";
                                 gotoxy(col2,5);system("pause");
                                 nettoyer();
                                 goto co;
                             }

                             else
                                {
                                    tab[pos].commission = comission;
                                    tab[pos].montant_payable = tab[pos].montant_depose - comission;
                                    gotoxy(col2,4);
                                    cout<<"Commission Enregistrer avec succès";
                                    gotoxy(col2,5);system("pause");
                                    nettoyer();
                                    f.close();
                                    ofstream f1("tranfert.txt");
                                    for(int i =0 ; i<nb ; i++)
                                     {
                                    f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                                    <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                                    <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                                    <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                                    <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                                    <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                                    <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                                    <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                                     }

                                }

                                }



    }
    else
        {
            gotoxy(col2,3); cout<<"Le Code ne correspond a aucun depot";
            gotoxy(col2,4);system("pause");
            nettoyer();

        }
        return 1;
}
int retirerDepot()
{
    calendrier();
    nettoyer(); Transfert T; Transfert tab[500]; int nb(0),pos;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,1); cout<<"donner le code du depot a retirer : ";
    string code_retrait;
    cin>>code_retrait;
    if (rechercheCode(code_retrait))
    {
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         tab[nb] = T;
         if(T.code == code_retrait) pos = nb;
         nb++;
     }
     f.close();
     if(tab[pos].commission == 0)
     {
        gotoxy(col2,2);
        cout<<"Veuillez enregistrer la comission du depot svp !";
        gotoxy(col2,4); system("pause");
     }
     else if(tab[pos].retirer)
             {
                gotoxy(col2,2);
                cout<<"Ce depot a deja ete retirer le "<<tab[pos].date_retrait.jj
                <<"/"<<tab[pos].date_retrait.mm<<"/"<<tab[pos].date_retrait.aaaa;
                gotoxy(col2,4); system("pause");
             }
         else if(tab[pos].annuler)
         {
                gotoxy(col2,2);
                cout<<"Ce depot a ete Annuler le "<<tab[pos].date_annulation.jj
                <<"/"<<tab[pos].date_annulation.mm<<"/"<<tab[pos].date_annulation.aaaa;
                gotoxy(col2,4); system("pause");
         }
         else
            {
                 tab[pos].date_retrait.jj = jourEnCours();
                 tab[pos].date_retrait.mm = moisEnCours();
                 tab[pos].date_retrait.aaaa = anneeEnCours();
                 tab[pos].retirer = true;
                 ofstream f1("tranfert.txt");
                 for(int i =0 ; i<nb ; i++)
                 {
                f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                 }

                gotoxy(col2,7);cout<<"Retrait efectuer avec succes !";
                gotoxy(col2,8);cout<<"Le montant correspondant est : "<<tab[pos].montant_payable<<" GNF";
                gotoxy(col2,10);system("pause");
            }
    }
    else
        {
            gotoxy(col2,2);cout<<"Le code saisi n'existe pas !";
            gotoxy(col2,4);system("pause");
        }
        return 1;
}
int annulerDepot()
{

    calendrier();
    nettoyer(); Transfert T; Transfert tab[500]; int nb(0),pos;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }

    gotoxy(col2,1); cout<<"donner le code du depot a annuler : ";
    string code_annuler;
    cin>>code_annuler;
    if (rechercheCode(code_annuler))
    {
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         tab[nb] = T;
         if(T.code == code_annuler) pos = nb;
         nb++;
     }
     f.close();
             if(tab[pos].retirer)
             {
                gotoxy(col2,2);
                cout<<"Ce depot a deja ete retirer le "<<tab[pos].date_retrait.jj
                <<"/"<<tab[pos].date_retrait.mm<<"/"<<tab[pos].date_retrait.aaaa<<" Impossible d'annuler ";;
                gotoxy(col2,4); system("pause");
             }
             else
             {
                 tab[pos].annuler = true;
                 tab[pos].commission = 0;
                 tab[pos].montant_payable = 0;
                 tab[pos].date_annulation.jj = jourEnCours();
                 tab[pos].date_annulation.mm = moisEnCours();
                 tab[pos].date_annulation.aaaa = anneeEnCours();
                 gotoxy(col2,6);
                 cout<<"Ce depot a ete annuler avec succes ! ";
                 gotoxy(col2,8);
                 system("pause");
                 ofstream f1("tranfert.txt");
                 for(int i =0 ; i<nb ; i++)
                 {
                f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                 }

             }
    }
    return 1;
}
int supprimerDepot()
{
    calendrier();
    nettoyer(); Transfert T; Transfert tab[500]; int nb(0),pos;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,1); cout<<"donner le code du depot a supprimer : ";
    string code_supprimer;
    cin>>code_supprimer;
    if (rechercheCode(code_supprimer))
    {

    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         tab[nb] = T;
         if(T.code == code_supprimer) pos = nb;
         nb++;
     }
     f.close();
     for ( int i = pos ; i < nb - 1; i++) tab[pos]  = tab[pos + 1];
     nb--;
                ofstream f1("tranfert.txt");
                 for(int i =0 ; i<nb ; i++)
                 {
                f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                 }
                 gotoxy(col2,2);
                 cout<<"Depot supprimer avec succes ! ";
                 gotoxy(col2,3); system("pause");


    }
    else
        {
                 gotoxy(col2,2);
                 cout<<"Le code ne correspond a aucun depot  ! ";
                 gotoxy(col2,3); system("pause");
        }
        return 1;
}
int modifierNomExpediteur()
{
    calendrier();
    nettoyer(); Transfert T; Transfert tab[500]; int nb(0),pos;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,1); cout<<"donner le code du depot a modifier : ";
    string code_modif;
    cin>>code_modif;
    if (rechercheCode(code_modif))
    {

    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         tab[nb] = T;
         if(T.code == code_modif) pos = nb;
         nb++;
     }
     f.close();
     if(tab[pos].retirer)
     {
         gotoxy(col2,2);
         cout<<"Impossible de modifier ce depot il a ete retirer ";
         gotoxy(col2,3); system("pause");
     }
     else if(tab[pos].annuler)
             {
                gotoxy(col2,2);
                cout<<"Impossible de modifier ce depot il a ete annuler ";
                gotoxy(col2,3); system("pause");
             }
             else
                {
                   gotoxy(col2,2); cout<<"Donner le nom de l'expediteur : ";
     cin>>T.nom_expediteur;
     tab[pos].nom_expediteur = T.nom_expediteur;
                 ofstream f1("tranfert.txt");
                 for(int i =0 ; i<nb ; i++)
                 {
                f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                 }
                 gotoxy(col2,3);
                 cout<<"Modification effectuer avec succes ! ";
                 gotoxy(col2,4); system("pause");
                }


}
else
    {
                 gotoxy(col2,2);
                 cout<<"Le code ne correspond a aucun depot ! ";
                 gotoxy(col2,4); system("pause");
    }
   return 1;

}
int modifierAdresseExpediteur()
{
    calendrier();
    nettoyer(); Transfert T; Transfert tab[500]; int nb(0),pos;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,1); cout<<"donner le code du depot a modifier : ";
    string code_modif;
    cin>>code_modif;
    if (rechercheCode(code_modif))
    {

    ifstream f("tranfert.txt");
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         tab[nb] = T;
         if(T.code == code_modif) pos = nb;
         nb++;
     }
     f.close();
     if(tab[pos].retirer)
     {
         gotoxy(col2,2);
         cout<<"Impossible de modifier ce depot il a ete retirer ";
         gotoxy(col2,3); system("pause");
     }
     else if(tab[pos].annuler)
             {
                gotoxy(col2,2);
                cout<<"Impossible de modifier ce depot il a ete annuler ";
                gotoxy(col2,3); system("pause");
             }
             else
                {
                   gotoxy(col2,2); cout<<"Donner l'adresse de l'expediteur : ";
     cin>>T.adresse_expediteur;
     tab[pos].adresse_expediteur = T.adresse_expediteur;
                 ofstream f1("tranfert.txt");
                 for(int i =0 ; i<nb ; i++)
                 {
                f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                 }
                 gotoxy(col2,3);
                 cout<<"Modification effectuer avec succes ! ";
                 gotoxy(col2,4); system("pause");
                }


}
else
    {
                 gotoxy(col2,2);
                 cout<<"Le code ne correspond a aucun depot ! ";
                 gotoxy(col2,4); system("pause");
    }
    return 1;
}
int modifierAdresseBeneficiare()
{
    calendrier();
    nettoyer(); Transfert T; Transfert tab[500]; int nb(0),pos;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,1); cout<<"donner le code du depot a modifier : ";
    string code_modif;
    cin>>code_modif;
    if (rechercheCode(code_modif))
    {

    ifstream f("tranfert.txt");
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         tab[nb] = T;
         if(T.code == code_modif) pos = nb;
         nb++;
     }
     f.close();
     if(tab[pos].retirer)
     {
         gotoxy(col2,2);
         cout<<"Impossible de modifier ce depot il a ete retirer ";
         gotoxy(col2,3); system("pause");
     }
     else if(tab[pos].annuler)
             {
                gotoxy(col2,2);
                cout<<"Impossible de modifier ce depot il a ete annuler ";
                gotoxy(col2,3); system("pause");
             }
             else
                {
                     gotoxy(col2,2); cout<<"Donner l'adresse du Beneficiare : ";
     cin>>T.adresse_beneficiaire;
     tab[pos].adresse_beneficiaire = T.adresse_beneficiaire;
                 ofstream f1("tranfert.txt");
                 for(int i =0 ; i<nb ; i++)
                 {
                f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                 }
                 gotoxy(col2,3);
                 cout<<"Modification effectuer avec succes ! ";
                 gotoxy(col2,4); system("pause");
                }


}
else
    {
                 gotoxy(col2,2);
                 cout<<"Le code ne correspond a aucun depot ! ";
                 gotoxy(col2,4); system("pause");
    }
    return 1;
}
int modifierMontantDeposer()
{
    calendrier();
    nettoyer(); Transfert T; Transfert tab[500]; int nb(0),pos;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,1); cout<<"donner le code du depot a modifier : ";
    string code_modif;
    cin>>code_modif;
    if (rechercheCode(code_modif))
    {

    ifstream f("tranfert.txt");
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         tab[nb] = T;
         if(T.code == code_modif) pos = nb;
         nb++;
     }
     f.close();
     if(tab[pos].retirer)
     {
         gotoxy(col2,2);
         cout<<"Impossible de modifier ce depot il a ete retirer ";
         gotoxy(col2,3); system("pause");
     }
     else if(tab[pos].annuler)
             {
                gotoxy(col2,2);
                cout<<"Impossible de modifier ce depot il a ete annuler ";
                gotoxy(col2,3); system("pause");
             }
             else
                {
                    char inputmnt[20];
                    label_mnt : gotoxy(col2,2); cout<<"Donner le montant deposer : ";
                    cin>>inputmnt;
                    T.montant_depose = controleEntier(inputmnt);
                    if(T.montant_depose == 0)
                    {
                     gotoxy(col2,3);cout<<"SVP veuillez saisir des entiers";
                     gotoxy(col2,4);getch();
                     nettoyer();
                     goto label_mnt;
                    }

                    tab[pos].montant_depose = T.montant_depose;
                    if(tab[pos].commission > 0)
                    {
                        tab[pos].montant_payable = tab[pos].montant_depose - tab[pos].commission;
                    }
                    ofstream f1("tranfert.txt");
                    for(int i =0 ; i<nb ; i++)
                      {
                        f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                        <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                        <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                        <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                        <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                        <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                        <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                        <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                      }
                    gotoxy(col2,3);
                    cout<<"Modification effectuer avec succes ! ";
                    gotoxy(col2,4); system("pause");
                }



}
else
    {
                 gotoxy(col2,2);
                 cout<<"Le code ne correspond a aucun depot ! ";
                 gotoxy(col2,4); system("pause");
    }
    return 1;
}
int modifierDateDepot()
{
    calendrier();
    nettoyer(); Transfert T; Transfert tab[500]; int nb(0),pos;
    DateOperation date_new;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,1); cout<<"donner le code du depot a modifier : ";
    string code_modif;
    cin>>code_modif;
    if (rechercheCode(code_modif))
    {

    ifstream f("tranfert.txt");
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         tab[nb] = T;
         if(T.code == code_modif) pos = nb;
         nb++;
     }
     f.close();
     if(tab[pos].retirer)
     {
         gotoxy(col2,2);
         cout<<"Impossible de modifier ce depot il a ete retirer ";
         gotoxy(col2,3); system("pause");
     }
     else if(tab[pos].annuler)
             {
                gotoxy(col2,2);
                cout<<"Impossible de modifier ce depot il a ete annuler ";
                gotoxy(col2,3); system("pause");
             }
             else
                {
     /* ***********************************  */
     char inputjj[10], inputmm[10], inputaa[10];
                gotoxy(col2,2);cout<<"donner la nouvelle date ";
                label_jj : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                date_new.jj = controleEntier(inputjj);
                if(date_new.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }
                label_mm : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                date_new.mm = atoi(inputmm);
                if(date_new.mm <= 0 || date_new.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mm;
                }
                if(date_new.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }

                 label_aa : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 date_new.aaaa = controleDateAnnee(inputaa);

                    if(date_new.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aa;
                    }
                    DateOperation date_encours;
                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();

                    if(compareDate(date_encours,date_new) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une modification dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jj;
                    }

        }

     /* *************************************** */
                 tab[pos].date_expedition = date_new;
                 ofstream f1("tranfert.txt");
                 for(int i =0 ; i<nb ; i++)
                 {
                f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                 }
                 gotoxy(col2,6);
                 cout<<"Modification effectuer avec succes ! ";
                 gotoxy(col2,7); system("pause");
                }
else
    {
                 gotoxy(col2,2);
                 cout<<"Le code ne correspond a aucun depot ! ";
                 gotoxy(col2,4); system("pause");
    }
    return 1;
}
int modifierNomBeneficiaire()
{
    calendrier();
    nettoyer(); Transfert T; Transfert tab[500]; int nb(0),pos;
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    gotoxy(col2,1); cout<<"donner le code du depot a modifier : ";
    string code_modif;
    cin>>code_modif;
    if (rechercheCode(code_modif))
    {

    ifstream f("tranfert.txt");
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         tab[nb] = T;
         if(T.code == code_modif) pos = nb;
         nb++;
     }
     f.close();
     if(tab[pos].retirer)
     {
         gotoxy(col2,2);
         cout<<"Impossible de modifier ce depot il a ete retirer ";
         gotoxy(col2,3); system("pause");
     }
     else if(tab[pos].annuler)
             {
                gotoxy(col2,2);
                cout<<"Impossible de modifier ce depot il a ete annuler ";
                gotoxy(col2,3); system("pause");
             }
             else
                {
                   gotoxy(col2,2); cout<<"Donner le nom du beneficiaire : ";
     cin>>T.nom_beneficiaire;
     tab[pos].nom_beneficiaire = T.nom_beneficiaire;
                 ofstream f1("tranfert.txt");
                 for(int i =0 ; i<nb ; i++)
                 {
                f1<<tab[i].code<<"\t"<<tab[i].nom_expediteur<<"\t"<<tab[i].adresse_expediteur
                <<"\t"<<tab[i].nom_beneficiaire<<"\t"<<tab[i].adresse_beneficiaire
                <<"\t"<<tab[i].numero_carte_beneficiaire<<"\t"<<tab[i].date_expedition.jj
                <<"\t"<<tab[i].date_expedition.mm<<"\t"<<tab[i].date_expedition.aaaa
                <<"\t"<<tab[i].date_annulation.jj<<"\t"<<tab[i].date_annulation.mm<<"\t"<<tab[i].date_annulation.aaaa
                <<"\t"<<tab[i].date_retrait.jj<<"\t"<<tab[i].date_retrait.mm<<"\t"<<tab[i].date_retrait.aaaa
                <<"\t"<<tab[i].montant_depose<<"\t"<<tab[i].montant_payable<<"\t"<<tab[i].commission<<"\t"
                <<tab[i].retirer<<"\t"<<tab[i].annuler<<endl;
                 }
                 gotoxy(col2,3);
                 cout<<"Modification effectuer avec succes ! ";
                 gotoxy(col2,4); system("pause");
                }


}
else
    {
                 gotoxy(col2,2);
                 cout<<"Le code ne correspond a aucun depot ! ";
                 gotoxy(col2,4); system("pause");
    }
    return 1;
}
int situationDepot()
{
    calendrier();
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }

     Transfert T; long long mnt(0); int cpt(0);
    long long mnttotal(0); int cpttotal(0);
    long long mntretirer(0); int cptretirer(0);
    long long mntannuler(0); int cptannuler(0);
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         if(T.retirer == false)
            {
               if(T.annuler == false)
                 {
                     mnt += T.montant_depose;
                     cpt++;
                 }
               else
                {
                     mntannuler += T.montant_depose;
                     cptannuler++;
                }
            }
            else
                {
                     mntretirer += T.montant_depose;
                     cptretirer++;
                }

        mnttotal += T.montant_depose;
        cpttotal++;

     }
     f.close();
     gotoxy(col2+5,2);cout<<"Nombre totale de tous les depots : "<<cpttotal;
     gotoxy(col2+5,3);cout<<"Montant totale de tous les depots : "<<mnttotal<<" GNF";
     gotoxy(col2+5,5);cout<<"Nombre de depots totale non retiter et non annuler : "<<cpt;
     gotoxy(col2+5,6);cout<<"Montant totale de depots non retiter et non annuler: "<<mnt<<" GNF";
     gotoxy(col2+5,8);cout<<"Nombre totale des depots annuler : "<<cptannuler;
     gotoxy(col2+5,9);cout<<"Montant totale des depots annuler : "<<mntannuler<<" GNF";
     gotoxy(col2+5,11);cout<<"Nombre totale des depots retirer : "<<cptretirer;
     gotoxy(col2+5,12);cout<<"Montant totale des depots retirer : "<<mntretirer<<" GNF";
     gotoxy(col2+5,14);system("pause");
     return 1;
}
int situationComissions()
{
    calendrier();
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    Transfert T; long long mnt(0); int cpt(0);

    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         if(T.commission > 0)
            {
                cpt++;
                mnt += T.commission;
            }


     }
     f.close();
     gotoxy(col2+5,2);cout<<"Nombre totale des comissions : "<<cpt;
     gotoxy(col2+5,3);cout<<"Montant totale de toute les comissions : "<<mnt<<" GNF";
     gotoxy(col2+5,5);system("pause");
     return 1;
}
int situationRetrait()
{
    calendrier();
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }

    Transfert T; long long mnt(0); int cpt(0);

    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         if(T.retirer)
            {
                cpt++;
                mnt += T.montant_payable;
            }


     }
     f.close();
     gotoxy(col2+5,2);cout<<"Nombre totale des retraits : "<<cpt;
     gotoxy(col2+5,3);cout<<"Montant totale de tous les retraits : "<<mnt<<" GNF";
     gotoxy(col2+5,5);system("pause");
      return 1;
}
int listeCodeDeposerEntreDeuxDate()
{
    calendrier();
    DateOperation date_debut,date_fin; int ligne(2); int num(1);
    DateOperation date_encours;
    bool trouve = false;
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }

    /* ******* date debut ******************** */
    char inputjj[10], inputmm[10], inputaa[10];
                gotoxy(col2,2);cout<<"donner la date de debut";
                label_jj : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                date_debut.jj = controleEntier(inputjj);
                if(date_debut.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }
                label_mm : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                date_debut.mm = controleDateMois(inputmm);
                if(date_debut.mm <= 0 || date_debut.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mm;
                }
                if(date_debut.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }

                 label_aa : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 date_debut.aaaa = controleDateAnnee(inputaa);

                    if(date_debut.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aa;
                    }

                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();

                    if(compareDate(date_encours,date_debut) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une recherche dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jj;
                    }

    /* ***********date final ************** */

                nettoyer();
                gotoxy(col2,2);cout<<"donner la date finale";
                label_jjf : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                date_fin.jj = controleEntier(inputjj);
                if(date_fin.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jjf;
                }
                label_mmf : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                date_fin.mm = controleDateMois(inputmm);
                if(date_fin.mm <= 0 || date_fin.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mmf;
                }
                if(date_fin.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jjf;
                }

                 label_aaf : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 date_fin.aaaa = controleDateAnnee(inputaa);

                    if(date_fin.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aaf;
                    }

                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();

                    if(compareDate(date_encours,date_fin) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une recherche dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jjf;
                    }



    if(compareDate(date_debut,date_fin)== 0)
    {
        gotoxy(col2,11);cout<<"vous avez saisie la meme date aller a l'option 11 du menu";
        gotoxy(col2,13);system("pause");
    }
    else if(compareDate(date_debut,date_fin) > 0)
            {
               gotoxy(col2,11);cout<<"La date de debut ne doit pas etre superieur a la date finale";
               gotoxy(col2,13);system("pause");
            }
             else
             {
                if(date_debut.aaaa == date_fin.aaaa)

                  {
                      if(date_debut.mm == date_fin.mm)
                    {
                         Transfert T;
                        nettoyer();
                        while
                        (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                         >>T.nom_beneficiaire>>T.adresse_beneficiaire
                         >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                         >>T.date_expedition.mm>>T.date_expedition.aaaa
                         >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                         >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                         >>T.montant_depose>>T.montant_payable>>T.commission
                         >>T.retirer>>T.annuler)
                         {
                             if(T.retirer == false)
                             if(T.annuler == false)
                             if((T.date_expedition.jj >= date_debut.jj) && (T.date_expedition.jj <= date_fin.jj))
                                {
                                    trouve = true;
                                    gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                                    gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                                    gotoxy(col2,ligne++);cout<<"---------------------------------------";
                                }
                         }
                         f.close();
                    }
                    else
                        {
                          Transfert T;
                           nettoyer();
                           while
                           (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                           >>T.nom_beneficiaire>>T.adresse_beneficiaire
                           >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                           >>T.date_expedition.mm>>T.date_expedition.aaaa
                           >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                           >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                           >>T.montant_depose>>T.montant_payable>>T.commission
                           >>T.retirer>>T.annuler)
                           {
                             if(T.retirer == false)
                             if(T.annuler == false)
                             if((T.date_expedition.mm >= date_debut.mm) && (T.date_expedition.mm <= date_fin.mm))
                                {
                                    trouve = true;
                                    gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                                    gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                                    gotoxy(col2,ligne++);cout<<"---------------------------------------";
                                }
                           }
                           f.close();
                        }
                  }
                  else
                  {
                    Transfert T;
                           nettoyer();
                           while
                           (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                           >>T.nom_beneficiaire>>T.adresse_beneficiaire
                           >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                           >>T.date_expedition.mm>>T.date_expedition.aaaa
                           >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                           >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                           >>T.montant_depose>>T.montant_payable>>T.commission
                           >>T.retirer>>T.annuler)
                           {
                             if(T.retirer == false)
                             if(T.annuler == false)
                             if((T.date_expedition.aaaa >= date_debut.aaaa) && (T.date_expedition.aaaa <= date_fin.aaaa))
                                {
                                    trouve = true;
                                    gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                                    gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                                    gotoxy(col2,ligne++);cout<<"---------------------------------------";
                                }
                           }
                           f.close();
                  }
                }
                if(trouve == false)
                {
                    nettoyer();
                    gotoxy(col2,1);cout<<"Aucune depot n'a ete effectuer entre le "<<date_debut.jj
                    <<"/"<<date_debut.mm<<"/"<<date_debut.aaaa<<" et le "
                    <<date_fin.jj<<"/"<<date_fin.mm<<"/"<<date_fin.aaaa;
                }
                gotoxy(col2,ligne++);system("pause");
                return 1;

}
int listeCodeDeposerAUneDate()
{
    calendrier();
    DateOperation dte; int ligne(2); int num(1); bool trouve = false;
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    char inputjj[10], inputmm[10], inputaa[10];
                gotoxy(col2,2);cout<<"donner la date";
                label_jj : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                dte.jj = controleEntier(inputjj);
                if(dte.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }
                label_mm : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                dte.mm = controleDateMois(inputmm);
                if(dte.mm <= 0 || dte.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mm;
                }
                if(dte.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }

                 label_aa : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 dte.aaaa = controleDateAnnee(inputaa);

                    if(dte.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aa;
                    }
                    DateOperation date_encours;
                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();
                    if(compareDate(date_encours,dte) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une recherche dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jj;
                    }



    Transfert T;
    nettoyer();
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         if(T.retirer == false)
         if(T.annuler == false)
         if((T.date_expedition.jj == dte.jj) && (T.date_expedition.mm == dte.mm) && (T.date_expedition.aaaa == dte.aaaa))
            {
                trouve = true;
                gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                gotoxy(col2,ligne++);cout<<"---------------------------------------";
            }


     }
     if(trouve == false)
                {
                    nettoyer();
                    gotoxy(col2,1);cout<<"Aucune depot n'a ete effectuer entre le "<<dte.jj
                    <<"/"<<dte.mm<<"/"<<dte.aaaa;
                }
     f.close();
     gotoxy(col2,ligne);system("pause");
     return 1;

}
int listeDeTousLesCodesDeposer()
{
    calendrier();
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    Transfert T; int ligne(2), num(1);
    bool trouve = false;
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         if(T.retirer == false)
            if(T.annuler == false)
            {
                trouve = true;
                gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                gotoxy(col2,ligne++);cout<<"---------------------------------------";
            }


     }
     if(trouve == false)
                {
                    nettoyer();
                    gotoxy(col2,1);cout<<"Aucune depot enregistrer";

                }
     gotoxy(col2,ligne++);system("pause");
     f.close();
     return 1;
}
int listeCodeRetirerAUneDate()
{
    calendrier();
    DateOperation dte; int ligne(2); int num(1); bool trouve = false;
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }

    char inputjj[10], inputmm[10], inputaa[10];
                gotoxy(col2,2);cout<<"donner la date";
                label_jj : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                dte.jj = controleEntier(inputjj);
                if(dte.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }
                label_mm : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                dte.mm = controleDateMois(inputmm);
                if(dte.mm <= 0 || dte.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mm;
                }
                if(dte.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }

                 label_aa : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 dte.aaaa = controleDateAnnee(inputaa);

                    if(dte.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aa;
                    }
                    DateOperation date_encours;
                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();
                    if(compareDate(date_encours,dte) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une recherche dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jj;
                    }



    Transfert T;
    nettoyer();
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {   if(T.retirer)
         if((T.date_expedition.jj == dte.jj) && (T.date_expedition.mm == dte.mm) && (T.date_expedition.aaaa == dte.aaaa))
            {
                trouve = true;
                gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                gotoxy(col2,ligne++);cout<<"---------------------------------------";
            }


     }
     f.close();
     if(trouve == false)
                {
                    nettoyer();
                    gotoxy(col2,1);cout<<"Aucune depot n'a ete retirer le "<<dte.jj
                    <<"/"<<dte.mm<<"/"<<dte.aaaa;
                }
     gotoxy(col2,ligne);system("pause");
     return 1;
}
int listeCodeRetirerEntreDeuxDate()
{
    calendrier();
    DateOperation date_debut,date_fin; int ligne(2); int num(1);
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    bool trouve = false;
    /* ******* date debut ******************** */
    char inputjj[10], inputmm[10], inputaa[10];
                gotoxy(col2,2);cout<<"donner la date de debut";
                label_jj : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                date_debut.jj = controleEntier(inputjj);
                if(date_debut.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }
                label_mm : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                date_debut.mm = controleDateMois(inputmm);
                if(date_debut.mm <= 0 || date_debut.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mm;
                }
                if(date_debut.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }

                 label_aa : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 date_debut.aaaa = controleDateAnnee(inputaa);

                    if(date_debut.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aa;
                    }
                    DateOperation date_encours;
                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();
                    if(compareDate(date_encours,date_debut) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une recherche dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jj;
                    }

    /* ***********date final ************** */

                nettoyer();
                gotoxy(col2,2);cout<<"donner la date finale";
                label_jjf : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                date_fin.jj = controleEntier(inputjj);
                if(date_fin.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jjf;
                }
                label_mmf : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                date_fin.mm = controleDateMois(inputmm);
                if(date_fin.mm <= 0 || date_fin.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mmf;
                }
                if(date_fin.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jjf;
                }

                 label_aaf : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 date_fin.aaaa = controleDateAnnee(inputaa);

                    if(date_fin.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aaf;
                    }
                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();
                    if(compareDate(date_encours,date_fin) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une recherche dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jj;
                    }



    if(compareDate(date_debut,date_fin)== 0)
    {
        gotoxy(col2,11);cout<<"vous avez saisie la meme date aller a l'option 11 du menu";
        gotoxy(col2,13);system("pause");
    }
    else if(compareDate(date_debut,date_fin) > 0)
            {
               gotoxy(col2,11);cout<<"La date de debut ne doit pas etre superieur a la date finale";
               gotoxy(col2,13);system("pause");
            }
             else
             {
                if(date_debut.aaaa == date_fin.aaaa)

                  {
                      if(date_debut.mm == date_fin.mm)
                    {
                         Transfert T;
                        nettoyer();
                        while
                        (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                         >>T.nom_beneficiaire>>T.adresse_beneficiaire
                         >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                         >>T.date_expedition.mm>>T.date_expedition.aaaa
                         >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                         >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                         >>T.montant_depose>>T.montant_payable>>T.commission
                         >>T.retirer>>T.annuler)
                         {
                             if(T.retirer)
                             if((T.date_expedition.jj >= date_debut.jj) && (T.date_expedition.jj <= date_fin.jj))
                                {
                                    trouve = true;
                                    gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                                    gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                                    gotoxy(col2,ligne++);cout<<"---------------------------------------";
                                }
                         }
                         f.close();
                    }
                    else
                        {
                            Transfert T;
                           nettoyer();
                           while
                           (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                           >>T.nom_beneficiaire>>T.adresse_beneficiaire
                           >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                           >>T.date_expedition.mm>>T.date_expedition.aaaa
                           >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                           >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                           >>T.montant_depose>>T.montant_payable>>T.commission
                           >>T.retirer>>T.annuler)
                           {
                             if(T.retirer)
                             if((T.date_expedition.mm >= date_debut.mm) && (T.date_expedition.mm <= date_fin.mm))
                                {
                                    trouve = true;
                                    gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                                    gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                                    gotoxy(col2,ligne++);cout<<"---------------------------------------";
                                }
                           }
                           f.close();
                        }
                  }
                  else
                  {
                           Transfert T;
                           nettoyer();
                           while
                           (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                           >>T.nom_beneficiaire>>T.adresse_beneficiaire
                           >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                           >>T.date_expedition.mm>>T.date_expedition.aaaa
                           >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                           >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                           >>T.montant_depose>>T.montant_payable>>T.commission
                           >>T.retirer>>T.annuler)
                           {
                             if(T.retirer)
                             if((T.date_expedition.aaaa >= date_debut.aaaa) && (T.date_expedition.aaaa <= date_fin.aaaa))
                                {
                                    trouve = true;
                                    gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                                    gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                                    gotoxy(col2,ligne++);cout<<"---------------------------------------";
                                }
                           }
                           f.close();
                  }
                }
                if(trouve == false)
                {
                    nettoyer();
                    gotoxy(col2,1);cout<<"Aucune depot n'a ete effectuer entre le "<<date_debut.jj
                    <<"/"<<date_debut.mm<<"/"<<date_debut.aaaa<<" et le "
                    <<date_fin.jj<<"/"<<date_fin.mm<<"/"<<date_fin.aaaa;
                }
                gotoxy(col2,ligne++);system("pause");
                return 1;

}
int listeDeTousLesCodesRetirer()
{
    calendrier();
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }

    Transfert T; int ligne(2), num(1);
    bool trouve = false;
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         if(T.retirer)
            {
                trouve = true;
                gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                gotoxy(col2,ligne++);cout<<"---------------------------------------";
            }


     }
     if(trouve == false)
                {
                    nettoyer();
                    gotoxy(col2,1);cout<<"Aucune Retrait Effectuer";

                }
     gotoxy(col2,ligne++);system("pause");
     f.close();
     return 1;
}
int listeCodeAnnulerAUneDate()
{
    calendrier();
    DateOperation dte; int ligne(2); int num(1); bool trouve = false;
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    char inputjj[10], inputmm[10], inputaa[10];
                gotoxy(col2,2);cout<<"donner la date";
                label_jj : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                dte.jj = controleEntier(inputjj);
                if(dte.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }
                label_mm : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                dte.mm = controleDateMois(inputmm);
                if(dte.mm <= 0 || dte.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mm;
                }
                if(dte.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }

                 label_aa : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 dte.aaaa = controleDateAnnee(inputaa);

                    if(dte.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aa;
                    }
                    DateOperation date_encours;
                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();
                    if(compareDate(date_encours,dte) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une recherche dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jj;
                    }



     Transfert T;
    nettoyer();
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {   if(T.annuler)
         if((T.date_expedition.jj == dte.jj) && (T.date_expedition.mm == dte.mm) && (T.date_expedition.aaaa == dte.aaaa))
            {
                trouve = true;
                gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                gotoxy(col2,ligne++);cout<<"---------------------------------------";
            }


     }
     f.close();
     if(trouve == false)
                {
                    nettoyer();
                    gotoxy(col2,1);cout<<"Aucune depot n'a ete retirer le "<<dte.jj
                    <<"/"<<dte.mm<<"/"<<dte.aaaa;
                }
     gotoxy(col2,ligne);system("pause");
     return 1;
}
int listeCodeAnnulerEntreDeuxDate()
{
    calendrier();
    DateOperation date_debut,date_fin; int ligne(2); int num(1);
    bool trouve = false;
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    /* ******* date debut ******************** */
    char inputjj[10], inputmm[10], inputaa[10];
                gotoxy(col2,2);cout<<"donner la date de debut";
                label_jj : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                date_debut.jj = controleEntier(inputjj);
                if(date_debut.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }
                label_mm : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                date_debut.mm = controleDateMois(inputmm);
                if(date_debut.mm <= 0 || date_debut.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mm;
                }
                if(date_debut.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jj;
                }

                 label_aa : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 date_debut.aaaa = controleDateAnnee(inputaa);

                    if(date_debut.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aa;
                    }
                    DateOperation date_encours;
                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();
                    if(compareDate(date_encours,date_debut) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une recherche dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jj;
                    }

    /* ***********date final ************** */

                nettoyer();
                gotoxy(col2,2);cout<<"donner la date finale";
                label_jjf : gotoxy(col2,3);cout<<"Jour : ";cin>>inputjj;
                date_fin.jj = controleEntier(inputjj);
                if(date_fin.jj == 0)
                {
                    gotoxy(col2,4);cout<<"Veuillez saisir un jour valide!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jjf;
                }
                label_mmf : gotoxy(col2,4);cout<<"Mois : ";cin>>inputmm;
                date_fin.mm = controleDateMois(inputmm);
                if(date_fin.mm <= 0 || date_fin.mm > 12)
                {
                    gotoxy(col2,5);cout<<"Veuillez saisir un mois valide!";
                    gotoxy(col2,6);getch();
                    nettoyer();
                    goto label_mmf;
                }
                if(date_fin.jj > controleDateJour(inputjj,inputmm))
                {
                    gotoxy(col2,4);cout<<"Le numero du jour ne correspond pas au mois!";
                    gotoxy(col2,4);getch();
                    nettoyer();
                    goto label_jjf;
                }

                 label_aaf : gotoxy(col2,5);cout<<"Annee : ";cin>>inputaa;
                 date_fin.aaaa = controleDateAnnee(inputaa);

                    if(date_fin.aaaa == 0)
                    {
                        gotoxy(col2,6);cout<<"SVP veuillez saisir une annee valide ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_aaf;
                    }
                    date_encours.jj = jourEnCours();
                    date_encours.mm = moisEnCours();
                    date_encours.aaaa = anneeEnCours();
                    if(compareDate(date_encours,date_fin) < 0)
                    {
                        gotoxy(col2,6);cout<<"Impossible de faire une recherche dans le futur ! ";
                        gotoxy(col2,7); getch();
                        nettoyer();
                        goto label_jj;
                    }



    if(compareDate(date_debut,date_fin)== 0)
    {
        gotoxy(col2,11);cout<<"vous avez saisie la meme date aller a l'option 11 du menu";
        gotoxy(col2,13);system("pause");
    }
    else if(compareDate(date_debut,date_fin) > 0)
            {
               gotoxy(col2,11);cout<<"La date de debut ne doit pas etre superieur a la date finale";
               gotoxy(col2,13);system("pause");
            }
             else
             {
                if(date_debut.aaaa == date_fin.aaaa)

                  {
                      if(date_debut.mm == date_fin.mm)
                    {
                         Transfert T;
                        nettoyer();
                        while
                        (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                         >>T.nom_beneficiaire>>T.adresse_beneficiaire
                         >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                         >>T.date_expedition.mm>>T.date_expedition.aaaa
                         >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                         >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                         >>T.montant_depose>>T.montant_payable>>T.commission
                         >>T.retirer>>T.annuler)
                         {
                             if(T.annuler)
                             if((T.date_expedition.jj >= date_debut.jj) && (T.date_expedition.jj <= date_fin.jj))
                                {
                                    trouve = true;
                                    gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                                    gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                                    gotoxy(col2,ligne++);cout<<"---------------------------------------";
                                }
                         }
                         f.close();
                    }
                    else
                        {
                            Transfert T;
                           nettoyer();
                           while
                           (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                           >>T.nom_beneficiaire>>T.adresse_beneficiaire
                           >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                           >>T.date_expedition.mm>>T.date_expedition.aaaa
                           >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                           >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                           >>T.montant_depose>>T.montant_payable>>T.commission
                           >>T.retirer>>T.annuler)
                           {
                             if(T.annuler)
                             if((T.date_expedition.mm >= date_debut.mm) && (T.date_expedition.mm <= date_fin.mm))
                                {
                                    trouve = true;
                                    gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                                    gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                                    gotoxy(col2,ligne++);cout<<"---------------------------------------";
                                }
                           }
                           f.close();
                        }
                  }
                  else
                  {
                     Transfert T;
                           nettoyer();
                           while
                           (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
                           >>T.nom_beneficiaire>>T.adresse_beneficiaire
                           >>T.numero_carte_beneficiaire>>T.date_expedition.jj
                           >>T.date_expedition.mm>>T.date_expedition.aaaa
                           >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
                           >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
                           >>T.montant_depose>>T.montant_payable>>T.commission
                           >>T.retirer>>T.annuler)
                           {
                             if(T.annuler)
                             if((T.date_expedition.aaaa >= date_debut.aaaa) && (T.date_expedition.aaaa <= date_fin.aaaa))
                                {
                                    trouve = true;
                                    gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                                    gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                                    gotoxy(col2,ligne++);cout<<"---------------------------------------";
                                }
                           }
                           f.close();
                  }
                }
                if(trouve == false)
                {
                    nettoyer();
                    gotoxy(col2,1);cout<<"Aucune depot n'a ete effectuer entre le "<<date_debut.jj
                    <<"/"<<date_debut.mm<<"/"<<date_debut.aaaa<<" et le "
                    <<date_fin.jj<<"/"<<date_fin.mm<<"/"<<date_fin.aaaa;
                }
                gotoxy(col2,ligne++);system("pause");
                return 1;

}
int listeDeTousLesCodesAnnuler()
{
    calendrier();
    nettoyer();
    ifstream f("tranfert.txt");
    if(!f)
    {
       gotoxy(col2,2); cout<<"Aucun depot n'est enregistrer ";
       gotoxy(col2,3);system("pause");
       return 0 ;
    }
    Transfert T; int ligne(2), num(1);
    bool trouve = false;
    while
    (f>>T.code>>T.nom_expediteur>>T.adresse_expediteur
     >>T.nom_beneficiaire>>T.adresse_beneficiaire
     >>T.numero_carte_beneficiaire>>T.date_expedition.jj
     >>T.date_expedition.mm>>T.date_expedition.aaaa
     >>T.date_annulation.jj>>T.date_annulation.mm>>T.date_annulation.aaaa
     >>T.date_retrait.jj>>T.date_retrait.mm>>T.date_retrait.aaaa
     >>T.montant_depose>>T.montant_payable>>T.commission
     >>T.retirer>>T.annuler)
     {
         if(T.annuler)
            {
                trouve = true;
                gotoxy(col2,ligne++);cout<<"Depot : "<<num++;
                gotoxy(col2,ligne++);cout<<"Code : "<<T.code;
                gotoxy(col2,ligne++);cout<<"---------------------------------------";
            }


     }
     if(trouve == false)
                {
                    nettoyer();
                    gotoxy(col2,1);cout<<"Aucune Depot n'a ete annuler";

                }
     gotoxy(col2,ligne++);system("pause");
     f.close();
     return 1;
}
void quitter()
{

               nettoyer();
               gotoxy(col2+5,10);
               cout<<"Merci pour l'utilisation de notre application ";
               gotoxy(col2+5,11);getch();
               nettoyer();
}
