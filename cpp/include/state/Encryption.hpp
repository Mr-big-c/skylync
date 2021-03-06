#ifndef STATE_ENCRYPTION_HPP
#define STATE_ENCRYPTION_HPP

#include "ILiveCycleState.hpp"

namespace sl
{

namespace state
{

class Encryption : public ILiveCycleState
{
public:
    Encryption(Listener& listener);

    void start() noexcept override;

    void onReceived(const DataPacket dataPacket) override;

    std::string toString() const noexcept override;
};

} // state

} // sl

#endif // STATE_ENCRYPTION_HPP
