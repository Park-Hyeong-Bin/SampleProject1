#pragma once
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

//고정 크기 배열 + head 인덱스로 순환 저장
// 꽉 차면, 가장 오래된 항목을 덮어쓰도록 구성
// 전투로그에 사용 할 것임
template <typename T>
class Ringbuffer
{
private:
        vector<T> data;
        int capacity;   //최대 저장 수 정의
        int head;       // 다음 위치( 순환 인덱스)
        int count;      //현재 저장된 항목 수
public:
        Ringbuffer(int capacity) : data(capacity), capacity(capacity), head(0), count(0){};
        
        void push(const T& value)
        {
                data[head] = value;
                head = (head + 1) % capacity; // 끝에 도달하면 0으로 순환
                if (count < capacity) count++;
        }
        void pirntAll() const
        {
                int start = (count<capacity) ? 0 : head; //가장 오래된 항목 위치
                for (int i = 0; i < count; i++)
                {
                        int idx = (start + i) % capacity;
                        cout << data[idx] << endl;
                }
        }
        
        int size() const {return count;}
        int empty() const {return count==0;}
};
                
