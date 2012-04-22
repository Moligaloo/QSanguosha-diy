#include "cardeditor.h"

#include <QApplication>

int main(int argc, char **argv){
	QApplication *app = new QApplication(argc, argv);

	CardEditor *editor = new CardEditor();
    QObject::connect(app, SIGNAL(lastWindowClosed()), app, SLOT(quit()));

    editor->show();

	return app->exec();
}
