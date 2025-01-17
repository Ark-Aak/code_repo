using u32 = unsigned;
struct IO_Tp
{
	const static int _I_Buffer_Size = 30 << 20;
	char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;
	
	const static int _O_Buffer_Size = 8 << 20;
	char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;
	
	u32 m[10000];
	
	IO_Tp()
	{
//		freopen("ambiguous.in", "r", stdin);
//		freopen("ambiguous.out", "w", stdout);
		constexpr u32 e0 = '\0\0\0\1', e1 = '\0\0\1\0', e2 = '\0\1\0\0', e3 = '\1\0\0\0';
		int x = 0;
		for (u32 i = 0, c0 = '0000'; i != 10; ++i, c0 += e0)
			for (u32 j = 0, c1 = c0; j != 10; ++j, c1 += e1)
				for (u32 k = 0, c2 = c1; k != 10; ++k, c2 += e2)
					for (u32 l = 0, c3 = c2; l != 10; ++l, c3 += e3)
						m[x++] = c3;
		
		fread(_I_Buffer, 1, _I_Buffer_Size, stdin);
	}
	~IO_Tp() { fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }
	
	IO_Tp &operator>>(int &res)
	{
		while (!isdigit(*_I_pos))
			++_I_pos;
		res = *_I_pos++ - '0';
		while (isdigit(*_I_pos))
			res = res * 10 + (*_I_pos++ - '0');
		return *this;
	}
	
	IO_Tp &operator<<(int x)
	{
		if (x == 0)
		{
			*_O_pos++ = '0';
			return *this; 
		}
		static char _buf[35];
		char *_pos = _buf + 35;
		while (x >= 10000)
			*--reinterpret_cast<u32 *&>(_pos) = m[x % 10000], x /= 10000;
		*--reinterpret_cast<u32 *&>(_pos) = m[x];
		_pos += (x < 1000) + (x < 100) + (x < 10);
		_O_pos = std::copy(_pos, _buf + 35, _O_pos);
		return *this;
	}
	
	IO_Tp &operator<<(char ch)
	{
		*_O_pos++ = ch;
		return *this;
	}
} IO;
