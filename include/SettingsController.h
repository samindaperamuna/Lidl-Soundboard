#ifndef INCLUDESETTINGSCONTROLLER_H
#define INCLUDESETTINGSCONTROLLER_H
#include <QString>
#include <QVector>
#include <QObject>
#include <QWidget>

#include <ui_Settings.h>
#include <QFileDialog>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QFileInfo>
#include <deque>
#include <algorithm>
#include <QMenu>
#include <QAction>
//#include <QDateTime>
// Class handling the settings
// we make it a singleton so we are gucci
namespace LIDL{


class SettingsController : public QObject
{
    Q_OBJECT
public:

    static SettingsController * GetInstance();

    // getters
    int GetDefaultMainVolume();
    int GetDefaultVacVolume();
    // Public methods
    bool OpenSettings();
    // Can still use constructor to set default valuues
    // Because it should be called before any other methods
    //void SetDefaultValues();
    void SaveSettings();

    QString GetLastOpenedSoundboard();
    std::deque<QFileInfo> GetRecentFiles();

private:
    QString fileName;
    // Singleton class
    SettingsController();
    // the pointer will exist even if class isn't instancied yet
    // but we need to initalize it in the .cpp with a weird syntax
    static SettingsController * self;


    // Default folder to open sounboard (lidljson) files
    QString defaultSoundboardFolder;
    // Default folder to add sound
    QString defaultSoundsFolder;

    // Number of files to show in recent files (and to be saved)
    int recentFileCount;


    // Default volume for the add sound dialog (or the open exp soundboard)
    int defaultMainVolume;
    int defaultVacVolume;

    // QVector of recents opened file (either from the file or from after opening/saving a file)
    // todo: use std::deque
   // QVector<QFileInfo> recentFiles;
    std::deque<QFileInfo> recentFiles;
    // The pointer to the ui
    Ui::Settings * ui;
    // The recent menu pointer
    QMenu * _recentMenu;
signals:
    void RecentFilesChanged();

public slots:
    void SetDefaultMainVolume(int);
    void SetDefaultVacVolume(int);
    void SetRecentFileCount(int);
    void ShowSettingsWindow();

    // slots for button in the ui
    void buttonBrowseLidl();
    void buttonBrowseSound();

    void addFile(QFileInfo fileInfo);

};
}
#endif // INCLUDESETTINGSCONTROLLER_H