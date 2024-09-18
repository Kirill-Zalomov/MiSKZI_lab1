#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H


#include <QObject>
#include <QByteArray>


const static QString russianAlphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
const static QString secondAlphabet = "!@#$%^&*()_+-=\\|~`[]{};:'\",<>?/№\t";


class AtbashCipher : public QObject {
    Q_OBJECT

public:
    explicit AtbashCipher(QObject *parent = nullptr);
    QString encrypt(const QString& input, const quint8& key) const;
    QString decrypt(const QString& input, const quint8& key) const;
};


#endif /* ATBASH_CIPHER_H */
