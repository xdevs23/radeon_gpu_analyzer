// C++.
#include <cassert>
#include <sstream>

// Qt.
#include <QApplication>
#include <QCheckBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>

// Infra.
#include <QtCommon/CustomWidgets/ArrowIconWidget.h>
#include <QtCommon/Util/CommonDefinitions.h>
#include <QtCommon/CustomWidgets/ListWidget.h>
#include <QtCommon/Util/QtUtil.h>
#include <QtCommon/Util/RestoreCursorPosition.h>

// Local.
#include <RadeonGPUAnalyzerGUI/include/rgConfigManager.h>
#include <RadeonGPUAnalyzerGUI/include/rgDefinitions.h>
#include <RadeonGPUAnalyzerGUI/include/qt/rgSettingsButtonsView.h>
#include <RadeonGPUAnalyzerGUI/include/qt/rgHideListWidgetEventFilter.h>
#include <RadeonGPUAnalyzerGUI/include/qt/rgIsaDisassemblyTableModel.h>
#include <RadeonGPUAnalyzerGUI/include/rgStringConstants.h>
#include <RadeonGPUAnalyzerGUI/include/rgUtils.h>


rgSettingsButtonsView::rgSettingsButtonsView(QWidget* pParent) :
    QWidget(pParent)
{
    // Setup the UI.
    ui.setupUi(this);

    // Set the background to white.
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    // Connect the signals.
    ConnectSignals();

    // Set the mouse cursor to the pointing hand cursor for various widgets.
    SetCursor();

    // Disable the "Save" button located on build settings view initially.
    ui.saveSettingsButton->setEnabled(false);
}

rgSettingsButtonsView::~rgSettingsButtonsView()
{
}

void rgSettingsButtonsView::ConnectSignals()
{
    // Restore default settings button.
    bool isConnected = connect(this->ui.defaultSettingsPushButton, &QPushButton::clicked, this, &rgSettingsButtonsView::HandleRestoreDefaultSettingsButtonClick);
    assert(isConnected);

    // Save settings button.
    isConnected = connect(this->ui.saveSettingsButton, &QPushButton::clicked, this, &rgSettingsButtonsView::HandleSaveSettingsButtonClick);
    assert(isConnected);
}


void rgSettingsButtonsView::SetCursor()
{
    // Set the cursor to pointing hand cursor.
    ui.defaultSettingsPushButton->setCursor(Qt::PointingHandCursor);
    ui.saveSettingsButton->setCursor(Qt::PointingHandCursor);
}

void rgSettingsButtonsView::HandleRestoreDefaultSettingsButtonClick()
{
    // Emit the signal to indicate clicking of "Save" button.
    emit RestoreDefaultSettingsButtonClickedSignal();
}

void rgSettingsButtonsView::HandleSaveSettingsButtonClick()
{
    // Emit the signal to indicate clicking of "Save" button.
    emit SaveSettingsButtonClickedSignal();
}

void rgSettingsButtonsView::EnableSaveButton(bool isEnabled)
{
    ui.saveSettingsButton->setEnabled(isEnabled);
}