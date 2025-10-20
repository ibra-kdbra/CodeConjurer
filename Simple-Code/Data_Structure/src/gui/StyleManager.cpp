#include "gui/StyleManager.h"
#include <QApplication>
#include <QPalette>

StyleManager* StyleManager::m_instance = nullptr;

StyleManager* StyleManager::instance() {
    if (!m_instance) {
        m_instance = new StyleManager();
    }
    return m_instance;
}

StyleManager::StyleManager(QObject *parent) : QObject(parent), m_currentTheme(ModernBlue) {
    applyModernBlueTheme();
    updateApplicationPalette();
}

void StyleManager::setTheme(StyleManager::Theme theme) {
    if (m_currentTheme != theme) {
        m_currentTheme = theme;

        switch (theme) {
            case ModernBlue:
                applyModernBlueTheme();
                break;
            case ModernGreen:
                applyModernGreenTheme();
                break;
            case Light:
                applyLightTheme();
                break;
            case Dark:
                applyDarkTheme();
                break;
        }

        updateApplicationPalette();
        emit themeChanged();
    }
}

void StyleManager::updateApplicationPalette() {
    QPalette palette = QApplication::palette();

    // Set window colors
    palette.setColor(QPalette::Window, m_backgroundColor);
    palette.setColor(QPalette::WindowText, m_textColor);

    // Set base widget colors (buttons, inputs, etc.)
    palette.setColor(QPalette::Base, m_surfaceColor);
    palette.setColor(QPalette::AlternateBase, m_surfaceColor.darker(105));
    palette.setColor(QPalette::Text, m_textColor);
    palette.setColor(QPalette::BrightText, m_accentColor);

    // Set button colors
    palette.setColor(QPalette::Button, m_primaryColor);
    palette.setColor(QPalette::ButtonText, m_backgroundColor);

    // Set highlight colors (selected items, focus)
    palette.setColor(QPalette::Highlight, m_primaryColor);
    palette.setColor(QPalette::HighlightedText, m_backgroundColor);

    // Set tooltip colors
    palette.setColor(QPalette::ToolTipBase, m_surfaceColor);
    palette.setColor(QPalette::ToolTipText, m_textColor);

    // Set link colors
    palette.setColor(QPalette::Link, m_accentColor);
    palette.setColor(QPalette::LinkVisited, m_accentColor.darker(120));

    // Apply to entire application
    QApplication::setPalette(palette);
}

void StyleManager::applyModernBlueTheme() {
    m_primaryColor = QColor(63, 81, 181);      // Indigo
    m_secondaryColor = QColor(240, 248, 255);  // Alice blue
    m_accentColor = QColor(33, 150, 243);      // Light blue
    m_backgroundColor = QColor(248, 249, 250); // Light gray
    m_surfaceColor = QColor(255, 255, 255);    // White
    m_textColor = QColor(33, 37, 41);          // Dark
    m_textColorSecondary = QColor(75, 85, 99); // Medium gray
    m_borderColor = QColor(63, 81, 181, 128);  // Indigo transparent
    m_spacing = 12;
    m_margin = 20;
    m_borderRadius = 12;
    m_buttonHeight = 40;
    m_animationDuration = 200;
}

void StyleManager::applyModernGreenTheme() {
    m_primaryColor = QColor(76, 175, 80);      // Green
    m_secondaryColor = QColor(245, 255, 245);  // Light green
    m_accentColor = QColor(139, 195, 74);      // Light green
    m_backgroundColor = QColor(250, 255, 250); // Light green background
    m_surfaceColor = QColor(255, 255, 255);    // White
    m_textColor = QColor(33, 47, 33);          // Dark green
    m_textColorSecondary = QColor(85, 107, 47); // Medium green
    m_borderColor = QColor(76, 175, 80, 128);  // Transparent green
    m_spacing = 12;
    m_margin = 20;
    m_borderRadius = 12;
    m_buttonHeight = 40;
    m_animationDuration = 200;
}

