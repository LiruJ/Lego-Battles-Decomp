#include "Battles/Map/Map.hpp"

#include <string.h>

const char *Battles::Map::TERR = "TERR";
const char *Battles::Map::EVNT = "EVNT";
const char *Battles::Map::TRIG = "TRIG";
const char *Battles::Map::MINE = "MINE";
const char *Battles::Map::MARK = "MARK";
const char *Battles::Map::PAM  = "PAM";

void Battles::Map::OnLoad() {}

u8 *Battles::Map::Load(u8 *data) {

    if (!strncmp((char *) data, (char *) TERR, 4)) {
        return LoadTerrain(data);
    }
    if (!strncmp((char *) data, (char *) EVNT, 4)) {
        return LoadEvents(data);
    }
    if (!strncmp((char *) data, (char *) TRIG, 4)) {
        return LoadTriggers(data);
    }
    if (!strncmp((char *) data, (char *) MINE, 4)) {
        return LoadMines(data);
    }
    if (!strncmp((char *) data, (char *) MARK, 4)) {
        return LoadMarkers(data);
    }
    strncmp((char *) data, (char *) PAM, 3);
    return (u8 *) 0;
}

u8 *Battles::Map::LoadTerrain(u8 *data) {
    return data;
}

u8 *Battles::Map::LoadMines(u8 *data) {
    return data;
}

u8 *Battles::Map::LoadEvents(u8 *data) {
    return data;
}

u8 *Battles::Map::LoadTriggers(u8 *data) {
    return data;
}

u8 *Battles::Map::LoadMarkers(u8 *data) {
    return data;
}

void Battles::Map::LoadMarker() {}

void Battles::Map::LoadTriggerTeam() {}