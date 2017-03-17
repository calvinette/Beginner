//
//  main.cpp


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    double moyenne(0.0);
    vector<double> notes;
    //lecture et cumul des notes
    double note_lue(-1.0);
    do
    {
        cout<<"Notes de l'étudiant"<<notes.size()+1<<" (0 pour finir )"<<endl;
        cin>>note_lue;
        if(note_lue >= 0.0)
        {
            //stock de la note du ième étudiant dans la ième case du tableau
            notes.push_back(note_lue);
            
            //maintient la somme à jour
            moyenne = moyenne + note_lue;
        }
        
    }while(note_lue >= 0.0);
    
    moyenne = moyenne /notes.size();
    
    //affichage des résultats
    cout<<"Moyenne de la classe = "<<moyenne <<endl;
    cout<<"Etudiant : note (écart à la moyenne )"<<endl;
    for(size_t i(0); i<notes.size(); ++i)
    {
        cout<<" "<<i+1<< ":" <<notes[i]<<"("<< notes[i] - moyenne <<" )"<<endl;
    }

    return 0;
}
