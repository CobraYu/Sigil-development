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

#include <QtWidgets/QDialog>
//#include <QtWidgets/QLineEdit>


#include "Dialogs/SetClassID.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <QtWidgets/QMessageBox>
//#include "ResourceObjects/HTMLResource.h"
//#include "Misc/SettingsStore.h"

//static QString SETTINGS_GROUP = "select_id";

SetClassID::SetClassID(QString tagName, int size, QString json, QWidget *parent)
    :
    QDialog(parent),
	m_size(size),
	m_tag(tagName)
    //m_SelectedText(id),
    //m_HTMLResource(html_resource),
    //m_Book(book)
{
    ui.setupUi(this);

    //QCompleter *qc = ui.id->completer();
    //qc->setCaseSensitivity(Qt::CaseSensitive);

    //connectSignalsSlots();
    //ReadSettings();
    //SetList();
	QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8());
	QJsonObject jsonObject = jsonDocument.object();
	ui.plainTextEdit_1->setPlainText(jsonObject.keys().at(0));
	ui.plainTextEdit_2->setPlainText(jsonObject.value(jsonObject.keys().at(0)).toString());
	ui.plainTextEdit_3->setPlainText(jsonObject.keys().at(1));
	ui.plainTextEdit_4->setPlainText(jsonObject.value(jsonObject.keys().at(1)).toString());
	ui.plainTextEdit_5->setPlainText(jsonObject.keys().at(2));
	ui.plainTextEdit_6->setPlainText(jsonObject.value(jsonObject.keys().at(2)).toString());
	ui.plainTextEdit_7->setPlainText(jsonObject.keys().at(3));
	ui.plainTextEdit_8->setPlainText(jsonObject.value(jsonObject.keys().at(3)).toString());
	ui.plainTextEdit_9->setPlainText(jsonObject.keys().at(4));
	ui.plainTextEdit_10->setPlainText(jsonObject.value(jsonObject.keys().at(4)).toString());
	ui.plainTextEdit_11->setPlainText(jsonObject.keys().at(5));
	ui.plainTextEdit_12->setPlainText(jsonObject.value(jsonObject.keys().at(5)).toString());
	ui.plainTextEdit_13->setPlainText(jsonObject.keys().at(6));
	ui.plainTextEdit_14->setPlainText(jsonObject.value(jsonObject.keys().at(6)).toString());
	ui.plainTextEdit_15->setPlainText(jsonObject.keys().at(7));
	ui.plainTextEdit_16->setPlainText(jsonObject.value(jsonObject.keys().at(7)).toString());
	
	connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

}



/*
void SetClassID::SetList()
{
    QStringList ids = m_Book->GetIdsInHTMLFile(m_HTMLResource);
    foreach(QString id, ids) {
        ui.id->addItem(id);
    }
    // Set default id name
    ui.id->setEditText(m_SelectedText);
}
*/
/*
QString SelectId::GetId()
{
    return m_SelectedText;
}

void SelectId::SetSelectedText()
{
    m_SelectedText = ui.id->currentText();
}

void SelectId::ReadSettings()
{
    SettingsStore settings;
    settings.beginGroup(SETTINGS_GROUP);
    // The size of the window and it's full screen status
    QByteArray geometry = settings.value("geometry").toByteArray();

    if (!geometry.isNull()) {
        restoreGeometry(geometry);
    }

    settings.endGroup();
}
*/
void SetClassID::WriteSettings()
{
    //SetSelectedText();
    //SettingsStore settings;
    //settings.beginGroup(SETTINGS_GROUP);
    //// The size of the window and it's full screen status
    //settings.setValue("geometry", saveGeometry());
    //settings.endGroup();
}

void SetClassID::accept()
{
	if(ui.plainTextEdit_1->toPlainText() == "" || ui.plainTextEdit_2->toPlainText() == "" ||
		ui.plainTextEdit_3->toPlainText() == "" || ui.plainTextEdit_4->toPlainText() == "" ||
		ui.plainTextEdit_5->toPlainText() == "" || ui.plainTextEdit_6->toPlainText() == "" ||
		ui.plainTextEdit_7->toPlainText() == "" || ui.plainTextEdit_8->toPlainText() == "" ||
		ui.plainTextEdit_9->toPlainText() == "" || ui.plainTextEdit_10->toPlainText() == "" ||
		ui.plainTextEdit_11->toPlainText() == "" || ui.plainTextEdit_12->toPlainText() == "" ||
		ui.plainTextEdit_13->toPlainText() == "" || ui.plainTextEdit_14->toPlainText() == "" ||
		ui.plainTextEdit_15->toPlainText() == "" || ui.plainTextEdit_16->toPlainText() == ""){
		QMessageBox::warning(0, "Warning", 
			"Some cells are empty!",
			QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	QJsonDocument jsonDoc;
	QJsonObject object;
	
	object.insert(ui.plainTextEdit_1->toPlainText(), ui.plainTextEdit_2->toPlainText());
	object.insert(ui.plainTextEdit_3->toPlainText(), ui.plainTextEdit_4->toPlainText());
	object.insert(ui.plainTextEdit_5->toPlainText(), ui.plainTextEdit_6->toPlainText());
	object.insert(ui.plainTextEdit_7->toPlainText(), ui.plainTextEdit_8->toPlainText());
	object.insert(ui.plainTextEdit_9->toPlainText(), ui.plainTextEdit_10->toPlainText());
	object.insert(ui.plainTextEdit_11->toPlainText(), ui.plainTextEdit_12->toPlainText());
	object.insert(ui.plainTextEdit_13->toPlainText(), ui.plainTextEdit_14->toPlainText());
	object.insert(ui.plainTextEdit_15->toPlainText(), ui.plainTextEdit_16->toPlainText());
	jsonDoc.setObject(object);
	QString json = jsonDoc.toJson(QJsonDocument::Compact);
	emit classIDChanged(m_tag, json);
	QDialog::accept();
}

void SetClassID::reject()
{
	

	QDialog::reject();
}
void SetClassID::connectSignalsSlots()
{
    connect(this, SIGNAL(accepted()), this, SLOT(WriteSettings()));
}
