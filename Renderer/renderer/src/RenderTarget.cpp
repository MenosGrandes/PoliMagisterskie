#include "RenderTarget.h"
RenderTarget::RenderTarget() {}


RenderTarget::~RenderTarget()
{
}

RenderTarget::RenderTarget(Vector2Bi size):m_size(size)
{
    m_pixels=new Colour[size.x*size.y];

    m_dBuffer=new d_type::Bfloat[getSizePixels()];
    for(d_type::Bint i=0; i<getSizePixels(); i++)
    {
        m_dBuffer[i]=100000.0f;

    }

}


void RenderTarget::setPixel(ColorDepth colorDepth, const d_type::Bint &x, const d_type::Bint &y)
{


        m_pixels[convert2dto1d(x,y)] = colorDepth.color;
        m_dBuffer[convert2dto1d(x,y)]= colorDepth.depth;



}
//Convert 2d array indexing to 1d indexing
d_type::Bint RenderTarget::convert2dto1d(d_type::Bint x, d_type::Bint y)
{
    return m_size.x * y + x;
}
d_type::Bint RenderTarget::convert2dto1d(Vector2Bi size)
{
    return m_size.x * size.y + size.x;
}


void RenderTarget::setWidth(const d_type::Bfloat &width)
{
    m_size.x=width;
}

void RenderTarget::setHeight(const d_type::Bfloat &height)
{
    m_size.y=height;
}

d_type::Bint RenderTarget::getWidth() const
{
    return m_size.x;
}

d_type::Bint RenderTarget::getHeight() const
{
    return m_size.y;
}

Vector2Bi RenderTarget::getSize() const
{
    return m_size;
}
d_type::Bint RenderTarget::getSizePixels() const
{

    return m_size.x * m_size.y;
}


d_type::Bfloat RenderTarget::getDepthBuffer() const
{

    for(d_type::Bint i=0; i<getSizePixels(); i++)
    {
        std::cout<<m_dBuffer[i]<<"\n";

    }
    return 0.0f;
}

void RenderTarget::drawToFile(std::string m_filename)
{
    //Error checking
    if (m_size.x <= 0 || m_size.y <= 0)
    {
        std::cout << "Image size is not set properly\n";
        return;
    }

    std::ofstream o(m_filename.c_str(), std::ios::out | std::ios::binary);

    //Write the header
    o.put(0);
    o.put(0);
    o.put(2);                         /* uncompressed RGB */
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);           /* X origin */
    o.put(0);
    o.put(0);           /* y origin */
    o.put(((int)m_size.x  & 0x00FF));
    o.put(((int)m_size.x & 0xFF00) / 256);
    o.put(((int)m_size.y  & 0x00FF));
    o.put(((int)m_size.y  & 0xFF00) / 256);
    o.put(32);                        /* 24 bit bitmap */
    o.put(0);

    //Write the pixel data
    for (d_type::Bint i=0; i<getSizePixels() ; i++)
    {
        //std::cout<<(float)m_pixels[i].b <<" "<<(float)m_pixels[i].g<<" "<<(float)m_pixels[i].r<<" "<<(float)m_pixels[i].a<<"\n";
        o.put(m_pixels[i].b*255);
        o.put(m_pixels[i].g*255);
        o.put(m_pixels[i].r*255);
        o.put(255);
    }

    //close the file
    o.close();
}




Colour RenderTarget::getCleanColour() const
{
    return m_cleanColour;
}

void RenderTarget::setCleanColour(const Colour& c)
{
    m_cleanColour=c;
}


void RenderTarget::clearPixel(const d_type::Bint& x, const d_type::Bint& y)
{
    m_pixels[convert2dto1d(x,y)] = m_cleanColour;

}


Colour * RenderTarget::getColorPixels()
{

    return m_pixels;
}


void RenderTarget::drawToFile(Colour* colors)
{
    //Error checking
    if (m_size.x <= 0 || m_size.y <= 0)
    {
        std::cout << "Image size is not set properly\n";
        return;
    }

    std::ofstream o("Wynikowy.tga", std::ios::out | std::ios::binary);

    //Write the header
    o.put(0);
    o.put(0);
    o.put(2);                         /* uncompressed RGB */
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);           /* X origin */
    o.put(0);
    o.put(0);           /* y origin */
    o.put(((int)m_size.x  & 0x00FF));
    o.put(((int)m_size.x & 0xFF00) / 256);
    o.put(((int)m_size.y  & 0x00FF));
    o.put(((int)m_size.y  & 0xFF00) / 256);
    o.put(32);                        /* 24 bit bitmap */
    o.put(0);

    //Write the pixel data
    for (d_type::Bint i=0; i<getSizePixels() ; i++)
    {
        //std::cout<<(float)m_pixels[i].b <<" "<<(float)m_pixels[i].g<<" "<<(float)m_pixels[i].r<<" "<<(float)m_pixels[i].a<<"\n";
        o.put(colors[i].b*255);
        o.put(colors[i].g*255);
        o.put(colors[i].r*255);
        o.put(255);
    }

    //close the file
    o.close();
}


