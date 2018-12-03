
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <string>
#include <sstream>

#include <time.h>
/* time */
#include<exception>

using namespace std;

class BrodoviMatrica
{
private:
    int matrica[20][20]= {};
    int ukupnoVrstaBrodova;
    int brojRedova;
    int brojKolona;


public:
    BrodoviMatrica( int ukupnoVrstaBrodova=4, int brojRedova=10, int brojKolona=10)
    {

        this->ukupnoVrstaBrodova=ukupnoVrstaBrodova;
        this->brojRedova=brojRedova;
        this->brojKolona=brojKolona;
    }


//verzija u kojoj nije potrebno da postoji razmak izmedju postavljenih brodova
    void odrediPozicijuBroda(int velicinaBroda)
    {
        int brojPotrebnihBrodova=this->ukupnoVrstaBrodova-(velicinaBroda-1);

        for(int brojBroda=0; brojBroda<brojPotrebnihBrodova; brojBroda++)
        {
            bool x=false;
            while(!x)
            {
                //pocetna koordinata broda
                int xRand = rand() % this->brojRedova ;
                int yRand = rand() % this->brojKolona ;

                int polozajRand = rand() % 4 + 1 ;
                bool mogucPolozaj=true;

                //polozaj preostalih koordinata broda je prema gore od pocetne koordinate
                if(polozajRand==1)
                {
                    if((xRand-(velicinaBroda-1))>=0)
                    {
                        for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                        {
                            if(matrica[xRand-pozicija][yRand]==1)
                            {
                                mogucPolozaj=false;
                            }
                        }
                        if(mogucPolozaj)
                        {
                            for (int i=0; i<velicinaBroda; i++)
                            {
                                matrica[xRand-i][yRand]=1;
                            }
                            x=true;
                        }
                    }
                }

                //polozaj preostalih koordinata broda je desno od pocetne koordinate
                else  if(polozajRand==2)
                {
                    if((yRand+(velicinaBroda-1))<=this->brojKolona-1)
                    {
                        for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                        {
                            if(matrica[xRand][yRand+pozicija]==1)
                            {
                                mogucPolozaj=false;
                            }
                        }
                        if(mogucPolozaj)
                        {
                            for (int i=0; i<velicinaBroda; i++)
                            {
                                matrica[xRand][yRand+i]=1;
                            }
                            x=true;
                        }
                    }
                }

                //polozaj preostalih koordinata broda dole od pocetne koordinate
                else if(polozajRand==3)
                {
                    if((xRand+(velicinaBroda-1))<=this->brojRedova-1)
                    {
                        for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                        {
                            if(matrica[xRand+pozicija][yRand]==1)
                            {
                                mogucPolozaj=false;
                            }
                        }
                        if(mogucPolozaj)
                        {


                            for (int i=0; i<velicinaBroda; i++)
                            {
                                matrica[xRand+i][yRand]=1;
                            }
                            x=true;
                        }
                    }
                }

                //polozaj preostalih koordinata broda lijevo od pocetne koordinate

                else
                {
                    if((yRand-(velicinaBroda-1))>=0)
                    {
                        for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                        {
                            if(matrica[xRand][yRand-pozicija]==1)
                            {
                                mogucPolozaj=false;
                            }
                        }
                        if(mogucPolozaj)
                        {

                            for (int i=0; i<velicinaBroda; i++)
                            {
                                matrica[xRand][yRand-i]=1;
                            }
                            x=true;
                        }
                    }

                }

            }
        }

    }


//verzija u kojoj je potrebno da postoji razmak izmedju postavljenih brodova
    bool odrediPozicijuBrodaVerzija2(int velicinaBroda)
    {
        int ukupanBrojPoljaZaBrodove=this->vratiUkupanBrojPoljaZaBrodove();

        if(ukupanBrojPoljaZaBrodove>brojRedova*brojKolona)
            throw string("Veci broj polja za brodove od ukupnog broja polja.");

        int brojPotrebnihBrodova=this->ukupnoVrstaBrodova-(velicinaBroda-1);

        for(int brojBroda=0; brojBroda<brojPotrebnihBrodova; brojBroda++)
        {
            bool x=false;
            int brojPokusaja=0;
            while(!x)
            {
                //srand (time(NULL));

                //pocetna koordinata broda
                int xRand = rand() % this->brojRedova;
                int yRand = rand() % this->brojKolona;

                int polozajRand = rand() % 4 + 1 ;

                //cout<<xRand<<" i "<<yRand<<"i polozaj "<<polozajRand<<endl;

                bool mogucPolozaj=true;

                if(matrica[xRand][yRand]==0)
                {
                    //polozaj preostalih koordinata broda je prema gore od pocetne koordinate
                    if(polozajRand==1)
                    {
                        if((xRand-(velicinaBroda-1))>=0)// and (xRand+1<=this->brojRedova-1))
                        {
                            for(int i=0; i<velicinaBroda; i++)
                            {
                                if(matrica[xRand-i][yRand]==1)
                                {
                                    mogucPolozaj=false;
                                    break;
                                }
                            }

                            if(xRand-velicinaBroda>=0)
                            {
                                if(matrica[xRand-velicinaBroda][yRand]==1)
                                    mogucPolozaj=false;
                                if(yRand-1>=0)
                                {
                                    if(matrica[xRand-velicinaBroda][yRand-1]==1)
                                        mogucPolozaj=false;
                                }
                                if(yRand+1<this->brojKolona)
                                {
                                    if(matrica[xRand-velicinaBroda][yRand+1]==1)
                                        mogucPolozaj=false;
                                }

                            }


                            if(yRand+1<this->brojKolona)
                            {
                                for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                                {
                                    if(matrica[xRand-pozicija][yRand+1]==1)
                                        mogucPolozaj=false;
                                }

                            }

                            if(yRand-1>=0)
                            {
                                for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                                {
                                    if(matrica[xRand-pozicija][yRand-1]==1)
                                        mogucPolozaj=false;
                                }
                            }

                            if(xRand+1<this->brojRedova)
                            {
                                if(matrica[xRand+1][yRand]==1)
                                    mogucPolozaj=false;
                                if(yRand-1>=0)
                                {
                                    if(matrica[xRand+1][yRand-1]==1)
                                        mogucPolozaj=false;
                                }
                                if(yRand+1<this->brojKolona)
                                {
                                    if(matrica[xRand+1][yRand+1]==1)
                                        mogucPolozaj=false;
                                }

                            }
                            /*for(int pozicija=-1; pozicija<=velicinaBroda; pozicija++)
                            {
                                if(matrica[xRand-pozicija][yRand]==1 or matrica[xRand-pozicija][yRand-1]==1 or matrica[xRand-pozicija][yRand+1]==1)
                                {
                                    mogucPolozaj=false;
                                }
                            }*/
                            if(mogucPolozaj)
                            {
                                for (int i=0; i<velicinaBroda; i++)
                                {
                                    matrica[xRand-i][yRand]=1;
                                }
                                x=true;
                            }
                        }
                    }

                    //polozaj preostalih koordinata broda je prema desno od pocetne koordinate
                    else  if(polozajRand==2)
                    {
                        if((yRand+(velicinaBroda-1))<this->brojKolona)
                        {

                            for(int i=0; i<velicinaBroda; i++)
                            {
                                if(matrica[xRand][yRand+i]==1)
                                {
                                    mogucPolozaj=false;
                                    break;
                                }
                            }

                            if(yRand-1>=0)
                            {
                                if(matrica[xRand][yRand-1]==1)
                                    mogucPolozaj=false;
                                if(xRand-1>=0)
                                {
                                    if(matrica[xRand-1][yRand-1]==1)
                                        mogucPolozaj=false;
                                }
                                if(xRand+1<this->brojKolona)
                                {
                                    if(matrica[xRand+1][yRand-1]==1)
                                        mogucPolozaj=false;
                                }

                            }


                            if(xRand+1<this->brojRedova)
                            {
                                for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                                {
                                    if(matrica[xRand+1][yRand+pozicija]==1)
                                        mogucPolozaj=false;
                                }

                            }

                            if(xRand-1>=0)
                            {
                                for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                                {
                                    if(matrica[xRand-1][yRand+pozicija]==1)
                                        mogucPolozaj=false;
                                }
                            }

                            if(yRand+velicinaBroda<this->brojKolona)
                            {
                                if(matrica[xRand][yRand+velicinaBroda]==1)
                                    mogucPolozaj=false;
                                if(xRand-1>=0)
                                {
                                    if(matrica[xRand-1][yRand+velicinaBroda]==1)
                                        mogucPolozaj=false;
                                }
                                if(xRand+1<this->brojRedova)
                                {
                                    if(matrica[xRand+1][yRand+velicinaBroda]==1)
                                        mogucPolozaj=false;
                                }
                            }
                            /* for(int pozicija=-1; pozicija<=velicinaBroda; pozicija++)
                             {
                                 if(matrica[xRand][yRand+pozicija]==1 or matrica[xRand-1][yRand+pozicija]==1 or matrica[xRand+1][yRand+pozicija]==1)
                                 {
                                     mogucPolozaj=false;
                                 }
                             }*/
                            if(mogucPolozaj)
                            {
                                for (int i=0; i<velicinaBroda; i++)
                                {
                                    matrica[xRand][yRand+i]=1;
                                }
                                x=true;
                            }
                        }
                    }

                    //polozaj preostalih koordinata broda je prema dole od pocetne koordinate
                    else if(polozajRand==3)
                    {
                        if((xRand+(velicinaBroda-1))<this->brojRedova)// and xRand-1>=0)
                        {

                            for(int i=0; i<velicinaBroda; i++)
                            {
                                if(matrica[xRand+i][yRand]==1)
                                {
                                    mogucPolozaj=false;
                                    break;
                                }
                            }


                            if(xRand+velicinaBroda<this->brojRedova)
                            {
                                if(matrica[xRand+velicinaBroda][yRand]==1)
                                    mogucPolozaj=false;
                                if(yRand-1>=0)
                                {
                                    if(matrica[xRand+velicinaBroda][yRand-1]==1)
                                        mogucPolozaj=false;
                                }
                                if(yRand+1<this->brojKolona)
                                {
                                    if(matrica[xRand+velicinaBroda][yRand+1]==1)
                                        mogucPolozaj=false;
                                }

                            }


                            if(yRand+1<this->brojKolona)
                            {
                                for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                                {
                                    if(matrica[xRand+pozicija][yRand+1]==1)
                                        mogucPolozaj=false;
                                }

                            }

                            if(yRand-1>=0)
                            {
                                for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                                {
                                    if(matrica[xRand+pozicija][yRand-1]==1)
                                        mogucPolozaj=false;
                                }
                            }

                            if(xRand-1>=0)
                            {
                                if(matrica[xRand-1][yRand]==1)
                                    mogucPolozaj=false;
                                if(yRand-1>=0)
                                {
                                    if(matrica[xRand-1][yRand-1]==1)
                                        mogucPolozaj=false;
                                }
                                if(yRand+1<this->brojKolona)
                                {
                                    if(matrica[xRand-1][yRand+1]==1)
                                        mogucPolozaj=false;
                                }

                            }
                            /*for(int pozicija=-1; pozicija<=velicinaBroda; pozicija++)
                            {
                                if(matrica[xRand+pozicija][yRand]==1 or matrica[xRand+pozicija][yRand-1]==1 or matrica[xRand+pozicija][yRand+1]==1)
                                {
                                    mogucPolozaj=false;
                                }
                            }*/
                            if(mogucPolozaj)
                            {
                                for (int i=0; i<velicinaBroda; i++)
                                {
                                    matrica[xRand+i][yRand]=1;
                                }
                                x=true;
                            }
                        }
                    }

                    //polozaj preostalih koordinata broda je prema lijevo od pocetne koordinate
                    else
                    {
                        if((yRand-(velicinaBroda-1))>=0)//and yRand+1<=this->brojKolona-1)
                        {
                            for(int i=0; i<velicinaBroda; i++)
                            {
                                if(matrica[xRand][yRand-i]==1)
                                {
                                    mogucPolozaj=false;
                                    break;
                                }
                            }

                            if(yRand+1<this->brojKolona)
                            {
                                if(matrica[xRand][yRand+1]==1)
                                    mogucPolozaj=false;
                                if(xRand-1>=0)
                                {
                                    if(matrica[xRand-1][yRand+1]==1)
                                        mogucPolozaj=false;
                                }
                                if(xRand+1<this->brojRedova)
                                {
                                    if(matrica[xRand+1][yRand+1]==1)
                                        mogucPolozaj=false;
                                }

                            }


                            if(xRand+1<this->brojRedova)
                            {
                                for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                                {
                                    if(matrica[xRand+1][yRand-pozicija]==1)
                                        mogucPolozaj=false;
                                }

                            }

                            if(xRand-1>=0)
                            {
                                for(int pozicija=0; pozicija<velicinaBroda; pozicija++)
                                {
                                    if(matrica[xRand-1][yRand-pozicija]==1)
                                        mogucPolozaj=false;
                                }
                            }

                            if(yRand-velicinaBroda>=0)
                            {
                                if(matrica[xRand][yRand-velicinaBroda]==1)
                                    mogucPolozaj=false;
                                if(xRand-1>=0)
                                {
                                    if(matrica[xRand-1][yRand-velicinaBroda]==1)
                                        mogucPolozaj=false;
                                }
                                if(xRand+1<this->brojRedova)
                                {
                                    if(matrica[xRand+1][yRand-velicinaBroda]==1)
                                        mogucPolozaj=false;
                                }

                            }
                            /*for(int pozicija=-1; pozicija<=velicinaBroda; pozicija++)
                            {
                                if(matrica[xRand][yRand-pozicija]==1 or matrica[xRand-1][yRand-pozicija]==1 or matrica[xRand+1][yRand-pozicija]==1)
                                {
                                    mogucPolozaj=false;
                                }
                            }*/
                            if(mogucPolozaj)
                            {

                                for (int i=0; i<velicinaBroda; i++)
                                {
                                    matrica[xRand][yRand-i]=1;
                                }
                                x=true;
                            }
                        }
                    }
                }
                if(!x)
                    brojPokusaja++;
                //cout<<"pokusaj broj_: "<<brojPokusaja<<endl;
                if(brojPokusaja==600)
                    return false;
            }
        }

        return true;
    }

