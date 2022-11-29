#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avocat.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QIntValidator>
#include<QFile>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_avocat->setModel(A.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString mail=ui->le_mail->text();
    int nb_clients=ui->sb_nc->text().toInt();
            Avocat A(id,nom,prenom,mail,nb_clients);
            bool test=A.ajouter();
             QMessageBox msgbox;
             if(test)
                 msgbox.setText("ajout avec succes");
                         else
                         msgbox.setText("Echec d'ajout");
                         msgbox.exec();
}


void MainWindow::on_pb_supp_clicked()
{
    Avocat A1 ; A1.setid(ui->le_id_supp->text().toInt());
            bool test=A1.supprimer(A1.getid());
             QMessageBox msgbox1;
             if(test)
                 msgbox1.setText("suppression avec succes");
                         else
                         msgbox1.setText("Echec de suppressiont");
                         msgbox1.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_mid->text().toInt();
    Avocat A2;
       QString nom=ui->le_mn->text();
       QString prenom=ui->le_mp->text();
       QString mail=ui->le_me->text();
       int nb_clients=ui->le_mn->text().toInt();

       Avocat(id,nom,prenom,mail,nb_clients);
       bool test=A2.modifier(id,nom,prenom,mail,nb_clients);
       if (test)
       {
           QMessageBox msgbox2;
           if(test)
               msgbox2.setText("modiffication avec succes");
                       else
                       msgbox2.setText("Echec de mod");
                       msgbox2.exec();
       }
}


void MainWindow::on_pb_tri_clicked()
{
    Avocat A;
             QString choix=ui->comboBox->currentText();
             if (choix=="Nom")
             {
                 ui->tableView->setModel(A.trie_NOM());
                 ui->tableView->setModel(A.afficher());
                 bool test=A.trie_NOM();//tri Nom
                 if (test)
                 {

             ui->tableView->setModel(A.trie_NOM());
                     QMessageBox::information(nullptr,QObject::tr("ok"),
                                              QObject::tr("tri Nom effectué \n"
                                                          "Click Cancel to exist ."),QMessageBox::Cancel);

                 }
                 else
                       QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                                   QObject::tr("tri Nom failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
             }
            else if (choix=="Prenom")
             {
                 ui->tableView->setModel(A.trie_PRENOM());
                 ui->tableView->setModel(A.afficher());
                 bool test=A.trie_PRENOM();//tri prenom
                if (test)
                 {

             ui->tableView->setModel(A.trie_PRENOM());
                     QMessageBox::information(nullptr,QObject::tr("ok"),
                                              QObject::tr("tri prenom effectué \n"
                                                          "Click Cancel to exist ."),QMessageBox::Cancel);

                 }
                 else
                       QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                                   QObject::tr("tri prenom failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
             }
           else  if (choix=="Identidiant")
             {
                 ui->tableView->setModel(A.trie_id());
                 ui->tableView->setModel(A.afficher());
                 bool test=A.trie_id();//tri produit
                 if (test)
                 {

             ui->tableView->setModel(A.trie_id());
                     QMessageBox::information(nullptr,QObject::tr("ok"),
                                              QObject::tr("tri departement effectué \n"
                                                          "Click Cancel to exist ."),QMessageBox::Cancel);

                 }
                 else
                       QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                                   QObject::tr("tri departement failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
             }

}

void MainWindow::on_pb_rech_clicked()
{

    Avocat A;
           QString choix=ui->comboBox_2->currentText();

           if (choix=="Identifiant")
           {
               int id =ui->le_rech->text().toInt();
               ui->tb_rech->setModel(A.rechercheid(id));
           }
           if (choix=="Nom")
           {
               QString Nom = ui->le_rech->text();
               ui->tb_rech->setModel(A.recherchenom(Nom));
           }
           if (choix=="Prenom")
           {
               QString Prenom = ui->le_rech->text();
               ui->tb_rech->setModel(A.rechercheprenom(Prenom));
           }




}

void MainWindow::on_pb_cal_clicked()
{

    Avocat A;


               int id =ui->le_tax->text().toInt();
 ui->tableView_2->setModel(A.rechercheid(id));

               if (A.taxes()<2)
               {
                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("taxes a payer =26% ."),QMessageBox::Cancel);

               }
               else  if (A.taxes()<3)
               {
                     QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("taxes a payer =28%."), QMessageBox::Cancel);
           }
               else  if (A.taxes()<5)
               {
                     QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("taxes a payer =32%."), QMessageBox::Cancel);
           }

               else if (A.taxes()>5)

                     QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("taxes a payer =35%."), QMessageBox::Cancel);







}


void MainWindow::on_PDF_clicked()
{
    QString strStream;
          QTextStream out(&strStream);

       const int rowCount = ui->tab_avocat->model()->rowCount();
       const int columnCount = ui->tab_avocat->model()->columnCount();
       out <<  "<html>\n"
               "<head>\n"
       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
       <<  QString("<title>%1</title>\n").arg("strTitle")
       <<  "</head>\n"
      "<body bgcolor=#ffffff link=#5000A0>\n"

      //     "<align='right'> " << datefich << "</align>"
         "<center> <H1>Liste Des RDV </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";


        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
       for (int column = 0; column < columnCount; column++)
       if (!ui->tab_avocat->isColumnHidden(column))
           out << QString("<th>%1</th>").arg(ui->tab_avocat->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";


               for (int row = 0; row < rowCount; row++) {
                out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                  for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_avocat->isColumnHidden(column)) {
         QString data = ui->tab_avocat->model()->data(ui->tab_avocat->model()->index(row, column)).toString().simplified();
         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                                       }
                                                   }
                          out << "</tr>\n";
                                               }
                                out <<  "</table> </center>\n"
                                        "</body>\n"
                                      "</html>\n";
         // QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                        //if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                       QPrinter printer (QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                       printer.setPaperSize(QPrinter::A4);
                      printer.setOutputFileName("C:\rafaa's pc\pdf");

                       QTextDocument doc;
                        doc.setHtml(strStream);
                        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                        doc.print(&printer);
}




void MainWindow::on_pushButton_clicked()
{
    Avocat A;

                 ui->tableView->setModel(A.afficher());
}
