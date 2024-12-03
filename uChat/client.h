#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <QPushButton>
#include <QRadioButton>
#include <QMainWindow>

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    void testIpPort();

private:
    int portNumber;
    QString ipAddress;
    QRadioButton *radioButtonClientTcpIp;
    QRadioButton *radioButtonClientUdp;

    void initializeClient();
};

#endif // CLIENT_H
