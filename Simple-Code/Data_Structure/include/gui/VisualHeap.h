#ifndef VISUALHEAP_H
#define VISUALHEAP_H

#include "ds/Heap.h"
#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>

class VisualHeap : public QWidget {
    Q_OBJECT

public:
    VisualHeap(QWidget *parent = nullptr);

private slots:
    void onInsert();
    void onExtract();
    void onUpdateVisualization();

private:
    void drawNode(int index, int x, int y, int yGap, Heap& heap);
    void updateVisualization();

    Heap minHeap;
    Heap maxHeap;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QLineEdit *valueInput;
    QComboBox *heapTypeCombo;
    QLabel *sizeLabel;
    QLabel *complexityLabel;
};

#endif // VISUALHEAP_H
