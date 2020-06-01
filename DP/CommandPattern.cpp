/*
 * CommandPattern.cpp
 *
 *  Created on: Jul 17, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<string>

#define MAX_CONTROLS 4

using namespace std;
//Receiver Class
class Light{
public:
	Light() {}
	void On(){
		cout << " On" << endl;
	}
	void Off(){
		cout << " Off" << endl;
	}

};

class Gaurage{
public:
	Gaurage(){}
	void Open(){
		cout  << " Open" << endl;
	}
	void Close(){
		cout  << " Close" << endl;
	}
};

class TV{
public:
	TV() {}
	void On(){
		cout <<  " On" << endl;
	}
	void Off(){
		cout  << " Off" << endl;
	}

};


//Command classes
class command{
	const std::string name;
public:
	command() : name("Dummy"){}
	command(const char *str) : name(str){}
	virtual ~command(){}

	virtual void execute() = 0;
	const std::string &GetName(){
		return name;
	}
};

class NoCommand : public command{
public:
	NoCommand() {}
	void execute(){
		cout << endl << GetName() << endl ;
	}
};
class LightOnCommand : public command{
	Light &light;
public:
	LightOnCommand(Light &l, const char *str) : command(str), light(l){}
	void execute(){
		cout << endl << GetName() << " ";
		light.On();
	}
};

class LightOffCommand : public command{
	Light &light;
public:
	LightOffCommand(Light &l, const char *str) : command(str), light(l){}
	void execute(){
		cout << endl << GetName() << " ";
		light.Off();
	}
};


class GarageOpenCommand : public command{
	Gaurage &garage;
public:
	GarageOpenCommand(Gaurage &g, const char *str) : command(str), garage(g){}
	void execute(){
		cout << endl << GetName() << " ";
		garage.Open();
	}
};

class GarageCloseCommand : public command{
	Gaurage &garage;
public:
	GarageCloseCommand(Gaurage &g, const char *str) : command(str), garage(g){}
	void execute(){
		cout << endl << GetName() << " ";
		garage.Close();
	}
};

class TVOnCommand : public command{
	TV &tv;
public:
	TVOnCommand(TV &v, const char *str) : tv(v), command(str) {}
	void execute(){
		cout << endl << GetName() << " ";
		tv.On();
	}
};

class TVOffCommand : public command{
	TV &tv;
public:
	TVOffCommand(TV &v, const char *str) : command(str), tv(v){}
	void execute(){
		cout << endl << GetName() << " ";
		tv.Off();
	}
};


class RemoteControl{
	command *onCommands[MAX_CONTROLS];
	command *offCommands[MAX_CONTROLS];
public:
	RemoteControl(){
		//onCommands = new command[MAX_CONTROLS];
		for(int i = 0;  i < MAX_CONTROLS; i++){
			onCommands[i] = new NoCommand;
			offCommands[i] = new NoCommand;
		}
	}

	void SetCommand(unsigned int index, command *Oncmd, command *offCmd){
		if(index >= MAX_CONTROLS){
			cout << endl << "index should not be greater than 3 \n";
			return ;
		}

		onCommands[index] = Oncmd;
		offCommands[index] = offCmd;
	}
	void OnCommandPush(unsigned int index){
		if(index >= MAX_CONTROLS){
			cout << endl << "index " << index << " should not be greater than " << MAX_CONTROLS << "  \n";
			return ;
		}
		onCommands[index]->execute();
	}
	void OffCommandPush(unsigned int index){
		if(index >= MAX_CONTROLS){
			cout << endl << "index " << index << " should not be greater than " << MAX_CONTROLS << "  \n";
			return ;
		}
		offCommands[index]->execute();
	}
};


int main(){

	Light light1;
	Light light2;
	Gaurage g;
	TV tv;

	LightOnCommand LivingRoomLightOn(light1, "Living Room");
	LightOnCommand KitchenLightOn(light2, "Kitchen");
	GarageOpenCommand gOpen(g, "Garage");
	TVOnCommand tvOn(tv, "TV");

	LightOffCommand LivingRoomLightOff(light1, "Living Room");
	LightOffCommand KitchenLightOff(light2, "Kitchen");
	GarageCloseCommand gClose(g, "Garage");
	TVOffCommand tvOff(tv, "TV");

	RemoteControl control;
	control.SetCommand(0, &LivingRoomLightOn, &LivingRoomLightOff);
	control.SetCommand(1, &KitchenLightOn, &KitchenLightOff);
	control.SetCommand(2, &gOpen, &gClose);
	control.SetCommand(3, &tvOn, &tvOff);

	control.OnCommandPush(0);
	control.OnCommandPush(1);
	control.OnCommandPush(2);
	control.OnCommandPush(3);

	control.OffCommandPush(0);
	control.OffCommandPush(1);
	control.OffCommandPush(2);
	control.OffCommandPush(3);

	return 0;
}
