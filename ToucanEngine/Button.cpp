#include "Button.h"
#include "RenderGL.h"
Button::Button()
{
	//g_renderGL.buttonList.Add(*this);
}
void Button::SetButton(float x, float y, float w, float h)
{
	buttonX = x;
	buttonY = y;
	width = w;
	height = h;
}
void Button::DrawButton()
{
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex2f(buttonX - (width*0.5), buttonY - (height*0.5));
	glVertex2f(buttonX + (width*0.5), buttonY - (height *0.5));
	glVertex2f(buttonX + (width *0.5),buttonY + (height *0.5));
	glVertex2f(buttonX - (width *0.5),buttonY + (height *0.5));
	glEnd();
	glPopMatrix();
}
void Button::SetFuncId(int _id)
{
	funcId = _id;
}
void Button::OnButtonClicked()
{
	//Agregar Casos para funcId
	switch (funcId)
	{
	default:
		break;
	}
}
