#ifndef VISUALBST_H
#define VISUALBST_H

#include "ds/BST.h"
#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <vector>

class VisualBST : public QWidget {
    Q_OBJECT

public:
    VisualBST(QWidget *parent = nullptr);

private slots:
    void onInsert();
    void onTraversal();

private:
    void updateVisualization();
    void drawBST(BST::Node* node, int x, int y, int level, QGraphicsScene* scene);

    BST bst;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QLineEdit *valueInput;
    QComboBox *traversalCombo;
    QLabel *complexityLabel;
    int nodeRadius;
};

#endif // VISUALBST_H
