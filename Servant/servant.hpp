#ifndef _JARVIS_HPP_
#define _JARVIS_HPP_

#include<iostream>
#include<stdio.h>
#include<map>
#include<unordered_map>
#include<sstream>
#include<memory>
#include<string>
#include<json/json.h>
#include"speech.h"
#include"base/http.h"
#include"log.hpp"


#define VOICE_PATH "voice"
#define SPEECH_TTL "ttl.mp3"
#define SPEECH_ASR "asr.wav"
#define CMD_ETC "command.etc"
#define SIZE 1024

using namespace std;


class TuLing{
    private:
		string url = "http://openapi.tuling123.com/openapi/api/v2";
        string apiKey = "8caa52dd73404526a1dc4f552c292753";
        string userId = "1";
		aip::HttpClient client;
    public:
        TuLing(){

        }

		string TlScreen(std::string &str)
		{
			JSONCPP_STRING errs;
			Json::Value root;
			Json::CharReaderBuilder rb;
			std::unique_ptr<Json::CharReader> const jsonReader(rb.newCharReader());
			bool res = jsonReader->parse(str.data(), str.data()+str.size(), &root, &errs);
			if(!res || !errs.empty())
			{
				LOG(Warning, "jsoncpp parse error");
				return errs;
			}
			Json::Value result = root["results"];
			Json::Value value = result[0]["values"];
			Json::Value text = value["text"];
			
			return text.asString();

		}

        string Chat(string message)
        {
            Json::Value root;
            root["reqType"] = 0;
            Json::Value text;
			text["text"] = message;

			Json::Value inputText;
			inputText["inputText"] = text;
            
            root["perception"] = inputText;

            Json::Value user;
            user["apiKey"] = apiKey;
            user["userId"] = userId;

            root["userInfo"] = user;

            Json::StreamWriterBuilder wb;
            std::ostringstream os;
            
            std::unique_ptr<Json::StreamWriter> JsWriter(wb.newStreamWriter());
            JsWriter->write(root, &os);

            std::string body = os.str();
            
			string response;
			int code = client.post(url, nullptr, body, nullptr, &response);
			
			if(code != CURLcode::CURLE_OK)
			{
				LOG(Warning, "http request error");	
				return "";
			}
				
			return TlScreen(response);
        }
        
        ~TuLing(){

        }


};

class Servent{
	private:
		aip::Speech *client;
		unordered_map<string, string> cmd_map;

		string appid = "22025919";
		string apikey = "36FI9fVallMdxeGNbcVVUX5Y";
		string secretkey = "AyaqxrDSLqidrsll0GMXV70t8sqIrM0D";

		string rec_cmd;
		string play_cmd;
		
	public:
		TuLing tl;
		Servent()
			:client(nullptr)
		{
			Init();
			LOG(Normal, "Servent init success");
		}
		void LoadCommand()
		{
			string name = CMD_ETC;
			ifstream in(name);
			if(!in.is_open())
			{
				LOG(Warring, "Load Command Error");
				exit(1);
			}
			char line[SIZE];
			string sep = ": ";
			
			while(in.getline(line, sizeof(line)))
			{
				string str = line;
				size_t pos = str.find(sep);
				if(pos == string::npos)
				{
					LOG(Warning, "command format error");
					break;
				}
				string key = str.substr(0, pos);
				string value = str.substr(pos+sep.size());
				cmd_map.insert({key, value});
			}

			in.close();
			LOG(Normal, "command load success");
		}


		void Init()
		{
			client = new aip::Speech(appid, apikey, secretkey);
			rec_cmd = "arecord -t wav -c 1 -r 16000 -d 3 -f S16_LE ";
			rec_cmd += VOICE_PATH;
			rec_cmd += "/";
			rec_cmd += SPEECH_ASR;
			rec_cmd += " > /dev/null 2>&1";
			
			play_cmd = "cvlc --play-and-exit ";
			play_cmd += VOICE_PATH;
			play_cmd += "/";
			play_cmd += SPEECH_TTL;
			play_cmd += " > /dev/null 2>&1";

			LoadCommand();
		}

		bool Exec(string command, bool is_print)
		{
			FILE *fp = popen(command.c_str(), "r");
			if(nullptr == fp)
			{
 		 		LOG(Warning, "popen error");
				return false;
			}
			
			if(is_print)
			{
			   	char c;
				size_t s = 0;
				while((s = fread(&c, 1, 1, fp) > 0))
				{
					cout << c;
				}
			}

			pclose(fp);
			return true;
		}

		string SevScreen(Json::Value & root)
		{
			int err_no = root["err_no"].asInt();
			if(err_no != 0)
			{
				cout << root["err_no"] << " : " << err_no << endl;
				return "Out Put Error";
			}

			return root["result"][0].asString();
		}

		string ASR(aip::Speech *cilent)
		{
			string asr_file = VOICE_PATH;
			asr_file += "/";
			asr_file += SPEECH_ASR;

			map<string, string> options;
			string file_content;
			aip::get_file_content(asr_file.c_str(), &file_content);

			Json::Value result = client->recognize(file_content, "wav", 16000, options);
			
			return SevScreen(result);
		}
		
		bool IfCommend(string& str)
		{
			return cmd_map.find(str) == cmd_map.end() ? false : true;
		}

		bool TTL(aip::Speech *client, std::string &str)
		{
			ofstream ofile;
			
			string ttl_file = VOICE_PATH;
			ttl_file += "/";
			ttl_file += SPEECH_TTL;
			
			ofile.open(ttl_file.c_str(), ios::out | ios::binary);
			
			string file_ret;
			map<string, string> options;//可选参数
			options["spd"] = "5";
			options["per"] = "4";

			Json::Value result = client->text2audio(str, options, file_ret);
			if(!file_ret.empty())
			{
				ofile << file_ret;
			}
			else
			{
				cout << result.toStyledString() << endl;
				LOG(Warning, result.toStyledString());
			}

			ofile.close();
		}

		void Run()
		{
			while(1)
			{
				cout << "				正在录音..." << endl;
				if(Exec(rec_cmd, false))
				{
				cout << "				正在识别..." << endl;
					string message = ASR(client);//语音识别
					LOG(Normal, "run ASR");

					if(IfCommend(message))
					{
						LOG(Normal, "receive command");
						//cout << "				收到指令# " << message << endl;
						Exec(cmd_map[message], true);
						continue;
					}
					if(message.find("退出") != string::npos)
					{
						LOG(Normal, "system exit");
						//cout << "				I say# " << message << endl;
						cout << "				Saber say# 收到，程序退出！" << endl;
						break;
					}

					LOG(Normal, "run chat");
					LOG(Normal, "I say# "+message);
					
					string answer = tl.Chat(message);
					LOG(Normal, "Saber say# "+answer); 
					
					TTL(client, answer);//语音合成
					LOG(Normal, "run TTL");
					Exec(play_cmd, false);
				}
			}
		}

};



#endif
