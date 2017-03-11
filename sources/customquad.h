#ifndef CUSTOMQUAD_H
#define CUSTOMQUAD_H

#include <QSGFlatColorMaterial>
#include <QSGGeometry>
#include <QQuickItem>

class CustomQuad : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QPointF topLeft READ topLeft WRITE setTopLeft NOTIFY topLeftChanged)
    Q_PROPERTY(QPointF topRight READ topRight WRITE setTopRight NOTIFY topRightChanged)
    Q_PROPERTY(QPointF bottomRight READ bottomRight WRITE setBottomRight NOTIFY bottomRightChanged)
    Q_PROPERTY(QPointF bottomLeft READ bottomLeft WRITE setBottomLeft NOTIFY bottomLeftChanged)

public:
    explicit CustomQuad(QQuickItem* parent = 0);

    QColor color() const { return mColor; }
    QPointF topLeft() const { return mTopLeft; }
    QPointF topRight() const { return mTopRight; }
    QPointF bottomRight() const { return mBottomRight; }
    QPointF bottomLeft() const { return mBottomLeft; }

    void setColor(QColor color);
    void setTopLeft(QPointF topLeft);
    void setTopRight(QPointF topRight);
    void setBottomRight(QPointF bottomRight);
    void setBottomLeft(QPointF bottomLeft);

protected:
    virtual QSGNode* updatePaintNode(QSGNode* node, UpdatePaintNodeData* updatePaintNodeData) override;

private:
    QColor mColor;
    QPointF mTopLeft;
    QPointF mTopRight;
    QPointF mBottomRight;
    QPointF mBottomLeft;

    QSGFlatColorMaterial* mMaterial;
    QSGGeometry::Point2D* mVertices;
    QSGGeometry* mGeometry;

signals:
    void colorChanged(QColor color);
    void topLeftChanged(QPointF topLeft);
    void topRightChanged(QPointF topRight);
    void bottomRightChanged(QPointF bottomRight);
    void bottomLeftChanged(QPointF bottomLeft);
};

#endif // CUSTOMQUAD_H
