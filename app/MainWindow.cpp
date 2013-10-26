/*  MainWindow.cpp
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

#include "MainWindow.h"

#include <QLabel>

#include <iostream>

#include "Icons.h"
#include "Help.h"


namespace gLabels
{

	MainWindow::MainWindow()
	{
		QLabel *tmp = new QLabel( "Coming Soon..." );
		setCentralWidget( tmp );

		createActions();
		createMenus();
	}


	void MainWindow::closeEvent( QCloseEvent *event )
	{
		std::cout << "CLOSE EVENT" << std::endl;
		event->accept();
	}


	void MainWindow::createActions()
	{
		/* File actions */
		fileNewAction = new QAction( tr("&New..."), this );
		fileNewAction->setIcon( QIcon::fromTheme( "document-new" ) );
		fileNewAction->setShortcut( QKeySequence::New );
		fileNewAction->setStatusTip( tr("Create a new file") );
		connect( fileNewAction, SIGNAL(triggered()), this, SLOT(fileNew()) );

		fileOpenAction = new QAction( tr("&Open..."), this );
		fileOpenAction->setIcon( QIcon::fromTheme( "document-open" ) );
		fileOpenAction->setShortcut( QKeySequence::Open );
		fileOpenAction->setStatusTip( tr("Open a file") );
		connect( fileOpenAction, SIGNAL(triggered()), this, SLOT(fileOpen()) );

		fileSaveAction = new QAction( tr("&Save"), this );
		fileSaveAction->setIcon( QIcon::fromTheme( "document-save" ) );
		fileSaveAction->setShortcut( QKeySequence::Save );
		fileSaveAction->setStatusTip( tr("Save current file") );
		connect( fileSaveAction, SIGNAL(triggered()), this, SLOT(fileSave()) );

		fileSaveAsAction = new QAction( tr("Save &As..."), this );
		fileSaveAsAction->setIcon( QIcon::fromTheme( "document-save-as" ) );
		fileSaveAsAction->setShortcut( QKeySequence::SaveAs );
		fileSaveAsAction->setStatusTip( tr("Save current file to a different name") );
		connect( fileSaveAsAction, SIGNAL(triggered()), this, SLOT(fileSaveAs()) );

		filePrintAction = new QAction( tr("&Print..."), this );
		filePrintAction->setIcon( QIcon::fromTheme( "document-print" ) );
		filePrintAction->setShortcut( QKeySequence::Print );
		filePrintAction->setStatusTip( tr("Print the current file") );
		connect( filePrintAction, SIGNAL(triggered()), this, SLOT(filePrint()) );

		filePropertiesAction = new QAction( tr("Properties..."), this );
		filePropertiesAction->setIcon( QIcon::fromTheme( "document-properties" ) );
		filePropertiesAction->setStatusTip( tr("Modify document properties") );
		connect( filePropertiesAction, SIGNAL(triggered()), this, SLOT(fileProperties()) );

		fileTemplateDesignerAction = new QAction( tr("Template &Designer..."), this );
		fileTemplateDesignerAction->setStatusTip( tr("Create custom templates") );
		connect( fileTemplateDesignerAction, SIGNAL(triggered()), this, SLOT(fileTemplateDesigner()) );

		fileCloseAction = new QAction( tr("&Close"), this );
		fileCloseAction->setIcon( QIcon::fromTheme( "window-close" ) );
		fileCloseAction->setShortcut( QKeySequence::Close );
		fileCloseAction->setStatusTip( tr("Close the current window") );
		connect( fileCloseAction, SIGNAL(triggered()), this, SLOT(fileClose()) );

		fileExitAction = new QAction( tr("E&xit"), this );
		fileExitAction->setIcon( QIcon::fromTheme( "application-exit" ) );
		fileExitAction->setShortcut( QKeySequence::Quit );
		fileExitAction->setStatusTip( tr("Exit glabels") );
		connect( fileExitAction, SIGNAL(triggered()), this, SLOT(fileExit()) );


		/* Edit actions */
		editUndoAction = new QAction( tr("Undo"), this );
		editUndoAction->setIcon( QIcon::fromTheme( "edit-undo" ) );
		editUndoAction->setShortcut( QKeySequence::Undo );
		editUndoAction->setStatusTip( tr("Undo") );
		connect( editUndoAction, SIGNAL(triggered()), this, SLOT(editUndo()) );

		editRedoAction = new QAction( tr("Redo"), this );
		editRedoAction->setIcon( QIcon::fromTheme( "edit-redo" ) );
		editRedoAction->setShortcut( QKeySequence::Redo );
		editRedoAction->setStatusTip( tr("Redo") );
		connect( editRedoAction, SIGNAL(triggered()), this, SLOT(editRedo()) );

		editCutAction = new QAction( tr("Cut"), this );
		editCutAction->setIcon( QIcon::fromTheme( "edit-cut" ) );
		editCutAction->setShortcut( QKeySequence::Cut );
		editCutAction->setStatusTip( tr("Cut the selection") );
		connect( editCutAction, SIGNAL(triggered()), this, SLOT(editCut()) );

		editCopyAction = new QAction( tr("&Copy"), this );
		editCopyAction->setIcon( QIcon::fromTheme( "edit-copy" ) );
		editCopyAction->setShortcut( QKeySequence::Copy );
		editCopyAction->setStatusTip( tr("Copy the selection") );
		connect( editCopyAction, SIGNAL(triggered()), this, SLOT(editCopy()) );

		editPasteAction = new QAction( tr("&Paste"), this );
		editPasteAction->setIcon( QIcon::fromTheme( "edit-paste" ) );
		editPasteAction->setShortcut( QKeySequence::Paste );
		editPasteAction->setStatusTip( tr("Paste the clipboard") );
		connect( editPasteAction, SIGNAL(triggered()), this, SLOT(editPaste()) );

		editDeleteAction = new QAction( tr("&Delete"), this );
		editDeleteAction->setIcon( QIcon::fromTheme( "edit-delete" ) );
		editDeleteAction->setShortcut( QKeySequence::Delete );
		editDeleteAction->setStatusTip( tr("Delete the selected objects") );
		connect( editDeleteAction, SIGNAL(triggered()), this, SLOT(editDelete()) );

		editSelectAllAction = new QAction( tr("Select &All"), this );
		editSelectAllAction->setIcon( QIcon::fromTheme( "edit-select-all" ) );
		editSelectAllAction->setShortcut( QKeySequence::SelectAll );
		editSelectAllAction->setStatusTip( tr("Select all objects") );
		connect( editSelectAllAction, SIGNAL(triggered()), this, SLOT(editSelectAll()) );

		editUnSelectAllAction = new QAction( tr("Un-select All"), this );
		editUnSelectAllAction->setIcon( QIcon::fromTheme( "edit-unselect-all" ) );
		editUnSelectAllAction->setStatusTip( tr("Remove all selections") );
		connect( editUnSelectAllAction, SIGNAL(triggered()), this, SLOT(editUnSelectAll()) );

		editPreferencesAction = new QAction( tr("Preferences"), this );
		editPreferencesAction->setIcon( QIcon::fromTheme( "edit-preferences" ) );
		editPreferencesAction->setShortcut( QKeySequence::Preferences );
		editPreferencesAction->setStatusTip( tr("Configure the application") );
		connect( editPreferencesAction, SIGNAL(triggered()), this, SLOT(editPreferences()) );


		/* View actions */
		viewMainToolbarAction = new QAction( tr("Main Toolbar"), this );
		viewMainToolbarAction->setCheckable( true );
		viewMainToolbarAction->setStatusTip( tr("Change visibility of main toolbar in current window") );
		connect( viewMainToolbarAction, SIGNAL(triggered()), this, SLOT(viewMainToolbar()) );

		viewDrawingToolbarAction = new QAction( tr("Drawing Toolbar"), this );
		viewDrawingToolbarAction->setCheckable( true );
		viewDrawingToolbarAction->setStatusTip( tr("Change visibility of drawing toolbar in current window") );
		connect( viewDrawingToolbarAction, SIGNAL(triggered()), this, SLOT(viewDrawingToolbar()) );

		viewGridAction = new QAction( tr("Grid"), this );
		viewGridAction->setCheckable( true );
		viewGridAction->setStatusTip( tr("Change visibility of the grid in current window") );
		connect( viewGridAction, SIGNAL(triggered()), this, SLOT(viewGrid()) );

		viewMarkupAction = new QAction( tr("Markup"), this );
		viewMarkupAction->setCheckable( true );
		viewMarkupAction->setStatusTip( tr("Change visibility of markup lines in current window") );
		connect( viewMarkupAction, SIGNAL(triggered()), this, SLOT(viewMarkup()) );

		viewZoomInAction = new QAction( tr("Zoom &In"), this );
		viewZoomInAction->setIcon( QIcon::fromTheme( "zoom-in" ) );
		viewZoomInAction->setShortcut( QKeySequence::ZoomIn );
		viewZoomInAction->setStatusTip( tr("Increase magnification") );
		connect( viewZoomInAction, SIGNAL(triggered()), this, SLOT(viewZoomIn()) );

		viewZoomOutAction = new QAction( tr("Zoom &Out"), this );
		viewZoomOutAction->setIcon( QIcon::fromTheme( "zoom-out" ) );
		viewZoomOutAction->setShortcut( QKeySequence::ZoomOut );
		viewZoomOutAction->setStatusTip( tr("Decrease magnification") );
		connect( viewZoomOutAction, SIGNAL(triggered()), this, SLOT(viewZoomOut()) );

		viewZoom1to1Action = new QAction( tr("Zoom &1 to 1"), this );
		viewZoom1to1Action->setIcon( QIcon::fromTheme( "zoom-original" ) );
		viewZoom1to1Action->setStatusTip( tr("Restore scale to 100%") );
		connect( viewZoom1to1Action, SIGNAL(triggered()), this, SLOT(viewZoom1to1()) );

		viewZoomToFitAction = new QAction( tr("Zoom to &Fit"), this );
		viewZoomToFitAction->setIcon( QIcon::fromTheme( "zoom-fit-best" ) );
		viewZoomToFitAction->setStatusTip( tr("Set scale to fit window") );
		connect( viewZoomToFitAction, SIGNAL(triggered()), this, SLOT(viewZoomToFit()) );


		/* Object actions */
		objectsArrowModeAction = new QAction( tr("Select Mode"), this );
		objectsArrowModeAction->setIcon( Icons::Arrow() );
		objectsArrowModeAction->setStatusTip( tr("Select, move and modify objects") );
		connect( objectsArrowModeAction, SIGNAL(triggered()), this, SLOT(objectsArrowMode()) );

		objectsCreateTextAction = new QAction( tr("Text"), this );
		objectsCreateTextAction->setIcon( Icons::Text() );
		objectsCreateTextAction->setStatusTip( tr("Create text object") );
		connect( objectsCreateTextAction, SIGNAL(triggered()), this, SLOT(objectsCreateText()) );

		objectsCreateBoxAction = new QAction( tr("Box"), this );
		objectsCreateBoxAction->setIcon( Icons::Box() );
		objectsCreateBoxAction->setStatusTip( tr("Create box object") );
		connect( objectsCreateBoxAction, SIGNAL(triggered()), this, SLOT(objectsCreateBox()) );

		objectsCreateLineAction = new QAction( tr("Line"), this );
		objectsCreateLineAction->setIcon( Icons::Line() );
		objectsCreateLineAction->setStatusTip( tr("Create line object") );
		connect( objectsCreateLineAction, SIGNAL(triggered()), this, SLOT(objectsCreateLine()) );

		objectsCreateEllipseAction = new QAction( tr("Ellipse"), this );
		objectsCreateEllipseAction->setIcon( Icons::Ellipse() );
		objectsCreateEllipseAction->setStatusTip( tr("Create ellipse/circle object") );
		connect( objectsCreateEllipseAction, SIGNAL(triggered()), this, SLOT(objectsCreateEllipse()) );

		objectsCreateImageAction = new QAction( tr("Image"), this );
		objectsCreateImageAction->setIcon( Icons::Image() );
		objectsCreateImageAction->setStatusTip( tr("Create image object") );
		connect( objectsCreateImageAction, SIGNAL(triggered()), this, SLOT(objectsCreateImage()) );

		objectsCreateBarcodeAction = new QAction( tr("Barcode"), this );
		objectsCreateBarcodeAction->setIcon( Icons::Barcode() );
		objectsCreateBarcodeAction->setStatusTip( tr("Create barcode object") );
		connect( objectsCreateBarcodeAction, SIGNAL(triggered()), this, SLOT(objectsCreateBarcode()) );

		objectsOrderRaiseAction = new QAction( tr("Bring To Front"), this );
		objectsOrderRaiseAction->setIcon( Icons::OrderTop() );
		objectsOrderRaiseAction->setStatusTip( tr("Raise selection to top") );
		connect( objectsOrderRaiseAction, SIGNAL(triggered()), this, SLOT(objectsOrderRaise()) );

		objectsOrderLowerAction = new QAction( tr("Send To Back"), this );
		objectsOrderLowerAction->setIcon( Icons::OrderBottom() );
		objectsOrderLowerAction->setStatusTip( tr("Lower selection to bottom") );
		connect( objectsOrderLowerAction, SIGNAL(triggered()), this, SLOT(objectsOrderLower()) );

		objectsXformRotateLeftAction = new QAction( tr("Rotate Left"), this );
		objectsXformRotateLeftAction->setIcon( Icons::RotateLeft() );
		objectsXformRotateLeftAction->setStatusTip( tr("Rotate object(s) 90 degrees counter-clockwise") );
		connect( objectsXformRotateLeftAction, SIGNAL(triggered()), this, SLOT(objectsXformRotateLeft()) );

		objectsXformRotateRightAction = new QAction( tr("Rotate Right"), this );
		objectsXformRotateRightAction->setIcon( Icons::RotateRight() );
		objectsXformRotateRightAction->setStatusTip( tr("Rotate object(s) 90 degrees clockwise") );
		connect( objectsXformRotateRightAction, SIGNAL(triggered()), this, SLOT(objectsXformRotateRight()) );

		objectsXformFlipHorizAction = new QAction( tr("Flip Horizontally"), this );
		objectsXformFlipHorizAction->setIcon( Icons::FlipHoriz() );
		objectsXformFlipHorizAction->setStatusTip( tr("Flip object(s) horizontally") );
		connect( objectsXformFlipHorizAction, SIGNAL(triggered()), this, SLOT(objectsXformFlipHoriz()) );

		objectsXformFlipVertAction = new QAction( tr("Flip Vertically"), this );
		objectsXformFlipVertAction->setIcon( Icons::FlipVert() );
		objectsXformFlipVertAction->setStatusTip( tr("Flip object(s) vertically") );
		connect( objectsXformFlipVertAction, SIGNAL(triggered()), this, SLOT(objectsXformFlipVert()) );

		objectsAlignLeftAction = new QAction( tr("Align Left"), this );
		objectsAlignLeftAction->setIcon( Icons::AlignLeft() );
		objectsAlignLeftAction->setStatusTip( tr("Align objects to left edges") );
		connect( objectsAlignLeftAction, SIGNAL(triggered()), this, SLOT(objectsAlignLeft()) );

		objectsAlignHCenterAction = new QAction( tr("Align Center"), this );
		objectsAlignHCenterAction->setIcon( Icons::AlignHCenter() );
		objectsAlignHCenterAction->setStatusTip( tr("Align objects to horizontal centers") );
		connect( objectsAlignHCenterAction, SIGNAL(triggered()), this, SLOT(objectsAlignHCenter()) );

		objectsAlignRightAction = new QAction( tr("Align Right"), this );
		objectsAlignRightAction->setIcon( Icons::AlignRight() );
		objectsAlignRightAction->setStatusTip( tr("Align objects to right edges") );
		connect( objectsAlignRightAction, SIGNAL(triggered()), this, SLOT(objectsAlignRight()) );

		objectsAlignTopAction = new QAction( tr("Align Top"), this );
		objectsAlignTopAction->setIcon( Icons::AlignTop() );
		objectsAlignTopAction->setStatusTip( tr("Align objects to top edges") );
		connect( objectsAlignTopAction, SIGNAL(triggered()), this, SLOT(objectsAlignTop()) );

		objectsAlignVCenterAction = new QAction( tr("Align Middle"), this );
		objectsAlignVCenterAction->setIcon( Icons::AlignVCenter() );
		objectsAlignVCenterAction->setStatusTip( tr("Align objects to vertical centers") );
		connect( objectsAlignVCenterAction, SIGNAL(triggered()), this, SLOT(objectsAlignVCenter()) );

		objectsAlignBottomAction = new QAction( tr("Align Bottom"), this );
		objectsAlignBottomAction->setIcon( Icons::AlignBottom() );
		objectsAlignBottomAction->setStatusTip( tr("Align objects to bottom edges") );
		connect( objectsAlignBottomAction, SIGNAL(triggered()), this, SLOT(objectsAlignBottom()) );

		objectsCenterHorizAction = new QAction( tr("Center Horizontally"), this );
		objectsCenterHorizAction->setIcon( Icons::CenterHoriz() );
		objectsCenterHorizAction->setStatusTip( tr("Horizontally center objects in label") );
		connect( objectsCenterHorizAction, SIGNAL(triggered()), this, SLOT(objectsCenterHoriz()) );

		objectsCenterVertAction = new QAction( tr("Center Vertically"), this );
		objectsCenterVertAction->setIcon( Icons::CenterVert() );
		objectsCenterVertAction->setStatusTip( tr("Vertically center objects in label") );
		connect( objectsCenterVertAction, SIGNAL(triggered()), this, SLOT(objectsCenterVert()) );

		objectsMergePropertiesAction = new QAction( tr("Merge Properties..."), this );
		objectsMergePropertiesAction->setIcon( Icons::Merge() );
		objectsMergePropertiesAction->setStatusTip( tr("Edit merge properties") );
		connect( objectsMergePropertiesAction, SIGNAL(triggered()), this, SLOT(objectsMergeProperties()) );


		/* Help actions */
		helpContentsAction = new QAction( tr("&Contents..."), this );
		helpContentsAction->setIcon( QIcon::fromTheme( "help-contents" ) );
		helpContentsAction->setShortcut( QKeySequence::HelpContents );
		helpContentsAction->setStatusTip( tr("Open gLabels manual") );
		connect( helpContentsAction, SIGNAL(triggered()), this, SLOT(helpContents()) );

		helpAboutAction = new QAction( tr("&About..."), this );
		helpAboutAction->setIcon( QIcon::fromTheme( "help-about" ) );
		helpAboutAction->setStatusTip( tr("About gLabels") );
		connect( helpAboutAction, SIGNAL(triggered()), this, SLOT(helpAbout()) );
	}


	void MainWindow::createMenus()
	{
		fileMenu = menuBar()->addMenu( tr("&File") );
		fileMenu->addAction( fileNewAction );
		fileMenu->addAction( fileOpenAction );
		fileMenu->addAction( fileSaveAction );
		fileMenu->addAction( fileSaveAsAction );
		fileMenu->addSeparator();
		fileMenu->addAction( filePrintAction );
		fileMenu->addSeparator();
		fileMenu->addAction( filePropertiesAction );
		fileMenu->addAction( fileTemplateDesignerAction );
		fileMenu->addSeparator();
		fileMenu->addAction( fileCloseAction );
		fileMenu->addAction( fileExitAction );

		editMenu = menuBar()->addMenu( tr("&Edit") );
		editMenu->addAction( editUndoAction );
		editMenu->addAction( editRedoAction );
		editMenu->addSeparator();
		editMenu->addAction( editCutAction );
		editMenu->addAction( editCopyAction );
		editMenu->addAction( editPasteAction );
		editMenu->addAction( editDeleteAction );
		editMenu->addSeparator();
		editMenu->addAction( editSelectAllAction );
		editMenu->addAction( editUnSelectAllAction );
		editMenu->addSeparator();
		editMenu->addAction( editPreferencesAction );

		viewMenu = menuBar()->addMenu( tr("&View") );
		viewMenu->addAction( viewMainToolbarAction );
		viewMenu->addAction( viewDrawingToolbarAction );
		viewMenu->addSeparator();
		viewMenu->addAction( viewGridAction );
		viewMenu->addAction( viewMarkupAction );
		viewMenu->addSeparator();
		viewMenu->addAction( viewZoomInAction );
		viewMenu->addAction( viewZoomOutAction );
		viewMenu->addAction( viewZoom1to1Action );
		viewMenu->addAction( viewZoomToFitAction );

		objectsMenu = menuBar()->addMenu( tr("&Objects") );
		objectsMenu->addAction( objectsArrowModeAction );
		objectsCreateMenu = objectsMenu->addMenu( tr("&Create") );
		objectsCreateMenu->addAction( objectsCreateTextAction );
		objectsCreateMenu->addAction( objectsCreateBoxAction );
		objectsCreateMenu->addAction( objectsCreateLineAction );
		objectsCreateMenu->addAction( objectsCreateEllipseAction );
		objectsCreateMenu->addAction( objectsCreateImageAction );
		objectsCreateMenu->addAction( objectsCreateBarcodeAction );
		objectsMenu->addSeparator();
		objectsOrderMenu = objectsMenu->addMenu( tr("&Order") );
		objectsOrderMenu->addAction( objectsOrderRaiseAction );
		objectsOrderMenu->addAction( objectsOrderLowerAction );
		objectsXformMenu = objectsMenu->addMenu( tr("&Rotate/Flip") );
		objectsXformMenu->addAction( objectsXformRotateLeftAction );
		objectsXformMenu->addAction( objectsXformRotateRightAction );
		objectsXformMenu->addAction( objectsXformFlipHorizAction );
		objectsXformMenu->addAction( objectsXformFlipVertAction );
		objectsAlignMenu = objectsMenu->addMenu( tr("&Alignment") );
		objectsAlignMenu->addAction( objectsAlignLeftAction );
		objectsAlignMenu->addAction( objectsAlignHCenterAction );
		objectsAlignMenu->addAction( objectsAlignRightAction );
		objectsAlignMenu->addSeparator();
		objectsAlignMenu->addAction( objectsAlignTopAction );
		objectsAlignMenu->addAction( objectsAlignVCenterAction );
		objectsAlignMenu->addAction( objectsAlignBottomAction );
		objectsCenterMenu = objectsMenu->addMenu( tr("Center") );
		objectsCenterMenu->addAction( objectsCenterHorizAction );
		objectsCenterMenu->addAction( objectsCenterVertAction );
		objectsMenu->addSeparator();
		objectsMenu->addAction( objectsMergePropertiesAction );

		helpMenu = menuBar()->addMenu( tr("&Help") );
		helpMenu->addAction( helpContentsAction );
		helpMenu->addAction( helpAboutAction );
	}


	void MainWindow::fileNew()
	{
		std::cout << "ACTION: file->New" << std::endl;
	}


	void MainWindow::fileOpen()
	{
		std::cout << "ACTION: file->Open" << std::endl;
	}


	void MainWindow::fileSave()
	{
		std::cout << "ACTION: file->Save" << std::endl;
	}


	void MainWindow::fileSaveAs()
	{
		std::cout << "ACTION: file->Save As" << std::endl;
	}


	void MainWindow::filePrint()
	{
		std::cout << "ACTION: file->Print" << std::endl;
	}


	void MainWindow::fileProperties()
	{
		std::cout << "ACTION: file->Properties" << std::endl;
	}


	void MainWindow::fileTemplateDesigner()
	{
		std::cout << "ACTION: file->Template Designer" << std::endl;
	}


	void MainWindow::fileClose()
	{
		std::cout << "ACTION: file->Close" << std::endl;
	}


	void MainWindow::fileExit()
	{
		std::cout << "ACTION: file->Exit" << std::endl;
	}


	void MainWindow::editUndo()
	{
		std::cout << "ACTION: edit->Undo" << std::endl;
	}


	void MainWindow::editRedo()
	{
		std::cout << "ACTION: edit->Redo" << std::endl;
	}


	void MainWindow::editCut()
	{
		std::cout << "ACTION: edit->Cut" << std::endl;
	}


	void MainWindow::editCopy()
	{
		std::cout << "ACTION: edit->Copy" << std::endl;
	}


	void MainWindow::editPaste()
	{
		std::cout << "ACTION: edit->Paste" << std::endl;
	}


	void MainWindow::editDelete()
	{
		std::cout << "ACTION: edit->Delete" << std::endl;
	}


	void MainWindow::editSelectAll()
	{
		std::cout << "ACTION: edit->Select All" << std::endl;
	}


	void MainWindow::editUnSelectAll()
	{
		std::cout << "ACTION: edit->Un-select All" << std::endl;
	}


	void MainWindow::editPreferences()
	{
		std::cout << "ACTION: edit->Preferences" << std::endl;
	}


	void MainWindow::viewMainToolbar()
	{
		std::cout << "ACTION: edit->Main Toolbar" << std::endl;
	}


	void MainWindow::viewDrawingToolbar()
	{
		std::cout << "ACTION: edit->Drawing Toolbar" << std::endl;
	}


	void MainWindow::viewGrid()
	{
		std::cout << "ACTION: edit->Grid" << std::endl;
	}


	void MainWindow::viewMarkup()
	{
		std::cout << "ACTION: edit->Markup" << std::endl;
	}


	void MainWindow::viewZoomIn()
	{
		std::cout << "ACTION: edit->Zoom in" << std::endl;
	}


	void MainWindow::viewZoomOut()
	{
		std::cout << "ACTION: edit->Zoom out" << std::endl;
	}


	void MainWindow::viewZoom1to1()
	{
		std::cout << "ACTION: edit->Zoom 1 to 1" << std::endl;
	}


	void MainWindow::viewZoomToFit()
	{
		std::cout << "ACTION: edit->Zoom to fit" << std::endl;
	}


	void MainWindow::objectsArrowMode()
	{
		std::cout << "ACTION: objects->Select Mode" << std::endl;
	}


	void MainWindow::objectsCreateText()
	{
		std::cout << "ACTION: objects->Create->Text" << std::endl;
	}


	void MainWindow::objectsCreateBox()
	{
		std::cout << "ACTION: objects->Create->Box" << std::endl;
	}


	void MainWindow::objectsCreateLine()
	{
		std::cout << "ACTION: objects->Create->Line" << std::endl;
	}


	void MainWindow::objectsCreateEllipse()
	{
		std::cout << "ACTION: objects->Create->Ellipse" << std::endl;
	}


	void MainWindow::objectsCreateImage()
	{
		std::cout << "ACTION: objects->Create->Image" << std::endl;
	}


	void MainWindow::objectsCreateBarcode()
	{
		std::cout << "ACTION: objects->Create->Barcode" << std::endl;
	}


	void MainWindow::objectsOrderRaise()
	{
		std::cout << "ACTION: objects->Order->Bring to front" << std::endl;
	}


	void MainWindow::objectsOrderLower()
	{
		std::cout << "ACTION: objects->Order->Send to back" << std::endl;
	}


	void MainWindow::objectsXformRotateLeft()
	{
		std::cout << "ACTION: objects->Rotate/Flip->Rotate Left" << std::endl;
	}


	void MainWindow::objectsXformRotateRight()
	{
		std::cout << "ACTION: objects->Rotate/Flip->Rotate Right" << std::endl;
	}


	void MainWindow::objectsXformFlipHoriz()
	{
		std::cout << "ACTION: objects->Rotate/Flip->Flip Horizontally" << std::endl;
	}


	void MainWindow::objectsXformFlipVert()
	{
		std::cout << "ACTION: objects->Rotate/Flip->Flip Vertically" << std::endl;
	}


	void MainWindow::objectsAlignLeft()
	{
		std::cout << "ACTION: objects->Align->Left" << std::endl;
	}


	void MainWindow::objectsAlignHCenter()
	{
		std::cout << "ACTION: objects->Align->Center Horizontally" << std::endl;
	}


	void MainWindow::objectsAlignRight()
	{
		std::cout << "ACTION: objects->Align->Right" << std::endl;
	}


	void MainWindow::objectsAlignTop()
	{
		std::cout << "ACTION: objects->Align->Top" << std::endl;
	}


	void MainWindow::objectsAlignVCenter()
	{
		std::cout << "ACTION: objects->Align->Center Vertically" << std::endl;
	}


	void MainWindow::objectsAlignBottom()
	{
		std::cout << "ACTION: objects->Align->Bottom" << std::endl;
	}


	void MainWindow::objectsCenterHoriz()
	{
		std::cout << "ACTION: objects->Center->Horizontally" << std::endl;
	}


	void MainWindow::objectsCenterVert()
	{
		std::cout << "ACTION: objects->Center->Vertically" << std::endl;
	}


	void MainWindow::objectsMergeProperties()
	{
		std::cout << "ACTION: objects->Merge Properties..." << std::endl;
	}


	void MainWindow::helpContents()
	{
		Help::displayContents( this );
	}


	void MainWindow::helpAbout()
	{
		Help::displayAbout( this );
	}

}
