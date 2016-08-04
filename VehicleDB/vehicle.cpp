#include "vehicle.h"

Vehicle::Vehicle(std::string plate,
                 float weight,
                 unsigned short int seatCount,
                 std::string chassisId,
                 std::string engineId,
                 Person owner,
                 Date initialRegistration,
                 Date currentRegistration)
    : m_Plate(plate),
      m_Weight(weight),
      m_SeatCount(seatCount),
      m_ChassisId(chassisId),
      m_EngineId(engineId),
      m_Owner(owner),
      m_InitialRegistration(initialRegistration),
      m_CurrentRegistration(currentRegistration)
{
}