    void restartujMatricu()
    {
        for (int i = 0; i < this->brojRedova; i++)
            for (int j = 0; j < this->brojKolona; j++)
                this->matrica[i][j] = 0;
    }


    void postaviBrodove()
    {
        int brojPokusaja=0;
        for(int i=this->ukupnoVrstaBrodova; i>0; i--)
        {
            //odrediPozicijuBroda(i);
            if(i==this->ukupnoVrstaBrodova)
                brojPokusaja++;

            bool odredjenaPozicija=odrediPozicijuBrodaVerzija2(i);

            if(!odredjenaPozicija)
            {
                //cout<<"neuspjesan pokusaj za brod velciine: "<<i<<", broj pokusaja: "<<brojPokusaja<<endl;
                //this->ispisiMatricu();
                this->restartujMatricu();
                //this->ispisiMatricu();

                i=this->ukupnoVrstaBrodova+1;
                //brojPokusaja++;
                if(brojPokusaja==5000)
                {
                    cout<<"Ukupan broj pokusaja: "<<brojPokusaja<<endl;
                    throw string("Ne mogu se postaviti svi brodovi, pokusajte povecati broj redova ili kolona");
                }

            }
            //cout<<"Ispis dobijene matrice za datu vrstu broda"<<endl;
            //this->ispisiMatricu();
            //else{brojPokusaja=0;}
                    //cout<<"ukupan broj pokusaja unutar petlje je bio:"<<brojPokusaja<<endl;


        }
        //cout<<"ukupan broj pokusaja je bio:"<<brojPokusaja<<endl;
    }


