template <typename T>
ActionTarget<T>::ActionTarget(const ActionMap<T>& map) 
	: actionMap_(map)
{}

template <typename T>
bool ActionTarget<T>::processEvent(const sf::Event& event) const
{
	bool res = false;
    for(auto& pair : eventsPoll_)
    {
        if(actionMap_.get(pair.first) == event)
        {
            pair.second(event);
            res = true;
            break;
        }
    }
    return res;
}

template <typename T>
void ActionTarget<T>::processEvents() const
{
	for (auto& pair : eventsRealTime_)
    {
        const Action& action = _actionMap.get(pair.first);
        if(action.test())
		    pair.second(action._event);
    }
}

template <typename T>
void ActionTarget<T>::bind(const T& key, const FuncType& callback)
{
    const Action& action = _actionMap.get(key);
    if (action.type_ & Action::Type::RealTime)
        eventsRealTime_.emplace_back(key, callback);
    else
        eventsPoll_.emplace_back(key, callback);
}

template <typename T>
void ActionTarget<T>::unbind(const T& key)
{
    auto remove_func = [&key](const std::pair<T,FuncType>& pair) -> bool
    {
        return pair.first == key;
    };

    const Action& action = actionMap_.get(key);
    if (action._type & Action::Type::RealTime)
        eventsRealTime_.remove_if(remove_func);
    else
        eventsPoll_.remove_if(remove_func);
}