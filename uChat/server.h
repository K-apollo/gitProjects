#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QList>
#include <QPair>

class Server : public QObject
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    void startServer(const QString &connectionType, const QList<QPair<QString, int>>& clientList);
    void stopServer();
    QString getConnectionType() const;

signals:
    void statusMessage(const QString &message);

private:
    void setupConnections();
    void handleNewConnection();
    void readClientData();

    QTcpServer *tcpServer;
    QUdpSocket *udpSocket;
    QString connectionType;
    QList<QTcpSocket*> clientSockets;
};

#endif // SERVER_H