    void ispisiMatricu()
    {
        cout<<endl;
        //int broj=0;
        for (int i=0; i<this->brojRedova; i++)
        {
            for(int j=0; j<this->brojKolona; j++)
            {
                cout << matrica[i][j]<<" ";
                /*if(matrica[i][j]==1)
                    broj++;*/
            }
            cout<<endl;
        }
        cout<<endl;
    }

    int vratiUkupanBrojPoljaZaBrodove()
    {

        int ukupnoBrodova=0;
        for(int i=0; i<this->ukupnoVrstaBrodova; i++)
            ukupnoBrodova+=(i+1)*(this->ukupnoVrstaBrodova-i);

        provjeriOmjerBrodoviPolja(ukupnoBrodova);
        return ukupnoBrodova;
    }

    void provjeriOmjerBrodoviPolja(int ukupnoBrodova)
    {
        int ukupnoPolja=this->brojRedova*this->brojKolona;
        if(ukupnoBrodova>ukupnoPolja)
        {
            stringstream ssUkupnoBrodova, ssUkupnoPolja;
            ssUkupnoBrodova << ukupnoBrodova;
            string ukupnoBrodova = ssUkupnoBrodova.str();

            ssUkupnoPolja << ukupnoPolja;
            string ukupnoPolja = ssUkupnoPolja.str();

            throw string ("Neispravna postavka, vise polja za brodove ("+ukupnoBrodova+") od ukupnog broja polja ("+ukupnoPolja+").");
        }
    }