void RenderTarget::triangle(Vertex3Bf a, Vertex3Bf b, Vertex3Bf c)
{
    //cout << a << b << c;
	// Optymalizacja 1 - przeszukiwanie pixeli wewn¹trz najmniejszego
	// prostok¹ta zawieraj¹cego trójk¹t
	float minX = std::min(std::min(a.m_position.x, b.m_position.x), c.m_position.x);
	float maxX = std::max(std::max(a.m_position.x, b.m_position.x), c.m_position.x);
	float minY = std::min(std::min(a.m_position.y, b.m_position.y), c.m_position.y);
	float maxY = std::max(std::max(a.m_position.y, b.m_position.y), c.m_position.y);
	//cout << minX << " " << maxX << ", " << minY << " " << maxY << endl;

	// Rzutowanie wspó³rzêdnych kanonicznych na wspó³rzêdne
	// w oknie renderingu
	int minXPrim = (int)((minX + 1) * m_size.x * 0.5f);
	int maxXPrim = (int)((maxX + 1) * m_size.x * 0.5f);
	int minYPrim = (int)((minY + 1) * m_size.y * 0.5f);
	int maxYPrim = (int)((maxY + 1) * m_size.y * 0.5f);
	//cout << minXPrim << " " << maxXPrim << ", " << minYPrim << " " << maxYPrim << endl;

	// Optymalizacja - obcinanie (pomijanie pixeli wchodz¹cych w sk³ad trójk¹ta,
	// ale nie mieszcz¹cych siê	w buforze wyjciowym
	minXPrim = std::max(minXPrim, 0);
	maxXPrim = std::min(maxXPrim, m_size.x-1);
	minYPrim = std::max(minYPrim, 0);
	maxYPrim = std::min(maxYPrim, m_size.y-1);
	//cout << minXPrim << " " << maxXPrim << ", " << minYPrim << " " << maxYPrim << endl;

	// Optymalizacja 2 - sta³e
	float dx12 = a.m_position.x - b.m_position.x;
	float dx23 = b.m_position.x - c.m_position.x;
	float dx31 = c.m_position.x - a.m_position.x;
	float dx13 = a.m_position.x - c.m_position.x;
	float dx32 = c.m_position.x - b.m_position.x;
	float dy12 = a.m_position.y - b.m_position.y;
	float dy23 = b.m_position.y - c.m_position.y;
	float dy31 = c.m_position.y - a.m_position.y;
	float dy13 = a.m_position.y - c.m_position.y;

	// Top - left
	bool tl1 = false, tl2 = false, tl3 = false;
	if (dy12 < 0 || (dy12 == 0 && dx12>0))
		tl1 = true;
	if (dy23 < 0 || (dy23 == 0 && dx23>0))
		tl2 = true;
	if (dy31 < 0 || (dy31 == 0 && dx31>0))
		tl3 = true;



	float tmpX, tmpY;
	float lambda1, lambda2, lambda3;
	float depth;
	Colour interpolatedColor;

	for (int i = minXPrim; i <= maxXPrim; i++)
	{
		tmpX = i / (m_size.x * 0.5f) - 1.0f;
		for (int j = minYPrim; j <= maxYPrim; j++)
		{
			tmpY = j / (m_size.y * 0.5f) - 1.0f;
			lambda1 = (dy23* (tmpX - c.m_position.x) + dx32 * (tmpY - c.m_position.y)) /
						(dy23 *dx13 + dx32*dy13);
			lambda2 = (dy31* (tmpX - c.m_position.x) + dx13 * (tmpY - c.m_position.y)) /
						(dy31 *dx23 + dx13*dy23);
			lambda3 = 1 - lambda1 - lambda2;

			if (
				((tl1 && (dx12 * (tmpY - a.m_position.y) - dy12 * (tmpX - a.m_position.x) >= 0.0f)) || (dx12 * (tmpY - a.m_position.y) - dy12 * (tmpX - a.m_position.x) > 0.0f)) &&
				((tl2 && (dx23 * (tmpY - b.m_position.y) - dy23 * (tmpX - b.m_position.x) >= 0.0f)) || (dx23 * (tmpY - b.m_position.y) - dy23 * (tmpX - b.m_position.x) >= 0.0f)) &&
				((tl3 && (dx31 * (tmpY - c.m_position.y) - dy31 * (tmpX - c.m_position.x) >= 0.0f)) || (dx31 * (tmpY - c.m_position.y) - dy31 * (tmpX - c.m_position.x) > 0.0f))
				)
			{
				depth = lambda1 * a.m_position.z + lambda2 * b.m_position.z + lambda3 * c.m_position.z;
				if (depth >= -1.f && depth <= 1.f && depth < m_dBuffer[convert2dto1d(i,j)])//buff.GetDepthAtPixel(i, j))
				{

					interpolatedColor = a.m_color * lambda1 + b.m_color * lambda2 + c.m_color * lambda3;

					ColorDepth cd;
					cd.color=interpolatedColor;
					cd.depth=depth;
					setPixel(cd,i,j);

				}
			}
		}
	}
}

