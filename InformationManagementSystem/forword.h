#ifndef FORWORLD_H
#define FORWORLD_H

#include <QObject>

class ForWord : public QObject
{
    Q_OBJECT
public:
    explicit ForWord(QObject *parent = nullptr);
    void creatWord();
signals:

public slots:
};

#endif // FORWORLD_H
