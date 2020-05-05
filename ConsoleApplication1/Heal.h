#pragma once

using namespace std;


class Heal//здоровье способность
{
private:
	int treatment;
	int counter;
public:
	Heal()
	{
		treatment = 20;
		counter = 0;
	}
	void SetCounter()
	{
		counter = 4;
	}
	void Countdown()
	{
		counter--;
		if (counter < 0)
		{
			counter = 0;
		}
	}
	int GetCounter()
	{
		return counter;
	}
	int GetHeal()
	{
		return treatment;//возврат значения здоровья в main
	}
};