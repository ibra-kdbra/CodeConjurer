#ifndef VISUALCIRCULARQUEUE_H
#define VISUALCIRCULARQUEUE_H

#include "ds/CircularQueue.h"
#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class VisualCircularQueue : public QWidget {
    Q_OBJECT

public:
    VisualCircularQueue(QWidget *parent = nullptr);

private slots:
    void onEnqueue();
    void onDequeue();
    void updateVisualization();

private:
    CircularQueue queue;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QLineEdit *valueInput;
};

#endif // VISUALCIRCULARQUEUE_H
