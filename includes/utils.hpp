/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:25:24 by sfournie          #+#    #+#             */
/*   Updated: 2022/08/02 09:50:21 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <regex>

using std::string;

namespace irc
{

int		error_log( const string& src,const string& msg, int error_code );
bool	validate_entry( string regex_format, string entry);

}

#endif
