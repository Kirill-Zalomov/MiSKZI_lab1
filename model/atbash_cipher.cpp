#include "atbash_cipher.h"


AtbashCipher::AtbashCipher() {}


QString AtbashCipher::encrypt(const QString& input) {
    QString output;
    for (QChar c : input) {
        if (c.isLetter()) {
            quint32 unicode = c.unicode();
            // Шифровка строчной буквы кириллического алфавита
            if (unicode >= 0x0430 && unicode <= 0x044F) unicode = 0x087F - unicode;
            // Шифровка прописной буквы кириллического алфавита
            else if (unicode >= 0x0410 && unicode <= 0x042F) unicode = 0x083F - unicode;
            // Шифровка строчной английской буквы
            else if (unicode >= 'a' && unicode <= 'z') unicode = 'z' - (unicode - 'a');
            // Шифровка прописной английской буквы
            else if (unicode >= 'A' && unicode <= 'Z') unicode = 'Z' - (unicode - 'A');
            else if (unicode >= '0' && unicode <= '9') unicode = '9' - (unicode - '0');
            c = QChar(unicode);
        }
        output.append(c);
    }
    return output;
}


QString AtbashCipher::decrypt(const QString& ciphertext) {
    return encrypt(ciphertext);
}
