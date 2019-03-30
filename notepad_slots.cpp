#include "notepad.h"

void Notepad::open_slot()
{
    if (this->is_saved == false) {
        int save = QMessageBox::question(this, "save", "the file is'nt saved, would you save ?", QMessageBox::Yes | QMessageBox::No);
        if (save == QMessageBox::Yes)
            save_slot();
    }
    QString path = QFileDialog::getOpenFileName(this, "Open an file", QString(), "");

    if (path.isEmpty())
        return;
    if (!open(path))
        return;
    else
        QMessageBox::warning(this, "error", "Error when open file");
}

void Notepad::save_slot()
{
    if (this->path == "0") {
        save_as_slot();
        return;
    }
    if (save(path))
        return;
    else
        QMessageBox::warning(this, "error", "Error when write file");
}

void Notepad::save_as_slot()
{
    QString path = QFileDialog::getSaveFileName(this, "Open an file", QString(), "");

    if (path.isEmpty())
        return;
    if (save(path))
        return;
    else
        QMessageBox::warning(this, "error", "Error when write file");
}

void Notepad::new_file_slot()
{
    this->path = "0";
    this->m_main->setText("");
}

void Notepad::modify_text()
{
    is_saved = false;
}

void Notepad::close_slot()
{
    if (this->is_saved)
            return;
    int save = QMessageBox::question(this, "save", "the file is'nt saved, would you save ?", QMessageBox::Yes | QMessageBox::No);
    if (save == QMessageBox::Yes)
        save_slot();
}

void Notepad::font_slot()
{
    bool selected = false;
    QFont font = QFontDialog::getFont(&selected, m_main->font(), this, "choose a font");
    if (selected)
        m_main->setFont(font);
}

void Notepad::color_slot()
{
    QColor color = QColorDialog::getColor(m_main->textColor(), this, "select color");
    QPalette palette(color);
    m_main->setPalette(palette);
    m_main->setTextColor(color);
}

void Notepad::about_dev()
{
    QMessageBox::information(this, "about", "developper: Guilian Ganster\n"
                                            "github: https://github.com/zoraneus\n"
                                            "website: ganster-dev.fr");
}
