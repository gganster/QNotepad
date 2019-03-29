#include "notepad.h"

void Notepad::open_slot()
{
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

    QMessageBox::information(this, "test", path);
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

}
