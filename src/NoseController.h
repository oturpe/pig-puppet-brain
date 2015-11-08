#ifndef NOSE_SNIFFER_H
#define NOSE_SNIFFER_H

/// \class NoseController
///
/// Controller for pigs nose. Runs a hard coded sequence of pulling and
/// releasing the nose's electromagnet when running. Expects some external
/// system to tell when should be activated.
///
/// This class expects to have the run() method called on regular intervals.
/// These calls provide the clock for the movements.
class NoseController {

public:
    /// \brief
    ///    Creates and initializes a new unose sniffer.
    ///
    /// The nose is initialized not running. Pin used is D4.
    ///
    /// \param halfPeriod
    ///    Half period of a single nose movement
    ///
    /// \param halfUpperPeriod
    ///    Half period of a single sequence of nose pulls
    NoseController(uint16_t halfPeriod, uint8_t halfUpperPeriod);

    /// \brief
    ///    Destroys this nose sniffer instance.
    ~NoseController();
public:
    /// \brief
    ///    Starts nose sniffing.
    ///
    /// If sniffing is already underway, this method does nothing. Otherwise,
    /// the sniffing sequence starts from the beginning.
    void start();

    /// \brief
    ///    Stops sniffing.
    void stop();

    /// \brief
    ///    Run nose sniffer.
    void run();

    /// \brief
    ///    Rests the stepper motor. All outputs are disabled.
    void rest();

private:
    /// If the nose is currently sniffing
    bool sniffing;
    /// If the current note position is back
    bool noseBack;
    /// If upper cycles says sleep
    bool upperCycleSleep;
    /// How long the sniffing has been going on.
    uint16_t counter;
    /// Half period of a single nose movement
    const uint16_t halfPeriod;
    /// Half period of a single sequence of nose pulls
    const uint8_t halfUpperPeriod;
};

#endif