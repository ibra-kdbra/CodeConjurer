#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include <QObject>
#include <QString>
#include <QColor>
#include <QFont>

class StyleManager : public QObject {
    Q_OBJECT

public:
    enum Theme {
        Light,
        Dark,
        ModernBlue,
        ModernGreen
    };

    static StyleManager* instance();

    void setTheme(Theme theme);
    Theme currentTheme() const { return m_currentTheme; }

    // Color palette
    QColor primaryColor() const { return m_primaryColor; }
    QColor secondaryColor() const { return m_secondaryColor; }
    QColor accentColor() const { return m_accentColor; }
    QColor backgroundColor() const { return m_backgroundColor; }
    QColor surfaceColor() const { return m_surfaceColor; }
    QColor textColor() const { return m_textColor; }
    QColor textColorSecondary() const { return m_textColorSecondary; }
    QColor borderColor() const { return m_borderColor; }

    // Typography
    QFont titleFont() const { return m_titleFont; }
    QFont bodyFont() const { return m_bodyFont; }
    QFont buttonFont() const { return m_buttonFont; }

    // Spacing and sizing
    int spacing() const { return m_spacing; }
    int margin() const { return m_margin; }
    int borderRadius() const { return m_borderRadius; }
    int buttonHeight() const { return m_buttonHeight; }

    // Animation durations
    int animationDuration() const { return m_animationDuration; }

    // Modern styling strings
    QString buttonStyle() const;
    QString inputStyle() const;
    QString labelStyle() const;
    QString comboBoxStyle() const;
    QString mainWindowStyle() const;
    QString messageBoxStyle() const;

private:
    explicit StyleManager(QObject *parent = nullptr);
    void applyLightTheme();
    void applyDarkTheme();
    void applyModernBlueTheme();
    void applyModernGreenTheme();
    void updateApplicationPalette();

    static StyleManager* m_instance;

    Theme m_currentTheme;

    // Colors
    QColor m_primaryColor;
    QColor m_secondaryColor;
    QColor m_accentColor;
    QColor m_backgroundColor;
    QColor m_surfaceColor;
    QColor m_textColor;
    QColor m_textColorSecondary;
    QColor m_borderColor;

    // Typography
    QFont m_titleFont;
    QFont m_bodyFont;
    QFont m_buttonFont;

    // Layout
    int m_spacing;
    int m_margin;
    int m_borderRadius;
    int m_buttonHeight;
    int m_animationDuration;

signals:
    void themeChanged();
};

#endif // STYLEMANAGER_H
