#include <iostream>
using namespace std;

class Macierz {
    friend ostream &operator<<(ostream &s1, const Macierz &o1);
    friend istream &operator>>(istream &s1, Macierz &o1);

    double *ws;
    int rozmiar;

public:

    Macierz() // konstruktor
    {
        ws = nullptr;
        rozmiar = 0;
    }

    Macierz(const Macierz &o1) // konstruktor kopiujacy
    {
        if(o1.rozmiar>0 && o1.ws != nullptr)
        {
            ws = new double[o1.rozmiar * o1.rozmiar];
            rozmiar = o1.rozmiar;

            for (int i = 0; i < rozmiar * rozmiar; i++)
            {
                ws[i] = o1.ws[i];
            }
        }
        else
        {
            ws = nullptr;
            rozmiar = o1.rozmiar;
        }
    }

    explicit Macierz(int rozmiar_macierzy) // konstruktor wypelniajacy zerami
    {
        if(rozmiar_macierzy>0)
        {
            ws = new double[rozmiar_macierzy * rozmiar_macierzy];
            rozmiar = rozmiar_macierzy;

            for (int i = 0; i < rozmiar * rozmiar; i++)
            {
                ws[i] = 0;
            }
        }
        else {
            ws = nullptr;
            rozmiar = rozmiar_macierzy;
        }
    }

    Macierz(int rozmiar_macierzy,int wypelniacz) // konstruktor wypelniajacy zadana liczba
    {
        if(rozmiar_macierzy>0)
        {
            ws = new double[rozmiar_macierzy * rozmiar_macierzy];
            rozmiar = rozmiar_macierzy;

            for (int i = 0; i < rozmiar * rozmiar; i++)
            {
                ws[i] = wypelniacz;
            }
        }
        else
        {
            ws = nullptr;
            rozmiar = rozmiar_macierzy;
        }
    }

    ~Macierz() // destruktor
    {
        if(ws!=nullptr)
        {
            delete [] ws; // nie jest zmieniana wartosc wskaznika
            ws=nullptr;
        }
    }

    Macierz & operator=(const Macierz & o1) // a.operator=(b); lub a=b;
    {
        if(this==&o1) // a=a
            return *this;

        delete [] ws;

        if(o1.rozmiar<1 || o1.ws==nullptr)
        {
            rozmiar=o1.rozmiar;
            ws = nullptr;
            return *this;
        }



        ws=new double[o1.rozmiar*o1.rozmiar];
        rozmiar=o1.rozmiar;

        for(int i=0;i<(o1.rozmiar*o1.rozmiar);i++)
        {
            ws[i]=o1.ws[i];
        }

        return *this; // zawsze to robimy (zapamietac) Jest to po to zeby mozna bylo a=b=c;
    }

    Macierz operator+(const Macierz &o1)
    {
        Macierz wynik_dodawania;

        if(rozmiar<0 || o1.rozmiar<0)
        {
            wynik_dodawania.ws= nullptr;
            wynik_dodawania.rozmiar=0;
            return wynik_dodawania;
        }

        if(rozmiar==o1.rozmiar)
        {   wynik_dodawania.rozmiar=o1.rozmiar;
            wynik_dodawania.ws=new double[o1.rozmiar*o1.rozmiar];

            for(int i=0;i<o1.rozmiar*o1.rozmiar;i++)
            {
                wynik_dodawania.ws[i]=ws[i]+o1.ws[i];
            }

            return wynik_dodawania;
        }
        else
        {
            wynik_dodawania.ws= nullptr;
            wynik_dodawania.rozmiar=0;
            return wynik_dodawania;
        }
    }

    Macierz operator-(const Macierz &o1)
    {
        Macierz wynik_odejmowania;

        if(rozmiar<0 || o1.rozmiar<0)
        {
            wynik_odejmowania.ws= nullptr;
            wynik_odejmowania.rozmiar=0;
            return wynik_odejmowania;
        }

        if(rozmiar==o1.rozmiar)
        {
            wynik_odejmowania.rozmiar=o1.rozmiar;
            wynik_odejmowania.ws=new double[o1.rozmiar*o1.rozmiar];

            for(int i=0;i<o1.rozmiar*o1.rozmiar;i++)
            {
                wynik_odejmowania.ws[i]=ws[i]-o1.ws[i];
            }

            return wynik_odejmowania;
        }
        else
        {
            wynik_odejmowania.ws= nullptr;
            wynik_odejmowania.rozmiar=0;
            return wynik_odejmowania;
        }

    }

