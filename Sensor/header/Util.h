
class RetVal {
public:
	enum Status {
		E_OK,
		E_NOT_OK
	};
	RetVal(Status status) : status(status){}
	Status getStatus() const {
		return status;
	}
private:
	Status status;
};
