#include "canvas.hpp"

#include <iostream>
#include <QLayout>
#include <QMouseEvent>
#include <QPen>


Canvas::Canvas(QWidget* parent)
{
	scene = new QGraphicsScene;
	QGraphicsView* view = new QGraphicsView(scene);
	
	QPen pen;
	pen.setWidth(3);
	
	scene->addLine(170.6, 0, 170.6, 512, pen);
	scene->addLine(341.3, 0, 341.3, 512, pen);
	scene->addLine(0, 170.6, 512, 170.6, pen);
	scene->addLine(0, 341.3, 512, 341.3, pen);
	
	//view->resize(512, 512);
	view->centerOn(256, 256);
	
	QGridLayout* layout = new QGridLayout;
	layout->addWidget(view, 0, 0);
	setLayout(layout);
}

void Canvas::mousePressEvent(QMouseEvent* event){
	if (event->button() == Qt::LeftButton) {
        QPoint point = event->pos();
        int pos = -1;
        
        if(point.x() < 182  && point.y() < 182){
			pos = 0;
		}
		else if(point.x() > 182 && point.x() < 352 && point.y() < 182){
			pos = 1;
		}
		else if(point.x() > 352 && point.y() < 182){
			pos = 2;
		}
		else if(point.x() < 182 && point.y() > 182 && point.y() < 352){
			pos = 3;
		}
		else if(point.x() > 182 && point.x() < 352 && point.y() > 182 && point.y() < 352){
			pos = 4;
		}
		else if(point.x() > 352 && point.y() > 182 && point.y() < 352){
			pos = 5;
		}
		else if(point.x() < 182 && point.y() > 352){
			pos = 6;
		}
		else if(point.x() > 182 && point.x() < 352 && point.y() > 352){
			pos = 7;
		}
		else if(point.x() > 352 && point.y() > 352){
			pos = 8;
		}
		
		emit clicked(pos);
    }
}

void Canvas::addPiece(int pos, int player){
	QPen pen;
	pen.setWidth(5);
	
	int x1, x2, y1, y2;
	
	if(pos == 0 || pos == 3 || pos == 6){
		x1 = 20;
		x2 = 151;
	}
	else if(pos == 1 || pos == 4 || pos ==7){
		x1 = 191;
		x2 = 321;
	}
	else{
		x1 = 361;
		x2 = 492;
	}
	
	if(pos == 0 || pos == 1 || pos == 2){
		y1 = 20;
		y2 = 151;
	}
	else if(pos == 3 || pos == 4 || pos == 5){
		y1 = 191;
		y2 = 321;
	}
	else{
		y1 = 361;
		y2 = 492;
	}
	
	if(player == 1){
		pen.setColor(Qt::red);
		scene->addLine(x1, y1, x2, y2, pen);
		scene->addLine(x1, y2, x2, y1, pen);
	}
	else{
		pen.setColor(Qt::blue);
		scene->addEllipse(x1, y1, 131, 131, pen);
	}
}


