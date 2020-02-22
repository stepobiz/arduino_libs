#include "Arduino.h"
#include "Command.h"
#include "CommandReader.h"

CommandReader::CommandReader()
{
	command = new Command();
	commandBuffer = new Command();
}

void CommandReader::reset()
{
	commandPartBuffer = "";
	delete commandBuffer;
	commandBuffer = new Command();
}

void CommandReader::resetCommand()
{
	delete command;
	command = new Command();
}

void CommandReader::ackExecution()
{
	resetCommand();
}

Command *CommandReader::getCommand(int incomingByte)
{
	if (incomingByte == 45 || incomingByte == 124 || incomingByte == 10)
	{
		if (commandBuffer->action == NULL)
		{
			if (commandPartBuffer == NULL)
			{
				commandPartBuffer = "!";
			}
			commandBuffer->action = commandPartBuffer;
		}
		else if (commandBuffer->param == NULL)
		{
			if (commandPartBuffer == NULL)
			{
				commandPartBuffer = "!";
			}
			commandBuffer->param = commandPartBuffer;
		}
		else
		{
			if (commandPartBuffer != NULL)
			{
				commandBuffer->device = commandPartBuffer;

				command->action = commandBuffer->action;
				command->param = commandBuffer->param;
				command->device = commandBuffer->device;
				command->executionReady = true;
			}
		}
		commandPartBuffer = "";
	}
	else
	{
		char incomingByteChar = incomingByte;
		commandPartBuffer += incomingByteChar;
	}

	// New Comand and New Line
	if (incomingByte == 124 || incomingByte == 10)
	{
		reset();
	}
	return command;
}