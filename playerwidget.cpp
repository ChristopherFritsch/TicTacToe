
#include "playerwidget.hpp"


PlayerWidget::PlayerWidget(QWidget* parent)
{
	xBox = new QComboBox;
	xBox->addItem("Player");
	xBox->addItem("Computer");
	
	QLabel* xLabel = new QLabel("X is a ");
	
	oBox = new QComboBox;
	oBox->addItem("Player");
	oBox->addItem("Computer");
	
	QLabel* oLabel = new QLabel("O is a ");
	
	button = new QPushButton("Start");
	
	QGridLayout* layout = new QGridLayout;
	layout->addWidget(xLabel, 0, 0);
	layout->addWidget(xBox, 0, 1);
	layout->addWidget(oLabel, 1, 0);
	layout->addWidget(oBox, 1, 1);
	layout->addWidget(button, 2, 1);
	setLayout(layout);
	
	QObject::connect(button, SIGNAL(pressed()), this, SLOT(hidePlayer()));
}

void PlayerWidget::hidePlayer(){
	this->hide();
	emit startClicked(xBox->currentIndex(), oBox->currentIndex());
}


