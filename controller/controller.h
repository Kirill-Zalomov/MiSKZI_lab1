#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QScreen>


#include "atbash_cipher.h"
#include "file_interactor.h"
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class Controller; }
QT_END_NAMESPACE


class Controller : public QMainWindow
{
    Q_OBJECT

public:
    Controller(QWidget *parent = nullptr);
    ~Controller();

private slots:
    void on_pushButton_cipher_clicked();
    void on_pushButton_decipher_clicked();
    void on_button_chooseSourceFile_clicked();
    void on_button_chooseResultFile_clicked();

private:
    Ui::Controller *ui;
};


#endif // CONTROLLER_H
