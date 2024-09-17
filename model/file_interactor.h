#ifndef FILEINTERACTOR_H
#define FILEINTERACTOR_H


#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


class FileInteractor : public QObject {
    Q_OBJECT
public:
    explicit FileInteractor(QObject *parent = nullptr);
    QString readContentFromFile(const QString& filepath) const;
    bool writeContentInFile(const QString &filePath, const QString &content, const bool &rewrite) const;
};


#endif // FILEINTERACTOR_H
