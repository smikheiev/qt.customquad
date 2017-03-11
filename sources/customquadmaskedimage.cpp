#include <QSGTextureProvider>
#include <QSGGeometryNode>

#include "customquadmaskedimage.h"

CustomQuadMaskedImage::CustomQuadMaskedImage(QQuickItem* parent)
    : QQuickItem(parent)
    , mSource(nullptr)
    , mTopLeft(0, 0)
    , mTopRight(0, 0)
    , mBottomRight(0, 0)
    , mBottomLeft(0, 0)
{
    mMaterial = new QSGTextureMaterial();
    mGeometry = new QSGGeometry(QSGGeometry::defaultAttributes_TexturedPoint2D(), 4);
    mVertices = mGeometry->vertexDataAsTexturedPoint2D();

    setFlag(QQuickItem::ItemHasContents);
}

CustomQuadMaskedImage::~CustomQuadMaskedImage()
{
    delete mMaterial;
    delete mGeometry;
    delete mSource;
}

void CustomQuadMaskedImage::setSource(QQuickItem* source)
{
    if (source != mSource)
    {
        mSource = source;
        emit sourceChanged(mSource);
        update();
    }
}

void CustomQuadMaskedImage::setTopLeft(QPointF topLeft)
{
    if (topLeft != mTopLeft)
    {
        mTopLeft = topLeft;
        emit topLeftChanged(mTopLeft);
        update();
    }
}

void CustomQuadMaskedImage::setTopRight(QPointF topRight)
{
    if (topRight != mTopRight)
    {
        mTopRight = topRight;
        emit topRightChanged(mTopRight);
        update();
    }
}

void CustomQuadMaskedImage::setBottomRight(QPointF bottomRight)
{
    if (bottomRight != mBottomRight)
    {
        mBottomRight = bottomRight;
        emit bottomRightChanged(mBottomRight);
        update();
    }
}

void CustomQuadMaskedImage::setBottomLeft(QPointF bottomLeft)
{
    if (bottomLeft != mBottomLeft)
    {
        mBottomLeft = bottomLeft;
        emit bottomLeftChanged(mBottomLeft);
        update();
    }
}

QSGNode* CustomQuadMaskedImage::updatePaintNode(QSGNode* node, UpdatePaintNodeData* updatePaintNodeData)
{
    Q_UNUSED(updatePaintNodeData)

    if (mSource == nullptr || not mSource->isTextureProvider())
    {
        delete node;
        return nullptr;
    }

    QSGTexture* texture = mSource->textureProvider()->texture();
    if (texture == nullptr)
    {
        delete node;
        return nullptr;
    }

    if (node == nullptr)
    {
        QSGGeometryNode* geometryNode = new QSGGeometryNode();
        node = geometryNode;

        geometryNode->setGeometry(mGeometry);
        geometryNode->setMaterial(mMaterial);
    }

    mMaterial->setTexture(texture);

    qreal w = boundingRect().width();
    qreal h = boundingRect().height();

    qreal x, y, tx, ty;

    x = mTopLeft.x();
    y = mTopLeft.y();
    tx = x / w;
    ty = y / h;
    mVertices[0].set(x, y, tx, ty);

    x = mTopRight.x();
    y = mTopRight.y();
    tx = x / w;
    ty = y / h;
    mVertices[1].set(x, y, tx, ty);

    x = mBottomLeft.x();
    y = mBottomLeft.y();
    tx = x / w;
    ty = y / h;
    mVertices[2].set(x, y, tx, ty);

    x = mBottomRight.x();
    y = mBottomRight.y();
    tx = x / w;
    ty = y / h;
    mVertices[3].set(x, y, tx, ty);

    node->markDirty(QSGNode::DirtyGeometry);

    return node;
}
