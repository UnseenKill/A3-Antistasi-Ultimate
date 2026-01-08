/* Args: String|Boolean _serverID, String _campaignID, String _mapName
 * Target: server + clients
 * Sent-by: server
 */
#define A3A_EVENT_SERVER_GAME_DELETED QUOTE(TRIPLES(PREFIX,event,onGameDeleted))

/* Args: None
 * Target: server + clients
 * Sent-by: server
 */
#define A3A_EVENT_SERVER_GAME_SAVED QUOTE(TRIPLES(PREFIX,event,onGameSaved))

/* Args: String|Boolean _serverID, String _campaignID, String _mapName
 * Target: server
 * Sent-by: server
 */
#define A3A_EVENT_SERVER_INIT_COMPLETE QUOTE(TRIPLES(PREFIX,event,serverLoadComplete))
