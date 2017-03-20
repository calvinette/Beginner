//
//  main.cpp
//  La pratique du cpp
//
//  Copyright © 2017 calvinette. All rights reserved.
//


/*
 ----------------------------------------------------------------
 ----------------------- Tours de Hanoî -------------------------
 ----------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

constexpr unsigned int N(4);

//Un disque sera représenté par sa taille (rayon)
typedef unsigned int Disque;

//0 signifiant pas de disque
constexpr Disque PAS_DE_DISQUE(0);

//Un pilier est une pile de disques
typedef vector<Disque> Pilier;

//le jeu est constitué de trois piliers
typedef array<Pilier, 3> Jeu;

//Les fonctions
void affiche(char c, unsigned int n=1);
void affiche(const Disque& d);
void affiche(const Jeu& jeu);
void init(Jeu& jeu, unsigned int taille);
size_t sommet(const Pilier& p);
void deplace(Pilier& origine, Pilier& destination);
unsigned int autre(unsigned int p1, unsigned int p2);
void hanoi(unsigned int taille, unsigned int origine, unsigned int destination, Jeu& jeu);

int main(int argc, const char * argv[]) {
 
    Jeu monjeu;
    init(monjeu, N);
    affiche(monjeu);
    hanoi(N,0,2,monjeu);
    
    return 0;
}
/*
 ----------------------------------------------------------------
 ----------------------- Initialise le jeu ----------------------
 ----------------------------------------------------------------
 */

void init(Jeu& jeu, unsigned int taille)
{
    //crée un jeu vide
    for(auto& pilier:jeu)
    {
        pilier = Pilier(taille, PAS_DE_DISQUE);
    }
    
    //Remplit le premier pilier
    for(size_t i(0); (i < jeu[0].size()) and (i < taille); ++i)
    {
        jeu[0][i] = Disque(i+1);
    }
}
/*
 ----------------- Affiche n fois un caractère ------------------
 ----Entrée : le caractère à afficher et le nombre de fois-------
 */

void affiche(char c, unsigned int n)
{
    for(unsigned int i(0); i<n; ++i) cout<<c;
}
/*
 ----------------- Affiche un disque ------------------
 ----Entrée : le disque à afficher---------------------
 */

void affiche(const Disque& d)
{
    if(d == PAS_DE_DISQUE)
    {
        affiche(' ',N-1);
        affiche('|');
        affiche(' ',N);
    }else
    {
        affiche(' ',N - d);
        affiche('-', 2 * d - 1);
        affiche(' ',N - d + 1);
    }
}

/*
 ----------------------------------------------------------------
 ------------------------- Affiche le jeu -----------------------
 ----------------------------------------------------------------
 */

void affiche(const Jeu& jeu)
{
    for(size_t i(0); i < jeu[0].size(); ++i)
    {
        affiche(jeu[0][i]);
        affiche(jeu[1][i]);
        affiche(jeu[2][i]);
        cout<<endl;
    }
    
    //Le socle
    affiche('#', 6 * N - 1);
    cout<<endl<<endl;
}
/*
 ------------------------------------------------------
 Retourne l'indice du sommet d'une tour sur un pilier. 
 Retourne N si pas de tour sur ce pilier
 */
size_t sommet(const Pilier& p)
{
    size_t top;
    for(top= 0; (top<p.size() and p[top] == PAS_DE_DISQUE); ++top);
    return top;
}
/*
Déplace le disque du top d'une tour à un autre pilier.
 Vérifie que le mouvement est valide.
 Entrée : pilier d'où enlever le disque et le pilier destination
 */

void deplace(Pilier& origine, Pilier& destination)
{
    size_t top1(sommet(origine));
    
    //Si la tour d'origine existe bien
    if(top1 < origine.size())
    {
        size_t top2(sommet(destination));
        
        /* Pas autorisé :
         On essaye de mettre un disque plus gros origine[top1]
         sur un disque plus petit destination[top2]
        */
        if( (top2 < destination.size()) and (destination[top2] < origine[top1]))
        {
            cerr<< "ERREUR : on ne peut pas deplacer un disque de taille "
            <<origine[top1]<<"sur un disque de taille "
            <<destination[top2]<<" !"<<endl;
            return;
        }
        
        //effectue le  mouvement
        destination[top2 - 1] = origine[top1];
        origine[top1] = PAS_DE_DISQUE;
    }
}

/* Etant données deux numéros de pilier p1 et p2
 On retourne l'indice du 3eme pilier
*/
unsigned int autre(unsigned int p1, unsigned int p2)
{
    return 3 - p1 - p2;
}
/*
Déplace une tour d'un pilier à un autre.
 Vérifie que le mouvement est valide.
 Entrée : la taille de la tour, le pilier de départ, le pilier de destination
*/

void hanoi(unsigned int taille, unsigned int origine, unsigned int destination, Jeu& jeu)
{
    if(taille != 0)
    {
        const unsigned int auxiliaire(autre(origine, destination));
        hanoi(taille - 1, origine, auxiliaire, jeu);
        deplace(jeu[origine], jeu[destination]);
        affiche(jeu);
        hanoi(taille - 1, auxiliaire, destination, jeu);

    }
}
