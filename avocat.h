#ifndef AVOCAT_H
#define AVOCAT_H
#include <QString>
#include<QSqlQueryModel>
class Avocat
{
public:
    Avocat();
    Avocat(int,QString,QString,QString,int);
    int getid() ;
    QString getnom() ;
    QString getprenom() ;
    QString getmail() ;
    int getnb_client() ;
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setmail(QString);
    void setnbclients(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
     bool modifier(int , QString,QString,QString,int);
     QSqlQueryModel * trie_NOM();
                 QSqlQueryModel * trie_PRENOM();
                 QSqlQueryModel * trie_id();
               QSqlQueryModel* rechercheid(int);
               QSqlQueryModel* recherchenom(QString);
               QSqlQueryModel* rechercheprenom(QString);
              int taxes();


private:
    int id ;
    QString nom ;
    QString prenom ;
    QString mail ;
    int nb_clients ;

};

#endif // AVOCAT_H
