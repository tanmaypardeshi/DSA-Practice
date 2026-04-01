#include<iostream>
#include<unordered_map>

using namespace std;

class Logger {
	private:
		unordered_map<string, int> mp;
	public:
		Logger() {};
	    bool shouldPrintMessage(int, const string&);
};

bool Logger::shouldPrintMessage(int timestamp, const string& message) {
	if(mp.find(message) != mp.end()) {
		if(timestamp - mp[message] >= 10) {
			mp[message] = timestamp;
			return true;
		}
		return false;
	} else {
		mp[message] = timestamp;
		return true;
	}
}

int main() {
	Logger logger;

	std::cout << logger.shouldPrintMessage(1, "foo") << std::endl; 
	std::cout << logger.shouldPrintMessage(2, "bar") << std::endl; 
	std::cout << logger.shouldPrintMessage(3, "foo") << std::endl; 
	std::cout << logger.shouldPrintMessage(11, "foo") << std::endl;

}
