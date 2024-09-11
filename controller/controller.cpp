#include "controller.h"
#include "ui_mainwindow.h"
#include "atbash_cipher.h"


Controller::Controller(QWidget *parent) : QMainWindow(parent) {
    ui = new Ui::Controller;
    ui->setupUi(this);
}

Controller::~Controller() {
    delete ui;
}


void Controller::on_pushButton_cipher_clicked() {
    QVector<int> shifts = {3, 5, 1};
    AtbashCipher cipher(shifts);

    QString sourceText = this->ui->textEdit_sourceText->toPlainText();
    QString cipherText = cipher.encrypt(sourceText);
    this->ui->textEdit_cipherText->setText(cipherText);
}


void Controller::on_pushButton_decipher_clicked() {
    QVector<int> shifts = {3, 5, 1};
    AtbashCipher cipher(shifts);

    QString cipherText = this->ui->textEdit_cipherText->toPlainText();
    QString decryptedText = cipher.decrypt(cipherText);
    this->ui->textEdit_sourceText->setText(decryptedText);
}

