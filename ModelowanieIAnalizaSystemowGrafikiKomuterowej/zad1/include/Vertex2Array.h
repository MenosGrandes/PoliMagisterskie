#ifndef VERTE2XARRAY_H
#define VERTE2XARRAY_H
#include "structs.hpp"
#include "Vertex2.h"
#include "PrimitiveType.h"
#include "Drawable.h"
#include <vector>

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

    void append(const Vertex2<d_type::Bfloat>& vertex)
    {
        m_vertices.push_back(vertex);
    }
    const Vertex2<float>& operator [](d_type::Bsize index) const;
    Vertex2<float>& operator [](d_type::Bsize index);
private:
    virtual void draw(RenderTarget &target)const
    {


std::cout<<"VERTEXARRAY DRAWABLE " << m_vertices.size()<<" \n";
        if(!m_vertices.empty())
        {
            target.draw(&m_vertices[0],m_vertices.size(),m_primitiveType);
        }
    };


    std::vector<Vertex2<d_type::Bfloat>> m_vertices;
    PrimitiveType m_primitiveType;

};

inline Vertex2<float>& Vertex2Array::operator [](d_type::Bsize  index)
{
    return m_vertices[index];
}


inline const Vertex2<float>& Vertex2Array::operator [](d_type::Bsize index) const
{
    return m_vertices[index];
}
#endif // VERTEX2ARRAY_H
