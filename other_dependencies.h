#pragma once

class OtherDependencies {
public:
	double ValueAt(int I) const { return 0.0; /* Could do anything*/ }
	void Prep(const char*) {}
	int ImportantSetting() const { return 3; }
};