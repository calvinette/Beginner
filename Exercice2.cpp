//
//  main.cpp
//  La pratique du cpp
//
//  Created by calvinette on 14/03/2017.
//  Copyright © 2017 calvinette. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

double factorielle(int k)
{
    int facto(0);
    if (k ==0) 	{ facto = 1;	}
    else 	{
        facto = factorielle(k-1) * k;
    }
    return facto;
}
double somme_partielle(double x, int N)
{
    double somme(0.0);
    for (int i=0; i<=N ; i++)
    {
        somme = pow((-1), i) * pow(x, 2 * i)/factorielle(2 * i) + somme;
    }
    return somme;
}

int main(int argc, const char * argv[]) {

    int N(0);
    double x(9.0);
    
/*    for(int i=1; i<10; i++)
    {
        cout<<"Factorielle de "<<i<<"= "<<factorielle(i)<<endl;
    }*/
    
    cout<< "Entrez la limite supérieure de la somme N = " <<endl;
    cin >> N;
    cout<< "Entrez le x du cosinus attendu = " <<endl;
    cin >> x;
    
    cout<< "Pour N = "<<N <<" cos ("<<x<<") = "<<somme_partielle(x, N)<<endl;

    return 0;
}
