#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "data.hpp"
#include "error.hpp"


namespace xig {

	class parser {
	public:
		static data from_file(const std::string file_location);
		static data from_string(const std::string source_code);

	private:
		static std::string read_file(const std::string file_location);

		static std::vector<std::string> source_to_string_list(const std::string source_code);
		static void validate_string_list(const std::vector<std::string> string_list);

		static data string_list_to_data_type(const std::vector<std::string> string_list, const data_type list_type = data_type::process);
		static data string_to_data_type(const std::string input_string);
		static bool is_number(std::string string);
	};

}
