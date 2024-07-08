/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:41:49 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/09 00:34:24 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Turns any uppercase character from a string into an lowercase character.
	- #### Parameters
	-	char *str: The string to transform
	- #### Return
	- The string passed.
*/
char	*ft_strlowcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

/*
	Turns a lowercase character from a string to uppercase.
	- #### Parameters
	-	char *c[]: The character to modify
	- #### Return
	-	The new character.
*/
char	*ft_toupper(char *c)
{
	*c -= 32;
	return (c);
}

/* 
	Turns every first letter of each word, considering a word is sequence of
	alfanumeric characters,	of a string and turns it into an uppercase letter,
	every other letter of that same word is turned into a lowercase letter.
	- #### Special cases
	-	In case a word starts by a number, all numbers are kept intact except
		from the letters, which are all turned to lowercase.
		i.e. 42mOTs -> 42mots
	- #### Parameters
	-	char *str: The string to modify
	- #### Return
	-	The modified string.
*/
char	*ft_strcapitalize(char *str)
{
	unsigned int	i;
	unsigned int	new_word;

	i = 0;
	new_word = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < '0' || str[i] > '9'))
			new_word = 1;
		else if (str[i] > '0' && str[i] < '9')
			new_word = 0;
		else if ((str[i] >= 'a' && str[i] <= 'z') && new_word == 1)
		{
			ft_toupper(&str[i]);
			new_word = 0;
		}
		i++;
	}
	return (str);
}
