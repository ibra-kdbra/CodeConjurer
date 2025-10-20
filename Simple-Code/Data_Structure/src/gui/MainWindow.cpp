#include "gui/MainWindow.h"
#include "gui/VisualLinkedList.h"
#include "gui/VisualHeap.h"
#include "gui/VisualStack.h"
#include "gui/VisualCircularQueue.h"
#include "gui/VisualQueueViaStacks.h"
#include "gui/VisualTrie.h"
#include "gui/VisualBST.h"
#include "gui/StyleManager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QStackedWidget>
#include <QGroupBox>
#include <QApplication>
#include <QStatusBar>
#include <QLabel>
#include <QShortcut>
#include <QToolBar>
#include <QAction>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), operationCount(0) {
    // Get style manager instance
    StyleManager* style = StyleManager::instance();

    setWindowTitle("Data Structure Visualizer");
    setMinimumSize(1000, 700);
    resize(1200, 800); // Default size

    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(16); // Professional desktop spacing
    mainLayout->setContentsMargins(16, 16, 16, 16); // Standard window margins

    // Header section
    QFrame *headerFrame = new QFrame;
    headerFrame->setFrameShape(QFrame::Box);
    headerFrame->setStyleSheet(QString("QFrame { border: 2px solid %1; border-radius: %2px; background-color: %3; }")
                              .arg(style->primaryColor().name())
                              .arg(style->borderRadius())
                              .arg(style->surfaceColor().name()));

    QVBoxLayout *headerLayout = new QVBoxLayout(headerFrame);

    // Title and theme selector in compact header
    QHBoxLayout *headerContentLayout = new QHBoxLayout();

    // Title (smaller)
    QLabel *titleLabel = new QLabel("Data Structure Visualizer");
    titleLabel->setStyleSheet(QString(
        "QLabel {"
        "    font-size: 24pt;"
        "    font-weight: bold;"
        "    color: %1;"
        "    padding: 0px;"
        "}")
        .arg(style->primaryColor().name()));
    headerContentLayout->addWidget(titleLabel);

    headerContentLayout->addStretch(); // Push theme selector to the right

    // Compact theme selector
    QLabel *themeLabel = new QLabel("Theme:");
    themeLabel->setStyleSheet("font-weight: bold;");
    headerContentLayout->addWidget(themeLabel);

    themeComboBox = new QComboBox;
    themeComboBox->setStyleSheet(style->comboBoxStyle());
    themeComboBox->setMinimumWidth(180); // More compact
    themeComboBox->setMaximumWidth(200);
    themeComboBox->addItem("🔵 Modern Blue", StyleManager::ModernBlue);
    themeComboBox->addItem("🟢 Modern Green", StyleManager::ModernGreen);
    themeComboBox->addItem("☀️ Light Theme", StyleManager::Light);
    themeComboBox->addItem("🌙 Dark Theme", StyleManager::Dark);
    connect(themeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onThemeChanged);
    headerContentLayout->addWidget(themeComboBox);

    headerLayout->addLayout(headerContentLayout);

    mainLayout->addWidget(headerFrame);

    // Data structure selector
    QFrame *selectorFrame = new QFrame;
    selectorFrame->setFrameShape(QFrame::Panel);
    selectorFrame->setStyleSheet(QString("QFrame { border: 1px solid %1; border-radius: %2px; background-color: %3; }")
                                .arg(style->borderColor().name())
                                .arg(style->borderRadius())
                                .arg(style->surfaceColor().name()));

    QHBoxLayout *selectorLayout = new QHBoxLayout(selectorFrame);

    QLabel *dsLabel = new QLabel("Select Data Structure:");
    dsLabel->setStyleSheet("font-weight: bold; margin-right: 10px;");
    selectorLayout->addWidget(dsLabel);

    dsComboBox = new QComboBox;
    dsComboBox->setMinimumWidth(180);
    dsComboBox->setMinimumHeight(35); // Consistent height
    dsComboBox->addItem("🔗 Linked List", 0);
    dsComboBox->addItem("📚 Stack", 1);
    dsComboBox->addItem("🎡 Circular Queue", 2);
    dsComboBox->addItem("💎 Priority Queue", 3);
    dsComboBox->addItem("🌳 Binary Tree", 4);
    dsComboBox->addItem("🔤 Trie", 5);
    connect(dsComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onDSChanged);
    selectorLayout->addWidget(dsComboBox);

    selectorLayout->addStretch();

    // Add operations toolbar
    addToolBar(Qt::TopToolBarArea, createOperationsToolBar());

    mainLayout->addWidget(selectorFrame);

    // Stacked widget for different visualizations
    views = new QStackedWidget;
    views->setStyleSheet(QString("QStackedWidget { border: 2px solid %1; border-radius: %2px; }")
                        .arg(style->borderColor().name())
                        .arg(style->borderRadius()));
    mainLayout->addWidget(views);

    // Add visualization widgets
    linkedListView = new VisualLinkedList;
    views->addWidget(linkedListView);

    visualStack = new VisualStack;
    views->addWidget(visualStack);

    visualCircularQueue = new VisualCircularQueue;
    views->addWidget(visualCircularQueue);

    visualHeap = new VisualHeap;
    views->addWidget(visualHeap);

    visualBST = new VisualBST;
    views->addWidget(visualBST);

    visualTrie = new VisualTrie;
    views->addWidget(visualTrie);

    VisualQueueViaStacks *queueViaStacks = new VisualQueueViaStacks;
    views->addWidget(queueViaStacks);

    // Create status bar
    statusBar = new QStatusBar;
    setStatusBar(statusBar);

    // Status bar labels - more compact layout
    dsStatusLabel = new QLabel("Linked List");
    memoryLabel = new QLabel("0 elements");
    operationsLabel = new QLabel("0 ops");

    // Add separators for better organization
    statusBar->addWidget(new QLabel("DS:"), 0);
    statusBar->addWidget(dsStatusLabel, 1);
    statusBar->addWidget(new QLabel("| Memory:"), 0);
    statusBar->addWidget(memoryLabel, 1);
    statusBar->addWidget(new QLabel("| Ops:"), 0);
    statusBar->addWidget(operationsLabel, 1);

    // Initial status bar styling
    updateStatusBar();

    // Add tooltips to main controls
    themeComboBox->setToolTip("Choose from 4 beautiful themes: Blue, Green, Light, Dark");
    dsComboBox->setToolTip("Select which data structure to visualize and interact with");

    // Keyboard shortcuts
    QShortcut *quitShortcut = new QShortcut(QKeySequence(QKeySequence::Quit), this);
    connect(quitShortcut, &QShortcut::activated, this, &QWidget::close);

    QShortcut *nextDSSc = new QShortcut(QKeySequence("Ctrl+Tab"), this);
    connect(nextDSSc, &QShortcut::activated, this, [this]() {
        int nextIndex = (dsComboBox->currentIndex() + 1) % dsComboBox->count();
        dsComboBox->setCurrentIndex(nextIndex);
    });

    QShortcut *prevDSSc = new QShortcut(QKeySequence("Ctrl+Shift+Tab"), this);
    connect(prevDSSc, &QShortcut::activated, this, [this]() {
        int prevIndex = (dsComboBox->currentIndex() - 1 + dsComboBox->count()) % dsComboBox->count();
        dsComboBox->setCurrentIndex(prevIndex);
    });

    QShortcut *themeCycleSc = new QShortcut(QKeySequence("Ctrl+T"), this);
    connect(themeCycleSc, &QShortcut::activated, this, [this]() {
        int nextIndex = (themeComboBox->currentIndex() + 1) % themeComboBox->count();
        themeComboBox->setCurrentIndex(nextIndex);
    });

    // Set initial theme
    onThemeChanged(StyleManager::ModernBlue);

    // Ensure toolbar is visible and properly positioned
    update(); // Force immediate update
    show(); // Make window visible first

    // Trigger toolbar visibility check
    QTimer::singleShot(100, this, [this]() {
        // Check toolbar exists and is visible
        QList<QToolBar*> toolbars = findChildren<QToolBar*>();
        for (QToolBar* tb : toolbars) {
            tb->setVisible(true);
            tb->raise(); // Bring to front
            tb->repaint(); // Force repaint
        }
    });
}

