#include "LoadImage.h"
#include "ui_LoadImage.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include "Configs.h"

#ifndef IMAGE_DIR
#define IMAGE_DIR ""
#endif

LoadImage::LoadImage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadImage)
{
    ui->setupUi(this);
}

LoadImage::~LoadImage()
{
    delete ui;
}

void LoadImage::on_pushButton_loadimg_clicked()
{
    QString fileName = QFileDialog::getOpenFileName( 0, QString(), IMAGE_DIR,
                                                     tr("Images (*.png *.jpg)") );
    QImage image;
    if ( !image.load(fileName) ) {
        ui->image_label->setText( tr("Selected file is not an image, please select another.") );
        return;
    }
    ui->image_label->setPixmap( QPixmap::fromImage(image) );
}
