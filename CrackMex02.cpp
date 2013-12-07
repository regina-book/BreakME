#include <iostream>
#include <stdio.h>
#define SECRET_SIZE 6
#define NOTICE "[KeyGen 001] Entrez votre numero de client et le bon code d'authentification :"
using namespace std;
typedef unsigned int uint;
typedef int Item;

struct Pile {
Item* cpile;
uint spile;
};

void init_pile(Pile& p);
void delete_pile(Pile& p);
void push_pile(Pile& p, Item item);
void pop_pile(Pile& p);
Item sommet_pile(Pile& p);

int main() {
    int auth;
    Pile pile;
    int secret[]={2,5,7,9,5,3};

    cout << NOTICE << endl;
    cin >> auth;
    cout << auth << endl;

    init_pile(pile);
    for(int i=0; i<SECRET_SIZE; i++)
    push_pile(pile, secret[i]);

    for(int i=0; i<SECRET_SIZE; i+=2)
        auth+=secret[i];

    for(int i=1; i<SECRET_SIZE; i+=2)
        auth*=secret[i];

    fprintf(stdout, "%d-2501", auth);
    delete_pile(pile);
    return 0;
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
