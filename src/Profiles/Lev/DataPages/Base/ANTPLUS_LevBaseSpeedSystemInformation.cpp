#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseSpeedSystemInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

uint8_t LevBaseSpeedSystemInformation::getCurrentRegenerativeLevel() {
    return getData(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_TRAVELMODESTATE_BYTE) & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_TRAVELMODESTATE_CURRENTREGENERATIVELEVEL_MASK;
}

uint8_t LevBaseSpeedSystemInformation::getCurrentAssistLevel() {
    return (getData(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_TRAVELMODESTATE_BYTE) >> ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_TRAVELMODESTATE_CURRENTASSISTLEVEL_SHIFT) & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_TRAVELMODESTATE_CURRENTASSISTLEVEL_MASK;
}

uint8_t LevBaseSpeedSystemInformation::getSystemState() {
    return getData(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_SYSTEMSTATE_BYTE);
}

uint8_t LevBaseSpeedSystemInformation::getCurrentFrontGear() {
    return getData(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_BYTE) & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_CURRENTFRONTGEAR_MASK;
}

uint8_t LevBaseSpeedSystemInformation::getCurrentRearGear() {
    return (getData(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_BYTE) >> ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_CURRENTREARGEAR_SHIFT) & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_CURRENTREARGEAR_MASK;
}

uint8_t LevBaseSpeedSystemInformation::getManualAutoState() {
    return (getData(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_BYTE) >> ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_MANUALAUTO_SHIFT) & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_MANUALAUTO_MASK;
}

uint8_t LevBaseSpeedSystemInformation::getGearExist() {
    return (getData(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_BYTE) >> ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_GEAREXIST_SHIFT) & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION_GEARSTATE_GEAREXIST_MASK;
}

uint16_t LevBaseSpeedSystemInformation::getSpeed() { // in 1/10 km/h
    return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}
