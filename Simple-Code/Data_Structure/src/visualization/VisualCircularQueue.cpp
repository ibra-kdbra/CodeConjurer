#include "gui/VisualCircularQueue.h"
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
#include <cmath>

VisualCircularQueue::VisualCircularQueue(QWidget *parent) : QWidget(parent) {
    // Get style manager
    StyleManager* style = StyleManager::instance();

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);
    view->setMinimumHeight(350);
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
    connect(enqueueBtn, &QPushButton::clicked, this, &VisualCircularQueue::onEnqueue);
    controlsLayout->addWidget(enqueueBtn);

    QPushButton *dequeueBtn = new QPushButton("⬅️ Dequeue");
    dequeueBtn->setFixedHeight(style->buttonHeight());
    dequeueBtn->setStyleSheet(style->buttonStyle());
    dequeueBtn->setCursor(Qt::PointingHandCursor);
    connect(dequeueBtn, &QPushButton::clicked, this, &VisualCircularQueue::onDequeue);
    controlsLayout->addWidget(dequeueBtn);

    QLabel *statusLabel = new QLabel("Size: 10 (Fixed)");
    statusLabel->setStyleSheet(style->labelStyle() + "font-style: italic;");
    controlsLayout->addWidget(statusLabel);

    QLabel *complexityLabel = new QLabel("O(1) operations");
    complexityLabel->setStyleSheet(style->labelStyle() + "font-style: italic; color: " + style->accentColor().name() + ";");

    controlsLayout->addWidget(new QWidget()); // Spacer
    controlsLayout->addWidget(complexityLabel);

    layout->addLayout(controlsLayout);
    layout->addWidget(view);

    // Connect theme changes
    connect(style, &StyleManager::themeChanged, this, &VisualCircularQueue::updateVisualization);

    updateVisualization();
}

void VisualCircularQueue::onEnqueue() {
    bool ok;
    int val = valueInput->text().toInt(&ok);
    if (ok && queue.enQueue(val)) {
        updateVisualization();
        valueInput->clear();
    }
}

void VisualCircularQueue::onDequeue() {
    if (queue.deQueue() != -1) { // deQueue returns -1 if empty
        updateVisualization();
    }
}

void VisualCircularQueue::updateVisualization() {
    scene->clear();

    StyleManager* style = StyleManager::instance();

    int* cq = queue.getCq();
    int capacity = queue.getSize();

    // Calculate positions for circular arrangement
    const int centerX = 300;
    const int centerY = 200;
    const int radius = 120;
    const int boxSize = 50;
    const int numElements = capacity;

    // Draw empty queue slots first (gray background)
    for (int i = 0; i < numElements; ++i) {
        double angle = 2 * M_PI * i / numElements;
        int x = centerX + radius * cos(angle) - boxSize/2;
        int y = centerY + radius * sin(angle) - boxSize/2;

        QGraphicsRectItem *rect = scene->addRect(x, y, boxSize, boxSize);
        rect->setBrush(QBrush(QColor(style->surfaceColor().darker(110))));
        rect->setPen(QPen(style->borderColor(), 1));
    }

    // Then draw occupied slots with values
    if (!queue.qempty()) {
        // Find the range of occupied elements
        int front = queue.getFront();
        int rear = queue.getRear();

        int count = 0;
        if (front <= rear) {
            count = rear - front + 1;
        } else {
            count = capacity - front + rear + 1;
        }

        for (int i = 0; i < count; ++i) {
            int elementIndex = (front + i) % capacity;
            int value = cq[elementIndex];

            double angle = 2 * M_PI * i / numElements;
            int x = centerX + radius * cos(angle) - boxSize/2;
            int y = centerY + radius * sin(angle) - boxSize/2;

            // Draw rectangle
            QGraphicsRectItem *rect = scene->addRect(x, y, boxSize, boxSize);
            rect->setBrush(QBrush(style->primaryColor()));
            rect->setPen(QPen(style->textColor(), 2));

            // Draw value
            QGraphicsTextItem *text = scene->addText(QString::number(value));
            text->setPos(x + boxSize/2 - 10, y + boxSize/2 - 10);
            text->setDefaultTextColor(style->backgroundColor());
            text->setFont(QFont("Segoe UI", 11, QFont::Bold));
        }

        // Add arrows for Front and Rear
        double frontAngle = 2 * M_PI * 0 / numElements; // Front is at position 0 visually
        int frontX = centerX + (radius + 40) * cos(frontAngle);
        int frontY = centerY + (radius + 40) * sin(frontAngle);

        QGraphicsTextItem *frontLabel = scene->addText("FRONT");
        frontLabel->setPos(frontX - 30, frontY - 10);
        frontLabel->setDefaultTextColor(style->accentColor());
        frontLabel->setFont(QFont("Segoe UI", 10, QFont::Bold));

        double rearAngle = 2 * M_PI * (count - 1) / numElements;
        int rearX = centerX + (radius + 40) * cos(rearAngle);
        int rearY = centerY + (radius + 40) * sin(rearAngle);

        QGraphicsTextItem *rearLabel = scene->addText("REAR");
        rearLabel->setPos(rearX - 25, rearY - 10);
        rearLabel->setDefaultTextColor(style->accentColor());
        rearLabel->setFont(QFont("Segoe UI", 10, QFont::Bold));
    } else {
        // Empty queue message
        QGraphicsTextItem *emptyText = scene->addText("Queue is Empty\nClick Enqueue to add items!");
        emptyText->setPos(200, 170);
        emptyText->setDefaultTextColor(style->textColorSecondary());
        emptyText->setFont(QFont("Segoe UI", 12, QFont::Bold));
    }
}
