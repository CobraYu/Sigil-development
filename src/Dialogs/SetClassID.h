/************************************************************************
**
**  Copyright (C) 2012 John Schember <john@nachtimwald.com>
**  Copyright (C) 2012 Dave Heiland
**
**  This file is part of Sigil.
**
**  Sigil is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Sigil is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Sigil.  If not, see <http://www.gnu.org/licenses/>.
**
*************************************************************************/

#pragma once
#ifndef SETCLASSID_H
#define SETCLASSID_H

#include <QtWidgets/QDialog>

#include "ui_SetClassID.h"

class SetClassID: public QDialog
{
	Q_OBJECT

public:
	SetClassID(QString tagName, int size, QString json, QWidget *parent = 0);

    //void SetList();

    //QString GetId();


signals:
	void classIDChanged(QString tagName, QString json);

public slots:
	void accept();
	void reject();

private slots:
    void WriteSettings();

private:
    //void SetSelectedText();

    //void ReadSettings();
    void connectSignalsSlots();

    //QString m_SelectedText;

    //HTMLResource *m_HTMLResource;

    //QSharedPointer<Book> m_Book;

    Ui::SetClassID ui;

	int m_size;
	QString m_tag;
};

#endif // SETCLASSID_H
