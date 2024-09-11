#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H


#include <QString>
#include <QVector>


class AtbashCipher {
public:
    AtbashCipher(const QVector<int>& shifts);
    QString encrypt(const QString& plaintext);
    QString decrypt(const QString& ciphertext);

private:
    QVector<int> _shifts;
};


#endif /* ATBASH_CIPHER_H */
