#include <QApplication>
#include "notepad.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Notepad *note = new Notepad;
    note->show();
    return (app.exec());
}
