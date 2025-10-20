#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QStatusBar>

class VisualLinkedList;
class VisualHeap;
class VisualStack;
class VisualCircularQueue;
class VisualBST;
class VisualTrie;
class VisualQueueViaStacks;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onDSChanged(int index);
    void onThemeChanged(int index);
    void updateAllWidgets();
    void updateStyle();

private slots:
    void onClearDataStructure();

private:
    void updateStatusBar();
    int getCurrentDataSize();
    QToolBar* createOperationsToolBar();
    void showAboutDialog();

    QComboBox *dsComboBox;
    QComboBox *themeComboBox;
    QStackedWidget *views;
    QStatusBar *statusBar;
    QLabel *dsStatusLabel;
    QLabel *memoryLabel;
    QLabel *operationsLabel;
    int operationCount;

    VisualLinkedList *linkedListView;
    VisualHeap *visualHeap;
    VisualStack *visualStack;
    VisualCircularQueue *visualCircularQueue;
    VisualBST *visualBST;
    VisualTrie *visualTrie;
    VisualQueueViaStacks *visualQueueViaStacks;
};

#endif // MAINWINDOW_H