void MainWindow::onDSChanged(int index) {
    if (views && index >= 0 && index < views->count()) {
        views->setCurrentIndex(index);
    }
}

void MainWindow::onThemeChanged(int index) {
    StyleManager::Theme theme = (StyleManager::Theme)themeComboBox->itemData(index).toInt();
    StyleManager* styleManager = StyleManager::instance();
    styleManager->setTheme(theme);

    // Update stylesheet
    updateStyle();
}

void MainWindow::updateStyle() {
    StyleManager* style = StyleManager::instance();

    // Update main window
    QString mainStyle = QString(
        "QMainWindow { background-color: %1; }"
        "QWidget#centralWidget { background-color: %1; }"
    ).arg(style->backgroundColor().name());

    setStyleSheet(mainStyle);

    // Update all child widgets by triggering a theme change
    updateAllWidgets();
}

void MainWindow::updateStatusBar() {
    StyleManager* style = StyleManager::instance();

    // Update data structure status
    QString dsNames[] = {"Linked List", "Stack", "Circular Queue", "Priority Queue", "Binary Tree", "Trie"};
    int index = dsComboBox->currentIndex();
    dsStatusLabel->setText(dsNames[index >= 0 && index < 6 ? index : 0]);

    // Update memory status (approximate)
    memoryLabel->setText(QString("Memory: %1 elements").arg(getCurrentDataSize()));

    // Update operations counter
    operationsLabel->setText(QString("Operations: %1").arg(operationCount));

    // Apply theme-aware styling
    QString statusStyle = QString("color: %1; font-weight: 500;")
                         .arg(style->textColor().name());

    dsStatusLabel->setStyleSheet(statusStyle);
    memoryLabel->setStyleSheet(statusStyle);
    operationsLabel->setStyleSheet(statusStyle);
}

