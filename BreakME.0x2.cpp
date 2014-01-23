
    /**/
    //@BreakME.0x2
    //@Toufik Airane
    //@2013.12
    /**/
    #include <iostream>
    #include <ctime>
    #include <windows.h>
    #define NOTICE " Entrez votre numero de client et votre code d'authentification :"
    using namespace std;

    typedef int Item;
    struct Pile {
    Item* cpile;
    int spile;
    };

    void push_pile(Pile& p, Item item);
    void pop_pile(Pile& p);
    Item sommet_pile(Pile& p);
    void init_pile(Pile& p);
    void delete_pile(Pile& p);

    int main() {
        int auth, pass;
        Pile pile;
        int secret[]={2,5,7,9,5,3};
        int ssecret = sizeof(secret) / sizeof(int);
        cout << NOTICE << endl;
        cin >> auth;
        cin >> pass;

        init_pile(pile);
        int antidbg = clock();

        for(int i=0; i<ssecret; i++)
        push_pile(pile, secret[i]);

        for(int i=0; i<ssecret; i+=2)
            auth+=secret[i];

        for(int i=1; i<ssecret; i+=2)
            auth*=secret[i];

        delete_pile(pile);

        if(clock() - antidbg > 100)
            return 0x1;

        if(pass==auth)
            cout << "Good Job ! :)";
        else
            cout << "Bad Job ! :(";

        return 0x0;
    }

    void push_pile(Pile& p, Item item) {
        Item* tmp = p.cpile;
        p.cpile = new Item[p.spile+1];
            for(int i=0; i<p.spile; i++)
                p.cpile[i] = tmp[i];
        delete[] tmp;
        p.cpile[p.spile]=item;
        p.spile++;
    }

    void pop_pile(Pile& p) {
        p.spile--;
        Item* tmp = p.cpile;
        p.cpile = new Item[p.spile];
            for(int i=0;i<p.spile;i++)
                p.cpile[i]=tmp[i];
        delete[] tmp;
    }

    Item sommet_pile(Pile& p) {
        return p.cpile[p.spile-1];
    }

    void init_pile(Pile& p) {
        p.cpile=NULL;
        p.spile=0;
    }

    void delete_pile(Pile& p) {
        delete[] p.cpile;
        p.cpile=NULL;
        p.spile=0;
    }
