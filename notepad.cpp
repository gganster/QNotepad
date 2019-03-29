#include "notepad.h"

Notepad::Notepad(QWidget *parent) : QMainWindow(parent)
{
    m_main = new QTextEdit;
    m_menubar = new QMenuBar;

    m_menu[FILE_SAVE] = new QMenu("&File");
        QAction *new_file = new QAction("&New");
            m_menu[FILE_SAVE]->addAction(new_file);
        QAction *save_file = new QAction("&Save");
            m_menu[FILE_SAVE]->addAction(save_file);
        QAction *save_file_as = new QAction("&Save as");
            m_menu[FILE_SAVE]->addAction(save_file_as);
        QAction *quit = new QAction("&Quitter", this);
            m_menu[FILE_SAVE]->addAction(quit);
    m_menu[DISPLAY] = new QMenu("&Display");
        QAction *color = new QAction("&Color");
            m_menu[DISPLAY]->addAction(color);
        QAction *font = new QAction("&Font");
            m_menu[DISPLAY]->addAction(font);
    m_menu[ABOUT] = new QMenu("&About");
        QAction *dev = new QAction("&Dev");

    for (int i = 0; i < NB_MENU; i++)
        m_menubar->addMenu(m_menu[i]);

    this->setMenuBar(m_menubar);
    this->setCentralWidget(m_main);
}
