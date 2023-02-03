#include <functional>

class UICallback
{
public:
    using Callback = std::function<void()>;

    UICallback(Callback callback) : _callback(callback) {}

    void operator()() const
    {
        _callback();
    }

private:
    Callback _callback;
};
