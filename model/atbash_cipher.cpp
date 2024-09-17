#include "atbash_cipher.h"


AtbashCipher::AtbashCipher(QObject *parent) : QObject(parent) {}


QString AtbashCipher::encrypt(const QString& input, const qint8& key) const {
    const QString russianAlphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const QString secondAlphabet = "!@#$%^&*()_+-=\\|~`[]{};:'\",<>?/№\t";

    QString output;

    for (qint32 i = 0; i < input.length(); i++) {
        QChar currentSymbol = input[i];
        if (russianAlphabet.contains(currentSymbol)) {
            int index = russianAlphabet.indexOf(currentSymbol);
            int encryptedIndex = russianAlphabet.length() - index - 1;
            // Apply the second alphabet complication with key-based shifting
            int shiftedIndex = (encryptedIndex + key) % secondAlphabet.length();
            output += secondAlphabet[shiftedIndex];
        } else if (currentSymbol == ' ') {
            output += ' ';
        } else if (currentSymbol == '.') {
            output += '.';
        }
    }

    return output;
}


inline QString AtbashCipher::decrypt(const QString& input, const qint8& key) const {

}
