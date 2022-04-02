#pragma once

template<typename ...TArgs>
class TCallback
{
public:
	typedef TFunction<void(TArgs...)> FSignature;
	
	void Broadcast_Impl(const TArgs &... Args);

	[[nodiscard]] int Subscribe_Impl(const FSignature &Subscriber);
	[[nodiscard]] int Subscribe_Impl(FSignature &&Subscriber);
	
	void Unsubscribe_Impl(int Token);
	
protected:
	TArray<FSignature> Subscribers;
	TArray<int> Tokens;
	int NextTokenId { 0 };
};

template <typename ... TArgs>
void TCallback<TArgs...>::Broadcast_Impl(const TArgs &... Args)
{
	for (const auto &Subscriber : Subscribers)
		Subscriber(Args...);
}

template <typename ... TArgs>
int TCallback<TArgs...>::Subscribe_Impl(const FSignature& Subscriber)
{
	Subscribers.Push(Subscriber);
	Tokens.Emplace(++NextTokenId);
	return NextTokenId;
}

template <typename ... TArgs>
int TCallback<TArgs...>::Subscribe_Impl(FSignature&& Subscriber)
{
	Subscribers.Emplace(Subscriber);
	Tokens.Emplace(++NextTokenId);
	return NextTokenId;
}

template <typename ... TArgs>
void TCallback<TArgs...>::Unsubscribe_Impl(const int Token)
{
	const auto Index = Tokens.Find(Token);
	Tokens.RemoveAt(Index);
	Subscribers.RemoveAt(Index);
}
