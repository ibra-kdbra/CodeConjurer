#include "gui/VisualTrie.h"
#include "gui/StyleManager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QMessageBox>
#include <QColor>

VisualTrie::VisualTrie(QWidget *parent) : QWidget(parent), root(nullptr), nodeRadius(25) {
    // Initialize root
    root = new TrieNode();

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

    wordInput = new QLineEdit();
    wordInput->setPlaceholderText("Enter word...");
    wordInput->setFixedHeight(style->buttonHeight());
    wordInput->setStyleSheet(style->inputStyle());
    controlsLayout->addWidget(wordInput);

    QPushButton *insertBtn = new QPushButton("🔤 Insert");
    insertBtn->setFixedHeight(style->buttonHeight());
    insertBtn->setStyleSheet(style->buttonStyle());
    insertBtn->setCursor(Qt::PointingHandCursor);
    connect(insertBtn, &QPushButton::clicked, this, &VisualTrie::onInsert);
    controlsLayout->addWidget(insertBtn);

    QPushButton *searchBtn = new QPushButton("🔍 Search");
    searchBtn->setFixedHeight(style->buttonHeight());
    searchBtn->setStyleSheet(style->buttonStyle());
    searchBtn->setCursor(Qt::PointingHandCursor);
    connect(searchBtn, &QPushButton::clicked, this, &VisualTrie::onSearch);
    controlsLayout->addWidget(searchBtn);

    QPushButton *startsWithBtn = new QPushButton("📝 Starts With");
    startsWithBtn->setFixedHeight(style->buttonHeight());
    startsWithBtn->setStyleSheet(style->buttonStyle());
    startsWithBtn->setCursor(Qt::PointingHandCursor);
    connect(startsWithBtn, &QPushButton::clicked, this, &VisualTrie::onStartsWith);
    controlsLayout->addWidget(startsWithBtn);

    QLabel *statusLabel = new QLabel("Words: 0");
    statusLabel->setStyleSheet(style->labelStyle() + "font-style: italic;");
    controlsLayout->addWidget(statusLabel);

    complexityLabel = new QLabel("Insert/Search O(m)");
    complexityLabel->setStyleSheet(style->labelStyle() + "font-style: italic; color: " + style->accentColor().name() + ";");

    controlsLayout->addWidget(new QWidget()); // Spacer
    controlsLayout->addWidget(complexityLabel);

    layout->addLayout(controlsLayout);
    layout->addWidget(view);

    // Connect theme changes
    connect(style, &StyleManager::themeChanged, this, &VisualTrie::updateVisualization);

    updateVisualization();
}

VisualTrie::~VisualTrie() {
    // Clean up Trie memory
    if (root) {
        deleteTrie(root);
    }
}

void VisualTrie::deleteTrie(TrieNode* node) {
    if (!node) return;
    for (auto& child : node->children) {
        deleteTrie(child.second);
    }
    delete node;
}

