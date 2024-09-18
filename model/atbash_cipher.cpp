#include "atbash_cipher.h"


AtbashCipher::AtbashCipher(QObject *parent) : QObject(parent) {}


QString AtbashCipher::encrypt(const QString& input, const qint8& key) const {
    QString output;

    for (qint32 i = 0; i < input.length(); i++) {
        QChar currentSymbol = input[i];
        if (russianAlphabet.contains(currentSymbol)) {
            int index = russianAlphabet.indexOf(currentSymbol);
            int encryptedIndex = russianAlphabet.length() - index - 1;
            int shiftedIndex = (encryptedIndex + key) % secondAlphabet.length();
            output += secondAlphabet[shiftedIndex];
        }
        else {
            output += currentSymbol;
        }
    }

    return output;
}


QString AtbashCipher::decrypt(const QString& input, const qint8& key) const {
    QString output;

    for (qint32 i = 0; i < input.length(); i++) {
        QChar currentSymbol = input[i];
        if (secondAlphabet.contains(currentSymbol)) {
            int index = secondAlphabet.indexOf(currentSymbol);
            int encryptedIndex = secondAlphabet.length() - index - 1;
            int shiftedIndex = (encryptedIndex + key) % secondAlphabet.length();
            output += russianAlphabet[shiftedIndex];
        }
        else {
            output += currentSymbol;
        }
    }

    return output;
}
