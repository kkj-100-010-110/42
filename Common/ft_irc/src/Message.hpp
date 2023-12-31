#ifndef MESSAGE_HPP
#define MESSAGE_HPP

// ping/pong/whois/list
/* [WELCOME 001 - 003]*/ // client == ":servername cmd-num username"
// 001
#define RPL_WELCOME(client, networkname, nick, user, host) \
    ":" + client + " :Welcome to the " + networkname + " Network,  " + nick + "[!" + user + "@" + host + "]"
// 002
#define RPL_YOURHOST(client, networkname, version) \
    ":" + client + " :Your host is " + networkname + ", running version  " + version
// 003
#define RPL_CREATED(client, datetime) \
    ":" + client + " :This server was created " + datetime

// RPL_MYINFO (004)
//   "<client> <servername> <version> <available user modes>
//   <available channel modes> [<channel modes with a parameter>]"
// Part of the post-registration greeting. Clients SHOULD discover available features using RPL_ISUPPORT tokens rather than the mode letters listed in this reply.

// RPL_ISUPPORT (005)
//   "<client> <1-13 tokens> :are supported by this server"
// The ABNF representation for an RPL_ISUPPORT token is:

//   token      =  *1"-" parameter / parameter *1( "=" value )
//   parameter  =  1*20 letter
//   value      =  * letpun
//   letter     =  ALPHA / DIGIT
//   punct      =  %d33-47 / %d58-64 / %d91-96 / %d123-126
//   letpun     =  letter / punct
// As the maximum number of message parameters to any reply is 15, the maximum number of RPL_ISUPPORT tokens that can be advertised is 13. To counter this, a server MAY issue multiple RPL_ISUPPORT numerics. A server MUST issue at least one RPL_ISUPPORT numeric after client registration has completed. It MUST be issued before further commands from the client are processed.

// When clients send a VERSION command to an external server (i.e. not the one they’re currently connected to), they receive the appropriate information from that server. That external server’s ISUPPORT tokens are sent to the client using the 105 (RPL_REMOTEISUPPORT) numeric instead of 005, to ensure that clients don’t process and start using these tokens sent by an external server. The format of the 105 message is exactly the same as RPL_ISUPPORT – the numeric itself is the only difference.

// A token is of the form PARAMETER, PARAMETER=VALUE or -PARAMETER. Servers MUST send the parameter as upper-case text.

// Tokens of the form PARAMETER or PARAMETER=VALUE are used to advertise features or information to clients. A parameter MAY have a default value and value MAY be empty when sent by servers. Unless otherwise stated, when a parameter contains a value, the value MUST be treated as being case sensitive. The value MAY contain multiple fields, if this is the case the fields SHOULD be delimited with a comma character (",", 0x2C). The value MAY contain escape sequences: \x20 for the space character (" ", 0x20), \x5C for the backslash character ("\", 0x5C) and \x3D for the equal character ("=", 0x3D).

// If the value of a parameter changes, the server SHOULD re-advertise the parameter with the new value in an RPL_ISUPPORT reply. An example of this is a client becoming an IRC operator and their CHANLIMIT changing.

// Tokens of the form -PARAMETER are used to negate a previously specified parameter. If the client receives a token like this, the client MUST consider that parameter to be removed and revert to the behaviour that would occur if the parameter was not specified. The client MUST act as though the paramater is no longer advertised to it. These tokens are intended to allow servers to change their features without disconnecting clients. Tokens of this form MUST NOT contain a value field.

// The server MAY negate parameters which have not been previously advertised; in this case, the client MUST ignore the token.

// A single RPL_ISUPPORT reply MUST NOT contain the same parameter multiple times nor advertise and negate the same parameter. However, the server is free to advertise or negate the same parameter in separate replies.

// See the Feature Advertisement section for more details on this numeric. A list of parameters is available in the RPL_ISUPPORT Parameters section.

// RPL_BOUNCE (010)
//   "<client> <hostname> <port> :<info>"
// Sent to the client to redirect it to another server. The <info> text varies between server software and reasons for the redirection.

// Because this numeric does not specify whether to enable SSL and is not interpreted correctly by all clients, it is recommended that this not be used.

// This numeric is also known as RPL_REDIR by some software.

// RPL_STATSCOMMANDS (212)
//   "<client> <command> <count> [<byte count> <remote count>]"
// Sent as a reply to the STATS command, when a client requests statistics on command usage.

// <byte count> and <remote count> are optional and MAY be included in responses.

// RPL_ENDOFSTATS (219)
//   "<client> <stats letter> :End of /STATS report"
// Indicates the end of a STATS response.

// RPL_STATSUPTIME (242)
//   "<client> :Server Up <days> days <hours>:<minutes>:<seconds>"
// Sent as a reply to the STATS command, when a client requests the server uptime. The text used in the last param of this message may vary.

// RPL_UMODEIS (221)
//   "<client> <user modes>"
// Sent to a client to inform that client of their currently-set user modes.

// RPL_LUSERCLIENT (251)
//   "<client> :There are <u> users and <i> invisible on <s> servers"
// Sent as a reply to the LUSERS command. <u>, <i>, and <s> are non-negative integers, and represent the number of total users, invisible users, and other servers connected to this server.

// RPL_LUSEROP (252)
//   "<client> <ops> :operator(s) online"
// Sent as a reply to the LUSERS command. <ops> is a positive integer and represents the number of IRC operators connected to this server. The text used in the last param of this message may vary.

// RPL_LUSERUNKNOWN (253)
//   "<client> <connections> :unknown connection(s)"
// Sent as a reply to the LUSERS command. <connections> is a positive integer and represents the number of connections to this server that are currently in an unknown state. The text used in the last param of this message may vary.

// RPL_LUSERCHANNELS (254)
//   "<client> <channels> :channels formed"
// Sent as a reply to the LUSERS command. <channels> is a positive integer and represents the number of channels that currently exist on this server. The text used in the last param of this message may vary.

