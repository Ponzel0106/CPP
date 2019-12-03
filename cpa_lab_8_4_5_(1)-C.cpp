#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum class State
{
	Start, S1, S2, S3, S4, Stop
};

class FSM
{
public:
	State getState() const noexcept
	{
		return state;
	}
	void printVisited() const
	{
			cout << "States visited:" << endl;
			for (int i = 0; i < 6; ++i)
				if (statesVisited[i])
					cout << (i == 0 ? "" : ", ") << i
						 << (i == 5 ? "(Stop)" : i == 0 ? "(Start)" : "");
	}
	
	friend FSM& operator<<(FSM&, int val);
private:
	void setState(State st)
	{
		state = st;
		statesVisited[(int)st] = true;
	}

	bool statesVisited[6] = { 1 };
	State state = State::Start;
};

FSM& operator<<(FSM& fsm, int val)
{
	if (fsm.state == State::Stop)
	{
		if (val == 0) // Restart
			fsm.setState(State::Start);
		return fsm;
	}
	if (val <= 0)
		fsm.setState(State::S1);
	else if (val < 10)
		fsm.setState(State::S2);
	else if (fsm.state == State::S3)
		fsm.setState(State::S4);
	else if (fsm.state == State::S4)
	{
		if (val >= 100)
			fsm.setState(State::Stop);
	}
	else
		fsm.setState(State::S3);
	return fsm;
}

int main(void)
{
	FSM fsm;
	int input;
	cout << "Enter input to the fsm. Enter invalid number to stop: " << endl;
	while (cin >> input)
	{
		fsm << input;
		if (fsm.getState() == State::Stop)
			cout << "Stop state reached" << endl;
	}
	fsm.printVisited();
	return 0;
}