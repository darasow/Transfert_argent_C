#ifndef TRANSFERT_H_INCLUDED
#define TRANSFERT_H_INCLUDED
#include <cstring>
#include "dateoperation.h"
using namespace std;
struct Transfert
                {
                    string code;
                    string nom_expediteur;
                    string adresse_expediteur;
                    string nom_beneficiaire;
                    string adresse_beneficiaire;
                    int numero_carte_beneficiaire;
                    DateOperation date_expedition;
                    DateOperation date_annulation;
                    DateOperation date_retrait;
                    int montant_depose;
                    int montant_payable;
                    int commission;
                    bool retirer;
                    bool annuler;
                };


#endif // TRANSFERT_H_INCLUDED
