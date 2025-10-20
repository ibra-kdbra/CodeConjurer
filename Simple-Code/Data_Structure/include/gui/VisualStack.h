#ifndef VISUALSTACK_H
#define VISUALSTACK_H

#include "ds/Stack.h"
#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsScene>

class VisualStack : public QWidget {
    Q_OBJECT

public:
    VisualStack(QWidget *parent = nullptr);

public slots:
    void clearStack();

private slots:
    void onPush();
    void onPop();
    void onPeek();

private:
    void updateVisualization();

    Stack stack;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QLineEdit *valueInput;
    QLabel *sizeLabel;
    QLabel *complexityLabel;
};

#endif // VISUALSTACK_H
