#include "Battles/ScriptingMacros/Timer.hpp"

void Battles::ScriptingMacros::Timer::AddNewTimeNode(u8 eventId, u32 timeInFrames, u32 unk1, s8 unk2, u32 unk3) {

    TimeNode *timeNode = new TimeNode(timeInFrames, unk1, eventId, unk2, unk3);
    AddTimeNode(timeNode);
}

void Battles::ScriptingMacros::Timer::AddTimeNode(TimeNode *timeNode) {}

Battles::ScriptingMacros::Timer::TimeNode::TimeNode(u32 timeInFrames, u32 unk1, u8 eventId, s8 unk2, u32 unk3) {}