// RPL_LUSERME (255)
//   "<client> :I have <c> clients and <s> servers"
// Sent as a reply to the LUSERS command. <c> and <s> are non-negative integers and represent the number of clients and other servers connected to this server, respectively.

// RPL_ADMINME (256)
#define RPL_ADMINME(client, server) \
    ":" + client + " " + server + " :Administrative info"
// Sent as a reply to an ADMIN command, this numeric establishes the name of the server whose administrative info is being provided. The text used in the last param of this message may vary.

// <server> is optional and MAY be included in responses, the server can also be gained from the <source> of this message.

// RPL_ADMINLOC1 (257)
#define RPL_ADMINLOC1(client, info) \
    ":" + client + " : " + info
// Sent as a reply to an ADMIN command, <info> is a string intended to provide information about the location of the server (i.e. city, state and country). The text used in the last param of this message varies wildly.

// RPL_ADMINLOC2 (258)
#define RPL_ADMINLOC2(client, info) \
    ":" + client + " : " + info
// Sent as a reply to an ADMIN command, <info> is a string intended to provide information about whoever runs the server (i.e. details of the institution hosting it). The text used in the last param of this message varies wildly.

// RPL_ADMINEMAIL (259)
#define RPL_ADMINEMAIL(client, info) \
    ":" + client + " : " + info
// Sent as a reply to an ADMIN command, <info> MUST contain the email address to contact the administrator(s) of the server. The text used in the last param of this message varies wildly.

// RPL_TRYAGAIN (263)
//   "<client> <command> :Please wait a while and try again."
// When a server drops a command without processing it, this numeric MUST be sent to inform the client. The text used in the last param of this message varies wildly, and commonly provides the client with more information about why the command could not be processed (i.e., due to rate-limiting).

// RPL_LOCALUSERS (265)
//   "<client> [<u> <m>] :Current local users <u>, max <m>"
// Sent as a reply to the LUSERS command. <u> and <m> are non-negative integers and represent the number of clients currently and the maximum number of clients that have been connected directly to this server at one time, respectively.

// The two optional parameters SHOULD be supplied to allow clients to better extract these numbers.

// RPL_GLOBALUSERS (266)
//   "<client> [<u> <m>] :Current global users <u>, max <m>"
// Sent as a reply to the LUSERS command. <u> and <m> are non-negative integers. <u> represents the number of clients currently connected to this server, globally (directly and through other server links). <m> represents the maximum number of clients that have been connected to this server at one time, globally.

// The two optional parameters SHOULD be supplied to allow clients to better extract these numbers.

// 276
#define RPL_WHOISCERTFP(client, nick, fingerprint) \
    ":" + client + " " + nick + " :has client certificate fingerprint " + fingerprint
// Sent as a reply to the WHOIS command, this numeric shows the SSL/TLS certificate fingerprint used by the client with the nickname <nick>. Clients MUST only be sent this numeric if they are either using the WHOIS command on themselves or they are an operator.

// RPL_NONE(300)
//   Undefined format
// RPL_NONE is a dummy numeric. It does not have a defined use nor format.

// 301
#define RPL_AWAY(client, nick, message) \
    ":" + client + " " + nick + " :" + message
// Indicates that the user with the nickname <nick> is currently away and sends the away message that they set.

// 302
#define RPL_USERHOST(client, reply) \
    ":" + client + " :[" + reply + "{ " + reply + "}]"
//  "<client> :[<reply>{ <reply>}]"
// Sent as a reply to the USERHOST command, this numeric lists nicknames and the information associated with them. The last parameter of this numeric (if there are any results) is a list of <reply> values, delimited by a SPACE character (' ', 0x20).

// The ABNF representation for <reply> is:

//   reply   =  nickname [ isop ] "=" isaway hostname
//   isop    =  "*"
//   isaway  =  ( "+" / "-" )
// <isop> is included if the user with the nickname of <nickname> has registered as an operator. <isaway> represents whether that user has set an [away] message. "+" represents that the user is not away, and "-" represents that the user is away.

// 305
#define RPL_UNAWAY(client) \
    ":" + client + " :You are no longer marked as being away"
//   "<client> :You are no longer marked as being away"
// Sent as a reply to the AWAY command, this lets the client know that they are no longer set as being away. The text used in the last param of this message may vary.

// 306
#define RPL_NOWAWAY(client) \
    ":" + client + " :You have been marked as being away"
//   "<client> :You have been marked as being away"
// Sent as a reply to the AWAY command, this lets the client know that they are set as being away. The text used in the last param of this message may vary.

// 352
#define RPL_WHOREPLY(client, channel, username, host, server, nick, flags, hopcount, realname) \
    ":" + client + " " + channel + " " + username + " " + host + " " + server + " " + nick + " " + flags + " : " + hopcount + " " + realname
//   "<client> <channel> <username> <host> <server> <nick> <flags> :<hopcount> <realname>"
// Sent as a reply to the WHO command, this numeric gives information about the client with the nickname <nick>. Refer to RPL_WHOISUSER (311) for the meaning of the fields <username>, <host> and <realname>. <server> is the name of the server the client is connected to. If the WHO command was given a channel as the <mask> parameter, then the same channel MUST be returned in <channel>. Otherwise <channel> is an arbitrary channel the client is joined to or a literal asterisk character ('*', 0x2A) if no channel is returned. <hopcount> is the number of intermediate servers between the client issuing the WHO command and the client <nick>, it might be unreliable so clients SHOULD ignore it.

// <flags> contains the following characters, in this order:

// Away status: the letter H ('H', 0x48) to indicate that the user is here, or the letter G ('G', 0x47) to indicate that the user is gone.
// Optionally, a literal asterisk character ('*', 0x2A) to indicate that the user is a server operator.
// Optionally, the highest channel membership prefix that the client has in <channel>, if the client has one.
// Optionally, one or more user mode characters and other arbitrary server-specific flags.

// 315
#define RPL_ENDOFWHO(client, mask) \
    ":" + client + " " + mask + " :End of WHO list"

