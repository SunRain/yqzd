#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class PreviewWidget;
class MediaDownloader;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *m_dataSelectBtn    = nullptr;
    QPushButton *m_outpathSelectBtn = nullptr;
    QPushButton *m_dlBtn            = nullptr;
    QPushButton *m_previewBtn       = nullptr;

    QLabel      *m_dataSelLabel     = nullptr;
    QLabel      *m_outpathSelLabel  = nullptr;
    QLabel      *m_infoLabel        = nullptr;

    PreviewWidget *m_previewWidget  = nullptr;

    MediaDownloader *m_mediaDL      = nullptr;

    QString m_datafile;
    QString m_outpath;

};
#endif // MAINWINDOW_H
