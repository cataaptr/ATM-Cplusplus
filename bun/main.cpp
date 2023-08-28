#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <typeinfo>
#include <string>
#include <fstream>

using namespace std;

int verificarePin(int *pin, int *adev)
{
    int i;
    char c;
    int num=0;

    cout<<"Va rog sa introduceti codul PIN:"<<endl;
    for(i=0;i<4;i++)
        {c=getch();
        num=num*10+(c-'0');
        cout<<c;
        }
    cout<<endl;
    cout<<"pin este "<<num<<endl;
    if(num==*pin)
        *adev=1;
    else
        *adev=0;

    return *adev;
}

void schimbarePin(int *pin)
{
    int num=0,i;
    char c,ch;

    cout<<"Va rugam introduceti noul Pin"<<endl;
    for(i=0;i<4;i++)
    {
        c=getch();
        num=num*10+(c-'0');
        cout<<"*";
    }
    cout<<endl;
    cout<<"noul pin este "<<num<<endl;
    *pin=num;
    fstream f("pin.txt",ios::out);
    f<<num;
    f.close();
}

void continuare(int *cont)
{
    char c;
    int num;

    cout<<"Doriti alta operatiune?\n"<<endl;
    cout<<"Da(apasati tasta 1)."<<endl;
    cout<<"Nu(apasati orice alta tasta)."<<endl;
    c=getch();
    num=c-'0';
    *cont=num;
}

void afisareMeniu()
{
    cout<<"***************MENIU***********************"<<endl;
    cout<<"*                                         *"<<endl;
    cout<<"*         1.Interogare sold               *"<<endl;
    cout<<"*         2.Depunere numerar              *"<<endl;
    cout<<"*         3.Eliberare numerar rapida      *"<<endl;
    cout<<"*         4.Eliberare numerar             *"<<endl;
    cout<<"*         5.Schimbare cod PIN             *"<<endl;
    cout<<"*         6.Iesire                        *"<<endl;
    cout<<"*                                         *"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<endl;
}

void afisareSold(double *sold)
{
    cout<<"Soldul curent este de "<<*sold<<" lei.";
    cout<<"Va rugam ridicati chitanta.\n"<<endl;
}

void depozit(double *sold,double depozitIntrodus)
{
    char c;
    int suma=1;

    while(suma==1)
    {cout<<"Introduceti valoarea depozitului:"<<endl;
    cin>>depozitIntrodus;
    *sold+=depozitIntrodus;
    system("CLS");
    cout<<"A fost introdusa suma de "<<depozitIntrodus<<" lei.\n"<<endl;
    cout<<"Doriti adaugarea altei sume?\n"<<endl;
    cout<<"DA (apasati tasta 1)."<<endl;
    cout<<"NU (apasati orice alta tasta)."<<endl;
    c=getch();
    suma=c-'0';
    }
    system("CLS");
    cout<<"Va rugam ridicati chitanta."<<endl;
}

void retragere(double *sold, double *cash)
{
    cout<<"Introduceti suma dorita:"<<endl;
    cin>>*cash;

    if(*cash>*sold)
        cout<<"Suma introdusa depaseste soldul dumneavoastra"<<endl;
        else if(*cash==0)
                cout<<"Suma introdusa este incorecta"<<endl;
                else if (*cash>3000)
                    cout<<"Ati depasit suma maxima de retragere zilnica. Va rugam contactati banca"<<endl;
                    else
                        {*sold-=*cash;
                        cout<<"Va rugam ridicati chitanta."<<endl;}

    cout<<*sold<<endl;

}

void retragereRapida(double *sold, int varianta, double *cash)
{
    cout<<"Alegeti suma dorita, alegand cifra variantei dorite"<<endl;

    cout<<"********************************"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"*         1.50 lei             *"<<endl;
    cout<<"*         2.100 lei            *"<<endl;
    cout<<"*         3.250 lei            *"<<endl;
    cout<<"*         4.500 lei            *"<<endl;
    cout<<"*                              *"<<endl;
    cout<<"********************************"<<endl;

    char c;
    c=getch();
    varianta=c-'0';

    switch(varianta)
    {
        case 1: {if(*sold<50) cout<<"Suma introdusa depaseste soldul dumneavoastra"<<endl; else if((*cash+50)>3000) cout<<"Ati depasit suma maxima de retragere zilnica. Va rugam contactati banca"<<endl;else {*sold-=50;*cash+=50;}}break;
        case 2: {if(*sold<100) cout<<"Suma introdusa depaseste soldul dumneavoastra"<<endl;else if((*cash+100)>3000) cout<<"Ati depasit suma maxima de retragere zilnica. Va rugam contactati banca"<<endl;else {*sold-=100;*cash+=100;}}break;
        case 3: {if(*sold<250) cout<<"Suma introdusa depaseste soldul dumneavoastra"<<endl;else if((*cash+250)>3000) cout<<"Ati depasit suma maxima de retragere zilnica. Va rugam contactati banca"<<endl;else {*sold-=250;*cash+=250;}}break;
        case 4: {if(*sold<500) cout<<"Suma introdusa depaseste soldul dumneavoastra"<<endl;else if((*cash+500)>3000) cout<<"Ati depasit suma maxima de retragere zilnica. Va rugam contactati banca"<<endl;else {*sold-=500;*cash+=500;}}break;
    }

}
int main()
{
    char c;
    int cont=1,pin=0,optiune;
    int i=0,p;
    int adev=0;
    double sold=10;
    double depozitIntrodus;
    double cash;
    int varianta;

    cout<<"Buna ziua!"<<endl;

    char ch;
    string nume;
    ifstream f("pin.txt");
    int j = 0;
    while (j < 4 && f.get(ch)) {
        if (isdigit(ch)) {
            nume += ch;
            j++;}}
    p=1000;
    for (j = 0; j < nume.length(); j++)
        {pin=pin+p*(nume[j]-'0');p/=10;}

   while(i<3 && adev!=1)
        {verificarePin(&pin,&adev);
        i++;
        if(adev==0)
           cout<<"PIN incorect. Va rugam reintroduceti PIN"<<endl;
        system("CLS");
        }

    if(adev==1)
{
    do{
    afisareMeniu();

    cout<<"Alegeti tipul operatiunii bancare:";


    c=getch();
    optiune=c-'0';
    cout<<c<<endl;

    switch(optiune)
        {
            case 1: {afisareSold(&sold); continuare(&cont); system("CLS");}break;
            case 2: {depozit(&sold,depozitIntrodus); continuare(&cont); system("CLS");}break;
            case 3: {retragereRapida(&sold, varianta,&cash);  continuare(&cont); system("CLS");} break;
            case 4: {retragere(&sold, &cash); continuare(&cont); system("CLS");}break;
            case 5: {schimbarePin(&pin); continuare(&cont); system("CLS");}break;

        }
    }while(optiune!=6 && cont==1);

}
    else
        cout<<"PIN incorect. Card blocat, va rugam ridicati cardul. Pentru mai multe detalii va rugam contactati banca."<<endl;


 return 0;
}