//   "<client> <mask> :End of WHO list"
// Sent as a reply to the WHO command, this numeric indicates the end of a WHO response for the mask <mask>.

// <mask> MUST be the same <mask> parameter sent by the client in its WHO message, but MAY be casefolded.

// This numeric is sent after all other WHO response numerics have been sent to the client.

// 307
#define RPL_WHOISREGNICK(client, nick) \
    ":" + client + " " + nick + " :has identified for this nick"
//   "<client> <nick> :has identified for this nick"
// Sent as a reply to the WHOIS command, this numeric indicates that the client with the nickname <nick> was authenticated as the owner of this nick on the network.

// See also RPL_WHOISACCOUNT, for information on the account name of the user.

// 311
#define RPL_WHOISUSER(client, nick, username, host, realname) \
    ":" + client + " " + nick + " " + username + " " + host " * :" + realname
//   "<client> <nick> <username> <host> * :<realname>"
// Sent as a reply to the WHOIS command, this numeric shows details about the client with the nickname <nick>. <username> and <realname> represent the names set by the USER command (though <username> may be set by the server in other ways). <host> represents the host used for the client in nickmasks (which may or may not be a real hostname or IP address). <host> CANNOT start with a colon (':', 0x3A) as this would get parsed as a trailing parameter – IPv6 addresses such as "::1" are prefixed with a zero ('0', 0x30) to ensure this. The second-last parameter is a literal asterisk character ('*', 0x2A) and does not mean anything.

// 312
#define RPL_WHOISSERVER(client, nick, server, server_info) \
    ":" + client + " " + nick + " " + server + " :" + server_info
//   "<client> <nick> <server> :<server info>"
// Sent as a reply to the WHOIS (or WHOWAS) command, this numeric shows which server the client with the nickname <nick> is (or was) connected to. <server> is the name of the server (as used in message prefixes). <server info> is a string containing a description of that server.

// 313
#define RPL_WHOISOPERATOR(client, nick) \
    ":" + client + " " + nick + " : is an IRC operator"
//   "<client> <nick> :is an IRC operator"
// Sent as a reply to the WHOIS command, this numeric indicates that the client with the nickname <nick> is an operator. This command MAY also indicate what type or level of operator the client is by changing the text in the last parameter of this numeric. The text used in the last param of this message varies wildly, and SHOULD be displayed as-is by IRC clients to their users.

// 314
#define RPL_WHOWASUSER(client, nick, username, host, realname) \
    ":" + client + " " + nick + " " + username + " " + host + "* :" + realname
//   "<client> <nick> <username> <host> * :<realname>"
// Sent as a reply to the WHOWAS command, this numeric shows details about one of the last clients that used the nickname <nick>. The purpose of each argument is the same as with the RPL_WHOISUSER (311) numeric.

// 317
#define RPL_WHOISIDLE(client, nick, secs, signon) \
    ":" + client + " " + nick + " " + secs + " " + signon + " :seconds idle, signon time"
//   "<client> <nick> <secs> <signon> :seconds idle, signon time"
// Sent as a reply to the WHOIS command, this numeric indicates how long the client with the nickname <nick> has been idle. <secs> is the number of seconds since the client has been active. Servers generally denote specific commands (for instance, perhaps JOIN, PRIVMSG, NOTICE, etc) as updating the ‘idle time’, and calculate this off when the idle time was last updated. <signon> is a unix timestamp representing when the user joined the network. The text used in the last param of this message may vary.

// 318
#define RPL_ENDOFWHOIS(client, nick) \
    ":" + client + " " + nick + " :End of /WHOIS list"
//   "<client> <nick> :End of /WHOIS list"
// Sent as a reply to the WHOIS command, this numeric indicates the end of a WHOIS response for the client with the nickname <nick>.

// <nick> MUST be exactly the <nick> parameter sent by the client in its WHOIS message. This means the case MUST be preserved, and if the client sent multiple nicks, this MUST be the comma-separated list of nicks, even if some of them were dropped.

// This numeric is sent after all other WHOIS response numerics have been sent to the client.

// 319
#define RPL_WHOISCHANNELS(client, nick, prefix, channel) \
    ":" + client + " " + nick + " :" + "[" + prefix + "]" + channel + "{ " + "[" + prefix + "]" + channel + "}"
//   "<client> <nick> :[prefix]<channel>{ [prefix]<channel>}
// Sent as a reply to the WHOIS command, this numeric lists the channels that the client with the nickname <nick> is joined to and their status in these channels. <prefix> is the highest channel membership prefix that the client has in that channel, if the client has one. <channel> is the name of a channel that the client is joined to. The last parameter of this numeric is a list of [prefix]<channel> pairs, delimited by a SPACE character (' ', 0x20).

// RPL_WHOISCHANNELS can be sent multiple times in the same whois reply, if the target is on too many channels to fit in a single message.

// The channels in this response are affected by the secret channel mode and the invisible user mode, and may be affected by other modes depending on server software and configuration.

// 320
#define RPL_WHOISSPECIAL(client, nick) \
    ":" + client + " " + nick + " :blah blah blah"
//   "<client> <nick> :blah blah blah"
// Sent as a reply to the WHOIS command, this numeric is used for extra human-readable information on the client with nickname <nick>. This should only be used for non-essential information that does not need to be machine-readable or understood by client software.

// 321
#define RPL_LISTSTART(client) \
    ":" + client + " Channel : Topic"
    // ":" + client + " Channel :Users Name"
//   "<client> Channel :Users  Name"
// Sent as a reply to the LIST command, this numeric marks the start of a channel list. As noted in the command description, this numeric MAY be skipped by the server so clients MUST NOT depend on receiving it.

// 322
#define RPL_LIST(client, channel, client_count, topic) \
    ":" + client + " " + channel + " " + client_count + " " + topic
//   "<client> <channel> <client count> :<topic>"
// Sent as a reply to the LIST command, this numeric sends information about a channel to the client. <channel> is the name of the channel. <client count> is an integer indicating how many clients are joined to that channel. <topic> is the channel’s topic (as set by the TOPIC command).

