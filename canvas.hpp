#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class Canvas : public QWidget
{
	Q_OBJECT
	public:
		Canvas(QWidget* parent = nullptr);
		
	signals:
		void clicked(int pos);
		
	private slots:
		void addPiece(int pos, int player);
		
	private:
		QGraphicsScene* scene;
		void mousePressEvent(QMouseEvent* event);
};

#endif /* CANVAS_HPP */ 
