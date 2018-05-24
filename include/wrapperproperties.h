#ifndef WRAPPERPROPERTIES_H
#define WRAPPERPROPERTIES_H

//#include <QDebug>


#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include "soundwrapper.h"
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QGroupBox>
#include <QCloseEvent>
#include <QListWidgetItem>
#include <QFileDialog>
//#include <QTreeWidget>
//#include <QTreeWidgetItem>
#include <QString>

#include <QButtonGroup>
#include <QKeySequence>
#include <QKeyEvent>
#include <QSet>
#include <QTimer>
#include <QPoint>
#include "soundwrapper.h"

// The class to save me from going insane
#include <QKeySequenceEdit>
#include "CustomShortcutEdit.h"
#include <QMessageBox>
#include "CustomListWidget.h"
#include "EnumsAndStructs.h"
#include <QSlider>
// #include "QFancySlider"
#include <CustomListWidgetItem.h>
#include <QSpinBox>
#include "SettingsController.h"

class WrapperProperties : public QWidget
{
    Q_OBJECT
public:
    explicit WrapperProperties(QWidget *parent = nullptr);
    // One constructor will deal
    // for both Add sound dialog and Edit sound dialog
    WrapperProperties(int mainOutput,int VACOutput,int pttScanCode,int pttVirtualKey,SoundWrapper * sound = nullptr,QWidget *parent = nullptr);
    // WrapperProperties(int mainOutput,int VACOutput,int pttScanCode,int pttVirtualKey,QWidget *parent = nullptr);
private:
    // Pointer to the main window
    QWidget     * _mainWidget;
    // Display for sounds
    // QListWidget *_soundListDisplay;
    //  QGroupBox        * _soundListGroup;
    CustomListWidget * _soundListDisplay;
    // QVBoxLayout      * _soundLayout;

    QLabel * _soundListHint;

    // Buttons to add and delete
    QPushButton *_btnAdd;
    QPushButton *_btnDelete;
    CustomListWidgetItem *_selectedItem;

    // Our layouts
    QVBoxLayout *_vLayout;
    QGridLayout *_gLayout;



    // Playbackmode
    QGroupBox    *_radioGroupBox;
    QButtonGroup *_radioGroup;
    QHBoxLayout  *_radioLayout;
    QRadioButton *_radioSequential;
    QRadioButton *_radioAuto;
    QRadioButton *_radioSingleton;

    QLabel       *_radioToolTip;
    // Hotkey
    QGroupBox   *_shortcutGroup;
    QGridLayout *_shortcutLayout;

    CustomShortcutEdit *_shortcutEdit;
    QKeySequence   *_shortcutSequence;
    QPushButton    *_shortcutResetBtn;
    QLabel         *_shortcutHint;
    QLabel         *_shortcutWarning;

 //   int            _shortcutVirtualKey;

    // Abort and done button
    QPushButton *_btnDone;
    QPushButton *_btnAbort;

    //reimplementation de l'event close
    void  closeEvent(QCloseEvent *event);
    LIDL::Playback  _playBackMode;
    // variables to store which output device and PTT are already set (if any)
    int _mainOutput;
    int _VACOutput;
    int _microphone;
    int _pttScanCode;
    int _pttVirtualKey;

    /*******************************************************
     *                                                     *
     *                     VOLUME SLIDERS                  *
     *                                                     *
     *******************************************************/
    QGroupBox* _sliderGroup;
    QGridLayout * _sliderLayout;
    QSpinBox    * _sliderMainSpin;
    QSpinBox    * _sliderVACSpin;
    QLabel  * _sliderLabelMain;
    QLabel  * _sliderLabelVAC;
    QLabel  * _sliderHint;
    QSlider *_sliderMain;
    QSlider *_sliderVAC;


// TODO ajouter volume
signals:
    void signalAddDone(SoundWrapper *sound);
    void signalEditDone(SoundWrapper *sound);

public slots:
    // Qlist Widget slots
    void AddSound();
    void AddSoundFromDrop(QString);
    void ItemWasClicked(QListWidgetItem* item);
    void DeleteSelectedSound(); //will call DeleteSound()


    // Radio Slots
    void RadioPressed(int id);
    // Btn slots
    void AbortMission();
    // Shorcut slots
    void SetKeySequence(QKeySequence);
    void ShortcutReset();
    void editingStarted();
    void editingDone();
    // Communicating with main ui slots: CreateWrapper and Edited wrapper
    void CreateWrapper();
    void SendEditedWrapper();

    // Slots for the item as the items aren't Q_OBJECT they can't have slots of their own forsenT
    void SetItemMainVolume(int);
    void SetItemVACVolume(int);



  //  void Test(SoundWrapper*);
};

#endif // WRAPPERPROPERTIES_H
