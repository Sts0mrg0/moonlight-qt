#pragma once

#include "renderer.h"

#include <interface/mmal/mmal.h>
#include <interface/mmal/util/mmal_util.h>
#include <interface/mmal/util/mmal_util_params.h>
#include <interface/mmal/util/mmal_default_components.h>

class MmalRenderer : public IFFmpegRenderer {
public:
    MmalRenderer();
    virtual ~MmalRenderer() override;
    virtual bool initialize(PDECODER_PARAMETERS params) override;
    virtual bool prepareDecoderContext(AVCodecContext* context) override;
    virtual void renderFrame(AVFrame* frame) override;
    virtual enum AVPixelFormat getPreferredPixelFormat(int videoFormat) override;
    virtual bool needsTestFrame() override;

private:
    static void InputPortCallback(MMAL_PORT_T* port, MMAL_BUFFER_HEADER_T* buffer);

    MMAL_COMPONENT_T* m_Renderer;
    MMAL_PORT_T* m_InputPort;
};

