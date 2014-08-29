#include "cgraphicbutton.h"
#include <QPainter>
#include <QApplication>
#include <qdebug.h>

CGraphicButton::CGraphicButton()
{
    setFixedSize(30,30);
    dzienSwiateczny=false;
    connect(this,SIGNAL(clicked()),this,SLOT(clickedButton()));
}
void CGraphicButton::enterEvent(QEvent *)
{   setCursor(Qt::OpenHandCursor);}
void CGraphicButton::mousePressEvent(QMouseEvent *e)
{   Q_UNUSED(e);
    if(e->button()==Qt::LeftButton)
    {   setCursor(Qt::ClosedHandCursor);
        dzienSwiateczny= !dzienSwiateczny;
        QPushButton::mousePressEvent(e);
    }
    else
        e->ignore();
}
void CGraphicButton::mouseReleaseEvent(QMouseEvent *e)
{   Q_UNUSED(e);
    setCursor(Qt::OpenHandCursor);
    QPushButton::mouseReleaseEvent(e);
}
void CGraphicButton::paintEvent(QPaintEvent *event)
{
    QPalette pal(palette());
    pal.setColor(QPalette::Background,QColor(230,200,167));
    if(dzienSwiateczny==true)
    {   this->setStyleSheet("*{background-color: rgb(253,95,9,220)}");}
    else
    {   this->setStyleSheet("*{background-color: rgb(100,235,167,150)}");}
    QPushButton::paintEvent(event);
}
bool& CGraphicButton::getSwiateczny()
{   return dzienSwiateczny;}
void CGraphicButton::clickedButton()
{   int x = this->text().toDouble();
    emit dzienZmieniony(x,dzienSwiateczny);
}
