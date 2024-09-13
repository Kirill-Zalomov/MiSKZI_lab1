#include "atbash_cipher.h"


AtbashCipher::AtbashCipher() {}


QString AtbashCipher::encrypt(const QString& plaintext) {
    QString ciphertext;
    for (QChar c : plaintext) {
        if (c.isLetter()) {
            char base = c.isUpper() ? 'A' : 'a';
            ciphertext += QChar(base + 25 - (c.toLatin1() - base));
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}


QString AtbashCipher::decrypt(const QString& ciphertext) {
    return encrypt(ciphertext);
}