// 323
#define RPL_LISTEND(client) \
    ":" + client + " :End of /LIST"
//   "<client> :End of /LIST"
// Sent as a reply to the LIST command, this numeric indicates the end of a LIST response.

// 324
#define RPL_CHANNELMODEIS(client, channel, modestring) \
	":" + client + " " + channel + " " + modestring
//   "<client> <channel> <modestring> <mode arguments>..."
// Sent to a client to inform them of the currently-set modes of a channel. <channel> is the name of the channel. <modestring> and <mode arguments> are a mode string and the mode arguments (delimited as separate parameters) as defined in the MODE message description.

// RPL_CREATIONTIME (329)
//   "<client> <channel> <creationtime>"
// Sent to a client to inform them of the creation time of a channel. <channel> is the name of the channel. <creationtime> is a unix timestamp representing when the channel was created on the network.

// 330
#define RPL_WHOISACCOUNT(client, nick, account) \
    ":" + client + " " + nick + " " + account + " :is logged in as"
//   "<client> <nick> <account> :is logged in as"
// Sent as a reply to the WHOIS command, this numeric indicates that the client with the nickname <nick> was authenticated as the owner of <account>.

// This does not necessarily mean the user owns their current nickname, which is covered byRPL_WHOISREGNICK.

// 331
#define RPL_NOTOPIC(client, channel) \
    ":" + client + " " + channel + " :No topic is set"
//   "<client> <channel> :No topic is set"
// Sent to a client when joining a channel to inform them that the channel with the name <channel> does not have any topic set.

// 332
#define RPL_TOPIC(client, channel, topic) \
    ":" + client + " " + channel + " :" + topic
//   "<client> <channel> :<topic>"
// Sent to a client when joining the <channel> to inform them of the current topic of the channel.

// 333
#define RPL_TOPICWHOTIME(client, channel, nick, setat) \
    ":" + client + " " + channel + " " + nick + " " + setat
//   "<client> <channel> <nick> <setat>"
// Sent to a client to let them know who set the topic (<nick>) and when they set it (<setat> is a unix timestamp). Sent after RPL_TOPIC (332).

// 336
#define RPL_INVITELIST(client, channel) \
    ":" + client + " " + channel
//   "<client> <channel>"
// Sent to a client as a reply to the INVITE command when used with no parameter, to indicate a channel the client was invited to.

// This numeric should not be confused with RPL_INVEXLIST (346), which is used as a reply to MODE.

// Some rare implementations use 346 instead of 336 for this reply.

// 337
#define RPL_ENDOFINVITELIST(client) \
    ":" + client + " :End of /INVITE list"
//   "<client> :End of /INVITE list"
// Sent as a reply to the INVITE command when used with no parameter, this numeric indicates the end of invitations a client received.

// This numeric should not be confused with RPL_ENDOFINVEXLIST (347), which is used as a reply to MODE.

// Some rare implementations use 347 instead of 337 for this reply.

// RPL_WHOISACTUALLY (338)
//   "<client> <nick> :is actually ..."
//   "<client> <nick> <host|ip> :Is actually using host"
//   "<client> <nick> <username>@<hostname> <ip> :Is actually using host"
// Sent as a reply to the WHOIS and WHOWAS commands, this numeric shows details about the client with the nickname <nick>.

// <username> represents the name set by the USER command (though <username> may be set by the server in other ways).

// <host> and <ip> represent the real host and IP address the client is connecting from. <host> CANNOT start with a colon (':', 0x3A) as this would get parsed as a trailing parameter – IPv6 addresses such as "::1" are prefixed with a zero ('0', 0x30) to ensure this. The resulting IPv6 is equivalent, as this is a partial expansion of the :: shorthand.

// See also: RPL_WHOISHOST (378), for similar semantics on other servers.

// 341
#define RPL_INVITING(client, nick, channel) \
    ":" + client + " " + nick + " " + channel
//   "<client> <nick> <channel>"
// Sent as a reply to the INVITE command to indicate that the attempt was successful and the client with the nickname <nick> has been invited to <channel>.

// 346
#define RPL_INVEXLIST(client, channel, mask) \
    ":" + client + " " + channel + " " + mask
//   "<client> <channel> <mask>"
// Sent as a reply to the MODE command, when clients are viewing the current entries on a channel’s invite-exception list. <mask> is the given mask on the invite-exception list.

// This numeric should not be confused with RPL_INVITELIST (336), which is used as a reply to INVITE.

// This numeric is sometimes erroneously called RPL_INVITELIST, as this was the name used in RFC2812.

// 347
#define RPL_ENDOFINVEXLIST(client, channel) \
    ":" + client + " " + channel + " :End of Channel Invite Exception List"
//   "<client> <channel> :End of Channel Invite Exception List"
// Sent as a reply to the MODE command, this numeric indicates the end of a channel’s invite-exception list.

// This numeric should not be confused with RPL_ENDOFINVITELIST (337), which is used as a reply to INVITE.

// This numeric is sometimes erroneously called RPL_ENDOFINVITELIST, as this was the name used in RFC2812.

// 348
#define RPL_EXCEPTLIST(client, channel, mask) \
    ":" + client + " " + channel + " " + mask
//   "<client> <channel> <mask>"
// Sent as a reply to the MODE command, when clients are viewing the current entries on a channel’s exception list. <mask> is the given mask on the exception list.

// 349
#define RPL_ENDOFEXCEPTLIST(client, channel) \
    ":" + client + " " + channel + " :End of channel exception list"
//   "<client> <channel> :End of channel exception list"
// Sent as a reply to the MODE command, this numeric indicates the end of a channel’s exception list.

// 351
#define RPL_VERSION(client, version, server, comments) \
    ":" + client + " " + version + " " + server + " :" + comments
//   "<client> <version> <server> :<comments>"
// Sent as a reply to the VERSION command, this numeric indicates information about the desired server. <version> is the name and version of the software being used (including any revision information). <server> is the name of the server. <comments> may contain any further comments or details about the specific version of the server.

