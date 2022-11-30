#ifndef PERSONNE_H
#define PERSONNE_H
#include <QString>

class personne
{
public:
    personne();
    personne(int,QString);
private:
    int identifiant ;
    QString mdp ;

};

#endif // PERSONNE_H
