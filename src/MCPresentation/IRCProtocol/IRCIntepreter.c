#include <stdio.h>
#include <stdlib.h>
#include "../../lib/bstrlib/bstrlib.h"
#include "../../lib/bstrlib/utf8util.h"
#include "../../lib/bstrlib/bstraux.h"
#include "../../lib/bstrlib/bsafe.h"
#include "../MCPresentation.h"
#include "IRCIntepreter.h"

void MCPFreeMessage(message *self)
{
	free(message.data);
	free(message);
}

message *MCPExplodeMessage(char *rawmsg)
{
	message *ret = malloc(sizeof(message));
	ret.free = MCPFreeMessage;
	
	if (rawmsg[0] == ':')
		ret.from = rawmsg;
	else
		ret.from = NULL;
	
	char *search_ptr;
	if (ret.from)
		search_ptr = ret.from;
	else
		search_ptr = rawmsg;
	while (*(search_ptr++) != ' ');
	ret.command = search_ptr;
	
	while (*(search_ptr++) != ' ');
	ret.params = search_ptr;

	return ret;
}


