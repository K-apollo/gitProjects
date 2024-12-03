#include "server.h"

Server::Server(QObject *parent) :
    QObject(parent),
    tcpServer(new QTcpServer(this)),
    udpSocket(new QUdpSocket(this))
{
    setupConnections();
}

void Server::setupConnections()
{
    connect(tcpServer, &QTcpServer::newConnection, this, [this]() { handleNewConnection(); });
}

void Server::startServer(const QString &type, const QList<QPair<QString, int>>& clientList)
{
    connectionType = type;
    stopServer();

    if (connectionType == "TCP/IP")
    {
        for (const auto &client : clientList)
        {
            if (tcpServer->listen(QHostAddress(client.first), client.second))
                emit statusMessage(QString("[TCP/IP] 서버 연결 시작: %1:%2").arg(client.first).arg(client.second));
            else
                emit statusMessage(QString("[TCP/IP] 서버 연결 실패: %1:%2").arg(client.first).arg(client.second));
        }
    }
    else if (connectionType == "UDP")
    {
        for (const auto &client : clientList)
        {
            if (udpSocket->bind(QHostAddress(client.first), client.second))
                emit statusMessage(QString("[UDP] 서버 연결 시작: %1:%2").arg(client.first).arg(client.second));
            else
                emit statusMessage(QString("[UDP] 서버 연결 실패: %1:%2").arg(client.first).arg(client.second));
        }
    }
}

void Server::stopServer()
{
    if (tcpServer->isListening())
    {
        tcpServer->close();
        for (QTcpSocket *socket : qAsConst(clientSockets))
        {
            socket->disconnectFromHost();
            socket->deleteLater();
        }
        clientSockets.clear();
        emit statusMessage("서버 연결 종료");
    }
    udpSocket->close();
}

QString Server::getConnectionType() const
{
    return connectionType;
}

void Server::handleNewConnection()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    clientSockets.append(clientSocket);

    emit statusMessage(QString("새로운 클라이언트 연결: %1:%2")
                           .arg(clientSocket->peerAddress().toString())
                           .arg(clientSocket->peerPort()));

    connect(clientSocket, &QTcpSocket::readyRead, this, [this]() { readClientData(); });
    connect(clientSocket, &QTcpSocket::disconnected, this, [this, clientSocket]() {
        clientSockets.removeAll(clientSocket);
        clientSocket->deleteLater();
        emit statusMessage("클라이언트 연결 해제");
    });
}

void Server::readClientData()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if (clientSocket)
    {
        QString receivedData = clientSocket->readAll();
        emit statusMessage(QString("클라이언트로부터 받은 데이터: %1").arg(receivedData));
    }
}
