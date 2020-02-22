class CommandReader
{
    private:
		String commandPartBuffer;
		Command* commandBuffer;
		Command* command;
		void reset();
		void resetCommand();
    public:
		CommandReader();
		void ackExecution();
        Command* getCommand(int incomingByte);
};