int MainWindow::getCurrentDataSize() {
    int currentIndex = views->currentIndex();

    switch (currentIndex) {
        case 0: return 0; // Linked List - no size tracking yet
        case 1: return visualStack ? 1 : 0; // Placeholder for stack size
        case 2: return 10; // Circular Queue is fixed size 10
        case 3: return visualHeap ? 1 : 0; // Placeholder for heap size
        case 4: return visualBST ? 1 : 0; // Placeholder for BST node count
        case 5: return visualTrie ? 1 : 0; // Placeholder for trie words
        default: return 0;
    }
}

void MainWindow::updateAllWidgets() {
    StyleManager* style = StyleManager::instance();

    // Update all QComboBoxes
    QList<QComboBox*> comboBoxes = findChildren<QComboBox*>();
    for (QComboBox* combo : comboBoxes) {
        combo->setStyleSheet(style->comboBoxStyle());
    }

    // Update all QPushButtons
    QList<QPushButton*> buttons = findChildren<QPushButton*>();
    for (QPushButton* button : buttons) {
        button->setStyleSheet(style->buttonStyle());
    }

    // Update all QLineEdits
    QList<QLineEdit*> lineEdits = findChildren<QLineEdit*>();
    for (QLineEdit* edit : lineEdits) {
        edit->setStyleSheet(style->inputStyle());
    }

    // Update all QLabels
    QList<QLabel*> labels = findChildren<QLabel*>();
    for (QLabel* label : labels) {
        label->setStyleSheet(style->labelStyle());
    }

    // Update status bar with new theme
    updateStatusBar();
}

