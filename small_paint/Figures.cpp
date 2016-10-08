#include "stdafx.h"
#include <windows.h>

class TFigure
{
	protected:
		virtual void Draw(HDC dc) = 0;
	public:
		void Paint(HDC dc)
		{
			Draw(dc);
		}
};

class TLine : public TFigure
{
	private:
		int x;
		int y;
	protected:
		virtual void Draw(HDC dc) 
		{
			LineTo(dc, x, y);
		}
	public:
		TLine(int aX, int aY) 
		{
			x = aX; y = aY;
		}
};

class TRectangle : public TFigure
{
	private:
		int x;
		int y;
		int width;
		int height;

	protected:
		virtual void Draw(HDC dc)
		{
			Rectangle(dc, x, y, x + width, y + height);
		}

	public:
		TRectangle(int aX, int aY, int aWidth, int aHeight)
		{
			x = aX; y = aY; width = aWidth; height = aHeight;
		}
};

class TCircle : public TFigure
{
	private:
		int x;
		int y;
		int radius;

	protected:
		virtual void Draw(HDC dc)
		{
			Ellipse(dc, x - radius, y - radius, x + radius, y + radius);
		}

	public:
		TCircle(int aX, int aY, int aRadius)
		{
			x = aX; y = aY; radius = aRadius;
		}
};