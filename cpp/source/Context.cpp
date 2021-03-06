#include "Context.hpp"

using namespace sl;

Context::Context()
{
}

bool Context::update(const skylync::Context* _protoContext)
{
    std::unique_ptr<const skylync::Context> guard(_protoContext);
    if (validateProto(_protoContext))
    {
        protoContext.swap(guard);
        return true;
    }
    return false;
}

sl::RefId Context::getRefId() const
{
    return protoContext->refid();
}

bool Context::validateProto(const skylync::Context* _protoContext) const
{
    if (_protoContext->refid() != 0)
    {
        return false;
    }
    return true;
}
