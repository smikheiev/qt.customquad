#ifndef CUSTOMQUADMASKEDIMAGE_H
#define CUSTOMQUADMASKEDIMAGE_H

#include <QSGTextureMaterial>
#include <QSGGeometry>
#include <QQuickItem>

class CustomQuadMaskedImage : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QQuickItem* source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QPointF topLeft READ topLeft WRITE setTopLeft NOTIFY topLeftChanged)
    Q_PROPERTY(QPointF topRight READ topRight WRITE setTopRight NOTIFY topRightChanged)
    Q_PROPERTY(QPointF bottomRight READ bottomRight WRITE setBottomRight NOTIFY bottomRightChanged)
    Q_PROPERTY(QPointF bottomLeft READ bottomLeft WRITE setBottomLeft NOTIFY bottomLeftChanged)

public:
    explicit CustomQuadMaskedImage(QQuickItem* parent = 0);
    ~CustomQuadMaskedImage();

    QQuickItem* source() const { return mSource; }
    QPointF topLeft() const { return mTopLeft; }
    QPointF topRight() const { return mTopRight; }
    QPointF bottomRight() const { return mBottomRight; }
    QPointF bottomLeft() const { return mBottomLeft; }

    void setSource(QQuickItem* source);
    void setTopLeft(QPointF topLeft);
    void setTopRight(QPointF topRight);
    void setBottomRight(QPointF bottomRight);
    void setBottomLeft(QPointF bottomLeft);

protected:
    virtual QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData* updatePaintNodeData) override;

private:
    QQuickItem* mSource;
    QPointF mTopLeft;
    QPointF mTopRight;
    QPointF mBottomRight;
    QPointF mBottomLeft;

    QSGGeometry* mGeometry;
    QSGTextureMaterial* mMaterial;
    QSGGeometry::TexturedPoint2D* mVertices;

signals:
    void sourceChanged(QQuickItem* source);
    void topLeftChanged(QPointF topLeft);
    void topRightChanged(QPointF topRight);
    void bottomRightChanged(QPointF bottomRight);
    void bottomLeftChanged(QPointF bottomLeft);
};

#endif // CUSTOMQUADMASKEDIMAGE_H