// 353
#define RPL_NAMREPLY(client, symbol, channel, prefix, nick) \
    ":" + client + " " + symbol + " " + channel + " :" + prefix + nick
//   "<client> <symbol> <channel> :[prefix]<nick>{ [prefix]<nick>}"
// Sent as a reply to the NAMES command, this numeric lists the clients that are joined to <channel> and their status in that channel.

// <symbol> notes the status of the channel. It can be one of the following:

// ("=", 0x3D) - Public channel.
// ("@", 0x40) - Secret channel (secret channel mode "+s").
// ("*", 0x2A) - Private channel (was "+p", no longer widely used today).
// <nick> is the nickname of a client joined to that channel, and <prefix> is the highest channel membership prefix that client has in the channel, if they have one. The last parameter of this numeric is a list of [prefix]<nick> pairs, delimited by a SPACE character (' ', 0x20).

// 366
#define RPL_ENDOFNAMES(client, channel) \
    ":" + client + " " + channel + " :End of /NAMES list"
//   "<client> <channel> :End of /NAMES list"
// Sent as a reply to the NAMES command, this numeric specifies the end of a list of channel member names.

// RPL_LINKS (364)
//   "<client> * <server> :<hopcount> <server info>"
// Sent as a reply to the LINKS command, this numeric specifies one of the known servers on the network.

// <server info> is a string containing a description of that server.

// RPL_ENDOFLINKS (365)
//   "<client> * :End of /LINKS list"
// Sent as a reply to the LINKS command, this numeric specifies the end of a list of channel member names.

// RPL_BANLIST (367)
//   "<client> <channel> <mask> [<who> <set-ts>]"
// Sent as a reply to the MODE command, when clients are viewing the current entries on a channel’s ban list. <mask> is the given mask on the ban list.

// <who> and <set-ts> are optional and MAY be included in responses. <who> is either the nickname or nickmask of the client that set the ban, or a server name, and <set-ts> is the UNIX timestamp of when the ban was set.

// 368
#define RPL_ENDOFBANLIST(client, channel) \
    ":" + client + " " + channel + " :End of channel ban list."
//   "<client> <channel> :End of channel ban list"
// Sent as a reply to the MODE command, this numeric indicates the end of a channel’s ban list.

// 369
#define RPL_ENDOFWHOWAS(client, nick) \
    ":" + client + " " + nick + " :End of WHOWAS"
//   "<client> <nick> :End of WHOWAS"
// Sent as a reply to the WHOWAS command, this numeric indicates the end of a WHOWAS reponse for the nickname <nick>. This numeric is sent after all other WHOWAS response numerics have been sent to the client.

// 371
#define RPL_INFO(client, string) \
    ":" + client + " :" + string
//   "<client> :<string>"
// Sent as a reply to the INFO command, this numeric returns human-readable information describing the server: e.g. its version, list of authors and contributors, and any other miscellaneous information which may be considered to be relevant.

// 374
#define RPL_ENDOFINFO(client) \
    ":" + client + " :End of INFO list"
//   "<client> :End of INFO list"
// Indicates the end of an INFO response.

// RPL_MOTDSTART(375)
//   "<client> :- <server> Message of the day - "
// Indicates the start of the Message of the Day to the client. The text used in the last param of this message may vary, and SHOULD be displayed as-is by IRC clients to their users.

// RPL_MOTD (372)
//   "<client> :<line of the motd>"
// When sending the Message of the Day to the client, servers reply with each line of the MOTD as this numeric. MOTD lines MAY be wrapped to 80 characters by the server.

// RPL_ENDOFMOTD (376)
//   "<client> :End of /MOTD command."
// Indicates the end of the Message of the Day to the client. The text used in the last param of this message may vary.

// 378
#define RPL_WHOISHOST(client, nick) \
    ":" + client + " " + nick + " :is connecting from #@localhost 127.0.0.1"
//   "<client> <nick> :is connecting from *@localhost 127.0.0.1"
// Sent as a reply to the WHOIS command, this numeric shows details about where the client with nickname <nick> is connecting from.

// See also: RPL_WHOISACTUALLY (338), for similar semantics on other servers.

// 379
#define RPL_WHOISMODES(client, nick) \
    ":" + client + " " + nick + " :is using modes +aliosw"
//   "<client> <nick> :is using modes +ailosw"
// Sent as a reply to the WHOIS command, this numeric shows the client what user modes the target users has.

// 381
#define RPL_YOUREOPER(client) \
    ":" + client + " :You are now an IRC operator"
//   "<client> :You are now an IRC operator"
// Sent to a client which has just successfully issued an OPER command and gained operator status. The text used in the last param of this message varies wildly.

// RPL_REHASHING(382)
//   "<client> <config file> :Rehashing"
// Sent to an operator which has just successfully issued a REHASH command. The text used in the last param of this message may vary.

// 391
// #define RPL_TIME(391)
//   "<client> <server> [<timestamp> [<TS offset>]] :<human-readable time>"
// Reply to the TIME command. Typically only contains the human-readable time, but it may include a UNIX timestamp.

// Clients SHOULD NOT parse the human-readable time.

// <TS offset> is used by some servers using a TS-based server-to-server protocol (eg. TS6), and represents the offset between the server’s system time, and the TS of the network. A positive value means the server is lagging behind the TS of the network. Clients SHOULD ignore its value.

// 400
#define ERR_UNKNOWNERROR(client, command, subcommand, info) \
    ":" + client + " " + command + "{" + subcommand + "} :" + info // doublc check
//   "<client> <command>{ <subcommand>} :<info>"
// Indicates that the given command/subcommand could not be processed. <subcommand> may repeat for more specific subcommands.

// For example, for an issue with a hypothetical command PACK, this may be returned:

//   :example.com 400 dan!~d@n PACK :Could not process multiple invalid parameters
// For an issue with a hypothetical command PACK with the subcommand BOX, this may be returned:

//   :example.com 400 dan!~d@n PACK BOX :Could not find box to pack
// This numeric indicates a very generalised error (which <info> should further explain). If there is another more specific numeric which represents the error occuring, that should be used instead.

