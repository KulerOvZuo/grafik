#ifndef CGRAPHICBUTTON_H
#define CGRAPHICBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class CGraphicButton : public QPushButton
{
    Q_OBJECT
public:
    CGraphicButton();

    bool& getSwiateczny();
protected:
    void enterEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);

    bool dzienSwiateczny;
private slots:
    void clickedButton();
signals:
    void dzienZmieniony(int,bool);
};

#endif // CGRAPHICBUTTON_H
