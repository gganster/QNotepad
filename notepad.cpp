#include "notepad.h"

Notepad::Notepad(QWidget *parent) : QMainWindow(parent)
{
    m_main = new QTextEdit;
    m_menubar = new QMenuBar;

    m_menu[FILE_SAVE] = new QMenu("&File");
        QAction *new_file = new QAction("&New");
            m_menu[FILE_SAVE]->addAction(new_file);
            connect(new_file, SIGNAL(triggered()), this, SLOT(new_file_slot()));
        QAction *open_file = new QAction("&Open");
            m_menu[FILE_SAVE]->addAction(open_file);
            connect(open_file, SIGNAL(triggered()), this, SLOT(open_slot()));
        QAction *save_file = new QAction("&Save");
            m_menu[FILE_SAVE]->addAction(save_file);
            connect(save_file, SIGNAL(triggered()), this, SLOT(save_slot()));
        QAction *save_file_as = new QAction("Save &As");
            m_menu[FILE_SAVE]->addAction(save_file_as);
            connect(save_file_as, SIGNAL(triggered()), this, SLOT(save_as_slot()));
        QAction *quit = new QAction("&Quitter", this);
            m_menu[FILE_SAVE]->addAction(quit);
            connect(quit, SIGNAL(triggered()), this, SLOT(close()));
    m_menu[DISPLAY] = new QMenu("&Display");
        QAction *color = new QAction("&Color");
            m_menu[DISPLAY]->addAction(color);
        QAction *font = new QAction("&Font");
            m_menu[DISPLAY]->addAction(font);
    m_menu[ABOUT] = new QMenu("&About");
        QAction *dev = new QAction("&Dev");
            m_menu[ABOUT]->addAction(dev);
        QAction *qt = new QAction("&Qt");
            m_menu[ABOUT]->addAction(qt);

    connect(m_main, SIGNAL(textChanged()), this, SLOT(modify_text()));
    for (int i = 0; i < NB_MENU; i++)
        m_menubar->addMenu(m_menu[i]);

    this->setMenuBar(m_menubar);
    this->setCentralWidget(m_main);
}

bool Notepad::open(QString path)
{
    QFile *file;

    if (!QFile::exists(path))
        return (0);
    file = new QFile(path);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        return (0);
    m_main->setText(file->readAll());
    this->path = path;
    file->close();
    delete file;
    this->is_saved = true;
    return (1);
}

bool Notepad::save(QString path)
{
    QFile *file;

    file = new QFile(path);
    if (!file->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate))
        return (0);
    QTextStream stream(file);
    stream << this->m_main->toPlainText();
    this->path = path;
    this->is_saved = true;
    file->close();
    delete file;
    return (1);
}
