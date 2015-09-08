#ifndef ANALOG_TRESHOLD_COMPARATOR_H_
#define ANALOG_TRESHOLD_COMPARATOR_H_

#include "Reading.h"

/// \class AnalogThresholdComparator
///
/// Reads analog values of two sensors and tells if they are above the set
/// threshold or not. Also sets indicator pins high if the threshold is
/// exceeded.

class AnalogThresholdComparator {
public:
    /// \brief
    ///    Creates a new analog treshold comparator instance with set threshold.
    ///
    ///
    /// \param threshold
    ///    Threshold for finding a value
    ///
    /// \param hysteresis
    ///    Hysteresis between find and lose conditions
    AnalogThresholdComparator(uint16_t threshold, uint16_t hysteresis);

    /// \brief
    ///    Destroys this analog threshold comparator instance
    ~AnalogThresholdComparator();

public:

    /// \brief
    ///    Reads ambient value to use as a base of finding values. This method must
    ///    be called before read() returns correct readings. The call must happen in
    ///    conditions when pen limit is not below sensors.
    void recordAmbientReading();
    ///
    /// \brief
    ///    Reads left and right pen limit sensors and returns their values. Note
    ///    that this function sleeps while the conversion is in progress
    ///
    /// \return
    ///    Sensor readings
    Reading read();

private:
    /// \brief
    ///    Sets indicators according to current reading. Does not take reading
    ///    validity into account in any way.
    void setIndicators();

private:
    /// Threshold above ambient for reading found
    const uint16_t threshold;

    /// Hysteresis between find and lose states
    const uint16_t hysteresis;

    uint16_t leftFindThreshold;
    uint16_t leftLoseThreshold;

    uint16_t rightFindThreshold;
    uint16_t rightLoseThreshold;

    /// Current reading
    Reading currentReading;
};

#endif