    Macierz operator*(const Macierz &o1)
    {
        Macierz wynik;

        if(rozmiar<0 || o1.rozmiar<0)
        {
            wynik.ws= nullptr;
            wynik.rozmiar=0;
            return wynik;
        }

        if(rozmiar==o1.rozmiar)
        {
            wynik.rozmiar=rozmiar;
            wynik.ws=new double[rozmiar*rozmiar];
            int kolumna,wiersz;

            for (int i = 0; i < rozmiar * rozmiar; i++)
            {
                wynik.ws[i] = 0;
                kolumna = i % rozmiar;
                wiersz = i / rozmiar;

                for (int j = wiersz * rozmiar; j < (rozmiar * wiersz + rozmiar); j++)
                {
                    wynik.ws[i] += (ws[j] * o1.ws[kolumna]);
                    kolumna += rozmiar;
                }
            }

            return wynik;
        }
        else
        {
            wynik.ws= nullptr;
            wynik.rozmiar=0;
            return wynik;
        }
    }

    bool operator==(const Macierz &o1)
    {
        if(rozmiar==o1.rozmiar && rozmiar>=0) {
            for (int i = 0; i < rozmiar * rozmiar; i++) {
                if (ws[i] != o1.ws[i])
                    return false;
            }

            return true;
        }

        return false;
    }

    bool operator!=(const Macierz &o1)
    {
        if(rozmiar==o1.rozmiar && rozmiar>0) {
            for (int i = 0; i < rozmiar * rozmiar; i++) {
                if (ws[i] != o1.ws[i]) {
                    return true;
                }
            }

            return false;
        }

        return false;
    }

    bool operator>(const Macierz &o1)
    {
        if(rozmiar==o1.rozmiar && rozmiar>0) {
            for (int i = 0; i < rozmiar * rozmiar; i++) {
                if (ws[i] <= o1.ws[i])
                    return false;
            }

            return true;
        }

        return false;
    }

    bool operator>=(const Macierz &o1)
    {
        if(rozmiar==o1.rozmiar && rozmiar>=0) {
            for (int i = 0; i < rozmiar * rozmiar; i++) {
                if (ws[i] < o1.ws[i])
                    return false;
            }

            return true;
        }

        return false;
    }

    bool operator<(const Macierz &o1)
    {
        if(rozmiar==o1.rozmiar && rozmiar>0) {
            for (int i = 0; i < rozmiar * rozmiar; i++) {
                if (ws[i] >= o1.ws[i])
                    return false;
            }

            return true;
        }

        return false;
    }

    bool operator<=(const Macierz &o1)
    {
        if(rozmiar==o1.rozmiar && rozmiar>=0)
        {
            for (int i = 0; i < rozmiar * rozmiar; i++)
            {
                if (ws[i] > o1.ws[i])
                    return false;
            }

            return true;
        }

        return false;
    }
};

istream & operator>>(istream & s1,Macierz & o1)
{
    if(o1.ws!=nullptr)
    {
        delete[] o1.ws;
        o1.ws = nullptr;
    }
    s1>>o1.rozmiar;

    if(o1.rozmiar>0)
    {
        o1.ws = new double[o1.rozmiar*o1.rozmiar];

        for(int i=0;i<(o1.rozmiar*o1.rozmiar);i++)
        {
            s1>>o1.ws[i];
        }

    }

    return s1;
}

ostream & operator<<(ostream & s1, const Macierz & o1)
{
    if(o1.ws!=nullptr)
    {

        for(int i=0;i<(o1.rozmiar*o1.rozmiar);i++)
        {
            if((i%o1.rozmiar)==0 && i!=0)
                s1 << endl;
            s1 << o1.ws[i] << " ";
        }
        s1<<endl;
    }

    return s1;
}

int main()
{
    Macierz a,b,c1,c2,c3,d(3),e(2,7);
    cin>>a>>b;
    Macierz kopia(a);
    c1=a+b;
    c2=a-b;
    c3=a*b;

    cout << endl;
    cout << "konstruktor kopiujacy obiekt a:" << endl << kopia <<endl;
    cout << "konstruktor wypelniajacy zerami:" << endl << d <<endl;
    cout << "konstruktor wypelniajacy zadana liczba:" << endl << e <<endl;
    cout << "a=a:" << endl << (a=a) <<endl;


    cout << "c1=a+b:" << endl << c1 <<endl;
    cout << "c2=a-b:" << endl << c2 <<endl;
    cout << "c3=a*b:" << endl << c3 <<endl;
    cout << "a==b: " << (a==b) << endl;
    cout << "a!=b: " << (a!=b) << endl;
    cout << "a<b: " << (a<b) << endl;
    cout << "a<=b: " << (a<=b) << endl;
    cout << "a>b: " << (a>b) << endl;
    cout << "a>=b: " << (a>=b) << endl;
}