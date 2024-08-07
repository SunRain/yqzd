#ifndef PREVIEWWIDGET_H
#define PREVIEWWIDGET_H

#include <QWidget>
#include <QImage>
#include <QJsonArray>

#include "PropertyData.h"

class PreviewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PreviewWidget(QWidget *parent = nullptr);
    virtual ~PreviewWidget();

    bool load(const QString &jsonPath, const QString &mediaPath);

    void drawPage(int pgNum);

    int pageCount() const;

    void save(int pgNum, const QString &path);

    QImage generateBarcode(const QString &text, int width, int height,
                           QColor foreground = Qt::black,
                           QColor background = Qt::white);

    QString generateBarcodeText(const QString &uri) const;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

protected:
    virtual bool parseProperty(const QJsonObject &obj);
    virtual void renderToImage(int pgNum);

private:
    void drawIntroPage(const QJsonObject &node);
    void drawVersionPage(const QJsonObject &node);
    void drawDirectoryPage(const QJsonObject &node);
    void drawProfilePage(const QJsonObject &node);
    void drawGraduationPhotoPage(const QJsonObject &node);
    void drawGraduationMoviePaget(const QJsonObject &node);
    void drawGraduationDreamPage(const QJsonObject &node);
    void drawHybridSubject(const QJsonObject &node, const QJsonObject &property);
    void drawFeedPage(const QJsonObject &node, const QJsonObject &property);
    void drawPhysicalExaminationPage(const QJsonObject &node, const QJsonObject &property);
    void drawEWishPage(const QJsonObject &node, const QJsonObject &property);
    void drawGraduationAudios(const QJsonObject &node, const QJsonObject &property);
    void drawEFinalPage(const QJsonObject &node, const QJsonObject &property);


    void drawPagination(const QJsonObject &node);

    void drawBackground(const QJsonObject &PropertyObject);
    void drawElement(const QJsonObject &node);
    void drawTemplateElement(const QJsonObject &node);

private:
    QString dotExtension(const QString &uri) const;

private:
    QImage *m_sceneImg = nullptr;
    QPainter *m_scenePainter = nullptr;

    int m_curID = -1;
    QString m_mediaPath;
    QString m_profileAvatar;

    PageSize m_pageSize;

    QJsonArray m_pages;
    DividingLine m_dvLine;
    Pagination m_pagination;

    // SubjectFonts m_subjectFonts;



};



#endif // PREVIEWWIDGET_H