void VisualTrie::onInsert() {
    QString word = wordInput->text().toLower().trimmed();
    if (word.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a word to insert.");
        return;
    }

    // Insert word into Trie
    TrieNode* node = root;
    for (QChar ch : word) {
        char c = ch.toLatin1();
        if (node->children.find(c) == node->children.end()) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->isEnd = true;

    updateVisualization();
    wordInput->clear();

    QMessageBox::information(this, "Success", QString("Word '%1' inserted successfully!").arg(word));
}

void VisualTrie::onSearch() {
    QString word = wordInput->text().toLower().trimmed();
    if (word.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a word to search.");
        return;
    }

    // Search for exact word
    TrieNode* node = root;
    for (QChar ch : word) {
        char c = ch.toLatin1();
        if (node->children.find(c) == node->children.end()) {
            QMessageBox::information(this, "Search Results", QString("Word '%1' NOT found!").arg(word));
            return;
        }
        node = node->children[c];
    }

    if (node->isEnd) {
        QMessageBox::information(this, "Search Results", QString("Word '%1' FOUND!").arg(word));
    } else {
        QMessageBox::information(this, "Search Results", QString("'%1' is a prefix but not a complete word.").arg(word));
    }
}

void VisualTrie::onStartsWith() {
    QString prefix = wordInput->text().toLower().trimmed();
    if (prefix.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a prefix to search.");
        return;
    }

    // Check if prefix exists
    TrieNode* node = root;
    for (QChar ch : prefix) {
        char c = ch.toLatin1();
        if (node->children.find(c) == node->children.end()) {
            QMessageBox::information(this, "Prefix Search", QString("No words start with '%1'.").arg(prefix));
            return;
        }
        node = node->children[c];
    }

    // Collect all words with this prefix
    std::vector<QString> words;
    collectWords(node, prefix, words);

    if (words.empty()) {
        QMessageBox::information(this, "Prefix Search", QString("Prefix '%1' exists but no complete words.").arg(prefix));
    } else {
        QString result = QString("Prefix '%1' found! Words:\n").arg(prefix);
        for (const QString& w : words) {
            result += w + "\n";
        }
        QMessageBox::information(this, "Prefix Search Results", result);
    }
}

void VisualTrie::collectWords(TrieNode* node, QString current, std::vector<QString>& words) {
    if (node->isEnd) {
        words.push_back(current);
    }

    for (auto& child : node->children) {
        collectWords(child.second, current + child.first, words);
    }
}

void VisualTrie::updateVisualization() {
    scene->clear();

    StyleManager* style = StyleManager::instance();

    if (!root || root->children.empty()) {
        QGraphicsTextItem *emptyText = scene->addText("Trie is Empty\nClick Insert to add words!");
        emptyText->setPos(200, 180);
        emptyText->setDefaultTextColor(style->textColorSecondary());
        emptyText->setFont(QFont("Segoe UI", 14, QFont::Bold));
        return;
    }

    // Add title
    QGraphicsTextItem *title = scene->addText("TRIE (Prefix Tree)");
    title->setPos(50, 10);
    title->setDefaultTextColor(style->primaryColor());
    title->setFont(QFont("Segoe UI", 12, QFont::Bold));

    // Draw the Trie
    drawTrie(root, 400, 50, 80, scene);
}

void VisualTrie::drawTrie(TrieNode* node, int x, int y, int level, QGraphicsScene* scene) {
    if (!node) return;

    StyleManager* style = StyleManager::instance();

    // Get all children for positioning
    std::vector<std::pair<char, TrieNode*>> children(node->children.begin(), node->children.end());

    // Draw root node (only once)
    if (node == root) {
        QGraphicsEllipseItem *rootEllipse = scene->addEllipse(x - nodeRadius, y - nodeRadius,
                                                            2 * nodeRadius, 2 * nodeRadius);
        rootEllipse->setBrush(QBrush(style->primaryColor()));
        rootEllipse->setPen(QPen(style->textColor(), 2));

        QGraphicsTextItem *rootText = scene->addText("ROOT");
        rootText->setPos(x - 20, y - 10);
        rootText->setDefaultTextColor(style->backgroundColor());
        rootText->setFont(QFont("Segoe UI", 8, QFont::Bold));

        if (node->isEnd) {
            // Mark root as end node
            QGraphicsEllipseItem *endMarker = scene->addEllipse(x - nodeRadius + 2, y - nodeRadius + 2,
                                                               2 * nodeRadius - 4, 2 * nodeRadius - 4);
            endMarker->setBrush(QBrush(Qt::transparent));
            endMarker->setPen(QPen(style->accentColor(), 3));
        }
    }

    // Draw children
    int childSpacing = 100;
    int startX = x - ((children.size() - 1) * childSpacing) / 2;

    for (size_t i = 0; i < children.size(); ++i) {
        char ch = children[i].first;
        TrieNode* child = children[i].second;

        int childX = startX + i * childSpacing;
        int childY = y + level;

        // Draw edge
        QGraphicsLineItem *line = scene->addLine(x, y + nodeRadius, childX, childY - nodeRadius);
        line->setPen(QPen(style->accentColor(), 2));

        // Draw edge label (character)
        QGraphicsTextItem *edgeLabel = scene->addText(QString(ch));
        edgeLabel->setPos((x + childX) / 2 - 5, (y + childY) / 2 - 5);
        edgeLabel->setDefaultTextColor(style->textColorSecondary());
        edgeLabel->setFont(QFont("Segoe UI", 9, QFont::Normal));

        // Draw child node
        QGraphicsEllipseItem *childEllipse = scene->addEllipse(childX - nodeRadius, childY - nodeRadius,
                                                             2 * nodeRadius, 2 * nodeRadius);

        QColor childColor = child->isEnd ? style->primaryColor().lighter(110) : style->primaryColor();
        childEllipse->setBrush(QBrush(childColor));
        childEllipse->setPen(QPen(style->textColor(), 2));

        // If this is an end node, add a small marker
        if (child->isEnd) {
            QGraphicsEllipseItem *endMarker = scene->addEllipse(childX - nodeRadius + 2, childY - nodeRadius + 2,
                                                               2 * nodeRadius - 4, 2 * nodeRadius - 4);
            endMarker->setBrush(QBrush(Qt::transparent));
            endMarker->setPen(QPen(style->accentColor(), 3));
        }

        // Recursively draw subtree
        drawTrie(child, childX, childY, level, scene);
    }
}
