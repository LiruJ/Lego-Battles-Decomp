#ifndef MAP_H
#define MAP_H

#include "global.h"
#include "types.h"

namespace Battles {
    class Map {
    public:
        static const char *TERR;
        static const char *EVNT;
        static const char *TRIG;
        static const char *MINE;
        static const char *MARK;
        static const char *PAM;

        THUMB void OnLoad();
        THUMB u8 *Load(u8 *data);
        THUMB u8 *LoadTerrain(u8 *data);
        THUMB u8 *LoadMines(u8 *data);
        THUMB u8 *LoadEvents(u8 *data);
        THUMB u8 *LoadTriggers(u8 *data);
        THUMB u8 *LoadMarkers(u8 *data);
        THUMB void LoadMarker();
        THUMB void LoadTriggerTeam();

        // PtrArray*
        THUMB void *GetEventWithId(u32 eventId) {
            return (void *) 0;
        }

    private:
    };
} // namespace Battles

#endif // !MAP_H