// 401
#define ERR_NOSUCHNICK(client, nickname) \
    ":" + client + " " + nickname + " :No such nick/channel"
//   "<client> <nickname> :No such nick/channel"
// Indicates that no client can be found for the supplied nickname. The text used in the last param of this message may vary.

// 402
#define ERR_NOSUCHSERVER(client, server_name) \
    ":" + client + " " + server_name + " :No such server"
//   "<client> <server name> :No such server"
// Indicates that the given server name does not exist. The text used in the last param of this message may vary.

// 403
#define ERR_NOSUCHCHANNEL(client, channel) \
    ":" + client + " " + channel
//   "<client> <channel> :No such channel"
// Indicates that no channel can be found for the supplied channel name. The text used in the last param of this message may vary.

// 404
#define ERR_CANNOTSENDTOCHAN(client, channel) \
    ":" + client + " " + channel + " :Cannot send to channel"
//   "<client> <channel> :Cannot send to channel"
// Indicates that the PRIVMSG / NOTICE could not be delivered to <channel>. The text used in the last param of this message may vary.

// This is generally sent in response to channel modes, such as a channel being moderated and the client not having permission to speak on the channel, or not being joined to a channel with the no external messages mode set.

// 405
#define ERR_TOOMANYCHANNELS(client, channel) \
    ":" + client + " " + channel + " :You have joined too many channels"
//   "<client> <channel> :You have joined too many channels"
// Indicates that the JOIN command failed because the client has joined their maximum number of channels. The text used in the last param of this message may vary.

// 406
#define ERR_WASNOSUCHNICK(client) \
    ":" + client + " :There was no such nickname"
//   "<client> :There was no such nickname"
// Returned as a reply to WHOWAS to indicate there is no history information for that nickname.

// 409
#define ERR_NOORIGIN(client) \
    ":" + client + " :No origin specified"
//   "<client> :No origin specified"
// Indicates a PING or PONG message missing the originator parameter which is required by old IRC servers. Nowadays, this may be used by some servers when the PING <token> is empty.

// 411
#define ERR_NORECIPIENT(client) \
    ":" + client + " :No recipient given (" + command ")"
//   "<client> :No recipient given (<command>)"
// Returned by the PRIVMSG command to indicate the message wasn’t delivered because there was no recipient given.

// 412
#define ERR_NOTEXTTOSEND(client) \
    ":" + client + " :No text to send"
//   "<client> :No text to send"
// Returned by the PRIVMSG command to indicate the message wasn’t delivered because there was no text to send.

// 417
#define ERR_INPUTTOOLONG(client) \
    ":" + client + " :Input line was too long"
//   "<client> :Input line was too long"
// Indicates a given line does not follow the specified size limits (512 bytes for the main section, 4094 or 8191 bytes for the tag section).

// 421
#define ERR_UNKNOWNCOMMAND(client, command) \
    ":" + client + " " + command + " :Unknown command"
//   "<client> <command> :Unknown command"
// Sent to a registered client to indicate that the command they sent isn’t known by the server. The text used in the last param of this message may vary.

// 422
#define ERR_NOMOTD(client) \
    ":" + client + " :MOTD File is missing"
//   "<client> :MOTD File is missing"
// Indicates that the Message of the Day file does not exist or could not be found. The text used in the last param of this message may vary.

// 431
#define ERR_NONICKNAMEGIVEN(client) \
    ":" + client + " :No nickname given"
//   "<client> :No nickname given"
// Returned when a nickname parameter is expected for a command but isn’t given.

// 432
#define ERR_ERRONEUSNICKNAME(client, nick) \
    ":" + client + " " + nick + " :Errorneus nickname"
//   "<client> <nick> :Erroneus nickname"
// Returned when a NICK command cannot be successfully completed as the desired nickname contains characters that are disallowed by the server. See the NICK command for more information on characters which are allowed in various IRC servers. The text used in the last param of this message may vary.

// 433
#define ERR_NICKNAMEINUSE(client, nick) \
    ":" + client + " * " + nick + " :Nickname is already in use."
//   "<client> <nick> :Nickname is already in use"
// Returned when a NICK command cannot be successfully completed as the desired nickname is already in use on the network. The text used in the last param of this message may vary.

// 436
#define ERR_NICKCOLLISION(client, nick, user, host) \
    ":" + client + " " + nick + " :Nickname collision KILL from " + user + "@" + host
//   "<client> <nick> :Nickname collision KILL from <user>@<host>"
// Returned by a server to a client when it detects a nickname collision (registered of a NICK that already exists by another server). The text used in the last param of this message may vary.

// 441
#define ERR_USERNOTINCHANNEL(client, nick, channel) \
    ":" + client + " " + nick + " " + channel + " :They aren't on that channel"
//   "<client> <nick> <channel> :They aren't on that channel"
// Returned when a client tries to perform a channel+nick affecting command, when the nick isn’t joined to the channel (for example, MODE #channel +o nick).

// 442
#define ERR_NOTONCHANNEL(client, channel) \
    ":" + client + " " + channel + " :You're not on that channel"
//   "<client> <channel> :You're not on that channel"
// Returned when a client tries to perform a channel-affecting command on a channel which the client isn’t a part of.

// 443
#define ERR_USERONCHANNEL(client, nick, channel) \
    ":" + client + " " + nick + " " + channel + " :is already on channel"
//   "<client> <nick> <channel> :is already on channel"
// Returned when a client tries to invite <nick> to a channel they’re already joined to.

// 451
#define ERR_NOTREGISTERED(client) \
    ":" + client + " :You have not registered"
//   "<client> :You have not registered"
// Returned when a client command cannot be parsed as they are not yet registered. Servers offer only a limited subset of commands until clients are properly registered to the server. The text used in the last param of this message may vary.

// 461
#define ERR_NEEDMOREPARAMS(client, command) \
    ":" + client + " " + command + " :Not enough parameters"
