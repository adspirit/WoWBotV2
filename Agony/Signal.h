#ifndef SIGNAL_HPP
#define SIGNAL_HPP
#include <functional>
#include <map>
#include <exception>
#include <stdexcept>
#include <mutex>
#include "Macros.h"

namespace Agony
{
	namespace Native
	{
		// A signal object may call multiple slots with the same signature.
		// You can connect functions to the signal which will be called when the emit() method on the signal object is invoked.
		// Any argument passed to emit() will be passed to the given functions.
		template <typename... Args>
		class DLLEXPORT Signal
		{
		public:
			Signal() : current_id_(0) {}

			// copy creates new signal
			Signal(Signal const& other) : current_id_(0) {}

			// connects a member function to this Signal
			template <typename T>
			int connect_member(T* inst, void (T::* func)(Args...)) {
				return connect([=](Args... args) {
					(inst->*func)(args...);
				});
			}

			// connects a const member function to this Signal
			template <typename T>
			int connect_member(T* inst, void (T::* func)(Args...) const) {
				return connect([=](Args... args) {
					(inst->*func)(args...);
				});
			}

			// connects a std::function to the signal. The returned
			// value can be used to disconnect the function again
			int connect(std::function<void(Args...)> const& slot) const {
				slots_.insert(std::make_pair(++current_id_, slot));
				return current_id_;
			}

			// disconnects a previously connected function
			void disconnect(int id) const {
				slots_.erase(id);
			}

			// disconnects all previously connected functions
			void disconnect_all() const {
				slots_.clear();
			}

			// calls all connected functions
			void emit(Args... p)
			{
				try
				{
					for (auto it : slots_)
					{
						try
						{
							it.second(p...);
						}
						catch (const std::exception& e)
						{
							std::cout << "Exception occured while emitting signal." << std::endl;
							std::cout << e.what() << std::endl;
						}
					}
				}
				catch (const std::exception& e)
				{
					std::cout << "Exception occured while emitting signal." << std::endl;
					std::cout << e.what() << std::endl;
				}
			}

			// assignment creates new Signal
			Signal& operator=(Signal const& other) {
				disconnect_all();
				return *this;
			}

		private:
			mutable std::map<int, std::function<void(Args...)>> slots_;
			mutable int current_id_;
		};
	}
}

#endif /* SIGNAL_HPP */