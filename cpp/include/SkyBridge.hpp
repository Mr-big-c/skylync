#ifndef SKYBRIDGE_HPP
#define SKYBRIDGE_HPP

#include "ITimer.hpp"
#include "ICommInterface.hpp"

#include "event/endpoint/Event.hpp"
#include "event/bridge/Event.hpp"

#include "state/IState.hpp"
#include "state/Idle.hpp"

#include <memory>
#include <mutex>

namespace sl
{

class SkyBridge : public state::IState::Listener,
        public ICommInterface::Listener
{
public:
    class Listener
    {
    public:
        enum Side
        {
            DEVICE,
            PILOT,
        } side;

        Listener(const Side _side);

        virtual ~Listener();

        virtual void
        notifyBridgeEvent(const event::bridge::Event* event) noexcept = 0;

        virtual std::shared_ptr<ICommInterface>
        createCommInterface(const ICommInterface::TransportProtocol protocol,
                            const ICommInterface::Listener& listener) noexcept = 0;

        virtual std::shared_ptr<ITimer>
        createTimer() noexcept = 0;

        virtual void
        trace(const std::string& message) noexcept = 0;
    };

    SkyBridge(Listener& _listener);

    void notifyEndpointEvent(const event::endpoint::Event* event) noexcept;

    state::IState::Type getState() const noexcept;

private:
    Listener& listener;

    std::unique_ptr<state::IState> state;
    std::mutex stateLock;

    std::shared_ptr<ICommInterface> commInterface;

    void handleEvent(const event::endpoint::Event* event) noexcept;
    void handleMessage() noexcept;

    // ICommInterface::Listener overrides
    void onConnected() override;
    void onDisconnected() override;
    void onReceived(const unsigned char* data, const size_t length) override;

    // state::IState::Listener overrides
    void connect();
    void disconnect();
    void notifyBridgeEvent(const event::bridge::Event* event) noexcept override;
    std::shared_ptr<ICommInterface>
    createCommInterface(const ICommInterface::TransportProtocol protocol,
                        const ICommInterface::Listener& _listener) noexcept override;
    std::shared_ptr<ITimer> createTimer() noexcept override;
    void trace(const std::string& message) noexcept override;
};

} // sl

#endif // SKYBRIDGE_HPP
