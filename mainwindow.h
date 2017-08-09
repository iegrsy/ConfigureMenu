#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QListWidgetItem>

#include <QJsonParseError>
#include <QDragEnterEvent>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_lstMenu_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QJsonDocument jDoc;

    QString readFile(QString path);
    void readJson(QString str);
    QStringList jObjToListMenu(QJsonObject jObj);
};

#endif // MAINWINDOW_H
