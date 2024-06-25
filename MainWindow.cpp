#include "MainWindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>

#include "MediaDownloader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_dataSelectBtn(new QPushButton)
    , m_outpathSelectBtn(new QPushButton)
    , m_dlBtn(new QPushButton)
    , m_dataSelLabel(new QLabel)
    , m_outpathSelLabel(new QLabel)
    , m_mediaDL(new MediaDownloader(this))
{

    auto centralWidget = new QWidget;
    auto *vb = new QVBoxLayout;
    vb->setContentsMargins(10, 10, 10, 10);

    m_dataSelectBtn->setText("input file");
    vb->addWidget(m_dataSelectBtn);
    vb->addWidget(m_dataSelLabel);

    m_outpathSelectBtn->setText("output path");
    vb->addWidget(m_outpathSelectBtn);
    vb->addWidget(m_outpathSelLabel);

    m_dlBtn->setText("download media");
    vb->addWidget(m_dlBtn);

    centralWidget->setLayout(vb);
    this->setCentralWidget(centralWidget);

    connect(m_dataSelectBtn, &QPushButton::clicked,
            this, [=]() {
                m_datafile = QFileDialog::getOpenFileName(nullptr,
                                                          "Choose json data",
                                                          qApp->applicationDirPath(),
                                                          QString(),
                                                          nullptr,
                                                          QFileDialog::Option::ReadOnly);
                qDebug()<<Q_FUNC_INFO<<">>>> selected data "<<m_datafile;
                m_dataSelLabel->setText(m_datafile);
            });


    connect(m_outpathSelectBtn, &QPushButton::clicked,
            this, [=]() {
                m_outpath = QFileDialog::getExistingDirectory(nullptr,
                                                               "Choose saved path",
                                                               qApp->applicationDirPath(),
                                                               QFileDialog::ShowDirsOnly
                                                                   | QFileDialog::DontResolveSymlinks);
                qDebug()<<Q_FUNC_INFO<<">>>> selected path "<<m_outpath;
                m_outpathSelLabel->setText(m_outpath);
            });

    connect(m_dlBtn, &QPushButton::clicked,
            this, [=]() {
        m_mediaDL->download(m_datafile, m_outpath);
    });

    connect(m_mediaDL, &MediaDownloader::dlError,
            this, [=](const QString &msg) {
        QMessageBox::warning(nullptr, "Error", msg);
    });



}

MainWindow::~MainWindow() {}