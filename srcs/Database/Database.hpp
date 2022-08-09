/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:53:04 by tshimoda          #+#    #+#             */
/*   Updated: 2022/08/08 14:04:35 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <list>
#include <map>
#include <iostream>

#include "Client.hpp"
#include "Channel.hpp"
#include "typedef.hpp"

using std::string;
using std::list;
using std::pair;

/*============================================================================*/ 
namespace irc {

class Database {

private:

	/*---------------PROHIBITED CONSTRUCTOR--------------*/
	Database( const Database& other );						// copy constructor
	Database& operator=( const Database& other );			// copy operator overload 
	
	/*--------------------ATTRIBUTES---------------------*/

	t_client_list			_client_list;
	t_channel_list			_channel_list;
	
	t_channel_clients_map	_channel_clients_list_map; // TO DO

public:
	/*-----------------------GETTERS----------------------*/
	
	// static Database&		get_Database(  ); // singleton
	Database( void );	// main constructor
	~Database( void );	// default destructor

	// [Client related getters]
	const t_client_list&	get_client_list( void );
	size_t					get_client_count( void );
	Client*					get_client( const int& fd );
	Client*					get_client( const string& nickname );
	t_client_ptr_list		get_clients_in_channel( const string& chan_name );
	t_client_ptr_list		get_clients_in_channel( Channel* channel );
	Channel*				get_channel( const string& chan_name );
	Channel*				get_channel( const Client* client );
	size_t					get_channel_count( void );
	t_channel_ptr_list		get_channel_list_of_client( Client* client );

	/*---------------OTHER-MEMBER-FUNCTIONS---------------*/
	
	void		init_Database( void );
	int			add_client_list( const Client& client );		// NEW renamed
	int			add_channel_list( const Channel& channel );		// NEW
															
	bool		is_client_listed( const Client& client );		// NEW
	bool		is_client_listed( const int& fd );				// NEW
	bool		is_client_listed( const string& nickname );		// NEW
	bool		is_channel_listed( const Channel& channel );	// NEW
	bool		is_channel_listed( const string& chan_name );	// NEW

	int			add_client_to_channel( Client* client, const string& chan_name );
	int			add_client_to_channel( Client* client, Channel* channel );
	void		remove_client_list( const int& fd );
	void		remove_client_list( const string& nickname );
	void		remove_client_list( Client* client );
	void		remove_channel_list( const string& chan_name );
	void		remove_client_from_channel( const string& nickname, const string& chan_name );
	void		remove_client_from_all_channels( const string& nickname );
	void		remove_all_clients_from_channel( const string& chan_name );


	
};



} // namespace irc end bracket

#endif
