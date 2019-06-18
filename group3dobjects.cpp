#include "group3dobjects.h"

Group3DObjects::Group3DObjects()
{
    m_Scale = 1.0f;
}

void Group3DObjects::draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions)
{
    QMatrix4x4 locmatr;
    locmatr.setToIdentity();
    locmatr.translate(m_Translate);
    locmatr.rotate(m_Rotate);
    locmatr.scale(m_Scale);
    locmatr = m_GlobalTransform * locmatr;

    for(auto o: m_Objects)
    {
        o->setGlobalTransform(locmatr);
        o->draw(program, functions);
    }
}

void Group3DObjects::rotate(const QQuaternion &r)
{
    m_Rotate = r * m_Rotate;
}

void Group3DObjects::translate(const QVector3D &t)
{
    m_Translate += t;
}

void Group3DObjects::scale(const float &s)
{
    m_Scale *= s;
}

void Group3DObjects::setGlobalTransform(const QMatrix4x4 &gt)
{
    m_GlobalTransform = gt;
}

void Group3DObjects::add(Transformational *obj)
{
    m_Objects.append(obj);
}
