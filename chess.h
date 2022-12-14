#ifndef CHESS_H
#define CHESS_H

#include <QObject>

class Chess : public QObject
{
    Q_OBJECT
public:
    explicit Chess(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CHESS_H