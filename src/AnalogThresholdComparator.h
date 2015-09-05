#ifndef ANALOG_TRESHOLD_COMPARATOR_H_
#define ANALOG_TRESHOLD_COMPARATOR_H_

/// \class AnalogThresholdComparator
///
/// Reads analog values of two sensors and tells if they are above the set
/// threshold or not. Also sets indicator pins high if the threshold is
/// exceeded.

class AnalogThresholdComparator {
public:
    /// \struct Reading
    ///
    /// Readings from sensors after comparator.
    struct Reading {
        bool leftFound;
        bool rightFound;
    };

public:
    /// \brief
    ///    Creates a new analog treshold comparator instance with set threshold.
    ///
    /// \param threshold
    ///    Comparator threshold
    AnalogThresholdComparator(uint16_t threshold);

    /// \brief
    ///    Destroys this analog threshold comparator instance
    ~AnalogThresholdComparator();

public:
/// \brief
///    Reads left and right pen limit sensors and returns their values. Note
///    that this function sleeps while the conversion is in progress
///
/// \return
///    Sensor readings
Reading read();

private:
    /// Comparator threshold
    uint16_t threshold;
};

#endif