#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QList>
#include <QDebug>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_3->setEnabled(false);
    connect (this, SIGNAL( singleFileLoad() ), this, SLOT( matchFiles() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "..",
                                                    tr("Text (*.txt)"));
    ui->lineEdit->setText(fileName);

    emit singleFileLoad();

}

void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "..",
                                                    tr("Text (*.txt)"));
    ui->lineEdit_2->setText(fileName);
    emit singleFileLoad();
}

bool MainWindow::matchFiles()
{
    if (ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "")
    {
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_3->setToolTip(0);
    }
    return 1;
}

void MainWindow::on_pushButton_3_clicked()
{
    QFile file1 (ui->lineEdit->text() );
    if(!file1.open(QIODevice::ReadWrite | QIODevice::Text))
    {
         qDebug()<<"Can't open the file1!"<<endl;
         return;
    }
    else
    {
         qDebug()<<"Open file1 OK!"<<endl;
    }



    QFile file2 (ui->lineEdit_2->text() );
    if(!file2.open(QIODevice::ReadWrite | QIODevice::Text))
    {
         qDebug()<<"Can't open the file2!";
         return;
    }
    else
    {
         qDebug()<<"Open file2 OK!";
    }


    QString filename001 = ui->lineEdit->text();
    QString filename002 = ui->lineEdit_2->text();

    QString backfilename001 = filename001.left(filename001.length() - 4) + ".bak";
    QString backfilename002 = filename002.left(filename002.length() - 4) + ".bak";

    QFile backfile001(backfilename001);
    if ( backfile001.exists() )
    {
        QFile::remove( backfilename001);
    }


    if( !QFile::copy(filename001, backfilename001 ) )
    {
        qDebug() << "back file1 failed";
    }
    else
    {
        qDebug() << "back file1 OK";
    }


    QFile backfile002(backfilename002);
    if ( backfile002.exists() )
    {
        QFile::remove( backfilename002);
    }


    if( !QFile::copy(filename002, backfilename002 ) )
    {
        qDebug() << "back file2 failed";
    }
    else
    {
        qDebug() << "back file2 OK";
    }



    QTextStream in1(&file1);
    QTextStream in2(&file2);

    QList <QString> list1;
    QList <QString> list3;

    bool needtochange1 = false;
    bool needtochange2 = false;



    QString pattern("([ \t])*");
    QRegExp rx(pattern);


    while ( !in1.atEnd() )
    {
        QString linefile1 = in1.readLine();
        if ( rx.exactMatch(linefile1) )
        {
            needtochange1 = true;
            continue;
        }
        else
        {
            qDebug() << linefile1;
            list1.push_back(linefile1);
        }

    }


    while ( !in2.atEnd() )
    {
        QString linefile2 = in2.readLine();
        if ( rx.exactMatch(linefile2) )
        {
            needtochange2 = true;
            continue;
        }
        else
        {
            qDebug() << linefile2;
            list3.push_back(linefile2);
        }

    }

    for (QList <QString>::iterator it1 = list1.begin(); it1 != list1.end(); it1++)
    {
        for (QList <QString>::iterator it2 = list3.begin(); it2 != list3.end(); it2++)
        {
            if (*it1 == *it2)
            {
                needtochange1 = true;
                needtochange2 = true;
                list1.erase(it1);
                it1--;
                list3.erase(it2);
                it2--;
            }
        }
    }

    file1.close();
    file2.close();

    if (needtochange1)
    {
        qDebug()<<"ready to rewrite file1!"<<endl;
        QFile file001 ( ui->lineEdit->text() );
        if(!file001.open(QIODevice::WriteOnly | QIODevice::Text))
        {
                        qDebug()<<"Can't ReWrite the file!"<<endl;
        }
        else
        {
            QTextStream in001(&file001);
            for (QList <QString>::const_iterator it1 = list1.begin(); it1 != list1.end(); it1++)
            {
                in001 << *it1;
            }
        }

        file001.close();
    }

    if (needtochange2)
    {
        qDebug()<<"ready to rewrite file2!"<<endl;
        QFile file002 ( ui->lineEdit_2->text() );
        if(!file002.open(QIODevice::WriteOnly | QIODevice::Text))
        {
                        qDebug()<<"Can't ReWrite the file!"<<endl;
        }
        else
        {
            QTextStream in002(&file002);
            for (QList <QString>::const_iterator it2 = list3.begin(); it2 != list3.end(); it2++)
            {
                in002 << *it2;
            }
        }
        file002.close();
    }
    ui->pushButton_3->setEnabled(false);
}
