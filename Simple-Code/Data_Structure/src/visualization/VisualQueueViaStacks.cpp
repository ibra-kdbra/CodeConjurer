#include "gui/VisualQueueViaStacks.h"
#include "gui/StyleManager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <vector>

VisualQueueViaStacks::VisualQueueViaStacks(QWidget *parent) : QWidget(parent), s1(), s2() {
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

    valueInput = new QLineEdit();
    valueInput->setPlaceholderText("Enter value...");
    valueInput->setFixedHeight(style->buttonHeight());
    valueInput->setStyleSheet(style->inputStyle());
    controlsLayout->addWidget(valueInput);

    QPushButton *enqueueBtn = new QPushButton("➡️ Enqueue");
    enqueueBtn->setFixedHeight(style->buttonHeight());
    enqueueBtn->setStyleSheet(style->buttonStyle());
    enqueueBtn->setCursor(Qt::PointingHandCursor);
    connect(enqueueBtn, &QPushButton::clicked, this, &VisualQueueViaStacks::onEnqueue);
    controlsLayout->addWidget(enqueueBtn);

    QPushButton *dequeueBtn = new QPushButton("⬅️ Dequeue");
    dequeueBtn->setFixedHeight(style->buttonHeight());
    dequeueBtn->setStyleSheet(style->buttonStyle());
    dequeueBtn->setCursor(Qt::PointingHandCursor);
    connect(dequeueBtn, &QPushButton::clicked, this, &VisualQueueViaStacks::onDequeue);
    controlsLayout->addWidget(dequeueBtn);

    QPushButton *frontBtn = new QPushButton("👁️ Front");
    frontBtn->setFixedHeight(style->buttonHeight());
    frontBtn->setStyleSheet(style->buttonStyle());
    frontBtn->setCursor(Qt::PointingHandCursor);
    connect(frontBtn, &QPushButton::clicked, this, &VisualQueueViaStacks::onFront);
    controlsLayout->addWidget(frontBtn);

    QLabel *statusLabel = new QLabel("Size: 0");
    statusLabel->setStyleSheet(style->labelStyle() + "font-style: italic;");
    controlsLayout->addWidget(statusLabel);

    complexityLabel = new QLabel("Enqueue O(1), Dequeue amortized O(1)");
    complexityLabel->setStyleSheet(style->labelStyle() + "font-style: italic; color: " + style->accentColor().name() + ";");

    controlsLayout->addWidget(new QWidget()); // Spacer
    controlsLayout->addWidget(complexityLabel);

    layout->addLayout(controlsLayout);
    layout->addWidget(view);

    // Connect theme changes
    connect(style, &StyleManager::themeChanged, this, &VisualQueueViaStacks::updateVisualization);

    updateVisualization();
}

void VisualQueueViaStacks::onEnqueue() {
    bool ok;
    int val = valueInput->text().toInt(&ok);
    if (ok) {
        s1.push(val);  // Always push to s1 for enqueue
        updateVisualization();
        valueInput->clear();
    }
}

void VisualQueueViaStacks::onDequeue() {
    if (s1.empty() && s2.empty()) {
        // Queue is empty
        return;
    }

    // If s2 is empty, move all elements from s1 to s2
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    // Now dequeue from s2
    if (!s2.empty()) {
        s2.pop();
        updateVisualization();
    }
}

void VisualQueueViaStacks::onFront() {
    // Front operation - just show the current state, the front element is the leftmost in the queue representation
    if (!s1.empty() || !s2.empty()) {
        updateVisualization();
    }
}

void VisualQueueViaStacks::updateVisualization() {
    scene->clear();

    StyleManager* style = StyleManager::instance();

    if (s1.empty() && s2.empty()) {
        QGraphicsTextItem *emptyText = scene->addText("Queue is Empty\nClick Enqueue to add elements!");
        emptyText->setPos(200, 180);
        emptyText->setDefaultTextColor(style->textColorSecondary());
        emptyText->setFont(QFont("Segoe UI", 14, QFont::Bold));
        return;
    }

    // Add title
    QGraphicsTextItem *title = scene->addText("QUEUE VIA STACKS - Algorithm Demonstration");
    title->setPos(50, 10);
    title->setDefaultTextColor(style->primaryColor());
    title->setFont(QFont("Segoe UI", 12, QFont::Bold));

    // Stack 1 (Input stack - for enqueue) - draw on left
    drawStack("Stack 1 (Input)", s1, 100, 60, style);

    // Stack 2 (Output stack - for dequeue) - draw on right
    drawStack("Stack 2 (Output)", s2, 500, 60, style);

    // Show queue order (front to back)
    drawQueueRepresentation(300, 300, style);
}

