#include "gui/VisualHeap.h"
#include "gui/StyleManager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <cmath>

VisualHeap::VisualHeap(QWidget *parent) : QWidget(parent), minHeap(true), maxHeap(false) {
    // Get style manager
    StyleManager* style = StyleManager::instance();

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);
    view->setMinimumHeight(400);
    view->setStyleSheet(QString("QGraphicsView { border: 2px solid %1; border-radius: %2px; background-color: %3; }")
                       .arg(style->borderColor().name())
                       .arg(style->borderRadius())
                       .arg(style->surfaceColor().name()));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(style->spacing());
    layout->setContentsMargins(style->margin(), style->margin(), style->margin(), style->margin());

    QHBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->setSpacing(style->spacing());

    heapTypeCombo = new QComboBox();
    heapTypeCombo->addItem("Min Heap");
    heapTypeCombo->addItem("Max Heap");
    heapTypeCombo->setFixedHeight(style->buttonHeight());
    heapTypeCombo->setStyleSheet(style->comboBoxStyle());
    heapTypeCombo->setMinimumWidth(120);
    controlsLayout->addWidget(heapTypeCombo);

    valueInput = new QLineEdit();
    valueInput->setPlaceholderText("Enter value...");
    valueInput->setFixedHeight(style->buttonHeight());
    valueInput->setStyleSheet(style->inputStyle());
    controlsLayout->addWidget(valueInput);

    QPushButton *insertBtn = new QPushButton("➕ Insert");
    insertBtn->setFixedHeight(style->buttonHeight());
    insertBtn->setStyleSheet(style->buttonStyle());
    insertBtn->setCursor(Qt::PointingHandCursor);
    connect(insertBtn, &QPushButton::clicked, this, &VisualHeap::onInsert);
    controlsLayout->addWidget(insertBtn);

    QPushButton *extractBtn = new QPushButton("➖ Extract");
    extractBtn->setFixedHeight(style->buttonHeight());
    extractBtn->setStyleSheet(style->buttonStyle());
    extractBtn->setCursor(Qt::PointingHandCursor);
    connect(extractBtn, &QPushButton::clicked, this, &VisualHeap::onExtract);
    controlsLayout->addWidget(extractBtn);

    sizeLabel = new QLabel("Size: 0|0");
    sizeLabel->setStyleSheet(style->labelStyle() + "font-style: italic;");
    controlsLayout->addWidget(sizeLabel);

    complexityLabel = new QLabel("O(log n) operations");
    complexityLabel->setStyleSheet(style->labelStyle() + "font-style: italic; color: " + style->accentColor().name() + ";");

    controlsLayout->addWidget(new QWidget()); // Spacer
    controlsLayout->addWidget(complexityLabel);

    layout->addLayout(controlsLayout);
    layout->addWidget(view);

    // Connect heap type change
    connect(heapTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &VisualHeap::onUpdateVisualization);

    // Connect theme changes
    connect(style, &StyleManager::themeChanged, this, &VisualHeap::updateVisualization);

    updateVisualization();
}

void VisualHeap::onInsert() {
    bool ok;
    int val = valueInput->text().toInt(&ok);
    if (ok) {
        if (heapTypeCombo->currentIndex() == 0) { // Min Heap
            minHeap.insert(val);
        } else { // Max Heap
            maxHeap.insert(val);
        }
        updateVisualization();
        valueInput->clear();
    }
}

void VisualHeap::onExtract() {
    try {
        if (heapTypeCombo->currentIndex() == 0) { // Min Heap
            if (!minHeap.empty()) {
                minHeap.extract();
            }
        } else { // Max Heap
            if (!maxHeap.empty()) {
                maxHeap.extract();
            }
        }
        updateVisualization();
    } catch (const std::logic_error&) {
        // Heap empty, ignore
    }
}

void VisualHeap::onUpdateVisualization() {
    updateVisualization();
}

void VisualHeap::updateVisualization() {
    scene->clear();

    StyleManager* style = StyleManager::instance();
    Heap& currentHeap = (heapTypeCombo->currentIndex() == 0) ? minHeap : maxHeap;

    if (currentHeap.empty()) {
        QGraphicsTextItem *emptyText = scene->addText("Heap is Empty\nSelect heap type and click Insert to add items!");
        emptyText->setPos(200, 180);
        emptyText->setDefaultTextColor(style->textColorSecondary());
        emptyText->setFont(QFont("Segoe UI", 14, QFont::Bold));
        return;
    }

    const int levelHeight = 80;
    const int baseWidth = 600;
    const int baseHeight = 50;

    // Draw heap tree structure using BFS-like approach
    drawNode(0, baseWidth/2, baseHeight, levelHeight, currentHeap);

    // Add heap type indicator
    QString heapTypeText = (heapTypeCombo->currentIndex() == 0) ? "MIN HEAP" : "MAX HEAP";
    QGraphicsTextItem *typeLabel = scene->addText(heapTypeText + " (Root: " +
        QString::number(currentHeap.top()) + ")");
    typeLabel->setPos(50, 10);
    typeLabel->setDefaultTextColor(style->primaryColor());
    typeLabel->setFont(QFont("Segoe UI", 12, QFont::Bold));

    // Update size display
    sizeLabel->setText(QString("Min: %1 | Max: %2").arg(minHeap.size()).arg(maxHeap.size()));
}

void VisualHeap::drawNode(int index, int x, int y, int yGap, Heap& heap) {
    if (index >= (int)heap.heap.size()) {
        return;
    }

    StyleManager* style = StyleManager::instance();
    const int nodeRadius = 25;

    // Draw node ellipse
    QGraphicsEllipseItem *node = scene->addEllipse(x - nodeRadius, y - nodeRadius,
                                                  2 * nodeRadius, 2 * nodeRadius);
    node->setBrush(QBrush(style->primaryColor()));
    node->setPen(QPen(style->textColor(), 2));

    // Draw value
    QGraphicsTextItem *text = scene->addText(QString::number(heap.heap[index]));
    text->setPos(x - 15, y - 15);
    text->setDefaultTextColor(style->backgroundColor());
    text->setFont(QFont("Segoe UI", 11, QFont::Bold));

    // Draw connections to children
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < (int)heap.heap.size()) {
        int childX = x - 150 / (1 << (int)(log2(index + 1) + 1));
        int childY = y + yGap;

        QGraphicsLineItem *line = scene->addLine(x, y + nodeRadius,
                                              childX, childY - nodeRadius);
        line->setPen(QPen(style->accentColor(), 2));

        drawNode(leftChild, childX, childY, yGap, heap);
    }

    if (rightChild < (int)heap.heap.size()) {
        int childX = x + 150 / (1 << (int)(log2(index + 1) + 1));
        int childY = y + yGap;

        QGraphicsLineItem *line = scene->addLine(x, y + nodeRadius,
                                              childX, childY - nodeRadius);
        line->setPen(QPen(style->accentColor(), 2));

        drawNode(rightChild, childX, childY, yGap, heap);
    }
}
