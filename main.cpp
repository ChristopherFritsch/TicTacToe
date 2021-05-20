#include <iostream>
#include <QApplication>

#include "gui.hpp"
#include "playerwidget.hpp"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	
	GUI* gui = new GUI;
	PlayerWidget* player = new PlayerWidget;
	
	player->show();
	
	QObject::connect(player, SIGNAL(startClicked(bool, bool)), gui, SLOT(startClicked(bool, bool)));
	
	return app.exec();
}

