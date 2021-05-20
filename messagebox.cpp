#include "messagebox.hpp"

#include <QLabel>



MessageBox::MessageBox(QWidget* parent){
	
	QLabel* messageLabel = new QLabel("TicTacToe >> ");
	
	messageBox = new QLineEdit("X to play");
	messageBox->setReadOnly(true);
	
	QGridLayout* layout = new QGridLayout;
	
	layout->addWidget(messageLabel, 0, 0);
	layout->addWidget(messageBox, 0, 1);
	setLayout(layout);
}

void MessageBox::showMessage(QString message){
	messageBox->setText(message);
}
