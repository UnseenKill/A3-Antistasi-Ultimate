// Client-only event; after client initialization; params=[]
#define CBA_EVENT_CLIENT_INIT_DONE QUOTE(TRIPLES(PREFIX,event,clientInitDone))
// Client-only event; on personal save loaded; params=[Hashmap saveData]
#define CBA_EVENT_CLIENT_PLAYER_LOAD QUOTE(TRIPLES(PREFIX,event,clientPlayerLoad))
// Client-only event; on personal save; params=[Hashmap saveData]
#define CBA_EVENT_CLIENT_PLAYER_SAVE QUOTE(TRIPLES(PREFIX,event,clientPlayerSave))
/* Args: String|Boolean _serverID, String _campaignID, String _mapName
 * Target: server + clients
 * Sent-by: server
 */
#define CBA_EVENT_SERVER_GAME_DELETED QUOTE(TRIPLES(PREFIX,event,onGameDeleted))
// Server-only event; after server initialization; params=[String|Boolean serverID, String campaignID, String worldname]
#define CBA_EVENT_SERVER_INIT_DONE QUOTE(TRIPLES(PREFIX,event,serverInitDone))
// Server-only event; on game save; params=[]
#define CBA_EVENT_SERVER_GAME_SAVED QUOTE(TRIPLES(PREFIX,event,serverGameSaved))
