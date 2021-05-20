#ifndef GUI_HPP
#define GUI_HPP

#include <QWidget>
#include <QGraphicsItem>

#include <QComboBox>
#include <QLayout>
#include <QTimer>
#include <QPoint>

#include "game.hpp"

class GUI : public QWidget
{
	Q_OBJECT
	public:
		GUI(QWidget* parent = nullptr);
	
	signals:
		void moveMade(int pos, int player);
		void sendMessage(QString message);
	private slots:
		void startClicked(bool xPlayer, bool oPlayer);
		void makeMove(int pos);
		void makeOptimalMove();
	private:
		Game g;
		bool xPlayer;
		bool oPlayer;
		QTimer* timer;
};
#endif /* GUI_HPP */ 
