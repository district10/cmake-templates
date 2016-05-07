#include <QWidget>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );
	qDebug() << QString( "Hello World." );
    app.exec();
}
