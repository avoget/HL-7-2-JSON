#include "spirit.hpp"
#include "hl7msg.hpp"
#include "conv.hpp"

BOOST_FUSION_ADAPT_STRUCT(
	ADTmsg,
	(std::vector<string>, msh)
	(std::vector<string>, evn)
	(std::vector<string>, pid)
	(std::vector<string>, pd1)
	(std::vector<string>, pv1)
)

namespace HL7{
	namespace qi = boost::spirit::qi;
	namespace ascii = boost::spirit::ascii;

	template <typename Iterator>
	struct ADT_parser : qi::grammar<Iterator, ADTmsg()> {
		ADT_parser() : ADT_parser::base_type(adt){
			using qi::lit;
			using ascii::char_;
			using boost::spirit::ascii::cntrl;
			using boost::spirit::qi::eol;
			t_string %= *(char_ - '|' - cntrl);
			field = lit("|") >> t_string;
			msh = lit("MSH") >> *field >> *eol;
			evn = lit("EVN") >> *field >> *eol;
			pid = lit("PID") >> *field >> *eol;
			pd1 = lit("PD1") >> *field >> *eol;
			pv1 = lit("PV1") >> *field >> *eol;

			adt %= msh >> evn >> pid >> -pd1 >> -pv1;
		}

		qi::rule<Iterator, std::string() > t_string;
		qi::rule<Iterator, std::string() > field;
		qi::rule<Iterator, std::vector<string>() > msh;
		qi::rule<Iterator, std::vector<string>() > evn;
		qi::rule<Iterator, std::vector<string>() > pid;
		qi::rule<Iterator, std::vector<string>() > pd1;
		qi::rule<Iterator, std::vector<string>() > pv1;
		qi::rule<Iterator, ADTmsg() > adt;
	};

	void Converter::Input(std::string const & in) throw() {
		input = in;
	}
	ADTmsg Converter::Convert() throw(const char*) {
		string::const_iterator begin = input.begin();
		string::const_iterator end = input.end();
		ADTmsg res;
		typedef string::const_iterator iterator_type;
		typedef ADT_parser<iterator_type> ADT_parser;
		ADT_parser parser;

		bool r = parse(begin, end, parser, res);
		if (!r) {
			throw "Parse error";
		}
		return res;
	}
	
}		//namespace HL7


//