QToolBar* MainWindow::createOperationsToolBar() {
    QToolBar* toolBar = new QToolBar("Operations");
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    // Add separator between toolbars
    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spacer);

    // Clear operation button
    QAction* clearAction = new QAction("🔄 Clear", this);
    clearAction->setStatusTip("Clear all data from current data structure");
    clearAction->setShortcut(QKeySequence("Ctrl+C"));
    connect(clearAction, &QAction::triggered, this, [this]() {
        // Implement clear operation for current data structure
        onClearDataStructure();
    });
    toolBar->addAction(clearAction);

    // Export button
    QAction* exportAction = new QAction("📤 Export", this);
    exportAction->setStatusTip("Export current data structure to file");
    exportAction->setShortcut(QKeySequence("Ctrl+E"));
    connect(exportAction, &QAction::triggered, this, [this]() {
        // Trigger export in current visualization
        QWidget* currentWidget = views->currentWidget();
        if (qobject_cast<VisualLinkedList*>(currentWidget)) {
            qobject_cast<VisualLinkedList*>(currentWidget)->exportData();
        }
    });
    toolBar->addAction(exportAction);

    // Import button
    QAction* importAction = new QAction("📥 Import", this);
    importAction->setStatusTip("Import data from file to current data structure");
    importAction->setShortcut(QKeySequence("Ctrl+I"));
    connect(importAction, &QAction::triggered, this, [this]() {
        // Trigger import in current visualization
        QWidget* currentWidget = views->currentWidget();
        if (qobject_cast<VisualLinkedList*>(currentWidget)) {
            qobject_cast<VisualLinkedList*>(currentWidget)->importData();
        }
    });
    toolBar->addAction(importAction);

    toolBar->addSeparator();

    // About button
    QAction* aboutAction = new QAction("❓ About", this);
    aboutAction->setStatusTip("Show application information");
    aboutAction->setShortcut(QKeySequence("Ctrl+A"));
    connect(aboutAction, &QAction::triggered, this, [this]() {
        // Show about dialog
        showAboutDialog();
    });
    toolBar->addAction(aboutAction);

    // CRITICAL: Add explicit styling to ensure toolbar visibility
    toolBar->setStyleSheet(
        "QToolBar {"
        "    background-color: #f0f0f0;" // Light gray for contrast
        "    border: 1px solid #999999;"
        "    border-top: none;"
        "    padding: 2px;"
        "    spacing: 5px;"
        "}"
        "QToolBar::separator {"
        "    background-color: #cccccc;"
        "    width: 1px;"
        "    margin: 0px 8px;"
        "}"
        "QToolButton {"
        "    background-color: transparent;"
        "    border: 1px solid transparent;"
        "    border-radius: 3px;"
        "    padding: 6px 12px;"
        "    font-weight: bold;"
        "    color: #333333;" // Dark text for visibility
        "}"
        "QToolButton:hover {"
        "    background-color: #e0e0e0;" // Light hover effect
        "    border: 1px solid #aaaaaa;"
        "}"
        "QToolButton:pressed {"
        "    background-color: #d0d0d0;" // Pressed effect
        "}"
    );

    // Ensure toolbar is visible and has proper size
    toolBar->setVisible(true);
    toolBar->setEnabled(true);
    toolBar->setMovable(false); // Keep it in place
    toolBar->setFloatable(false); // Prevent floating
    toolBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->setMinimumHeight(40); // Enough height for buttons

    // Theme change handler for toolbar
    connect(StyleManager::instance(), &StyleManager::themeChanged, this, [toolBar]() {
        StyleManager* style = StyleManager::instance();

        // Update with theme-appropriate colors
        QString bgColor = style->surfaceColor().lighter(115).name(); // Lighter than surface
        QString textColor = style->textColor().name();
        QString hoverColor = style->surfaceColor().lighter(125).name();

        toolBar->setStyleSheet(QString(
            "QToolBar {"
            "    background-color: %1;"
            "    border: 1px solid %2;"
            "    border-top: none;"
            "    padding: 2px;"
            "    spacing: 5px;"
            "}"
            "QToolBar::separator {"
            "    background-color: %3;"
            "    width: 1px;"
            "    margin: 0px 8px;"
            "}"
            "QToolButton {"
            "    background-color: transparent;"
            "    border: 1px solid transparent;"
            "    border-radius: 3px;"
            "    padding: 6px 12px;"
            "    font-weight: bold;"
            "    color: %4;"
            "}"
            "QToolButton:hover {"
            "    background-color: %5;"
            "    border: 1px solid %6;"
            "}"
            "QToolButton:pressed {"
            "    background-color: %7;"
            "}"
        ).arg(bgColor) // Toolbar background
         .arg(style->borderColor().name()) // Border color
         .arg(style->borderColor().darker(150).name()) // Separator
         .arg(textColor) // Text color
         .arg(hoverColor) // Hover background
         .arg(style->accentColor().name()) // Hover border
         .arg(style->accentColor().lighter(150).name())); // Pressed background
    });

    return toolBar;
}

void MainWindow::onClearDataStructure() {
    // Clear the current data structure visualization
    QWidget* currentWidget = views->currentWidget();
    if (qobject_cast<VisualLinkedList*>(currentWidget)) {
        qobject_cast<VisualLinkedList*>(currentWidget)->clearList();
    } else if (qobject_cast<VisualStack*>(currentWidget)) {
        qobject_cast<VisualStack*>(currentWidget)->clearStack();
    }
    // Add similar clear methods for other data structures as implemented
}

void MainWindow::showAboutDialog() {
    QMessageBox aboutBox(this);
    aboutBox.setWindowTitle("About Data Structure Visualizer");
    aboutBox.setText("Data Structure Visualizer v1.0\n\n"
                    "An educational tool for visualizing and interacting with:\n"
                    "• Linked Lists\n"
                    "• Stacks\n"
                    "• Queues (Circular & Stack-based)\n"
                    "• Binary Search Trees (BST)\n"
                    "• Heap (Priority Queue)\n"
                    "• Trie (Prefix Tree)\n\n"
                    "Built with Qt5 - Professional desktop application development.");
    aboutBox.setIcon(QMessageBox::Information);
    aboutBox.exec();
}
