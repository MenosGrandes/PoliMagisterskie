#ifndef VERTE2XARRAY_H
#define VERTE2XARRAY_H
#include "structs.hpp"
#include "Vertex2.h"
#include "PrimitiveType.h"
#include "Drawable.h"
#include <vector>

template <typename T>
class Vertex2Array : public Drawable
{
public:
    Vertex2Array()
    {
        //ctor
    }

    ~Vertex2Array()
    {
        //dtor
    }

    explicit Vertex2Array(PrimitiveType type, d_type::Bsize vertexCount):m_primitiveType(type)
    {
        m_vertices.reserve(vertexCount);
//!OR RESIZE!
    }


    d_type::Bint getVerticesCount()
    {
        return m_vertices.size();
    }

    void setPrimitiveType(PrimitiveType type)
    {
        m_primitiveType=type;
    }

    void clean()
    {
        m_vertices.clear();
    }

    void resize(d_type::Bsize vertexCount)
    {
        m_vertices.resize(vertexCount);
    }

    void append(const Vertex2<T>& vertex)
    {
        m_vertices.push_back(vertex);
    }


private:
    virtual void draw(RenderTarget &target)const {};
    std::vector<Vertex2<T>> m_vertices;
    PrimitiveType m_primitiveType;

};
typedef Vertex2Array<d_type::Bfloat>Vertex2FloatArray;
typedef Vertex2Array<d_type::Bint>Vertex2IntArray;
typedef Vertex2Array<d_type::Bdouble>Vertex2DoubleArray;
#endif // VERTEX2ARRAY_H
