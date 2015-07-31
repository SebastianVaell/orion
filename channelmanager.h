#ifndef CHANNEL_MANAGER_H
#define CHANNEL_MANAGER_H

#include "channel.h"
#include "fileutils.h"
#include "connector.h"
#include "rapidjson/include/rapidjson/document.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "threadman.h"
#include "kstream/mainwindow.h"
#include <QObject>

#define TWITCH_URI "https://api.twitch.tv/kraken"
#define DATAURI "./data.json"

class ThreadManager;
class MainWindow;

class ChannelManager: public QObject{
    Q_OBJECT
	protected:
		unsigned int update_counter, check_counter;
        std::vector<Channel*> channels;
        ThreadManager* tman;
	
	public:
		ChannelManager();

		~ChannelManager();	
        void load();
        void save();
		bool readJSON(const char*);
		bool writeJSON(const char*);
		void checkStream(Channel*,bool);
		void check(Channel*,std::string);
        void checkStreams(bool sync);
        bool update(Channel*);
        bool update(Channel*,std::string);
        void updateChannels(bool sync);
        void add(Channel *channel);
		void add(const char*,const char*,const char*,const char*);
		void remove(const char*);
        void remove(Channel*);
		void add(const char*);
		void printList();
        void setAlert(const char*,const char*);
		Channel *find(const char*);
		int findPos(const char*);
        std::vector<Channel*> *getChannels(){ return &channels; }
		void clearData();
        void play(Channel*);
        Channel* getLastAdded();
        bool channelExists(const char*);
        void checkAllStreams();
        void parseOnlineStreams(std::string);

    signals:
        void channelExists(Channel*);
        void channelNotFound();
        void channelStateChanged(Channel*);
        void newChannel(Channel*);

};

#endif //CHANNEL_MANAGER_H
