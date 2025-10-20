#include "gui/VisualStack.h"
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

VisualStack::VisualStack(QWidget *parent) : QWidget(parent) {
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
    layout->setSpacing(12); // More compact spacing
    layout->setContentsMargins(12, 12, 12, 12); // More reasonable margins

    QHBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->setSpacing(style->spacing());

    valueInput = new QLineEdit();
    valueInput->setPlaceholderText("Enter value...");
    valueInput->setFixedHeight(style->buttonHeight());
    valueInput->setStyleSheet(style->inputStyle());
    controlsLayout->addWidget(valueInput);

    QPushButton *pushBtn = new QPushButton("📤 Push");
    pushBtn->setFixedHeight(style->buttonHeight());
    pushBtn->setStyleSheet(style->buttonStyle());
    pushBtn->setCursor(Qt::PointingHandCursor);
    connect(pushBtn, &QPushButton::clicked, this, &VisualStack::onPush);
    controlsLayout->addWidget(pushBtn);

    QPushButton *popBtn = new QPushButton("📥 Pop");
    popBtn->setFixedHeight(style->buttonHeight());
    popBtn->setStyleSheet(style->buttonStyle());
    popBtn->setCursor(Qt::PointingHandCursor);
    connect(popBtn, &QPushButton::clicked, this, &VisualStack::onPop);
    controlsLayout->addWidget(popBtn);

    QPushButton *peekBtn = new QPushButton("👁️ Peek");
    peekBtn->setFixedHeight(style->buttonHeight());
    peekBtn->setStyleSheet(style->buttonStyle());
    peekBtn->setCursor(Qt::PointingHandCursor);
    connect(peekBtn, &QPushButton::clicked, this, &VisualStack::onPeek);
    controlsLayout->addWidget(peekBtn);

    sizeLabel = new QLabel("Size: 0");
    sizeLabel->setStyleSheet(style->labelStyle() + "font-style: italic;");
    controlsLayout->addWidget(sizeLabel);

    complexityLabel = new QLabel("O(1) operations");
    complexityLabel->setStyleSheet(style->labelStyle() + "font-style: italic; color: " + style->accentColor().name() + ";");

    controlsLayout->addWidget(new QWidget()); // Spacer
    controlsLayout->addWidget(complexityLabel);

    layout->addLayout(controlsLayout);
    layout->addWidget(view);

    // Connect theme changes
    connect(style, &StyleManager::themeChanged, this, &VisualStack::updateVisualization);

    updateVisualization();
}

void VisualStack::onPush() {
    bool ok;
    int val = valueInput->text().toInt(&ok);
    if (ok) {
        stack.push(val);
        updateVisualization();
    }
    valueInput->clear();
}

void VisualStack::onPop() {
    if (!stack.isEmpty()) {
        stack.pop();
        updateVisualization();
    }
}

void VisualStack::onPeek() {
    // Peek doesn't change the stack, just show the top element
    updateVisualization();
}

void VisualStack::updateVisualization() {
    scene->clear();

    StyleManager* style = StyleManager::instance();

    int size = stack.getSize();
    sizeLabel->setText(QString("Size: %1").arg(size));

    if (size == 0) {
        QGraphicsTextItem *emptyText = scene->addText("Stack is Empty\nClick Push to add items!");
        emptyText->setPos(150, 150);
        emptyText->setDefaultTextColor(style->textColorSecondary());
        emptyText->setFont(QFont("Segoe UI", 14, QFont::Bold));
        return;
    }

    // Get all stack elements
    std::vector<int> elements;
    Stack::NODEPTR current = stack.top;
    while (current) {
        elements.push_back(current->data);
        current = current->next;
    }

    // Realistic card stack visualization
    const int cardWidth = 120;
    const int cardHeight = 80;
    const int cardOffsetX = 8;
    const int cardOffsetY = 6;
    const int baseX = 250;
    const int baseY = 300;

    // Draw stack from bottom to top (reverse order for visual stacking)
    for (size_t i = 0; i < elements.size(); ++i) {
        int cardIndex = elements.size() - 1 - i; // Bottom card first
        int value = elements[i];

        // Calculate card position with stacking effect
        int x = baseX - (i * cardOffsetX);
        int y = baseY - (i * cardOffsetY);

        // Draw card shadow first (for depth)
        QGraphicsRectItem *shadow = scene->addRect(x + 3, y + 3, cardWidth, cardHeight);
        shadow->setBrush(QBrush(QColor(0, 0, 0, 30)));
        shadow->setPen(Qt::NoPen);

        // Draw main card
        QGraphicsRectItem *card = scene->addRect(x, y, cardWidth, cardHeight);
        QColor cardColor = style->primaryColor();
        if (i == 0) { // Top card highlighted
            cardColor = cardColor.lighter(110);
        } else {
            cardColor = cardColor.darker(110 - (i * 5));
        }
        card->setBrush(QBrush(cardColor));
        card->setPen(QPen(style->borderColor(), 2));

        // Add rounded corners effect with border
        QGraphicsRectItem *overlay = scene->addRect(x + 2, y + 2, cardWidth - 4, cardHeight - 4);
        overlay->setBrush(QBrush(style->primaryColor().lighter(120)));
        overlay->setPen(Qt::NoPen);

        // Draw value prominently
        QGraphicsTextItem *valueText = scene->addText(QString::number(value));
        valueText->setPos(x + cardWidth/2 - 12, y + cardHeight/2 - 12);
        valueText->setDefaultTextColor(style->backgroundColor());
        valueText->setFont(QFont("Segoe UI", 16, QFont::Bold));
    }

    // Add "TOP" visual indicator
    if (!elements.empty()) {
        int topX = baseX - ((elements.size() - 1) * cardOffsetX);
        int topY = baseY - ((elements.size() - 1) * cardOffsetY);

        // Arrow pointing to top
        QGraphicsLineItem *arrow = scene->addLine(topX - 40, topY + cardHeight/2,
                                               topX - 15, topY + cardHeight/2);
        arrow->setPen(QPen(style->accentColor(), 3));

        // Arrow head
        scene->addLine(topX - 15, topY + cardHeight/2 - 5, topX - 15, topY + cardHeight/2 + 5);
        scene->addLine(topX - 15, topY + cardHeight/2, topX - 10, topY + cardHeight/2);

        QGraphicsTextItem *topLabel = scene->addText("TOP");
        topLabel->setPos(topX - 80, topY + cardHeight/2 - 10);
        topLabel->setDefaultTextColor(style->accentColor());
        topLabel->setFont(QFont("Segoe UI", 10, QFont::Bold));
    }

    // Add realistic stack base
    QGraphicsRectItem *base = scene->addRect(baseX - 10, baseY + 10, cardWidth + 20, 15);
    base->setBrush(QBrush(QColor(139, 69, 19))); // Brown wood color
    base->setPen(QPen(QColor(101, 51, 15), 2));

    QGraphicsTextItem *stackTitle = scene->addText("REALISTIC CARD STACK");
    stackTitle->setPos(50, 50);
    stackTitle->setDefaultTextColor(style->primaryColor());
    stackTitle->setFont(QFont("Segoe UI", 14, QFont::Bold));
}

void VisualStack::clearStack() {
    while (!stack.isEmpty()) {
        stack.pop();
    }
    sizeLabel->setText("Size: 0");
    updateVisualization();
}
