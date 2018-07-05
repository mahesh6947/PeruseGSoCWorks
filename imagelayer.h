#ifndef IMAGELAYER_H
#define IMAGELAYER_H

#include <QImage>
#include <QObject>



class ImageLayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(qreal opacity READ opacity NOTIFY opacityChanged)
    Q_PROPERTY(bool visible READ isVisible NOTIFY visibleChanged)

public:
    ImageLayer();
    explicit ImageLayer(QObject *parent, const QImage &image = QImage());
    ~ImageLayer();

    QString name() const;
    void setName(const QString &name);

    QImage *image();
    const QImage *image() const;

    QSize size() const;
    void setSize(const QSize &newSize);

    qreal opacity() const;
    void setOpacity(const qreal &opacity);

    bool isVisible() const;
    void setVisible(bool visible);

    void read(const QJsonObject &jsonObject);
    void write(QJsonObject &jsonObject);

signals:
    void nameChanged();
    void opacityChanged();
    void visibleChanged();

public:
    QString mName;
    bool mVisible;
    qreal mOpacity;
    QImage mImage;
};





#endif // IMAGELAYER_H
