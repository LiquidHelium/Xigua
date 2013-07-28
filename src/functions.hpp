#pragma once

#include "datatype.hpp"
#include "enviroment.hpp"

#include "functions/core.hpp"
#include "functions/math.hpp"
#include "functions/boolean.hpp"
#include "functions/string.hpp"
#include "functions/tuple.hpp"

namespace Xigua
{
	Enviroment get_global_enviroment()
	{
		Enviroment enviroment;

	// core

		enviroment.defined_variables["="] = DataType(DataTypes::Function);
		enviroment.defined_variables["="].set_function(&Functions::Core::define, 2, 0, false);

		enviroment.defined_variables["fn"] = DataType(DataTypes::Function);
		enviroment.defined_variables["fn"].set_function(&Functions::Core::create_lambda, 2, 0, false);

		enviroment.defined_variables["if"] = DataType(DataTypes::Function);
		enviroment.defined_variables["if"].set_function(&Functions::Core::if_expression, 3, 0, false);

		enviroment.defined_variables["println"] = DataType(DataTypes::Function);
		enviroment.defined_variables["println"].set_function(&Functions::Core::print_line, 1, 0, true);

		enviroment.defined_variables["get-input"] = DataType(DataTypes::Function);
		enviroment.defined_variables["get-input"].set_function(&Functions::Core::get_input, 0, 0, true);

	// math

		enviroment.defined_variables["+"] = DataType(DataTypes::Function);
		enviroment.defined_variables["+"].set_function(&Functions::Math::add, 2, 1, true);

		enviroment.defined_variables["-"] = DataType(DataTypes::Function);
		enviroment.defined_variables["-"].set_function(&Functions::Math::minus, 2, 1, true);

		enviroment.defined_variables["*"] = DataType(DataTypes::Function);
		enviroment.defined_variables["*"].set_function(&Functions::Math::multiply, 2, 1, true);
		
		enviroment.defined_variables["/"] = DataType(DataTypes::Function);
		enviroment.defined_variables["/"].set_function(&Functions::Math::divide, 2, 1, true);

		enviroment.defined_variables["<"] = DataType(DataTypes::Function);
		enviroment.defined_variables["<"].set_function(&Functions::Math::less_than, 2, 1, true);

		enviroment.defined_variables[">"] = DataType(DataTypes::Function);
		enviroment.defined_variables[">"].set_function(&Functions::Math::greater_than, 2, 1, true);
		
		enviroment.defined_variables["=="] = DataType(DataTypes::Function);
		enviroment.defined_variables["=="].set_function(&Functions::Math::equal_to, 2, 1, true);

	//string

		enviroment.defined_variables["string"] = DataType(DataTypes::Function);
		enviroment.defined_variables["string"].set_function(&Functions::String::to_string, 1, 0, true);

		enviroment.defined_variables["conc"] = DataType(DataTypes::Function);
		enviroment.defined_variables["conc"].set_function(&Functions::String::concatinate, 2, 1, true);

	//boolean

		enviroment.defined_variables["not"] = DataType(DataTypes::Function);
		enviroment.defined_variables["not"].set_function(&Functions::Boolean::boolean_not, 1, 0, true);

	//tuple

		enviroment.defined_variables["join"] = DataType(DataTypes::Function);
		enviroment.defined_variables["join"].set_function(&Functions::Tuple::join, 2, 1, true);



		return enviroment;
	}
}
