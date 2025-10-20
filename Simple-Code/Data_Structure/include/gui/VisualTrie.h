#ifndef VISUALTRIE_H
#define VISUALTRIE_H

#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <unordered_map>
#include <vector>

struct TrieNode {
    bool isEnd;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() : isEnd(false) {}
};

class VisualTrie : public QWidget {
    Q_OBJECT

public:
    VisualTrie(QWidget *parent = nullptr);
    ~VisualTrie();

private slots:
    void onInsert();
    void onSearch();
    void onStartsWith();

private:
    void updateVisualization();
    void drawTrie(TrieNode* node, int x, int y, int level, QGraphicsScene* scene);
    void deleteTrie(TrieNode* node);
    void collectWords(TrieNode* node, QString current, std::vector<QString>& words);

    TrieNode* root;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QLineEdit *wordInput;
    QLabel *complexityLabel;
    int nodeRadius;
};

#endif // VISUALTRIE_H
