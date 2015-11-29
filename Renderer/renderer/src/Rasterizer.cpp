#include "stdafx.h"
#include "Rasterizer.h"


Rasterizer::Rasterizer()
{
	buff = Buffer(512, 512);
}

Rasterizer::Rasterizer(Buffer buff_)
{
	buff = buff_;
}

void Rasterizer::Triangle(Vertex a, Vertex b, Vertex c)
{
	//cout << a << b << c;
	// Optymalizacja 1 - przeszukiwanie pixeli wewn¹trz najmniejszego 
	// prostok¹ta zawieraj¹cego trójk¹t
	float minX = std::min(std::min(a.position.x(), b.position.x()), c.position.x());
	float maxX = std::max(std::max(a.position.x(), b.position.x()), c.position.x());
	float minY = std::min(std::min(a.position.y(), b.position.y()), c.position.y());
	float maxY = std::max(std::max(a.position.y(), b.position.y()), c.position.y());
	//cout << minX << " " << maxX << ", " << minY << " " << maxY << endl;

	// Rzutowanie wspó³rzêdnych kanonicznych na wspó³rzêdne 
	// w oknie renderingu
	int minXPrim = (int)((minX + 1) * buff.GetBufferWidth() * 0.5f);
	int maxXPrim = (int)((maxX + 1) * buff.GetBufferWidth() * 0.5f);
	int minYPrim = (int)((minY + 1) * buff.GetBufferHeight() * 0.5f);
	int maxYPrim = (int)((maxY + 1) * buff.GetBufferHeight() * 0.5f);
	//cout << minXPrim << " " << maxXPrim << ", " << minYPrim << " " << maxYPrim << endl;

	// Optymalizacja - obcinanie (pomijanie pixeli wchodz¹cych w sk³ad trójk¹ta,
	// ale nie mieszcz¹cych siê	w buforze wyjœciowym
	minXPrim = std::max(minXPrim, 0);
	maxXPrim = std::min(maxXPrim, buff.GetBufferWidth()-1);
	minYPrim = std::max(minYPrim, 0);
	maxYPrim = std::min(maxYPrim, buff.GetBufferHeight()-1);
	//cout << minXPrim << " " << maxXPrim << ", " << minYPrim << " " << maxYPrim << endl;

	// Optymalizacja 2 - sta³e
	float dx12 = a.position.x() - b.position.x();
	float dx23 = b.position.x() - c.position.x();
	float dx31 = c.position.x() - a.position.x();
	float dx13 = a.position.x() - c.position.x();
	float dx32 = c.position.x() - b.position.x();
	float dy12 = a.position.y() - b.position.y();
	float dy23 = b.position.y() - c.position.y();
	float dy31 = c.position.y() - a.position.y();
	float dy13 = a.position.y() - c.position.y();

	// Top - left
	bool tl1 = false, tl2 = false, tl3 = false;
	if (dy12 < 0 || (dy12 == 0 && dx12>0))
		tl1 = true;
	if (dy23 < 0 || (dy23 == 0 && dx23>0))
		tl2 = true;
	if (dy31 < 0 || (dy31 == 0 && dx31>0))
		tl3 = true;

	//cout << tl1 << " " << tl2 << " " << tl3 << endl;


	float tmpX, tmpY;
	float lambda1, lambda2, lambda3;
	float depth;
	Color interpolatedColor;

	for (int i = minXPrim; i <= maxXPrim; i++)
	{
		// Rzutowanie z wspó³rzêdnych w oknie renderingu na wspó³rzêdne kanoniczne
		tmpX = i / (buff.GetBufferWidth() * 0.5f) - 1.0f;
		for (int j = minYPrim; j <= maxYPrim; j++)
		{
			// Rzutowanie z wspó³rzêdnych w oknie renderingu na wspó³rzêdne kanoniczne
			tmpY = j / (buff.GetBufferHeight() * 0.5f) - 1.0f;
			lambda1 = (dy23* (tmpX - c.position.x()) + dx32 * (tmpY - c.position.y())) /
						(dy23 *dx13 + dx32*dy13);
			lambda2 = (dy31* (tmpX - c.position.x()) + dx13 * (tmpY - c.position.y())) /
						(dy31 *dx23 + dx13*dy23);
			lambda3 = 1 - lambda1 - lambda2;

			// Half - space -> sprawdzanie czy pixel nale¿y do wnêtrza trójk¹ta
			//if (
			//	(dx12 * (tmpY - a.position.y()) - dy12 * (tmpX - a.position.x()) >= 0.0f) &&
			//	(dx23 * (tmpY - b.position.y()) - dy23 * (tmpX - b.position.x()) >= 0.0f) &&
			//	(dx31 * (tmpY - c.position.y()) - dy31 * (tmpX - c.position.x()) >= 0.0f))

			// Half - space -> sprawdzanie czy pixel nale¿y do wnêtrza trójk¹ta (b¹dŸ lezy na lewej||górnej krawêdzi)
			if (
				((tl1 && (dx12 * (tmpY - a.position.y()) - dy12 * (tmpX - a.position.x()) >= 0.0f)) || (dx12 * (tmpY - a.position.y()) - dy12 * (tmpX - a.position.x()) > 0.0f)) &&
				((tl2 && (dx23 * (tmpY - b.position.y()) - dy23 * (tmpX - b.position.x()) >= 0.0f)) || (dx23 * (tmpY - b.position.y()) - dy23 * (tmpX - b.position.x()) >= 0.0f)) &&
				((tl3 && (dx31 * (tmpY - c.position.y()) - dy31 * (tmpX - c.position.x()) >= 0.0f)) || (dx31 * (tmpY - c.position.y()) - dy31 * (tmpX - c.position.x()) > 0.0f))
				)
			{
				// Bufor g³ebokoœci
				depth = lambda1 * a.position.z() + lambda2 * b.position.z() + lambda3 * c.position.z();
				if (depth >= -1.f && depth <= 1.f && depth < buff.GetDepthAtPixel(i, j))
				{
					// Interpolacja koloru
					interpolatedColor = a.color.ToColor() * lambda1 + b.color.ToColor() * lambda2 + c.color.ToColor() * lambda3;
					buff.SetPixel(i, j, interpolatedColor, depth);
				}
			}
		}
	}
}

void Rasterizer::SaveBuffer(char *filename_)
{
	buff.SaveBufferToTga(filename_);
}

Rasterizer::~Rasterizer()
{
}
