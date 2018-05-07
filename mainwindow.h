#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_VerVuelos_clicked();

    void on_VerReservas_clicked();

    void on_VerHoteles_clicked();

    void on_VerVuelosAdmin_clicked();

    void on_VerHotelesAdmin_clicked();

    void on_VerVuelos_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
