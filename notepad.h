#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QStatusBar>
#include <QMenuBar>
#include <QLabel>
#include <QFileDialog>
#include <QTextEdit>
#include <cstdlib>

#define NB_MENU 3
enum {FILE_SAVE, DISPLAY, ABOUT};

class Notepad : public QMainWindow
{
    Q_OBJECT
public:
    Notepad(QWidget *parent = nullptr);
private:
    QMenuBar *m_menubar;
    QMenu *m_menu[NB_MENU];

    QTextEdit *m_main;

    QStatusBar *m_statusbar;
};

#endif // NOTEPAD_H