//   "<client> <command> :Not enough parameters"
// Returned when a client command cannot be parsed because not enough parameters were supplied. The text used in the last param of this message may vary.

// 462
#define ERR_ALREADYREGISTERED(client) \
    ":" + client + " :You may not register"
//   "<client> :You may not reregister"
// Returned when a client tries to change a detail that can only be set during registration (such as resending the PASS or USER after registration). The text used in the last param of this message varies.

// 464
#define ERR_PASSWDMISMATCH(client) \
    ":" + client + " :Password incorrect"
//   "<client> :Password incorrect"
// Returned to indicate that the connection could not be registered as the password was either incorrect or not supplied. The text used in the last param of this message may vary.

// 465
#define ERR_YOUREBANNEDCREEP(client) \
    ":" + client + " :You are banned from this server."
//   "<client> :You are banned from this server."
// Returned to indicate that the server has been configured to explicitly deny connections from this client. The text used in the last param of this message varies wildly and typically also contains the reason for the ban and/or ban details, and SHOULD be displayed as-is by IRC clients to their users.

// 471
#define ERR_CHANNELISFULL(client, channel) \
    ":" + client + " " + channel + " :Cannot join channel (+l)"
//   "<client> <channel> :Cannot join channel (+l)"
// Returned to indicate that a JOIN command failed because the client limit mode has been set and the maximum number of users are already joined to the channel. The text used in the last param of this message may vary.

// 472
#define ERR_UNKNOWNMODE(client, modechar) \
    ":" + client + " " + modechar + " :is unknown mode char to me"
//   "<client> <modechar> :is unknown mode char to me"
// Indicates that a mode character used by a client is not recognized by the server. The text used in the last param of this message may vary.

// 473
#define ERR_INVITEONLYCHAN(client, channel) \
    ":" + client + " " + channel + " :Cannot join channel (+i)"
//   "<client> <channel> :Cannot join channel (+i)"
// Returned to indicate that a JOIN command failed because the channel is set to [invite-only] mode and the client has not been invited to the channel or had an invite exception set for them. The text used in the last param of this message may vary.

// 474
#define ERR_BANNEDFROMCHAN(client, channel) \
    ":" + client + " " + channel + " :Cannot join channel (+b)"
//   "<client> <channel> :Cannot join channel (+b)"
// Returned to indicate that a JOIN command failed because the client has been banned from the channel and has not had a ban exception set for them. The text used in the last param of this message may vary.

// 475
#define ERR_BADCHANNELKEY(client, channel) \
    ":" + client + " " + channel + " :Cannot join channel (+k)"
//   "<client> <channel> :Cannot join channel (+k)"
// Returned to indicate that a JOIN command failed because the channel requires a key and the key was either incorrect or not supplied. The text used in the last param of this message may vary.

// Not to be confused with ERR_INVALIDKEY, which may be returned when setting a key.

// 476
#define ERR_BADCHANMASK(client, channel) \
    ":" + client + " " + channel + " :Bad Channel Mask"
//   "<channel> :Bad Channel Mask"
// Indicates the supplied channel name is not a valid.

// This is similar to, but stronger than, ERR_NOSUCHCHANNEL (403), which indicates that the channel does not exist, but that it may be a valid name.

// The text used in the last param of this message may vary.

// 481
#define ERR_NOPRIVILEGES(client) \
    ":" + client + " :Permission Denied- You're not an IRC operator"
//   "<client> :Permission Denied- You're not an IRC operator"
// Indicates that the command failed because the user is not an IRC operator. The text used in the last param of this message may vary.

// 482
#define ERR_CHANOPRIVSNEEDED(client, channel) \
    ":" + client + " " + channel + " :You're not channel operator"
//   "<client> <channel> :You're not channel operator"
// Indicates that a command failed because the client does not have the appropriate channel privileges. This numeric can apply for different prefixes such as halfop, operator, etc. The text used in the last param of this message may vary.

// 483
#define ERR_CANTKILLSERVER(client) \
    ":" + client + " :You cant kill a server!"
//   "<client> :You cant kill a server!"
// Indicates that a KILL command failed because the user tried to kill a server. The text used in the last param of this message may vary.

// 491
#define ERR_NOOPERHOST(client) \
    ":" + client + " :No O-lines for your host"
//   "<client> :No O-lines for your host"
// Indicates that an OPER command failed because the server has not been configured to allow connections from this client’s host to become an operator. The text used in the last param of this message may vary.

// 501
#define ERR_UMODEUNKNOWNFLAG(client) \
    ":" + client + " :Unknown MODE flag"
//   "<client> :Unknown MODE flag"
// Indicates that a MODE command affecting a user contained a MODE letter that was not recognized. The text used in the last param of this message may vary.

// 502
#define ERR_USERSDONTMATCH(client) \
    ":" + client + " :Cant change mode for other users"
//   "<client> :Cant change mode for other users"
// Indicates that a MODE command affecting a user failed because they were trying to set or view modes for other users. The text used in the last param of this message varies, for instance when trying to view modes for another user, a server may send: "Can't view modes for other users".

// 524
#define ERR_HELPNOTFOUND(client, subject) \
    ":" + client + " " + subject + " :No help available on this topic"
// "<client> <subject> :No help available on this topic" Indicates that a HELP command requested help on a subject the server does not know about.

// 525
#define ERR_INVALIDKEY(client, target_chan) \
    ":" + client + " " + target_chan + " :Key is not well-formed"

// The<subject>
//     MUST be the one requested by the client,
//     but may be casefolded;
// unless it would be an invalid parameter, in which case it MUST be *.

//                                          ERR_INVALIDKEY(525) "<client> <target chan> :Key is not well-formed" Indicates the value of a key channel mode change(+k) was rejected.

//                                          Not to be confused with ERR_BADCHANNELKEY,
//     which is returned when someone tries to join a channel.

//     RPL_STARTTLS(670) "<client> :STARTTLS successful, proceed with TLS handshake" This numeric is used by the IRCv3 tls extension and indicates that the client may begin a TLS handshake.For more information on this numeric,
//     see the linked IRCv3 specification.

