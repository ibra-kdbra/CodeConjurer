#ifndef VISUALQUEUEVIASTACKS_H
#define VISUALQUEUEVIASTACKS_H

#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsScene>
#include <stack>

class StyleManager;

class VisualQueueViaStacks : public QWidget {
    Q_OBJECT

public:
    VisualQueueViaStacks(QWidget *parent = nullptr);

private slots:
    void onEnqueue();
    void onDequeue();
    void onFront();

private:
    void updateVisualization();
    void drawStack(const QString& stackName, std::stack<int> stk, int x, int y, StyleManager* style);
    void drawQueueRepresentation(int x, int y, StyleManager* style);

    std::stack<int> s1, s2;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QLineEdit *valueInput;
    QLabel *complexityLabel;
};

#endif // VISUALQUEUEVIASTACKS_H
