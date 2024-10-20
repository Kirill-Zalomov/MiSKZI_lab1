#ifndef FREQUENCYANALYZER_H
#define FREQUENCYANALYZER_H


#include <QObject>
#include <QMap>
#include <QString>
#include <QVector>


class FrequencyAnalyzer : public QObject {
    Q_OBJECT

public:
    explicit FrequencyAnalyzer(QObject *parent = nullptr);

};


#endif // FREQUENCYANALYZER_H
