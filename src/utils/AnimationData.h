#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"


struct FrameRect{
    float x;
    float y;
    float w;
    float h;
};

struct FrameData{

    FrameRect frame_r;
    int sourceWidth,sourceHeight;
    bool rotated;
    bool trimmed;
    float durationSeconds;
};

class AnimationData{
    
    private:

    std::vector<FrameData> frames;

    public:
    const std::vector<FrameData> & getFrames() const;
    void ReadFile(std::string path);
    
    
    int FrameCount();
};