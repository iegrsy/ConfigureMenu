#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    QString jfilepath = "/home/ieg/qt/qtProjects/ConfigurationSetting/settings.json";
    QString jstr = readFile(jfilepath);
    readJson(jstr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::readFile(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return 0;

    QString jdata = file.readAll().data();
    file.close();

    return jdata;
}

void MainWindow::readJson(QString str)
{
    if(str.isEmpty())
        return;

    jDoc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jObj = jDoc.object();
    ui->lstMenu->addItems(jObjToListMenu(jObj));

}

QStringList MainWindow::jObjToListMenu(QJsonObject jObj)
{
    QStringList itemList;

    foreach (QString s, jObj.keys())
    {
        itemList.append(s);

        QJsonObject jo = jObj[s].toObject();
        QJsonArray jAr;
        foreach (QString s, jo.keys()) {
            if(s.at(0) == '_' && jo[s].isArray())
            {
                jAr = jo[s].toArray();

                for(int i = 0; i < jAr.count(); i++)
                {
                    QJsonObject o = jAr[i].toObject();
                    itemList.append(o["name"].toString());
                }
            }
        }
    }
    return itemList;
}




void MainWindow::on_lstMenu_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug()<<item->text();
}

























