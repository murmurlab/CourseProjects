#if !defined(SERIALIZER_HPP)
# define SERIALIZER_HPP

# include "common.hpp"
# include "Data.hpp"

# if defined(__APPLE__)
#  include "ft_uintptr_t.hpp"
# elif __linux__
#  include "ft_uintptr_t.hpp"
# endif

class Serializer {
	private:
		Serializer(Serializer& cpy);
		virtual Serializer& operator=(Serializer& assgn) = 0;
		virtual ~Serializer() = 0;
		Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif  // SERIALIZER_HPP
