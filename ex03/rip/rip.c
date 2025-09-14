/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:12:28 by tbaindur          #+#    #+#             */
/*   Updated: 2025/09/14 14:35:59 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	rip(char *str, int pos, int remL, int remR, int open)
{
	char	save;

	if (!str[pos])
	{
		if (remL == 0 && remR == 0 && open == 0)
			print_str(str);
		return ;
	}
	if (str[pos] == '(')
	{
		if (remL > 0)
		{
			save = str[pos];
			str[pos] = ' ';
			rip(str, pos + 1, remL - 1, remR, open);
			str[pos] = save;
		}
		rip(str, pos + 1, remL, remR, open + 1);
	}
	else if (str[pos] == ')')
	{
		if (remR > 0)
		{
			save = str[pos];
			str[pos] = ' ';
			rip(str, pos + 1, remL, remR - 1, open);
			str[pos] = save;
		}
		if (open > 0)
			rip(str, pos + 1, remL, remR, open - 1);
	}
	else
		rip(str, pos + 1, remL, remR, open);
}

int	main(int ac, char *av[])
{
	char	*s;
	int		i;
	int		remL;
	int		remR;

	if (ac != 2)
		return (1);
	i = 0;
	s = av[1];
	remL = 0;
	remR = 0;
	while (s[i])
	{
		if (s[i] == '(')
			remL++;
		else if (s[i] == ')')
		{
			if (remL > 0)
				remL--;
			else
				remR++;
		}
		i++;
	}
	rip(s, 0, remL, remR, 0);
}


#include <unistd.h>

void print_string(char *s) {
    int i = 0;
    while (s[i]) {
        write(1, &s[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

void solve(char *str, int pos, int left_rem, int right_rem, int balance) {
    // Base case: reached end of string
    if (str[pos] == '\0') {
        if (left_rem == 0 && right_rem == 0 && balance == 0)
            print_string(str);
        return;
    }
    
    char current = str[pos];
    
    if (current == '(') {
        // Option 1: Remove this '('
        if (left_rem > 0) {
            str[pos] = ' ';
            solve(str, pos + 1, left_rem - 1, right_rem, balance);
            str[pos] = '(';  // backtrack
        }
        // Option 2: Keep this '('
        solve(str, pos + 1, left_rem, right_rem, balance + 1);
    }
    else if (current == ')') {
        // Option 1: Remove this ')'
        if (right_rem > 0) {
            str[pos] = ' ';
            solve(str, pos + 1, left_rem, right_rem - 1, balance);
            str[pos] = ')';  // backtrack
        }
        // Option 2: Keep this ')' (only if we have unmatched '(')
        if (balance > 0)
            solve(str, pos + 1, left_rem, right_rem, balance - 1);
    }
    else {
        // Regular character - just move forward
        solve(str, pos + 1, left_rem, right_rem, balance);
    }
}

int main(int ac, char **av) {
    if (ac != 2) return 1;
    
    char *s = av[1];
    int left_to_remove = 0;
    int right_to_remove = 0;
    int i = 0;
    
    // Count how many '(' and ')' need to be removed
    while (s[i]) {
        if (s[i] == '(') {
            left_to_remove++;
        }
        else if (s[i] == ')') {
            if (left_to_remove > 0)
                left_to_remove--;  // matched with previous '('
            else
                right_to_remove++; // extra ')'
        }
        i++;
    }
    
    solve(s, 0, left_to_remove, right_to_remove, 0);
    return 0;
}