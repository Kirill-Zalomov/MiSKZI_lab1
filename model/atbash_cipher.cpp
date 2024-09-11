#include "atbash_cipher.h"


AtbashCipher::AtbashCipher(const QVector<int>& shifts) : _shifts(shifts) {}


QString AtbashCipher::encrypt(const QString& plaintext) {
    QString ciphertext;
    for (QChar c : plaintext) {
        int charCode = c.toLatin1();
        for (int shift : _shifts) {
            charCode = 'z' - (charCode - 'a' + shift) % 26 + 'a';
        }
        ciphertext += QChar(charCode);
    }
    return ciphertext;
}


QString AtbashCipher::decrypt(const QString& ciphertext) {
    QString plaintext;
    for (QChar c : ciphertext) {
        int charCode = c.toLatin1();
        for (int shift : _shifts) {
            charCode = 'z' - (charCode - 'a' - shift) % 26 + 'a';
        }
        plaintext += QChar(charCode);
    }
    return plaintext;
}
