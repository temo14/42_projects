unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char c;
	int i = 0;

	while (i < 8)
	{
		c = (c << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}

	return (octet);
}
