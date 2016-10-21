#pragma once
#ifndef __MC_IRCINTERPRETER_H__
#define __MC_IRCINTERPRETER_H__

void MCPFreeMessage(message *self);
message *MCPExplodeMessage(char *rawmsg);

#endif

