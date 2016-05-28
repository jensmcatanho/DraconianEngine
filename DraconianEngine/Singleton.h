#pragma once

namespace Draconian {

template <typename T>
class Singleton {
	public:
		Singleton() {
			m_Instance = static_cast<T *>(this);
		}

		~Singleton() {
			m_Instance = 0;
		}

		static T &getSingleton() {
			return *m_Instance;
		}

		static T *getSingletonPtr() {
			return m_Instance;
		}

	protected:
		static const T *m_Instance;
};

}