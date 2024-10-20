#include "frequency_dictionary_parser.h"

FrequencyDictionaryParser::FrequencyDictionaryParser(QObject *parent) : QObject{parent} {}


void FrequencyDictionaryParser::parseCsvContentToFreqDictionary(const QStringList &csvContent, QMap<QString, float> &freqDictionary) const {
    qsizetype index = 0;
    qsizetype linesInCsvContent = csvContent.size();
    QString currentLine;

    while (index < linesInCsvContent) {
        currentLine = csvContent.at(index);
        this->
        index++;
    }
}
