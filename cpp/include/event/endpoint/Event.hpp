#ifndef ENDPOINT_EVENT_HPP
#define ENDPOINT_EVENT_HPP

namespace sl
{

namespace event
{

namespace endpoint
{

class Event
{
public:
    enum Type
    {
        CONNECT,
    };

    Event(const Type _type):
        type(_type)
    {
    }

    virtual ~Event()
    {
    }

private:
    const Type type;
};

} // endpoint

} // event

} // sl

#endif // ENDPOINT_EVENT_HPP