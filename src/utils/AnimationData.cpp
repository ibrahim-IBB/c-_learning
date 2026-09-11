#include "AnimationData.h"


using json = nlohmann::json;

const std::vector<FrameData>& AnimationData::getFrames()const{
    return frames;
}



void AnimationData::ReadFile(std::string path){
    std::fstream file(path.c_str());

    if(!file.is_open()){
        std::cout<<"error opening file"<<path<<std::endl;
        return;
    }
    json data=json::parse(file);

    for(const auto &obj: data["frames"]){
        FrameRect temp_frame_rect;
        FrameData temp_frame_data;
        temp_frame_rect.x=obj["frame"]["x"];
        temp_frame_rect.y=obj["frame"]["y"];
        temp_frame_rect.w=obj["frame"]["w"];
        temp_frame_rect.h=obj["frame"]["h"];

        temp_frame_data.frame_r=temp_frame_rect;
        temp_frame_data.durationSeconds=obj["duration"];
        temp_frame_data.rotated=obj["rotated"];
        temp_frame_data.trimmed=obj["trimmed"];
        temp_frame_data.sourceHeight=obj["sourceSize"]["h"];
        temp_frame_data.sourceWidth=obj["sourceSize"]["w"];

  
        frames.push_back(temp_frame_data);
    }
    
 
    

}

int AnimationData::FrameCount(){
    return frames.size();
}