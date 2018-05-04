#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlTableModel>
#include <QStringList>
#include <QSqlQuery>
#include <QTreeView>
#include <QFile>
#include <QSqlError>
#include <iostream>

using namespace std;

int ExecuteSqlScriptFile(QSqlDatabase & db, const QString & fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return  0;

    QTextStream in(&file);
    QString sql = in.readAll();
    QStringList sqlStatements = sql.split(';', QString::SkipEmptyParts);
    int successCount = 0, failCount = 0;

    foreach(const QString& statement, sqlStatements)
    {
        if (statement.trimmed() != "")
        {
            cout << "entra" << endl;
            QSqlQuery query(db);
            if (query.exec(statement))
                successCount++;
            else {
                qDebug() << "Failed:" << statement << "\nReason:" << query.lastError();
                failCount++;
            }
        }
    }
    return failCount;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    db.open();

    int num = ExecuteSqlScriptFile(db, "C:/Users/Diego/Documents/VivaAvion/Crear.sql");
    int num2 = ExecuteSqlScriptFile(db, "C:/Users/Diego/Documents/VivaAvion/Insertar.sql");


    cout << num << " - " << num2 << endl;

    QSqlTableModel  tbl(0, db);
    tbl.setTable("Hotel");
    tbl.select();

    QTreeView tv;
    tv.setModel(&tbl);
    //tv.show();

    return a.exec();
}
