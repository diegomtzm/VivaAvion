#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStringList>
#include <QFile>

using namespace std;

int ExecuteSqlScriptFile(QSqlDatabase & db, const QString & fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return  0;

    QTextStream in(&file);
    QString sql = in.readAll();
    QStringList sqlStatements = sql.split(';', QString::SkipEmptyParts);
    int successCount = 0;

    foreach(const QString& statement, sqlStatements)
    {
        if (statement.trimmed() != "")
        {
            QSqlQuery query(db);
            if (query.exec(statement))
                successCount++;
            else
                qDebug() << "Failed:" << statement << "\nReason:" << query.lastError();
        }
    }
    return successCount;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");

    if(!db.open())
       qWarning() << "ERROR: " << db.lastError();


    int num = ExecuteSqlScriptFile(db, "C:/Users/Diego/Documents/VivaAvion/Crear.sql");
    int num2 = ExecuteSqlScriptFile(db, "C:/Users/Diego/Documents/VivaAvion/Insertar.sql");


    return a.exec();
}
