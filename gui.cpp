#include "gui.hpp"
#include "messagebox.hpp"
#include "canvas.hpp"

#include <QGraphicsLineItem>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMouseEvent>

#include <iostream>
#include <string>


GUI::GUI(QWidget* parent)
{
	MessageBox* message = new MessageBox;
	Canvas* canvas = new Canvas;
	timer = new QTimer();
	timer->setSingleShot(true);
	
	QGridLayout* layout = new QGridLayout;
	layout->addWidget(message, 0, 0);
	layout->addWidget(canvas, 1, 0);
	
	setLayout(layout);
	
	QObject::connect(canvas, SIGNAL(clicked(int)), this, SLOT(makeMove(int)));
	QObject::connect(this, SIGNAL(moveMade(int, int)), canvas, SLOT(addPiece(int, int)));
	QObject::connect(this, SIGNAL(sendMessage(QString)), message, SLOT(showMessage(QString)));
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(makeOptimalMove()));
}

void GUI::startClicked(bool xPlayer, bool oPlayer){
	this->show();
	this->xPlayer = xPlayer;
	this->oPlayer = oPlayer;
	if(this->xPlayer){
		timer->start(100);
	}
}

void GUI::makeMove(int pos){
	if(g.getWinner() == 0){
		g.makeMove(pos);
		emit moveMade(g.getMoveHist().back(), g.getPlayerHist().back());
		if(g.getWinner() == 0 && g.getMoveHist().size() < 9){
			if(g.getPlayerHist().back() == 1){
				emit sendMessage("O to play");
			}
			else{
				emit sendMessage("X to play");
			}
		}
		else if(g.getWinner() == 1){
			emit sendMessage("X wins");
		}
		else if(g.getWinner() == -1){
			emit sendMessage("O wins");
		}
		else if(g.getWinner() == 0 && g.getMoveHist().size() == 9){
			emit sendMessage("Tie");
		}
		
		if(g.getPlayerHist().back() == 1 && oPlayer){
			timer->start(1000);
		}
		else if(g.getPlayerHist().back() == -1 && xPlayer){
			timer->start(1000);
		}
	}
}

void GUI::makeOptimalMove(){
	if(g.getWinner() == 0){
		g.makeOptimalMove();
		emit moveMade(g.getMoveHist().back(), g.getPlayerHist().back());
		if(g.getWinner() == 0 && g.getMoveHist().size() < 9){
			if(g.getPlayerHist().back() == 1){
				emit sendMessage("O to play");
			}
			else{
				emit sendMessage("X to play");
			}
		}
		else if(g.getWinner() == 1){
			emit sendMessage("X wins");
		}
		else if(g.getWinner() == -1){
			emit sendMessage("O wins");
		}
		else if(g.getWinner() == 0 && g.getMoveHist().size() == 9){
			emit sendMessage("Tie");
		}
		
		if(g.getPlayerHist().back() == 1 && oPlayer){
			timer->start(1000);
		}
		else if(g.getPlayerHist().back() == -1 && xPlayer){
			timer->start(1000);
		}
	}
}

