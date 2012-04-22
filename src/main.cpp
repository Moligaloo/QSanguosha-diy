#include "cardeditor.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char **argv){
	QApplication *app = new QApplication(argc, argv);

    QTranslator *translator = new QTranslator;
    translator->load("sanguosha-diy.qm");
    app->installTranslator(translator);

	CardEditor *editor = new CardEditor();
    QObject::connect(app, SIGNAL(lastWindowClosed()), app, SLOT(quit()));

    editor->show();

	return app->exec();
}