//     The text used in the last param of this message varies wildly.

//     RPL_WHOISSECURE(671) "<client> <nick> :is using a secure connection" Sent as a reply to the WHOIS command,
//     this numeric shows the client is connecting to the server in a way the server considers reasonably safe from eavesdropping(e.g.connecting from localhost, using TLS, using Tor).

//         ERR_STARTTLS(691) "<client> :STARTTLS failed (Wrong moon phase)" This numeric is used by the IRCv3 tls extension and indicates that a server
//         - side error occured and the STARTTLS command failed.For more information on this numeric,
//     see the linked IRCv3 specification.

//         The text used in the last param of this message varies wildly.

// check
// 696
#define ERR_INVALIDMODEPARAM(client, target_user, mode_char, param, description) \
    ":" + client + " " + target_user + " " + mode_char + " " + param + " :" + description
//"<client> <target chan/user> <mode char> <parameter> :<description>" Indicates that there was a problem with a mode parameter.Replaces various implementation
//         - specific mode - specific numerics.

// RPL_HELPSTART (704)
#define RPL_HELPSTART(client, subject, text) \
    ":" + client + " " + subject + " : " + text
// Indicates the start of a reply to a HELP command. The text used in the last parameter of this message may vary, and SHOULD be displayed as-is by IRC clients to their users; possibly emphasized as the title of the help section.
// The <subject> MUST be the one requested by the client, but may be casefolded; unless it would be an invalid parameter, in which case it MUST be *.

// RPL_HELPTXT(705)
#define RPL_HELPTXT(client, subject, text) \
    ":" + client + " " + subject + " : " + text
// Returns a line of HELP text to the client. Lines MAY be wrapped to a certain line length by the server. Note that the final line MUST be a RPL_ENDOFHELP (706) numeric.
// The <subject> MUST be the one requested by the client, but may be casefolded; unless it would be an invalid parameter, in which case it MUST be *.

// RPL_ENDOFHELP (706)
#define RPL_ENDOFHELP(client, subject, text) \
    ":" + client + " " + subject + " : " + text
// Returns the final HELP line to the client.
// The <subject> MUST be the one requested by the client, but may be casefolded; unless it would be an invalid parameter, in which case it MUST be *.

//                                              ERR_NOPRIVS(723) "<client> <priv> :Insufficient oper privileges." Sent by a server to alert an IRC
//                                              operator that they they do not have the specific
//                                              operator privilege required by this server / network to perform the command or action they requested.The text used in the last param of this message may vary.

//                                              <priv>is a string that has meaning in the server software,
//     and allows an operator the privileges to perform certain commands or actions.These strings are server - defined and may refer to one or multiple commands or actions that may be performed by IRC operators.

//         Examples of the sorts of privilege strings used by server software today include: kline, dline, unkline, kill, kill:remote, die, remoteban, connect, connect:remote, rehash.

// RPL_LOGGEDIN (900)
//   "<client> <nick>!<user>@<host> <account> :You are now logged in as <username>"
// This numeric indicates that the client was logged into the specified account (whether by SASL authentication or otherwise). For more information on this numeric, see the IRCv3 sasl-3.1 extension.

// The text used in the last param of this message varies wildly.

// RPL_LOGGEDOUT (901)
//   "<client> <nick>!<user>@<host> :You are now logged out"
// This numeric indicates that the client was logged out of their account. For more information on this numeric, see the IRCv3 sasl-3.1 extension.

// The text used in the last param of this message varies wildly.

// ERR_NICKLOCKED (902)
//   "<client> :You must use a nick assigned to you"
// This numeric indicates that SASL authentication failed because the account is currently locked out, held, or otherwise administratively made unavailable. For more information on this numeric, see the IRCv3 sasl-3.1 extension.

// The text used in the last param of this message varies wildly.

// RPL_SASLSUCCESS (903)
//   "<client> :SASL authentication successful"
// This numeric indicates that SASL authentication was completed successfully, and is normally sent along with RPL_LOGGEDIN (900). For more information on this numeric, see the IRCv3 sasl-3.1 extension.

// The text used in the last param of this message varies wildly.

// ERR_SASLFAIL (904)
//   "<client> :SASL authentication failed"
// This numeric indicates that SASL authentication failed because of invalid credentials or other errors not explicitly mentioned by other numerics. For more information on this numeric, see the IRCv3 sasl-3.1 extension.

// The text used in the last param of this message varies wildly.

// ERR_SASLTOOLONG (905)
//   "<client> :SASL message too long"
// This numeric indicates that SASL authentication failed because the AUTHENTICATE command sent by the client was too long (i.e. the parameter was longer than 400 bytes). For more information on this numeric, see the IRCv3 sasl-3.1 extension.

// The text used in the last param of this message varies wildly.

// ERR_SASLABORTED (906)
//   "<client> :SASL authentication aborted"
// This numeric indicates that SASL authentication failed because the client sent an AUTHENTICATE command with the parameter ('*', 0x2A). For more information on this numeric, see the IRCv3 sasl-3.1 extension.

// The text used in the last param of this message varies wildly.

// ERR_SASLALREADY (907)
//   "<client> :You have already authenticated using SASL"
// This numeric indicates that SASL authentication failed because the client has already authenticated using SASL and reauthentication is not available or has been administratively disabled. For more information on this numeric, see the IRCv3 sasl-3.1 and sasl-3.2 extensions.

// The text used in the last param of this message varies wildly.

// RPL_SASLMECHS (908)
//   "<client> <mechanisms> :are available SASL mechanisms"
// This numeric specifies the mechanisms supported for SASL authentication. <mechanisms> is a list of SASL mechanisms, delimited by a comma (',', 0x2C). For more information on this numeric, see the IRCv3 sasl-3.1 extension.

// IRCv3.2 also specifies this information in the sasl client capability value. For more information on this, see the IRCv3 sasl-3.2 extension.

// The text used in the last param of this message varies wildly.

#endif
