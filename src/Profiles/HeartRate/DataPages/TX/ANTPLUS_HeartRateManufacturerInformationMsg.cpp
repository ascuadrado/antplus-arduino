#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateManufacturerInformationMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateManufacturerInformationMsg::HeartRateManufacturerInformationMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER) {

}

uint8_t HeartRateManufacturerInformationMsg::getManufacturerIdLsb() {
    // TODO
}

uint16_t HeartRateManufacturerInformationMsg::getSerialNumber() {
    // TODO
}

void HeartRateManufacturerInformationMsg::setManufacturerIdLsb(uint8_t id) {
    // TODO
}

void HeartRateManufacturerInformationMsg::setSerialNumber(uint16_t serialNumber) {
    // TODO
}
