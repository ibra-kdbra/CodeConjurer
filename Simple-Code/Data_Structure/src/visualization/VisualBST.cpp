#include "gui/VisualBST.h"
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

VisualBST::VisualBST(QWidget *parent) : QWidget(parent), bst(), nodeRadius(25) {
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

    QPushButton *insertBtn = new QPushButton("🌳 Insert");
    insertBtn->setFixedHeight(style->buttonHeight());
    insertBtn->setStyleSheet(style->buttonStyle());
    insertBtn->setCursor(Qt::PointingHandCursor);
    connect(insertBtn, &QPushButton::clicked, this, &VisualBST::onInsert);
    controlsLayout->addWidget(insertBtn);

    traversalCombo = new QComboBox();
    traversalCombo->addItem("🔄 In-Order");
    traversalCombo->addItem("⬆️ Pre-Order");
    traversalCombo->addItem("⬇️ Post-Order");
    traversalCombo->setFixedHeight(style->buttonHeight());
    traversalCombo->setStyleSheet(style->comboBoxStyle());
    traversalCombo->setMinimumWidth(140);
    controlsLayout->addWidget(traversalCombo);

    QPushButton *traversalBtn = new QPushButton("🔍 Traverse");
    traversalBtn->setFixedHeight(style->buttonHeight());
    traversalBtn->setStyleSheet(style->buttonStyle());
    traversalBtn->setCursor(Qt::PointingHandCursor);
    connect(traversalBtn, &QPushButton::clicked, this, &VisualBST::onTraversal);
    controlsLayout->addWidget(traversalBtn);

    QLabel *statusLabel = new QLabel("Height: 0");
    statusLabel->setStyleSheet(style->labelStyle() + "font-style: italic;");
    controlsLayout->addWidget(statusLabel);

    complexityLabel = new QLabel("Insert O(h), Traversal O(n)");
    complexityLabel->setStyleSheet(style->labelStyle() + "font-style: italic; color: " + style->accentColor().name() + ";");

    controlsLayout->addWidget(new QWidget()); // Spacer
    controlsLayout->addWidget(complexityLabel);

    layout->addLayout(controlsLayout);
    layout->addWidget(view);

    // Connect theme changes
    connect(style, &StyleManager::themeChanged, this, &VisualBST::updateVisualization);

    updateVisualization();
}

void VisualBST::onInsert() {
    bool ok;
    int val = valueInput->text().toInt(&ok);
    if (ok) {
        bst.insert(val);
        updateVisualization();
        valueInput->clear();
    }
}

void VisualBST::onTraversal() {
    if (bst.root) {
        std::vector<int> result;
        QString traversalName;

        switch (traversalCombo->currentIndex()) {
            case 0: // In-Order
                result = bst.inorder();
                traversalName = "In-Order Traversal";
                break;
            case 1: // Pre-Order
                result = bst.preorder();
                traversalName = "Pre-Order Traversal";
                break;
            case 2: // Post-Order
                result = bst.postorder();
                traversalName = "Post-Order Traversal";
                break;
        }

        // Show traversal result in a small overlay or status
        updateVisualization();
    }
}

void VisualBST::updateVisualization() {
    scene->clear();

    StyleManager* style = StyleManager::instance();

    if (!bst.root) {
        QGraphicsTextItem *emptyText = scene->addText("BST is Empty\nClick Insert to add nodes!");
        emptyText->setPos(200, 180);
        emptyText->setDefaultTextColor(style->textColorSecondary());
        emptyText->setFont(QFont("Segoe UI", 14, QFont::Bold));
        return;
    }

    // Calculate tree height for proper spacing
    const int startX = 600;
    const int startY = 50;
    const int levelGap = 100;

    // Add BST type indicator
    QGraphicsTextItem *title = scene->addText("BINARY SEARCH TREE");
    title->setPos(50, 10);
    title->setDefaultTextColor(style->primaryColor());
    title->setFont(QFont("Segoe UI", 12, QFont::Bold));

    // Draw the tree
    drawBST(bst.root, startX, startY, levelGap, scene);

    // Add traversal indicator
    QString traversalText = "Current: ";
    switch (traversalCombo->currentIndex()) {
        case 0: traversalText += "In-Order"; break;
        case 1: traversalText += "Pre-Order"; break;
        case 2: traversalText += "Post-Order"; break;
    }
    QGraphicsTextItem *traversalLabel = scene->addText(traversalText);
    traversalLabel->setPos(50, 30);
    traversalLabel->setDefaultTextColor(style->accentColor());
    traversalLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));
}

void VisualBST::drawBST(BST::Node* node, int x, int y, int level, QGraphicsScene* scene) {
    if (!node) {
        return;
    }

    StyleManager* style = StyleManager::instance();

    // Draw node ellipse
    QGraphicsEllipseItem *ellipse = scene->addEllipse(x - nodeRadius, y - nodeRadius,
                                                    2 * nodeRadius, 2 * nodeRadius);
    ellipse->setBrush(QBrush(style->primaryColor()));
    ellipse->setPen(QPen(style->textColor(), 2));

    // Draw value
    QGraphicsTextItem *text = scene->addText(QString::number(node->value));
    text->setPos(x - 15, y - 15);
    text->setDefaultTextColor(style->backgroundColor());
    text->setFont(QFont("Segoe UI", 11, QFont::Bold));

    // Draw left subtree
    if (node->left) {
        int childX = x - 150 / (1 << (int)(log2(x - 300) + 1)); // Dynamic spacing
        int childY = y + level;

        // Draw connection line
        QGraphicsLineItem *line = scene->addLine(x, y + nodeRadius,
                                              childX, childY - nodeRadius);
        line->setPen(QPen(style->accentColor(), 2));

        // Add "L" label
        QGraphicsTextItem *leftLabel = scene->addText("L");
        leftLabel->setPos((x + childX)/2 - 5, (y + childY)/2 - 5);
        leftLabel->setDefaultTextColor(style->accentColor());
        leftLabel->setFont(QFont("Segoe UI", 8, QFont::Bold));

        drawBST(node->left, childX, childY, level, scene);
    }

    // Draw right subtree
    if (node->right) {
        int childX = x + 150 / (1 << (int)(log2(x - 300) + 1)); // Dynamic spacing
        int childY = y + level;

        // Draw connection line
        QGraphicsLineItem *line = scene->addLine(x, y + nodeRadius,
                                              childX, childY - nodeRadius);
        line->setPen(QPen(style->accentColor(), 2));

        // Add "R" label
        QGraphicsTextItem *rightLabel = scene->addText("R");
        rightLabel->setPos((x + childX)/2 - 5, (y + childY)/2 - 5);
        rightLabel->setDefaultTextColor(style->accentColor());
        rightLabel->setFont(QFont("Segoe UI", 8, QFont::Bold));

        drawBST(node->right, childX, childY, level, scene);
    }
}
