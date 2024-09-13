#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H


#include <QString>
#include <QChar>


class AtbashCipher {
public:
    AtbashCipher();
    QString encrypt(const QString& plaintext);
    QString decrypt(const QString& ciphertext);
};


#endif /* ATBASH_CIPHER_H */
