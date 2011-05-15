#include "parser.hpp"
#include "spirit.hpp"

namespace Parser{
	namespace qi = boost::spirit::qi;
	namespace ascii = boost::spirit::ascii;

	template <typename Iterator>
	struct SepStringParser : qi::grammar<Iterator, std::vector<std::string>()> {
		SepStringParser(char sep) : SepStringParser::base_type(result){
			using qi::lit;
			using ascii::char_;
			using boost::spirit::ascii::cntrl;
			using boost::spirit::qi::eol;
			t_string %= *(char_ - char_(sep) - cntrl);
			field = lit(std::string(&sep, 1)) >> t_string;
			result = *field >> *eol;
		}

		qi::rule<Iterator, std::string() > t_string;
		qi::rule<Iterator, std::string() > field;
		qi::rule<Iterator, std::vector<std::string>() > result;
	};


	void Parser::clear(){
		_values.clear();
	}
	Parser::StringVector & Parser::parseString(std::string const & str, char sep){
		clear();
		std::string::const_iterator begin = str.begin();
		std::string::const_iterator end = str.end();
		typedef std::string::const_iterator iterator_type;
		typedef SepStringParser<iterator_type> SepStringParser;
		SepStringParser parser(sep);
		bool r = parse(begin, end, parser, _values);
		if (!r) {
			throw "Parse error";
		}
		return _values;
	}
}		//Parser





