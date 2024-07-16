/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:56:02 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/16 16:20:28 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Gets the length of a string.
	- #### Parameters
	-	char *str: The string to measure.
	- #### Return
	-	Returns the length of the string up to the first NULL (\0) terminator.
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
	Prints a string.
	- #### Parameters
	-	char *str: The string to print
*/
void	ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

/*
	Compares two strings.
	- #### Parameters
	-	char *s1: The first string
	-	char *s2: The other string
	- #### Return
	-	Returns 0 if both strings are equal, a positive value if the first
		string is bigger than the second and a negative value if the second
		string is bigger than the first.
*/
int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

/*
	Sorts all the strings in a matrix using the bubble sort method.
*/
char	**ft_sort_str_matrix_rev(char **matrix, int size)
{
	char	*xstr;
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(matrix[i], matrix[i + 1]) > 0)
		{
			xstr = matrix[i];
			matrix[i] = matrix[i + 1];
			matrix[i + 1] = xstr;
			i = 0;
		}
		else
			i++;
	}
	return (matrix);
}

/*
	Prints the parameters used sorted in alphabetical order.
*/
int	main(int argc, char *argv[])
{
	const char	newline = '\n';
	char		**args;
	int			i;

	i = 1;
	while (i <= argc - 1)
	{
		args[i - 1] = argv[i];
		i++;
	}
	i = 0;
	ft_sort_str_matrix_rev(args, argc - 1);
	while (i <= argc - 2)
	{
		ft_putstr(args[i]);
		write(STDOUT_FILENO, &newline, 1);
		i++;
	}
}
