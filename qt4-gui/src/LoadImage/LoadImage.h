#ifndef LOADIMAGE_H
#define LOADIMAGE_H

#include <QWidget>

namespace Ui {
class LoadImage;
}

class LoadImage : public QWidget
{
    Q_OBJECT

public:
    explicit LoadImage(QWidget *parent = 0);
    ~LoadImage();

private slots:
    void on_pushButton_loadimg_clicked();

private:
    Ui::LoadImage *ui;
};

#endif // LOADIMAGE_H
