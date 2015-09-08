#ifndef READING_H_
#define READING_H_

#include <stdint.h>

/// \class Reading
///
/// Readings from sensors after comparator.
class Reading {
public:
    /// \brief
    ///    Initialized a new reading instance. Both values are set false.
    Reading();

    /// \brief
    ///    Destroys this reading instance.
    ~Reading();

    bool operator == (Reading & that);

public:
    /// \brief
    ///    Supports the reading.
    void support();

    /// \brief
    ///    If this reading has been confirmed enough times to consider it valid.
    ///
    /// \return
    ///    If this reading is valid
    bool isValid();

public:
    /// Left reading
    bool left;
    /// Right reading
    bool right;

private:
	/// How many times this reading has been supported.
	uint8_t supported;
};

#endif
