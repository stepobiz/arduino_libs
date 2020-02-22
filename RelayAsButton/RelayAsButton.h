class RelayAsButton
{
    private:
		int _pin;
		int _buttonDelay;
		long clickAt;
    public:
		RelayAsButton(int pin, int buttonDelay);
		bool push();
        void check();
};