#include "cardeditor.h"

#include <QApplication>
#include <QTranslator>
#include <QDir>
#include <QFileInfo>
#include <QFontDatabase>

int main(int argc, char **argv){
	QApplication *app = new QApplication(argc, argv);

    QTranslator *translator = new QTranslator;
    translator->load("sanguosha-diy.qm");
    app->installTranslator(translator);

    QDir font_dir("font");
    foreach(QFileInfo info, font_dir.entryInfoList()){
        QFontDatabase::addApplicationFont(info.absoluteFilePath());
    }

	CardEditor *editor = new CardEditor();
    QObject::connect(app, SIGNAL(lastWindowClosed()), app, SLOT(quit()));

    editor->show();

	return app->exec();
}
