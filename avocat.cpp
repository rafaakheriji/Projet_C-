#include "avocat.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QDebug>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>
#include<QtNetwork/QNetworkRequest>
Avocat::Avocat()
{
 id=0 ; nom=" "; prenom="";mail="";nb_clients=0;
}
Avocat::Avocat(int id,QString nom,QString prenom,QString mail,int nb_clients)
{this->id=id;this->nom=nom;this->prenom=prenom;this->mail=mail;this->nb_clients=nb_clients;}
int Avocat::getid(){return id;}
QString Avocat::getnom(){return nom;}
QString  Avocat::getprenom(){return prenom;}
QString Avocat::getmail(){return mail;}
int Avocat::getnb_client(){return nb_clients;}
void Avocat::setid(int id){this->id=id;}
void Avocat::setnom(QString nom){this->nom=nom;}
void Avocat::setprenom(QString prenom){this->prenom=prenom;}
void Avocat::setmail(QString mail){this->mail=mail;}
void Avocat::setnbclients(int nb_clients){this->nb_clients=nb_clients;}
bool Avocat::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString nc_string= QString::number(nb_clients);
          query.prepare("INSERT INTO AVOCAT (IDENTIFIANT, NOM, PRENOM , EMAIL, NB_CLIENTS)"
                         "VALUES(:IDENTIFIANT,:NOM,:PRENOM,:EMAIL,:NB_CLIENTS)");
          query.bindValue(":IDENTIFIANT", id_string);
          query.bindValue(":NOM", nom);
          query.bindValue(":PRENOM", prenom);
          query.bindValue(":EMAIL", mail);
          query.bindValue(":NB_CLIENTS", nc_string);
          return  query.exec();

}
bool Avocat::supprimer(int id)
{
    QSqlQuery query;
QString id1= QString::number(id);
          query.prepare("Delete from AVOCAT where id=:"+id1+"");
          query.bindValue(":id", id1);

          return  query.exec();

}
QSqlQueryModel* Avocat::afficher()
{

    QSqlQueryModel* model = new QSqlQueryModel() ;

    model->setQuery("SELECT * FROM avocat ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NB_CLIENTS"));



   return model ;
}
bool Avocat::modifier(int id, QString nom, QString prenom , QString mail, int nb_clients)
{

    QSqlQuery query ;
    QString id1_string= QString::number(id);
    QString nc1_string= QString::number(nb_clients);

    query.prepare("UPDATE  AVOCAT (IDENTIFIANT, NOM, PRENOM , EMAIL, NB_CLIENTS) "
                  "VALUES (:id, :forename, :surname , :mail, :clients number)");
    query.bindValue(":id", id1_string);
    query.bindValue(":forename", nom);
    query.bindValue(":surname", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":clients number", nc1_string);
    return  query.exec();

}
QSqlQueryModel * Avocat::trie_NOM()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM AVOCAT ORDER BY nom ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("nb_clients"));
    return model;
}
QSqlQueryModel * Avocat::trie_PRENOM()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Avocat ORDER BY prenom ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("nb_clients"));
    return model;
}
QSqlQueryModel * Avocat::trie_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Avocat ORDER BY identifiant ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("nb_clients"));
    return model;
}


QSqlQueryModel* Avocat::rechercheid(int id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
      QString res=QString ::number(id);
            model->setQuery("select * from AVOCAT where IDENTIFIANT="+res+"");

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("nb_clients"));
      return model;

}
QSqlQueryModel* Avocat::recherchenom(QString nom)
{
    QSqlQueryModel *model=new QSqlQueryModel();

            model->setQuery("select * from AVOCAT where NOM='"+nom+"'");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("nb_clients"));
      return model;

}
QSqlQueryModel* Avocat::rechercheprenom(QString prenom)
{
    QSqlQueryModel *model=new QSqlQueryModel();

            model->setQuery("select * from AVOCAT where PRENOM='"+prenom+"'");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("nb_clients"));
      return model;

}

int Avocat::taxes()
{
Avocat A;
QSqlQuery query;
  int n ;
   QString res=QString ::number(id);
          query.exec("SELECT NB_CLIENTS FROM AVOCAT WHERE IDENTIFIANT=:"+res+"");
  query.bindValue(":NB_CLIENT",n);
  return  n;
}
