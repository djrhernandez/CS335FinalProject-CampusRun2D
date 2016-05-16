//Ryan Frapwell
// First created 4/25/16
// Last modified 5/13/16

#include "tyM.h"

extern "C" {
#include "fonts.h"
}


//This code gets called when the sprite jumps. 
//It updates the y axis of the sprite to make it look like it is jumping.
int Jumping (double spritesheetx, float wid, int jump, 
	int *sprite_y, GLuint jumpTexture, int stuff)
{
    if (!stuff) {
	if (jump < 32 && jump > 0) {
	    *sprite_y += 3;
	    jump++;
	} else if (jump >= 32 && jump < 62 ) {
	    *sprite_y -= 3;
	    jump ++;
	} else {
	    jump = 0;
	    *sprite_y = 75;
	}
    }
    if (stuff) {
	*sprite_y += 3;
	jump++;
    }

    glPushMatrix();
    //cout << bigfoot.pos[1] << endl;
    glTranslatef(140, *sprite_y, 0);
    glBindTexture(GL_TEXTURE_2D, jumpTexture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f+spritesheetx, 1.0f); glVertex2i(-wid,-wid);
    glTexCoord2f(0.0f+spritesheetx, 0.0f); glVertex2i(-wid, wid);
    glTexCoord2f(0.1f+spritesheetx, 0.0f); glVertex2i( wid, wid);
    glTexCoord2f(0.1f+spritesheetx, 1.0f); glVertex2i( wid,-wid);
    glEnd();
    glPopMatrix();

    return jump;

}

//This will project powerups onto the screen in front of the player
void projectImage(float x, float y, float z, GLuint speedTexture)
{
    float wid = 30;
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, speedTexture);
    glTranslatef(x, y, z);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(-wid,-wid);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(-wid, wid);
    glTexCoord2f(1.0f, 0.0f); glVertex2i( wid,wid);
    glTexCoord2f(1.0f, 1.0f); glVertex2i( wid,-wid);
    glEnd();
    glPopMatrix();

}

int checkcollison(int sprite_x, float x, int sprite_y, float y)
{

    if (x <= sprite_x+50 && x >= sprite_x-50) {
	if (y <= sprite_y+50 && y >= sprite_y-20) {
	    return 1;
	}
    } else {
	return 0; 
    }
    return 0; 
}

void displaybackground(double backgroundx, GLuint Texture, int yres, int xres, bool toggle)
{
    if(!toggle)
    {
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f-backgroundx, 1.0f); glVertex2i(0, 0);
	glTexCoord2f(0.0f-backgroundx, 0.0f); glVertex2i(0, yres);
	glTexCoord2f(1.0f-backgroundx, 0.0f); glVertex2i(xres, yres);
	glTexCoord2f(1.0f-backgroundx, 1.0f); glVertex2i(xres, 0);
	glEnd();
    } else {
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f-backgroundx, 1.0f); glVertex2i(0, 0);
	glTexCoord2f(0.0f-backgroundx, 0.0f); glVertex2i(0, yres);
	glTexCoord2f(1.0f-backgroundx, 0.0f); glVertex2i(xres*2, yres);
	glTexCoord2f(1.0f-backgroundx, 1.0f); glVertex2i(xres*2, 0);
	glEnd();
    }
}
