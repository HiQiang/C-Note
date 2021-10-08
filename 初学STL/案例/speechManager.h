#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<algorithm>
#include<functional>
#include<numeric>
#include<fstream>
#include"speaker.h"

using namespace std;

//����ݽ�������
class SpeechManager 
{
public:
	//���캯��
	SpeechManager();

	//չʾ�˵�
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//��������
	~SpeechManager();

	//��ʼ������������
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	//��ʼ���� �����������̿��ƺ���
	void startSpeech();
	
	//��ǩ
	void speechDraw();

	//����
	void speehContest();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//��ʾ�����¼
	void showRecord();

	//��ռ�¼
	void clearRecord();

	//****************************
	//��Ա����

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	
	//��������¼������
	map<int, vector<string>> m_Record;

	//�����һ�ֱ���ѡ�ֱ�ŵ�����
	vector<int> v1;

	//��һ�ֽ�����ѡ�ֵı�ŵ�����
	vector<int> v2;
	
	//ʤ����ǰ����ѡ�ֵı�ŵ�����
	vector<int> vVictory;

	//��ű���Լ���Ӧ�ľ���ѡ�ֵ�����
	map<int, Speaker> m_Speaker;

	//��ű��������ı���
	int m_Index;
};