    void igraj()
    {
        int ukupnoBrodova=vratiUkupanBrojPoljaZaBrodove();
        this->postaviBrodove();
        this->ispisiMatricu();

        int pogodjenoPolja=0;
        int brojPokusaja=0;

        while(pogodjenoPolja<ukupnoBrodova)
        {
            try
            {
                int x,y;
                cout<<"Unesi x i y koordinate, za x (1-"<<this->brojRedova<<"), za y (1-"<<this->brojKolona<<"):"<<endl;

                cout<<"X koordinata: ";
                if(!(cin>>x))
                    throw string("Morate unijeti broj.");

                cout<<"Y koordinata: ";
                if(!(cin>>y))
                    throw string("Morate unijeti broj.");

                cout<<endl;

                stringstream sRed,sKolona;
                sRed << this->brojRedova;
                string red = sRed.str();

                sKolona << this->brojKolona;
                string kolona = sKolona.str();


                if(x<1 or x>this->brojRedova or y<1 or y>this->brojKolona)
                    throw string ("Brojevi moraju biti u sljedecem opsegu, za x (1-"+red+") i za y (1-"+kolona+").");

                x--;
                y--;

                if(matrica[x][y]==1)
                {
                    matrica[x][y]=3;
                    pogodjenoPolja++;
                    brojPokusaja++;
                }
                else if(matrica[x][y]==0)
                {
                    matrica[x][y]=2;
                    brojPokusaja++;
                }

                this->ispisiMatricu();

                cout<<"Broj pokusaja: "<<brojPokusaja<<endl;
                cout<<"Broj pogodjenih: "<<pogodjenoPolja<<endl<<endl;
            }
            catch (string s)
            {
                cout<<s<<endl<<endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }

            catch(...)
            {
            }

        }
    }

};

