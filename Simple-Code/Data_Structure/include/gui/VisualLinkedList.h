#ifndef VISUALLINKEDLIST_H
#define VISUALLINKEDLIST_H

#include "ds/SinglyLinkedList.h"
#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>

class VisualLinkedList : public QWidget {
    Q_OBJECT

public:
    VisualLinkedList(QWidget *parent = nullptr);

public slots:
    void exportData();
    void importData();
    void clearList();

private slots:
    void onPush();
    void onPop();
    void onInsertAfter();
    void onPrint();

private:
    void updateVisualization();
    void drawNode(int value, int x, int y);

    List list;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QLineEdit *valueInput;
    QSpinBox *afterValueSpin;
    QLabel *complexityLabel;
};

#endif // VISUALLINKEDLIST_H
