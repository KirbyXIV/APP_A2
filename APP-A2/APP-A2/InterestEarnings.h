#pragma once
class InterestEarnings
{
	public:
		virtual ~InterestEarnings() = default;
		virtual float computeInterest(int years) = 0;
};

