#include "CommandManager.hpp"
#include "typedef.hpp"
#include "Message.hpp"

using namespace irc;
using std::cout;
using std::cerr;
using std::endl;

/*---------------------------------------COMMANDS-UTILS-------------------------------------------*/

void CommandManager::send_to_clients( t_client_ptr_list list_of_client, string output)
{
    t_client_ptr_list::iterator it;

    for (it = list_of_client.begin(); it != list_of_client.end(); it++)
        (*it)->append_buff(BUFFOUT, output);
} 

void CommandManager::send_to_channels(t_channel_ptr_list list_of_chan, string output)
{
    t_channel_ptr_list::iterator it;

    for (it = list_of_chan.begin(); it != list_of_chan.end(); it++)
        send_to_clients(_database->get_clients_in_channel((*it)), output);
    
}
