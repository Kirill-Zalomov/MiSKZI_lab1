#ifndef FREQUENCYDICTIONARYPARSER_H
#define FREQUENCYDICTIONARYPARSER_H


#include <QObject>
#include <QString>
#inlcude <QStringList>
#include <QMap>


class FrequencyDictionaryParser : public QObject {
    Q_OBJECT

public:
    explicit FrequencyDictionaryParser(QObject *parent = nullptr);
    void parseCsvContentToFreqDictionary(const QStringList &csvContent, QMap<QString, float> &freqDictionary) const;
    bool validateLineInCsvContent(const QString &content);

signals:

};

#endif // FREQUENCYDICTIONARYPARSER_H
