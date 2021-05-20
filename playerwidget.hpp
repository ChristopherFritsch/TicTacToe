#ifndef PLAYERWIDGET_HPP
#define PLAYERWIDGET_HPP

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QLayout>

class PlayerWidget : public QWidget
{
	Q_OBJECT
	public:
		PlayerWidget(QWidget* parent = nullptr);
		QComboBox* xBox;
		QComboBox* oBox;
		QPushButton* button;
	signals:
		void startClicked(bool xPlayer, bool oPlayer);
	private slots:
		void hidePlayer();
	private:
	
		
};

#endif /* PLAYERWIDGET_HPP */ 
