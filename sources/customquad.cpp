#include <QSGGeometryNode>

#include "customquad.h"

CustomQuad::CustomQuad(QQuickItem* parent)
    : QQuickItem(parent)
    , mColor(QColor(0, 0, 0, 0))
    , mTopLeft(0, 0)
    , mTopRight(0, 0)
    , mBottomRight(0, 0)
    , mBottomLeft(0, 0)
{
    mMaterial = new QSGFlatColorMaterial();
    mGeometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 4);
    mVertices = mGeometry->vertexDataAsPoint2D();

    setFlag(QQuickItem::ItemHasContents);
}

void CustomQuad::setColor(const QColor color)
{
    if (color != mColor)
    {
        mColor = color;
        emit colorChanged(mColor);
        update();
    }
}

void CustomQuad::setTopLeft(QPointF topLeft)
{
    if (topLeft != mTopLeft)
    {
        mTopLeft = topLeft;
        emit topLeftChanged(mTopLeft);
        update();
    }
}

void CustomQuad::setTopRight(QPointF topRight)
{
    if (topRight != mTopRight)
    {
        mTopRight = topRight;
        emit topRightChanged(mTopRight);
        update();
    }
}

void CustomQuad::setBottomRight(QPointF bottomRight)
{
    if (bottomRight != mBottomRight)
    {
        mBottomRight = bottomRight;
        emit bottomRightChanged(mBottomRight);
        update();
    }
}

void CustomQuad::setBottomLeft(QPointF bottomLeft)
{
    if (bottomLeft != mBottomLeft)
    {
        mBottomLeft = bottomLeft;
        emit bottomLeftChanged(mBottomLeft);
        update();
    }
}

QSGNode* CustomQuad::updatePaintNode(QSGNode* node, UpdatePaintNodeData* updatePaintNodeData)
{
    Q_UNUSED(updatePaintNodeData)

    if (node == nullptr)
    {
        QSGGeometryNode* geometryNode = new QSGGeometryNode();
        node = geometryNode;

        geometryNode->setGeometry(mGeometry);
        geometryNode->setFlag(QSGNode::OwnsGeometry);

        geometryNode->setMaterial(mMaterial);
        geometryNode->setFlag(QSGNode::OwnsMaterial);
    }

    mMaterial->setColor(mColor);

    mVertices[0].set(mTopLeft.x(), mTopLeft.y());
    mVertices[1].set(mTopRight.x(), mTopRight.y());
    mVertices[2].set(mBottomLeft.x(), mBottomLeft.y());
    mVertices[3].set(mBottomRight.x(), mBottomRight.y());

    node->markDirty(QSGNode::DirtyGeometry);

    return node;
}
