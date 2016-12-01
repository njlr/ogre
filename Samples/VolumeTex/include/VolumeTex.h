/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2014 Torus Knot Software Ltd
Also see acknowledgements in Readme.html

You may use this sample code for anything you like, it is not covered by the
same license as the rest of the engine.
-----------------------------------------------------------------------------
*/
#ifndef SAMPLES_VOLUMETEX_INCLUDE_VOLUMETEX_H_
#define SAMPLES_VOLUMETEX_INCLUDE_VOLUMETEX_H_


/** Generate 3D julia sets and render them as volume texture
    This demonstrates
       - User generated textures
       - Procedural volume textures (Julia makes nice dust clouds)
       - Custom renderables
    @author W.J. van der Laan
*/

#include "SamplePlugin.h"
#include "SdkSample.h"

using namespace Ogre;
using namespace OgreBites;

class _OgreSampleClassExport Sample_VolumeTex : public SdkSample
{
public:

    Sample_VolumeTex()
    {
        mInfo["Title"] = "Volume Textures";
        mInfo["Description"] = "Demonstrates the use of volume textures.";
        mInfo["Thumbnail"] = "thumb_voltex.png";
        mInfo["Category"] = "Unsorted";
    }

    void testCapabilities(const RenderSystemCapabilities* caps)
    {
        if (!caps->hasCapability(RSC_TEXTURE_3D))
        {
            OGRE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "Your card does not support 3D textures, so cannot "
                "run this demo. Sorry!", "Sample_VolumeTex::testCapabilities");
        }
    }

protected:

    float global_real, global_imag, global_theta;

    void setupView(void)
    {
        SdkSample::setupView();

        // Create the camera
        mCamera->setPosition(Vector3(220,-2,176));
        mCamera->lookAt(Vector3(0,0,0));
        mCamera->setNearClipDistance(5);
    }

    void setupContent(void);

    bool frameRenderingQueued( const FrameEvent& evt );

    void cleanupContent(void);

    void createControls()
    {
        mTrayMgr->createLabel(TL_TOPLEFT, "JuliaParamLabel", "Julia Parameters", 200);
        mTrayMgr->createThickSlider(TL_TOPLEFT, "RealSlider", "Real", 200, 80, -1, 1, 50)->setValue(global_real, false);
        mTrayMgr->createThickSlider(TL_TOPLEFT, "ImagSlider", "Imag", 200, 80, -1, 1, 50)->setValue(global_imag, false);
        mTrayMgr->createThickSlider(TL_TOPLEFT, "ThetaSlider", "Theta", 200, 80, -1, 1, 50)->setValue(global_theta, false);
        mTrayMgr->showCursor();
    }

    void sliderMoved(Slider* slider)
    {
        if (slider->getName() == "RealSlider")
        {
            global_real = slider->getValue();
        }
        else if (slider->getName() == "ImagSlider")
        {
            global_imag = slider->getValue();
        }
        else if (slider->getName() == "ThetaSlider")
        {
            global_theta = slider->getValue();
        }
        generate();
    }

    void generate();
};



#endif /* SAMPLES_VOLUMETEX_INCLUDE_VOLUMETEX_H_ */