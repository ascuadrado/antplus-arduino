#ifndef ANTPLUS_PROFILELEVDISPLAY_h
#define ANTPLUS_PROFILELEVDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/Lev/DataPages/ANTPLUS_ProfileLevDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

#include "ANT.h"

class ProfileLevDisplay : public BaseSlaveProfile {
public:
    ProfileLevDisplay();
    ProfileLevDisplay(uint16_t deviceNumber);
    ProfileLevDisplay(uint16_t deviceNumber, uint8_t transmissionType);

    void onLevSpeedSystemInformation1(void(*func)(LevSpeedSystemInformation1&, uintptr_t), uintptr_t data = 0) { _onLevSpeedSystemInformation1.set(func, data); }
    void onLevSpeedDistanceInformation(void(*func)(LevSpeedDistanceInformation&, uintptr_t), uintptr_t data = 0) { _onLevSpeedDistanceInformation.set(func, data); }
    void onLevAltSpeedDistanceInformation(void(*func)(LevAltSpeedDistanceInformation&, uintptr_t), uintptr_t data = 0) { _onLevAltSpeedDistanceInformation.set(func, data); }
    void onLevSpeedSystemInformation2(void(*func)(LevSpeedSystemInformation2&, uintptr_t), uintptr_t data = 0) { _onLevSpeedSystemInformation2.set(func, data); }
    void onLevBatteryInformation(void(*func)(LevBatteryInformation&, uintptr_t), uintptr_t data = 0) { _onLevBatteryInformation.set(func, data); }
    void onLevCapabilities(void(*func)(LevCapabilities&, uintptr_t), uintptr_t data = 0) { _onLevCapabilities.set(func, data); }
    void onManufacturersInformation(void(*func)(ManufacturersInformation&, uintptr_t), uintptr_t data = 0) { _onManufacturersInformation.set(func, data); }
    void onProductInformation(void(*func)(ProductInformation&, uintptr_t), uintptr_t data = 0) { _onProductInformation.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(LevBaseMainDataPage& dataPage);
    bool handleSpeedSystemInformation1(LevBaseMainDataPage& dataPage);
    bool handleSpeedDistanceInformation(LevBaseMainDataPage& dataPage);
    bool handleAltSpeedDistanceInformation(LevBaseMainDataPage& dataPage);
    bool handleSpeedSystemInformation2(LevBaseMainDataPage& dataPage);
    bool handleBatteryInformation(LevBaseMainDataPage& dataPage);
    bool handleCapabilities(LevBaseMainDataPage& dataPage);
    bool handleManufacturersInformation(LevBaseMainDataPage& dataPage);
    bool handleProductInformation(LevBaseMainDataPage& dataPage);

    AntCallback<LevSpeedSystemInformation1&> _onLevSpeedSystemInformation1;
    AntCallback<LevSpeedDistanceInformation&> _onLevSpeedDistanceInformation;
    AntCallback<LevAltSpeedDistanceInformation&> _onLevAltSpeedDistanceInformation;
    AntCallback<LevSpeedSystemInformation2&> _onLevSpeedSystemInformation2;
    AntCallback<LevBatteryInformation&> _onLevBatteryInformation;
    AntCallback<LevCapabilities&> _onLevCapabilities;
    AntCallback<ManufacturersInformation&> _onManufacturersInformation;
    AntCallback<ProductInformation&> _onProductInformation;
};

#endif // ANTPLUS_PROFILELEVDISPLAY_h
