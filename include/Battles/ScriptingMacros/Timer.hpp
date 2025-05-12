#ifndef TIMER_H
#define TIMER_H

#include "types.h"

namespace Battles {
    namespace ScriptingMacros {
        class Timer {
        public:
            class TimeNode {
            public:
                u32 unk1;
                void *List1;
                void *List2;

                TimeNode(u32 timeInFrames, u32 unk1, u8 eventId, s8 unk2, u32 unk3);

                virtual ~TimeNode() {};
            };

            void AddNewTimeNode(u8 eventId, u32 timeInFrames, u32 unk1, s8 unk2, u32 unk3);

            virtual ~Timer() {}

        private:
            void AddTimeNode(TimeNode *timeNode);
        } CurrentTimer;
    } // namespace ScriptingMacros
} // namespace Battles
#endif // !TIMER_H