#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Visual Laser 10 New - 2022

class Scala
{
    //classe di una scala
    //la scala è una sequenza di note distanziate l'una dall'altra da un tono o da un semitono
    //la sequenza di toni o semitoni è in input dall'utente
    //la dominante della scala è in input dall'utente
    private:
        string defaultnote[12] =   { "Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "Sol", "Sol#", "La",  "La#", "Si"};
        string defaultpretty[12] = { "Do", "Reb", "Re", "Mib", "Mi", "Fa", "Solb","Sol", "Lab",  "La",  "Sib", "Si" };
        string note[8] = {""};

        int inc(int ton, string tono, int i)
        {
            if(tono[i] == 't')
                ton += 2;
            else if(tono[i] == 's')
                ton++;

            return ton % 12;
        }

        bool startsEqual(string a, string b)
        {
            int eq = 0;
            for(int i = 0; i < a.length(); i++)
            {
                if(a[i] == b[i])
                    eq++;
            }

            return (eq == a.length()-1);
        }
    public:
        void calcScala(string tono, int tonalita) //tono è la stringa di intervalli ttsttst; tonalità è la prima nota della scala: 0 -> Do, 1 -> Do#, 2 Re, ecc...
        {
            //tono = +2
            //semitono = +1
            //tonalita è l'indice della nota nell'array default, note[i]  = defaultnote[tonalita]
            for(int i=0; i< 8; i++)
            {
                note[i] = defaultnote[tonalita];

                if(i == 7) //cosicchè non calcoli la tonalità con la 9a nota, la quale non esiste
                    break;
                
                tonalita = inc(tonalita, tono, i); //incremento la tonalità di 2 se tono o 1 se semitono
            }
        }

        void prettyView()
        {
            //permette di sostituire le note in fila che iniziano con le stesse lettere: 
            /*
            * se la scala contiene -> Do Re Re#
            * questa diventerà     -> Do Re Mib
            * per maggiore leggibilità
            */
            for(int i=1; i<8; i++)
            {
                if(startsEqual(note[i], note[i-1]))
                {                    
                    auto it = find(defaultnote, defaultnote+12, note[i]);
                    note[i] = defaultpretty[distance(defaultnote, it)];
                }
            }
        }

        void printScala(char delimitatore)
        {
            for(int i=0; i<8; i++)
                cout << note[i] << delimitatore;
            cout << endl;
        }
};

string starter()
{
    cout << "Scrivi 7 intervalli (ttsttts):" << endl;
    string tonalita;
    getline(cin, tonalita);
    return tonalita;
}

void calc(string tono)
{
    Scala scala[12];
    for(int i = 0; i < 12; i++)
    {
        scala[i].calcScala(tono, i);
        scala[i].prettyView();
        scala[i].printScala('\t');
    }
}

int main()
{
    string tono = starter();
    calc(tono);
}