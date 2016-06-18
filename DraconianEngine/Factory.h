#pragma once

namespace Draconian {

template <typename T>
class Factory {
	public:
		virtual ~Factory() { }

		virtual const String &getType() const = 0;
		virtual T *createInstance(const String &name) = 0;
		virtual void destroyInstance(T *ptr) = 0;
};

}