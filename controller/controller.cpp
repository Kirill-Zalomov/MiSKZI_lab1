#include "controller.h"
#include "ui_mainwindow.h"
#include "atbash_cipher.h"


Controller::Controller(QWidget *parent) : QMainWindow(parent) {
    ui = new Ui::Controller;
    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen->geometry();
    QPoint centerPoint = rect.center();
    centerPoint.setX(centerPoint.x() - (this->width() / 2));
    centerPoint.setY(centerPoint.y() - this->height() / 2);
    this->move(centerPoint);
}


Controller::~Controller() {
    delete ui;
}


void Controller::on_pushButton_cipher_clicked() {
    AtbashCipher cipher {};
    FileInteractor fileInteractor{};

    qDebug() << this->ui->lineEdit_sourceFilePath->text() << "\n";
    qDebug() << fileInteractor.readContentFromFile(this->ui->lineEdit_sourceFilePath->text()) << "\n";
    qDebug() << cipher.encrypt(fileInteractor.readContentFromFile(this->ui->lineEdit_sourceFilePath->text()), 0xFE) << "\n";
}


void Controller::on_pushButton_decipher_clicked() {
    AtbashCipher cipher {};

}


void Controller::on_button_chooseSourceFile_clicked() {
    QString selectedFilePath;
    selectedFilePath = QFileDialog::getOpenFileName(this, "Выбор файл", QStandardPaths::writableLocation(QStandardPaths::HomeLocation), "Все файлы (*)");
    if(selectedFilePath.isEmpty()) return;

    this->ui->lineEdit_sourceFilePath->setText(selectedFilePath);
}


void Controller::on_button_chooseResultFile_clicked() {
    QString selectedFilePath;
    selectedFilePath = QFileDialog::getOpenFileName(this, "Выбор файл", QStandardPaths::writableLocation(QStandardPaths::HomeLocation), "Все файлы (*)");
    if(selectedFilePath.isEmpty()) return;

    this->ui->lineEdit_resultFilePath->setText(selectedFilePath);
}

