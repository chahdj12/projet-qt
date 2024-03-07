#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnexion(){
    db= QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("PROJET2A");
    db.setUserName("jouini");
    db.setPassword("esprit18");
    if (db.open())test=true;
    return test;
}
void connexion::closeconnexion(){db.close();}
