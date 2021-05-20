#ifndef MESSAGEBOX_HPP
#define MESSAGEBOX_HPP

#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QWidget>

class MessageBox : public QWidget
{
	Q_OBJECT
	public:
		MessageBox(QWidget* parent = nullptr);
	signals:
	private slots:
		void showMessage(QString message);
			
	private:
		QLineEdit* messageBox;
};

#endif /* MESSAGEBOX_HPP */ 
