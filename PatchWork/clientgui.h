#ifndef CLIENTGUI_H
#define CLIENTGUI_H

#include <QWidget>

namespace Ui {
class ClientGui;
}

class ClientGui : public QWidget
{
    Q_OBJECT

public:
    explicit ClientGui(QWidget *parent = 0);
    ~ClientGui();

private:
    Ui::ClientGui *ui;
};

#endif // CLIENTGUI_H
