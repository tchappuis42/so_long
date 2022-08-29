/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:47:14 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/28 13:49:09 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putcharlen(char c);
int		ft_putstrlen(char *s);
size_t	ft_strlen(const char *s);
int		ft_putnbrlen(int n);
int		ft_uputnbrlen(unsigned int n);
int		ft_puthexlen(unsigned int n);
int		ft_puthexlenu(unsigned int n);
int		ft_hexlen(unsigned int n);
int		ft_nbrlen(int n);
int		ft_nbrlenu(unsigned int n);
int		ft_puthexlenp(unsigned long n);
int		ft_hexlenp(unsigned long n);
#endif
