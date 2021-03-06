#ifndef STATE_ATTACHED_PILOT_OPERATION_HPP
#define STATE_ATTACHED_PILOT_OPERATION_HPP

#include "state/attached/IAttachedState.hpp"

namespace sl
{

namespace state
{

namespace attached
{

namespace pilot
{

class Operation : public IAttachedState
{
public:
    Operation(ILiveCycleState::Listener& listener);

    void start() noexcept override;

    IAttachedState* handleEvent(const sl::event::endpoint::Event& event) override;

    IAttachedState* handleMessage(std::shared_ptr<skylync::BridgeMessage> message) override;

    std::string toString() const noexcept override;
};

} // pilot

} // attached

} // state

} // sl

#endif // STATE_ATTACHED_PILOT_OPERATION_HPP
