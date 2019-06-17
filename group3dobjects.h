#ifndef GROUP3DOBJECTS_H
#define GROUP3DOBJECTS_H

#include "transformational.h"

#include <QVector>
#include <QMatrix4x4>

class Group3DObjects : public Transformational
{
public:
    Group3DObjects();

    void draw(QOpenGLShaderProgram* program, QOpenGLFunctions* functions);
    void rotate(const QQuaternion &r);
    void translate(const QVector3D &t);
    void scale(const float &s);
    void setGlobalTransform(const QMatrix4x4 &gt);
    void add(Transformational* obj);

private:
    QQuaternion m_Rotate;
    QVector3D m_Translate;
    float m_Scale;
    QMatrix4x4 m_GlobalTransform;
    QVector<Transformational*> m_Objects;
};

#endif // GROUP3DOBJECTS_H
