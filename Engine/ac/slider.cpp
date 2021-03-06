//=============================================================================
//
// Adventure Game Studio (AGS)
//
// Copyright (C) 1999-2011 Chris Jones and 2011-20xx others
// The full list of copyright holders can be found in the Copyright.txt
// file, which is part of this source code distribution.
//
// The AGS source code is provided under the Artistic License 2.0.
// A copy of this license can be found in the file License.txt and at
// http://www.opensource.org/licenses/artistic-license-2.0.php
//
//=============================================================================

#include "ac/slider.h"
#include "ac/common.h"

extern int guis_need_update;

// *** SLIDER FUNCTIONS

void Slider_SetMax(GUISlider *guisl, int valn) {

    if (valn != guisl->max) {
        guisl->max = valn;

        if (guisl->value > guisl->max)
            guisl->value = guisl->max;
        if (guisl->min > guisl->max)
            quit("!Slider.Max: minimum cannot be greater than maximum");

        guis_need_update = 1;
    }

}

int Slider_GetMax(GUISlider *guisl) {
    return guisl->max;
}

void Slider_SetMin(GUISlider *guisl, int valn) {

    if (valn != guisl->min) {
        guisl->min = valn;

        if (guisl->value < guisl->min)
            guisl->value = guisl->min;
        if (guisl->min > guisl->max)
            quit("!Slider.Min: minimum cannot be greater than maximum");

        guis_need_update = 1;
    }

}

int Slider_GetMin(GUISlider *guisl) {
    return guisl->min;
}

void Slider_SetValue(GUISlider *guisl, int valn) {
    if (valn > guisl->max) valn = guisl->max;
    if (valn < guisl->min) valn = guisl->min;

    if (valn != guisl->value) {
        guisl->value = valn;
        guis_need_update = 1;
    }
}

int Slider_GetValue(GUISlider *guisl) {
    return guisl->value;
}

int Slider_GetBackgroundGraphic(GUISlider *guisl) {
    return (guisl->bgimage > 0) ? guisl->bgimage : 0;
}

void Slider_SetBackgroundGraphic(GUISlider *guisl, int newImage) 
{
    if (newImage != guisl->bgimage)
    {
        guisl->bgimage = newImage;
        guis_need_update = 1;
    }
}

int Slider_GetHandleGraphic(GUISlider *guisl) {
    return (guisl->handlepic > 0) ? guisl->handlepic : 0;
}

void Slider_SetHandleGraphic(GUISlider *guisl, int newImage) 
{
    if (newImage != guisl->handlepic)
    {
        guisl->handlepic = newImage;
        guis_need_update = 1;
    }
}

int Slider_GetHandleOffset(GUISlider *guisl) {
    return guisl->handleoffset;
}

void Slider_SetHandleOffset(GUISlider *guisl, int newOffset) 
{
    if (newOffset != guisl->handleoffset)
    {
        guisl->handleoffset = newOffset;
        guis_need_update = 1;
    }
}