void StyleManager::applyLightTheme() {
    m_primaryColor = QColor(74, 144, 226);    // Blue
    m_secondaryColor = QColor(250, 250, 250); // Light gray
    m_accentColor = QColor(255, 107, 107);    // Coral
    m_backgroundColor = QColor(255, 255, 255); // White
    m_surfaceColor = QColor(247, 247, 247);   // Light gray
    m_textColor = QColor(33, 33, 33);         // Dark gray
    m_textColorSecondary = QColor(117, 117, 117); // Medium gray
    m_borderColor = QColor(224, 224, 224);    // Light border
    m_spacing = 8;
    m_margin = 16;
    m_borderRadius = 8;
    m_buttonHeight = 36;
    m_animationDuration = 150;
}

void StyleManager::applyDarkTheme() {
    m_primaryColor = QColor(100, 181, 246);   // Light blue
    m_secondaryColor = QColor(45, 45, 45);    // Dark gray
    m_accentColor = QColor(255, 138, 101);    // Orange
    m_backgroundColor = QColor(33, 33, 33);   // Dark background
    m_surfaceColor = QColor(45, 45, 45);      // Dark surface
    m_textColor = QColor(255, 255, 255);      // White text
    m_textColorSecondary = QColor(189, 189, 189); // Light gray
    m_borderColor = QColor(81, 81, 81);       // Dark border
    m_spacing = 8;
    m_margin = 16;
    m_borderRadius = 8;
    m_buttonHeight = 36;
    m_animationDuration = 150;
}

QString StyleManager::buttonStyle() const {
    return QString(
        "QPushButton {"
        "    background-color: %1;"
        "    color: %2;"
        "    border: 2px solid %1;"
        "    border-radius: %3px;"
        "    padding: %4px %5px;"
        "    font-weight: bold;"
        "    min-height: %6px;"
        "    transition: background-color %7ms ease, border-color %7ms ease;"
        "}"
        "QPushButton:hover {"
        "    background-color: %8;"
        "    border-color: %8;"
        "}"
        "QPushButton:pressed {"
        "    background-color: %9;"
        "    border-color: %9;"
        "}"
    ).arg(m_primaryColor.name())
     .arg(m_backgroundColor.name())
     .arg(m_borderRadius)
     .arg(m_spacing)
     .arg(m_spacing * 2)
     .arg(m_buttonHeight)
     .arg(m_animationDuration)
     .arg(m_primaryColor.lighter(110).name())
     .arg(m_primaryColor.darker(120).name());
}

QString StyleManager::comboBoxStyle() const {
    return QString(
        "QComboBox {"
        "    background-color: %1;"
        "    color: %2;"
        "    border: 2px solid %3;"
        "    border-radius: %4px;"
        "    padding: 6px 12px 6px 12px;"
        "    font-weight: 500;"
        "    min-height: %5px;"
        "}"
        "QComboBox:hover {"
        "    border-color: %6;"
        "}"
        "QComboBox:focus {"
        "    border-color: %7;"
        "}"
        "QComboBox::drop-down {"
        "    border: none;"
        "    width: 24px;"
        "}"
        "QComboBox::down-arrow {"
        "    border-left: 4px solid transparent;"
        "    border-right: 4px solid transparent;"
        "    border-top: 5px solid %2;"
        "    margin-right: 8px;"
        "}"
        "QComboBox QAbstractItemView {"
        "    background-color: %1;"
        "    color: %2;"
        "    border: 2px solid %3;"
        "    border-top: none;"
        "}"
    ).arg(m_surfaceColor.name())
     .arg(m_textColor.name())
     .arg(m_borderColor.name())
     .arg(QString::number(m_borderRadius))
     .arg(m_buttonHeight)
     .arg(m_primaryColor.lighter(110).name())
     .arg(m_primaryColor.name());
}

QString StyleManager::inputStyle() const {
    return QString(
        "QLineEdit, QSpinBox {"
        "    background-color: %1;"
        "    color: %2;"
        "    border: 2px solid %3;"
        "    border-radius: %4px;"
        "    padding: %5px %6px;"
        "    min-height: %7px;"
        "}"
        "QLineEdit:focus, QSpinBox:focus {"
        "    border-color: %8;"
        "}"
    ).arg(m_surfaceColor.name())
     .arg(m_textColor.name())
     .arg(m_borderColor.name())
     .arg(m_borderRadius)
     .arg(m_spacing)
     .arg(m_spacing)
     .arg(m_buttonHeight)
     .arg(m_primaryColor.name());
}

QString StyleManager::labelStyle() const {
    return QString(
        "QLabel {"
        "    color: %1;"
        "}"
    ).arg(m_textColor.name());
}