bool daLiNovuPartijuIgrati()
{
    string odluka;
    bool novaPartija=true;
    bool ispravanUnos=false;
    while(!ispravanUnos)
    {
        cout<<"Zelite li igrati novu partiju? (y/n): ";
        cin>>odluka;
        cout<<endl;
        if(odluka=="y")
        {
            ispravanUnos=true;
            novaPartija=true;
        }

        else if(odluka=="n")
        {
            ispravanUnos=true;
            novaPartija=false;
        }
    }
    return novaPartija;
}


int main()
{
    srand (time(NULL));

    /*clock_t tStart = clock();
    cout<<"Time taken: \n"<<(double)((clock() - tStart));*/

    int brojVrstaBrodova,brojRedova, brojKolona;
    bool igraUToku=true;
    while (igraUToku)
    {
        try
        {
            cout<<"Unesite broj vrsta brodova: ";
            if(!(cin>>brojVrstaBrodova))
                throw string("Morate unijeti broj.");

            if(brojVrstaBrodova<1)
                throw string("Broj vrsta brodova mora biti pozitivan broj.");


            cout<<"Unesite broj redova u opsegu (1-20): ";
            if(!(cin>>brojRedova))
                throw string("Morate unijeti broj.");

            if(brojRedova<1 or brojRedova>20)
                throw string("Broj redova nije u datom opsegu (1-20).");


            cout<<"Unesite broj kolona u opsegu (1-20): ";
            if(!(cin>>brojKolona))
                throw string("Morate unijeti broj.");

            if(brojKolona<1 or brojKolona>20)
                throw string("Broj kolona nije u datom opsegu (1-20).");

            BrodoviMatrica brodoviMatrica (brojVrstaBrodova, brojRedova, brojKolona);
            brodoviMatrica.postaviBrodove();
            brodoviMatrica.ispisiMatricu();
            //brodoviMatrica.igraj();

            igraUToku=daLiNovuPartijuIgrati();

        }
        catch (string s)
        {
            cout<<s<<endl<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        catch(...)
        {
        }
    }


    return 0;
}







/*
void poredajOdCetiri(int (&matrica)[10][10])
{

    bool x=false;
    while(!x)
    {
        int xRand = rand() % 10 ;
        int yRand = rand() % 10 ;

        int polozajRand = rand() % 4 + 1 ;

        if(polozajRand==1)
        {
            if((xRand-1)>=0 && (xRand-3)>=0)
            {
                matrica[xRand][yRand]=1;
                matrica[xRand-1][yRand]=1;
                matrica[xRand-2][yRand]=1;
                matrica[xRand-3][yRand]=1;
                x=true;
            }
        }

        else  if(polozajRand==2)
        {
            if((yRand+3)<=9)
            {
                matrica[xRand][yRand]=1;
                matrica[xRand][yRand+1]=1;
                matrica[xRand][yRand+2]=1;
                matrica[xRand][yRand+3]=1;
                x=true;
            }
        }
        else if(polozajRand==3)
        {
            if((xRand+3)<=9)
            {
                matrica[xRand][yRand]=1;
                matrica[xRand+1][yRand]=1;
                matrica[xRand+2][yRand]=1;
                matrica[xRand+3][yRand]=1;
                x=true;
            }
        }
        else
        {
            if((yRand-3)>=0)
            {
                matrica[xRand][yRand]=1;
                matrica[xRand][yRand-1]=1;
                matrica[xRand][yRand-2]=1;
                matrica[xRand][yRand-3]=1;
                x=true;
            }

        }

    }

}


void poredajOdTri(int (&matrica)[10][10])
{
    for (int i=0; i<2; i++)
    {
        bool x=false;
        while(!x)
        {
            int xRand = rand() % 10 ;
            int yRand = rand() % 10 ;

            if( ((xRand-1)>=0 && (xRand-2)>=0) &&
                    (matrica[xRand][yRand]==0 && matrica[xRand-1][yRand]==0 && matrica[xRand-2][yRand]==0))
            {
                matrica[xRand][yRand]=1;
                matrica[xRand-1][yRand]=1;
                matrica[xRand-2][yRand]=1;
                x=true;
            }
        }
    }

}

void poredajOdDva(int (&matrica)[10][10])
{
    for (int i=0; i<3; i++)
    {
        bool x=false;
        while(!x)
        {


            int xRand = rand() % 10 ;
            int yRand = rand() % 10 ;

            if((xRand-1)>=0  && (matrica[xRand][yRand]==0 && matrica[xRand-1][yRand]==0))
            {
                matrica[xRand][yRand]=1;
                matrica[xRand-1][yRand]=1;
                x=true;
            }
        }
    }

}


void poredajOdJedan(int (&matrica)[10][10])
{
    for (int i=0; i<4; i++)
    {
        bool x=false;
        while(!x)
        {
            int xRand = rand() % 10 ;
            int yRand = rand() % 10 ;

            if(matrica[xRand][yRand]==0)
            {
                matrica[xRand][yRand]=1;
                x=true;
            }
        }
    }
}*/



