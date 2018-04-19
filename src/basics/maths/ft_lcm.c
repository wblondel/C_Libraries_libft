/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lcm.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:44 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:44 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/basics/maths.h"

long long int	ft_lcm(long long int m, long long int n)
{
	if (m > n)
		return ((m / ft_gcd(m, n)) * n);
	else
		return ((n / ft_gcd(m, n)) * m);
}
