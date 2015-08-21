/*  Preview.cpp
 *
 *  Copyright (C) 2013  Jim Evins <evins@snaught.com>
 *
 *  This file is part of gLabels-qt.
 *
 *  gLabels-qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels-qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Preview.h"

#include "LabelModel.h"

#include <QGraphicsRectItem>
#include <QGraphicsDropShadowEffect>
#include <QtDebug>


//
// Private Configuration Data
//
namespace
{
        const QColor  paperColor( 255, 255, 255 );
        const QColor  paperOutlineColor( 0, 0, 0 );
	const double  paperOutlineWidthPixels = 1;

        const QColor  shadowColor( 64, 64, 64 );
	const double  shadowOffsetPixels = 3;
	const double  shadowRadiusPixels = 12;

        const QColor  labelColor( 255, 255, 255 );
        const QColor  labelOutlineColor( 215, 215, 215 );
	const double  labelOutlineWidthPixels = 1;
}


namespace glabels
{

	///
	/// Constructor
	///
	Preview::Preview( QWidget *parent )
		: mModel(0), QGraphicsView(parent)
	{
		mScene = new QGraphicsScene();
		setScene( mScene );

		setAttribute(Qt::WA_TranslucentBackground);
		viewport()->setAutoFillBackground(false);

		setFrameStyle( QFrame::NoFrame );
		setRenderHints( QPainter::Antialiasing );
	}


	///
	/// Set model
	///
	void Preview::setModel( const LabelModel* model )
	{
		mModel = model;

		clearScene();

		if ( mModel != NULL )
		{
			// Set scene up with a 5% margin around paper
			double x = -0.05 * mModel->tmplate()->pageWidth();
			double y = -0.05 * mModel->tmplate()->pageHeight();
			double w = 1.10 * mModel->tmplate()->pageWidth();
			double h = 1.10 * mModel->tmplate()->pageHeight();

			mScene->setSceneRect( x, y, w, h );
			fitInView( mScene->sceneRect(), Qt::KeepAspectRatio );

			drawPaper( mModel->tmplate()->pageWidth(), mModel->tmplate()->pageHeight() );
			drawLabels();
		}
	}


	///
	/// Resize Event Handler
	///
	void Preview::resizeEvent( QResizeEvent* event )
	{
		fitInView( mScene->sceneRect(), Qt::KeepAspectRatio );
	}


	///
	/// Clear View
	///
	void Preview::clearScene()
	{
		foreach ( QGraphicsItem *item, mScene->items() )
		{
			mScene->removeItem( item );
			delete item;
		}
	}


	///
	/// Draw Paper
	///
	void Preview::drawPaper( double pw, double ph )
	{
		QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
		shadowEffect->setColor( shadowColor );
		shadowEffect->setOffset( shadowOffsetPixels );
		shadowEffect->setBlurRadius( shadowRadiusPixels );

		QBrush brush( paperColor );
		QPen pen( paperOutlineColor );
		pen.setCosmetic( true );
		pen.setWidthF( paperOutlineWidthPixels );

		QGraphicsRectItem *pageItem = new QGraphicsRectItem( 0, 0, pw, ph );
		pageItem->setBrush( brush );
		pageItem->setPen( pen );
		pageItem->setGraphicsEffect( shadowEffect );
				
		mScene->addItem( pageItem );
	}


	///
	/// Draw Labels on Paper
	///
	void Preview::drawLabels()
	{
		libglabels::Frame *frame = mModel->tmplate()->frames().first();

		foreach (libglabels::Point origin, frame->getOrigins() )
		{
			drawLabel( origin.x(), origin.y(), frame->path() );
		}
	}


	///
	/// Draw a Single Label at x,y
	///
	void Preview::drawLabel( double x, double y, const QPainterPath &path )
	{
		QBrush brush( labelColor );
		QPen pen( labelOutlineColor );
		pen.setStyle( Qt::DotLine );
		pen.setCosmetic( true );
		pen.setWidthF( labelOutlineWidthPixels );

		QGraphicsPathItem *labelItem  = new QGraphicsPathItem( path );
		labelItem->setBrush( brush );
		labelItem->setPen( pen );
		labelItem->setPos( x, y );

		mScene->addItem( labelItem );
	}


}