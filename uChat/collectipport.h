#ifndef COLLECTIPPORT_H
#define COLLECTIPPORT_H

#include <QWidget>
#include <QCloseEvent>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QDateTime>
#include <QHeaderView>
#include <QTimer>

namespace Ui {
class CollectIpPort;
}

class CollectIpPort : public QWidget
{
    Q_OBJECT

public:
    explicit CollectIpPort(QWidget *parent = nullptr);
    ~CollectIpPort();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void initializeTableWidget();
    void onSelectAllToggled(int state);
    void setupTable();
    void addEntry();
    void removeSelectedEntries();
    void initializeUI();
    void connectSignals(bool withLineEdit = true, bool withTable = true);
    void toggleAllCheckBoxes();
    void handleCellClick(int row, int column);
    void on_leClientIpList_textChanged(const QString &text);
    void on_leClientIpList_textChanged_Numeric(const QString &text);  // 추가된 부분
    void on_leClientPortList_textChanged(const QString &text);
    void showIpPortInMainWindow();

public slots:
    void updateTable();
    void clearInputs();
    void setIp(const QString &ip);
    void setPort(const QString &port);
    void updateStatusDisplay(int row, const QString &status);
    void toggleConnectionStatus(int row);

signals:
    void ipPortSelected(const QString &ip, const QString &port);

private:
    Ui::CollectIpPort *ui;
    QTableWidget *tableWidget;
    QLineEdit *leClientIpList;
    QLineEdit *leClientPortList;
    QPushButton *pAdd;
    QPushButton *pRemove;
    QCheckBox *selectAllCheckBox;
    bool *allChecked;
    QTimer *displayTimer;
    QString displayIp;
    QString displayPort;
};

#endif // COLLECTIPPORT_H
