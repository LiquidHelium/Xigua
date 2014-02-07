#pragma once

#include <set>
#include <functional>
#include <memory>

#include "xigua/error.hpp"

namespace xig {

	class data;
	class enviroment;

	class method {
	public:
		virtual data run(std::vector<data>, enviroment &, std::vector<std::string>) = 0;

		virtual int amount_of_arguments() const = 0;
		virtual bool has_repeating_arguments() const;
		virtual bool should_evaluate_arguments() const;

		data call(std::vector<data> arguments, enviroment & enviroment, std::vector<std::string> function_call_list);
	};

	struct method_set_comparator {
		bool operator() (const std::shared_ptr<method> & a, const std::shared_ptr<method> & b);
	};

	class function {
		public:
			function(){};

			template <class T>
			function(T in_method) {
				add_method(in_method);
			}

			template <class T>
			void add_method(T in_method) {
				methods.insert(std::shared_ptr<T>(new T(in_method)));
			}

			data call(std::vector<data> & args, enviroment & enviroment, std::vector<std::string> function_call_list);

		private:
			std::set<std::shared_ptr<method>, method_set_comparator> methods;
	};

}
