#include "gui/VisualLinkedList.h"
#include "ds/SinglyLinkedList.h"
#include "gui/StyleManager.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

VisualLinkedList::VisualLinkedList(QWidget *parent) : QWidget(parent) {
    // Data structure initializes automatically via default constructor

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

    QPushButton *pushBtn = new QPushButton("Add");
    pushBtn->setFixedHeight(style->buttonHeight());
    pushBtn->setStyleSheet(style->buttonStyle());
    pushBtn->setCursor(Qt::PointingHandCursor);
    connect(pushBtn, &QPushButton::clicked, this, &VisualLinkedList::onPush);
    controlsLayout->addWidget(pushBtn);

    QPushButton *popBtn = new QPushButton("Remove");
    popBtn->setFixedHeight(style->buttonHeight());
    popBtn->setStyleSheet(style->buttonStyle());
    popBtn->setCursor(Qt::PointingHandCursor);
    connect(popBtn, &QPushButton::clicked, this, &VisualLinkedList::onPop);
    controlsLayout->addWidget(popBtn);

    QLabel *autoLabel = new QLabel("Auto updates");
    autoLabel->setStyleSheet(style->labelStyle() + "font-style: italic;");
    controlsLayout->addWidget(autoLabel);

    QPushButton *exportBtn = new QPushButton("📤 Export");
    exportBtn->setFixedHeight(style->buttonHeight());
    exportBtn->setStyleSheet(style->buttonStyle());
    exportBtn->setCursor(Qt::PointingHandCursor);
    exportBtn->setToolTip("Export list data to a file");
    connect(exportBtn, &QPushButton::clicked, this, &VisualLinkedList::exportData);
    controlsLayout->addWidget(exportBtn);

    QPushButton *importBtn = new QPushButton("📥 Import");
    importBtn->setFixedHeight(style->buttonHeight());
    importBtn->setStyleSheet(style->buttonStyle());
    importBtn->setCursor(Qt::PointingHandCursor);
    importBtn->setToolTip("Import list data from a file");
    connect(importBtn, &QPushButton::clicked, this, &VisualLinkedList::importData);
    controlsLayout->addWidget(importBtn);

    layout->addLayout(controlsLayout);
    layout->addWidget(view);

    // Connect theme changes
    connect(style, &StyleManager::themeChanged, this, &VisualLinkedList::updateVisualization);

    updateVisualization();
}

void VisualLinkedList::onPush() {
    bool ok;
    int val = valueInput->text().toInt(&ok);
    if (ok) {
        list.push(val);
        updateVisualization();
    }
}

void VisualLinkedList::onPop() {
    if (list.head != nullptr) {
        list.pop();
        updateVisualization();
    }
}

void VisualLinkedList::onInsertAfter() {
    // Insert after functionality - placeholder for now
    updateVisualization();
}

void VisualLinkedList::onPrint() {
    // Print functionality - placeholder for now
    updateVisualization();
}

void VisualLinkedList::updateVisualization() {
    scene->clear();

    StyleManager* style = StyleManager::instance();

    QList<List::Node*> allNodes;
    List::Node* current = list.head;
    while (current) {
        allNodes.append(current);
        current = current->next;
    }

    if (allNodes.isEmpty()) {
        QGraphicsTextItem *emptyText = scene->addText("List is Empty\nClick Add to insert items!");
        emptyText->setPos(150, 150);
        emptyText->setDefaultTextColor(style->textColorSecondary());
        emptyText->setFont(QFont("Segoe UI", 14, QFont::Bold));
        return;
    }

    int x = 50;
    int nodeRadius = 25;

    for (int i = 0; i < allNodes.size(); ++i) {
        List::Node* node = allNodes[i];

        // Draw node ellipse
        QGraphicsEllipseItem *ellipse = scene->addEllipse(x - nodeRadius, 100 - nodeRadius,
                                                        2 * nodeRadius, 2 * nodeRadius);
        ellipse->setBrush(QBrush(style->primaryColor()));
        ellipse->setPen(QPen(style->textColor(), 2));

        // Draw value
        QGraphicsTextItem *text = scene->addText(QString::number(node->info));
        text->setPos(x - 10, 85);
        text->setDefaultTextColor(style->backgroundColor());
        text->setFont(QFont("Segoe UI", 12, QFont::Bold));

        // Connect to next node with arrow
        if (i < allNodes.size() - 1) {
            QGraphicsLineItem *line = scene->addLine(x + nodeRadius, 100, x + 100 - nodeRadius, 100);
            line->setPen(QPen(style->primaryColor(), 3));

            // Arrow head
            scene->addLine(x + 80, 95, x + 84, 100);
            scene->addLine(x + 80, 105, x + 84, 100);
        }

        x += 100;
    }
}

void VisualLinkedList::exportData() {
    QString fileName = QFileDialog::getSaveFileName(this, "Export Linked List",
                                                   QDir::homePath(),
                                                   "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open file for writing!");
        return;
    }

    QTextStream out(&file);

    // Write header
    out << "# Exported Linked List Data" << Qt::endl;

    // Write data
    out << "DATA:" << Qt::endl;
    List::Node* current = list.head;
    while (current) {
        out << current->info;
        current = current->next;
        if (current) {
            out << ",";
        }
    }
    out << Qt::endl;

    file.close();
    QMessageBox::information(this, "Export Complete", "Linked list data exported successfully!");
}

void VisualLinkedList::importData() {
    QString fileName = QFileDialog::getOpenFileName(this, "Import Linked List",
                                                   QDir::homePath(),
                                                   "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open file for reading!");
        return;
    }

    QTextStream in(&file);
    bool foundData = false;
    QList<int> values;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        // Skip comments and empty lines
        if (line.startsWith("#") || line.isEmpty()) {
            continue;
        }

        if (line == "DATA:") {
            // Read the next line with data
            if (!in.atEnd()) {
                QString dataLine = in.readLine().trimmed();
                QStringList valueStrings = dataLine.split(",", Qt::SkipEmptyParts);

                bool ok;
                for (const QString& valStr : valueStrings) {
                    int val = valStr.toInt(&ok);
                    if (ok) {
                        values.append(val);
                    }
                }

                foundData = true;
                break;
            }
        }
    }

    file.close();

    if (!foundData) {
        QMessageBox::warning(this, "Import Error", "No valid data found in file!");
        return;
    }

    // Clear existing list and import new data
    clearList();
    for (int val : values) {
        list.push(val);
    }

    updateVisualization();
    QMessageBox::information(this, "Import Complete", QString("Successfully imported %1 elements!").arg(values.size()));
}

void VisualLinkedList::clearList() {
    while (list.head != nullptr) {
        list.pop();
    }
    updateVisualization();
}
