#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QLabel>
#include <QWidgetAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* label = new QLabel("menu", &mMenu);
    label->setAlignment(Qt::AlignCenter);
    label->setMinimumHeight(30);

    QFont font("Arial", 11, 1);
    font.setBold(true);
    label->setFont(font);

    QWidgetAction* action = new QWidgetAction(&mMenu);
    action->setDefaultWidget(label);

    mMenu.addAction(action);
    mMenu.addAction("Hello");
    mMenu.addAction("World");
    mMenu.addAction("Thank you");

    mMenu.setStyleSheet("QMenu::item {"
                            "padding: 5px 5px 2px 2px;"
                            "}"
                            "QMenu::item:selected {"
                            "background-color: rgb(0, 85, 127);"
                            "color: rgb(255, 255, 255);"
                            "}"
                            "QMenu::item:disabled {"
                            "color: black;"
                            "font-size:14px"
                            "};"
                        );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton) {
        QPoint pt;
        pt.setX(event->globalX());
        pt.setY(event->globalY());

        mMenu.popup(pt);
    }
}