void VisualQueueViaStacks::drawStack(const QString& stackName, std::stack<int> stk, int x, int y, StyleManager* style) {
    const int boxWidth = 70;
    const int boxHeight = 40;
    const int spacing = 5;

    // Add stack label
    QGraphicsTextItem *label = scene->addText(stackName);
    label->setPos(x + 10, y - 25);
    label->setDefaultTextColor(style->textColorSecondary());
    label->setFont(QFont("Segoe UI", 10, QFont::Bold));

    // Create a copy to display without destroying the stack
    std::stack<int> tempStack = stk;
    std::vector<int> elements;

    while (!tempStack.empty()) {
        elements.push_back(tempStack.top());
        tempStack.pop();
    }

    // Draw from bottom to top
    for (size_t i = 0; i < elements.size(); ++i) {
        int elemY = y + (elements.size() - 1 - i) * (boxHeight + spacing);

        // Draw rectangle
        QGraphicsRectItem *rect = scene->addRect(x, elemY, boxWidth, boxHeight);
        rect->setBrush(QBrush(style->primaryColor()));
        rect->setPen(QPen(style->textColor(), 2));

        // Draw value
        QGraphicsTextItem *text = scene->addText(QString::number(elements[i]));
        text->setPos(x + boxWidth/2 - 10, elemY + boxHeight/2 - 10);
        text->setDefaultTextColor(style->backgroundColor());
        text->setFont(QFont("Segoe UI", 10, QFont::Bold));
    }

    // Draw stack bottom line
    if (!elements.empty()) {
        int bottomY = y + elements.size() * (boxHeight + spacing);
        QGraphicsLineItem *bottomLine = scene->addLine(x, bottomY, x + boxWidth, bottomY);
        bottomLine->setPen(QPen(style->textColor(), 2));
    }
}

void VisualQueueViaStacks::drawQueueRepresentation(int x, int y, StyleManager* style) {
    // Create temporary queue representation by copying stacks
    std::stack<int> tempS1 = s1;
    std::stack<int> tempS2 = s2;
    std::vector<int> queueElements;

    // The queue elements are: s2 (reversed) + s1 (in order)
    // First add s2 elements (which are already in dequeue order)
    std::stack<int> s2Copy = tempS2;
    while (!s2Copy.empty()) {
        queueElements.push_back(s2Copy.top());
        s2Copy.pop();
    }

    // Then add s1 elements (in reverse order since stack)
    std::vector<int> s1Elements;
    while (!tempS1.empty()) {
        s1Elements.push_back(tempS1.top());
        tempS1.pop();
    }
    // Add s1 in correct order (reverse of popped)
    for (int i = s1Elements.size() - 1; i >= 0; --i) {
        queueElements.push_back(s1Elements[i]);
    }

    if (queueElements.empty()) return;

    // Draw queue as a horizontal arrangement
    QGraphicsTextItem *queueLabel = scene->addText("Logical Queue (Front → Back)");
    queueLabel->setPos(x - 100, y - 30);
    queueLabel->setDefaultTextColor(style->accentColor());
    queueLabel->setFont(QFont("Segoe UI", 11, QFont::Bold));

    const int boxSize = 50;
    const int spacing = 10;

    int startX = x - ((queueElements.size() - 1) * (boxSize + spacing)) / 2;

    // Draw arrow pointing to front
    QGraphicsLineItem *arrow = scene->addLine(startX - 30, y + boxSize/2,
                                           startX - 5, y + boxSize/2);
    arrow->setPen(QPen(style->accentColor(), 3));

    // Arrow head
    scene->addLine(startX - 5, y + boxSize/2 - 5, startX - 5, y + boxSize/2 + 5);
    scene->addLine(startX - 5, y + boxSize/2, startX, y + boxSize/2);

    QGraphicsTextItem *frontLabel = scene->addText("FRONT");
    frontLabel->setPos(startX - 50, y + boxSize + 10);
    frontLabel->setDefaultTextColor(style->accentColor());
    frontLabel->setFont(QFont("Segoe UI", 9, QFont::Bold));

    for (size_t i = 0; i < queueElements.size(); ++i) {
        int elemX = startX + i * (boxSize + spacing);

        // Draw rectangle
        QGraphicsRectItem *rect = scene->addRect(elemX, y, boxSize, boxSize);
        rect->setBrush(QBrush(style->primaryColor().lighter(110)));
        rect->setPen(QPen(style->textColor(), 2));

        // Draw value
        QGraphicsTextItem *text = scene->addText(QString::number(queueElements[i]));
        text->setPos(elemX + boxSize/2 - 8, y + boxSize/2 - 10);
        text->setDefaultTextColor(style->backgroundColor());
        text->setFont(QFont("Segoe UI", 10, QFont::Bold));
    }

    // Draw arrow pointing to back
    int backX = startX + (queueElements.size() - 1) * (boxSize + spacing) + boxSize;
    QGraphicsLineItem *backArrow = scene->addLine(backX + 5, y + boxSize/2,
                                                backX + 30, y + boxSize/2);
    backArrow->setPen(QPen(style->accentColor(), 3));

    // Arrow head
    scene->addLine(backX + 25, y + boxSize/2 - 5, backX + 25, y + boxSize/2 + 5);
    scene->addLine(backX + 25, y + boxSize/2, backX + 30, y + boxSize/2);

    QGraphicsTextItem *backLabel = scene->addText("BACK");
    backLabel->setPos(backX + 5, y + boxSize + 10);
    backLabel->setDefaultTextColor(style->accentColor());
    backLabel->setFont(QFont("Segoe UI", 9, QFont::Bold));
}
