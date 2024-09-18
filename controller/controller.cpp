#include "controller.h"
#include "ui_mainwindow.h"
#include "atbash_cipher.h"


Controller::Controller(QWidget *parent) : QMainWindow(parent) {
    ui = new Ui::Controller;
    ui->setupUi(this);

    this->moveWindowToCenterOfDisplay();
}


Controller::~Controller() {
    delete ui;
}


void Controller::moveWindowToCenterOfDisplay() {
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect rect = screen->geometry();
    QPoint centerPoint = rect.center();
    centerPoint.setX(centerPoint.x() - (this->width() / 2));
    centerPoint.setY(centerPoint.y() - this->height() / 2);
    this->move(centerPoint);
}


void Controller::on_pushButton_cipher_clicked() {
    if (!this->isBothFilesSelected()) {
        this->setStatusBarText("Укажите два файла перед шифрованием.");
        return;
    }

    AtbashCipher cipher {};
    FileInteractor fileInteractor{};
    quint8 encryptionKey = static_cast<quint8>(this->ui->spinBox_encryptionKey->value());

    QString encryptedText = cipher.encrypt(fileInteractor.readContentFromFile(this->ui->lineEdit_sourceFilePath->text()), encryptionKey);
    if (encryptedText.isEmpty()) return;

    QString pathToResultFile = this->ui->lineEdit_resultFilePath->text();
    if (this->ui->checkBox_addEncExtension->checkState() == Qt::Checked) {
        fileInteractor.deleteFile(pathToResultFile);
        pathToResultFile += ".enc";
    }

    fileInteractor.writeContentInFile(pathToResultFile, encryptedText, true);
    this->setStatusBarText("Исходный файл успешно зашифрован.");
}


void Controller::on_pushButton_decipher_clicked() {
    if (!this->isBothFilesSelected()) {
        this->setStatusBarText("Укажите два файла перед расшифрованием.");
        return;
    }

    AtbashCipher cipher {};
    FileInteractor fileInteractor{};
    quint8 decryptionKey = static_cast<quint8>(this->ui->spinBox_encryptionKey->value());

    QString decryptedText = cipher.decrypt(fileInteractor.readContentFromFile(this->ui->lineEdit_sourceFilePath->text()), decryptionKey);
    if(decryptedText.isEmpty()) return;

    QString pathToResultFile = this->ui->lineEdit_resultFilePath->text();
    if (this->ui->checkBox_addEncExtension->checkState() == Qt::Checked) {
        fileInteractor.deleteFile(pathToResultFile);
        pathToResultFile += ".dec";
    }

    fileInteractor.writeContentInFile(pathToResultFile, decryptedText, true);
    this->setStatusBarText("Исходный файл расшифрован.");
}


void Controller::on_button_chooseSourceFile_clicked() {
    QString selectedFilePath;
    selectedFilePath = QFileDialog::getOpenFileName(this, "Выбор файл", QStandardPaths::writableLocation(QStandardPaths::HomeLocation), "Все файлы (*)");
    if(selectedFilePath.isEmpty()) return;

    this->ui->lineEdit_sourceFilePath->setText(selectedFilePath);
    this->setStatusBarText("Выбран исходный файл.");
}


void Controller::on_button_chooseResultFile_clicked() {
    QString selectedFilePath;
    selectedFilePath = QFileDialog::getOpenFileName(this, "Выбор файл", QStandardPaths::writableLocation(QStandardPaths::HomeLocation), "Все файлы (*)");
    if(selectedFilePath.isEmpty()) return;

    this->ui->lineEdit_resultFilePath->setText(selectedFilePath);
    this->setStatusBarText("Выбран файл результата.");
}


bool Controller::isBothFilesSelected() {
    return !this->ui->lineEdit_resultFilePath->text().isEmpty() &&
           !this->ui->lineEdit_sourceFilePath->text().isEmpty();
}


inline void Controller::setStatusBarText(const QString &text) {
    this->ui->label_statusBar->setText("Строка состояния: " + text);
}
